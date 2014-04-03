#ifndef BLOCK_HPP_INCLUDED
#define BLOCK_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
class Block {

public:

    Block(std::string texture,bool collision,int s,int posX,int posY);
    sf::Sprite getSprite();
    void setPosition(float x, float y);
    sf::Sprite* getRealSprite();
    bool collision;
private:

    sf::Sprite sprite;

    sf::Texture texture;

};


#endif // BLOCK_HPP_INCLUDED
