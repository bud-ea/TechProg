#include "authform.h"
#include "ui_authform.h"
#include "netclient.h"

AuthForm::AuthForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AuthForm)
{
    ui->setupUi(this);
    this->change_mode(true);
}

AuthForm::~AuthForm()
{
    delete ui;
}

void AuthForm::change_mode(bool mode)//mode==true for auth
{
    ui->label_email->setVisible(!mode);
    ui->lineEdit_email->setVisible(!mode);
    ui->pushButton_reg->setVisible(!mode);
    ui->pushButton_auth->setVisible(mode);

    if(mode)
        ui->pushButton_change->setText("to reg");
    else
        ui->pushButton_change->setText("to auth");
}
void AuthForm::on_pushButton_change_clicked()
{
    this->change_mode(ui->pushButton_reg->isVisible());
}


void AuthForm::on_pushButton_reg_clicked()
{
    qDebug()<<"reg "+ui->lineEdit_log->text()+
              " "+ui->lineEdit_pas->text()+
              " "+ui->lineEdit_email->text();
    //"registration$"
    this->on_pushButton_auth_clicked();
}


void AuthForm::on_pushButton_auth_clicked()
{
    qDebug()<<"auth "+ui->lineEdit_log->text()+
              " "+ui->lineEdit_pas->text();

    NetClient::Connect()->SendData("auth "+ui->lineEdit_log->text()+
                                   " "+ui->lineEdit_pas->text());
    //"login$user$par"
    //emit auth_ok(ui->lineEdit_log->text());
    //this->close();
}

