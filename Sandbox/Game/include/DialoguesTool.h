#ifndef __SANDBOX_GAME_DIALOGUESTOOL_H__
#define __SANDBOX_GAME_DIALOGUESTOOL_H__

#include <iostream>
#include <string>
#include <vector>
#include <cstdarg>
#include <sstream>
#include "../include/Dialogues.h"

using namespace std;

namespace Hoopoe 
{

vector<int> convert_dialogue_index(string index, int n, vector<int> nums);

void add_dialogue(string index, string dialogue_text, size_t count, ...);

void collect_dialogues();

}

#endif
