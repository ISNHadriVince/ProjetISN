#include "GameLoop.h"
#include "Gui.h"
#include <SFML/Graphics.hpp>
#include "IRenderable.h"
#include <string.h>
#include <iostream>
#include <map>
#include <utility>
#include "worlds/Map.h"


bool GameLoop::run = true;

std::vector<IRenderable*> GameLoop::renderables;

void GameLoop::quitGame() {
    for(unsigned int i(0); i< renderables.size(); ++i)
    {

        delete renderables[i];  //On libère la i-ème case mémoire allouée
        renderables[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }
screen.close();
}


 void GameLoop::registerRender( IRenderable *render ) {
    renderables.push_back(render);
    std::cout<<"Adding render... (index " << (renderables.size() - 1) << ")" << std::endl;
}

void GameLoop::loop() {


   Map arene(&screen);
   arene.load();
   registerRender(&arene);


 while (screen.isOpen())
    {
        sf::Event event;
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
    quitGame();

            }


        }
    screen.clear();
        for (unsigned int i(0); i < renderables.size(); i++) {

            renderables[i]->render(screen);


        }


        screen.display();
    }
}
GameLoop::GameLoop() : screen(sf::VideoMode(800, 600), "Projet ISN") {

}


