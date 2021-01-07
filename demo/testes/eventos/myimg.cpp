#include <gtkmm.h>
#include "tree.h"
class myCtn : public Gtk::Fixed
{
    
    public:
        Gtk::Button btn;
        
        bool on_configure_event (GdkEventConfigure *e)
    {
        printf("\non configure");
        return false;
        
    };
        
        
        void botao_clicked()
    {
        Gtk::Button *tmp = new Gtk::Button("Button");
//        pack_start (*tmp);
put(*tmp,0,0);        tmp->show();
    };
        
        
        
        myCtn(): btn("Botao"){
            Gtk::Widget::set_events(Gdk::STRUCTURE_MASK);
//            pack_start (btn);
put(btn,10,10);     
       btn.signal_clicked().connect(sigc::mem_fun(this, &myCtn::botao_clicked));
            btn.show();
            set_has_window ();
        };
        
        
        
        
};

bool 
on_configure(GdkEventConfigure* event) 
{
    printf("\nEventConfigure Funcao");
}

void 
on_configure_notify(GdkEventConfigure* event) 
{ 
    
    printf("\nEventNOTIFYConfigure Funcao");
    
}






int main (int argc, char *argv[])
{
    
    Gtk::Main kit(argc, argv);
    Gtk::Window win;
    
    myCtn box;
    win.add(box);
    win.add_events (Gdk::ALL_EVENTS_MASK);
    
    box.signal_configure_event().connect(sigc::ptr_fun(&on_configure));
    box.signal_configure_event().connect_notify(sigc::ptr_fun(&on_configure_notify));

    Example_TreeView_ListStore tree;
    box.pack_start(tree);

        win.show_all();

    Gtk::Main::run(win);
    
    
    
    
}
