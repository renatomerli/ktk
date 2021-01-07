#ifndef GUIH
#define GUIH

#include<gtkmm.h>

#include "pdvtoolbox.h"
#include "common.h"

#include <ktk/common.h>
#include <ktk/tparent.h>
#include <ktk/toolbox.h>
#include <ktk/kcomp.h>


class widEdit ;

	
//////////////////////////////////////////////////////////////////////////////
//////////////////// BaseWin
//////////////////////////////////////////////////////////////////////////////
	
	class BaseWin : public Gtk::Window 
	{
		
		public:
//		BaseWin();
		int Init ();
		// set_screen
	};
	

	
	
	
	
//////////////////////////////////////////////////////////////////////////////		
//////////////////// MainWin
//////////////////////////////////////////////////////////////////////////////

	class MainWin : public BaseWin
	{
	
		public:
		MainWin();

//		pdvMain nb_main;
		
	};

	class EditWin : public BaseWin
	{
	
		public:
		EditWin();
        ~EditWin();
        

//		pdvMain nb_main;
		
	};
//////////////////////////////////////////////////////////////////////////////
//////////////////// pdvBase
//////////////////////////////////////////////////////////////////////////////

class pdvBase : public Gtk::Notebook
	{
		public:
			pdvBase();
			~pdvBase();
		
		private:
		
			bool fechamento;
			bool bloqueado;
			bool debug;
			
			
          
            estados estado;

            virtual estados getEstado();
			virtual	int setEstado(estados _estado);
			virtual int Init();
			
            virtual void on_switch_page (GtkNotebookPage* page, guint page_num);
    }; // base_gui			


	
	
	
//////////////////////////////////////////////////////////////////////////////
//////////////////// pdvMain
/////////////////////////////////////////////////////////////////////////////////
		
class pdvMain : public pdvBase
{
    public:
    
        // tem que ter venda, lista produtos, mvc, estado, tudo aqui
        pdvMain();
        ~pdvMain();
        
        // TParent e TParentData para todos os estados
        Ktk::TParent tparInicio, tparFechado, tparAguarda, tparProcessamento, tparPagamento,  tparInfo, tparConfig;
        
        Ktk::TParent * tparAtual;
        pdvToolbox * toolbox;
        Ktk::Widedit * widedit;
        
        // toolbar window, widedit window
        EditWin twin, wwin;
        
        int add (Glib::RefPtr<Gdk::Pixbuf> &_pbuf);
        int add (Ktk::Label &_label);
        int add (Ktk::Clock &_clock);
        
        // sobrecarga
        
        estados getEstado();
        int setEstado(estados novo_estado);
      
        bool m_editmode;
        void set_editmode(bool _editmode);
        bool get_editmode();
        int Init();		
        virtual void on_switch_page (GtkNotebookPage* page, guint page_num);        
            
        
        void cb_teste();
        
};


	
	
	
	


//////////////////////////////////////////////////////////////////////////////
/////////////////// segundo monitor
/////////////////////////////////////////////////////////////////////////////////
		
	class pdvCliente : public pdvBase
	{
	};

//////////////////////////////////////////////////////////////////////////////
/////////////////// terceiro monitor
/////////////////////////////////////////////////////////////////////////////////
	
	class pdvMonitor : public pdvBase
	{
	};

	
	


#endif
