#include "RibbonGroup.h"
#include <QLabel>

RibbonGroup::RibbonGroup(const QString &title, QWidget *parent)
    : QWidget(parent) {
    // 主垂直布局
    m_mainLayout = new QVBoxLayout(this);
    m_mainLayout->setSpacing(0);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    _sTitle = title;

    if(!title.isEmpty()){
        QLabel *titleLabel = new QLabel(title, this);
        titleLabel->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        titleLabel->setStyleSheet("color: white; font-size: 11px;");
        m_mainLayout->addWidget(titleLabel);
    }

    // 按钮容器
    m_buttonContainer = new QWidget(this);
    m_buttonLayout = new QHBoxLayout(m_buttonContainer);
    m_buttonLayout->setSpacing(4); // 稍微增加按钮间距
    m_buttonLayout->setContentsMargins(2, 0, 2, 0); // 左右留少量边距

    m_mainLayout->addWidget(m_buttonContainer);
}

void RibbonGroup::addButton(QToolButton *button) {
    if (m_layoutFinalized) {
        return;
    }

    button->setParent(m_buttonContainer);
    button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    // button->setStyleSheet(
    //     "QToolButton {"
    //     "  background-color: transparent;"
    //     "  color: white;"
    //     "  border: none;"
    //     "  padding: 5px 8px;"
    //     "  margin: 0px;"
    //     "  font-size: 11px;"
    //     "  text-align: center;"
    //     "  min-width: 60px;"
    //     "}"
    //     "QToolButton:hover {"
    //     "  background-color: rgba(255, 255, 255, 0.2);"
    //     "  border-radius: 3px;"
    //     "}"
    //     "QToolButton:pressed {"
    //     "  background-color: rgba(255, 255, 255, 0.1);"
    //     "}"
    //     );

    m_buttonLayout->addWidget(button);
}

void RibbonGroup::finalizeLayout() {
    if (m_layoutFinalized) return;

    // 在所有按钮后添加弹簧
    m_buttonLayout->addStretch();
    m_layoutFinalized = true;
}
