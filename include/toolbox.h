#ifndef _TOOLBOX_H_
#define _TOOLBOX_H_

#include<gtkmm.h>


class pdvMain;
namespace Ktk
{


class Toolbox : public Gtk::Table
	{
	public:
        
	Toolbox();
	~Toolbox();
	Gtk::Button btBox, btTrans, btImage, btLink, btClock;

            
	Gtk::Button btSave, btLoad;
			
	Gtk::Image imgBox, imgTrans, imgImage, imgLink, imgClock;
	

    virtual void cb_add_image();
    virtual void cb_add_label();
    virtual void cb_add_clock();

    };

};

#endif // _TOOLBOX_H_


