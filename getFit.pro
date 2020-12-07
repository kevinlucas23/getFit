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
    lifttips.cpp \
    main.cpp \
    getfit.cpp \
    mainmenu.cpp \
    password_recovery.cpp \
    showgraphs.cpp \
    sleep.cpp \
    sleeptips.cpp \
    suggestions.cpp \
    updatepassword.cpp \
    updateweight.cpp \
    usercreation.cpp \
    weightlifting.cpp \
    wgraphs.cpp

HEADERS += \
    dailyexercise.h \
    foodintake.h \
    getfit.h \
    graphsuggest.h \
    inputoutput.h \
    lifttips.h \
    mainmenu.h \
    password_recovery.h \
    showgraphs.h \
    sleep.h \
    sleeptips.h \
    suggestions.h \
    updatepassword.h \
    updateweight.h \
    usercreation.h \
    weightlifting.h \
    wgraphs.h

FORMS += \
    dailyexercise.ui \
    foodintake.ui \
    getfit.ui \
    graphsuggest.ui \
    lifttips.ui \
    mainmenu.ui \
    password_recovery.ui \
    showgraphs.ui \
    sleep.ui \
    sleeptips.ui \
    suggestions.ui \
    updatepassword.ui \
    updateweight.ui \
    usercreation.ui \
    weightlifting.ui \
    wgraphs.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Greens.png \
    UAuth.json \
    beans.png \
    bench.png \
    chicken.png \
    deadlift.png \
    milk.png \
    nuts.png \
    pic.jpg \
    pic1.jpg \
    pic2.jpg \
    pic3.jpg \
    potatoes.png \
    rice.png \
    salmon.png \
    scale.png \
    sleep.png \
    sleep2.png \
    squat.png \
    tuna.png \
    yogurt.png
