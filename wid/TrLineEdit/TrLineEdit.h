
#ifndef TRLINEEDIT_H
#define TRLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

#include "Ttr_reload.h"

class TrLineEdit : public QLineEdit , public Ttr_reload
{
    Q_OBJECT
public:
    TrLineEdit(QWidget *parent = nullptr);
    ~TrLineEdit();

signals:

protected:

private:

};
#endif // TRLINEEDIT_H
