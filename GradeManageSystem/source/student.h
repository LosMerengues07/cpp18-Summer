#ifndef STUDENT_H
#define STUDENT_H
#include<QString>

//学生类（包含姓名、班级、学号）
class Student
{
public:
    Student(QString sname = "\0", QString class_name = "\0", QString id = "\0");
    QString GetSname();  //返回学生姓名
    QString GetClass();  //返回班级名
    QString GetId();  //返回学号
    void set(QString sname, QString class_name, QString id);
    ~Student() {}
protected:
    QString student_name_;	//学生姓名
    QString class_name_;
    QString id_;
};


#endif // STUDENT_H
