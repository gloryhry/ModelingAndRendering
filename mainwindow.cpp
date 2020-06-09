#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  move(1080,100);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *ev)
{
  switch(ev->key())
    {
    case Qt::Key_Escape:
      this->close();
      break;

    default:
      ev->ignore();
      break;
    }
}

void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[0]->model_position = ui->openGLWidget->light[0].setposx(arg1);
}

void MainWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[0]->model_position = ui->openGLWidget->light[0].setposy(arg1);
}

void MainWindow::on_doubleSpinBox_3_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[0]->model_position = ui->openGLWidget->light[0].setposz(arg1);
}

void MainWindow::on_doubleSpinBox_8_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[1]->model_position = ui->openGLWidget->light[1].setposx(arg1);
}

void MainWindow::on_doubleSpinBox_9_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[1]->model_position = ui->openGLWidget->light[1].setposy(arg1);
}

void MainWindow::on_doubleSpinBox_10_valueChanged(double arg1)
{
  ui->openGLWidget->object_light[1]->model_position = ui->openGLWidget->light[1].setposz(arg1);
}

void MainWindow::on_doubleSpinBox_4_valueChanged(double arg1)
{
  ui->openGLWidget->light[0].setcolorx(arg1);
}

void MainWindow::on_doubleSpinBox_5_valueChanged(double arg1)
{
  ui->openGLWidget->light[0].setcolory(arg1);
}

void MainWindow::on_doubleSpinBox_6_valueChanged(double arg1)
{
  ui->openGLWidget->light[0].setcolorz(arg1);
}

void MainWindow::on_doubleSpinBox_11_valueChanged(double arg1)
{
  ui->openGLWidget->light[1].setcolorx(arg1);
}

void MainWindow::on_doubleSpinBox_12_valueChanged(double arg1)
{
  ui->openGLWidget->light[1].setcolory(arg1);
}

void MainWindow::on_doubleSpinBox_13_valueChanged(double arg1)
{
  ui->openGLWidget->light[1].setcolorz(arg1);
}

void MainWindow::on_doubleSpinBox_14_valueChanged(double arg1)
{
    ui->openGLWidget->light[1].setlinear(0.07/arg1);
}

void MainWindow::on_doubleSpinBox_7_valueChanged(double arg1)
{
    ui->openGLWidget->light[0].setlinear(0.07/arg1);
}

void MainWindow::on_doubleSpinBox_15_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_position.setX(arg1);
}

void MainWindow::on_doubleSpinBox_16_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_position.setY(arg1);
}

void MainWindow::on_doubleSpinBox_17_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_position.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_22_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_position.setX(arg1);
}

void MainWindow::on_doubleSpinBox_23_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_position.setY(arg1);
}

void MainWindow::on_doubleSpinBox_24_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_position.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_29_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_position.setX(arg1);
}

void MainWindow::on_doubleSpinBox_30_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_position.setY(arg1);
}

void MainWindow::on_doubleSpinBox_31_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_position.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_18_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_row.setX(arg1);
}

void MainWindow::on_doubleSpinBox_19_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_row.setY(arg1);
}

void MainWindow::on_doubleSpinBox_20_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_row.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_25_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_row.setX(arg1);
}

void MainWindow::on_doubleSpinBox_26_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_row.setY(arg1);
}

void MainWindow::on_doubleSpinBox_27_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_row.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_32_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_row.setX(arg1);
}

void MainWindow::on_doubleSpinBox_33_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_row.setY(arg1);
}

void MainWindow::on_doubleSpinBox_34_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_row.setZ(arg1);
}

void MainWindow::on_doubleSpinBox_21_valueChanged(double arg1)
{
    ui->openGLWidget->object[0]->model_scale = QVector3D(arg1,arg1,arg1);
}

void MainWindow::on_doubleSpinBox_28_valueChanged(double arg1)
{
    ui->openGLWidget->object[1]->model_scale = QVector3D(arg1,arg1,arg1);
}

void MainWindow::on_doubleSpinBox_35_valueChanged(double arg1)
{
    ui->openGLWidget->object[2]->model_scale = QVector3D(arg1,arg1,arg1);
}

void MainWindow::on_pushButton_2_released()
{
    ui->openGLWidget->PolygonMode = !ui->openGLWidget->PolygonMode;
    ui->pushButton_2->setDown(ui->openGLWidget->PolygonMode);
}


void MainWindow::on_pushButton_released()
{
    this->close();
}

void MainWindow::on_pushButton_3_released()
{
  QString test;
  test = "WASD控制视角前后左右移动\n鼠标控制视角方向\n鼠标滚轮控制视角大小\n按T切换线框模式";
    QMessageBox::information(this, QString::fromLocal8Bit("使用方法"),test);
}
