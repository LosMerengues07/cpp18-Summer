#ifndef PAGE4_H
#define PAGE4_H

#include <QDialog>
#include"student_grade.h"
namespace Ui {
class Page4;
}

class Page4 : public QDialog
{
    Q_OBJECT

public:
    explicit Page4(QWidget *parent = 0);
    ~Page4();
public slots:
    void PressEnterButton();
private:
    Ui::Page4 *ui;
    void Operation41(StudentGrade *p, int num);
    void Operation42(StudentGrade *p, int num);
    void Operation43(StudentGrade *p, int num);
};

#endif // PAGE4_H
