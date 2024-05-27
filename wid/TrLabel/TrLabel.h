
#ifndef TRLABEL_H
#define TRLABEL_H

#include <QWidget>
#include <QLabel>

#include "Ttr_reload.h"

class TrLabel : public QLabel , public Ttr_reload
{
    Q_OBJECT
public:
    TrLabel(QWidget *parent = nullptr);
    ~TrLabel();

signals:

protected:

private:

};
#endif // TRLABEL_H
