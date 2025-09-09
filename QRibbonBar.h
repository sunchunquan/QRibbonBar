#ifndef QRIBBONBAR_H
#define QRIBBONBAR_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QStackedWidget>
#include "NativeWindowTemplate.hpp"


QT_BEGIN_NAMESPACE
namespace Ui {
class QRibbonBar;
}
QT_END_NAMESPACE

class QRibbonBar : public QMainWindow
{
    Q_OBJECT

public:
    QRibbonBar(QWidget *parent = nullptr);
    ~QRibbonBar();
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::QRibbonBar *ui;
    QStackedWidget *pQStackedWidget;
};
#endif // QRIBBONBAR_H
