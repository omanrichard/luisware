
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
//#include <wiringPi.h>

#include <iostream>
#include <fstream>
#include <vector>
#include <string>



using namespace sf;

// Here is a small helper for you! Have a look.
//#include "ResourcePath.hpp"

int i,j;

int main(int, char const**)
{
    
//--------------------- Set up -----------------------------------
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(700, 700), "ECE3220 Final Project");
/*
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Boss Camera", font, 50);
    text.setFillColor(sf::Color::Black);

    // Load a music to play
*    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }
*/
    
    // Load sprites to display
    
    //----------------- Menu ---------------------
    Texture t_settings;
    if (!t_settings.loadFromFile("wrench.png")) {
        return EXIT_FAILURE;
    }
    
    
    Texture t_record;
    if (!t_record.loadFromFile("add-button.png")) {
        return EXIT_FAILURE;
    }
   ;
    
    Texture t_stop;
    if (!t_stop.loadFromFile("close.png")) {
        return EXIT_FAILURE;
    }
    
    
    Texture t_play;
    if (!t_play.loadFromFile("play-button.png")) {
        return EXIT_FAILURE;
    }
    
    
    Texture t_trash;
    if (!t_trash.loadFromFile("delete.png")) {
        return EXIT_FAILURE;
    }
  
    
    Texture t_save;
    if (!t_trash.loadFromFile("download.png")) {
        return EXIT_FAILURE;
    }
    
    sf::Font font;
    if (!font.loadFromFile("sansation.ttf")) {
        return EXIT_FAILURE;
    }
   
    
    //----------------- Camera Grid ----------------
    int gridx, gridy;
    RectangleShape grid[8][8];
    
    for( i=0 ; i < 8 ; i++ ){
        for( j=0 ; j<8 ; j++ ){
            gridx = (164+i*59);
            gridy = (88+j*59);
            RectangleShape newPix(sf::Vector2f(58, 58));
            newPix.setPosition( gridx, gridy );
            newPix.setFillColor(sf::Color::White);
            grid[i][j] = newPix;
        }
    }
    
    
  
    
    sf::RectangleShape line( Vector2f( 1, 700) );
    line.setFillColor( Color::Black );
    line.setPosition(94, 0);
    
    RectangleShape line2( Vector2f( 625, 1));
    line2.setFillColor( Color::Black );
    line2.setPosition(94, 606);
    
 /*/----------------Draw Toolbar----------------/*/
   
    sf::RectangleShape toolbarFrame(sf::Vector2f( 94, 700 ));
    toolbarFrame.setFillColor(sf::Color(132, 101, 142));
    toolbarFrame.setPosition(0, 0);
    
    sf::RectangleShape toolbarHeader(sf::Vector2f( 10, 700 ));
    toolbarHeader.setFillColor(sf::Color(113, 85, 122));
    toolbarHeader.setPosition(84, 0);
    
    
    Sprite settings( t_settings );
    settings.setPosition( 15, 109 );
    settings.scale(0.50, 0.50);
    
    Sprite record( t_record );
    record.setPosition( 15, 188+15 );
    record.scale(0.50, 0.50);
    
    Sprite play( t_play );
    play.setPosition( 15, 346+45 );
    play.scale(0.50, 0.50);
    
    Sprite stop( t_stop );
    stop.setPosition( 15, 267+30);
    stop.scale(0.50, 0.50);
    
    Sprite save( t_save );
    save.setPosition( 15, 504+75 );
    save.scale(0.50, 0.50);
    
    Sprite trash( t_trash );
    trash.setPosition( 15, 425+60 );
    trash.scale(0.50, 0.50);
    
 /*/-----------------Draw Terminal Window-------------------/*/
    
    sf::RectangleShape terminal(sf::Vector2f( 625, 94 ));
    terminal.setFillColor(sf::Color::Black);
    terminal.setPosition(94, 606);
    
    sf::RectangleShape terminalHeader(sf::Vector2f( 625, 10 ));
    terminalHeader.setFillColor(sf::Color(255,94,20));
    terminalHeader.setPosition(94, 596);
    
    
    sf::Text terminalText1("root@thermalCamera: Terminal text placeholder line 1", font, 12);
    terminalText1.setFillColor(sf::Color(0,255,0));
    terminalText1.setPosition( 100 , 610);
    
    sf::Text terminalText2("root@thermalCamera: Terminal text placeholder line 2", font, 12);
    terminalText2.setFillColor(sf::Color(0,255,0));
    terminalText2.setPosition( 100 , 622);
    
    sf::Text terminalText3("root@thermalCamera: Terminal text placeholder line 3", font, 12);
    terminalText3.setFillColor(sf::Color(0,255,0));
    terminalText3.setPosition( 100 , 634);
    
    sf::Text terminalText4("root@thermalCamera: Terminal text placeholder line 4", font, 12);
    terminalText4.setFillColor(sf::Color(0,255,0));
    terminalText4.setPosition( 100 , 646);
    
    sf::Text terminalText5("root@thermalCamera: Terminal text placeholder line 5", font, 12);
    terminalText5.setFillColor(sf::Color(0,255,0));
    terminalText5.setPosition( 100 , 658);
    
    sf::Text terminalText6("root@thermalCamera: Terminal text placeholder line 6", font, 12);
    terminalText6.setFillColor(sf::Color(0,255,0));
    terminalText6.setPosition( 100 , 670);
    
    sf::Text terminalText7("root@thermalCamera: Terminal text placeholder line 7", font, 12);
    terminalText7.setFillColor(sf::Color(0,255,0));
    terminalText7.setPosition( 100 , 682);
    
    
    /*/---------------Background---------------/*/
    
    
    sf::RectangleShape background(sf::Vector2f( 700, 700 ));
    background.setFillColor(sf::Color(130, 117, 135));
    background.setPosition(0, 0);
    
    
    sf::Text text("Thermal Camera", font, 50);
    text.setFillColor(sf::Color::Black);
    text.setPosition( 109 , 10);
    
    sf::Text r_text("Recording", font, 30);
    r_text.setFillColor(sf::Color::Black);
    r_text.setPosition( 550 , 10);

//---------------------- Draw -------------------------
    // Play the music
    //music.play();

    
    // Start the game loop
    while (window.isOpen())
    {
        
        window.draw(line);
        
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        
        //Background
        window.draw(background);

        
        // Toolbar
        window.draw(toolbarFrame);
        window.draw(toolbarHeader);
        window.draw(settings);
        window.draw(record);
        window.draw(stop);
        window.draw(play);
        window.draw(trash);
        window.draw(save);
        
        //Draw output Grid
        for( i=0 ; i < 8 ; i++ ){
            for( j=0 ; j<8 ; j++ ){
                window.draw( grid[i][j] );
            }
        }
        
        // Draw the placeholder text
        window.draw(text);
        window.draw(r_text);
        
        
        //Draw the Terminal window
        window.draw(terminalHeader);
        window.draw(terminal);
        window.draw(terminalText1);
        window.draw(terminalText2);
        window.draw(terminalText3);
        window.draw(terminalText4);
        window.draw(terminalText5);
        window.draw(terminalText6);
        window.draw(terminalText7);
        
        
        
        //window.draw(line);
        //window.draw(line2);
        
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
