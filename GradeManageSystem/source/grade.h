#ifndef GRADE_H
#define GRADE_H
#include"course.h"
#include<QString>

//成绩类（继承课程信息类，包含分数、等级、学分绩、是否挂科四个变量）
class Grade : public Course
{
public:
    Grade(double grade = 0, QString term = "\0", QString subject = "\0", int credit = 0);	//level,gpa,flag等变量通过grade的值确定
    virtual void set(double grade, QString term, QString subject, int credit);
    ~Grade() {}
protected:
    double grade_;   //百分制分数
    QString level_;	//成绩对应的等级，如A+等
    double gpa_;
    bool flag_;	//是否挂科变量，true表示挂科，false表示未挂科
};
#endif // GRADE_H
