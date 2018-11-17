#include "page5.h"
#include "ui_page5.h"
#include<QString>
#include"student_grade.h"

extern StudentGrade *stugrade;
extern int num;
Page5::Page5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page5)
{
    ui->setupUi(this);
    connect(ui->button_back,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->button_enter,SIGNAL(clicked(bool)),this,SLOT(PressEnterButton()));
}

Page5::~Page5()
{
    delete ui;
}

void Page5::PressEnterButton()
{
    ui->textBrowser->setText("");
    if(ui->comboBox_semester->currentText()=="2017秋季学期")
    {
        Operation51(stugrade, num);
    }else if(ui->comboBox_semester->currentText()=="2018春季学期")
    {
        Operation52(stugrade, num);
    }else
    {
        Operation53(stugrade, num);
    }

}
void Page5::Operation51(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    int failnum;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++)
    {
        if (p[i].GetUpFailCredit() != 0)
        {
            q[k] = &p[i];
            k++;
        }
    }
    failnum = k;

    //对挂科数降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetUpFailNumber() < q[k]->GetUpFailNumber())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数相同按挂科学分降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetUpFailNumber() == q[k]->GetUpFailNumber() && q[i]->GetUpFailCredit() < q[k]->GetUpFailCredit())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数、挂科学分相同按学号升序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetUpFailNumber() == q[k]->GetUpFailNumber() && q[i]->GetUpFailCredit() == q[k]->GetUpFailCredit() && q[i]->GetId().compare(q[k]->GetId()))
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }

    ui->textBrowser->append("2017秋季学期挂科情况表");
    QString str1="    学号             姓名      班级    挂科数  挂科学分";
    ui->textBrowser->append(str1);
    for(i=0;i<failnum;i++)
    {

        QString str=q[i]->GetId()+"   "+q[i]->GetSname()+"   "+q[i]->GetClass()+"      "+QString::number(q[i]->GetUpFailNumber())+"        "+QString::number(q[i]->GetUpFailCredit());
        ui->textBrowser->append(str);
    }
    delete[]q;
}

void Page5::Operation52(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    int failnum;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++)
    {
        if (p[i].GetDownFailCredit() != 0)
        {
            q[k] = &p[i];
            k++;
        }
    }
    failnum = k;

    //对挂科数降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetDownFailNumber() < q[k]->GetDownFailNumber())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数相同按挂科学分降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetDownFailNumber() == q[k]->GetDownFailNumber() && q[i]->GetDownFailCredit() < q[k]->GetDownFailCredit())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数、挂科学分相同按学号升序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetDownFailNumber() == q[k]->GetDownFailNumber() && q[i]->GetDownFailCredit() == q[k]->GetDownFailCredit() && q[i]->GetId().compare(q[k]->GetId()))
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }

    ui->textBrowser->append("2018春季学期挂科情况表");
    QString str1="    学号             姓名      班级    挂科数  挂科学分";
    ui->textBrowser->append(str1);
    for(i=0;i<failnum;i++)
    {
      QString str=q[i]->GetId()+"   "+q[i]->GetSname()+"   "+q[i]->GetClass()+"      "+QString::number(q[i]->GetDownFailNumber())+"        "+QString::number(q[i]->GetDownFailCredit());
      ui->textBrowser->append(str);
  }
    delete[]q;
}
void Page5::Operation53(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    int failnum;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++)
    {
        if (p[i].GetTotalFailCredit() != 0)
        {
            q[k] = &p[i];
            k++;
        }
    }
    failnum = k;

    //对挂科数降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetTotalFailNumber() < q[k]->GetTotalFailNumber())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数相同按挂科学分降序排序
    for (i = 0; i < failnum; i++)
    {
        for (k = i; k < failnum; k++)
            if (q[i]->GetTotalFailNumber() == q[k]->GetTotalFailNumber() && q[i]->GetTotalFailCredit() < q[k]->GetTotalFailCredit())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //挂科数、挂科学分相同按学号升序排序
    for (i = 0; i < failnum; i++)
    {
        for (int k = i; k < failnum; k++)
            if (q[i]->GetTotalFailNumber() == q[k]->GetTotalFailNumber() && q[i]->GetTotalFailCredit() == q[k]->GetTotalFailCredit() && q[i]->GetId().compare(q[k]->GetId()))
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }

    ui->textBrowser->append("2017-2018学年挂科情况表");
    QString str1="    学号             姓名      班级    挂科数  挂科学分";
    ui->textBrowser->append(str1);
    for(i=0;i<failnum;i++)
    {

       QString str=q[i]->GetId()+"   "+q[i]->GetSname()+"   "+q[i]->GetClass()+"      "+QString::number(q[i]->GetTotalFailNumber())+"        "+QString::number(q[i]->GetTotalFailCredit());
        ui->textBrowser->append(str);
    }
    delete[]q;
}
