
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QWidget>
#include <QTranslator>

#include "Ttr_reload.h"

class main_window : public QWidget , public Ttr_reload
{
    Q_OBJECT
public:
    main_window(QWidget *parent = nullptr);
    ~main_window();

signals:

protected:


};
#endif // MAIN_WINDOW_H
