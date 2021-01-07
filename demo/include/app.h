#ifndef APPH
#define APPH

#include<gtkmm.h>
#include"gui.h"
/*	
///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

// tudo aqui vai sofrer marshaling para presistencia de estado (recuperacao de desastre)
// todos os metodos devem estar na classe filha appDataClass
*/
    
class appData
{
public:
	
// estados
bool fechamento;


//Ticket ticket();


Glib::ustring get_config();
int set_config(Glib::ustring _config);


};



class appDataClass : appData
{
    public:
int setEstado();
estados getEstado();

appDataClass();
~appDataClass();

Glib::ustring configfile;
Glib::ustring configstr;

// persistencia dessa estrutura;
int parse_config();
int get_xml_config();
// int algo como update() para ler 



};


class app
{
    public:
    
    app(int _argc, char **_argv);
    ~app();
    
    estados m_estado;
    bool processamento();
    bool pagamento();
//    appDataClass m_dataclass;
    
    MainWin win_main;
    Gtk::EventBox evbox_main;
    pdvMain gui_main;
    pdvCliente gui_cliente;
    pdvMonitor gui_monitor;
    // tef
    // ecf
    
    // log
    bool cb_keypress(GdkEventKey* event);
        
};



	
#endif


	
	
