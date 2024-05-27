
#ifndef TRRADIOBUTTON_H
#define TRRADIOBUTTON_H

#include <QWidget>
#include <QRadioButton>

#include "Ttr_reload.h"

class TrRadioButton : public QRadioButton , public Ttr_reload
{
    Q_OBJECT
public:
    TrRadioButton(QWidget *parent = nullptr);
    ~TrRadioButton();

signals:

protected:

private:

};
#endif // TRRADIOBUTTON_H
