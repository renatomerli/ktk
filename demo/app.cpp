#include"app.h"
#include"common.h"
#include<gtkmm.h>

//app::~app(){};


app::~app(){};


bool app::processamento(){ return m_estado == OPERANDO ? true : false ; } 
bool app::pagamento(){ return m_estado == PAGAMENTO ? true : false ; } 



app::app(int _argc, char **_argv)
{

//    Gtk::Main kit(_argc, _argv);
    

  //  Gtk::Window *win = new Gtk::Window;
//    win->show_all();
    
    win_main.add(evbox_main);
//    bt->signal_clicked().connect( sigc::mem_fun(*this, &pdvMain::cb_teste));

    evbox_main.signal_key_press_event().connect( sigc::mem_fun(*this, &app::cb_keypress));
    evbox_main.add_events(Gdk::KEY_PRESS_MASK);

    evbox_main.add(gui_main);
    
    gui_main.set_editmode(true);

    win_main.show_all();
    Gtk::Main::run(win_main);

    
    
    
};



bool app::cb_keypress(GdkEventKey* event)
{


  char utf8string[10];
  int ll;
  guint32 unichar;

  printf("keyval = %d (0x%x)\n", event->keyval, event->keyval);
  unichar = gdk_keyval_to_unicode(event->keyval);
  printf("unichar = %d (0x%x)\n", unichar, unichar);
  ll = g_unichar_to_utf8(unichar, utf8string);
  utf8string[ll] = '\0';
  printf("utf8 = %s\n", utf8string); 
    
    fflush(stdout);
    
    
    
    
    
    
    
    
    
    printf("\n keyval: %i, hardware_keycode: %i", event->keyval, event->hardware_keycode);
    
    if (processamento()) 
    if (event->keyval >= GDK_0 && event->keyval <= GDK_9)
    {
        
        
        
        
    }
    
    
    if (event->keyval == GDK_F12){
        if (gui_main.get_editmode())
            gui_main.set_editmode(false);
        else
            gui_main.set_editmode(true);
    }
    
    
    
    
    
    
    
}










