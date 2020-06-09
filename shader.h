#ifndef SHADER_H
#define SHADER_H

#include <QOpenGLFunctions_3_3_Core>
#include <QOpenGLTexture>
#include <QOpenGLShaderProgram>
#include <QSharedPointer>
#include <model.h>
#include <camera.h>
#include <light.h>


class Shader : protected QOpenGLFunctions_3_3_Core
{
public:
  Shader();
  ~Shader();
  void initShader(QString file,QString model);
  void paintShader(Camera *cam,int width,int height,std::vector<Light> light);

  QOpenGLShaderProgram *program;
  Model *object_model;
  QVector3D model_scale,model_position,model_row;
};

#endif // SHADER_H
