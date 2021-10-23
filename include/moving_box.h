#include <SFML/Graphics.hpp>

namespace demo {

class MovingBox {
public:
    explicit MovingBox(sf::Vector2f position);

    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

    void Draw(sf::RenderWindow* window) const;

private:
    sf::Vector2f position_;
};  // class MovingBox

}  // namespace demo
