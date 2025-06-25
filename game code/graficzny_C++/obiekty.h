#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#ifndef OBIEKTY_H
#define OBIEKTY_H
class obiekt : public sf::Transformable
{
    public:
    short w=0;

    static std::vector<sf::FloatRect> platformy;
    sf::RectangleShape hitbox;
    
    sf::Texture platfomra_ziemia1;
    std::optional<sf::Sprite> platfomra_ziemiaa1;
    sf::FloatRect platfomra_ziemiaaa1;

    sf::Texture platfomra_ziemia2;
    std::optional<sf::Sprite> platfomra_ziemiaa2;
    sf::FloatRect platfomra_ziemiaaa2;

    sf::Texture platfomra_ziemia3;
    std::optional<sf::Sprite> platfomra_ziemiaa3;
    sf::FloatRect platfomra_ziemiaaa3;

    sf::Texture drzewo1;
    std::optional<sf::Sprite> drzewoo1;


void rysuj_platforma1(sf::RenderWindow& window,float a,float b)
{
    if (!platfomra_ziemia1.loadFromFile("teskstory gry\\platforma.png") )
    {
         std::cerr << "Nie można załadować tekstur!\n";
         return;
    }
    platfomra_ziemiaa1.emplace(platfomra_ziemia1);
    platfomra_ziemiaaa1 = platfomra_ziemiaa1->getLocalBounds();
    platfomra_ziemiaa1->setPosition({a,b});
    
   
    window.draw(*platfomra_ziemiaa1);
    w=1;
    dodaj(w);
   
}
void rysuj_platforma2(sf::RenderWindow& window,float a,float b)
{
    if (!platfomra_ziemia2.loadFromFile("teskstory gry\\platforma2.png") )
    {
         std::cerr << "Nie można załadować tekstur!\n";
         return;
    }
    platfomra_ziemiaa2.emplace(platfomra_ziemia2);
    platfomra_ziemiaaa2 = platfomra_ziemiaa2->getLocalBounds();
    platfomra_ziemiaa2->setPosition({a,b});
    window.draw(*platfomra_ziemiaa2);
    w=2;
    dodaj(w);
   
}
void rysuj_platforma3(sf::RenderWindow& window,float a,float b)
{
    if (!platfomra_ziemia3.loadFromFile("teskstory gry\\platforma3_100.png") )
    {
         std::cerr << "Nie można załadować tekstur!\n";
         return;
    }
    platfomra_ziemiaa3.emplace(platfomra_ziemia3);
    platfomra_ziemiaaa3 = platfomra_ziemiaa3->getLocalBounds();
    platfomra_ziemiaa3->setPosition({a,b});
;

    
    window.draw(*platfomra_ziemiaa3);
    w=3;
    dodaj(w);
   
}
void rysuj_drzewo1(sf::RenderWindow& window,float a,float b)
{
    if (!drzewo1.loadFromFile("teskstory gry\\drzewo1.png") )
    {
         std::cerr << "Nie można załadować tekstur!\n";
         return;
    }
    drzewoo1.emplace(drzewo1);
    drzewoo1->setPosition({a,b});
    sf::FloatRect drzewooo1 = drzewoo1->getLocalBounds();
   
    window.draw(*drzewoo1);
    w=4;
    dodaj(w);
   
}



/*
//void rysujDebugHitbox2(sf::RenderWindow& window,float a,float b)
{
   //std::cout <<a<<" boko "<<b<<std::endl;

    
    hitbox.setOrigin({platfomra_ziemiaaa2.size.x / 2.f, platfomra_ziemiaaa2.size.y / 2.f});
    hitbox.setSize({platfomra_ziemiaaa2.size.x, platfomra_ziemiaaa2.size.y});
    hitbox.setPosition({a, b});
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(2.f);
 
    window.draw(hitbox);
}
*/
void dodaj(short w)
{
    switch (w)
    {
        case 1: platformy.push_back(platfomra_ziemiaa1->getGlobalBounds());
        ////
        case 2: platformy.push_back(platfomra_ziemiaa2->getGlobalBounds());
        ////
        case 3: platformy.push_back(platfomra_ziemiaa3->getGlobalBounds()); //std::cout<<"3";
    }
}



};
std::vector<sf::FloatRect> obiekt::platformy;
#endif