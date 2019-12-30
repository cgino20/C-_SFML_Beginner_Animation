#include "Animation.h"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime)
{
    //ctor
    this->imageCount = imageCount;  //  Pointer to the specific class, it access the variable that have the same name.
    this->switchTime = switchTime;
    totalTime = 0.0f;
    currentImage.x = 0;     //  Currently accessing in the row(x). 0 because it will start at 0.

    //  Calculating the height and width of the image.
    uvRect.width = texture->getSize().x / float(imageCount.x);  //  Calculates the width of the image.
    uvRect.height = texture->getSize().y / float(imageCount.y); //  Calculates the height of the image.
}

Animation::~Animation()
{
    //dtor
}

void Animation::update(int row, float deltaTime){
    currentImage.y = row;   //  Setting the current image Y to row.
    totalTime += deltaTime;
    if(totalTime >= switchTime){
        totalTime -= switchTime;    //  To have a bit smoother animation.
        currentImage.x++;   //  It switch the current image from 0 onwards.

        if(currentImage.x >= imageCount.x){     //  Limits the switching of the image.
            currentImage.x = 0; //  Back to start of the animation.
        }
    }
    //  Setting the left top offset of the image.
    uvRect.left = currentImage.x * uvRect.width;
    uvRect.top = currentImage.y * uvRect.height;
}
