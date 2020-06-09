#ifndef LIGHT_H
#define LIGHT_H

#include "qopenglfunctions_3_3_core.h"
#include <QOpenGLShaderProgram>
#include <QVector3D>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLBuffer>


class Model;

class Light
{
public:
  Light(QVector3D _pos,QVector3D _color,float _ambient,float _diffuse,
        float _specular,float _constant,float _linear,float _quadratic,
        int _index);
  void setup(QOpenGLShaderProgram *program);
  QVector3D setposx(double arg);
  QVector3D setposy(double arg);
  QVector3D setposz(double arg);
  void setambient(double arg);
  void setdiffuse(double arg);
  void setspecular(double arg);
  void setcolorx(double arg);
  void setcolory(double arg);
  void setcolorz(double arg);
  void setconstant(double arg);
  void setlinear(double arg);
  void setquadratic(double arg);

//  void draw(QOpenGLShaderProgram *light_program);


private:

  int index;
  QVector3D pos;
  QVector3D color;
  float ambient;
  float diffuse;
  float specular;

  float constant;
  float linear;
  float quadratic;

  float *vertices;

};

#endif // LIGHT_H
