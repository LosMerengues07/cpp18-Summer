#-------------------------------------------------
#
# Project created by QtCreator 2018-09-08T00:42:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GradeManageSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    page1.cpp \
    page2.cpp \
    page3.cpp \
    page4.cpp \
    page5.cpp \
    student.cpp \
    grade.cpp \
    info.cpp \
    mian_page.cpp \
    student_grade.cpp

HEADERS += \
    page1.h \
    page2.h \
    page3.h \
    page4.h \
    page5.h \
    course.h \
    student.h \
    grade.h \
    info.h \
    main_page.h \
    student_grade.h

FORMS += \
    page1.ui \
    page2.ui \
    page3.ui \
    page4.ui \
    page5.ui \
    main_page.ui

DISTFILES +=

RESOURCES += \
    rc.qrc
RC_FILE = proj.rc


