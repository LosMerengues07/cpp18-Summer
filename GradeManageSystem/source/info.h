#ifndef INFO_H
#define INFO_H
#include"grade.h"
#include"student.h"
//录入信息类（继承成绩类、学生类）
class Info : public Grade, public Student
{
public:
    Info(double grade = 0, QString term = "\0", QString subject = "\0", int credit = 0, QString sname = "\0", QString class_name = "\0", QString id = "\0");
    virtual void set(double grade, QString term, QString subject, int credit, QString sname, QString class_name, QString id);
    QString GetTerm();	//返回该条信息中课程所在学期
    QString GetSubject();	//返回该条信息中课程名
    double GetGpa();	//返回该条信息中课程学分绩
    int GetCredit();	//返回该条信息中课程学分
    double GetGrade();	//返回该条信息中课程分数
    QString GetLevel();
    ~Info() {}
    QString& operator =(QString &str);    //重载赋值运算符以方便对对象赋值
};
#endif // INFO_H
