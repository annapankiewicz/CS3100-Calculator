#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Calculator"));

    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(digitClicked()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(digitClicked()));

    connect(ui->pushButton_plusminus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_recip,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_squared,SIGNAL(released()),this,SLOT(unary_operation_pressed()));
    connect(ui->pushButton_sqrt,SIGNAL(released()),this,SLOT(unary_operation_pressed()));

    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(operatorClicked()));
    connect(ui->pushButton_minus,SIGNAL(released()),this,SLOT(operatorClicked()));
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(operatorClicked()));
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(operatorClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitClicked()
{
    QPushButton *button = (QPushButton*)sender();
    double labelNumber;
    QString newLabel;
    labelNumber = (ui->label->text() + button->text()).toDouble();
    newLabel = QString::number(labelNumber,'g',15);
    ui->label->setText(newLabel);
}

void MainWindow::operatorClicked()
{
    // QPushButton *button = (QPushButton*)sender();

}

void MainWindow::equalClicked()
{

}

void MainWindow::historyBack()
{

}

void MainWindow::historyForward()
{

}

void MainWindow::backspaceClicked()
{

}

void MainWindow::clear()
{

}

void MainWindow::on_pushButton_decimal_released()
{
    // TODO: check if label already has decimal
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed()
{
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;
    if (button->text() == "±")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "1/x")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = 1/labelNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "x²")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber*labelNumber;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if (button->text() == "sqrt")
    {
        labelNumber = ui->label->text().toDouble();
        labelNumber = sqrt(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
}

void MainWindow::on_pushButton_clear_released()
{

}

void MainWindow::on_pushButton_equals_released()
{

}
