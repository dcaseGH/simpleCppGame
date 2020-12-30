#include "Game.h"
#include "Team.h"

#include "coreFunctions.h"

Game::Game()
{
    //ctor
}

Game::Game(std::vector<Team*> &t)
{
   this->teams = t;
}

Game::~Game()
{
    //dtor
}

void Game::updateGraphics()
{
   // Put shapes where players are
   for (auto it1 = this->teams.begin(); it1 != this->teams.end(); ++it1)
   {
       (*it1)->update_player_shape_positions();
   }
}

void Game::playTurn()
{
//   this->window.clear();

   this->updateMechanics((*this->teams[0]), (*this->teams[1]));
   this->updateMechanics((*this->teams[1]), (*this->teams[0]));

   this->updateGraphics();
//   this->window.display();
}

void Game::updateMechanics(Team &team1, Team &team2)
{
//    this->teams[0].evaluate_turn(this->teams[1]);
//    float critical_range = 15.;
    for (auto it1 = team1.players.begin(); it1 != team1.players.end(); ++it1)
    {
        float nearest_distance = std::numeric_limits<float>::infinity();
        Player *enemy;

        for (auto it2 = team2.players.begin(); it2 != team2.players.end(); ++it2)
        {
            float this_distance = inter_player_distance((*it1), (*it2));
            if (this_distance < nearest_distance){
               nearest_distance = this_distance;
               enemy = (*it2);
            }

        }
        if (nearest_distance < this->constant_values["critical_range"]){
           fight((*it1), enemy);
        }
        else{
          (*it1)->move_towards_target(enemy->position);
        }

        //kill players inside fight???
        if ((*it1)->energy <= 0){
           team1.players.erase(std::remove(team1.players.begin(), team1.players.end(), (*it1)), team1.players.end());
        }
        if (enemy->energy <= 0){
           team2.players.erase(std::remove(team2.players.begin(), team2.players.end(), enemy), team2.players.end());
        }

    }
}
