#include "RibbonTab.h"
#include <QFrame>
#include <QPainter>
RibbonTab::RibbonTab(QWidget *parent)
    : QWidget{parent}
{
    m_layout = new QHBoxLayout(this);
    m_layout->setSpacing(8);
    m_layout->setContentsMargins(0, 0, 0, 0);
    setAutoFillBackground(true);

    _bFirstIn = true;
}

void RibbonTab::addGroup(RibbonGroup *group) {
    // 添加分隔线（如果不是第一个组）
    if (m_layout->count() > 0) {
        QFrame *line = new QFrame(this);
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line->setStyleSheet("color: rgb(27, 127, 220);");
        m_layout->addWidget(line);
    }

    m_layout->addWidget(group);
}

void RibbonTab::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);

    QPainter painter(this);
    QLinearGradient gradient(0, 0, width(), 0);  // 水平渐变
    gradient.setColorAt(0.7, QColor(0x16, 0x4E, 0xA5));
    gradient.setColorAt(1, QColor(0x01, 0x22, 0x45));
    painter.fillRect(rect(), gradient);
}

void RibbonTab::finalizeLayout() {
    // 在最右侧添加弹簧，使所有组左对齐
    if(m_layout->count() > 0 && _bFirstIn){
        _bFirstIn = false;
        m_layout->addStretch();
    }
}
