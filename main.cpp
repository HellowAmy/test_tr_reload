#include <QApplication>
#include <QWidget>

#include <iostream>

#include "tinyxml2.h"
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#include "window/main_window.h"

#include "Txml_tr.h"
#include "Txlsx.h"
#include "Tvlog.h"
#include "Ttinyxml.h"
#include "Ttr_manage.h"

using namespace QXlsx;
using namespace std;
using namespace tinyxml2;

int run_main_app(int argc, char *argv[])
{
    QApplication a(argc,argv);
    
    {
        QString s = "/home/cong/open/test_qt/test_tr_reload/config/language/cn/qm/cn.qm";
        Ttrms::get()->install_translator(Tnation::e_cn,Ttrms::get()->make_translator(s));
    }
    {
        QString s = "/home/cong/open/test_qt/test_tr_reload/config/language/jp/qm/jp.qm";
        Ttrms::get()->install_translator(Tnation::e_jp,Ttrms::get()->make_translator(s));
    }
    {
        Ttrms::get()->install_translator(Tnation::e_us,nullptr); // 默认语言，空载入
    }

    main_window w;
    w.resize(500,500);
    w.show();

    return a.exec();
}

int exit_main_app(int run_value)
{
    cout<<"exit run value : "<<run_value<<endl;
    return run_value;
}

int perse_arg(int argc, char *argv[])
{
    cout<<"perse_arg : "<<argc<<endl;
    for(int i=0;i<argc;i++)
    {
        cout<<"arg: "<<string(argv[i])<<endl;
    }
    return argc;
}

int main(int argc, char *argv[])
{
    perse_arg(argc,argv);

    int run_value = run_main_app(argc,argv);

    return exit_main_app(run_value);
}