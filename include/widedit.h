#ifndef _WIDEDIT_H_
#define _WIDEDIT_H_

#include <gtkmm.h>
#include "tchild.h"

namespace Ktk
{
    
    class Widedit: public Gtk::VBox
    {
        
        public:
            Widedit();
            ~Widedit();
            
        TChild *m_tchild;
        Gtk::VBox mainbox;
        Gtk::Frame frame_pmap;
        Gtk::Frame frame_primeiro;
        Gtk::Frame frame_segundo;
        
        Gtk::Frame frame_terceiro;
        
        Gtk::Notebook nb_main;
        
        Gtk::Frame frame_label;
        Gtk::Frame frame_dclock;
        Gtk::Frame frame_image;
        Gtk::Frame frame_link;
        
        
        //frame 1
            Gtk::Label lbl_alpha, lbl_saturacao;
            Gtk::Label lbl_allocx, lbl_allocy;
            Gtk::Label lbl_width, lbl_height ;
            
        Gtk::SpinButton spin_allocx, spin_allocy;
        Gtk::SpinButton spin_width, spin_height;   
        
        // main     
        Gtk::Table maintable;
        Ktk::Image img_widget;
        Gtk::HScale scale_alpha;
        Gtk::HScale scale_saturation;
	/////////////////////////////////////////////////
	
	//frame label
	Gtk::Table table_label;
	Gtk::Label lbl_rotulo, lbl_cor, lbl_fonte, lbl_bkg;
	Gtk::Entry etr_rotulo;
	Gtk::FontButton bt_fonte;
	Gtk::ColorButton bt_cor, bt_bkg;
    Gtk::CheckButton ck_bkg;
    Gtk::HBox box_bkg;
	void set_label();
	void set_image();
	void set_dclock();
	void cb_label_changed();
    void cb_font_set();
    void cb_color_set();
	void cb_bkg_set();
            
	
	
        void cb_change_scale();
        void cb_change_spin();
            
            Glib::RefPtr<Gdk::Pixmap> pmap_shot;
            
            Glib::RefPtr<Gdk::Pixbuf> pbuf_shot;
                        
            // todos os componentes ???		
            // cor da fonte, cor do fundo
            // fonte
            // tamanho da fonte
            // ticket tem muuuitos outros //////
            
            
            // se tem transparencia alpha e se sim qual fonte eh a transparente ?
            // se tem transparencia composite e se sim qual o indice de transparencia ?

// set para todos os tipos ...?! !? ?!
            int set_widget(Ktk::TChild * _tchild);
            Ktk::TChild* getWidget();
            int set(Ktk::TChild * _tchild);
            int set_pixbuf (Glib::RefPtr<Gdk::Pixbuf> _pbuf);
            
            void update_allocation(Gtk::Allocation  _allocation);
            
            
            
            
    };
    
}; // namespace Ktk

#endif // _WIDEDIT_H_
