
#ifndef TTR_MANAGE_H
#define TTR_MANAGE_H

#include <iostream>
#include <list>
#include <map>

#include <QApplication>
#include <QTranslator>
#include <functional>

#include "Tvlog.h"

using namespace Tconf;

namespace Tnation {

enum en_nation
{
    e_cn,
    e_us,
    e_jp,
};

}; // Tnation

class Ttr_manage
{
public:
    Ttr_manage() {}
    ~Ttr_manage() {}

    void register_reload(std::function<void()> fn)
    {
        if(fn != nullptr)
        {
            _ls_reload.push_back(fn);
        }
    }

    void switch_translator(Tnation::en_nation type)
    {
        auto it = _mp_translator.find(type);
        if(it != _mp_translator.end())
        {
            if(it->second != nullptr)
            {
                if(qApp->installTranslator(it->second))
                {
                    _old_translator = it->second;
                }
            }
            else if(_old_translator != nullptr)
            {
                qApp->removeTranslator(_old_translator);
            }
            reload_tr_ls();
        }
    }

    bool install_translator(Tnation::en_nation type,QTranslator *translator)
    {
        auto it = _mp_translator.emplace(type,translator);
        return it.second;
        if(translator != nullptr)
        return false;
    }

    QTranslator* make_translator(qcstr file)
    {
        QTranslator *trp = new QTranslator(qApp);
        if(trp->load(file))
        {
            return trp;
        }
        return nullptr;
    }

    std::vector<Tnation::en_nation> get_install_translator()
    {
        std::vector<Tnation::en_nation> vec;
        for(const auto &a:_mp_translator)
        {
            vec.push_back(a.first);
        }
        return vec;
    }

protected:
    void reload_tr_ls()
    {
        for(const auto &fn:_ls_reload)
        {
            if(fn) fn();
        }
    }

protected:  
    QTranslator *_old_translator = nullptr;
    std::list<std::function<void()>> _ls_reload;
    std::map<Tnation::en_nation,QTranslator *> _mp_translator;

};

typedef Tsingle_d<Ttr_manage> Ttrms;

#endif // TTR_MANAGE_H
