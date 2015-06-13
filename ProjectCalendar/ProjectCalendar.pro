
CONFIG   -= x86_64
QT += widgets
/NODEFAULTLIB:msvcrt.lib
QT += xml

SOURCES += \
    main.cpp \
    tache.cpp \
    projet.cpp \
    calendrier.cpp \
    tacheediteur.cpp \
    timing.cpp \
    activite.cpp \
    projetManager.cpp \
    programtask.cpp \
    projectmain.cpp \
    newprojectwindow.cpp
HEADERS += \
    ProjC.h \
    tache.h \
    projet.h \
    activite.h \
    calendrier.h \
    tacheediteur.h \
    timing.h \
    projetManager.h \
    programtask.h \
    projectmain.h \
    newprojectwindow.h

FORMS += \
    programtask.ui \
    projectmain.ui \
    newprojectwindow.ui
