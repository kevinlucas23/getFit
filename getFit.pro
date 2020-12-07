QT       += core gui multimedia charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dailyexercise.cpp \
    foodintake.cpp \
    graphsuggest.cpp \
    inputoutput.cpp \
    liftprogram.cpp \
    lifttips.cpp \
    main.cpp \
    getfit.cpp \
    mainmenu.cpp \
    rpe.cpp \
    showgraphs.cpp \
    sleep.cpp \
    sleeptips.cpp \
    suggestions.cpp \
    updateweight.cpp \
    usercreation.cpp \
    weightlifting.cpp

HEADERS += \
    dailyexercise.h \
    foodintake.h \
    getfit.h \
    graphsuggest.h \
    inputoutput.h \
    liftprogram.h \
    lifttips.h \
    mainmenu.h \
    rpe.h \
    showgraphs.h \
    sleep.h \
    sleeptips.h \
    suggestions.h \
    updateweight.h \
    usercreation.h \
    weightlifting.h

FORMS += \
    dailyexercise.ui \
    foodintake.ui \
    getfit.ui \
    graphsuggest.ui \
    liftprogram.ui \
    lifttips.ui \
    mainmenu.ui \
    rpe.ui \
    showgraphs.ui \
    sleep.ui \
    sleeptips.ui \
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
