
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
#include <iostream>
#include <sstream>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"

#include "Player.hpp"

using namespace sf;
using namespace std;

int main(int, char const**)
{
    RenderWindow window(sf::VideoMode(1600, 800), "SFML window");  // Create the main window
    
    // Create a an SFML View for the main action
    View mainView(FloatRect(0, 0, 1600, 800));
    
    Vector2f mouseWorldPosition;
    Vector2i mouseScreenPosition;
    
    Text txtPlayerCoordinates;
    Font font;
    font.loadFromFile(resourcePath() + "sansation.ttf");
    txtPlayerCoordinates.setCharacterSize(30);
    txtPlayerCoordinates.setFont(font);
    
    
    
    
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
            if (event.type == Event::MouseMoved){
                mouseScreenPosition = Mouse::getPosition(window);
                mouseWorldPosition = window.mapPixelToCoords(mouseScreenPosition, mainView);
                
                cout << "(" << mouseScreenPosition.x << ", "
                     << mouseScreenPosition.y << ")";
                
                cout << "   World = (" << mouseWorldPosition.x << ", "
                     << mouseWorldPosition.y << ")" << endl;
                
            }
            
            
        }
        
        /****************************************/
        // Remove or comment out this code block later
        
        
        
        
        /****************************************/
        
        
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
        //int   dtAsMilliseconds = dt.asMilliseconds();
        
        
        // where is the mouse pointer?
 //       mouseScreenPosition = Mouse::getPosition();
        
        // update the player
        player1.update(dtAsSeconds, Mouse::getPosition(window));
        
        window.clear();
        window.setView(mainView);
        
        window.draw(player1.getSprite(dt.asMilliseconds()));
        window.draw(txtPlayerCoordinates);
        
        // display the player's coordinates just below the ship
        FloatRect playerPosition = player1.getPostion();
        
        std::ostringstream s;
        s << "(" << playerPosition.left << ", " << playerPosition.top << ")";
        
        txtPlayerCoordinates.setString( s.str() );
        txtPlayerCoordinates.setPosition(playerPosition.left+110,
                                         playerPosition.top+70);
        
        window.display();
    }

    return EXIT_SUCCESS;
}
