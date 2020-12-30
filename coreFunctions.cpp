#include "coreFunctions.h"

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
