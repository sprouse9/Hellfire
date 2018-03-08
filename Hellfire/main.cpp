
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

using namespace sf;

int main(int, char const**)
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");   // Create the main window

    sf::Texture texture;    // Load a sprite to display
    if (!texture.loadFromFile(resourcePath() + "Hellfire-Player-SpriteSheet.png")) {
        return EXIT_FAILURE;
    }
    //sf::Sprite sprite(texture);
    short int playerFrame = 0;
    sf::Sprite sprite(texture, sf::IntRect(playerFrame*161,0, 161,110));

    // here is our clock
    Clock clock;

    while (window.isOpen())    // Start the game loop
    {
        sf::Event event;    // Process events
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)    // Close window: exit
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }
        
        if(clock.getElapsedTime().asMilliseconds() > 90){
            // update the player ship frame every "x" milliseconds
            sprite.setTextureRect(sf::IntRect(playerFrame*161,0, 161,110));
            
            if(playerFrame == 7)
                playerFrame = 0;
            else
                playerFrame++;
            
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return EXIT_SUCCESS;
}
