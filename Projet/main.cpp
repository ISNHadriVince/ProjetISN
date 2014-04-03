#include "GameLoop.h"
#include "worlds/Map.h"
#include <string>
#include "worlds/TinyXML/tinyxml.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <map>
#include "worlds/Map.h"

int main()
{

   Map::loadTileSets();
   GameLoop gameLoop;
   gameLoop.loop();





    return 5;
}
