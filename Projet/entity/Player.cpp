#include "Player.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../worlds/Block.hpp"

void Player::load(std::string file,std::vector<std::vector <Block> > gr) {
t_body.loadFromFile(file);
body.setTexture(t_body);
body.setTextureRect(sf::IntRect(22,96,22,32));
clock.restart();
frame = 0;
level = gr;

}

sf::FloatRect Player::getPosition() {
return body.getGlobalBounds();

}
void Player::draw(sf::RenderWindow& screen) {
    float time = 10;

    if (clock.getElapsedTime().asMilliseconds() >= time){
        clock.restart();
        frame++;
        if (frame == 3) {
            frame = 0;
        }
        }
float speed = 10.0f;
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
{

int caseX = (body.getGlobalBounds().left / 32) + 1;
int caseY = (body.getGlobalBounds().top + 32)  / 32;
Block block = level[caseY][caseX];
if (!block.collision) {
    body.move(speed,0);
}
body.setTextureRect(sf::IntRect(frame * 22,32,22,32));
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
{
int caseX = (body.getGlobalBounds().left / 32) - 1;
int caseY = (body.getGlobalBounds().top + 32) / 32;
Block block = level[caseY][caseX];
if (!block.collision) {
    body.move(-speed,0);
}
body.setTextureRect(sf::IntRect(frame * 22,64,22,32));
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
{

int caseX = (body.getGlobalBounds().left / 32) ;
int caseY = (body.getGlobalBounds().top + 32) / 32 - 1;
Block block = level[caseY][caseX];
if (!block.collision) {
  body.move(0,-speed);
}
body.setTextureRect(sf::IntRect(frame * 22,0,22,32));
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
{

int caseX = (body.getGlobalBounds().left / 32) ;
int caseY = (body.getGlobalBounds().top + 32) / 32 + 1;
Block block = level[caseY][caseX];
if (!block.collision) {
  body.move(0,speed);
}
body.setTextureRect(sf::IntRect(frame * 22,96,22,32));
}
screen.draw(body);
}
