QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += ./inc

DEFINES += STB_IMAGE_IMPLEMENTATION

SOURCES += \
        ./src/main.cpp\
        ./src/glad.c\
        ./src/shader.cpp \
        ./src/camera.cpp \
        ./src/mesh.cpp

LIBS +=  -lglfw3 -lGL -lX11 -ldl


HEADERS += \
    inc/shader.h\
    inc/stb_image.h\
    inc/camera.h \
    inc/mesh.h

DESTDIR += ../bin
