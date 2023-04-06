#include "taskform.h"
#include "ui_taskform.h"

TaskForm::TaskForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TaskForm)
{
    ui->setupUi(this);
}

void TaskForm::set_show_task(int num)
{
    this->task_number = num;
    ui->label_task->setText(QString::fromStdString("text")+
                            QString::number(num));
    this->show();
}

TaskForm::~TaskForm()
{
    delete ui;
}

void TaskForm::on_pushButton_check_clicked()
{
    qDebug()<<"check " + QString::number(task_number) + " "+
              ui->label_variant->text()+" "+
              ui->lineEdit_answer->text();
    this->close();
}

