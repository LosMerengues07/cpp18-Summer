#include "student_grade.h"

StudentGrade::StudentGrade(const char* name, const char* Class, const char* num, int upCredit, int downCredit, double upGpa, double downGpa, int upFailNumber, int downFailNumber, int upFailCredit, int downFailCredit) : Student(name, Class, num)
{
    this->up_credit_ = upCredit; this->down_credit_ = downCredit;
    total_credit_ = upCredit + downCredit;

    this->up_gpa_ = upGpa; this->down_gpa_ = downGpa;
    total_gpa_ = (upGpa*upCredit + downGpa * downCredit) / (upCredit + downCredit);

    //this->upFailNumber = upFailNumber; this->downFailNumber = downFailNumber;
    total_fail_number = upFailNumber + downFailNumber;

    //this->upFailCredit = upFailCredit; this->downFailCredit = downFailCredit;
    total_fail_credit = upFailCredit + downFailCredit;
}


int& StudentGrade::GetUpCredit()
{
    return up_credit_;
}

int& StudentGrade::GetDownCredit()
{
    return down_credit_;
}

int& StudentGrade::GetTotalCredit()
{
    return total_credit_;
}

double& StudentGrade::GetUpGpa()
{
    return up_gpa_;
}

double& StudentGrade::GetDownGpa()
{
    return down_gpa_;
}

double& StudentGrade::GetTotalGpa()
{
    return total_gpa_;
}

int& StudentGrade::GetUpFailNumber()
{
    return up_fail_number;
}

int& StudentGrade::GetDownFailNumber()
{
    return down_fail_number;
}

int& StudentGrade::GetTotalFailNumber()
{
    return total_fail_number;
}

int& StudentGrade::GetUpFailCredit()
{
    return up_fail_credit;
}

int& StudentGrade::GetDownFailCredit()
{
    return down_fail_credit;
}

int& StudentGrade::GetTotalFailCredit()
{
    return total_fail_credit;
}

