//
//  Bullet.hpp
//  Hellfire
//
//  Created by Randy on 3/9/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//

#ifndef Bullet_hpp
#define Bullet_hpp

#endif /* Bullet_hpp */

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

using namespace sf;

class Bullet
{
    
private:
    const float SPEED = 2;
    
    const int SHIP_ROTATION_TIMER = 50; // in Milliseconds

    Vector2f m_Position;
//    Sprite   m_Sprite;
//    Texture  m_Texture;
    
    Vector2f m_Resolution;
    
    float m_Speed;          // Speed in pixels per second
    
    int dtSinceLastFrame;   // is it time to move the bullet forward to the right?
    
    Text hyphenBullet;
    Font sansationFont;
    
    bool bulletInFlight = false;
    
public:
    
    Bullet(Vector2f resolution);
    
    void moveRight();
    
    void shoot(FloatRect playerPosition);
    
    // We will call this function once every frame
    void update(float elapsedTime);
    
    // Send a copy of the sprite to main
    Sprite getSprite(int dtMilliseconds);
    
    FloatRect getPostion();
    
    Text getBullet(int dtMilliseconds);
    
};
