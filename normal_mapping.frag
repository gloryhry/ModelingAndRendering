#version 330 core
out vec4 FragColor;

in VS_OUT {
    vec3 FragPos;
    vec2 TexCoords;
    mat3 TBN;
} fs_in;

uniform sampler2D texture_diffuse1;
uniform sampler2D texture_specular1;
uniform sampler2D texture_normal1;
uniform sampler2D texture_height1;
uniform float shininess;

struct PointLight {
    vec3 position;

    float constant;
    float linear;
    float quadratic;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};
#define NR_POINT_LIGHTS 2
uniform PointLight pointLights[NR_POINT_LIGHTS];
//uniform vec3 lightPos;
uniform vec3 viewPos;


vec3 CalcPointLight(PointLight light, vec3 normal, vec3 Pos, vec3 viewDir);

void main()
{           
    vec3 normal = texture(texture_normal1, fs_in.TexCoords).rgb;
    // 转换法向量到[-1,1]范围
    normal = normalize(normal * 2.0 - 1.0);  // 此向量是切线空间中的向量
    normal = normalize(fs_in.TBN * normal);

    vec3 result = CalcPointLight(pointLights[0],normal,fs_in.FragPos,normalize(viewPos - fs_in.FragPos));
    result += CalcPointLight(pointLights[1],normal,fs_in.FragPos,normalize(viewPos - fs_in.FragPos));
    FragColor = vec4(result, 1.0);
}


vec3 CalcPointLight(PointLight light,vec3 normal,vec3 Pos, vec3 viewDir)
{
    // 采样漫反射
    vec3 color = texture(texture_diffuse1, fs_in.TexCoords).rgb;
    // 环境光
    vec3 ambient = 0.1 * color;
    // 漫反射
    vec3 lightDir = normalize(light.position - fs_in.FragPos);
    float diff = max(dot(normal,lightDir), 0.0);
//    vec3 diffuse = diff * color;
    vec3 diffuse  = diff * color;
    // 镜面高光
//    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);
    vec3 halfwayDir = normalize(lightDir + viewDir);
    float spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);

    vec3 specular = vec3(0.2) * spec;

//    // attenuation
//    float distance = length(light.position - Pos);
//    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance));
//    ambient *= attenuation;
//    diffuse *= attenuation;
//    specular *= attenuation;

    return (ambient + diffuse + specular);
}
