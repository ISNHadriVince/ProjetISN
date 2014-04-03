#include "MapLoader.hpp"
#include <string>
#include "TinyXML/tinyxml.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::vector<std::vector<int> > loadMap(const char * file,int& row, int& col) {


 std::vector<std::vector<int> > vectmaps;
 TiXmlDocument doc;

if(!doc.LoadFile(file))
{
    std::cerr << doc.ErrorDesc() << std::endl;
    return vectmaps;
}



TiXmlElement* root = doc.FirstChildElement();
if(root == NULL)
{
    std::cerr << "Failed to load file: No root element."
         << std::endl;
    doc.Clear();
    return vectmaps;
}
for(TiXmlElement* elem = root->FirstChildElement(); elem != NULL; elem = elem->NextSiblingElement())
{
   std::string elemName = elem->Value();
   std::cout<<"Noeud Principal : " << elemName << std::endl;
   if (elemName == "tilemap") {

        int rows;
        int columns;

const char* attr;
  attr = elem->Attribute("name");
        if(attr != NULL) {
            std::cout<< "Nom de la map : " << attr << std::endl;
        }
       attr = elem->Attribute("layers");
        if(attr != NULL) {
            std::cout<< "Nombre de couches : " << attr << std::endl;
        }
    attr = elem->Attribute("rows");
        if(attr != NULL) {
                std::istringstream flux(attr);

    flux >> rows;
    row = rows;
            std::cout<< "Nombre de lignes : " << attr << std::endl;
        }
          attr = elem->Attribute("columns");
        if(attr != NULL) {
                    std::istringstream flux(attr);

    flux >> columns;
    col = columns;
            std::cout<< "Nombre de colonnes : " << attr << std::endl;
        }

          attr = elem->Attribute("tileWidth");
        if(attr != NULL) {
            std::cout<< "Largeur d'une tile : " << attr << " px" << std::endl;
        }
          attr = elem->Attribute("tileHeight");
        if(attr != NULL) {
            std::cout<< "Hauteur d'une tile: " << attr << " px" << std::endl;
        }
           int f = 0;
        int g = 0;
    for(TiXmlElement* e = elem->FirstChildElement("layer"); e != NULL; e = e->NextSiblingElement("layer"))
{
    attr = e->Attribute("index");

        if(attr != NULL) {
            std::cout<< "--------- Layer  " << attr << " ---------" << std::endl;
        }

        for(TiXmlElement* data = e->FirstChildElement("data"); data != NULL; data = data->NextSiblingElement("data")) {



                const char* tilemap =  data->GetText();

                std::string s = tilemap;

std::string delimiter = ",";
size_t pos = 0;
std::string token;
int vect[rows * columns];
int co = 0;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);



    std::istringstream flux(token);
    int ii;
    flux >> ii;

    vect[co] = ii;


    co++;
    s.erase(0, pos + delimiter.length());
}
std::cout<<std::endl;
    std::istringstream flux(s);
    int ii;
    flux >> ii;
    vect[co] = ii;

    std::cout<< (sizeof(vect) / 4)<< " tiles " << std::endl;

    int i = 0;
   for (int y = 0; y < rows; y++) {
                std::vector<int> temp;


				for (int x = 0; x < columns; x++) {
				     temp.push_back(vect[i]);

					i++;
				}

   vectmaps.push_back(temp);


			}


std::cout << g << std::endl;
    for (int x = 0; x < rows; x++) {
				for (int y = 0; y < columns; y++) {
					std::cout<<vectmaps[g][y] << ",";
				}
				std::cout<<std::endl;

g++;
			}

std::cout << std::endl;

        }

}



   }

}
return vectmaps;
}
