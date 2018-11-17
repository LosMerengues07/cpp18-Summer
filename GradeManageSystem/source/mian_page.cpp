#include "main_page.h"
#include "ui_grademanagesystem.h"
#include "page1.h"
#include "page2.h"
#include "page3.h"
#include "page4.h"
#include "page5.h"
#include"student_grade.h"
#include<QFile>
#include<QTextCodec>
#include"info.h"
#include<QTextStream>
#include<QPixmap>
#include<QPalette>
void SetStudentGrade();

int counta=0;					//全局变量,文件内有效信息数
StudentGrade *stugrade=NULL;	//全局变量，文件内的每位学生成绩的对象数组的首地址
int num=0;						//全局变量，文件内学生数



MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GradeManageSystem)
{
    setWindowIcon(QIcon(QStringLiteral(":/icon1.jpg")));
    SetStudentGrade();    //通过文本初始化StudentGrade类
    ui->setupUi(this);
    setFixedSize(QSize(590,611));
    connect(ui->pushButton1,SIGNAL(clicked(bool)),this,SLOT(OpenPage1()));
    connect(ui->pushButton2,SIGNAL(clicked(bool)),this,SLOT(OpenPage2()));
    connect(ui->pushButton3,SIGNAL(clicked(bool)),this,SLOT(OpenPage3()));
    connect(ui->pushButton4,SIGNAL(clicked(bool)),this,SLOT(OpenPage4()));
    connect(ui->pushButton5,SIGNAL(clicked(bool)),this,SLOT(OpenPage5()));
    connect(ui->pushButton6,SIGNAL(clicked(bool)),this,SLOT(close()));

    //设置背景图片
    QPixmap pixmap = QPixmap(":/background.jpg").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Background, QBrush(pixmap));
    this->setPalette(palette);

}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage:: OpenPage1()
{
    Page1 page;
    page.exec();
}

void MainPage:: OpenPage2()
{
    Page2 page;
    page.exec();
}
void MainPage:: OpenPage3()
{
    Page3 page;
    page.exec();
}
void MainPage:: OpenPage4()
{
    Page4 page;
    page.exec();
}
void MainPage:: OpenPage5()
{
    Page5 page;
    page.exec();
}

void SetStudentGrade()
{
    QFile file("grade.txt");
    num=0;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    counta=0;
    QTextStream in(&file);
    in.seek(0);
    while (!in.atEnd()) {
        QString line = in.readLine();
        counta++;
    }
    in.seek(0);
    QTextCodec *code=QTextCodec::codecForName("UTF8");  //注意设置编码！！
    in.setCodec(code);

    stugrade=new StudentGrade[counta];
    Info test;
    int flag=0,i=0,k=0;
    QString term,sname,Class,number,cname;
    int credit;
    double mark;
    while (!in.atEnd())//逐行读取文本，并去除每行的回车
    {
        flag=0;
        QString line;
        line = in.readLine() ;
        line.remove('\n');
        QStringList string_list;
        string_list=line.split(" ");   //分割文本 用元素初始化对象
        term=string_list[0];
        sname=string_list[1];
        Class=string_list[2];
        number=string_list[3];
        cname=string_list[4];
        credit=string_list[5].toInt();
        mark=string_list[6].toDouble();
        test.set(mark,term,cname,credit,sname,Class,number);
        for(k=0;k<=i;k++)
        {
            if(number==stugrade[k].GetId()) {flag=1;break;}
            if(stugrade[k].GetId()=="") break;
        }
        if(flag==0) num++;	//确定系统中学生人数

        //统计信息
        stugrade[k].set(sname,Class,number);

        if(term=="2017秋季学期")
        {
            stugrade[k].GetUpCredit()+=credit;
            stugrade[k].GetUpGpa()+=test.GetCredit()*test.GetGpa();
            if(mark<60)
            {
                stugrade[k].GetUpFailCredit()+=credit;
                stugrade[k].GetUpFailNumber()+=1;
            }
        }
        if(term=="2018春季学期")
        {
            stugrade[k].GetDownCredit()+=credit;
            stugrade[k].GetDownGpa()+=test.GetCredit()*test.GetGpa();
            if(mark<60)
            {
                stugrade[k].GetDownFailCredit()+=credit;
                stugrade[k].GetDownFailNumber()+=1;
            }
        }
        i++;
    }
    file.close();
    //在获得完整版信息后完善信息
    for(i=0;i<num;i++)
    {
        stugrade[i].GetTotalCredit()=stugrade[i].GetUpCredit()+stugrade[i].GetDownCredit();
        stugrade[i].GetTotalFailNumber()=stugrade[i].GetUpFailNumber()+stugrade[i].GetDownFailNumber();
        stugrade[i].GetTotalFailCredit()=stugrade[i].GetUpFailCredit()+stugrade[i].GetDownFailCredit();
        if(stugrade[i].GetUpCredit()!=0) stugrade[i].GetUpGpa()/=stugrade[i].GetUpCredit();
        if(stugrade[i].GetDownCredit()!=0) stugrade[i].GetDownGpa()/=stugrade[i].GetDownCredit();
        stugrade[i].GetTotalGpa()=(stugrade[i].GetUpGpa()*stugrade[i].GetUpCredit()+stugrade[i].GetDownGpa()*stugrade[i].GetDownCredit())/stugrade[i].GetTotalCredit();
    }
}
