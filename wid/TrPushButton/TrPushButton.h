
#ifndef TRPUSHBUTTON_H
#define TRPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>

#include "Ttr_reload.h"

class TrPushButton : public QPushButton , public Ttr_reload
{
    Q_OBJECT
public:
    TrPushButton(QWidget *parent = nullptr);
    ~TrPushButton();

signals:

protected:

private:

};
#endif // TRPUSHBUTTON_H
