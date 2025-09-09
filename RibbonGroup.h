#ifndef RIBBONGROUP_H
#define RIBBONGROUP_H

#include <QObject>
#include <QWidget>
#include <QToolButton>
#include <QVBoxLayout>

class RibbonGroup : public QWidget {
    Q_OBJECT
public:
    explicit RibbonGroup(const QString &title, QWidget *parent = nullptr);
    void addButton(QToolButton *button);
    void finalizeLayout();
private:
    QVBoxLayout *m_mainLayout;
    QWidget *m_buttonContainer;
    QHBoxLayout *m_buttonLayout;
    bool m_layoutFinalized = false; // 标记布局是否已完成

    QString _sTitle;

};

#endif // RIBBONGROUP_H
