#include"pdvtoolbox.h"
#include"gui.h"

pdvToolbox::pdvToolbox(pdvMain *_guiref)
{
    guiref = _guiref;
};

pdvToolbox::~pdvToolbox()
{
};


void pdvToolbox::cb_add_image()
{
    printf("\n\nadd IMAGE");
    
    Gtk::FileChooserDialog dlg("Teste", Gtk::FILE_CHOOSER_ACTION_OPEN);
    //	dlg.set_transient_for(*newwin);
    dlg.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dlg.add_button("Select", Gtk::RESPONSE_OK);
    //	dlg.set_current_folder_url("/root/");
    
    
    
    //  filtros para o dialogo de arquivos (imagens e any)
    Gtk::FileFilter flt_img;
    flt_img.set_name("Images");
    flt_img.add_pixbuf_formats();
    
    Gtk::FileFilter flt_any;
    flt_any.set_name("Any files");
    flt_any.add_pattern("*");
    
    dlg.add_filter(flt_img);
    dlg.add_filter(flt_any);
    
    
    
    // adicionando a imagem selecionada ao tparent      
    if (dlg.run() == Gtk::RESPONSE_OK)
    {
        Glib::ustring fname = dlg.get_filename();
        Glib::RefPtr<Gdk::Pixbuf> pbuf = Gdk::Pixbuf::create_from_file(fname);
        guiref->add(pbuf);   
    }
    
        
    
}




void pdvToolbox::cb_add_label()
{
        Ktk::Label *tmp_label = new Ktk::Label( "Texto Inicial");
        guiref->add(*tmp_label);


}


void pdvToolbox::cb_add_clock()
{
    Ktk::Clock *tmp_clock = new Ktk::Clock();
        guiref->add(*tmp_clock);
    
}




    













