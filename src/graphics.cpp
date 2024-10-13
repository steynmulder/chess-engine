#include "graphics.hpp"

#include<list>
#include<iostream>

#include<SFML/Graphics.hpp>


using namespace std;

void draw(int width) {
    sf::RenderWindow window(sf::VideoMode(width, width), "Chess Engine");
    list<sf::RectangleShape> board_cells = generate_board(width);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // draw board
        for (sf::RectangleShape cell : board_cells) {
            window.draw(cell);
        }
        // draw pieces
        int sprite_size = 45;
        int image_width = 270;
        int image_height = 90;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 6; j++) {

                sf::Texture texture;
                if (!texture.loadFromFile("../assets/textures/pieces.png", sf::IntRect(j * (image_width / 6),
                                                                                        i * (image_height / 2),
                                                                                        sprite_size,
                                                                                        sprite_size)))
                {
                    // TODO error
                }
                sf::Sprite sprite;
                sprite.setTexture(texture);
                sprite.setScale(width / (sprite_size * 8), width / (sprite_size * 8));
                sprite.setPosition(j * (width / 8), i * (width / 8));
                window.draw(sprite);
            }
        }
        
        
        window.display();
    }
}

list<sf::RectangleShape> generate_board(int width) {
    list<sf::RectangleShape> cells; 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::RectangleShape shape(sf::Vector2f(width / 8.0f, width / 8.0f));
            if ((i + j) % 2 == 0) {
                shape.setFillColor(sf::Color{255, 231, 206, 255}); // light
            } else {
                shape.setFillColor(sf::Color{201, 153, 106, 255}); // dark
            }
            shape.setPosition({(float) j * width / 8, (float) i * width / 8});
            
            cells.push_back(shape);
        }
        
    }

    return cells;
}