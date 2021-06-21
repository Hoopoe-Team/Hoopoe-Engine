#ifndef __SANDBOX_GAME_TIME_H__
#define __SANDBOX_GAME_TIME_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace Hoopoe 
{

enum period_type 
{
	STEPS,
	MINS,
	HOURS,
	DAYS,
	YEARS
};

int get_period(period_type type);
string get_age();
string get_time();

}

#endif
