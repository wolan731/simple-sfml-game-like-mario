#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#pragma once
class koniec : public sf::Transformable
{
    public:
    sf::Texture a;
    std::optional<sf::Sprite> koniec1;
    sf::FloatRect gdzie_koniec;
    void rysuj(sf::RenderWindow& window,float a,float b)
    {
        laduj();
        koniec1->setPosition({a,b});
        window.draw(*koniec1);
        gdzie_koniec=koniec1->getGlobalBounds();
    }
    
    void laduj()
    {
        if(!a.loadFromFile("teskstory gry\\koniec.png"))
        {
            std::cerr << "\033[1;31m Błąd: Nie udało się otworzyć pliku! - koniec \033[0m\n";
        }
        koniec1.emplace(a);

    }


};