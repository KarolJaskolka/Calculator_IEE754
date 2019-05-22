#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float result = 0.0;
    float memory = 0.0;
    int choice = 0;
    bool clear = true;
    bool dotUsed = false;

private slots:
    void on_pushButton_0_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_Sign_clicked();

    void on_pushButton_Dot_clicked();

    void on_pushButton_Equal_clicked();

    void on_pushButton_Add_clicked();

    void on_pushButton_Sub_clicked();

    void on_pushButton_Mul_clicked();

    void on_pushButton_Div_clicked();

    void on_pushButton_Sqrt_clicked();

    void on_pushButton_Back_clicked();

    void on_pushButton_Clear_clicked();

    void buttonClicked(int number);

    void clearDisplay();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
