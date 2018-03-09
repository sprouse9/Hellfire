/***********************************************************/
//
//  Player.h
//  Hellfire
//
//  Created by Randy on 3/8/18.
//  Copyright © 2018 randy sprouse. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp
#endif /* Player_hpp */

#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

using namespace sf;

class Player
{
    
private:
    const float START_SPEED = 100;
    
    // the ship needs to keep track of the timer for rotation animation
    const int SHIP_ROTATION_TIMER = 90; // in Milliseconds
    
    Vector2f m_Position;
    Sprite   m_Sprite;
    Texture  m_Texture;
    
    Vector2f m_Resolution;
    
    // Which direction is the player moving in?
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    
    bool m_Shield;  // is the ship shielded with force field?
    
    float m_Speed;  // Speed in pixels per second
    
    short int playerFrame;
    
    int dtSinceLastFrame;   // is it time to change the ship frame for rotaion animation?
    
public:
    
    Player();
    
    // Where is the player
    FloatRect getPostion();
    
    // How much health has the player currently got?
    int getHealth();
    
    // The next four functions move the player
    void moveLeft();
    
    void moveRight();
    
    void moveUp();
    
    void moveDown();
    
    // We will call this function once every frame
    void update(float elapsedTime, Vector2i mousePosition);
    
    // Send a copy of the sprite to main
    Sprite getSprite(int dtMilliseconds);
    
};


