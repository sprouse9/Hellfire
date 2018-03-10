//
//  Bullet.cpp
//  Hellfire
//
//  Created by Randy on 3/9/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//

#include "Bullet.hpp"

Bullet::Bullet(Vector2f resolution)
{
    m_Speed = SPEED;

    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
    
    
    sansationFont.loadFromFile(resourcePath() + "sansation.ttf");
    hyphenBullet.setCharacterSize(30);
    hyphenBullet.setStyle(sf::Text::Bold);
    hyphenBullet.setFont(sansationFont);
    hyphenBullet.setString( "==>" );

    dtSinceLastFrame = 0;
    
}

bool Bullet::isBulletInFlight() {
    
    return bulletInFlight;
}


FloatRect Bullet::getPostion(){
    return hyphenBullet.getGlobalBounds();
}

void Bullet::shoot(FloatRect playerPosition) {
    // a new bullet was shot
    bulletInFlight = true;
    
    // set the initial coordinates for the bullet based on the player position
    m_Position.x = playerPosition.left + playerPosition.width;
    m_Position.y = playerPosition.top + 40; // 40 is approximating the ship's nose
}


void Bullet::update(float elapsedTime) {
    
    // is there a bullet in flight?
    if(bulletInFlight == true){

        //have we reached the end of the edge of the window?
        if(m_Position.x < (m_Resolution.x)) {
            m_Position.x += m_Speed * elapsedTime;
            hyphenBullet.setPosition(m_Position);
        }
        else
            bulletInFlight = false;
    }
    
    //return hyphenBullet;
    
}

Text Bullet::getBullet(int dtMilliseconds){
    
    
    return hyphenBullet;
}


