#include "widedit.h"
#include <iostream>
namespace Ktk{	
    
    Widedit::~Widedit(){};
    
    Widedit::Widedit()
        : scale_alpha(0, 99, 1), scale_saturation(0, 99, 1),
    spin_allocx(5, 0),spin_allocy(5, 0),
    spin_width(5, 0), spin_height(5, 0),
    lbl_alpha("Alpha"), lbl_saturacao("Saturation"),
    lbl_allocx("Origin X: "), lbl_allocy("Origin Y: "),
    lbl_width("Width: "), lbl_height("Height"),
    lbl_rotulo("Rotulo: "), lbl_cor("Cor: "), 
    lbl_fonte("Fonte: "), lbl_bkg("Fundo: ")    
    {

        
        
        //setup
        
        
        //principal
        set_border_width (2);
        
        pack_start(frame_pmap);
        pack_start(frame_primeiro);
        pack_start(frame_segundo);
        pack_start(frame_terceiro);
        
        frame_pmap.set_border_width(5);
        frame_pmap.add(img_widget);
        
        
        
        //scales
        scale_alpha.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_scale));  
        scale_saturation.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_scale));
        scale_saturation.set_draw_value(false);
        scale_alpha.set_draw_value(false);
        
        
        //spins
        spin_allocx.set_numeric(); spin_allocy.set_numeric();
        spin_width.set_numeric(); spin_height.set_numeric();
        
        Gtk::Adjustment *adj_allocx = new Gtk::Adjustment (0, 0, 2000, 1, 0);
        Gtk::Adjustment *adj_allocy = new Gtk::Adjustment (0, 0, 2000, 1, 0);
        Gtk::Adjustment *adj_width = new Gtk::Adjustment (0, 0, 2000, 1, 0);
        Gtk::Adjustment *adj_height = new Gtk::Adjustment (0, 0, 2000, 1, 0);
        
        spin_allocx.set_adjustment(*adj_allocx);
        spin_allocy.set_adjustment(*adj_allocy);
        spin_width.set_adjustment(*adj_width);
        spin_height.set_adjustment(*adj_height);
        
        
        spin_allocx.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_spin));
        spin_allocy.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_spin));
        spin_width.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_spin));
        spin_height.signal_value_changed().connect( sigc::mem_fun( *this, & Widedit::cb_change_spin));
        
        
        //primeiro frame
        frame_primeiro.add(mainbox);
        mainbox.pack_start(lbl_alpha);
        lbl_alpha.set_justify(Gtk::JUSTIFY_LEFT);
        mainbox.pack_start(scale_alpha);
        mainbox.pack_start(lbl_saturacao);
        mainbox.pack_start(scale_saturation);
        
        // segundo frame
        frame_segundo.add(maintable);
        maintable.attach(lbl_allocx, 0, 1, 0, 1);
        maintable.attach(spin_allocx, 1, 3, 0, 1);
        maintable.attach(lbl_allocy, 0, 1, 1, 2);
        maintable.attach(spin_allocy, 1, 3, 1, 2);
        
        maintable.attach(lbl_width, 0, 1, 2, 3);
        maintable.attach(spin_width, 1, 3, 2, 3);
        
        maintable.attach(lbl_height, 0, 1, 3, 4);
        maintable.attach(spin_height, 1, 3, 3, 4);
        
        //terceiro frame
        frame_terceiro.add(nb_main);
        nb_main.append_page(frame_label, "");
        nb_main.append_page(frame_image, "");
        nb_main.append_page(frame_dclock, "");
        nb_main.append_page(frame_link, "");
        frame_label.add(table_label);
        table_label.attach(lbl_rotulo, 0, 1, 0, 1);
        table_label.attach(lbl_fonte, 0, 1, 1, 2);
        table_label.attach(lbl_cor, 0, 1, 2, 3 );
        table_label.attach(lbl_bkg,0,1,3, 4);
        
        table_label.attach(etr_rotulo, 1, 2, 0, 1);
        table_label.attach(bt_fonte,1,2, 1,2 );
        table_label.attach(bt_cor, 1,2, 2, 3);
        box_bkg.pack_start(ck_bkg, false, false);
        box_bkg.pack_start(bt_bkg);
        table_label.attach(box_bkg, 1,2, 3, 4);
         
//        table_label.attach(ck_bkg, 1,2, 3, 4);
//        table_label.attach(bt_bkg, 2,3, 3, 4);
        
        
        etr_rotulo.signal_changed().connect(sigc::mem_fun(*this,&Widedit::cb_label_changed));
        bt_fonte.signal_font_set().connect(sigc::mem_fun(*this,&Widedit::cb_font_set));   
        bt_cor.signal_color_set().connect(sigc::mem_fun(*this,&Widedit::cb_color_set));
        bt_bkg.signal_color_set().connect(sigc::mem_fun(*this,&Widedit::cb_bkg_set));

        
        
        show_all();
        
        
    };
    
    void Widedit::cb_label_changed()
    {
        printf("\nWidgedit KEYPRESS");
        if (m_tchild->get_child_type() != LABEL) 
            return; 
        //Gtk::Widget::on_key_press_event(e);
        
        Ktk::Label *tmp_label = (Ktk::Label*) m_tchild->child_ptr;
        tmp_label->set_rotulo(etr_rotulo.get_text());    
        
        return ;// Gtk::Widget::on_key_press_event(e);
        
    }
    
    void Widedit::cb_font_set()
    {
        //        std::cout << bt_fonte.get_font_name() ; 
        Ktk::Label *tmp_label = (Ktk::Label*) m_tchild->child_ptr;
        tmp_label->set_font(Pango::FontDescription(bt_fonte.get_font_name()));    
        
        
    }
    
    void Widedit::cb_color_set()
    {
        Ktk::Label *tmp_label = (Ktk::Label*) m_tchild->child_ptr;
        Gdk::Color tmp_cor = bt_cor.get_color();
        tmp_label->set_color(tmp_cor);    
        
        
    }
    
    void Widedit::cb_bkg_set()
    {
        m_tchild->modify_bg(Gtk::STATE_NORMAL, bt_bkg.get_color()); 
    
    }
    
    
    
    
    void Widedit::cb_change_scale()
    {

        m_tchild->alpha_index = scale_alpha.get_value();
        m_tchild->saturate_index = scale_saturation.get_value();
        m_tchild->queue_draw();    
        
    
    }
    
    
    
    void Widedit::cb_change_spin()
    {
        printf("\non_change_spin");
        Gtk::Allocation alloc = m_tchild->get_allocation();
        alloc.set_x(spin_allocx.get_value());
        alloc.set_y(spin_allocy.get_value());
        alloc.set_width(spin_width.get_value());
        alloc.set_height(spin_height.get_value());
        m_tchild->pset_allocation(alloc);
        m_tchild->queue_draw();
        m_tchild->queue_resize();
        Gtk::Widget * par = get_parent ();

        
    
    }
    
    
    
    
    
    
    void Widedit::update_allocation(Gtk::Allocation  _allocation)
    {
        
        spin_allocx.set_value(_allocation.get_x());
        spin_allocy.set_value(_allocation.get_y());
        spin_width.set_value(_allocation.get_width());
        spin_height.set_value(_allocation.get_height());
        
        
    }
    
    
    int Widedit::set(Ktk::TChild * _tchild)
    {
        printf("\nWidedit --->SET ");
        
        m_tchild = _tchild;
        scale_alpha.set_value(_tchild->alpha_index);
        
        
        Glib::RefPtr<Gdk::Pixbuf> pbuf_shot = Gdk::Pixbuf::create ((Glib::RefPtr<Gdk::Drawable>)
                                                                   _tchild->get_window(), 0, 0, 
                                                                   _tchild->get_width(),
                                                                   _tchild->get_height());
        pbuf_shot = pbuf_shot->scale_simple(80,80, Gdk::INTERP_BILINEAR);
        
        img_widget.set(pbuf_shot);
        
        
        Gtk::Allocation m_allocation = m_tchild->get_allocation();
        spin_allocx.set_value(m_allocation.get_x());
        spin_allocy.set_value(m_allocation.get_y());
        spin_width.set_value(m_allocation.get_width());
        spin_height.set_value(m_allocation.get_height());
        
        
        switch(m_tchild->get_child_type())
        {	
            case LABEL:
                set_label();
                break;	
            case IMAGE:
                //		set_image();
                break;
            case DCLOCK:
                //		set_dclock();
                break;
            default:
                break;
        }	    
        
        
        
    }
    
    
    
    void Widedit::set_label()
    {
        Ktk::Label *tmp_label = (Ktk::Label*) m_tchild->child_ptr;
        etr_rotulo.set_text(tmp_label->get_rotulo());
        

//        bt_cor.set_
    
    
    
    }
    
    
    
    
    
    
    
    
    
    
    
    

    Ktk::TChild*  Widedit::getWidget()
    {
    return m_tchild;
    
    
    }
    
    int Widedit::set_pixbuf (Glib::RefPtr<Gdk::Pixbuf> _pbuf)
    {
        _pbuf = _pbuf->scale_simple(100,100, Gdk::INTERP_BILINEAR);
        img_widget.set(_pbuf);
        
    
    }
    
    
    

}; // Ktk
