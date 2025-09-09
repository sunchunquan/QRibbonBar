QMAKE_PROJECT_DEPTH = 0

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CustomRibbonBar.cpp \
    RibbonGroup.cpp \
    RibbonTab.cpp \
    main.cpp \
    QRibbonBar.cpp

HEADERS += \
    CustomRibbonBar.h \
    NativeWindowTemplate.hpp \
    QRibbonBar.h \
    RibbonGroup.h \
    RibbonTab.h

FORMS += \
    QRibbonBar.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/3rdParty/QAppModel/include
INCLUDEPATH += $$PWD/3rdParty/QMYUI/include
INCLUDEPATH += $$PWD/3rdParty/log4cpp/include
INCLUDEPATH += $$PWD/3rdParty/QXlsx/include

# 如果是Debug构建
CONFIG(debug, debug|release) {
    message("Debug build")
    # 在这里添加Debug构建时特有的编译选项或者路径等
    DEFINES += QT_DEPRECATED_WARNINGS
    contains(QT_ARCH, i386) {
        message("32-bit")
        LIBS += -L$$PWD/3rdParty/QAppModel/lib/X86/Debug -lQAppModel_d
        LIBS += -L$$PWD/3rdParty/QMYUI/lib/X86/Debug -lQMYUI_d
        LIBS += -L$$PWD/3rdParty/log4cpp/lib/X86/Debug -llog4cpp_d
        LIBS += -L$$PWD/3rdParty/QXlsx/lib/X86/Debug -lQXlsxd
    } else {
        message("64-bit")
        LIBS += -L$$PWD/3rdParty/QAppModel/lib/X64/Debug -lQAppModel_d
        LIBS += -L$$PWD/3rdParty/QMYUI/lib/X64/Debug -lQMYUI_d
        LIBS += -L$$PWD/3rdParty/log4cpp/lib/X64/Debug -llog4cpp
        LIBS += -L$$PWD/3rdParty/QXlsx/lib/X64/Debug -lQXlsxd
    }
}
# 如果是Release构建
CONFIG(release, debug|release) {
    message("Release build")
    # 在这里添加Release构建时特有的编译选项或者路径等
    DEFINES += QT_NO_DEBUG_OUTPUT
    QMAKE_CXXFLAGS += -O2 # 启用优化
    contains(QT_ARCH, i386) {
        message("32-bit")
        LIBS += -L$$PWD/3rdParty/QAppModel/lib/X86/Release -lQAppModel
        LIBS += -L$$PWD/3rdParty/QMYUI/lib/X86/Release -lQMYUI
        LIBS += -L$$PWD/3rdParty/log4cpp/lib/X86/Release -llog4cpp
        LIBS += -L$$PWD/3rdParty/QXlsx/lib/X86/Release -lQXlsx
    } else {
        message("64-bit")
        LIBS += -L$$PWD/3rdParty/QAppModel/lib/X64/Release -lQAppModel
        LIBS += -L$$PWD/3rdParty/QMYUI/lib/X64/Release -lQMYUI
        LIBS += -L$$PWD/3rdParty/log4cpp/lib/X64/Release -llog4cpp
        LIBS += -L$$PWD/3rdParty/QXlsx/lib/X64/Release -lQXlsx
    }
}

LIBS += -ldwmapi
LIBS += -lUser32

RESOURCES += \
    QRibbonBar.qrc
