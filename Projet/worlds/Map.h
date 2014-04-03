#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <vector>
#include "../IRenderable.h"
#include "Block.hpp"
#include <SFML/Graphics.hpp>
#include "../entity/Player.h"
class Map : public IRenderable{


public:
    void load();
    Map(sf::RenderWindow *screen);
   virtual void render(sf::RenderWindow& screen);
    std::vector<std::vector <Block> > background;
    std::vector<std::vector <Block> > ground;
    std::vector<std::vector<Block> > foreground;
    static std::map<std::string, sf::Texture> t_tilesets;
    static void loadTileSets();
    sf::View view;



private:

    sf::RenderWindow *m_screen;

    int rows;
    int columns;
    Player player;

};

#endif // MAP_H_INCLUDED
