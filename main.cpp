#include <SFML/Graphics.hpp>
#include "Team.h"
#include "Player.h"
#include <string>
#include <iostream>
#include <array>
#include <vector>
#include <unistd.h>
#include <cmath>
#include "coreFunctions.h"

void write_smack_talk()
{
  std::cout << "[Comrade Geakeski] I am Comrade Geakeski and I love communism" << std::endl;
  std::cout << "[General Sir Tomoto] I am General Sir Tomoto and I think you suck" << std::endl;
  std::cout << "[Comrade Geakeski] Well then I will mass produce red blobs and make them kill you" << std::endl;
  std::cout << "[General Sir Tomoto] My samurai honour prevents me from killing you so I will unleash my army of school girls" << std::endl;
  std::cout << "[General Sir Tomoto] Normally they look like younger Barbara Windsors but for this fight they shall take their green circle form" << std::endl;
  std::cout << "[Narrator] FIGHT!" << std::endl;
}

//void draw_stuff()
void draw_stuff(sf::RenderWindow &w, sf::CircleShape &s)
{
   w.clear();
   w.draw(s);
   w.display();
//   std::cout << "Drawing stuff " << std::endl;
}
/*
float inter_player_distance(Player *p1, Player *p2)
{
   // L2 norm 2D distances
   return sqrt(pow(p1->position[0] - p2->position[0], 2)
             + pow(p1->position[1] - p2->position[1], 2));

}

void fight(Player *p1, Player *p2)
{
   // Fight
   int accuracy = 100000000;
   float nran = (rand()%accuracy)/(float)accuracy;
   float cutoff = p1->strength / (p1->strength + p2->strength);
   if (nran < cutoff){
     p1->energy -= 1.f;
   }
   else{
     p2->energy -= 1.f;
   }
}
*/
void play_turn(Team &team1, Team &team2)
{

    float critical_range = 15.;
    for (auto it1 = team1.players.begin(); it1 != team1.players.end(); ++it1)
    {
        float nearest_distance = std::numeric_limits<float>::infinity();
        Player *enemy;

        for (auto it2 = team2.players.begin(); it2 != team2.players.end(); ++it2)
        {
            float this_distance = inter_player_distance((*it1), (*it2));
            if (this_distance < nearest_distance){
               nearest_distance = this_distance;
//               std::cout<< it2 << std::endl;
               enemy = (*it2);
            }

        }
 //       std::cout << nearest_distance << std::endl;
        if (nearest_distance < critical_range){
           fight((*it1), enemy);
        }
        else{
          (*it1)->move_towards_target(enemy->position);
        }
//        std::cout << nearest_distance << std::endl;
        //kill players inside fight???
        if ((*it1)->energy <= 0){
           team1.players.erase(std::remove(team1.players.begin(), team1.players.end(), (*it1)), team1.players.end());
        }
        if (enemy->energy <= 0){
           team2.players.erase(std::remove(team2.players.begin(), team2.players.end(), enemy), team2.players.end());
        }

    }

}


int main()
{

    sf::RenderWindow window(sf::VideoMode(1500, 1500), "Red Alert 4");

    // Hack make Red team
    std::vector<Player*> red_players;
    for (int i=0; i<30 ; i++)
    {
       Player *pptr = new Player({10.f, 10.f + (float)i * 30.f});
       sf::CircleShape *shp = new sf::CircleShape(15.f);
       shp->setFillColor(sf::Color::Red);
       pptr->shape = shp;
       pptr->speed = 10.f;
       pptr->strength = 10.f;
       pptr->energy = 3.f;
       red_players.push_back(pptr);
    }
    Team red_team(red_players);
//    red_team.print_info();
//    std::cout<< inter_player_distance(red_players[0], red_players[1]) << std::endl;
//    red_players[0]->move_towards_target(red_players[1]->position);
//    return 0;

    // Hack make green team
    std::vector<Player*> green_players;
    for (int i=0; i<6 ; i++)
    {
       Player *pptr = new Player({1200.f, 110.f + (float)i * 30.f});
       sf::CircleShape *shp = new sf::CircleShape(5.f);
       shp->setFillColor(sf::Color::Green);
       pptr->shape = shp;
       pptr->speed = 15.f;
       pptr->strength = 15.f;
       pptr->energy = 20.f;
       green_players.push_back(pptr);
    }
    Team green_team(green_players);

//    void write_smack_talk();
  std::cout << "[Comrade Geakeski] I am Comrade Geakeski and I love communism" << std::endl;
  std::cout << "[General Sir Tomoto] I am General Sir Tomoto and I think you suck" << std::endl;
  std::cout << "[Comrade Geakeski] Well then I will mass produce red blobs and make them kill you" << std::endl;
  std::cout << "[General Sir Tomoto] My samurai honour prevents me from killing you so I will unleash my army of school girls" << std::endl;
  std::cout << "[General Sir Tomoto] Normally they look like younger Barbara Windsors but for this fight they shall take their green circle form" << std::endl;
  std::cout << "[Background drunk] FIGHT!" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        play_turn(red_team, green_team);
        play_turn(green_team, red_team);
        red_team.update_player_shape_positions();
        red_team.draw_players(window);
        green_team.update_player_shape_positions();
        green_team.draw_players(window);
        window.display();
        usleep(100000);
    }

    return 0;
}
