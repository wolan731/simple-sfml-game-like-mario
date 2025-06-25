#include <SFML/Graphics.hpp>
#include <iostream>
#include "funkcje.h"
sf::View view(sf::FloatRect({0.f, 0.f}, {1920.f, 1080.f}));
void sterowanie(sf::RenderWindow& window) 
{
    bool run=1;
    window.clear();
    sf::Texture a("menu\\sterowanie.png");
    sf::Sprite sterowanie(a);
    sf::Texture zm("menu\\powroc do menu.png");
    sf::Sprite zamknij(zm);
    zamknij.setScale({1.3,1.3});
    zamknij.setPosition({960.f-170,900.f});

    sf::FloatRect zamknij_f=zamknij.getGlobalBounds();
    window.draw(sterowanie);
    window.draw(zamknij);
    window.display();
    while(run==1)
    {
   
       if(const std::optional menu_e = window.pollEvent())
       {
        if(const auto* mouseButtonPressed = (menu_e->getIf<sf::Event::MouseButtonPressed>()))
        {
          if(mouseButtonPressed->button == sf::Mouse::Button::Left)
          {
            sf::Vector2i mousePosition = mouseButtonPressed->position; 
            if(zamknij_f.contains(static_cast <sf::Vector2f> (mousePosition)))
            {
              window.clear();
              return ;
            }
          }
        }
         


       }
    }
}


bool powtrorka(sf::RenderWindow& window,float &z1) 
{    
  
   sf::View view = window.getView();
      sf::Vector2f viewSize = view.getSize();
      sf::Vector2f viewCenter = view.getCenter();
    view.setCenter({960.f, 540.f});
    window.setView(view);
    window.clear();
    sf::Texture a("menu\\powrotdomenu.png");
    sf::Sprite menu(a);
    sf::Texture zm("menu\\wyjdzzgry.png");
    sf::Sprite koniec(zm);

    
   
    sf::FloatRect menu_n = menu.getGlobalBounds();
    sf::FloatRect koniec_n = koniec.getGlobalBounds();
    menu.setOrigin({menu_n.size.x / 2.f , menu_n.size.y / 2.f});
    koniec.setOrigin({koniec_n.size.x / 2.f , koniec_n.size.y / 2.f});
    menu.setPosition({960.f, 900.f});
    koniec.setPosition({960.f, 400.f});
    menu_n = menu.getGlobalBounds();
    koniec_n = koniec.getGlobalBounds();
    window.draw(menu);
    window.draw(koniec);
    window.display();
    window.setView(window.getDefaultView());
   
    while(1)
    {
      
      
      
      //std::cout << "View size: " << viewSize.x << " x " << viewSize.y << std::endl;
      //std::cout << "View center: (" << viewCenter.x << ", " << viewCenter.y << ")" << std::endl;
        if(const std::optional menu_e = window.pollEvent())
       {
        if(const auto* mouseButtonPressed = (menu_e->getIf<sf::Event::MouseButtonPressed>()))
        {
          if(mouseButtonPressed->button == sf::Mouse::Button::Left)
          {
            sf::Vector2i mousePosition = mouseButtonPressed->position; 
            if(menu_n.contains(static_cast <sf::Vector2f> (mousePosition)))
            {
              window.clear();
              return 0;
            }
            if(koniec_n.contains(static_cast <sf::Vector2f> (mousePosition)))
            {
              window.clear();
              
              return 1;
            }
          }
        }
         


       }
    }
}