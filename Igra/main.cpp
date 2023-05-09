#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    int player_choice, computer_choice, player_score = 0, computer_score = 0, rounds;

    cout << "Kolku rundi sakate da igrate? ";
    cin >> rounds;

    for (int i = 1; i <= rounds; i++) {
        cout << "\nRunda " << i << "\n";
        cout << "Izberete 1 za kamen, 2 za nozici, 3 za list ";
        cin >> player_choice;

        srand(time(NULL));
        computer_choice = rand() % 3 + 1;

        if (player_choice == 1) {
            if (computer_choice == 1) {
                cout << "Kompjuterot izbra kamen. Izednaceno\n";
            } else if (computer_choice == 2) {
                cout << "Kompjuterot izbra nozici. Vie pobedivte\n";
                player_score++;
            } else {
                cout << "Kompjuterot izbra list. Kompjuterot pobedi\n";
                computer_score++;
            }
        } else if (player_choice == 2) {
            if (computer_choice == 1) {
                cout << "Kompjuterot izbra kamen. Kompjuterot pobedi\n";
                computer_score++;
            } else if (computer_choice == 2) {
                cout << "Kompjuterot izbra nozici. Izednaceno\n";
            } else {
                cout << "Kompjuterot izbra list. Vie pobedivte\n";
                player_score++;
            }
        } else if (player_choice == 3) {
            if (computer_choice == 1) {
                cout << "Kompjuterot izbra kamen. Vie pobedivte\n";
                player_score++;
            } else if (computer_choice == 2) {
                cout << "Kompjuterot izbra nozici. Kompjuterot pobedi\n";
                computer_score++;
            } else {
                cout << "Kompjuterot izbra list. Nereseno\n";
            }
        }
    }

    cout << "\nRezultat:\n";
    cout << "Vie: " << player_score << " pobedi\n";
    cout << "Kompjuterot " << computer_score <<" pobedi\n";

    return 0;
}
