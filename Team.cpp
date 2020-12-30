#include "Team.h"
#include <iostream>

Team::Team(std::vector<Player*> &myplayers)
{
   this->players = myplayers;
}

Team::~Team()
{
    //dtor
}

void Team::print_info()
{
   std::cout << "n players " << this->players.size() << std::endl;

   for (auto it = this->players.begin(); it != this->players.end(); ++it)
      {
      std::cout << (*it)->position[0] << " " << (*it)->position[1] << std::endl;
      std::cout << (*it) << std::endl;
      std::cout << (*it)->shape << std::endl;

      }
}

void Team::update_player_shape_positions()
{
  // Draw them on the window
  for (auto it = this->players.begin(); it != this->players.end(); ++it)
     (*it)->update_shape();
}

void Team::move_players()
{
//   std::array<int, 2> translation;
   std::array<float, 2> translation;
   for (auto it = this->players.begin(); it != this->players.end(); ++it)
      {
//      translation = {(*it)->speed, 0};
      translation = {3.1,0.1};
      (*it)->move(translation);
//       std::cout<<(*it)->position[0]<<" "<<(*it)->position[1]<<std::endl;
      }
}

void Team::draw_players(sf::RenderWindow &w)
{
  // Draw them on the window - understand syntax one day....??
   for (auto it = this->players.begin(); it != this->players.end(); ++it)
      (*it)->display_shape(w);
}

