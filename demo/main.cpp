


#include<gtkmm.h>

#include"gui.h"
#include"app.h"
int main(int argc, char *argv[])
{
  Gtk::Main kit(argc, argv);

//	Ktk::Init(argc, argv);
//	Ktk::setupScreens();
//	Ktk::run();
	
/*
    void * obj = new Gtk::Window ();
    obj = new Gtk::EventBox();
    Gtk::EventBox * tmpev = (Gtk::EventBox*) obj;
    	MainWin win_main;

	pdvMain gui_main;
//	guiMonitor gui_monitor;
//	guiCliente gui_client;

	win_main.add(gui_main);
//	win_main.show_all();
    Glib::RefPtr<Gdk::Window> mwin = win_main.get_window();
 //   mwin->fullscreen();
    mwin->set_opacity(0.5);

	Gtk::Main::run(win_main);
	return 0;

*/
app pdv(argc,argv);
    return 0;



}

