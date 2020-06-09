#include "light.h"


Light::Light(QVector3D _pos,QVector3D _color,float _ambient,float _diffuse,
             float _specular,float _constant,float _linear,float _quadratic,
             int _index):
  index(_index),
  pos(_pos),
  color(_color),
  ambient(_ambient),
  diffuse(_diffuse),
  specular(_specular),
  constant(_constant),
  linear(_linear),
  quadratic(_quadratic)
{
}


void Light::setup(QOpenGLShaderProgram *program)
{
//  light = new Model("/home/glory/文档/计算机图形学/interactive_rendering_tool/resource/objects/ball.obj");
  std::string light = "pointLights[" + std::to_string(index)+"]";
  program->setUniformValue((light+".position").data(),pos);
  program->setUniformValue((light+".constant").data(),constant);
  program->setUniformValue((light+".linear").data(),linear);
  program->setUniformValue((light+".ambient").data(),color*ambient);
  program->setUniformValue((light+".diffuse").data(),color*diffuse);
  program->setUniformValue((light+".specular").data(),color*specular);
}

//void Light::draw(QOpenGLShaderProgram *light_program)
//{

//}

QVector3D Light::setposx(double arg)
{
  pos.setX(arg);
  QVector3D back_pos(pos.x(),pos.y(),pos.z());
  return back_pos;
}

QVector3D Light::setposy(double arg)
{
  pos.setY(arg);
  QVector3D back_pos(pos.x(),pos.y(),pos.z());
  return back_pos;
}

QVector3D Light::setposz(double arg)
{
  pos.setZ(arg);
  QVector3D back_pos(pos.x(),pos.y(),pos.z());
  return back_pos;
}

void Light::setambient(double arg)
{
  ambient= arg;
}

void Light::setdiffuse(double arg)
{
  diffuse = arg;
}

void Light::setspecular(double arg)
{
  specular = arg;
}

void Light::setcolorx(double arg)
{
  color.setX(arg);
}

void Light::setcolory(double arg)
{
  color.setY(arg);
}

void Light::setcolorz(double arg)
{
  color.setZ(arg);
}

void Light::setconstant(double arg)
{
  constant = arg;
}

void Light::setlinear(double arg)
{
  linear = arg;
}

void Light::setquadratic(double arg)
{
  quadratic =arg;
}
