#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include<array>

class Player
{
    public:
        Player();
//        Player(std::array<int, 2>);
        Player(std::array<float, 2>);
        virtual ~Player();
//        set_position(int b[2] );
//        std::array<int,2> position;
        std::array<float,2> position;
        float speed;
        float strength;
        float energy;
        sf::CircleShape *shape;
//        void set_shape(sf::CircleShape *s);
//        void move(std::array<int, 2> x);
        void move(std::array<float, 2> x);
        void move_towards_target(std::array<float, 2> x);
        void update_shape();
        void display_shape(sf::RenderWindow &w);

    protected:

    private:
};

#endif // PLAYER_H
