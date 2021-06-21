#ifndef __SANDBOX_GAME_PLAYER_H__
#define __SANDBOX_GAME_PLAYER_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../include/Creature.h"
#include "../include/Location.h"

namespace Hoopoe 
{

class Player : public Creature 
{
public:
    Player();
    Player(
        int id,
        string name,
        double intelligence,
        double strenght,
        double stamina,
        double agility,
        double spirit,
        double accuracy,
        double armor,
        double mastery,
        Location *location
    );

    Location get_location();

    void set_location(Location &location);
private:
    Location *location;
};

}

#endif
