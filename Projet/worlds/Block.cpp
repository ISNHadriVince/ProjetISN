#include "Block.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Map.h"


Block::Block(std::string texture,bool c,int s,int posX,int posY) {
sprite.setTexture(Map::t_tilesets[texture]);
sprite.setTextureRect(sf::IntRect(posX,posY,s,s));
collision = c;
if (c) {
    sprite.setColor(sf::Color(255,0,0));
}
}

sf::Sprite Block::getSprite() {
    return sprite;
}
sf::Sprite* Block::getRealSprite(){
    return &sprite;
}
void Block::setPosition(float x, float y) {
sprite.setPosition(x,y);
}
