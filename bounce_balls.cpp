#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <cstdlib>

const int winHEIGHT=600;
const int winWIDTH=800;


float random(int low, int high){
    
    return float (rand()%(high-low) +low);

}

sf::RenderWindow window(sf::VideoMode(winWIDTH,winHEIGHT),"Ballz");

// class Game{
//     public:
//         void run();
    
//     private:
//         void processEvents();
//         void update();
//         void render();
    
//     // private:
//     //     sf::RenderWindow window;
        
// };

// void Game::run(){
//     processEvents();
//     update();
//     render();
// }


class Ball{
    private:
        float ball_size;
        sf::Color ball_color;
        sf::CircleShape player;
        float posX;
        float posY;
        float velX;
        float velY;
        float gravity = 0.00001;
        float r_factor= 0.00005;

    private:
        void render(){
            window.draw(player);
        }

    public:
        Ball(float size,sf::Color color){
            ball_size=size;
            ball_color=color;
            player.setRadius(size);
            player.setFillColor(ball_color);
            posX=random(0,winWIDTH);
            posY=random(0,winHEIGHT);
            player.setOrigin(player.getRadius(),player.getRadius());
            velX=random(1,5)/100;
            velY=random(1,5)/50;
            // velX=0;
            // velY=0;
            update();
        }
    void update(){
            if((posX-ball_size <= 0) || (posX+ball_size >= winWIDTH)){
                velX= 0-velX;
            }
            if((posY-ball_size <= 0) || (posY+ball_size >= winHEIGHT)){
                velY= 0-velY;
            }
            velY+=gravity;
            velY-= velY*r_factor;
            posX+=velX;
            posY+=velY;
            player.setPosition(posX,posY);
            
            render();
        }
};



int main(){
    std::vector<Ball> Balls;
    int ball_count = 10;
    for(int i=0;i<ball_count;i++){
        Balls.push_back(Ball(20,sf::Color::Cyan));
    }

    while(window.isOpen()){
        window.clear();
        sf::Event event;
        while (window.pollEvent(event)){

            if (event.type == sf::Event::Closed)
                window.close();
        }

        for(int i=0;i<ball_count;i++){
                Balls[i].update();
            }
            
            
        window.display();
    }
}