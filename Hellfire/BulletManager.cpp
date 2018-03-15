//
//  BulletManager.cpp
//  Hellfire
//
//  Created by Randy on 3/9/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//

#include "BulletManager.hpp"

BulletManager::BulletManager(Vector2f resolution)
{
    //m_Speed = SPEED;

    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
    
    sansationFont.loadFromFile(resourcePath() + "sansation.ttf");
    hyphenBullet.setCharacterSize(30);
    hyphenBullet.setStyle(Text::Bold);
    hyphenBullet.setFont(sansationFont);
    hyphenBullet.setString( "==" );

    dtSinceLastFrame = 0;
}

FloatRect BulletManager::getPostion(){
    return hyphenBullet.getGlobalBounds();
}

void BulletManager::shoot(FloatRect playerPosition) {
    
    if( bulletInFlight == false) {
        // a new bullet was shot
        bulletInFlight = true;
        
        // set the initial coordinates for the bullet based on the player position
        m_Position.x = playerPosition.left + 130;
        m_Position.y = playerPosition.top + 40; // 40 is approximating the ship's nose
        
        
        
        
    }
}

void BulletManager::update(int dtMilliseconds) {
    
    // is there a bullet in flight?
    if(bulletInFlight == true){

        //have we reached the end of the edge of the window?
        if(m_Position.x < (m_Resolution.x)) {
            
            // change the timing to be based on the dt
            dtSinceLastFrame += dtMilliseconds;
            
            if(dtSinceLastFrame > BULLET_TIMER){
            
                m_Position.x += m_Speed;
                hyphenBullet.setPosition(m_Position);
                dtSinceLastFrame = 0;
            }
        }
        else
            bulletInFlight = false;
    }
}

void BulletManager::draw(RenderWindow &targetWindow) {
    
    if( bulletInFlight ) {
        targetWindow.draw(hyphenBullet);
    }
}
