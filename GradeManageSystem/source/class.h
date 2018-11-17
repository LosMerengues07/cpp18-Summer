#ifndef CLASS_H
#define CLASS_H
#include<QString>
//课程信息类（包含开课时间、名称、所占学分三个变量）
    class Course
    {
    public:
        Course(QString a = "\0", QString b = "\0", int c = 0);
        virtual void set(double m, QString a, QString b, int c) = 0;
        virtual void set(double m, QString a, QString b, int c, QString d, QString e, QString f) = 0;
        ~Course() {}
    protected:
        QString term;
        QString cname;	//课程名
        int credit;
    };


    //成绩类（继承课程信息类，包含分数、等级、学分绩、是否挂科四个变量）
    class Grade : public Course
    {
    public:
        Grade(double m = 0, QQString a = "\0", QString b = "\0", int c = 0);	//level,gpa,flag等变量通过a的值确定
        virtual void set(double m, QString a, QString b, int c);
        ~Grade() {}
    protected:
        double mark;
        QString level;	//成绩对应的等级，如A+等
        double gpa;
        bool flag;	//是否挂科变量，true表示挂科，false表示未挂科
    };


    //学生类（包含姓名、班级、学号）
    class Student
    {
    public:
        Student(QString a = "\0", QString b = "\0", QString c = "\0");
        QString getSname();
        QString getClass();
        QString getNum();
        void set(QString a, QString b, QString c);
        ~Student() {}
    protected:
        QString sname;	//学生姓名
        QString Class;
        QString number;
    };


    //录入信息类（继承成绩类、学生类）
    class Info : public Grade, public Student
    {
    public:
        Info(double m = 0, QString a = "\0", QString b = "\0", int c = 0, QString d = "\0", QString e = "\0", QString f = "\0");
        virtual void set(double m, QString a, QString b, int c, QString d, QString e, QString f);
        QString getTerm();	//返回该条信息中课程所在学期
        QString getCName();	//返回该条信息中课程名
        double getGpa();	//返回该条信息中课程学分绩
        int getCredit();	//返回该条信息中课程学分
        double getMark();	//返回该条信息中课程分数
        friend ostream& operator <<(ostream&, Info&);	//重载流插入运算符便于输出考生所见成绩信息
        ~Info() {}
    };


    //学生成绩类（继承学生类，包含上、下学期及整个学年所修学分、平均gpa、挂科数、挂科总学分）
    class studentGrade : public Student
    {
    public:
        studentGrade(const char* name = "\0", const char* Class = "\0", const char* num = "\0", const int upCredit = 0, const int downCredit = 0, double upGpa = 0, double downGpa = 0, int upFailNumber = 0, int downFailNumber = 0, int upFailCredit = 0, int downFailCredit = 0);
        QString getNum() { return number; }

        //传回变量地址以修改
        int& getupCredit();
        int& getdownCredit();
        int& gettotalCredit();
        double& getupGpa();
        double& getdownGpa();
        double& gettotalGpa();
        int& getupFailNumber();
        int& getdownFailNumber();
        int& gettotalFailNumber();
        int& getupFailCredit();
        int& getdownFailCredit();
        int& gettotalFailCredit();
        ~studentGrade() {}
    protected:
        int upCredit, downCredit, totalCredit;
        double upGpa, downGpa, totalGpa;
        int upFailNumber, downFailNumber, totalFailNumber;
        int upFailCredit, downFailCredit, totalFailCredit;
    };


#endif // CLASS_H
