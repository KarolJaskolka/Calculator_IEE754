#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "floatingpoint.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText("0");
    this->setWindowTitle("Calculator");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_0_clicked()
{
    if(clear == true){
        ui->lineEdit->setText("0");
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text() + "0");
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    buttonClicked(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    buttonClicked(2);
}

void MainWindow::on_pushButton_3_clicked()
{
    buttonClicked(3);
}

void MainWindow::on_pushButton_4_clicked()
{
    buttonClicked(4);
}

void MainWindow::on_pushButton_5_clicked()
{
    buttonClicked(5);
}

void MainWindow::on_pushButton_6_clicked()
{
    buttonClicked(6);
}

void MainWindow::on_pushButton_7_clicked()
{
    buttonClicked(7);
}

void MainWindow::on_pushButton_8_clicked()
{
    buttonClicked(8);
}

void MainWindow::on_pushButton_9_clicked()
{
    buttonClicked(9);
}

void MainWindow::on_pushButton_Sign_clicked()
{
    float number = ui->lineEdit->text().toFloat();
    number = FloatingPoint::multiply(number,-1);
    QString text;
    ui->lineEdit->setText(text.setNum(number));
}

void MainWindow::on_pushButton_Dot_clicked()
{
    if(!dotUsed){
        if(clear == true){
            ui->lineEdit->setText("0.");
            clear = false;
            dotUsed = true;
        }
        else{
            ui->lineEdit->setText(ui->lineEdit->text() + ".");
            dotUsed = true;
        }
    }

}

void MainWindow::on_pushButton_Equal_clicked()
{
    float number = ui->lineEdit->text().toFloat();
    QString text;

    switch(choice){
    case 1:
        number = FloatingPoint::add(number,memory);
        ui->lineEdit->setText(text.setNum(number));
        break;
    case 2:
        number = FloatingPoint::subtract(memory,number);
        ui->lineEdit->setText(text.setNum(number));
        break;
    case 3:
        number = FloatingPoint::multiply(number,memory);
        ui->lineEdit->setText(text.setNum(number));
        break;
    case 4:
        number = FloatingPoint::divide(memory,number);
        ui->lineEdit->setText(text.setNum(number));
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_Add_clicked()
{
    choice = 1;
    memory = ui->lineEdit->text().toFloat();
    clear = true;
    dotUsed = false;
}

void MainWindow::on_pushButton_Sub_clicked()
{
    choice = 2;
    memory = ui->lineEdit->text().toFloat();
    clear = true;
    dotUsed = false;
}

void MainWindow::on_pushButton_Mul_clicked()
{
    choice = 3;
    memory = ui->lineEdit->text().toFloat();
    clear = true;
    dotUsed = false;
}

void MainWindow::on_pushButton_Div_clicked()
{
    choice = 4;
    memory = ui->lineEdit->text().toFloat();
    clear = true;
    dotUsed = false;
}

void MainWindow::on_pushButton_Sqrt_clicked()
{
    float number = FloatingPoint::sqrt(ui->lineEdit->text().toFloat());
    QString text;
    ui->lineEdit->setText(text.setNum(number));
    clear = true;
    dotUsed = false;
}

void MainWindow::on_pushButton_Back_clicked()
{
    clearDisplay();
}

void MainWindow::on_pushButton_Clear_clicked()
{
    ui->lineEdit->setText("0");
    clear = true;
    dotUsed = false;
}
void MainWindow::buttonClicked(int number){
    if(clear == true){
        ui->lineEdit->setText(QString::number(number));
        clear = false;
    }
    else{
        ui->lineEdit->setText(ui->lineEdit->text() + QString::number(number));
    }
}
void MainWindow::clearDisplay(){
    ui->lineEdit->setText("0");
    clear = true;
    dotUsed = false;
}
