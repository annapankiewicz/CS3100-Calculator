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
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void digitClicked();
    void operatorClicked();
    void equalClicked();
    void historyBack();
    void historyForward();
    void backspaceClicked();
    void clear();
    void on_pushButton_decimal_released();
    void unary_operation_pressed();
    void on_pushButton_clear_released();
    void on_pushButton_equals_released();
};

#endif // MAINWINDOW_H
