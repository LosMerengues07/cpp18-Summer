//存放各种界面界面
#include"course.h"
#include"grade.h"
#include"info.h"
#include"student.h"
#include"studentgrade.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <fstream>
//using namespace std;

int counta=0;					//全局变量,文件内有效信息数
studentGrade *stugrade=NULL;	//全局变量，文件内的每位学生成绩的对象数组的首地址
int num=0;						//全局变量，文件内学生数

void update1();				//更新文件，删除修改前的学生成绩
void update2();				//制作所有学生的studentGrade对象

/*
//更新文件，删除修改前的学生成绩
void update1()
{
    counta=0;
    ifstream infile("grade.txt",ios::in|ios::_Nocreate);
    if(!infile)
    {
        cout<<"文件grade.txt无法打开，按任意键退出系统\n";
        _getwch();
        page6();
    }

//统计文件中的信息数，便于创建录入信息类对象数组
    int n=0;
    while(1)
    {
        if(infile.get()=='\n')	n++;
        if(infile.fail()) break;
    }
    infile.clear();infile.sync();
    infile.seekg(0);
//创建录入信息类对象数组，存放最新版本的信息
    Info *p=new Info[n];
    string term,sname,Class,number,cname;
    double mark;
    int credit;
    int i=0;
    int k=0,flag=0;
    for(i=0;i<n;i++)
    {
        flag=0;
        infile>>term>>sname>>Class>>number>>cname>>credit>>mark;
        for(k=0;k<i;k++)
        {
            if(term==p[k].getTerm()&&number==p[k].getNum()&&cname==p[k].getCName()) {flag=1;break;}
        }
        if(flag==0) {p[counta].set(mark,term,cname,credit,sname,Class,number);counta++;}
        else p[k].set(mark,term,cname,credit,sname,Class,number);
    }
    infile.close();

//将最新版本的信息写入文件
    ofstream outfile("grade.txt",ios::out|ios::trunc);
    if(!outfile)
    {
        cout<<"文件grade.txt无法打开，按任意键退出系统\n";
        _getwch();
        page6();
    }
    for(i=0;i<counta;i++)
    {
        outfile<<p[i].getTerm()<<" "<<p[i].getSname()<<" "<<p[i].getClass()<<" "<<p[i].getNum()<<" "<<p[i].getCName()<<" "<<p[i].getCredit()<<" "<<p[i].getMark()<<endl;
    }

    outfile.close();
    delete []p;
}

//制作所有学生的studentGrade类对象数组
void update2()
{
    stugrade=new studentGrade[counta];
    ifstream infile("grade.txt",ios::in|ios::_Nocreate);
    if(!infile)
    {
        cout<<"文件grade.txt无法打开，按任意键退出系统\n";
        _getwch();
        page6();
    }

    Info test;

    int flag=0,i=0,k=0;
    string term,sname,Class,number,cname;
    int credit;
    double mark;
    for(i=0;i<counta;i++)
    {
        flag=0;
        infile>>term>>sname>>Class>>number>>cname>>credit>>mark;

        //用信息对象得到完整版信息
        test.set(mark,term,cname,credit,sname,Class,number);

        for(k=0;k<=i;k++)
        {
            if(number==stugrade[k].getNum()) {flag=1;break;}
            if(stugrade[k].getNum()=="") break;
        }

        if(flag==0) num++;	//确定系统中学生人数

        //统计信息
        stugrade[k].set(sname,Class,number);
        if(term=="大一上学期")
        {
            stugrade[k].getupCredit()+=credit;
            stugrade[k].getupGpa()+=test.getCredit()*test.getGpa();
            if(mark<60)
                {
                    stugrade[k].getupFailCredit()+=credit;
                    stugrade[k].getupFailNumber()+=1;
                }
        }
        if(term=="大一下学期")
        {
            stugrade[k].getdownCredit()+=credit;
            stugrade[k].getdownGpa()+=test.getCredit()*test.getGpa();
            if(mark<60)
                {
                    stugrade[k].getdownFailCredit()+=credit;
                    stugrade[k].getdownFailNumber()+=1;
                }
        }
    }
    infile.close();

    //在获得完整版信息后完善信息
    for(i=0;i<num;i++)
    {
        stugrade[i].gettotalCredit()=stugrade[i].getupCredit()+stugrade[i].getdownCredit();
        stugrade[i].gettotalFailNumber()=stugrade[i].getupFailNumber()+stugrade[i].getdownFailNumber();
        stugrade[i].gettotalFailCredit()=stugrade[i].getupFailCredit()+stugrade[i].getdownFailCredit();
        if(stugrade[i].getupCredit()!=0) stugrade[i].getupGpa()/=stugrade[i].getupCredit();
        if(stugrade[i].getdownCredit()!=0) stugrade[i].getdownGpa()/=stugrade[i].getdownCredit();
        stugrade[i].gettotalGpa()=(stugrade[i].getupGpa()*stugrade[i].getupCredit()+stugrade[i].getdownGpa()*stugrade[i].getdownCredit())/stugrade[i].gettotalCredit();
    }
}

*/

