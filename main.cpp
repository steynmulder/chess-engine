#include<iostream>
#include<list>

#include<SFML/Graphics.hpp>


using namespace std;

void draw(int width) {
    sf::RenderWindow window(sf::VideoMode(width, width), "SFML Window");
    list<sf::RectangleShape> cells; 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            sf::RectangleShape shape(sf::Vector2f(width / 8.0f, width / 8.0f));
            if ((i + j) % 2 == 0) {
                shape.setFillColor(sf::Color{255, 231, 206, 255});
            } else {
                shape.setFillColor(sf::Color{201, 153, 106, 255});
            }
            shape.setPosition({(float) j * width / 8, (float) i * width / 8});
            
            cells.push_back(shape);
        }
        
    }
    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (sf::RectangleShape shape : cells) {
            window.draw(shape);
        }
        
        window.display();
    }
}

int main(int argc, char* argv[]) {
    draw(800);

    return 0;
}