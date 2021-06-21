#include "../include/Player.h"

namespace Hoopoe {

    Player::Player() : Creature() { this->location = nullptr; }
    Player::Player(
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
    ) : Creature(id, name, intelligence, strenght, stamina, agility, spirit, accuracy, armor, mastery) {
        this->location = location;
    }

    Location Player::get_location() { return *location; }
    void Player::set_location(Location &location) { this->location = &location; }

}
