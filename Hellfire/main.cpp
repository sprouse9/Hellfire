
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

//#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "Player.hpp"
#include "BulletManager.hpp"

using namespace sf;
using namespace std;

int main(int, char const**)
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width * .7;
    resolution.y = VideoMode::getDesktopMode().height * .7;
    
    std::ostringstream s1;
    s1 << resolution.x << " x " << resolution.y;
    
    // Create the main window
    RenderWindow window(sf::VideoMode(resolution.x, resolution.y), s1.str());
    window.setMouseCursorVisible(false);
    
    // Create a SFML View for the main action
    View mainView(FloatRect(0, 0, resolution.x, resolution.y));
    
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    
//    Text txtPlayerCoordinates;
//    Font font;
//    font.loadFromFile(resourcePath() + "sansation.ttf");
//    txtPlayerCoordinates.setCharacterSize(30);
//    txtPlayerCoordinates.setFont(font);
    
    
    Player player1(resolution);
    BulletManager bulletManager(resolution);
    
    Clock clock;
    Time dt;
    
    
    while (window.isOpen())     // Start the game loop
    {
        Event event;            // Process events
        
        while (window.pollEvent(event)){
            if (event.type == Event::Closed)    // Close window: exit
                window.close();
            if (event.type == Event::KeyPressed){
                if(event.key.code == Keyboard::Escape)
                    window.close();
            }
        }

        dt = clock.restart();
        
        if(Keyboard::isKeyPressed( Keyboard::A )){
            
            // the shoot() method should decide whether to add a bullet to the scene and how many
            bulletManager.shoot(player1.getPostion(), dt.asMilliseconds());
            
        
        }
        
        
        // Update the frame
//        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        
        // update the player
        player1.update(dtAsSeconds, Mouse::getPosition(window));
        
        // update the bullet (if any)
        bulletManager.update(dt.asMilliseconds());
        
        window.clear();
        window.setView(mainView);
        
        window.draw(player1.getSprite(dt.asMilliseconds()));
        
        bulletManager.draw(window);
        

        
        
        
        window.display();
    }

    return EXIT_SUCCESS;
}
