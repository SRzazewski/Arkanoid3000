#include "block.hpp"

block::block(sf::RenderWindow *const app_window, sf::Vector2f start_position):
        window(app_window)
{
    float size_x = 90.f;
    float size_y = 20.f;
    broken = false;
    block_obj = sf::RectangleShape();
    block_obj.setSize(sf::Vector2f(size_x, size_y));
    block_obj.setOrigin(size_x/2.0f, size_y/2.0f);
    block_obj.setFillColor(sf::Color(0, 0, 255));
    block_obj.setOutlineThickness(5.0f);
    block_obj.setOutlineColor(sf::Color(100, 150, 255));
    block_obj.setPosition(start_position);
}

void block::set_position(sf::Vector2f position) 
{
    block_obj.setPosition(position);
}

sf::Vector2f block::get_position() const
{
    return block_obj.getPosition();
}

sf::RectangleShape block::get_block()
{
    return block_obj;
}

void block::break_obj()
{
    broken = true;
}

bool block::is_broken()
{
    return broken;
}

void block::display()
{
    if (!broken)
    {
        window->draw(block_obj);
    }
}
