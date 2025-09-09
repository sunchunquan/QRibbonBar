#include "QRibbonBar.h"
#include "ui_QRibbonBar.h"
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>

#include "CustomRibbonBar.h"

QRibbonBar::QRibbonBar(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::QRibbonBar)
{
    ui->setupUi(this);
    setWindowTitle("Qt Ribbon Demo");
    setFixedSize(1280,1024);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 添加阴影效果
    // auto *shadow = new QGraphicsDropShadowEffect(this);
    // shadow->setBlurRadius(20);
    // shadow->setColor(QColor(0, 0, 0, 150));
    // shadow->setOffset(0, 5);
    // setGraphicsEffect(shadow);

    // 确保中央部件透明
    if (centralWidget()) {
        centralWidget()->setAttribute(Qt::WA_TranslucentBackground);
        centralWidget()->setStyleSheet("background: transparent;");
    }


    // 创建自定义 RibbonBar
    CustomRibbonBar *ribbonBar = new CustomRibbonBar(this);

    // 添加标签页
    RibbonTab *homeTab = ribbonBar->addTab(QStringLiteral("主页"), 0xf015);
    RibbonTab *insertTab = ribbonBar->addTab(QStringLiteral("插入"), 0xf068);
    RibbonTab *viewTab = ribbonBar->addTab(QStringLiteral("视图"), 0xf00d);

    // 为 Home 标签页添加组
    QList<QToolButton*> clipboardButtons;

    QToolButton *pasteBtn = new QToolButton();
    pasteBtn->setText(QStringLiteral("复制"));
    pasteBtn->setMinimumSize(40,40);
    pasteBtn->setIcon(QIcon("://Resources/image/add-nomal.png"));
    pasteBtn->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

    pasteBtn->setStyleSheet(
            "QToolButton {"
            "  background-color: transparent;"
            "  color: white;"
            "  border: none;"
            "  padding: 5px 8px;"
            "  margin: 2px;"
            "  font-size: 13px;"
            "  text-align: center;"
            "}"
            "QToolButton:hover {"
            "  background-color: rgba(255, 255, 255, 0.2);"
            "  border-radius: 3px;"
            "}"
            "QToolButton:pressed {"
            "  background-color: rgba(255, 255, 255, 0.1);"
            "}"
            );

    clipboardButtons.append(pasteBtn);

    QToolButton *cutBtn = new QToolButton();
    cutBtn->setText("Cut");
    cutBtn->setIcon(QIcon::fromTheme("edit-cut"));
    clipboardButtons.append(cutBtn);

    QToolButton *copyBtn = new QToolButton();
    copyBtn->setText("Copy");
    copyBtn->setIcon(QIcon::fromTheme("edit-copy"));
    clipboardButtons.append(copyBtn);

    ribbonBar->addGroup(homeTab, "", clipboardButtons);


    // 添加字体组
    QList<QToolButton*> fontButtons;

    QToolButton *boldBtn = new QToolButton();
    boldBtn->setText("Bold");
    boldBtn->setIcon(QIcon::fromTheme("format-text-bold"));
    fontButtons.append(boldBtn);

    QToolButton *italicBtn = new QToolButton();
    italicBtn->setText("Italic");
    italicBtn->setIcon(QIcon::fromTheme("format-text-italic"));
    fontButtons.append(italicBtn);

    ribbonBar->addGroup(homeTab, "", fontButtons);
    //ribbonBar->setCurrentTab(insertTab);

    // 添加字体组
    QList<QToolButton*> fontButtons1;

    QToolButton *boldBtn1 = new QToolButton();
    boldBtn1->setText("Bold1");
    boldBtn1->setIcon(QIcon::fromTheme("format-text-bold"));
    fontButtons1.append(boldBtn1);

    QToolButton *italicBtn1 = new QToolButton();
    italicBtn1->setText("Italic1");
    italicBtn1->setIcon(QIcon::fromTheme("format-text-italic"));
    fontButtons1.append(italicBtn1);

    ribbonBar->addGroup(insertTab, "test", fontButtons1);


    ribbonBar->setCurrentTab(homeTab);

    // 将 RibbonBar 添加到窗口
    this->centralWidget()->layout()->addWidget(ribbonBar);
    pQStackedWidget = new QStackedWidget(this);
    this->centralWidget()->layout()->addWidget(pQStackedWidget);

}

QRibbonBar::~QRibbonBar()
{
    delete ui;
}

void QRibbonBar::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    int cornerRadius = 10;
    // 创建仅左上和右上圆角的路径
    QPainterPath path;
    QRect rect = this->rect();
    path.addRect(rect);
    // 填充背景
    painter.fillPath(path, QColor("#001441"));

    // 绘制边框
    painter.setPen(QPen(QColor(255, 255, 255, 150), 1));
    painter.drawPath(path);
}
