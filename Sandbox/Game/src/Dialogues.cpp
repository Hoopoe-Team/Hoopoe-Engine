#include "../include/Dialogues.h"

namespace Hoopoe {

    Dialogue::Dialogue() { text = ""; }
    Dialogue::Dialogue(string &text, vector<Option> options) {
        this->text = text;
        this->options = options;
    }

    bool Dialogue::exist() { if(this->text == "") { return false; } else { return true; } }

    string Dialogue::get_text() { return this->text; }
    Option Dialogue::get_option(int index) { return this->options.at(index); }
    vector<Option> Dialogue::get_options() { return this->options; }
    void Dialogue::set_option(int index, Option option) { this->options[index] = option; }

    void Dialogue::echo_dialogue() { cout << text; }
    void Dialogue::echo_options() {
        for(int i = 0; i < options.size(); ++i) {
            cout << (i+1) << ") " << options[i].get_text() << endl;
        }
    }

    void Dialogue::echo() {
        this->echo_dialogue(); cout << "\n\n";
        this->echo_options();
    }


    Option::Option() { this->text = ""; this->next_dialogue = Dialogue(); }
    Option::Option(string text, Dialogue next_dialogue) { this->text = text; this->next_dialogue = next_dialogue; }

    bool Option::exist() { if(this->text == "") { return false; } else { return true; } }

    Dialogue Option::get_next_dialogue() { return this->next_dialogue; }
    string Option::get_text() { return this->text; }

    void converse(Dialogue dialogue) {
        if(dialogue.exist()) {
            dialogue.echo();

            int index;
            cout << "Your choice: "; cin >> index;
            --index;

            if(dialogue.get_option(index).exist()) {
                converse(dialogue.get_option(index).get_next_dialogue());
            }
        }
    }

}
