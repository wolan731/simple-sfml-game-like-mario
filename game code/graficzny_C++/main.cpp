#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <random> 
#include <string> 
#include "menu/particle.h"
#include "bohater.h"
#include "obiekty.h"
#include "przeciwnik.h"
#include "tlo.h"
#include "przeciwnikv2.h"
#include "funkcje.h"

// zmiene statyczen do klas
int Charaker::skok = 0;
int Charaker::skok2 = 0;
int Charaker::rskok = 0;
int Charaker::bohater = 0;
int Charaker::licznik = 0;
sf::FloatRect Charaker::bohateer;
int Charaker::pw = 0;
bool Charaker::to_menu =0;
int atak::ktory=1;
float atak::x=1700;
float atak::y=550; 
short atak::tik=0;
short atak::usungoblin[2]={};
sf::FloatRect atak::lol;

// 

void wszsytko(sf::RenderWindow& window,float &z1, float &z2,int &p,Charaker &mario,sf::Clock &zegar,std::string  &spac,int &lastp,int &tl,sf::View &view,przeciwnik &kolce_1,
    przeciwnik &kolce_2,obiekt &platfoma1,obiekt &platfoma2,obiekt &platfoma3,obiekt &platfoma4, obiekt &drzewo1,tlo &backgound,int &potwierdzenie,atak &goblin,float &goblin1x,float &goblin1y,float &goblin2x,float &goblin2y,atak &goblin1);
bool postacchod(float &z1, float &z2,int &p,Charaker &mario,sf::Clock &zegar,std::string  &spac,int &lastp,int &potwierdzenie,bool &ud);
void watek2()
{
   sf::Music musi("sound\\muza.wav");
    musi.setLooping(true); 
    musi.play();
    while (true) {
       std::this_thread::sleep_for(std::chrono::milliseconds(100));
   }
   
}
bool menu(sf::RenderWindow& window) {
    
    bool menuRunning = true;
//////////////////
Charaker::to_menu=0;
sf::Texture przyciask_start("menu\\start_przycisk.png");
sf::Vector2f przyciask_start_wielosc(przyciask_start.getSize().x, przyciask_start.getSize().y);
sf::Sprite przyciask_starts(przyciask_start);
sf::FloatRect przyciask_starts_s = przyciask_starts.getLocalBounds();
przyciask_starts.setOrigin({przyciask_starts_s.size.x / 2.f, przyciask_starts_s.size.y / 2.f});
przyciask_starts.setPosition({960.f,540.f-200});
sf::FloatRect przyciask_starts_s_new = przyciask_starts.getGlobalBounds();
////////////////
sf::Texture przyciask_start_podmiana("menu\\start_przycisk_podmiana.png");
sf::Sprite przyciask_starts_podmianas(przyciask_start_podmiana);
sf::FloatRect przyciask_starts_podmianas_s = przyciask_starts_podmianas.getLocalBounds();
przyciask_starts_podmianas.setOrigin({przyciask_starts_podmianas_s.size.x / 2.f, przyciask_starts_podmianas_s.size.y / 2.f});
przyciask_starts_podmianas.setPosition({960.f,540.f-200});
sf::FloatRect przyciask_starts_podmianas_new = przyciask_starts_podmianas.getGlobalBounds();
////////////////
sf::Texture przyciask_wyjdz("menu\\wyjdz_przycisk.png");
sf::Vector2f przyciask_wyjdz_wielosc(przyciask_wyjdz.getSize().x, przyciask_wyjdz.getSize().y);
sf::Sprite przyciask_wyjdzs(przyciask_wyjdz);
sf::FloatRect przyciask_wyjdzs_s = przyciask_wyjdzs.getLocalBounds();
przyciask_wyjdzs.setOrigin({przyciask_wyjdzs_s.size.x / 2.f, przyciask_wyjdzs_s.size.y / 2.f});
przyciask_wyjdzs.setPosition({960.f,540.f+200});
sf::FloatRect przyciask_wyjdzs_s_new = przyciask_wyjdzs.getGlobalBounds();
////////////////
sf::Texture przyciask_wyjdz_podmiana("menu\\wyjdz_przycisk_podmiana.png");
sf::Sprite przyciask_wyjdz_podmianas(przyciask_wyjdz_podmiana);
sf::FloatRect przyciask_wyjdz_podmianas_s = przyciask_wyjdz_podmianas.getLocalBounds();
przyciask_wyjdz_podmianas.setOrigin({przyciask_wyjdz_podmianas_s.size.x / 2.f, przyciask_wyjdz_podmianas_s.size.y / 2.f});
przyciask_wyjdz_podmianas.setPosition({960.f,540.f+200});
sf::FloatRect przyciask_wyjdz_podmianas_new = przyciask_wyjdz_podmianas.getGlobalBounds();

sf::Texture sterowanie_textura("menu\\sterowanie_menu.png");
sf::Sprite przyciask_sterowanie(sterowanie_textura);
sf::FloatRect przyciask_sterowanie_s = przyciask_sterowanie.getLocalBounds();
przyciask_sterowanie.setOrigin({przyciask_sterowanie_s.size.x / 2.f, przyciask_sterowanie_s.size.y / 2.f});
przyciask_sterowanie.setPosition({960.f,500.f+20});
sf::FloatRect przyciask_sterowanie_new = przyciask_sterowanie.getGlobalBounds();
przyciask_sterowanie.setScale({0.70,0.70});

window.clear();
ParticleSystem particles(100);
sf::Clock clock;
sf::Vector2i mouse = sf::Mouse::getPosition(window);
particles.setEmitter(window.mapPixelToCoords(mouse));
sf::Time elapsed = clock.restart();
particles.update(elapsed);
sf::View currentView = window.getView();
sf::Vector2f size = currentView.getSize();
sf::Vector2f center = currentView.getCenter();


    while (window.isOpen()  && menuRunning==1) 
    {
       // std::cout << "Current view size: " << size.x << " x " << size.y << std::endl;
       //std::cout << "Current view center: (" << center.x << ", " << center.y << ")" << std::endl;
        
        while (const std::optional menu_e = window.pollEvent()) 
        {
            if (menu_e->is<sf::Event::Closed>())
            {
                window.close();
            }
                if (const auto* mouseButtonPressed = (menu_e->getIf<sf::Event::MouseButtonPressed>()))
                {
                    if (mouseButtonPressed->button == sf::Mouse::Button::Left)
                    {
                        sf::Vector2i mousePosition = mouseButtonPressed->position;  
                        if (przyciask_wyjdzs_s_new.contains(static_cast<sf::Vector2f>(mousePosition)))
                        {
    
                            
                            window.clear();
                            window.draw(przyciask_starts);
                            window.draw(przyciask_wyjdz_podmianas);
                            window.display();
                            std::this_thread::sleep_for(std::chrono::milliseconds(250));
                            window.close();
                            return 0;
                        }
                        if (przyciask_starts_s_new.contains(static_cast<sf::Vector2f>(mousePosition)))
                        {
                           
                            
                            window.clear();
                            window.draw(przyciask_starts_podmianas);
                            window.draw(przyciask_wyjdzs);
                            window.display();
                            std::this_thread::sleep_for(std::chrono::milliseconds(250));
                            menuRunning=0;
                            return 1;
                        }
                         if (przyciask_sterowanie_new.contains(static_cast<sf::Vector2f>(mousePosition)))
                        {
    
                            
                            sterowanie(window);
                            break;;
                            
                        }
                       
                    }
                } 

         }
         
         
         
        window.draw(przyciask_starts);
        window.draw(przyciask_wyjdzs);
        window.draw(przyciask_sterowanie);
        window.draw(particles);
        window.display();

         
         
         
        
    Sleep(50);
    window.clear();
    }
    
    
    
    
  
    return 0;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode({1920, 1080}), L"Gra Prototyp/n");
    sf::Vector2f srodek(window.getSize().x / 2, window.getSize().y / 2);
     //////////////////////////////
     window.clear();
    //////////////////////////////
    sf::Font ont; 
    if (!ont.openFromFile("trzcionka\\Arial.ttf"))
    {
       std::cerr<<"errroe";
    }
    sf::Text poczatek(ont);
    poczatek.setString("Mateusz Wolankewicz prezentuje");
    poczatek.setFillColor(sf::Color(255, 255, 255, 255));
    poczatek.setStyle(sf::Text::Italic);
    sf::FloatRect poczatekc = poczatek.getLocalBounds();
    poczatek.setOrigin({poczatekc.size.x / 2.f, poczatekc.size.y / 2.f});
    //////////////////////////////
    sf::Texture tlo_pus("tlo.png");
    sf::Vector2f tlo_2ielkosc(tlo_pus.getSize().x, tlo_pus.getSize().y);
    sf::Sprite tlo_pusty(tlo_pus);
    tlo_pusty.setScale({1.f,1.f});
    sf::FloatRect tlo_pustyy = tlo_pusty.getLocalBounds();
    //tlo_pusty.setOrigin({tlo_pustyy.size.x / 2.f, tlo_pustyy.size.y / 2.f});
    ///////////////////////////////
       poczatek.setPosition(srodek);
       window.draw(poczatek);
       window.display();
       Sleep(3500);
       window.clear();
       std::thread playMusic(watek2); 
       playMusic.detach();
       std::cout<< "\033[1;34m Witaj ,powyższy program został napisany przez m wolankiewicz ,poniżej zostana wypisane bledy przy uruchamianiu jesli takie byly\n"<< "\033[0m\n";
       if (menu(window) == 0)
       return 0;
   
       Charaker mario;
       float z1=500;
       float z2=600;
       obiekt platfoma1;
       obiekt platfoma2;
       obiekt platfoma3;
       obiekt platfoma4;
       obiekt drzewo1;
       
       float goblin1x=1700;
       float goblin1y=550;

       float goblin2x=2350;
       float goblin2y=510;

       int p=1;
       int lastp=1;
       int tl=0;
       std::string spac="";
       
       sf::Clock zegar;
       
       przeciwnik kolce_1;
       przeciwnik kolce_2;
       
       tlo backgound;
       
       window.setView(view);
       
       float czas_skok_s;
       int potwierdzenie=100;

       
       atak goblin;
       atak goblin1;
    while (window.isOpen())
    { 
        window.clear();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
     
      //pojeabne ify ↓
      {
    
    }
        wszsytko(window, z1, z2, p, mario, zegar, spac, lastp, tl, view, kolce_1, kolce_2, platfoma1, platfoma2,platfoma3,platfoma4, drzewo1, backgound,potwierdzenie,goblin,goblin1x,goblin1y,goblin2x,goblin2y,goblin1);
        window.display();
        if(Charaker::to_menu==1)
        {  view.setCenter({960.f, 540.f});
            window.setView(view);
            Charaker::to_menu=0;
            menu(window);
            window.clear();
            z1=500;
            z2=600;
            atak::x = 500;
            atak::y = 600;
            
            
        }
        Sleep(10);
        
        
            
    }
    
    return 0;
}
void wszsytko(sf::RenderWindow& window,float &z1, float &z2,int &p,Charaker &mario,sf::Clock &zegar,std::string  &spac,int &lastp,int &tl,sf::View &view,przeciwnik &kolce_1,
    przeciwnik &kolce_2,obiekt &platfoma1,obiekt &platfoma2,obiekt &platfoma3,obiekt &platfoma4,obiekt &drzewo1,tlo &backgound,int &potwierdzenie,atak &goblin,float &goblin1x,float &goblin1y,float &goblin2x,float &goblin2y,atak &goblin1) 
{
    bool wej=0;
    bool ud=0;
   //
        {
        postacchod(z1,z2,p,mario,zegar,spac,lastp,potwierdzenie,ud); //poruszanie sie postaci 
        backgound.rysuj(window,tl); //rysowanie tła
        if(goblin.usungoblin[0]==0)
        {
        wej=goblin.loadtxt(window,1750,2000,ud,goblin1x,goblin1y,0); 
        }
        if(wej==0)
        {
        wej=goblin1.loadtxt(window,2340.f,2500.f,ud,goblin2x,goblin2y,1); 
        }
         if(wej==1)
        {
          mario.die(window,z1,1);
          //std::cout<<"die kordyanty"<<z1;
        }

        } 
  
       
      
        //ponizej kolce musza byc wywalonae na 2 komendy w ten sposob ↓
        {
        kolce_1.widok_kolce(window,1400.f,770.f);
        mario.ustawKolce(kolce_1.kol_,window,z1);
        //
        kolce_1.widok_kolce(window,225.f,830.f);
        mario.ustawKolce(kolce_1.kol_,window,z1);
        //
        kolce_1.widok_kolce(window,2170.f,460.f);
        mario.ustawKolce(kolce_1.kol_,window,z1);
        //
        kolce_1.widok_kolce(window,3500.f,830.f);
        mario.ustawKolce(kolce_1.kol_,window,z1);
        }
        //po

        mario.widok1I2(window,z1,z2,p,potwierdzenie);
        tl=mario.gdzie(z1);
        view.setCenter({z1, 540.f});
        window.setView(view);

        //prdzmioty typu drzewa itd↓

        drzewo1.rysuj_drzewo1(window,300.f,250.f);   
        //platofrmy 
        {
        // Rozmieszczenie platform na różnych wysokościach Y
        platfoma3.rysuj_platforma1(window, 100.f, 630.f);
        platfoma3.rysuj_platforma1(window, -20.f, 530.f);
        platfoma1.rysuj_platforma3(window, 225.f, 850.f);   // Poziom 1 kolce 20 w dol
        platfoma2.rysuj_platforma2(window, 449.f, 900.f);
        platfoma2.rysuj_platforma2(window, 449.f, 800.f);
        platfoma3.rysuj_platforma1(window, 900.f, 790.f);
        platfoma2.rysuj_platforma2(window, 1050.f, 690.f);
        platfoma1.rysuj_platforma3(window, 1400.f, 790.f);
        platfoma3.rysuj_platforma1(window, 1550.f, 690.f);
        platfoma2.rysuj_platforma2(window, 1750.f, 590.f);
        platfoma1.rysuj_platforma3(window, 2170.f, 480.f);  //
        platfoma2.rysuj_platforma2(window, 2340.f, 550.f);  
        platfoma3.rysuj_platforma1(window, 2700.f, 660.f);
        platfoma3.rysuj_platforma1(window, 2920.f, 690.f);
        platfoma3.rysuj_platforma1(window, 3230.f, 700.f);
        platfoma1.rysuj_platforma3(window, 3500.f, 850.f);   
        platfoma1.rysuj_platforma2(window, 3700.f, 760.f);   
        //platfoma3.rysuj_platforma1(window, 4200.f, 700.f);
          
        }
    
} 















bool postacchod(float &a, float &b,int &p,Charaker &mario,sf::Clock &zegar,std::string  &spac,int &lastp,int &potwierdzenie,bool &ud) 
{
    int d;
    p=0;

    if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space) 

    &&(mario.sprawdzKolizje()==1) 

    &&(zegar.getElapsedTime().asSeconds() > 0.25))
    {

    if(mario.sprawdzKolizjegorna()==0)
    {
     mario.pw=1;
    }
    else
    {
      mario.pw=1;
    } 

    zegar.restart();
    ud=0;

    }

    if(mario.sprawdzKolizjegorna()==0)
    {
        d=mario.skakanie();
    }
    else
    {
        mario.rskok=0;
        d=mario.skakanie();
    }
    b=b-d;  
    ud=0;
    
    if  (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) || sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)  )
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            if(potwierdzenie < 11 || potwierdzenie > 14)
            {
            potwierdzenie=11;
            }
            switch (potwierdzenie)
            {
            case 11: p=11; break;
            case 12: p=12; break;
            case 13: p=13; break;
            case 14: p=14; break;
            }
           
        }

        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
            {
                if(potwierdzenie < 15 || potwierdzenie > 18)
                {
                potwierdzenie=15;
                }
                switch (potwierdzenie)
                {
                case 15: p=15; break;
                case 16: p=16; break;
                case 17: p=17; break;
                case 18: p=18; break;
                    
                }
                
            }
 
            if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
            {
            
                a=a+10;
                
            
            }

            if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            {
                
                a=a-10;
                
            
            }
        ud=1;    
    }
    else
    {
      
      if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) 
      {
        
          a=a+15;
          //ddddddddd  daaddddddddddddddddd ::cout<<"\033[1;33 p jest rowne\033[0m\n "<<p<<std::endl;
            if(potwierdzenie < 2 || potwierdzenie > 10)
            {
                potwierdzenie=1;
            }
            switch (potwierdzenie)
            {
            case 1: p=1; break;
            case 2: p=2; break;
            case 3: p=3; break;
            case 4: p=4; break;
            case 5: p=5; break;    //tu zjebane
            case 6: p=6; break;
            case 7: p=7; break;
            case 8: p=8; break;
            case 9: p=9; break;
            case 10: p=10; break;
            }
        }

        if  (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        {
             a=a-15;
            if(potwierdzenie > -1 || potwierdzenie < -10)
             {
                 potwierdzenie = -1;
             }
            //  std::cout<<"\033[1;33 p jest rowne\033[0m\n "<<p<<std::endl;
             switch (potwierdzenie)
            {
            case -1: p=-1; break;
            case -2: p=-2; break;
            case -3: p=-3; break;
            case -4: p=-4; break;
            case -5: p=-5; break;
            case -6: p=-6; break;
            case -7: p=-7; break;
            case -8: p=-8; break;
            case -9: p=-9; break;
            case -10: p=-10; break;
            } 
      
        }
        ud=0;
    }
        
     
    return 0;
}
      

