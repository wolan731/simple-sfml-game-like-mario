
#ifndef BOHATER_H
#define BOHATER_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>
#include <windows.h>
#include "obiekty.h"
#include "koniec.h"
#include "funkcje.h"

class Charaker : public sf::Transformable
{
public:
 
    
    sf::Texture teksturakoncowa;
    
    sf::Sprite* kolce = nullptr;
    bool smierc_kolec=0;
    static int skok;
    static int skok2;
    static int rskok;
    static int bohater;
    static int licznik;
    static int pw;
    static bool to_menu;
    sf::RectangleShape hitbox;

    //prwo ⬇️
    sf::Texture animacja1; //1
    sf::Texture animacja2; //2
    sf::Texture animacja3; //3
    sf::Texture animacja4; //4
    sf::Texture animacja5; //5
    sf::Texture animacja6; //6
    sf::Texture animacja7; //7
    sf::Texture animacja8; //8
    sf::Texture animacja9; //9
    sf::Texture animacja10; //10
    //lewo ⬇️
    sf::Texture _1animacja; //1
    sf::Texture _2animacja; //2
    sf::Texture _3animacja; //3
    sf::Texture _4animacja; //4
    sf::Texture _5animacja; //5 
    sf::Texture _6animacja; //6
    sf::Texture _7animacja; //7
    sf::Texture _8animacja; //8 
    sf::Texture _9animacja; //9
    sf::Texture _10animacja;//10
    //stanie ⬇️
    sf::Texture apostoj;//10
    //atak prawo ⬇️ 
    sf::Texture atak_1; //1
    sf::Texture atak_2; //2
    sf::Texture atak_3; //3
    sf::Texture atak_4; //4
    //atak lewo ⬇️ 
    sf::Texture atak_11; //1
    sf::Texture atak_22; //2
    sf::Texture atak_33; //3
    sf::Texture atak_44; //4
 


    std::optional<sf::Sprite> osoba1; 
    std::optional<sf::Sprite> osoba2;
    std::optional<sf::Sprite> osoba3;
    std::optional<sf::Sprite> osoba4; 
    std::optional<sf::Sprite> osoba5;
    std::optional<sf::Sprite> osoba6;
    std::optional<sf::Sprite> osoba7; 
    std::optional<sf::Sprite> osoba8;
    std::optional<sf::Sprite> osoba9;
    std::optional<sf::Sprite> osoba10;
    
    std::optional<sf::Sprite> _osoba1; 
    std::optional<sf::Sprite> _osoba2;
    std::optional<sf::Sprite> _osoba3;
    std::optional<sf::Sprite> _osoba4; 
    std::optional<sf::Sprite> _osoba5;
    std::optional<sf::Sprite> _osoba6;
    std::optional<sf::Sprite> _osoba7; 
    std::optional<sf::Sprite> _osoba8;
    std::optional<sf::Sprite> _osoba9;
    std::optional<sf::Sprite> _osoba10;


    std::optional<sf::Sprite> postoj;
    //atak prawo ⬇️ 
    std::optional<sf::Sprite> atak_1_p;
    std::optional<sf::Sprite> atak_2_p;
    std::optional<sf::Sprite> atak_3_p;
    std::optional<sf::Sprite> atak_4_p;

    std::optional<sf::Sprite> atak_1_l;
    std::optional<sf::Sprite> atak_2_l;
    std::optional<sf::Sprite> atak_3_l;
    std::optional<sf::Sprite> atak_4_l;

    sf::FloatRect osoba1_inn;
    sf::FloatRect osoba2_inn;
    sf::FloatRect osoba3_inn;
    sf::FloatRect osoba4_inn;
    sf::FloatRect osoba5_inn;
    sf::FloatRect osoba6_inn;
    sf::FloatRect osoba7_inn;
    sf::FloatRect osoba8_inn;
    sf::FloatRect osoba9_inn;
    sf::FloatRect osoba10_inn;

    sf::FloatRect _osoba1_inn;
    sf::FloatRect _osoba2_inn;
    sf::FloatRect _osoba3_inn;
    sf::FloatRect _osoba4_inn;
    sf::FloatRect _osoba5_inn;
    sf::FloatRect _osoba6_inn;
    sf::FloatRect _osoba7_inn;
    sf::FloatRect _osoba8_inn;
    sf::FloatRect _osoba9_inn;
    sf::FloatRect _osoba10_inn;
    
    static sf::FloatRect bohateer; 


    sf::FloatRect kolce_in;
    //
    sf::FloatRect osobav_inn; //uniewerslae gówno spowmiedzy tych wyrzej bo sie pierdoli jak tusk w ue 
    //
    sf::View widok;
    float z1=500;
    float z2=500;

    sf::Texture sm; 
    std::optional<sf::Sprite> koniec1;
    
    Charaker()
    {
        
        // Ładowanie tekstur
        if ( !sm.loadFromFile("teskstory gry\\sm.png")
        || !_1animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\1_Run.png")
        || !_2animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\2_Run.png")
        || !_3animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\3_Run.png")
        || !_4animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\4_Run.png")
        || !_5animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\5_Run.png")
        || !_6animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\6_Run.png")
        || !_7animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\7_Run.png")
        || !_8animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\8_Run.png")
        || !_9animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\9_Run.png")
        || !_10animacja.loadFromFile("teskstory gry\\postacie\\bieg lewo\\10_Run.png")
        || !animacja1.loadFromFile("teskstory gry\\postacie\\biegpr\\1_Run.png") 
        || !animacja2.loadFromFile("teskstory gry\\postacie\\biegpr\\2_Run.png")    
        || !animacja3.loadFromFile("teskstory gry\\postacie\\biegpr\\3_Run.png")
        || !animacja4.loadFromFile("teskstory gry\\postacie\\biegpr\\4_Run.png")
        || !animacja5.loadFromFile("teskstory gry\\postacie\\biegpr\\5_Run.png")
        || !animacja6.loadFromFile("teskstory gry\\postacie\\biegpr\\6_Run.png")
        || !animacja7.loadFromFile("teskstory gry\\postacie\\biegpr\\7_Run.png")
        || !animacja8.loadFromFile("teskstory gry\\postacie\\biegpr\\8_Run.png")
        || !animacja9.loadFromFile("teskstory gry\\postacie\\biegpr\\9_Run.png")
        || !animacja10.loadFromFile("teskstory gry\\postacie\\biegpr\\10_Run.png")
        || !apostoj.loadFromFile("teskstory gry\\postacie\\_Idle.png")
        || !atak_1.loadFromFile("teskstory gry\\postacie\\atak_pr\\1.png")
        || !atak_2.loadFromFile("teskstory gry\\postacie\\atak_pr\\2.png")
        || !atak_3.loadFromFile("teskstory gry\\postacie\\atak_pr\\3.png")
        || !atak_4.loadFromFile("teskstory gry\\postacie\\atak_pr\\4.png")    
        || !atak_11.loadFromFile("teskstory gry\\postacie\\atak_lw\\1.png")
        || !atak_22.loadFromFile("teskstory gry\\postacie\\atak_lw\\2.png")
        || !atak_33.loadFromFile("teskstory gry\\postacie\\atak_lw\\3.png")
        || !atak_44.loadFromFile("teskstory gry\\postacie\\atak_lw\\4.png")                                                                                       )
        {
            std::cerr << "\033[1;31mNie można załadować tekstur!\nMożliwe problemy -\n"
            << "Problem z folderem graficzny_C++\\graficzny_C++\\teskstory gry\\postacie \n"
            << "\033[0m\n";
         
             return;
        }
        else
        {
            std::wcerr<<L"\033[1;31m zładowane popranie " << "\033[0m\n";
         
        }


        _osoba1.emplace(_1animacja);
        _osoba2.emplace(_2animacja);
        _osoba3.emplace(_3animacja);
        _osoba4.emplace(_4animacja);
        _osoba5.emplace(_5animacja);
        _osoba6.emplace(_6animacja);
        _osoba7.emplace(_7animacja);
        _osoba8.emplace(_8animacja);
        _osoba9.emplace(_9animacja);
        _osoba10.emplace(_10animacja);

        osoba1.emplace(animacja1);
        osoba2.emplace(animacja2);
        osoba3.emplace(animacja3);
        osoba4.emplace(animacja4);
        osoba5.emplace(animacja5);
        osoba6.emplace(animacja6);
        osoba7.emplace(animacja7);
        osoba8.emplace(animacja8);
        osoba9.emplace(animacja9);
        osoba10.emplace(animacja10);

        postoj.emplace(apostoj);

        atak_1_p.emplace(atak_1);
        atak_2_p.emplace(atak_2);
        atak_3_p.emplace(atak_3);
        atak_4_p.emplace(atak_4);    

        atak_1_l.emplace(atak_11);
        atak_2_l.emplace(atak_22);
        atak_3_l.emplace(atak_33);
        atak_4_l.emplace(atak_44);  

        koniec1.emplace(sm);

        sf::FloatRect osoba1_in = osoba1->getLocalBounds();
        sf::FloatRect osoba2_in = osoba2->getLocalBounds();
        sf::FloatRect osoba3_in = osoba3->getLocalBounds(); 
        sf::FloatRect osoba4_in = osoba4->getLocalBounds();
        sf::FloatRect osoba5_in = osoba5->getLocalBounds();
        sf::FloatRect osoba6_in = osoba6->getLocalBounds();
        sf::FloatRect osoba7_in = osoba7->getLocalBounds();
        sf::FloatRect osoba8_in = osoba8->getLocalBounds();
        sf::FloatRect osoba9_in = osoba9->getLocalBounds();
        sf::FloatRect osoba10_in = osoba10->getLocalBounds();

        sf::FloatRect _osoba1_in = _osoba1->getLocalBounds();
        sf::FloatRect _osoba2_in = _osoba2->getLocalBounds();
        sf::FloatRect _osoba3_in = _osoba3->getLocalBounds(); 
        sf::FloatRect _osoba4_in = _osoba4->getLocalBounds();
        sf::FloatRect _osoba5_in = _osoba5->getLocalBounds();
        sf::FloatRect _osoba6_in = _osoba6->getLocalBounds();
        sf::FloatRect _osoba7_in = _osoba7->getLocalBounds();
        sf::FloatRect _osoba8_in = _osoba8->getLocalBounds();
        sf::FloatRect _osoba9_in = _osoba9->getLocalBounds();
        sf::FloatRect _osoba10_in = _osoba10->getLocalBounds();

        sf::FloatRect postoj_in=postoj->getLocalBounds();

        sf::FloatRect atak_1_in = atak_1_p->getLocalBounds();
        sf::FloatRect atak_2_in = atak_2_p->getLocalBounds();
        sf::FloatRect atak_3_in = atak_3_p->getLocalBounds();
        sf::FloatRect atak_4_in = atak_4_p->getLocalBounds();

        sf::FloatRect atak_1_lin = atak_1_l->getLocalBounds();
        sf::FloatRect atak_2_lin = atak_2_l->getLocalBounds();
        sf::FloatRect atak_3_lin = atak_3_l->getLocalBounds();
        sf::FloatRect atak_4_lin = atak_4_l->getLocalBounds();



        // Ustawienie punktu 'origin' na środek sprite'ów
        osoba1->setOrigin({osoba1_in.size.x / 2.f, osoba1_in.size.y / 2.f});
        osoba2->setOrigin({osoba2_in.size.x / 2.f, osoba2_in.size.y / 2.f});
        osoba3->setOrigin({osoba3_in.size.x / 2.f, osoba3_in.size.y / 2.f});
        osoba4->setOrigin({osoba4_in.size.x / 2.f, osoba4_in.size.y / 2.f});
        osoba5->setOrigin({osoba5_in.size.x / 2.f, osoba5_in.size.y / 2.f});
        osoba6->setOrigin({osoba6_in.size.x / 2.f, osoba6_in.size.y / 2.f});
        osoba7->setOrigin({osoba7_in.size.x / 2.f, osoba7_in.size.y / 2.f});
        osoba8->setOrigin({osoba8_in.size.x / 2.f, osoba8_in.size.y / 2.f});
        osoba9->setOrigin({osoba9_in.size.x / 2.f, osoba9_in.size.y / 2.f});
        osoba10->setOrigin({osoba10_in.size.x / 2.f, osoba10_in.size.y / 2.f});

        _osoba1->setOrigin({_osoba1_in.size.x / 2.f, _osoba1_in.size.y / 2.f});
        _osoba2->setOrigin({_osoba2_in.size.x / 2.f, _osoba2_in.size.y / 2.f});
        _osoba3->setOrigin({_osoba3_in.size.x / 2.f, _osoba3_in.size.y / 2.f});
        _osoba4->setOrigin({_osoba4_in.size.x / 2.f, _osoba4_in.size.y / 2.f});
        _osoba5->setOrigin({_osoba5_in.size.x / 2.f, _osoba5_in.size.y / 2.f});
        _osoba6->setOrigin({_osoba6_in.size.x / 2.f, _osoba6_in.size.y / 2.f});
        _osoba7->setOrigin({_osoba7_in.size.x / 2.f, _osoba7_in.size.y / 2.f});
        _osoba8->setOrigin({_osoba8_in.size.x / 2.f, _osoba8_in.size.y / 2.f});
        _osoba9->setOrigin({_osoba9_in.size.x / 2.f, _osoba9_in.size.y / 2.f});
        _osoba10->setOrigin({_osoba10_in.size.x / 2.f, _osoba10_in.size.y / 2.f});

        postoj->setOrigin({postoj_in.size.x / 2.f,postoj_in.size.y / 2.f});
 
        atak_1_p->setOrigin({atak_1_in.size.x / 2.f,atak_1_in.size.y / 2.f});
        atak_2_p->setOrigin({atak_2_in.size.x / 2.f,atak_2_in.size.y / 2.f});
        atak_3_p->setOrigin({atak_3_in.size.x / 2.f,atak_3_in.size.y / 2.f});
        atak_4_p->setOrigin({atak_4_in.size.x / 2.f,atak_4_in.size.y / 2.f});

        atak_1_l->setOrigin({atak_1_lin.size.x / 2.f,atak_1_lin.size.y / 2.f});
        atak_2_l->setOrigin({atak_2_lin.size.x / 2.f,atak_2_lin.size.y / 2.f});
        atak_3_l->setOrigin({atak_3_lin.size.x / 2.f,atak_3_lin.size.y / 2.f});
        atak_4_l->setOrigin({atak_4_lin.size.x / 2.f,atak_4_lin.size.y / 2.f});


     
        



       

    }
////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////
    void widok1I2(sf::RenderWindow& window, float& z1, float& z2, int p,int &potwierdzenie)
{
if (osoba1 && osoba2 && osoba3 && osoba4 && osoba5 && osoba6 && osoba7 && osoba8 && osoba9 && osoba10 )
    {
        //std::wcout<<"\033[1;33m p jest równe w bohaterze \033[0m "<<p<<"\n";
        if (die(window,z1,0) == 0)
        {
            sf::Sprite* aktywnySprite = nullptr;
            //sf::Sprite* L=nullptr;
            
            switch (p) 
            {  //chod w prawo ->
                case 1: aktywnySprite = &*osoba1; potwierdzenie=2; break;
                case 2: aktywnySprite = &*osoba2; potwierdzenie=3; break; 
                case 3: aktywnySprite = &*osoba3; potwierdzenie=4; break;//tu
                case 4: aktywnySprite = &*osoba4; potwierdzenie=5; break;//
                case 5: aktywnySprite = &*osoba5; potwierdzenie=6; break;
                case 6: aktywnySprite = &*osoba6; potwierdzenie=7; break;
                case 7: aktywnySprite = &*osoba7; potwierdzenie=8; break;
                case 8: aktywnySprite = &*osoba8; potwierdzenie=9; break;
                case 9: aktywnySprite = &*osoba9; potwierdzenie=10; break;
                case 10: aktywnySprite = &*osoba10; potwierdzenie=11; break;

                case -1: aktywnySprite = &*_osoba1; potwierdzenie=-2; break;
                case -2: aktywnySprite = &*_osoba2; potwierdzenie=-3; break; 
                case -3: aktywnySprite = &*_osoba3; potwierdzenie=-4; break;
                case -4: aktywnySprite = &*_osoba4; potwierdzenie=-5; break;
                case -5: aktywnySprite = &*_osoba5; potwierdzenie=-6; break;
                case -6: aktywnySprite = &*_osoba6; potwierdzenie=-7; break;
                case -7: aktywnySprite = &*_osoba7; potwierdzenie=-8; break;
                case -8: aktywnySprite = &*_osoba8; potwierdzenie=-9; break;
                case -9: aktywnySprite = &*_osoba9; potwierdzenie=-10; break;
                case -10: aktywnySprite = &*_osoba10; potwierdzenie=-11; break;
                
                case 0: aktywnySprite = &*postoj; break;

                case 11: aktywnySprite = &*atak_1_p; potwierdzenie=12; break;
                case 12: aktywnySprite = &*atak_2_p; potwierdzenie=13; break;
                case 13: aktywnySprite = &*atak_3_p; potwierdzenie=14; break;
                case 14: aktywnySprite = &*atak_4_p; potwierdzenie=11; break;
              
                case 15: aktywnySprite = &*atak_1_l;  potwierdzenie=16; break;
                case 16: aktywnySprite = &*atak_2_l;  potwierdzenie=17; break;
                case 17: aktywnySprite = &*atak_3_l;  potwierdzenie=18; break;
                case 18: aktywnySprite = &*atak_4_l;  potwierdzenie=19; break;
              




                //case 3: aktywnySprite = &*osoba14; break;
                //case 4: aktywnySprite = &*osoba24; break;
               // case 5: aktywnySprite = &*osoba34; break;
               // case 6: aktywnySprite = &*osoba44; break;

               // case 7: aktywnySprite = &*osoba1_4; break;
               // case 8: aktywnySprite = &*osoba2_4; break;
               // case 9: aktywnySprite = &*osoba3_4; break;
                //case 10: aktywnySprite = &*osoba4_4; break;
                
            }

           // std::cout<<" swich"<<std::endl;
            
            
            if (aktywnySprite )
            
             //  std::cout<<"whcozdi swich if"<<std::endl;
                aktywnySprite->scale({1.3f, 1.3f}); 
                aktywnySprite->setPosition({z1, z2});
                osobav_inn = aktywnySprite->getGlobalBounds(); // aktualizacja hitboxa
                koniecc(window,4200,650,z1);
                grwaitacja(z2); 
               
               bohateer=osobav_inn; 

               // rysujDebugHitbox(window); 
                window.draw(*aktywnySprite); 
                aktywnySprite->scale({0.7692f, 0.7692f}); 
               
                //aktywnySprite->setScale({-1.f,1.f});
            
            //grwaitacja(z2); 
        }
        else
        {
            for (int i = 0; i < 255; i++)
            {
                koniec1->setColor(sf::Color(255, 255, 255, i));
                koniec1->setPosition({z1-960,0.f});
                window.draw(*koniec1);
                window.display();
                Sleep(1);
            }

            window.close();
        }
    }
    else
   {
       //std::cerr<<"\033[1;31m nie wczytno posatci w bohater !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\033[0m\n";
    }
}


    
    bool sprawdzKolizje() 
{
    for (const auto& platform : obiekt::platformy) 
    {
      
        // Ręczne sprawdzenie przecięcia dwóch prostokątów
        if (
            (osobav_inn.position.x + osobav_inn.size.x  > platform.position.x-5) && // NIE RUSZAC KURWA 
            (osobav_inn.position.x+5  < platform.position.x + platform.size.x) &&
            (osobav_inn.position.y + osobav_inn.size.y  > platform.position.y) &&
            (osobav_inn.position.y < platform.position.y -platform.size.y)
        )
        {
           // std::cout<<std::endl;
           // std::cout<<"pozycja platormy - "<<platform.position.x<<" "<<platform.position.y<<std::endl;
           // std::cout<<"rozmiar - "<<platform.size.y<<std::endl;
           //std::cout<<"pozycja osoby - "<<osobav_inn.position.y<<std::endl;
           // std::cout<<"rozmiar osoby - "<<osobav_inn.size.y<<std::endl;
           // std::cout<<std::endl;
           //std::cout<<"\033[1;33m Kolizja dolna "<< "\033[0m\n"<<std:: endl;
            return true; 
        }
    }//std::cout<<"\033[1;33m Kolizja dolna brak "<< "\033[0m\n"<<std:: endl;
    return false;
}
bool sprawdzKolizjegorna() 
{
    int i=300;
    int a=0;
    int b=0;
    b++;
    for (const auto& platform : obiekt::platformy)  /**/
    {
       // std::cout<<"\033[1;34mpozycja platormy - "<<platform.position.x<<" "<<platform.position.y<<std::endl;
      //  std::cout<<"rozmiar - "<<platform.size.y<<std::endl;
       // std::cout<<"pozycja osoby - "<<osobav_inn.position.y<<std::endl;
       // std::cerr << "\033[1;33mrozmiar osoby - " << osobav_inn.size.y << "\033[0m" << std::endl;
    if ((osobav_inn.position.x + osobav_inn.size.x /*-34*/  > platform.position.x) && // NIE RUSZAC KURWA 
    (osobav_inn.position.x /*30 */ < platform.position.x + platform.size.x) &&
    (osobav_inn.position.y - 10 < platform.position.y + platform.size.y) &&
    (osobav_inn.position.y > platform.position.y))
   {
  
    
    while(osobav_inn.position.y  - i  < platform.position.y )
        {
            i=i-10;
             
            //std::cout<<"\033[1;33m Kolizja gorna "<< "\033[0m\n"<<std:: endl;
        }
        std::cout<<"\033[1;33m Kolizja gorna "<< "\033[0m\n"<<std:: endl;
        skok=i;
    return 1;
   }
  
        
}

//std::cout<<b<<std::endl; 
return 0;
}

bool sprawdzKolizjeboccznep()
{

    
    for (const auto& platform : obiekt::platformy)
    {
        
        
        if ((osobav_inn.position.x+44 < platform.position.x + platform.size.x &&        
            osobav_inn.position.x-40 > platform.position.x - platform.size.x )&&
        (((osobav_inn.position.y+osobav_inn.size.y/2<platform.position.y-platform.size.y)&&
        (osobav_inn.position.y+osobav_inn.size.y/2>platform.position.y))||

        ((osobav_inn.position.y-osobav_inn.size.y/2>platform.position.y)&&
        (osobav_inn.position.y-osobav_inn.size.y/2<platform.position.y+platform.size.y))||

        ((osobav_inn.position.y-osobav_inn.size.y/2<platform.position.y)&&
        (osobav_inn.position.y+osobav_inn.size.y/2>platform.position.y+platform.size.y))))                                                                                     
       // &&osobav_inn.position.x+osobav_inn.size.x-34>platform.position.x - platform.size.x )
           
        {
            //std::cout << "💥 Kolizja boczna wykryta!" << std::endl;
            
            return false;
        }
    }
    return false;
}


void grwaitacja(float &z2)
{
    //std::cout<<"grawitacja ";
    if(sprawdzKolizje()==0 && rskok==0)
    {
      z2=z2+10;
      //std::cout<<"zminiono grawitacje"<<std::endl;
    }
   else
    {
       skok=300;
    }
}
//void grwaitacjab(float &z2)
//{
    
   // {
    //  z2=z2+10;
      
   // }
//}
bool die(sf::RenderWindow& window,float &z1,bool p)
{
  bool k=0;
   if(die_in_space()==1)
   {
    k=1;

   }

   if(smierc_kolec==1 || p==1)
     {
        //std::cout<<"top"<<std:: endl;
        for (int i = 0; i < 255; i++)
        {
            koniec1->setColor(sf::Color(255, 255, 255, i));
            koniec1->setPosition({z1-960,0.f});
            window.draw(*koniec1);
            window.display();
            Sleep(1);
        }

        
        k=1;
     }
     
   if(k==1)
   {
    if(powtrorka(window,z1)==1)
    {
        window.close();
        return 1; 
    }
    to_menu=1;
   }
   return 0;
  
} 
void ustawKolce(sf::FloatRect& kol_,sf::RenderWindow& window,float z1)
{
        //std::cout<<kol_.position.x<<"AA "<<std::endl;

    if (osobav_inn.position.x < kol_.position.x + kol_.size.x &&        
        osobav_inn.position.x > kol_.position.x - kol_.size.x &&                                                                                                                                          /*osobav_inn.position.x + osobav_inn.size.x > platform.position.x+34*/         
        osobav_inn.position.y < kol_.position.y + kol_.size.y &&      
        osobav_inn.position.y + osobav_inn.size.y > kol_.position.y
)
    {
        //std::cout<<"inter"<<std:: endl;
        smierc_kolec=1;
        die(window,z1,0);
    }
    
    smierc_kolec=0;
}
bool die_in_space()
{
    if (
        ( 
            osobav_inn.position.y > 1080 
        )
       
    )
    {
       return 1; 
    }
    return 0; 
} 
void rysujDebugHitbox(sf::RenderWindow& window)
{
    sf::RectangleShape hitbox;
    hitbox.setSize({osobav_inn.size.x, osobav_inn.size.y});
    hitbox.setPosition({osobav_inn.position.x, osobav_inn.position.y});
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(2.f);

    window.draw(hitbox);
}
int gdzie(float z1)
{
   // std::cout<<"wejscie"<<std::endl;
 
   if(osobav_inn.position.x<3840-960-10)
   {
    return 0;

   }
    bohater=1;
   if(osobav_inn.position.x+960+10>3840*bohater )
   {
    
   //std::cout<<"++"<<std::endl;
   
   }
   return bohater;
   bohater++;

}
void koniecc(sf::RenderWindow& window,float a,float b,float &z1)
{
   koniec koniec_1;
   koniec_1.rysuj(window,a,b);
   
   
   if(osobav_inn.findIntersection(koniec_1.gdzie_koniec))
   {
    if(!teksturakoncowa.loadFromFile("teskstory gry\\koniec1.png"))
    {
           std::cerr<<"\033[1;31m blad \033[0m\n";
    }
    window.clear();
    sf::Sprite a(teksturakoncowa);
    a.setPosition({z1-960-20,0.f});
    window.draw(a);
    window.display();
    Sleep(5000);
    if(powtrorka(window,z1)==1)
    {
        window.close();
        
    }
    to_menu=1;
    window.clear();
    z1=500;
    //z2=600;
  
    std::cerr<<"\033[1;31m ide do menu !!!!!!!!!\033[0m\n";
     return;
   }

}
int skakanie()
{

    if(pw==1)
    {
    rskok=300;
    skok2=300;
    pw=0;
    }
   int ac=rskok*0.08;
   licznik=ac+licznik;
   rskok=rskok*0.80;
   if(licznik>300)
   {
    rskok+10;
   } 
   if(rskok<10)
   {
    rskok=0;
   }
   return ac;
}
};
#endif




