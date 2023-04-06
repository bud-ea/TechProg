#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "authform.h"
#include "taskform.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButton_exit_clicked();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actiontask_1_triggered();

    void on_actiontask_2_triggered();

    void on_actiontask_3_triggered();

    void on_actionexit_triggered();

    void slot_on_ReceiveData(QString);

private:
    Ui::MainWindow *ui;
    AuthForm *ui_auth;
    TaskForm *ui_task;
};
#endif // MAINWINDOW_H
