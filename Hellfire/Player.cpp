//
//  Player.cpp
//  Hellfire
//
//  Created by Randy on 3/8/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//
 
#include "Player.hpp"

Player::Player()
{
    m_Speed = START_SPEED;
    //m_Health = START_HEALTH;
    //m_MaxHealth = START_HEALTH;
    
    // Associate a texture with the sprite
    // !!Watch this space!!
    
    playerFrame = 0;
    
    m_Texture.loadFromFile(resourcePath() + "Hellfire-Player-SpriteSheet.png");
    m_Sprite.setTexture(m_Texture);
    
    // Set the origin of the sprite to the centre,
    // for smooth rotation
    m_Sprite.setOrigin(25, 25);
}


FloatRect Player::getPostion(){
    return m_Sprite.getGlobalBounds();
}

//******************************************************
// we need to figure out which frame in the spritesheet
// to return based on how much time has passed
// It may not be time to rotate the ship
// key presses or mousemoves should not interfere with
// ship rotation
Sprite Player::getSprite(int dtMilliseconds){
    
                //    if(clock.getElapsedTime().asMilliseconds() > 90){       // update the player ship frame every "x" milliseconds
                //        sprite.setTextureRect(sf::IntRect(playerFrame*161,0, 161,110));
                //        
                //        if(playerFrame == 7)
                //            playerFrame = 0;
                //        else
                //            playerFrame++;
                //        
                //        clock.restart();
                //}

    if(dtMilliseconds > 10){
     
        m_Sprite.setTextureRect(IntRect(playerFrame*161, 0, 161, 110));
        if(playerFrame == 7)
            playerFrame = 0;
        else
            playerFrame++;

    }else
        m_Sprite.setTextureRect(IntRect(playerFrame*161, 0, 161, 110));
    
    
    return m_Sprite;
}





// keeping things simple for now, no mouse, down & right arrows only
void Player::update(float elapsedTime, Vector2i mousePosition){
    
    if(m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
        m_UpPressed = false;
    }
    
    if(m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
        m_DownPressed = false;
    }

    if(m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
        m_LeftPressed = false;
    }
    
    
    if(m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
        m_RightPressed = false;
    }
    
    
    
    
    
    
    m_Sprite.setPosition(m_Position);
    
    
    
    
}

void Player::moveLeft()
{
    m_LeftPressed = true;
}

void Player::moveRight()
{
    m_RightPressed = true;
}

void Player::moveUp()
{
    m_UpPressed = true;
}

void Player::moveDown()
{
    m_DownPressed = true;
}


















