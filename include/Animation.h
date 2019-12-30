#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#pragma once

class Animation
{
    public:
        /*
            sf::Texture* texture
                For the size of the texture.
                This is a pointer.

            sf::Vector2u imageCount
                Contain the amount of images.
                It will store the amount of images to the private imageCount.

            float switchTime
                Time of each part of animation to take.
        */
        Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();

        /*
            int row
                what row of the animation to be access.

            float deltaTime
                time between the previous frame and the current frame.
        */
        void update(int row, float deltaTime);

    //  Separating the variables to functions.
    public:
        sf::IntRect uvRect;     //  Used to display the animation.

    private:
        sf::Vector2u imageCount;    //  The size of the image will be stored in it.
        sf::Vector2u currentImage;

    //  Controlling the speed of animation
        float totalTime;
        float switchTime;
};

#endif // ANIMATION_H
