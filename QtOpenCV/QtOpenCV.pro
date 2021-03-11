QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    imagebaseinfo.cpp \
    main.cpp \
    mainwindow.cpp \
    statusbar.cpp

HEADERS += \
    imagebaseinfo.h \
    mainwindow.h \
    statusbar.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    QtOpenCV_zh_CN.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#INCLUDEPATH += D:\OpenCV\opencv-3.4.13-build\install\include
#               D:\OpenCV\opencv-3.4.13-build\install\include\opencv
#               D:\OpenCV\opencv-3.4.13-build\install\include\opencv2

INCLUDEPATH += C:\Users\MHD\Desktop\opencv-build\install\include
               C:\Users\MHD\Desktop\opencv-build\install\include\opencv
               C:\Users\MHD\Desktop\opencv-build\install\include\opencv2

# LIBS += D:\OpenCV\opencv-3.4.13-build\lib\libopencv_*.a
LIBS += C:\Users\MHD\Desktop\opencv-build\lib\libopencv_*.a

RESOURCES += \
    Resources.qrc
