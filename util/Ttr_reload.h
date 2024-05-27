
#ifndef TTR_RELOAD_H
#define TTR_RELOAD_H


#include <iostream>
#include <functional>

#include "Tconfig.h"
#include "Ttr_manage.h"

#include <QString>

using namespace Tconf;

class Ttr_reload
{
public:
    Ttr_reload() 
    {
        Ttrms::get()->register_reload([=] () {
            reload_tr_fn();
        });
    }
    ~Ttr_reload() {}

    void reload_tr_fn()
    {
        if(_fn_tr)
        {
            _fn_tr();
        }
    }

    virtual void set_tr_fn(std::function<void()> fn)
    {
        _fn_tr = fn;
        if(_fn_tr)
        {
            _fn_tr();
        }
    }

protected:
    std::function<void()> _fn_tr = nullptr;
};
#endif // TTR_RELOAD_H
