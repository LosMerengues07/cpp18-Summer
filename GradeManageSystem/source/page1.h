#ifndef PAGE1_H
#define PAGE1_H

#include <QDialog>

namespace Ui {
class Page1;
}

class Page1 : public QDialog
{
    Q_OBJECT

public:
    explicit Page1(QWidget *parent = 0);
    ~Page1();
public slots:
    void PressEnterButton();
private:
    Ui::Page1 *ui;
};

#endif // PAGE1_H
