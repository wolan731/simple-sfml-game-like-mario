#ifndef PZECIWNIK_H
#define PZECIWNIK_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <windows.h>
class przeciwnik : public sf::Transformable
{
public:
    sf::Texture kol;
    std::optional<sf::Sprite> koll; 
    static sf::Clock zegar;
    static int licznik;
    sf::FloatRect kol_;

    przeciwnik()
    {
        if (!kol.loadFromFile("teskstory gry\\pixilart-drawing (2).png"))
        {
            std::cerr << "\033[1;31m Błąd: Nie udało się otworzyć pliku!(kolce) - koniec \033[0m\n";
            return;
        }
        koll.emplace(kol);
          
    }

    void widok_kolce(sf::RenderWindow& window,float a,float b)
    {
        
        licznik = zegar.getElapsedTime().asSeconds();
        
        if (licznik > 1 )  
        {
           
            //koll->setOrigin({kol_.size.x / 2.f, kol_.size.y / 2.f});
            koll->setPosition({a, b});
            kol_=koll->getGlobalBounds();
            
            //std::cout << kol_.position.x << std::endl;
            window.draw(*koll);
        }
  
        if (licznik > 2)
        {  
            kol_ = {};
            zegar.restart();  
            licznik = 0;
        }
        
    }
};
#endif
sf::Clock przeciwnik::zegar;
int przeciwnik::licznik = 0;