#ifndef _KCOMP_H_
#define _KCOMP_H_

#include <gtkmm.h>
#include <pangomm.h>

namespace Ktk{
    
    
    class Image : public Gtk::Image
    {
        private:
            Glib::RefPtr<Gdk::Pixbuf> img_bkp;
            bool resized;
            
        public:
            Image();
            Image(Glib::RefPtr<Gdk::Pixbuf> & pixbuf);
            ~Image();
            
            void get_childshot();
            void set_font( Pango::FontDescription & _font_desc);
            
            void set(Glib::RefPtr<Gdk::Pixbuf> & pixbuf);
            
            virtual void on_size_allocate (Gtk::Allocation& allocation);
            
            
    };
    
    
    
    class Label : public Gtk::EventBox
    {
        Gtk::Alignment alinhamento;
        Gtk::Label rotulo;
        
        public:
        
            Label();
            Label(Glib::ustring _rotulo);
            
            ~Label();
            
            
            void set_rotulo(Glib::ustring _rotulo);
            Glib::ustring get_rotulo();
            void set_font (Pango::FontDescription  _font_desc);
        void set_color (Gdk::Color &_color);
            
            //    set_font;
            
            
            
            
    };
    
    
    class Link
        
    {
    };
    
    
    class Clock : public Gtk::EventBox
    {public:
        
            Clock();
            ~Clock();
            
            Gtk::Label Hora, Minuto, Segundo, dot1, dot2;
            
            Gtk::Frame m_frame;
            Gtk::HBox m_hbox;
            
            bool m_doze;
            int set_doze(bool _doze);
            
            int set_segundos(bool _segundos);
            bool m_segundos;
            
            int set_interval (int _interval);
            
            bool on_timeout();
            
            
    };
    
    
    
};











#endif // _KCOMP_H_
