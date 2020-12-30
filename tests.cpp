#define BOOST_TEST_MODULE My Test
#include <boost/test/included/unit_test.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
//#include <vector>
#include "Game.h"
#include "Team.h"
#include "Player.h"
#include "coreFunctions.h"

BOOST_AUTO_TEST_CASE(first_test)
{
  int i = 1;
  BOOST_TEST(i);
}

BOOST_AUTO_TEST_CASE(test_player_constructor)
{
   Player p1;
   p1.energy = 10.f;
   BOOST_ASSERT(p1.energy == 10.f);
}

BOOST_AUTO_TEST_CASE(test_core_functions)
{
  Player *p1 = new Player({-10.f, -10.f});
  Player *p2 = new Player({10.f, 20.f});

  BOOST_TEST(inter_player_distance(p1, p2) == sqrt(pow(20.f, 2) + pow(30.f, 2)),
             boost::test_tools::tolerance(1.e-5) );

  p1->energy   = 3.f;
  p2->energy   = 2.f;
  p1->strength = 3.f;
  p2->strength = 4.f;

}

BOOST_AUTO_TEST_CASE(game_class_tests)
{

  Player *p1 = new Player({-10.f, -10.f});
  p1->speed = 10.f;
  p1->strength = 10.f;
  p1->energy = 3.f;
  sf::CircleShape *shp = new sf::CircleShape(5.f);
  shp->setFillColor(sf::Color::Red);
  p1->shape = shp;

  std::vector<Player*> players1;
  players1.push_back(p1);

  // Why must name be new??? previously could be within loop????
  Player *p2 = new Player({10.f, 20.f});
  p2->speed = 10.f;
  p2->strength = 10.f;
  p2->energy = 3.f;
  sf::CircleShape *shp2 = new sf::CircleShape(5.f);
  shp2->setFillColor(sf::Color::Green);
  p2->shape = shp2;

  std::vector<Player*> players2;
  players2.push_back(p2);

  Team team1(players1);
  Team team2(players2);

  std::vector<Team*> teams;
  teams.push_back(&team1);
  teams.push_back(&team2);
  Game game(teams);

  game.constant_values["critical_range"] = 15.0;
  BOOST_TEST(game.constant_values["critical_range"] == 15.0);
  BOOST_TEST(teams.size() == 2);
  BOOST_TEST( inter_player_distance(teams[0]->players[0],
                                    teams[1]->players[0])  == sqrt(pow(20.f, 2) + pow(30.f, 2)),
             boost::test_tools::tolerance(1.e-5) );

  game.playTurn();

  BOOST_TEST( inter_player_distance(p1,
                                    p2)  == sqrt(pow(20.f, 2) + pow(30.f, 2))
             - (p1->speed + p2->speed),
             boost::test_tools::tolerance(1.e-5) );
  BOOST_TEST( inter_player_distance(teams[0]->players[0],
                                    teams[1]->players[0])  == sqrt(pow(20.f, 2) + pow(30.f, 2))
             - (p1->speed + p2->speed),
             boost::test_tools::tolerance(1.e-5) );

}
