#ifndef __SANDBOX_GAME_LOCATION_H__
#define __SANDBOX_GAME_LOCATION_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace Hoopoe 
{

enum Location_type 
{
	UNKOWN,
	DUNGEON,
	TOWN,
	CROSSROADS,
	HOUSE
};

struct a_location; /* Available location */

class Location 
{
public:
	Location();
	Location(int index, string location_name, Location_type type);
	Location(int index, string location_name, Location_type type, vector<a_location> &a_locations);

	int get_index();
	string get_location_name();
	Location_type get_type();
	vector<a_location> get_a_locations();

	void set_index(int index);
	void set_location_name(string location_name);
	void set_type(Location_type type);
	void set_a_locations(vector<a_location> &a_locations); // Set vector of available locations
	void set_a_location(Location &location); // this_location = new_location

	void echo_a_locations(); // Displaying available locations
private:
	int index;
	string location_name;
	Location_type type;
	vector<a_location> a_locations;
};

struct a_location /* Available location */
{ 
	a_location();
	a_location(Location *location, int require_steps);

	Location *location; // Location you can get to
	int require_steps; //Required number of steps
};

}

#endif