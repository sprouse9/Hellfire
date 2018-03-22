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
#include <sstream>
#include <iostream>
#include "ResourcePath.hpp"
#include "Bullet.hpp"

using namespace sf;
using namespace std;

class BulletManager
{

private:
    
    const short int maxBullet = 100;
    Bullet bullets[100];                 // Array of bullets
    int bulletCount;
    int indexOfNextAvailableBullet = 0;
    
    
    
    Clock clock;
    Time dt;
    
    //const float SPEED = 30;
    
    const int BULLET_TIMER = 50;         // in Milliseconds

//    Sprite   m_Sprite;
//    Texture  m_Texture;
    
    Vector2f m_Resolution;
    
    float m_Speed = 10;         // Speed in pixels per frame
    
    int dtSinceLastFrame = 0;   // is it time to move the bullet forward to the right?
    int dtSinceLastBullet = 0;
    
    Text hyphenBullet;
    Font sansationFont;
    
    
public:
    
    BulletManager(Vector2f resolution);
    
    void shoot(FloatRect playerPosition, int dtMilliseconds);
    
    // We will call this function once every frame
    void update(int dtMilliseconds);
    
    FloatRect getPostion();
    
    void draw(RenderWindow &targetWindow);
    
};
