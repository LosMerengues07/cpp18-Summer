#ifndef COURSE_H
#define COURSE_H
#include<QString>

//抽象类：课程信息类（包含开课时间、名称、所占学分三个变量）
class Course
{
public:
    Course(QString term = "\0", QString subject = "\0", int credit = 0):term_(term),subject_(subject),credit_(credit){}
    virtual void set(double m, QString a, QString b, int c) = 0;
    virtual void set(double m, QString a, QString b, int c, QString d, QString e, QString f) = 0;
    ~Course() {}
protected:
    QString term_;
    QString subject_;	//课程名
    int credit_;
};


#endif // COURSE_H
