#ifndef __SANDBOX_GAME_DIALOGUES_H__
#define __SANDBOX_GAME_DIALOGUES_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Hoopoe 
{

class Option;

class Dialogue 
{
public:
	Dialogue();
	Dialogue(string &text, vector<Option> options);

	bool exist();

	string get_text();
	Option get_option(int index);
	vector<Option> get_options();
	void set_option(int index, Option option);

	void echo_dialogue();
	void echo_options();
	void echo();

private:
	string text;
	vector<Option> options;
};

class Option 
{
public:
	Option();
	Option(string text, Dialogue next_dialogue);

	bool exist();

	Dialogue get_next_dialogue();
	string get_text();
private:
	Dialogue next_dialogue;
	string text;
};

void converse(Dialogue dialogue);

}

#endif
