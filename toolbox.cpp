#include "toolbox.h"
//#include "gui.h"
#include "kcomp.h"


namespace Ktk
{
    Toolbox::~Toolbox(){};

    Toolbox::Toolbox()
        :btSave("Salvar"), btLoad("Carregar")
    {
        
        
        imgBox.set(Gtk::Stock::STOP, Gtk::ICON_SIZE_MENU);
        imgTrans.set(Gtk::Stock::GO_UP, Gtk::ICON_SIZE_MENU); 
        imgImage.set(Gtk::Stock::HELP,  Gtk::ICON_SIZE_MENU);
        imgLink.set(Gtk::Stock::HOME,  Gtk::ICON_SIZE_MENU);
        imgClock.set(Gtk::Stock::INFO,  Gtk::ICON_SIZE_MENU);
        
        btBox.add(imgBox);
        btTrans.add(imgTrans);
        btImage.add(imgImage);
        btLink.add(imgLink);
        btClock.add(imgClock);
        
        attach (btBox, 0,1,0,1);
        attach (btTrans, 1,2,0,1);
        attach (btImage, 0, 1, 1, 2);
        attach (btLink, 1, 2, 1, 2 );
        attach (btClock, 0, 1, 2, 3);
        attach (btLoad, 0,2,3,4);
        attach (btSave, 0,2,4,5); 
        
        //m_button1.signal_clicked().connect( sigc::mem_fun(*this,&HelloWorld::on_button_clicked) );
        btImage.signal_clicked().connect( sigc::mem_fun(*this, &Toolbox::cb_add_image));
        btBox.signal_clicked().connect( sigc::mem_fun(*this, &Toolbox::cb_add_label));
        btClock.signal_clicked().connect( sigc::mem_fun(*this, &Toolbox::cb_add_clock));
    };
    
    void Toolbox::cb_add_image()
    {
        
        
    };
    
    
    
    
        

    
    
        void Toolbox::cb_add_label()
    {
    
    
    
    
    }
    
    
        void Toolbox::cb_add_clock()
    {
        
        
    }
    
    
    
    
    
    
    
    
    
    
};
