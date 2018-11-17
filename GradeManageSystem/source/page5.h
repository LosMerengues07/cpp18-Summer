#ifndef PAGE5_H
#define PAGE5_H

#include <QDialog>
#include"student_grade.h"
namespace Ui {
class Page5;
}

class Page5 : public QDialog
{
    Q_OBJECT

public:
    explicit Page5(QWidget *parent = 0);
    ~Page5();
public slots:
    void PressEnterButton();
private:
    Ui::Page5 *ui;
    void Operation51(StudentGrade *p, int num);
    void Operation52(StudentGrade *p, int num);
    void Operation53(StudentGrade *p, int num);
};

#endif // PAGE5_H
