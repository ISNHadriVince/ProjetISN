#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "../worlds/Block.hpp"
class Player {
public:

void draw(sf::RenderWindow& screen);
void load(std::string file,std::vector<std::vector <Block> > gr);
sf::FloatRect getPosition();

private:

sf::Sprite body;
sf::Texture t_body;
sf::Clock clock;
int frame;
std::vector<std::vector <Block> > level;

};


#endif // PLAYER_H_INCLUDED
