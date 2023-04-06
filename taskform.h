#ifndef TASKFORM_H
#define TASKFORM_H

#include <QWidget>
#include <QDebug>

namespace Ui {
class TaskForm;
}

class TaskForm : public QWidget
{
    Q_OBJECT

public:
    explicit TaskForm(QWidget *parent = nullptr);
    ~TaskForm();
    void set_show_task(int);

private slots:
    void on_pushButton_check_clicked();

private:
    Ui::TaskForm *ui;
    int task_number;
};

#endif // TASKFORM_H
