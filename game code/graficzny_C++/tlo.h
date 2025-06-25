#ifndef Tlo_H
#define Tlo_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
class tlo : public sf::Transformable
{
    public:
        
    sf::Texture tekstura;
    std::optional<sf::Sprite> background;


    static int kt;



    void rysuj(sf::RenderWindow& window,int tk)
    {
        przypisz();
        background->setPosition({0.f+3840.f*(tk-1),0.f});
        window.draw(*background);
        
        background->setPosition({0.f+3840.f*tk,0.f});
        window.draw(*background);
        
    }
void przypisz()
    {
           if(tekstura.loadFromFile("tlo.png")) 
           {
             background.emplace(tekstura);
             
           }
           else
           {
               std::cout<<"bload";
           }

    }






};
int tlo::kt=0;



















#endif
