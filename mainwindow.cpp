#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "netclient.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui_auth = new AuthForm;
//    connect(ui_auth,&AuthForm::auth_ok,
  //          this, &MainWindow::slot_on_auth_ok);

    connect(ui_auth,&AuthForm::auth_ok,
            this, &MainWindow::slot_on_auth_ok);

    connect(NetClient::Connect(),&NetClient::ReceiveData,this,&MainWindow::slot_on_ReceiveData);

    ui_auth->show();
    ui_task = new TaskForm;
}

void MainWindow::slot_on_ReceiveData(QString log)
{
    if (log=="auth ok")
    {
        ui_auth->close();
        ui->label_log->setText(log);
        this->show();
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_exit_clicked()
{
    this->close();
}
void MainWindow::on_pushButton_1_clicked()
{
    ui_task->set_show_task(1);
    qDebug()<<"task 1";
}
void MainWindow::on_pushButton_2_clicked()
{
    ui_task->set_show_task(2);
    qDebug()<<"task 2";
}
void MainWindow::on_pushButton_3_clicked()
{
    ui_task->set_show_task(3);
    qDebug()<<"task 3";
}
void MainWindow::on_actiontask_1_triggered()
{
    this->on_pushButton_1_clicked();
}
void MainWindow::on_actiontask_2_triggered()
{
    this->on_pushButton_2_clicked();
}
void MainWindow::on_actiontask_3_triggered()
{
    this->on_pushButton_3_clicked();
}
void MainWindow::on_actionexit_triggered()
{
    this->on_pushButton_exit_clicked();
}
