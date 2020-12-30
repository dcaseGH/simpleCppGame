#ifndef GAME_H
#define GAME_H

#include <string>
#include "Team.h"

class Game
{
    public:
        Game();
        Game(std::vector<Team*> &t);
        virtual ~Game();

        std::vector<Team*> teams;
        std::map<std::string, float> constant_values;

        void playTurn();
        void updateMechanics(Team &t1, Team &t2);
        void updateGraphics();

    protected:

    private:
};

#endif // GAME_H
