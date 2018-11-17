#include "page1.h"
#include "ui_page1.h"
#include"student_grade.h"
#include"info.h"
#include <QFile>
#include<QMessageBox>
#include<QList>
#include<QTextCodec>
#include<QTextStream>


extern void SetStudentGrade();
extern
Page1::Page1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page1)
{
    ui->setupUi(this);
    connect(ui->button_back,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->button_enter,SIGNAL(clicked(bool)),this,SLOT(PressEnterButton()));
}

Page1::~Page1()
{
    delete ui;
}

void Page1::PressEnterButton()   //按下确认按钮的事件
{
    //获取输入属性
    int _id=ui->lineEdit_id->text().toInt();
    QString _term=ui->comboBox_semester->currentText();
    QString _sname=ui->lineEdit_name->text();
    QString _classname=ui->lineEdit_class->text();
    QString _subject=ui->lineEdit_subject->text();
    int _credit=ui->lineEdit_credit->text().toInt();
    int _grade=ui->lineEdit_grade->text().toInt();

    //判断输入合法性
    if(_id>2000000000&&_id<2019000000&&_credit&&_credit>=1&&_grade>=0&&_grade<=100)
    {
        QFile file("grade.txt");
        file.open(QIODevice::ReadOnly | QIODevice::Append);
        int count=0;       //记录行数即info信息的个数
        QTextStream in(&file);
        in.seek(0);
        while (!in.atEnd()) {
            QString line = in.readLine();
            count++;
        }
        in.seek(0);
        QTextCodec *code=QTextCodec::codecForName("UTF8");  //注意设置编码！！
        in.setCodec(code);
        Info *p = new Info[count];
        in.seek(0);
        int flag=-1;
        int number=0;
        while (!in.atEnd())//逐行读取文本，并去除每行的回车
        {
            QString term, sname, classname, id, subject;
            int credit,grade;
            QString line;
            line = in.readLine() ;
            line.remove('\n');
            QStringList string_list;
            string_list=line.split(" ");   //分割文本 用元素初始化对象

            term=string_list[0];
            sname=string_list[1];
            classname=string_list[2];
            id=string_list[3];
            subject=string_list[4];
            credit=string_list[5].toInt();
            grade=string_list[6].toDouble();

            if(term==_term&&id.toInt()==_id&&subject==_subject)   //判断是否覆盖原有文件
            {
                flag=number;
                grade=ui->lineEdit_grade->text().toInt();
            }
            p[number].set(grade, term, subject, credit, sname, classname, id);

            number++;
        }
        if(flag!=-1)     //需要覆盖文件
        {

            //以TEXT模式写入第一行以清除原先内容
            file.close();
            file.open(QIODevice::WriteOnly | QIODevice::Text);
            QString output=p[0].GetTerm()+" "+p[0].GetSname()+" "+p[0].GetClass()+" "+
                    p[0].GetId()+" "+p[0].GetSubject()+" "+QString::number(p[0].GetCredit())+" "+QString::number(p[0].GetGrade())+"\n";
            file.write(output.toUtf8());
            file.close();

            //以APPEND模式写入之后行
            file.open(QIODevice::WriteOnly | QIODevice::Append);
            for(int i=1;i<count;i++)
            {
                QString output=p[i].GetTerm()+" "+p[i].GetSname()+" "+p[i].GetClass()+" "+
                        p[i].GetId()+" "+p[i].GetSubject()+" "+QString::number(p[i].GetCredit())+" "+QString::number(p[i].GetGrade())+"\n";
                file.write(output.toUtf8());
            }
            file.close();

            QMessageBox msgbox(QMessageBox::NoIcon,"Congratulations!", "覆盖信息成功！");
            msgbox.exec();
        }
        else  //直接录入
        {
            QString output=_term+" "+_sname+" "+_classname+" "+QString::number(_id,10)+
                    " "+_subject+" "+QString::number(_credit,10)+" "+QString::number(_grade,10)+"\n";
            file.write(output.toUtf8());
            file.close();
            QMessageBox msgbox(QMessageBox::NoIcon,"Congratulations!", "录入信息成功！");
            msgbox.exec();
        }

    }else
    {
        QMessageBox msgbox(QMessageBox::NoIcon,"Warning!", "输入不合法！请检查并重新输入");
        msgbox.exec();
    }
    SetStudentGrade();
}


