//
//  Player.cpp
//  Hellfire
//
//  Created by Randy on 3/8/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//
 
#include "Player.hpp"
#include <iostream>

Player::Player(Vector2f resolution)
{
    m_Speed = START_SPEED;
    //m_Health = START_HEALTH;
    //m_MaxHealth = START_HEALTH;
    
    
    
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
    
    
    
    // Associate a texture with the sprite
    // !!Watch this space!!
    
    playerFrame = 0;
    dtSinceLastFrame = 0;
    
    m_Texture.loadFromFile(resourcePath() + "Hellfire-Player-SpriteSheet.png");
    m_Sprite.setTexture(m_Texture);
    
    m_ShipWidth = 1288/8;   // 8 frames in the spritesheet
    m_ShipHeight = 110;
    
    // Set the origin of the sprite to the centre, for smooth rotation
    //m_Sprite.setOrigin(25, 25);
}


FloatRect Player::getPostion(){
    return m_Sprite.getGlobalBounds();
}

//******************************************************
// We need to figure out which frame in the spritesheet
// to return based on how much time (SHIP_ROTATION_TIMER) has passed
// It may not be time to rotate the ship
// Key presses or mousemoves should not interfere with ship rotation
Sprite Player::getSprite(int dtMilliseconds){
    
    dtSinceLastFrame += dtMilliseconds;
    
    if(dtSinceLastFrame > SHIP_ROTATION_TIMER){
     
        m_Sprite.setTextureRect(IntRect(playerFrame*161, 0, 161, 110));
        if(playerFrame == 7)
            playerFrame = 0;
        else
            playerFrame++;
        
        dtSinceLastFrame = 0;
    }

    return m_Sprite;
}

// keeping things simple for now, no mouse
void Player::update(float elapsedTime, Vector2i mousePosition){
    
    //bool keyPressed = false;
    
    if(m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
        m_UpPressed = false;
        //keyPressed = true;
    }
    
    if(m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
        m_DownPressed = false;
        //keyPressed = true;
    }

    if(m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
        m_LeftPressed = false;
        //keyPressed = true;
    }
    
    if(m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
        m_RightPressed = false;
        //keyPressed = true;
    }
    
//    if(keyPressed == false) {
//        m_Position.x = mousePosition.x;
//        m_Position.y = mousePosition.y;
//    }
    
    m_Sprite.setPosition(m_Position);
}

void Player::moveLeft()
{
    if(m_Position.x > 0)
        m_LeftPressed = true;
}

void Player::moveRight()
{
    if(m_Position.x < (m_Resolution.x - m_ShipWidth))
        m_RightPressed = true;
    
    //std::cout << "width = " << m_ShipWidth << std::endl;
}

void Player::moveUp()
{
    if(m_Position.y > 0)
        m_UpPressed = true;
}

void Player::moveDown()
{
    if(m_Position.y < (m_Resolution.y - m_ShipHeight))
        m_DownPressed = true;
}
