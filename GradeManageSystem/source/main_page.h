#ifndef GRADEMANAGESYSTEM_H
#define GRADEMANAGESYSTEM_H

#include <QMainWindow>

namespace Ui {
class GradeManageSystem;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

private:
    Ui::GradeManageSystem *ui;

public slots:
    void OpenPage1();
    void OpenPage2();
    void OpenPage3();
    void OpenPage4();
    void OpenPage5();

};

#endif // GRADEMANAGESYSTEM_H
