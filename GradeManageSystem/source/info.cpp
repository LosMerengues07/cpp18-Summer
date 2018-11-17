#include "info.h"
#include<ostream>
#include<QString>

Info::Info(double grade, QString term, QString subject, int credit, QString sname, QString class_name, QString id)
    : Grade(grade, term, subject, credit), Student(sname, class_name, id)
{}

void Info::set(double grade, QString term, QString subject, int credit, QString sname, QString class_name, QString id)
{
    Grade::set(grade, term, subject, credit);
    Student::set(sname, class_name, id);
}

QString Info::GetTerm()
{
    return term_;
}

QString Info::GetSubject()
{
    return subject_;
}
QString Info::GetLevel()
{
    return level_;
}

int Info::GetCredit()
{
    return credit_;
}

double Info::GetGrade()
{
    return grade_;
}

double Info::GetGpa()
{
    return gpa_;
}

QString& Info::operator =(QString &str)
{
    str=term_+" "+subject_+" "+credit_+" "+grade_+" "+level_+" "+gpa_;
    return str;
}



