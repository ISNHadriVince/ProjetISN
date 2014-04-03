#ifndef GAMELOOP_H_INCLUDED
#define GAMELOOP_H_INCLUDED
#include <SFML/Graphics.hpp>
#include "IRenderable.h"
#include <vector>



class GameLoop {

public:


    void quitGame();
    static std::vector<IRenderable*> renderables;
    sf::RenderWindow screen;
    static void registerRender(IRenderable *render);
    void loop();
    GameLoop();
    static bool run;



private:


};

#endif
