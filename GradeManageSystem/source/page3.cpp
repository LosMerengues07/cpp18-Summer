#include "page3.h"
#include "ui_page3.h"
#include<QMessageBox>
#include<QFile>
#include<QDebug>
#include"info.h"
#include<QList>
#include<QTextCodec>
Page3::Page3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page3)
{
    ui->setupUi(this);
    connect(ui->button_back,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->button_enter,SIGNAL(clicked(bool)),this,SLOT(PressEnterButton()));
}

Page3::~Page3()
{
    delete ui;
}

void Page3::PressEnterButton()
{
    ui->textBrowser->setText("");
    //QString class_name=ui->lineEdit_class_name->text();
    QString term=ui->comboBox_semester->currentText();
    QFile file("grade.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int count=0;       //记录行数即info信息的个数
    int num=0;
    int i=0;
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine();
        count++;
    }
    in.seek(0);
    QTextCodec *code=QTextCodec::codecForName("UTF8");  //注意设置编码！！
    in.setCodec(code);
    Info *p = new Info[count];
    in.seek(0);
    while (!in.atEnd())//逐行读取文本，并去除每行的回车
    {
        QString _term, _name, _classname, _id, _subject;
        int _credit,_grade;
        QString line;
        line = in.readLine() ;
        line.remove('\n');
        QStringList string_list;
        string_list=line.split(" ");   //分割文本 用元素初始化对象
        _term=string_list[0];
        _name=string_list[1];
        _classname=string_list[2];
        _id=string_list[3];
        _subject=string_list[4];
        _credit=string_list[5].toInt();
        _grade=string_list[6].toDouble();
        if(term==_term && ui->lineEdit_class_name->text()==_subject)
        {
            p[num].set(_grade, _term, _subject, _credit, _name, _classname, _id);
            num++;
        }
    }
    if(num == 0)
    {
        QMessageBox msgbox(QMessageBox::NoIcon,"Warning!", "无数据！");
        msgbox.exec();
    }else
    {
        //排序
        Info **q = new Info*[num];
        Info *t = NULL;
        for (i = 0; i < num; i++)	q[i] = &p[i];

        //先对成绩降序排序
        for (i = 0; i < num; i++)
        {
            for (int k = i; k < num; k++)
                if (q[i]->GetGrade() <= q[k]->GetGrade())
                {
                    t = q[i]; q[i] = q[k]; q[k] = t;
                }
        }

        //再对学号升序排序
        for (i = 0; i < num; i++)
        {
            for (int k = i; k < num; k++)
                if (q[i]->GetId().compare(q[k]->GetId()) > 0 && q[i]->GetGrade() == q[k]->GetGrade())
                {
                    t = q[i]; q[i] = q[k]; q[k] = t;
                }
        }
        //输出到文本框
        QString str1="排名    学号         姓名      班级      学期         课程     学分  分数  等级  GPA";
        ui->textBrowser->append(str1);
        for (i = 0; i < num; i++)
        {
            QString str=" "+QString::number(i+1)+" "+q[i]->GetId()+" "+q[i]->GetSname()+" "+q[i]->GetClass()+" "+q[i]->GetTerm()+"  "+q[i]->GetSubject()+"    "+QString::number(q[i]->GetCredit())+"    "+QString::number(q[i]->GetGrade())+"    "+q[i]->GetLevel()+"    "+QString::number(q[i]->GetGpa());
            ui->textBrowser->append(str);
        }
        delete[]p;
        delete[]q;

    }
    file.close();
}

