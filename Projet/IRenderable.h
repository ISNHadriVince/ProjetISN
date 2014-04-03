#ifndef IRENDERABLE_H_INCLUDED
#define IRENDERABLE_H_INCLUDED
#include <SFML/Graphics.hpp>
class IRenderable {

public:
    virtual void render(sf::RenderWindow& screen);
};


#endif
