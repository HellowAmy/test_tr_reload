
#include "main_window.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QUdpSocket>
#include <QComboBox>
#include <QApplication>
#include <QLabel>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QComboBox>
#include <QRadioButton>
#include <QScrollArea>

#include "wid_check_dig.h"
#include "Txml_tr.h"
#include "Tvlog.h"
#include "Ttr_manage.h"
#include "TrLabel.h"
#include "TrRadioButton.h"
#include "TrLineEdit.h"
#include "TrPushButton.h"


main_window::main_window(QWidget *parent) : QWidget(parent)
{   
    auto fn_type_to_str = [](Tnation::en_nation e) -> QString {
        QString s;
        if(e == Tnation::e_cn) s = "中文";
        if(e == Tnation::e_jp) s = "にほんご";
        if(e == Tnation::e_us) s = "English";
        return s;
    };
    auto fn_str_to_type = [](QString s) -> Tnation::en_nation {
        Tnation::en_nation e;
        if(s == "中文") e = Tnation::e_cn;
        if(s == "にほんご") e = Tnation::e_jp;
        if(s == "English") e = Tnation::e_us;
        return e;
    };


    this->resize(500,250);

    this->set_tr_fn([=](){
        this->setWindowTitle(tr("Login Window"));
    });

    QVBoxLayout *lay_main = new QVBoxLayout(this);

    {
        QWidget *wid = new QWidget(this);
        wid->resize(400,500000);
        wid->show();

        QScrollArea *area = new QScrollArea(this);
        area->resize(500,500);
        area->setWidget(wid);

        QVBoxLayout *lay = new QVBoxLayout(wid);
        lay->setContentsMargins(0,0,0,0);
        lay->setSpacing(0);
        for(int i=0;i<10000;i++)
        {
            {
                TrPushButton *lab = new TrPushButton(wid);
                lab->set_tr_fn([=](){
                    lab->setText(tr("It is PushButton %1").arg(i));
                });
                lay->addWidget(lab);
            }
        }
        lay_main->addWidget(area);
    }
    {
        QComboBox *combo = new QComboBox(this);
        auto vec = Ttrms::get()->get_install_translator();
        for(auto &a:vec)
        {
            combo->addItem(fn_type_to_str(a));
        }

        connect(combo,&QComboBox::currentTextChanged,[=](const QString & s){
            Ttrms::get()->switch_translator(fn_str_to_type(s));
        });

        combo->setCurrentText(fn_type_to_str(Tnation::e_us));
        lay_main->addWidget(combo);
    }

    {
        TrLabel *lab = new TrLabel(this);
        lab->set_tr_fn([=](){
            lab->setText(tr("Welcome to XX Hospital"));
        });
        lay_main->addWidget(lab);
    }
    {
        TrLabel *lab = new TrLabel(this);
        lab->set_tr_fn([=](){
            lab->setText(tr("It is the best hospital in the world"));
        });
        lay_main->addWidget(lab);
    }
    {
        QHBoxLayout *lay = new QHBoxLayout;
        TrRadioButton *rbutt_student = new TrRadioButton(this);
        rbutt_student->set_tr_fn([=](){
            rbutt_student->setText(tr("Student"));
        });
        TrRadioButton *rbutt_doctor_s = new TrRadioButton(this);
        rbutt_doctor_s->set_tr_fn([=](){
            rbutt_doctor_s->setText(tr("Doctor","at school"));
        });
        TrRadioButton *rbutt_doctor_h = new TrRadioButton(this);
        rbutt_doctor_h->set_tr_fn([=](){
            rbutt_doctor_h->setText(tr("Doctor","at hospital"));
        });
        TrRadioButton *rbutt_director = new TrRadioButton(this);
        rbutt_director->set_tr_fn([=](){
            rbutt_director->setText(tr("Director"));
        });

        rbutt_student->setChecked(true);

        lay->addWidget(rbutt_student);
        lay->addWidget(rbutt_doctor_s);
        lay->addWidget(rbutt_doctor_h);
        lay->addWidget(rbutt_director);
        lay_main->addLayout(lay);
    }

    {
        QHBoxLayout *lay = new QHBoxLayout;
        TrLabel *lab = new TrLabel(this);
        lab->set_tr_fn([=](){
            lab->setText(tr("Account:"));
        });

        TrLineEdit *edit = new TrLineEdit(this);
        edit->set_tr_fn([=](){
            edit->setText(tr("Hellow Amy"));
            edit->setPlaceholderText(tr("Please enter the account"));
        });

        lay->addWidget(lab);
        lay->addWidget(edit);
        lay_main->addLayout(lay);
    }
    {
        QHBoxLayout *lay = new QHBoxLayout;
        TrLabel *lab = new TrLabel(this);
        lab->set_tr_fn([=](){
            lab->setText(tr("Password:"));
        });

        TrLineEdit *edit = new TrLineEdit(this);
        edit->set_tr_fn([=](){
            edit->setPlaceholderText(tr("Please enter the Password"));
        });

        lay->addWidget(lab);
        lay->addWidget(edit);
        lay_main->addLayout(lay);
    }

    {
        QHBoxLayout *lay = new QHBoxLayout;
        TrPushButton *butt_cancel = new TrPushButton(this);
        butt_cancel->set_tr_fn([=](){
            butt_cancel->setText(tr("Exit"));
        });
        TrPushButton *butt_confirm = new TrPushButton(this);
        butt_confirm->set_tr_fn([=](){
            butt_confirm->setText(tr("Login"));
        });
        lay->addWidget(butt_cancel);
        lay->addWidget(butt_confirm);
        lay_main->addLayout(lay);
    }
}

main_window::~main_window()
{
}

