#include "student.h"

Student::Student(QString sname, QString class_name, QString id)
{
    student_name_ = sname;
    class_name_ = class_name;
    id_ = id;
}

void Student::set(QString sname, QString class_name, QString id)
{
    student_name_ = sname;
    class_name_ = class_name;
    id_ = id;
}
QString Student::GetSname()
{
    return student_name_;
}

QString Student::GetClass()
{
    return class_name_;
}

QString Student::GetId()
{
    return id_;
}
