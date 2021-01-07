#ifndef PDVTOOLBOX_H
#define PDVTOOLBOX_H

#include<ktk/toolbox.h>

class pdvMain;

class pdvToolbox : public Ktk::Toolbox
{
    public:

    pdvMain * guiref;

    pdvToolbox(pdvMain *_guiref);
    ~pdvToolbox();
    
    
    void cb_add_image();
    void cb_add_label();
    void cb_add_clock();




};


#endif

