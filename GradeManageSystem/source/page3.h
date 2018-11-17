#ifndef PAGE3_H
#define PAGE3_H

#include <QDialog>

namespace Ui {
class Page3;
}

class Page3 : public QDialog
{
    Q_OBJECT

public:
    explicit Page3(QWidget *parent = 0);
    ~Page3();
public slots:
    void PressEnterButton();

private:
    Ui::Page3 *ui;
};

#endif // PAGE3_H
