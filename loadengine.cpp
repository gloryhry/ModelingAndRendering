#include "loadengine.h"
#include <QOpenGLTexture>
#include <QVector3D>
#include <QOpenGLShaderProgram>
#include <QDebug>


LoadEngine::LoadEngine(QWidget *parent) :
  QOpenGLWidget(parent),
  camera(nullptr),
  firstMouse(true),
  PolygonMode(false)
{
  //设置OpenGL的版本信息
  QSurfaceFormat format;
  format.setRenderableType(QSurfaceFormat::OpenGL);
  format.setProfile(QSurfaceFormat::CoreProfile);
  //指定opengl版本为3.3
  format.setVersion(3, 3);
  setFormat(format);
  setCursor(Qt::ArrowCursor);
  setFocusPolicy(Qt::StrongFocus);

  for(int i=0;i<3;i++)
    {
      object[i]=new Shader();
    }
  for(int i=0;i<2;i++)
    {
      object_light[i]=new Shader();
    }
}


LoadEngine::~LoadEngine()
{
  if(camera)
    {
      delete camera;
      camera = nullptr;
    }
}


void LoadEngine::initializeGL()
{
  //初始化OpenGL函数
  initializeOpenGLFunctions();
  glEnable(GL_CULL_FACE);// 面剔除 仅在封闭形状有效
  //设置全局变量
  glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // 背景颜色

  QString file[3] = {"./objects/nanosuit/nanosuit.obj",
                     "./objects/cyborg/cyborg.obj",
                     "./objects/planet/planet.obj"};
  for(int i=0;i<3;i++)
    {
      object[i]->initShader("loadengine",file[i]);
    }
  for(int i=0;i<2;i++)
    {
      object_light[i]->initShader("light","./objects/planet/planet.obj");
    }

  object[0]->model_scale = QVector3D(0.1f,0.1f,0.1f);
  object[0]->model_position = QVector3D(-1.0f,0.0f,0.0f);
  object[1]->model_scale = QVector3D(0.4f,0.4f,0.4f);
  object[1]->model_position = QVector3D(0.0f,0.0f,0.0f);
  object[2]->model_scale = QVector3D(0.1f,0.1f,0.1f);
  object[2]->model_position = QVector3D(0.0f,0.0f,-2.0f);
  object_light[0]->model_position = QVector3D(-1.0f,0.5f,1.0f);
  object_light[0]->model_scale = QVector3D(0.01f,0.01f,0.01f);
  object_light[1]->model_position = QVector3D(1.0f,0.5f,1.0f);
  object_light[1]->model_scale = QVector3D(0.01f,0.01f,0.01f);


  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);//结束记录状态信息

  glEnable(GL_DEPTH_TEST);  //开启深度测试
  camera = new Camera(QVector3D(-0.0f, 1.0f, 5.0f));
  for (int i =0;i<2;i++)
    {
      QVector3D pos(-1.0f+2.0f*i,0.5f,1.0f);
      QVector3D color(1.0f,1.0f,1.0f);
      Light temp_light(pos,color,0.1,0.64,0.5,1.0,0.07,0.017,i);
      light.push_back(temp_light);
    }
}


void LoadEngine::paintGL()
{
  //清理屏幕
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!

  if(PolygonMode)
    {
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    }
  else
    {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

  for(auto temp_object:object)
    {
      temp_object->paintShader(camera, width(),height(),light);
    }
  for(auto temp_object:object_light)
    {
      temp_object->paintShader(camera,width(),height(),light);
    }

  update();
}


void LoadEngine::resizeGL(int width, int height)
{
  glViewport(0, 0, width, height);
  firstMouse = true;
  update();
}


void LoadEngine::wheelEvent(QWheelEvent *ev)
{
  qDebug()<<ev->delta();
  if (ev->delta() > 0)
    {
      camera->zoomIn();
      update();
    }
  else if (ev->delta() < 0)
    {
      camera->zoomOut();
      update();
    }
  else
    {
      ev->ignore();
    }
}


void LoadEngine::mouseMoveEvent(QMouseEvent *ev)
{
  if (firstMouse)
    {
      lastMousePos = ev->pos();
      firstMouse = false;
      return;
    }
  QPoint diff = ev->pos() - lastMousePos;
  qDebug()<<"diff:"<<diff<<endl;
  if (QPoint::dotProduct(diff, diff) > 50 * 50)
    {
      // ignore the case in which the mouse move drastically
      firstMouse = true;
      return;
    }
  float xoffset = -ev->x() + lastMousePos.x();
  float yoffset = -lastMousePos.y() + ev->y();
  lastMousePos = ev->pos();
  camera->rotate(xoffset, yoffset);
  update();
}

void LoadEngine::keyPressEvent(QKeyEvent *ev)
{
  switch (ev->key())
    {
    case Qt::Key_W:
      camera->move(Camera::FORWARD);
      update();
      break;
    case Qt::Key_S:
      camera->move(Camera::BACKWARD);
      update();
      break;
    case Qt::Key_A:
      camera->move(Camera::LEFT);
      update();
      break;
    case Qt::Key_D:
      camera->move(Camera::RIGHT);
      update();
      break;
    case Qt::Key_T:
      PolygonMode = !PolygonMode;
      update();
      break;
    default:
      ev->ignore();
      break;
    }
}

