#include "QRibbonBar.h"
#include <QApplication>
#include <QMainWindow>
#include "QMYIconHelper.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // QMainWindow mainWindow;
    // mainWindow.setWindowFlags(Qt::FramelessWindowHint);;
    // mainWindow.setWindowTitle("Custom RibbonBar Demo");
    // mainWindow.resize(1280, 768);
    // //mainWindow.setAttribute(Qt::WA_TranslucentBackground);
    // mainWindow.setStyleSheet(
    //     "QMainWindow {"
    //     "   background: qlineargradient(x1:0.3, y1:0.3, x2:1, y2:1, stop:0 #3498db, stop:1 #2ecc71);"
    //     "   border-radius: 15px;"
    //     "}"
    //     "QWidget#centralWidget {"  // 中央部件也需要设置
    //     "    background: transparent;"
    //     "    border-radius: 15px;"
    //     "}"
    //     );

    // QPalette pal(mainWindow.palette());
    // pal.setColor(QPalette::Background, QColor("#001441"));
    // mainWindow.setAutoFillBackground(true);
    // mainWindow.setPalette(pal);

    // // 创建自定义 RibbonBar
    // CustomRibbonBar *ribbonBar = new CustomRibbonBar(&mainWindow);

    // // 添加标签页
    // RibbonTab *homeTab = ribbonBar->addTab(QStringLiteral("主页"), 0xf015);
    // RibbonTab *insertTab = ribbonBar->addTab(QStringLiteral("插入"), 0xf068);
    // RibbonTab *viewTab = ribbonBar->addTab(QStringLiteral("视图"), 0xf00d);

    // // 为 Home 标签页添加组
    // QList<QToolButton*> clipboardButtons;

    // QToolButton *pasteBtn = new QToolButton();
    // pasteBtn->setText(QStringLiteral("复制"));
    // pasteBtn->setMinimumSize(40,40);
    // pasteBtn->setIcon(QIcon("://Resources/image/add-nomal.png"));
    // pasteBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    // pasteBtn->setStyleSheet(
    //         "QToolButton {"
    //         "  background-color: transparent;"
    //         "  color: white;"
    //         "  border: none;"
    //         "  padding: 5px 8px;"
    //         "  margin: 2px;"
    //         "  font-size: 13px;"
    //         "  text-align: center;"
    //         "}"
    //         "QToolButton:hover {"
    //         "  background-color: rgba(255, 255, 255, 0.2);"
    //         "  border-radius: 3px;"
    //         "}"
    //         "QToolButton:pressed {"
    //         "  background-color: rgba(255, 255, 255, 0.1);"
    //         "}"
    //         );

    // clipboardButtons.append(pasteBtn);

    // QToolButton *cutBtn = new QToolButton();
    // cutBtn->setText("Cut");
    // cutBtn->setIcon(QIcon::fromTheme("edit-cut"));
    // clipboardButtons.append(cutBtn);

    // QToolButton *copyBtn = new QToolButton();
    // copyBtn->setText("Copy");
    // copyBtn->setIcon(QIcon::fromTheme("edit-copy"));
    // clipboardButtons.append(copyBtn);

    // ribbonBar->addGroup(homeTab, "", clipboardButtons);


    // // 添加字体组
    // QList<QToolButton*> fontButtons;

    // QToolButton *boldBtn = new QToolButton();
    // boldBtn->setText("Bold");
    // boldBtn->setIcon(QIcon::fromTheme("format-text-bold"));
    // fontButtons.append(boldBtn);

    // QToolButton *italicBtn = new QToolButton();
    // italicBtn->setText("Italic");
    // italicBtn->setIcon(QIcon::fromTheme("format-text-italic"));
    // fontButtons.append(italicBtn);

    // ribbonBar->addGroup(homeTab, "", fontButtons);
    // //ribbonBar->setCurrentTab(insertTab);

    // // 添加字体组
    // QList<QToolButton*> fontButtons1;

    // QToolButton *boldBtn1 = new QToolButton();
    // boldBtn1->setText("Bold1");
    // boldBtn1->setIcon(QIcon::fromTheme("format-text-bold"));
    // fontButtons1.append(boldBtn1);

    // QToolButton *italicBtn1 = new QToolButton();
    // italicBtn1->setText("Italic1");
    // italicBtn1->setIcon(QIcon::fromTheme("format-text-italic"));
    // fontButtons1.append(italicBtn1);

    // ribbonBar->addGroup(insertTab, "test", fontButtons1);


    // ribbonBar->setCurrentTab(homeTab);

    // // 将 RibbonBar 添加到窗口
    // mainWindow.setMenuWidget(ribbonBar);

    //mainWindow.show();


    QRibbonBar pQRibbonBar;
    pQRibbonBar.show();

    return a.exec();
}
