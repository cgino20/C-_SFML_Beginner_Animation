#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"

int main(){
    sf::RenderWindow mainWindow(sf::VideoMode(512, 512), "Second Try in Animation");
    sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));    //  Creating an object with size where the texture will be applied.

    sf::Texture playerTexture;  //  Assigning the name of the texture.
    playerTexture.loadFromFile("data/images/textures/tux_from_linux.png");  //  Loading the texture file.
    player.setTexture(&playerTexture);  //  Assigning the texture to the object.

    Animation animation(&playerTexture, sf::Vector2u(3, 9), 0.3f);

    float deltaTime = 0.0f; //  Setting the time of animation.
    sf::Clock clock;

    while(mainWindow.isOpen()){
        /*
            .restart()
                It returns the time to the clock. It still contain the deltaTime.
            .asSeconds()
                It returns the time from the deltaTime in float.

        */
        deltaTime = clock.restart().asSeconds();    //  It converts the unit of the clock to float to use for animation.
        sf::Event event;
        while(mainWindow.pollEvent(event)){
            switch(event.type){
                case    sf::Event::Closed:
                        mainWindow.close();
                        break;
            }
        }
        /*
            int row = 0
                Selecting the animation row, in this case, the idle animation(first row of the image 0 - 8).
            deltaTime
                Time of animation.
        */
        animation.update(6, deltaTime);
        player.setTextureRect(animation.uvRect);

        mainWindow.clear(sf::Color(150, 150, 150));
        mainWindow.draw(player);
        mainWindow.display();
    }

    return 0;
}
