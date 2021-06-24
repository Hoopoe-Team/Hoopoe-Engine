#include <Hoopoe.h>
#include <stdio.h>

#include "Game/GameHeaders.h"

class Sandbox : public Hoopoe::Application {
public:
    Sandbox() {
        Hoopoe::Graphics game;

        SDL_Texture *background = game.loadTexture("../Sandbox/Game/resources/sprites/background.png");
        SDL_RenderClear(game.get_renderer());
        game.renderBackground(background);
        SDL_RenderPresent(game.get_renderer());

        SDL_Delay(5000);

        SDL_DestroyTexture(background);
    }

    ~Sandbox() {}
};

Hoopoe::Application* Hoopoe::CreateApplication() {
    return new Sandbox();
}


// Location northland(1, "Североземье", TOWN);
// Location crossroads(2, "Златоземье", CROSSROADS);

// a_location n_to_crossroads(&crossroads, 2);
// a_location c_to_northland(&northland, 2);

// vector<a_location> v_northland; v_northland.push_back(n_to_crossroads);
// vector<a_location> v_crossroads; v_crossroads.push_back(c_to_northland);

// northland.set_a_locations(v_northland);
// crossroads.set_a_locations(v_crossroads);

// Player player(1, "Ворвол", 10, 5, 10, 5, 0, 70, 0, 0, &northland);

// player.get_location().echo_a_locations();

// int num;
// while(true) {
//     cin >> num;
//     switch(num) {
//     case 1:
//         player.set_location(*player.get_location().get_a_locations()[0].location);
//         break;
//     }

//     player.get_location().echo_a_locations();
// }


/*
add_dialogue("1", "� ������� ���������... �� �����������...", 3, "������������, ��������!", "����� � ����, ������!", "���� ���� ��������, ���!");

add_dialogue("1_1", "� ������ ����� ����� ��������� �������\n����� ���������� � ����� ���!", 1, "��� ����������. ������ ������.");
add_dialogue("1_2", "���� ��� �����. �� ����� ��� ���������, � �� ������ ���� ��������. �� ����� ��� ������, �� ����� ���� ��������?", 4, "������ ���, � ����� ����� �� ���", "� ������ ��, � ���� ���-�� �� �����������", "������ ���� ��������, ������ ��� ���������, ��� ���� � ���� ������", "����� ������ ����� ����� �� ��� �����?");
add_dialogue("1_3", "��� ����� �� ��, �������? �� � ��� ���� �������� �� ���� ������.", 1, "��� ����������. ������ ������.");

add_dialogue("1_2_1", "� ��� ��� ������� ��� � �������", 1, "��� ����������. ������ ������.");
add_dialogue("1_2_2", "�� ��� �� �����������, ������ ����������", 1, "��� ����������. ������ ������.");
add_dialogue("1_2_3", "����� ����������, ����� �������� ��������� ������ ������ �� 9999�. ������ ���������� �� QIWI +79097906796", 1, "�����������! �� ������� ����� � ����!");
add_dialogue("1_2_4", "��� ��� ����� ���������. ������� �� ��� ����, � ����� �� ���� ������.", 1, "��� ����������. ������ ������.");

collect_dialogues();
*/
