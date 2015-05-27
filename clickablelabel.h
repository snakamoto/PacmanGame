#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <QWidget>
#include <QObject>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT
public:
    ClickableLabel(QWidget *parent);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *e);
};

#endif // CLICKABLELABEL_H
