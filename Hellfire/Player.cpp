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
    m_Sprite = Sprite(TextureHolder::GetTexture("graphics/player.png"));
    
    // Set the origin of the sprite to the centre,
    // for smooth rotation
    m_Sprite.setOrigin(25, 25);
}
