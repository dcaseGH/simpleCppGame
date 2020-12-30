#ifndef TEAM_H
#define TEAM_H

#include "Player.h"
#include <vector>

class Team
{
    public:
        Team(std::vector<Player*> &p);
        virtual ~Team();
        void print_info();
        void draw_players(sf::RenderWindow &w);
        void move_players();
        void update_player_shape_positions();
        std::vector <Player*> players;

    protected:

    private:
//       std::vector <Player*> players;
};

#endif // TEAM_H
