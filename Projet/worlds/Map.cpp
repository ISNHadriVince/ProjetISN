#include "Map.h"
#include "MapLoader.hpp"
#include <iostream>
#include "TinyXML/tinyxml.h"
#include "../utils/Numbers.hpp"
#include <SFML/Graphics.hpp>
#include <tgmath.h>
#include <string>
#include "../entity/Player.h"

typedef struct {
    std::string texture;
    int posX,posY,width;
    bool collision;
} DataBlock;

std::map<std::string, sf::Texture> Map::t_tilesets;

    Map::Map(sf::RenderWindow *screen) {
m_screen = screen;



    }

void Map::loadTileSets() {

 TiXmlDocument doct;

if(!doct.LoadFile("ressources/tilesets/tileset.xml"))
{
    std::cerr << "Erreur 0 : " << doct.ErrorDesc() << std::endl;
    return;
}


std::map<int,DataBlock> descBlocks;


TiXmlElement* roott = doct.FirstChildElement();
if(roott == NULL)
{
    std::cerr << "Failed to load file: No root element."
         << std::endl;
    doct.Clear();
    return;
}

for(TiXmlElement* elem = roott->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
{

for(TiXmlElement* e = elem->FirstChildElement("tileset"); e != NULL; e = e->NextSiblingElement("tileset"))
{
        const char* attr;
      attr = e->Attribute("file");

        if(attr != NULL) {
            std::cout<< "--------- file :  " << attr << " ---------" << std::endl;
            sf::Texture text;
            if (text.loadFromFile(std::string("ressources/tilesets/") + attr)) {
               std::cout << "adding tileset index : " << attr << std::endl;
                t_tilesets[attr] = text;
            }
            else {
                std::cout << "Error while loading tileset..." << std::endl;
            }
        }
}
  std::cout << "tilesets loaded : " << t_tilesets.size() << std::endl;

}

}
void Map::load() {


 TiXmlDocument doct;

if(!doct.LoadFile("ressources/tilesets/tileset.xml"))
{
    std::cerr << "Erreur 0 : " << doct.ErrorDesc() << std::endl;
    return;
}


std::map<int,DataBlock> descBlocks;


TiXmlElement* roott = doct.FirstChildElement();
if(roott == NULL)
{
    std::cerr << "Failed to load file: No root element."
         << std::endl;
    doct.Clear();
    return;
}


for(TiXmlElement* elem = roott->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
{




   for(TiXmlElement* e = elem->FirstChildElement("tilesetTile"); e != NULL; e = e->NextSiblingElement("tilesetTile"))
{

    const char* attr;
attr = e->Attribute("id");

        if(attr != NULL) {

    int id = parseInt(attr);

    std::cout << "id : " << id << std::endl;

    attr = e->Attribute("width");
        if (attr != NULL) {
        int width = parseInt(attr);
        TiXmlElement* e2 = e->FirstChildElement("tilesetImage");
        attr = e2->Attribute("file");
        if (attr != NULL)  {
            std::string file = attr;
            std::cout << "File : " << attr << std::endl;
            attr = e2->Attribute("posX");
            if (attr != NULL) {
            int posX = parseInt(attr);
            attr = e2->Attribute("posY");
            if (attr != NULL) {
                int posY = parseInt(attr);
                TiXmlElement* e3 = e->FirstChildElement("collision");
                attr = e3->Attribute("area");
                bool collision = false;
                if (attr != NULL) {
                        std::string btemp = attr;
                     if (btemp.compare("full") == 0) {
                    collision = true;
                }
                std::cout << "collision : " << attr << " : " << collision << std::endl;
                DataBlock db;
                db.collision = collision;
                db.texture = file;
                db.posX = posX;
                db.posY = posY;
                db.width = width;
                descBlocks[id] = db;
                }

            }
            }

        }

        }

        }
}
}
std::cout << descBlocks.size() << " data blocks loaded !" << std::endl;
  std::vector<std::vector<int> > vectormap = loadMap("ressources/maps/map_test.xml", rows, columns);

    int step = 0;
    std::cout << "starting ..." << std::endl;
    for (int i(0); i < rows; i++) {
            std::vector<Block> temp;
        for (int j(0) ;j < columns; j++) {
          DataBlock db = descBlocks[vectormap[i][j]];
            std::cout << vectormap[i][j] << "-";

          Block block(db.texture,db.collision,32,db.posX,db.posY);
          block.setPosition(j* db.width, i * db.width);

        temp.push_back(block);

        }
        std::cout << std::endl;
        background.push_back(temp);


    step++;
    }
    std::cout << "step 1 finished !" << std::endl;

     for (int i(0); i < rows; i++) {
            std::vector<Block> temp;


        for (int j(0) ;j < columns; j++) {
          DataBlock db = descBlocks[vectormap[step][j]];
           Block block(db.texture,db.collision,db.width,db.posX,db.posY);
          block.setPosition(j* db.width, i * db.width);
        temp.push_back(block);

        }
        ground.push_back(temp);
    step++;
    }
    std::cout << "step 2 finished !" << std::endl;
     for (int i(0); i < rows; i++) {
            std::vector<Block> temp;


        for (int j(0) ;j < columns; j++) {
          DataBlock db = descBlocks[vectormap[step][j]];
           Block block(db.texture,db.collision,db.width,db.posX,db.posY);
          block.setPosition(j* db.width, i * db.width);
        temp.push_back(block);

        }
        foreground.push_back(temp);

//    background.push_back(vectormap[step]);
    step++;
    }
    std::cout << "background size : " << background.size() << std::endl;
     std::cout << "ground size : " << ground.size() << std::endl;
     std::cout << "foreground size : " << foreground.size() << std::endl;
     player.load("ressources/entity/player/body.png",ground);
     view = sf::View(sf::FloatRect(200, 200, 400, 300));
     m_screen->setView(view);


}

void Map::render(sf::RenderWindow& screen) {
/*
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
    view.move(-1, 0);
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{
    view.move(1, 0);
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{
    view.move(0, -1);
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{
    view.move(0, 1);
}*/

view.setCenter(sf::Vector2f(player.getPosition().left,player.getPosition().top));

m_screen->setView(view);

for (int i(0) ; i < rows; i++) {
    for (int j(0); j < columns; j++) {
        screen.draw(background[i][j].getSprite());
    }
}
for (int i(0) ; i < rows; i++) {
    for (int j(0); j < columns; j++) {
        screen.draw(ground[i][j].getSprite());
    }
}
player.draw(screen);
for (int i(0) ; i < rows; i++) {
    for (int j(0); j < columns; j++) {
        screen.draw(foreground[i][j].getSprite());
    }
}

}
