#include "main_page.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainPage w;
    w.show();

    return a.exec();
}
