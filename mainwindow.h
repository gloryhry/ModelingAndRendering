#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

protected:
  virtual void keyPressEvent(QKeyEvent *ev) override;

private slots:
  void on_doubleSpinBox_valueChanged(double arg1);

  void on_doubleSpinBox_2_valueChanged(double arg1);

  void on_doubleSpinBox_3_valueChanged(double arg1);

  void on_doubleSpinBox_8_valueChanged(double arg1);

  void on_doubleSpinBox_9_valueChanged(double arg1);

  void on_doubleSpinBox_10_valueChanged(double arg1);

  void on_doubleSpinBox_4_valueChanged(double arg1);

  void on_doubleSpinBox_5_valueChanged(double arg1);

  void on_doubleSpinBox_6_valueChanged(double arg1);

  void on_doubleSpinBox_11_valueChanged(double arg1);

  void on_doubleSpinBox_12_valueChanged(double arg1);

  void on_doubleSpinBox_13_valueChanged(double arg1);

  void on_doubleSpinBox_14_valueChanged(double arg1);

  void on_doubleSpinBox_7_valueChanged(double arg1);

  void on_doubleSpinBox_15_valueChanged(double arg1);

  void on_doubleSpinBox_16_valueChanged(double arg1);

  void on_doubleSpinBox_17_valueChanged(double arg1);

  void on_doubleSpinBox_22_valueChanged(double arg1);

  void on_doubleSpinBox_23_valueChanged(double arg1);

  void on_doubleSpinBox_24_valueChanged(double arg1);

  void on_doubleSpinBox_29_valueChanged(double arg1);

  void on_doubleSpinBox_30_valueChanged(double arg1);

  void on_doubleSpinBox_31_valueChanged(double arg1);

  void on_doubleSpinBox_18_valueChanged(double arg1);

  void on_doubleSpinBox_19_valueChanged(double arg1);

  void on_doubleSpinBox_20_valueChanged(double arg1);

  void on_doubleSpinBox_25_valueChanged(double arg1);

  void on_doubleSpinBox_26_valueChanged(double arg1);

  void on_doubleSpinBox_27_valueChanged(double arg1);

  void on_doubleSpinBox_32_valueChanged(double arg1);

  void on_doubleSpinBox_33_valueChanged(double arg1);

  void on_doubleSpinBox_34_valueChanged(double arg1);

  void on_doubleSpinBox_21_valueChanged(double arg1);

  void on_doubleSpinBox_28_valueChanged(double arg1);

  void on_doubleSpinBox_35_valueChanged(double arg1);

  void on_pushButton_2_released();


  void on_pushButton_released();

  void on_pushButton_3_released();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
