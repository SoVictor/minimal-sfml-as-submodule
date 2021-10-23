#include "moving_box.h"

namespace demo {

namespace {

const sf::Vector2f kBoxSize(20, 20);
const float kStep = 1.0F;

}  // namespace

MovingBox::MovingBox(sf::Vector2f position) : position_(std::move(position)) {}

void MovingBox::MoveUp() { position_.y -= kStep; }
void MovingBox::MoveDown() { position_.y += kStep; }
void MovingBox::MoveLeft() { position_.x -= kStep; }
void MovingBox::MoveRight() { position_.x += kStep; }

void MovingBox::Draw(sf::RenderWindow* window) const {
    sf::RectangleShape shape(kBoxSize);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(position_);
    window->draw(shape);
}

}  // namespace demo
