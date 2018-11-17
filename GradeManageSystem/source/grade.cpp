#include "grade.h"

Grade::Grade(double grade, QString term, QString subject, int credit) :Course(term, subject, credit)
{
    grade_ = grade;
    if (grade_ < 60) { flag_ = true; gpa_ = 0; level_ = "F"; }
    else
    {
        flag_ = false;
        if (grade_ >= 60 && grade_ <= 62) { gpa_ = 1; level_ = "D"; }
        else if (grade_ >= 63 && grade_ <= 66) { gpa_ = 1.3; level_ = "D+"; }
        else if (grade_ >= 67 && grade_ <= 69) { gpa_ = 1.7; level_ = "C-"; }
        else if (grade_ >= 70 && grade_ <= 72) { gpa_ = 2.0; level_ = "C"; }
        else if (grade_ >= 73 && grade_ <= 76) { gpa_ = 2.3; level_ = "C+"; }
        else if (grade_ >= 77 && grade_ <= 79) { gpa_ = 2.7; level_ = "B-"; }
        else if (grade_ >= 80 && grade_ <= 84) { gpa_ = 3.0; level_ = "B"; }
        else if (grade_ >= 85 && grade_ <= 89) { gpa_ = 3.3; level_ = "B+"; }
        else if (grade_ >= 90 && grade_ <= 94) { gpa_ = 3.7; level_ = "A-"; }
        else if (grade_ >= 95) { gpa_ = 4.0; level_ = "A"; }
    }
}


void Grade::set(double grade, QString term, QString subject, int credit)
{
    grade_ = grade;
    if (grade_ < 60) { flag_ = true; gpa_ = 0; level_ = "F"; }
    else
    {
        flag_ = false;
        if (grade_ >= 60 && grade_ <= 62) { gpa_ = 1; level_ = "D"; }
        else if (grade_ >= 63 && grade_ <= 66) { gpa_ = 1.3; level_ = "D+"; }
        else if (grade_ >= 67 && grade_ <= 69) { gpa_ = 1.7; level_ = "C-"; }
        else if (grade_ >= 70 && grade_ <= 72) { gpa_ = 2.0; level_ = "C"; }
        else if (grade_ >= 73 && grade_ <= 76) { gpa_ = 2.3; level_ = "C+"; }
        else if (grade_ >= 77 && grade_ <= 79) { gpa_ = 2.7; level_ = "B-"; }
        else if (grade_ >= 80 && grade_ <= 84) { gpa_ = 3.0; level_ = "B"; }
        else if (grade_ >= 85 && grade_ <= 89) { gpa_ = 3.3; level_ = "B+"; }
        else if (grade_ >= 90 && grade_ <= 94) { gpa_ = 3.7; level_ = "A-"; }
        else if (grade_ >= 95) { gpa_ = 4.0; level_ = "A"; }
    }
    term_ = term;
    subject_ = subject;
    credit_ = credit;
}
