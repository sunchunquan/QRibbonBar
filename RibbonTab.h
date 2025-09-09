#ifndef RIBBONTAB_H
#define RIBBONTAB_H

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include "RibbonGroup.h"

class RibbonTab : public QWidget
{
    Q_OBJECT
public:
    explicit RibbonTab(QWidget *parent = nullptr);
    void addGroup(RibbonGroup *group);
    void finalizeLayout();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QHBoxLayout *m_layout;
    bool _bFirstIn;
};

#endif // RIBBONTAB_H
