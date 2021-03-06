/*********************************************************************************
 * EmFace v. 0.1 beta
 * Copyright 2009 by Renato Merli
 * ALL RIGHTS RESERVED
 **********************************************************************************
 */


#include "tparent.h"
#include "toolbox.h"
#include<gtkmm.h>
#include<iostream>

namespace Ktk
{
    
    
    bool TParent::moving() {return m_moving;}
    void TParent::set_moving( bool _moving = true) { m_moving = _moving; }
    
    bool TParent::clicked() { return m_clicked; }
    void TParent::set_clicked (bool _clicked = true) { m_clicked = _clicked; }
    
    bool TParent::get_movedark() { return m_movedark; }
    void TParent::set_movedark (bool _movedark) { m_movedark = _movedark; }
    
    
    void TParent::set_widedit ( Widedit & _widedit) { m_widedit = &_widedit; }
    
    
    
    TParent::TParent()
    {
        Init();
    };
    
    
    TParent::~TParent()
    {};
    
    
    void TParent::Init()
    {
        
        set_moving (false);
        set_clicked (false);
        set_editmode (false);
        set_movedark (true);
        set_background_mode ();
        
        signal_size_allocate();
        set_has_window(true);
        add_events (Gdk::ALL_EVENTS_MASK);
        
    };
    
    // will rewrite this in the future.
    
    void TParent::put (Gtk::TreeView &_tree, int x, int y)
    {
        
        TChild *tmpchild = new TChild(this);
        tmpchild->add (_tree);
        if(editmode ()) tmpchild->set_above_child(true);
        Gtk::Fixed::put(*tmpchild,x,y);
        tmpchild->set_visible_window (true);
        show_all ();
        tchild_list.push_back(tmpchild);
    }
    
    void TParent::put (Gtk::Button &_bt, int x, int y)
    {
        
        TChild *tmpchild = new TChild(this);
        tmpchild->add (_bt);
        if(editmode ()) tmpchild->set_above_child(true);
        Gtk::Fixed::put(*tmpchild,x,y);
        tmpchild->set_visible_window (true);
        show_all ();
        tchild_list.push_back(tmpchild);
    }
    
    void TParent::put (Gtk::Frame &_frame, int x, int y)
    {
        TChild *tmpchild = new TChild(this);
        tmpchild->add (_frame);
        if(editmode ()) tmpchild->set_above_child(true);
        Gtk::Fixed::put(*tmpchild,x,y);
        tmpchild->set_visible_window (true);
        show_all ();
        tchild_list.push_back(tmpchild);
    }
    
    void TParent::put (Ktk::Label & _label, int x, int y)
    {
        printf("\nPut Label");
        
        TChild *tmpchild = new TChild(this);
        
        tmpchild->add (_label);
        
        Gtk::Fixed::put(*tmpchild,x,y);

        if(editmode ()) tmpchild->set_above_child(true);

        tmpchild->m_resizable=false;
        tmpchild->set_child_type(LABEL);
        tmpchild->set_visible_window (true);
        
        tchild_list.push_back(tmpchild);
        
        show_all ();
    }
    
    
    void TParent::put (Ktk::Clock & _clock, int x, int y)
    {
        TChild *tmpchild = new TChild(this);
        tmpchild->add (_clock);
        if(editmode ()) tmpchild->set_above_child(true);
        tmpchild->set_child_type(DCLOCK);

        tmpchild->m_resizable=false;
        Gtk::Fixed::put(*tmpchild,x,y);
        tmpchild->set_visible_window (false);
        tchild_list.push_back(tmpchild);
        
        
    }
    
    void TParent::put (Ktk::Image & _image, int x, int y)
    {
        
        TChild *tmpchild = new TChild(this);
        tmpchild->add (_image);
        if(editmode ()) tmpchild->set_above_child(true);
        Gtk::Fixed::put(*tmpchild,x,y);
        tmpchild->set_visible_window (true);
        show_all ();
        tchild_list.push_back(tmpchild);
        
    }
    
    
     void TParent::put (Gtk::Widget &_widget, int x, int y)
     {
         printf("\nPut Widget");
         TChild *tmpchild = new TChild(this);
         tmpchild->add (_widget);
         if(editmode ()) tmpchild->set_above_child(true);
         Gtk::Fixed::put(*tmpchild,x,y);
         tmpchild->set_visible_window (true);
         show_all ();
        tchild_list.push_back(tmpchild);

}
  
    
    
    
    void TParent::set_background_mode (tipo_fundo _fundo)
    {
        //	fundo = _fundo;
    }
    
    
    void TParent::setBackground (Glib::ustring  _file)
    {
        pbuf_background = Gdk::Pixbuf::create_from_file (_file);
    }
    
    bool TParent::editmode()
    {
        return m_editmode;
    }
    
    bool TParent::set_editmode (bool _editmode)
    {
        
        m_editmode = _editmode;        
        
        std::vector<Ktk::TChild*>::iterator it;
        
        for (it = tchild_list.begin(); it != tchild_list.end(); it++)
        {
            
            if (_editmode)
            {
                
                if ( (*it)->child_type == LABEL) 
                {
                    printf ("\n\n\n--->LABEL");
                    Ktk::Label *lbltmp = (Ktk::Label*) (*it)->child_ptr;
                    lbltmp->set_font(Pango::FontDescription("Sans Regular 22"));
                    
                }
                
                if ( (*it)->child_type == DCLOCK)
                {
                    printf ("\n\n\n--->CLOCK");
                    Ktk::Clock *clocktmp = (Ktk::Clock*) (*it)->child_ptr;
                    clocktmp->set_segundos(false);
                    
                }
                
                (*it)->set_above_child(true);
                //	    (*it)->hide();
                
            }
            else
            {
                (*it)->set_above_child(false);
                //	    (*it)->show();
                
                
            }
            
            
        }
        
    }    
        
        Glib::ustring TParent::get_description()
        {
        }
        
        
        
        
        
        ////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////
        //  MOTION
        ////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////
        // READ MOREFRESH MOUSE POSITIONS ?
        
        
        void TParent::cb_child_click (TChild * _tchild, GdkEventButton* event)
        {
            // se widget sendo editado nao eh atual, entao seta o atual
            if (editmode () && m_widedit->getWidget() != _tchild) m_widedit->set(_tchild);
            
            // tratamento padrao
            set_clicked (true);
            clicked_child = _tchild;
            clicked_allocation = _tchild->get_allocation();
            
            
            //get_pointer ((int&) clicked_pointer_x, (int&)clicked_pointer_y);
            clicked_pointer_x =  event->x;
            clicked_pointer_y =  event->y;
            clicked_root_x = event->x_root;
            clicked_root_y = event->y_root;
            
            translate_coordinates ( *_tchild, 0,0, clicked_widget_x, clicked_widget_y);
            //translate widgets retorna valores negativos, entao a linha abaixo
            clicked_widget_x = - clicked_widget_x;
            clicked_widget_y = - clicked_widget_y;
            
            clicked_width=_tchild->get_width();
            clicked_height=_tchild->get_height();
            
            move_left = clicked_pointer_x < 5 ? true: false;
            move_top = clicked_pointer_y < 5?  true: false;
            move_right = clicked_pointer_x  > ( _tchild->get_width()- 5 ) ? true : false ;
            move_down = clicked_pointer_y  > ( _tchild->get_height()- 5  ) ? true : false ;
            
        };
        
        
        
        
        
        void TParent::cb_child_release(TChild * _tchild, GdkEventButton* event)
        {
            clicked_child = NULL;
            set_clicked (false);
            if (moving ()){
                set_moving (false);
                m_widedit->update_allocation(_tchild->get_allocation());
                _tchild->queue_draw();
            }
            
        };
        
        
        
        
        
        
        void TParent::cb_child_motion(TChild * _tchild, GdkEventMotion* event)
        {        
            
            if (! editmode() ){
                _tchild->get_window()->set_cursor (Gdk::Cursor (   Gdk::X_CURSOR ));
                return;
            }
            
            if (clicked()) set_moving (true);
            
            int offset_x = event->x_root - clicked_root_x ;
            int offset_y = event->y_root - clicked_root_y ;
            
            if (!clicked() ){ 
                //////////////////////////////////////////////////////////////////////////////////////////
                // atualiza ponteiro do mouse e R-E-T-O-R-N-A !!!
                int x,y;
                _tchild->get_pointer(x,y);
                
                on_left = x < 5 ? true : false ;
                on_top = y < 5 ? true : false ;
                on_right = x > _tchild->get_width() - 5 ? true : false;
                on_down = y > _tchild->get_height() - 5 ? true : false;
                
                
                if ( !on_top && !on_left
                    && !on_down && ! on_right) // mid
                    _tchild->get_window()->set_cursor (Gdk::Cursor (   Gdk::X_CURSOR ));
                
                if (on_top && !on_left) // top
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::TOP_SIDE));
                
                if (on_top && on_left) // topleft
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::TOP_LEFT_CORNER));
                
                if (on_top && on_right) // topright
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::TOP_RIGHT_CORNER));
                
                if (on_down && !on_right && !on_left) // ondown
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::BOTTOM_SIDE ));
                
                if (on_down && on_right) //downright
                    _tchild->get_window()->set_cursor (Gdk::Cursor (   Gdk::BOTTOM_RIGHT_CORNER));
                
                if (on_down && on_left) //downleft
                    _tchild->get_window()->set_cursor (Gdk::Cursor (   Gdk::BOTTOM_LEFT_CORNER));
                
                if (on_left && !on_top && !on_down) //left
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::RIGHT_SIDE));
                
                if (on_right && !on_top && !on_down) //right
                    _tchild->get_window()->set_cursor (Gdk::Cursor ( Gdk::LEFT_SIDE));
                
                return;
            }
            
            ///////////////////////////////////////////////////////////////////////////////////////////
                
                
                if (!move_top && !move_down
                    && !move_left && !move_right){
                        // arrastando.
                        
                        int out_x = clicked_widget_x + offset_x;     
                        int out_y = clicked_widget_y + offset_y;    
                        // limita borda de cima
                        out_x = out_x > 0 ? out_x : 0 ;
                        out_y = out_y > 0 ? out_y : 0 ;
                        //limita borda de baixo (estouro no parent)
                        out_x = out_x + _tchild->get_width() < get_width() ? out_x : get_width() - _tchild->get_width(); 
                        out_y = out_y + _tchild->get_height() < get_height() ? out_y : get_height() - _tchild->get_height(); 
                        
                        if (clicked())
                            move (*_tchild, out_x, out_y );
                    }
            
            
            
            
            ////////////////////////////////////////////////////////////////////////
            //topleft
            if (move_left && move_top)
            {
                if(editmode () && _tchild->pget_resizable() ){
                    
                    
                    if (clicked()){
                        move (*_tchild, clicked_widget_x + offset_x, clicked_widget_y + offset_y);
                        
                        _tchild->set_size_request( clicked_width - offset_x, clicked_height - offset_y);
                    }
                    
                }
            }    
            ////////////////////////////////////////////////////////////////////////
            //topright
            if (move_top && move_right)
            {                 
                if(editmode () && _tchild->pget_resizable() ){
                    
                    if (clicked()){
                        
                        move (*_tchild, clicked_widget_x , clicked_widget_y + offset_y );
                        _tchild->set_size_request (clicked_width + offset_x, clicked_height - offset_y );
                    }
                }
            }
            
            
            
            
            ////////////////////////////////////////////////////////////////////////
            //top
            if (move_top && !move_right &&!move_left)
            {
                if(editmode () && _tchild->pget_resizable()){
                    
                    //set cursor
                    
                    if (clicked()){
                        move (*_tchild, clicked_widget_x , clicked_widget_y + offset_y );
                        _tchild->set_size_request (clicked_width, clicked_height - offset_y );
                        
                        
                    }
                }
            }
            
            ////////////////////////////////////////////////////////////////////////
            //down
            if (move_down && !move_left && ! move_right)
            {
                
                if(editmode ()&& _tchild->pget_resizable() ){
                    
                    
                    if (clicked()){
                        
                        _tchild->set_size_request( clicked_width, clicked_height + offset_y);
                        
                    }
                }
            }
            
            ////////////////////////////////////////////////////////////////////////
            //right
            if (move_right && !move_top)
            {
                if(editmode () && _tchild->pget_resizable() ){
                    
                    if (clicked()){
                        
                        _tchild->set_size_request (clicked_width + ( event->x_root - clicked_root_x), clicked_height);       
                        
                        
                    }
                }
            }
            
            
            
            ////////////////////////////////////////////////////////////////////////
            //left
            if (move_left && !move_top)
            {
                if( editmode() && _tchild->pget_resizable() ){
                    
                    if (clicked()){
                        move (*_tchild, clicked_widget_x + offset_x, clicked_widget_y );
                        _tchild->set_size_request( clicked_width - offset_x, clicked_height);
                    }
                }
            }
            
            
            
            
            ////////////////////////////////////////////////////////////////////////
            //downleft
            if (move_left && move_down)
            {           
                
                if( editmode() && _tchild->pget_resizable() ){
                    
                    if (clicked()){
                        move (*_tchild, clicked_widget_x + offset_x, clicked_widget_y );
                        _tchild->set_size_request( clicked_width - offset_x, clicked_height + offset_y);
                    }
                }
            }
            
            
            
            
            
            ////////////////////////////////////////////////////////////////////////
            //downright
            if (move_right && move_down)
            {
                if( editmode() && _tchild->pget_resizable() ){
                    
                    if (clicked()){
                        _tchild->set_size_request (clicked_width + offset_x,clicked_height + offset_y);       
                        
                    }
                }
            }
            
            
            
            _tchild->queue_draw();
            //        m_widedit->update_allocation(_tchild->get_allocation());
            
            
            
            
        };    
        
        
        void TParent::cb_child_keypress(TChild * _tchild, GdkEventKey* event)
        {};
        
        
        
        
        
        
        
        
        /* transparency     
     FIX; THIS APPROACH ONLY WORKS WHEN TCHILD HAVE IMAGES, EVBOXES, SOME OTHERS,
     BUT NOT TEXVIEW OR TREEVIEW.
     */
    
    void TParent::cb_child_expose (Ktk::TChild* _tchild, GdkEventExpose* event)
    {
        
        if (! is_mapped()) return;
        if (!_tchild->get_visible_window()) return;

        //////////////////////////////////////////////////////////////////////////////////////////
        int off_x, off_y;        
        translate_coordinates (*_tchild, 0,0, off_x, off_y);

        // get childshot
        Glib::RefPtr<Gdk::Window> mw = _tchild->get_window();
        Glib::RefPtr<Gdk::GC> gc = Gdk::GC::create(mw);

        Glib::RefPtr<Gdk::Pixbuf> pbuf_childshot = Gdk::Pixbuf::create ((Glib::RefPtr<Gdk::Drawable>)
                                                                        _tchild->get_window(), 0, 0, _tchild->get_width(),
                                                                        _tchild->get_height());
        //////////////////////////////////////////////////////////////////////////////////////////
        
        // if moving, just draw a box and return
        if ( moving() && clicked_child == _tchild
            && get_movedark())
        {
            mw->clear();
            mw->draw_line(gc, 3,3,  _tchild->get_width()-3, _tchild->get_height()-3);
            mw->draw_line(gc, 3, _tchild->get_height()-3, _tchild->get_width()-3, 3);
            mw->draw_line(gc, _tchild->get_width()/2 , 3 , _tchild->get_width()/2 , _tchild->get_height()-3);
            mw->draw_line(gc, 3, _tchild->get_height()/2, _tchild->get_width()-3, _tchild->get_height()/2);
            mw->draw_rectangle(gc, false, 3, 3, _tchild->get_width()-6, _tchild->get_height()-6);
        return;
        }
        
        
        
        
        
        // se estamos em editmode e widedit tem o widget atual, atualiza imagem em widedit
        if (editmode () && m_widedit->getWidget() == _tchild ) m_widedit->set_pixbuf(pbuf_childshot);
        
        // se nao ultrapassamos o limite da tela, entao podemos compor...
        if ( ( (off_x + _tchild->get_width()) < pbuf_background->get_width() )
            && (off_y + _tchild->get_height()) < pbuf_background->get_height()){
                
                /* the part we are cutting */
                Glib::RefPtr<Gdk::Pixbuf> pbuf_parentshot = Gdk::Pixbuf::create_subpixbuf( pbuf_background,
                                                                                          -off_x, -off_y,
                                                                                          _tchild->get_width(),
                                                                                          _tchild->get_height());
                
                /* composing-and-drawing-on-widget-and-returning :) */
                if (_tchild->alpha_index)
                    pbuf_background->composite(pbuf_childshot, 0,0, _tchild->get_width(), _tchild->get_height(),
                                               off_x, off_y, 1, 1, Gdk::INTERP_BILINEAR, _tchild->alpha_index);
                
                if (_tchild->saturate_index)
                    pbuf_childshot->saturate_and_pixelate(pbuf_childshot, _tchild->saturate_index, true);
                
                
                mw->draw_pixbuf(pbuf_childshot, 0,0,0,0, _tchild->get_width (), _tchild->get_height(), Gdk::RGB_DITHER_NONE, -1,-1);
                
               return; 
                
                
            }
        
        
    }
    
    
    // here we update the image background
    void TParent::on_size_allocate (Gtk::Allocation& allocation)
    {
        Gtk::Widget::on_size_allocate(allocation);
        
        if (! is_mapped()) return ;   
        
        Glib::RefPtr<Gdk::Window> mw = get_window();
        Glib::RefPtr<Gdk::GC> gc = Gdk::GC::create(mw);
        Glib::RefPtr<Gdk::Pixmap> pmap = Gdk::Pixmap::create(get_window(), allocation.get_width(), allocation.get_height (),  mw->get_depth());
        pbuf_background =	pbuf_background->scale_simple(allocation.get_width(), allocation.get_height(), Gdk::INTERP_BILINEAR);
        pmap->draw_pixbuf(pbuf_background, 0,0,0,0, allocation.get_width (), allocation.get_height(), Gdk::RGB_DITHER_NONE, 0,0);
        mw->set_back_pixmap (pmap, false);         
        
    };	
    
    
    
    
    
    
    
};  //   Ktk


    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
