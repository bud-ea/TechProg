#ifndef AUTHFORM_H
#define AUTHFORM_H

#include <QWidget>
#include<QDebug>

namespace Ui {
class AuthForm;
}

class AuthForm : public QWidget
{
    Q_OBJECT

public:
    explicit AuthForm(QWidget *parent = nullptr);
    ~AuthForm();

private slots:
    void on_pushButton_change_clicked();

    void on_pushButton_reg_clicked();

    void on_pushButton_auth_clicked();

private:
    Ui::AuthForm *ui;

    void change_mode(bool);

signals:
    void auth_ok(QString);
};

#endif // AUTHFORM_H
