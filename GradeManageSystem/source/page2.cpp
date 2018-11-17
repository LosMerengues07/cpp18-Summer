#include"page2.h"
#include"ui_page2.h"
#include"info.h"
#include<QMessageBox>
#include<QFile>
#include<QList>
#include<QTextCodec>
#include<QTextStream>
Page2::Page2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page2)
{
    ui->setupUi(this);
    connect(ui->button_back,SIGNAL(clicked(bool)),this,SLOT(close()));
    connect(ui->button_enter,SIGNAL(clicked(bool)),this,SLOT(PressEnterButton()));
}

Page2::~Page2()
{
    delete ui;
}

void Page2::PressEnterButton()
{
    ui->textBrowser->setText("");  //先清空文本框
    //
    int id=ui->lineEdit_id->text().toInt();
    if(id<=2000000000||id>=2019000000)
    {
        QMessageBox msgbox(QMessageBox::NoIcon,"Warning!", "请输入格式正确的学号！");
        msgbox.exec();
    }else
    {
        if(ui->comboBox_semester->currentText()=="2017-2018学年")
        {
            Operation21();
        }
        else
        {
            Operation22();
        }

    }

}

void Page2::Operation21()
{
    QFile file("grade.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int count=0;       //记录行数即info信息的个数
    int num=0;
    int i=0;
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
        //qDebug()<<id<<term<<endl;
        if(id==ui->lineEdit_id->text())
        {
            p[num].set(grade, term, subject, credit, sname, classname, id);
            num++;
        }
    }
    if(num == 0)
    {
        QMessageBox msgbox(QMessageBox::NoIcon,"Warning!", "无数据！");
        msgbox.exec();
    }else
    {
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
        //再将成绩相同的按学分降序排列
        for (i = 0; i < num; i++)
        {
            for (int k = i; k < num; k++)
                if (q[i]->GetGrade() == q[k]->GetGrade() && q[i]->GetCredit() <= q[i]->GetCredit())
                {
                    t = q[i]; q[i] = q[k]; q[k] = t;
                }
        }

        double Gpa = 0;
        int totalcredit = 0;
        QString str1=q[0]->GetClass() + " " + q[0]->GetSname() + " " + q[0]->GetId() + " "+ui->comboBox_semester->currentText()+"\n";
        ui->textBrowser->append(str1);
        //qDebug() << q[0]->getClass() << " " << q[0]->getSname() << " " << q[0]->getNum() << " 大一上学期成绩单" << endl;
        for (i = 0; i < num; i++)
        {
            QString str=q[i]->GetTerm()+" "+q[i]->GetSubject()+" "+QString::number(q[i]->GetCredit())+" "+QString::number(q[i]->GetGrade())+" "+q[i]->GetLevel()+" "+QString::number(q[i]->GetGpa());
            ui->textBrowser->append(str);
            Gpa += q[i]->GetGpa()*q[i]->GetCredit();
            totalcredit += q[i]->GetCredit();
        }

        QString str3="\n2017-2018学年GPA为: " + QString::number((Gpa / totalcredit));
        ui->textBrowser->append(str3);

        delete[]p;
        delete[]q;

    }
}


void Page2::Operation22()
{
    QFile file("grade.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    int count=0;       //记录行数即info信息的个数
    int num=0;
    int i=0;
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
    while (!in.atEnd())//逐行读取文本，并去除每行的回车
    {
        QString term, name, classname, id, cname;
        int credit,grade;
        QString line;
        line = in.readLine() ;
        line.remove('\n');
        QStringList string_list;
        string_list=line.split(" ");   //分割文本 用元素初始化对象
        term=string_list[0];
        name=string_list[1];
        classname=string_list[2];
        id=string_list[3];
        cname=string_list[4];
        credit=string_list[5].toInt();
        grade=string_list[6].toDouble();
        //qDebug()<<id<<term<<endl;
        if(id==ui->lineEdit_id->text()
                &&term==ui->comboBox_semester->currentText())
        {
            p[num].set(grade, term, cname, credit, name, classname, id);
            num++;
        }
    }
    if(num == 0)
    {
        QMessageBox msgbox(QMessageBox::NoIcon,"Warning!", "无数据！");
        msgbox.exec();
    }else
    {
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
        //再将成绩相同的按学分降序排列
        for (i = 0; i < num; i++)
        {
            for (int k = i; k < num; k++)
                if (q[i]->GetGrade() == q[k]->GetGrade() && q[i]->GetCredit() <= q[i]->GetCredit())
                {
                    t = q[i]; q[i] = q[k]; q[k] = t;
                }
        }

        double Gpa = 0;
        int totalcredit = 0;
        QString str1=q[0]->GetClass() + " " + q[0]->GetSname() + " " + q[0]->GetId() +" "+ ui->comboBox_semester->currentText()+"\n";
        ui->textBrowser->append(str1);

        for (i = 0; i < num; i++)
        {
            QString str=q[i]->GetTerm()+" "+q[i]->GetSubject()+" "+QString::number(q[i]->GetCredit())+" "+QString::number(q[i]->GetGrade())+" "+q[i]->GetLevel()+" "+QString::number(q[i]->GetGpa());
            ui->textBrowser->append(str);
            Gpa += q[i]->GetGpa()*q[i]->GetCredit();
            totalcredit += q[i]->GetCredit();
        }
        if(ui->comboBox_semester->currentText()=="2017秋季学期")
        {
            QString str3="\n2017秋季学期GPA为: " + QString::number((Gpa / totalcredit));
            ui->textBrowser->append(str3);
        }
        else{
            QString str3="\n2018春季学期GPA为: " + QString::number((Gpa / totalcredit));
            ui->textBrowser->append(str3);
        }

        delete[]p;
        delete[]q;
    }
    file.close();
}
