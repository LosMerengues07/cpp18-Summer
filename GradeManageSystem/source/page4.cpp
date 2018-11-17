#include "page4.h"
#include "ui_page4.h"
#include<QString>
#include"student_grade.h"
extern StudentGrade *stugrade;
extern int num;

Page4::Page4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page4)
{
    ui->setupUi(this);
    connect(ui->button_back,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->button_enter,SIGNAL(clicked(bool)),this,SLOT(PressEnterButton()));
}

Page4::~Page4()
{
    delete ui;
}


//判断是哪一个学期
void Page4::PressEnterButton()
{
    ui->textBrowser->setText("");
    if(ui->comboBox_semester->currentText()=="2017秋季学期")
    {
        Operation41(stugrade, num);
    }else if(ui->comboBox_semester->currentText()=="2018春季学期")
    {
        Operation42(stugrade, num);
    }else
    {
        Operation43(stugrade, num);
    }
}

void Page4::Operation41(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++) q[i] = &p[i];

    //对成绩降序排序
    for (i = 0; i < num; i++)
    {
        for (k = i; k < num; k++)
            if (q[i]->GetUpGpa() < q[k]->GetUpGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //成绩相同按学号升序排序
    for (i = 0; i < num; i++)
    {
        for (int k = i; k < num; k++)
            if (q[i]->GetId().compare(q[k]->GetId()) > 0 && q[i]->GetUpGpa() == q[k]->GetUpGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //输出
    ui->textBrowser->append("2017秋季学期总成绩情况表");
    QString str1="排名    学号        姓名     班级    GPA";
    ui->textBrowser->append(str1);
    for(i=0;i<num;i++)
    {
        QString str=" "+QString::number(i+1)+" "+q[i]->GetId()+" "+q[i]->GetSname()+" "+q[i]->GetClass()+" "+QString::number(q[i]->GetUpGpa());
        ui->textBrowser->append(str);
    }
    delete[]q;
}

void Page4::Operation42(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++) q[i] = &p[i];

    //对成绩降序排序
    for (i = 0; i < num; i++)
    {
        for (k = i; k < num; k++)
            if (q[i]->GetDownGpa() < q[k]->GetDownGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //成绩相同按学号升序排序
    for (i = 0; i < num; i++)
    {
        for (int k = i; k < num; k++)
            if (q[i]->GetId().compare(q[k]->GetId()) > 0 && q[i]->GetDownGpa() == q[k]->GetDownGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    ui->textBrowser->append("2018春季学期总成绩情况表");
    QString str1="排名    学号        姓名     班级    GPA";
    ui->textBrowser->append(str1);
    for(i=0;i<num;i++)
    {
        QString str=" "+QString::number(i+1)+" "+q[i]->GetId()+" "+q[i]->GetSname()+" "+q[i]->GetClass()+" "+QString::number(q[i]->GetDownGpa());
        ui->textBrowser->append(str);
    }
    delete[]q;
}

void Page4::Operation43(StudentGrade *p, int num)
{
    int i = 0, k = 0;
    StudentGrade **q = new StudentGrade*[num];
    StudentGrade *t;
    for (i = 0; i < num; i++) q[i] = &p[i];

    //对成绩降序排序
    for (i = 0; i < num; i++)
    {
        for (k = i; k < num; k++)
            if (q[i]->GetTotalGpa() < q[k]->GetTotalGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    //成绩相同按学号升序排序
    for (i = 0; i < num; i++)
    {
        for (int k = i; k < num; k++)
            if (q[i]->GetId().compare(q[k]->GetId()) > 0 && q[i]->GetTotalGpa() == q[k]->GetTotalGpa())
            {
                t = q[i]; q[i] = q[k]; q[k] = t;
            }
    }
    ui->textBrowser->append("2017-2018学年总成绩情况表");
    QString str1="排名    学号        姓名     班级    GPA";
    ui->textBrowser->append(str1);
    for(i=0;i<num;i++)
    {
        QString str=" "+QString::number(i+1)+" "+q[i]->GetId()+" "+q[i]->GetSname()+" "+q[i]->GetClass()+" "+QString::number(q[i]->GetTotalGpa());
        ui->textBrowser->append(str);
    }
    delete[]q;

}
