#ifndef _TPARENT_H_
#define _TPARENT_H_

#include "tchild.h"
#include "common.h"
#include "widedit.h"
#include "kcomp.h"
#include <gtkmm.h>




namespace Ktk
{

class TParent : public Gtk::Fixed
{
    public:
    
        TParent();
        ~TParent();
  
        std::vector<Ktk::TChild*> tchild_list;
        
        tipo_fundo bkg_type;
        Gdk::Color bkg_color;
        
        //return a XML description of the interface to be saved to a file (not done)
        Glib::ustring get_description();
        
        /**Construct a interface form a XML description (not done)
        @paran _description xml file description
        */
        void set_description (Glib::ustring _description);
        
        
        // config
        bool m_editmode;
        bool editmode();
        bool set_editmode(bool _editmode = true);
        bool get_editmode();
        
        bool m_movedark;
        void set_movedark(bool _movedark = true);
        bool get_movedark();
        

        Ktk::Widedit *m_widedit;
        void set_widedit (Widedit &_widedit);
        
        void set_background_mode (tipo_fundo _fundo = opaco);
        void setBackground (Glib::ustring  _file);
        void Init();
 
        // transparency data
        Gtk::Image img;
        Glib::RefPtr<Gdk::Pixbuf> pbuf_background;
        Glib::RefPtr<Gdk::Drawable> draw;
        Glib::RefPtr<Gdk::GC> gc;
        
        //motion parts
        
        TChild * clicked_child;
        Gtk::Allocation clicked_allocation;

        bool m_moving;
        bool moving();
        void set_moving(bool _moving);

        bool m_clicked;
        bool clicked();
        void set_clicked(bool _clicked);
        
        bool move_top, move_down, move_left, move_right;
        bool on_top, on_down, on_left, on_right;
        
        gdouble clicked_pointer_x;
        gdouble clicked_pointer_y;
        gdouble clicked_root_x; 
        gdouble clicked_root_y;
        int clicked_widget_x; 
        int clicked_widget_y;
        int clicked_height;
        int clicked_width;
    
        
        // callbacks for motion
        void cb_child_click (Ktk::TChild* _tchild, GdkEventButton* event);
        void cb_child_motion (Ktk::TChild* _tchild, GdkEventMotion* event) ;
        void cb_child_release (Ktk::TChild* _tchild, GdkEventButton* event);
        
        
        
        void cb_child_keypress (Ktk::TChild* _tchild, GdkEventKey* event);	 

        
        //transparency callback
        void cb_child_expose (Ktk::TChild* _tchild, GdkEventExpose* event);	 
        
        /**Put a child widget in the the interface, using x and y as values for cartesian position.*/

        void put (Ktk::Clock &_clock, int x, int y);
        void put (Ktk::Image &_image, int x, int y);
 
        
        void put (Gtk::TreeView &_tree, int x, int y);
        void put (Gtk::Frame &_frame, int x, int y);
        void put (Gtk::Button &_bt, int x, int y);
        
        void put (Ktk::Label &_label, int x, int y);
        void put (Gtk::Widget &_widget, int x, int y);



    protected:
        virtual void on_size_allocate (Gtk::Allocation& allocation);
        
        
};










}; // TParent




#endif // _TPARENT_H_
