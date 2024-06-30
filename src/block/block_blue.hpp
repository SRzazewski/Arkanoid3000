#ifndef BLOCK_BLUE_HPP
#define BLOCK_BLUE_HPP

#include "block.hpp"
#include <SFML/Graphics.hpp>

class block_blue : public block
{
public:
    block_blue(sf::Vector2f start_position);
    void set_position(sf::Vector2f position) override;
    sf::Vector2f get_position() const override;
    sf::RectangleShape get_block() override;
    int break_obj() override;
    bool is_broken() override;
    void draw(sf::RenderWindow &window) override;

private:
    sf::RectangleShape block_obj;
    bool broken;
    int point_for_breaking;
};

#endif