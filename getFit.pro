QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    caloriegoal.cpp \
    dailyexercise.cpp \
    foodintake.cpp \
    graphsuggest.cpp \
    inputoutput.cpp \
    main.cpp \
    getfit.cpp \
    mainmenu.cpp \
    menu.cpp \
    showgraphs.cpp \
    sleep.cpp \
    suggestions.cpp \
    updateweight.cpp \
    usercreation.cpp \
    weightlifting.cpp

HEADERS += \
    caloriegoal.h \
    dailyexercise.h \
    foodintake.h \
    getfit.h \
    graphsuggest.h \
    inputoutput.h \
    mainmenu.h \
    menu.h \
    showgraphs.h \
    sleep.h \
    suggestions.h \
    updateweight.h \
    usercreation.h \
    weightlifting.h

FORMS += \
    caloriegoal.ui \
    dailyexercise.ui \
    foodintake.ui \
    getfit.ui \
    graphsuggest.ui \
    mainmenu.ui \
    menu.ui \
    showgraphs.ui \
    sleep.ui \
    suggestions.ui \
    updateweight.ui \
    usercreation.ui \
    weightlifting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    UAuth.json \
    pic.jpg \
    pic2.jpg \
    pic3.jpg
