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
    hyphenBullet.setCharacterSize(50);
    hyphenBullet.setStyle(Text::Bold);
    hyphenBullet.setFont(sansationFont);
    hyphenBullet.setString( "==" );

    dtSinceLastFrame = 0;
    bulletCount = 0;
    
}

FloatRect BulletManager::getPostion() {
    return hyphenBullet.getGlobalBounds();
}

/*
    The shoot() method is called every time the fire key (A) is pressed.
    We have to ignore calls to shoot() if enough time has not passed yet.
    Keep track of the timing since the previous bullet was shot.
 
*/
void BulletManager::shoot(FloatRect playerPosition, int dtMilliseconds) {

    dtSinceLastBullet += dtMilliseconds;
    
    if(dtSinceLastBullet > 100 || bulletCount == 0) { //BULLET_TIMER){
        // enough time has passed since last bullet was shot
        
        if(bulletCount < maxBullet) {    // are we at Max yet?
            // we need to shoot another bullet
            bullets[bulletCount].position.x = playerPosition.left + 130;
            bullets[bulletCount].position.y = playerPosition.top + 40;
            bullets[bulletCount].bulletInFlight = true;
            bulletCount++;
            dtSinceLastBullet = 0;
            cout << endl << bulletCount;
            
        }
        else {
            //bulletCount = 0;
        }
    
        
    }
    else{
        // not enough time has passed since the last bullet was shot
        return;
        
    }
    
    
    
    /************************************************************************
    
    if( bulletCount == 0 ) {
        // a new bullet was shot
        
        bullets[bulletCount].position.x = playerPosition.left + 130;
        bullets[bulletCount].position.y = playerPosition.top + 40;
        
        clock.restart();       // restart the timer

        bulletCount++;
        indexOfNextAvailableBullet++;
    }
    else{
        // we need to shoot another bullet
        if(bulletCount < maxBullet) {    // are we at Max yet?
            
            // has enough time elapsed since last bullet? We don't want them overlapping!
            if( clock.getElapsedTime().asMilliseconds() > 10 )  // 10 milliseconds must have passed
            {
                bullets[indexOfNextAvailableBullet].position.x = playerPosition.left + 130;
                bullets[indexOfNextAvailableBullet].position.y = playerPosition.top + 40;
                bulletCount++;
                
                
            }
            else {
                cout << "it's not time to add a new bullet yet" << endl;
            }
            
            
            
            
        }
        else{
            // we have the max amount of bullets on the screen (4)
            // we can't add another bullet
            bulletCount = 0;
        }
        
    }
    
    //cout << "dt.ms = " << dt.asMicroseconds() << endl;
     ************************************************************************/

}


// Loop thru each bullet and update it's position
void BulletManager::update(int dtMilliseconds) {
    
    dtSinceLastFrame += dtMilliseconds;
    
    if(bulletCount >= 0) {
        if(dtSinceLastFrame > 30){  //BULLET_TIMER
            
            // it's time to advance all bullets to the right
            for( int i=0 ; i < bulletCount ; i++ ) {
                
                if(bullets[i].bulletInFlight){
                    if(bullets[i].position.x < (m_Resolution.x)) {
                        // advance the bullet
                        bullets[i].position.x += m_Speed;
                    }
                    else {
                        // bullet has reached the end of it's trajectory
                        // and will no longer be displayed
                        bullets[i].bulletInFlight = false;
        
                    }
                }
                
                
                

            }
        
        
        }
        
        
        
        
    }
    
    
    
    /***************************************
    // is there a bullet in flight?
    if(bulletCount > 0){
        int temp = bulletCount;
        dtSinceLastFrame += dtMilliseconds;
        
        if(dtSinceLastFrame > 10){  //BULLET_TIMER
            // it's time to advance all bullets to the right
            for( int i=bulletCount ; i>0 ; i--) {
                if(bullets[i-1].position.x < (m_Resolution.x)) {
                    // advance the bullet
                    bullets[i-1].position.x += m_Speed;
                }
                else {
                    // bullet has reached the end of it's trajectory
                    // and will no longer be displayed
                    temp--;
                }
            }
            bulletCount = temp;
            // we've updated all bullets' positions, restart the frame timer
            dtSinceLastFrame = 0;
        }
    }
     
     ***************************************/
     
}

void BulletManager::draw(RenderWindow &targetWindow) {
    
    std::stringstream bulletNumber;
    
    for( int i=0 ; i<bulletCount ; i++ ) {
        
        if(bullets[i].bulletInFlight) {
        
            hyphenBullet.setPosition(bullets[i].position);
            
            //bulletNumber << i;
            
//            hyphenBullet.setString( bulletNumber.str() );

            targetWindow.draw(hyphenBullet);
        }
        
    }

}






