#include<ktk/toolbox.h>
#include"gui.h"
//#include"pdvtoolbox.h"

#include"tree.h"
#include"textview.h"
#include<iostream>

pdvBase::pdvBase()
{
};

pdvBase::~pdvBase()
{
    printf("\nDestrutor pdvBase");
};
estados pdvBase::getEstado()
{};

int pdvBase::setEstado(estados novo_estado)
{};

int pdvBase::Init()
{};

void pdvBase::on_switch_page (GtkNotebookPage* page, guint page_num)
{
    printf("\nSuperPage %i", page_num);
}


//////////////////////////////////////////////////////////////////////////////
//////////////////// pdv_main
//////////////////////////////////////////////////////////////////////////////

pdvMain::pdvMain() 
{
	printf("\nconstrutor pdvMain()");
 
	set_tab_pos (Gtk::POS_TOP);
	set_show_tabs ();
	add_events (Gdk::ALL_EVENTS_MASK);
    
    
    // Adicionar os TParents
 // cuidado. nao mudar a ordem.
	append_page (tparInicio, "Inicio"); 
	append_page (tparFechado, "Fechado");
	append_page (tparAguarda, "Aguardando");
	append_page (tparProcessamento, "Processamento");
	append_page (tparPagamento, "Pagamento");
	append_page (tparInfo, "Informacoes");
	append_page (tparConfig, "Configuracoes");

    /*



	Glib::RefPtr<Gdk::Pixbuf> xbuf1 = Gdk::Pixbuf::create_from_file ("./img1.bmp");
	Ktk::Image *img1 = new Ktk::Image (xbuf1);
	tparInicio.put (*img1, 50,50);
    
	Glib::RefPtr<Gdk::Pixbuf> xbuf2 = Gdk::Pixbuf::create_from_file ("./img2.bmp");
	Ktk::Image *img2 = new Ktk::Image (xbuf2);
	tparFechado.put (*img2, 10,15);

    Glib::RefPtr<Gdk::Pixbuf> xbuf3 = Gdk::Pixbuf::create_from_file ("./img3.bmp");
	Ktk::Image *img3 = new Ktk::Image (xbuf3);
	tparPagamento.put (*img3, 15,20);

    
    Tree *tree = new Tree();
    Gtk::VBox *nbox = new Gtk::VBox();
    nbox->add(*tree);
    tparProcessamento.put (*nbox, 400,200);
    
    Example_TextView *tview = new Example_TextView();
    tparProcessamento.put (*tview, 10,10);
*/

    
    Tree *tree2 = new Tree();
    Gtk::Frame *frm2 = new Gtk::Frame();
    frm2->add(*tree2);
    tparInicio.put(*frm2, 10,10);

    
    Gtk::Button * bt = new Gtk::Button("Clickeeeeeeeee");
    tparAguarda.put(*bt, 5,5);
    bt->signal_clicked().connect( sigc::mem_fun(*this, &pdvMain::cb_teste));
 //   btClock.signal_clicked().connect( sigc::mem_fun(*this, &));

    
    
    // o toolbox e o edit pra essa gui
    toolbox = new pdvToolbox(this);
    widedit = new Ktk::Widedit();
 
    twin.add(*toolbox);
    twin.resize(20,20);
    twin.set_keep_above(true);
    wwin.add(*widedit);
    wwin.set_keep_above(true);

//    twin.show_all();
//    wwin.show_all();

    
    tparInicio.set_widedit(*widedit);
    tparFechado.set_widedit(*widedit);
    tparAguarda.set_widedit(*widedit);
    tparProcessamento.set_widedit(*widedit);
    tparPagamento.set_widedit(*widedit);
    tparConfig.set_widedit(*widedit);
    tparInfo.set_widedit(*widedit);
    
    

    tparInicio.setBackground("img.bmp");
    tparFechado.setBackground("img.bmp");
    tparAguarda.setBackground("img.bmp");
    tparProcessamento.setBackground("img.bmp");
    tparPagamento.setBackground("img.bmp");
    tparConfig.setBackground("img.bmp");
    tparInfo.setBackground("img.bmp");
    
 
    
    
    
show_all();	
	
};

pdvMain::~pdvMain() 
{
};

estados pdvMain::getEstado()
{};


int pdvMain::setEstado(estados novo_estado)
{};

int pdvMain::Init()
{};


int pdvMain::add (Glib::RefPtr<Gdk::Pixbuf> &_pbuf)
{

    tparAtual->put(* Gtk::manage (new Ktk::Image (_pbuf)), 10,10);
    tparAtual->show_all();

};



int pdvMain::add (Ktk::Label &_label)
{
    
    tparAtual->put(* Gtk::manage (&_label), 10,10);
    tparAtual->show_all();

};


int pdvMain::add (Ktk::Clock &_clock)
{
    tparAtual->put(* Gtk::manage (&_clock), 10,10);
    tparAtual->show_all();
}

void pdvMain::on_switch_page (GtkNotebookPage* page, guint page_num)
{
    
    page_num = ( page_num < 0)  ?  0 : page_num;
    page_num = ( page_num > 6)  ?  0 : page_num;
    
    Gtk::Notebook::on_switch_page(page, page_num);
    
    printf("\nPage %i", page_num);
    switch (page_num){
        
        case 0:
            tparAtual = &tparInicio;
            break;
        case 1:
            tparAtual = &tparFechado;
            break;
        case 2:
            tparAtual = &tparAguarda;
            break;
        case 3:
            tparAtual = &tparProcessamento;
            break;
        case 4:
            tparAtual = &tparPagamento;
            break;
        case 5:
            tparAtual = &tparInfo;
            break;
        case 6:
            tparAtual = &tparConfig;
            break;
            
        default:
            printf("\nPage default");
            tparAtual = &tparInicio;
            break;
    }

//tparAtual->signal_size_allocate().emit(tparAtual->get_allocation());
    
    
}

void pdvMain::cb_teste()
{
if (get_editmode())
        set_editmode(false);
else
        set_editmode(true);
    
    std::cout << tparAtual->get_description() ;

}




void pdvMain::set_editmode(bool _editmode)
{
    
    m_editmode = _editmode;
    
    if (_editmode){
        
        //    twin.set_visible(true);
        //    wwin.set_visible(true);
        twin.show_all();
        wwin.show_all();
         
        tparInicio.set_editmode(true);
        tparFechado.set_editmode(true);
        tparAguarda.set_editmode(true);
        tparProcessamento.set_editmode(true);
        tparPagamento.set_editmode(true);
        tparConfig.set_editmode(true);
        tparInfo.set_editmode(true);
    
    }
    else
    {
        twin.hide();
        wwin.hide();
        
        tparInicio.set_editmode(false);
        tparFechado.set_editmode(false);
        tparAguarda.set_editmode(false);
        tparProcessamento.set_editmode(false);
        tparPagamento.set_editmode(false);
        tparConfig.set_editmode(false);
        tparInfo.set_editmode(false);
    }
    
}

bool pdvMain::get_editmode()
{
    return m_editmode;
}






//////////////////////////////////////////////////////////////////////////////
//////////////////// MainWin
//////////////////////////////////////////////////////////////////////////////

MainWin::MainWin ()
{
    
};


EditWin::EditWin ()
{
    
};

EditWin::~EditWin ()
{
    
};




