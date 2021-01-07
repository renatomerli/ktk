#include <gtkmm.h>
#include "kcomp.h"
#include <pangomm.h>
#include <time.h>

Ktk::Label::~Label()
{};

Ktk::Label::Label()
{};

Ktk::Label::Label(Glib::ustring _rotulo)
{
rotulo.set_text(_rotulo);
add(alinhamento);
alinhamento.add(rotulo);
show_all();
set_visible_window (false);
};

void Ktk::Label::set_font( Pango::FontDescription  _font_desc)
{
rotulo.modify_font (_font_desc);
}

void Ktk::Label::set_rotulo(Glib::ustring _rotulo)
{
rotulo.set_label(_rotulo);
}

Glib::ustring Ktk::Label::get_rotulo()
{
return rotulo.get_label();
}

void Ktk::Label::set_color(Gdk::Color & _color)
{

    rotulo.modify_fg(Gtk::STATE_NORMAL, _color);

}











Ktk::Image::Image()
{

}

Ktk::Image::Image(Glib::RefPtr<Gdk::Pixbuf>& _pixbuf)
{
    img_bkp = _pixbuf->copy();
    Gtk::Image::Image();
    Gtk::Image::set(_pixbuf);
    show_all();
    
}







void Ktk::Image::on_size_allocate (Gtk::Allocation& allocation)
{

    Gtk::Image::on_size_allocate (allocation);
    printf("\nOn Image allocate !!!!");    
    if (! is_mapped()) return;

    if (!resized)
    {
    Glib::RefPtr<Gdk::Pixbuf> img_tmp = 
   img_bkp->scale_simple(allocation.get_width(),
                              allocation.get_height(),
                              Gdk::INTERP_BILINEAR);
    
  Gtk::Image::set(img_tmp);
    resized=true;
    }
    else
    {
    resized=false;
    }
    
    return;

}




void Ktk::Image::set (Glib::RefPtr<Gdk::Pixbuf>& _pixbuf)
{
    img_bkp = _pixbuf->copy();
    Gtk::Image::set(_pixbuf);
    show_all();

}


Ktk::Image::~Image(){};




Ktk::Clock::~Clock(){};

Ktk::Clock::Clock()
{

    add(m_frame);
    m_frame.add(m_hbox);
    m_hbox.pack_start(Hora);
    m_hbox.pack_start(dot1);
    m_hbox.pack_start(Minuto);
    m_hbox.pack_start(dot2);
    m_hbox.pack_start(Segundo);
    
    set_doze (false);
    set_segundos (true);
    
    
    on_timeout();

//    sigc::slot<bool> my_slot = sigc::bind(sigc::mem_fun(*this, &Clock::on_timeout), 0);
    

    Glib::signal_timeout().connect(sigc::mem_fun(*this, &Clock::on_timeout),1000);
    
    
    Pango::FontDescription* font = new Pango::FontDescription("Sans Regular 20");
    Hora.modify_font (*font);
    Minuto.modify_font (*font);
    Segundo.modify_font (*font);
    dot1.modify_font (*font);
    dot2.modify_font (*font);
    dot1.set_text(":");
    dot2.set_text(".");
    
    
    set_visible_window (false);
    show_all();

}


int Ktk::Clock::set_doze(bool _doze)
{
    m_doze = _doze;
}

int Ktk::Clock::set_segundos(bool _segundos)
{
    m_segundos = _segundos;

    if (m_segundos) 
        dot2.show();
    else
        dot2.hide();
    
    
}


bool Ktk::Clock::on_timeout()
{
    
    time_t date_temp;       // Stores seconds elapsed since 01-01-1970
    struct tm *date_format; // Saves in Date format
 //   char date_out[25];      // Output string
    
    time(&date_temp);
    date_format = localtime(&date_temp);
    //strftime(date_out, 25, "%Y-%m-%d, %H:%M:%S", date_format);
    
    
    
    std::stringstream s_hora, s_minuto, s_segundo;
    s_hora << date_format->tm_hour;
    s_minuto << date_format->tm_min;
    s_segundo << date_format->tm_sec;
    
    
    
    Hora.set_text(s_hora.str());
    if (date_format->tm_min < 10) Minuto.set_text("0" + s_minuto.str() ) ;
    else Minuto.set_text(s_minuto.str());
    
    if (m_segundos) {
        dot2.show();
        if (date_format->tm_sec < 10) Segundo.set_text("0" + s_segundo.str() );
        else Segundo.set_text(s_segundo.str());
    }
    else
        dot2.hide();
    
    return true; 

}





