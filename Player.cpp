#include "Player.h"

#include <SFML/Graphics.hpp>
#include<array>
#include <cmath>

#include <iostream>

Player::Player()
{
//   this->position = {0,0};
   this->position = {0.f,0.f};
}

//Player::Player(std::array<int, 2> p)
Player::Player(std::array<float, 2> p)
{
   this->position = p;
//   this->shape;
}


Player::~Player()
{
    //dtor
}

void Player::move(std::array<float, 2> x)
{
   this->position[0] += x[0];
   this->position[1] += x[1];
}

void Player::move_towards_target(std::array<float, 2> x)
{
   std::array<float, 2> target_vector = {x[0] - this->position[0], x[1] - this->position[1]};
   float l2_norm_target = sqrt(pow(target_vector[0], 2) + pow(target_vector[1], 2));
   if (l2_norm_target > 0){
      target_vector[0] *= (this->speed / l2_norm_target);
      target_vector[1] *= (this->speed / l2_norm_target);
   }else{
      target_vector = {0,0};
   }
//   std::cout << this->position[0] << " " << this->position[1] << " "
//             << x[0] << " " << x[1] << " " << this->speed << " " << l2_norm_target << " " << target_vector[0] << " " << target_vector[1] <<std::endl;
   this->move(target_vector);
//   this->position[0] += target_vector[0];
//   this->position[1] += target_vector[1];
//   std::cout << this->position[0] << " " << this->position[1] << " " << this->speed << " " << l2_norm_target << " " << target_vector[0] << " " << target_vector[1] <<std::endl;
}

void Player::update_shape()
{
//   this->shape->setPosition({(float)this->position[0],(float)this->position[1]});
   this->shape->setPosition({this->position[0],this->position[1]});
}

void Player::display_shape(sf::RenderWindow &w)
{
   w.draw(*(this->shape));

}
