#ifndef _TCHILD_H_
#define _TCHILD_H_
#include<gtkmm.h>
#include"kcomp.h"
#include"common.h"

//********************************************************
//******************* T-C-h-i-l-d ************************
//********************************************************

namespace Ktk
{
    
    class TParent ;
    
    
    class TChild : public Gtk::EventBox
    {
        public:
            TParent * tparent;
            
            
            TChild (TParent *_parent);
            
            
        //	protected:

	    CHILD_TYPE child_type;
	    void * child_ptr;
	    
	    void set_child_type(CHILD_TYPE _child_type);
	    CHILD_TYPE get_child_type();
	                
            int alpha_index;
            int saturate_index;
            bool is_alpha();
            bool alpha;
            
            bool m_resizable;
            int pset_resizable(bool _resizable);
            bool pget_resizable ();
            
            bool m_buildable();
            void set_buildable(bool _buildable);
            bool get_buildable();
            
            
            void * m_child;
            void * get_child();
            

            virtual bool on_button_press_event( GdkEventButton* event); 
            virtual bool on_motion_notify_event(GdkEventMotion* event);
            virtual bool on_button_release_event( GdkEventButton* event); 

            virtual bool on_key_press_event( GdkEventKey* 	event ) ;
            virtual bool on_expose_event (GdkEventExpose* event);
            virtual bool on_configure_event (GdkEventConfigure* event );
            virtual bool on_enter_notify_event (GdkEventCrossing* event);
            virtual bool on_leave_notify_event (GdkEventCrossing* event);

            
            void add (Gtk::Widget & _widget);
            void add (Ktk::Label & _label);
            void add (Ktk::Image & _image);
            void add (Ktk::Clock & _clock);

            /*

             void add (Ktk::Label & _label);
             void add (Gtk::TreeView  & _tree);
             */          
            //motion
            void pset_allocation(Gtk::Allocation & _allocation);
            
            
            
            
            
    };
    
    
    
};







#endif // _TCHILD_H_
