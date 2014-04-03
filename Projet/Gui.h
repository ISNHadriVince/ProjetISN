#ifndef GUI_H_INCLUDED
#define GUI_H_INCLUDED
#include "IRenderable.h"
class Gui : public IRenderable {

public:

    virtual void render();
    void registerRender();
    Gui();
};

#endif // GUI_H_INCLUDED
