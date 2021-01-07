#include "tchild.h"
#include "tparent.h"
#include <gtkmm.h>
#include "common.h"
namespace Ktk
{
    
    
    int TChild::pset_resizable(bool _resizable) {m_resizable = _resizable;}
    bool TChild::pget_resizable () {return m_resizable;}

    CHILD_TYPE TChild::get_child_type()
    {
    return child_type;
    }
    
    void TChild::set_child_type( CHILD_TYPE _child_type)
    {
    child_type = _child_type;
    }

    
    
    void TChild::add (Gtk::Widget & _widget)
    {
        Gtk::Container::add(_widget);

        printf("\nCHILD: ADD WIDGET\n");
    }

    void TChild::add (Ktk::Label & _label)
    {
    printf("\nCHILD: Add Label");
        Gtk::Container::add(_label);
        child_type = LABEL;
        child_ptr = (void *) &_label;
    }

    void TChild::add (Ktk::Image & _image)
    {
	printf("\nCHILD: Add Image");
        Gtk::Container::add(_image);
        child_type = IMAGE;
        child_ptr = (void *) &_image;
    }
    
    void TChild::add (Ktk::Clock & _clock)
    {
        printf("\nCHILD: Add Clock");
        Gtk::Container::add(_clock);
        child_type = DCLOCK;
        child_ptr = (void *) &_clock;

    }











    
    
	
	TChild::TChild ( TParent *_parent )
	{
	printf ("\nConstrutor TChild");
	tparent = _parent;
        //set_app_paintable(true);
	add_events (Gdk::BUTTON_PRESS_MASK );
	add_events (Gdk::KEY_PRESS_MASK );
       // add_events (Gdk::POINTER_MOTION_MASK );
        add_events (Gdk::ALL_EVENTS_MASK );

        alpha_index = 50;
        saturate_index = 0;
        pset_resizable (true);
        
 //       set_double_buffered (false);
      
        
	};
	
 
       bool TChild::on_configure_event (GdkEventConfigure* event )
    {
	printf("\nChild Configure!!!");
    
    
    };

    
    void TChild::pset_allocation(Gtk::Allocation & _allocation)
    {
//        Gtk::EventBox::on_size_allocate(_allocation);

        set_size_request (_allocation.get_width(), _allocation.get_height());
        //tparent->cb_child_pset_allocation(this, _allocation);
        
    };

    
    
    
    
    
    
    
    
    bool TChild::on_button_press_event 	(	GdkEventButton * 	event 	 ) 
    {
	tparent->cb_child_click(this, event );
    return true;
    };
	
    bool TChild::on_button_release_event( GdkEventButton* event)
    {
	tparent->cb_child_release( this,event);
        return true;
    };

    bool TChild::on_motion_notify_event( GdkEventMotion* event)
    {
	tparent->cb_child_motion(this, event);
	return true;
    };
    
    
	
    
    bool TChild::on_key_press_event 	( GdkEventKey * 	event 	 ) 
    {
        tparent->cb_child_keypress(this, event);
    };
	
    bool TChild::on_enter_notify_event (GdkEventCrossing* event)
    {
    };
    
    bool TChild::on_leave_notify_event (GdkEventCrossing* event)
    {
    };

    
    bool TChild::on_expose_event (GdkEventExpose* event)
    {
	if (event->count >0) return true;
    	Gtk::Widget::on_expose_event(event);
          
	tparent->cb_child_expose(this, event);
        return false;
		
    };
    

    /*

    void TChild::add (Ktk::Image &_image)
    {}
    
	
	  void TChild::add (Ktk::Label &_label)
    {}
  
	*/
	
	
	
	
	
	
	
	
};



