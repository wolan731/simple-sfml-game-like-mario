#ifndef PRZECIWNIKV2_H
#define PRZECIWNIKV2_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include "bohater.h"
class atak: public sf::Transformable
{
    public:
sf::Texture _1;
sf::Texture _2;
sf::Texture _3;
sf::Texture _4;
sf::Texture _5;
sf::Texture _6;
sf::Texture _7;
sf::Texture _8;
std::optional<sf::Sprite> goblin;

static sf::FloatRect lol;
static int ktory;
static float x;
static float y;
static short tik;
static short usungoblin[2];

int zmiana=0;
short j;
sf::FloatRect osoba;

int loadtxt(sf::RenderWindow& window,float a,float b,bool ud,float &x1,float &y1,short i )
{
   if(usungoblin[i]==0)
   {
    if(!(_1.loadFromFile("teskstory gry\\ork_pr\\1.png")&&
       _2.loadFromFile("teskstory gry\\ork_pr\\2.png")&&
       _3.loadFromFile("teskstory gry\\ork_pr\\3.png")&&
       _4.loadFromFile("teskstory gry\\ork_pr\\4.png")&&
       _5.loadFromFile("teskstory gry\\ork_pr\\5.png")&&
       _6.loadFromFile("teskstory gry\\ork_pr\\6.png")&&
       _7.loadFromFile("teskstory gry\\ork_pr\\7.png")&&
       _8.loadFromFile("teskstory gry\\ork_pr\\8.png"))
)
{
    std::cerr<<"\033[1;31m blad wczytywania goblina \033[0m \n";
}
         switch (ktory)
         {
         case 1: goblin.emplace(_1); ktory++; break;
         case 2: goblin.emplace(_2); ktory++; break;
         case 3: goblin.emplace(_3); ktory++; break;
         case 4: goblin.emplace(_4); ktory++; break;
         case 5: goblin.emplace(_5); ktory++; break;
         case 6: goblin.emplace(_6); ktory++; break;
         case 7: goblin.emplace(_7); ktory++; break;
         case 8: goblin.emplace(_8); ktory=1; break;
         
            
            
         
         
         }
         
         //std::cerr<<ktory<<std::endl;
          
        

          
        
          sf::FloatRect osobaa = Charaker::bohateer;
     
         


         
         if(x1==b+40)
         {
            zmiana=1;
            //(*goblin).setScale({-1.f, 1.f});
         }
         if(x1==a)
         {
            zmiana=0;
            //(*goblin).setScale({-1.f, 1.f});
         }
         if(zmiana==0)
         {
           
            x1=x1+2.5;
            //(*goblin).setScale({-1.f, 1.f});

         }
         if(zmiana==1)
         {
           
            x1=x1-2.5;
            goblin->setScale({-1.f, 1.f});

         }
        goblin->setPosition({x1,y1});
         osoba=goblin->getGlobalBounds();
         std::cerr<<"ud "<<ud<<std::endl;
          if(ud==1)
          {
            tik=3;
          }
        

        
           if (
                     (abs(static_cast<int>(osobaa.position.x) - static_cast<int>(osoba.position.x))<35) && // NIE RUSZAC KURWA 
                     (abs(static_cast<int>(osobaa.position.y) - static_cast<int>(osoba.position.y))<35)
               )
               {
                  if(tik>0)
                  {
                     std::cerr<<"weszlo w tik"<<std::endl;
                     usungoblin[i]=1;
                     (*goblin).setColor(sf::Color(255, 0, 0, 128));
                     window.draw(*goblin);
                     ud=0;
                     return 0;
                  }
                  else
                  {
                     return 1;
                  }
               }
               tik--;
               //(*goblin).setColor(sf::Color(60, 0, 0, 180));
              window.draw(*goblin);
              
        
}
return 0;
}
};



#endif