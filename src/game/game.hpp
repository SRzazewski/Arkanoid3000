#ifndef GAME
#define GAME

#include "paddle.hpp"
#include "ball.hpp"
#include "block.hpp"
#include "powerup.hpp"
#include <SFML/Graphics.hpp>

struct game_area
{
    float x_start;
    float x_stop;
    float y_start;
    float y_stop;
};

const sf::Vector2f ball_start_position_shift = sf::Vector2f(-10.0f, -40.f);
class game
{
public:
    game();
    game(game_area area);
    void init(sf::Font &font);
    void serve_events(const sf::Event event, sf::RenderWindow &window, sf::Clock &clock_obj);
    void update(sf::Clock &clock_obj);
    void draw(sf::RenderWindow &window);

private:
    game_area block_breaker_area;
    sf::RectangleShape game_area_field;
    game_states game_state_previus;
    game_states game_state;
    game_states game_state_requested;
    paddle paddle_obj;
    std::vector<ball> balls;
    std::vector<block> blocks;
    std::vector<powerup> powerups;
    sf::Text text_obj;
    sf::Font font_obj;
    sf::Time previus_time;
    sf::Time time_delta;
    int blocks_number;
    int balls_number;
    std::vector<int> powerup_from_blocks;

    void serve_events_level_init(const sf::Event event, sf::RenderWindow &window, sf::Clock &clock_obj);
    void serve_events_level(const sf::Event event, sf::RenderWindow &window, sf::Clock &clock_obj);
    void serve_events_level_won(const sf::Event event, sf::RenderWindow &window, sf::Clock &clock_obj);
    void serve_events_level_lost(const sf::Event event, sf::RenderWindow &window, sf::Clock &clock_obj);

    void game_state_update();
    void obj_reset();
    void rand_powerups(int powerup_number);
    void game_state_level_1_prepare();
    void game_state_level_2_prepare();
    void game_state_level_3_prepare();
    void game_state_level_4_prepare();
    void game_state_level_5_prepare();
    
    void move_paddle();
    void move_ball(ball &ball_obj);
    void move_powerup(powerup &powerup_obj);
    void ball_meets_edge(ball &ball_obj, sf::Vector2f ball_position);
    void powerup_meets_paddle(powerup &powerup_obj);
    void powerup_meets_edge(powerup &powerup_obj);
    void block_broke(block &block_obj);
    void ball_meets_block(ball &ball_obj, block &block_obj, sf::Vector2f ball_position);
    void ball_meets_paddle(ball &ball_obj, sf::Vector2f ball_position);
    sf::Vector2f calculate_new_vector(sf::Vector2f vector_current, float fi);
};

#endif