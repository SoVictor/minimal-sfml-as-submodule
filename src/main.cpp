#include <SFML/Graphics.hpp>
#include "moving_box.h"

namespace {

const sf::VideoMode kVideoMode(640, 480);
const unsigned int kFrameLimit = 60;

const sf::Vector2f kInitialBoxPosition(200.0F, 200.0F);

}  // namespace

int main() {
    sf::RenderWindow window(kVideoMode, "demo");
    window.setFramerateLimit(kFrameLimit);

    demo::MovingBox box(kInitialBoxPosition);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }

                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;

                    case sf::Keyboard::Up:
                        box.MoveUp();
                        break;
                    case sf::Keyboard::Down:
                        box.MoveDown();
                        break;
                    case sf::Keyboard::Left:
                        box.MoveLeft();
                        break;
                    case sf::Keyboard::Right:
                        box.MoveRight();
                        break;

                    default:
                        break;
                }
            }
        }

        window.clear();
        box.Draw(&window);
        window.display();
    }

    return 0;
}
