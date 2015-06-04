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
    projetManager.c
HEADERS += \
    ProjC.h \
    tache.h \
    projet.h \
    activite.h \
    calendrier.h \
    tacheediteur.h \
    timing.h \
    projetManager.h

FORMS += \
    projectViewer.ui
