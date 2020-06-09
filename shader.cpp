#include "shader.h"

Shader::Shader():
  program(new QOpenGLShaderProgram),
  object_model(nullptr)
{
  qDebug()<<"build!";
  model_scale=QVector3D(1.0f,1.0f,1.0f);
}

void Shader::initShader(QString file,QString model)
{
  qDebug()<<"init!";
//  //初始化OpenGL函数
//  initializeOpenGLFunctions();
  //将文件内容编译为指定类型的着色器，并将其添加到着色器程序object
  if(!program->addShaderFromSourceFile(QOpenGLShader::Vertex,":/"+file+".vert"))
    {
      //如果执行不成功，打印错误信息
      qDebug()<< "compile error" << program->log();
    }
  if (!program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/"+file+".frag"))
    {
      //如果执行不成功，打印错误信息
      qDebug() << "compile error" << program->log();
    }
  //将顶点着色器跟片元着色器链接起来
  if (!program->link())
    {
      //如果连接不成功，打印错误信息
      qDebug() << "link error" << program->log();
    }
  program->release();

  this->object_model = new Model(model);

  //给着色器变量赋值,projextion,view默认构造是生成单位矩阵
  QMatrix4x4 Mprojection, Mview, Mmodel;
  Mview.translate(model_position);
  if (!program->bind())
    {
      qDebug() << "bind error" << program->log();
    }
  program->setUniformValue("projection",Mprojection);
  program->setUniformValue("view", Mview);
  program->setUniformValue("model", Mmodel);
  program->release();


}


Shader::~Shader()
{
  qDebug()<<"destory!";
  program->removeAllShaders();
  if(program)
    {
      delete program;
      program = nullptr;
    }
  if(object_model)
    {
      delete object_model;
      object_model = nullptr;
    }
}


void Shader::paintShader(Camera *cam,int width,int height,std::vector<Light> light)
{
  QMatrix4x4 Mprojection, Mview, Mmodel;
  Mprojection.perspective(cam->fov,width/float(height),0.1f,100.0f);
  if (!program->bind())
    {
      qDebug() << "bind error" << program->log();
    }
  Mmodel.translate(model_position);
  Mmodel.scale(model_scale);
  Mmodel.rotate(model_row.x(),1,0,0);
  Mmodel.rotate(model_row.y(),0,1,0);
  Mmodel.rotate(model_row.z(),0,0,1);
  program->setUniformValue("model", Mmodel);
  program->setUniformValue("projection",Mprojection*cam->viewMatrix());
  program->setUniformValue("viewPos",cam->position);
  for(auto temp:light)
    {
      temp.setup(program);
    }
  object_model->draw(program);
  program->release();
}
