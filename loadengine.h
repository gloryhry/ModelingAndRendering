#ifndef LOADENGINE_H
#define LOADENGINE_H


#include <QOpenGLTexture>
#include <QSharedPointer>
#include <QOpenGLWidget>
#include <QString>
#include <QOpenGLFunctions_3_3_Core>
#include <QTime>
#include "model.h"
#include "camera.h"
#include "light.h"
#include <shader.h>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QKeyEvent>


class LoadEngine : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core
{
  Q_OBJECT
public:
  explicit LoadEngine(QWidget *parent = nullptr);
  ~LoadEngine();

protected:
  virtual void initializeGL() override;
  virtual void paintGL() override;
  virtual void resizeGL(int width, int height) override;
  virtual void wheelEvent(QWheelEvent *ev) override;
  virtual void mouseMoveEvent(QMouseEvent *ev) override;
  virtual void keyPressEvent(QKeyEvent* ev) override;

public:
  std::vector<Light> light;
  Shader *object[3];
  Shader *object_light[2];
  bool PolygonMode;

private:
  Camera *camera;
  bool firstMouse;
  QPoint lastMousePos;


};
#endif // LOADENGINE_H
