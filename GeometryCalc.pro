QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

Target = GeometryCalc
MOC_DIR = moc_dir
OBJECTS_DIR = o_dir

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Sources/Cerchio.cpp \
    Sources/Controller.cpp \
    Sources/FiguraPiana.cpp \
    Sources/Model.cpp \
    Sources/Quadrato.cpp \
    Sources/Rettangolo.cpp \
    Sources/Trapezio.cpp \
    Sources/TrapezioIsoscele.cpp \
    Sources/TrapezioRettangolo.cpp \
    Sources/Triangolo.cpp \
    Sources/TriangoloEquilatero.cpp \
    Sources/TriangoloIsoscele.cpp \
    Sources/TriangoloRettangolo.cpp \
    Sources/View.cpp \
    Sources/main.cpp

HEADERS += \
    Headers/Cerchio.h \
    Headers/Contenitore.h \
    Headers/Controller.h \
    Headers/DeepPtr.h \
    Headers/FiguraPiana.h \
    Headers/Model.h \
    Headers/Quadrato.h \
    Headers/Rettangolo.h \
    Headers/Trapezio.h \
    Headers/TrapezioIsoscele.h \
    Headers/TrapezioRettangolo.h \
    Headers/Triangolo.h \
    Headers/TriangoloEquilatero.h \
    Headers/TriangoloIsoscele.h \
    Headers/TriangoloRettangolo.h \
    Headers/View.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    risorse.qrc
