
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

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "Player.hpp"

using namespace sf;

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");   // Create the main window
    
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    
    Player player1;
    
    Clock clock;

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
        
        // WASD - Handle controls while playing
        if(Keyboard::isKeyPressed( Keyboard::Up )){
            player1.moveUp();
        }
        if(Keyboard::isKeyPressed( Keyboard::Down )){
            player1.moveDown();
        }
        if(Keyboard::isKeyPressed( Keyboard::Left )){
            player1.moveLeft();
        }
        if(Keyboard::isKeyPressed( Keyboard::Right )){
            player1.moveRight();
        }        
        
        // Update the frame
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        int   dtAsMilliseconds = dt.asMilliseconds();
        
        
        // where is the mouse pointer?
 //       mouseScreenPosition = Mouse::getPosition();
        
        // update the player
        player1.update(dtAsSeconds, Mouse::getPosition());
        
        
        window.clear();
        window.draw(player1.getSprite(dtAsMilliseconds));
        window.display();
    }

    return EXIT_SUCCESS;
}
