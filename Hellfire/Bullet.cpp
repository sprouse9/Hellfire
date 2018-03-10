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
    hyphenBullet.setCharacterSize(40);
    hyphenBullet.setFont(sansationFont);
    hyphenBullet.setString( "-" );

    dtSinceLastFrame = 0;
    
}

FloatRect Bullet::getPostion(){
    return hyphenBullet.getGlobalBounds();
}

void Bullet::shoot(FloatRect position) {
    // a new bullet was shot
    bulletInFlight = true;
    
}


void Bullet::update(float elapsedTime) {
    
    // is there a bullet in flight?
    if(bulletInFlight == true){

        m_Position.x += m_Speed * elapsedTime;
        
        hyphenBullet.setPosition(m_Position);
                                 
    }
    
    //return hyphenBullet;
    
}


void Player::moveRight()
{
    if(m_Position.x < (m_Resolution.x - m_ShipWidth))
        m_RightPressed = true;
    
    //std::cout << "width = " << m_ShipWidth << std::endl;
}
