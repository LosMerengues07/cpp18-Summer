#ifndef STUDENTGRADE_H
#define STUDENTGRADE_H
#include"student.h"
#include<QString>

//学生成绩类（继承学生类，包含上、下学期及整个学年所修学分、平均gpa、挂科数、挂科总学分）
class StudentGrade : public Student
{
public:
    StudentGrade(const char* name = "\0", const char* class_name_ = "\0", const char* num = "\0", const int up_credit_ = 0, const int down_credit_ = 0, double up_gpa_ = 0, double down_gpa_ = 0, int up_fail_number = 0, int down_fail_number = 0, int up_fail_credit = 0, int down_fail_credit = 0);
    QString GetId() { return id_; }

    //传回变量地址以修改
    //up代表上学期 down代表下学期
    int& GetUpCredit();
    int& GetDownCredit();
    int& GetTotalCredit();
    double& GetUpGpa();
    double& GetDownGpa();
    double& GetTotalGpa();
    int& GetUpFailNumber();
    int& GetDownFailNumber();
    int& GetTotalFailNumber();
    int& GetUpFailCredit();
    int& GetDownFailCredit();
    int& GetTotalFailCredit();
    ~StudentGrade() {}
protected:
    int up_credit_, down_credit_, total_credit_;
    double up_gpa_, down_gpa_, total_gpa_;
    int up_fail_number=0, down_fail_number=0, total_fail_number=0;
    int up_fail_credit=0, down_fail_credit=0, total_fail_credit=0;
};

#endif // STUDENTGRADE_H
