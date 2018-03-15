//
//  Bullet.hpp
//  Hellfire
//
//  Created by Randy on 3/9/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//

#ifndef BulletManager_hpp
#define BulletManager_hpp

#endif /* BulletManager_hpp */

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

using namespace sf;

class BulletManager
{

private:
    
    //bullets[4];                 // Array of bullets
    
    //const float SPEED = 30;
    
    const int BULLET_TIMER = 2; // in Milliseconds

    Vector2f m_Position;
//    Sprite   m_Sprite;
//    Texture  m_Texture;
    
    Vector2f m_Resolution;
    
    float m_Speed = 10;         // Speed in pixels per frame
    
    int dtSinceLastFrame = 0;   // is it time to move the bullet forward to the right?
    
    Text hyphenBullet;
    Font sansationFont;
    
    bool bulletInFlight = false;
    
public:
    
    BulletManager(Vector2f resolution);
    
    void shoot(FloatRect playerPosition);
    
    // We will call this function once every frame
    void update(int dtMilliseconds);
    
    FloatRect getPostion();
    
    void draw(RenderWindow &targetWindow);
    
};
