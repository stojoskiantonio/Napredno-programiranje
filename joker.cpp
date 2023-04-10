#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

int main () {
    vector<string> deck;
    string suits[] = {"Hearts", "Clubs", "Diamonds", "Spades"};
    string ranks[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.push_back(ranks[j] + " " + suits[i]);
        }
    }
    
    deck.push_back("Black Joker");
    deck.push_back("Red Joker");
    cout<<"Deck of cards:"<<endl;
    for (int i = 0; i < deck.size(); i++) {
        cout<<deck[i]<<endl;
    }

    srand(time(0));
    for (int i = 0; i < deck.size(); i++) {
        int j = rand() % deck.size();
        swap(deck[i], deck[j]);
    }
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"Mixed deck of cards"<<endl;
    for (int i = 0; i < deck.size(); i++) {
        cout<<deck[i]<<endl;
    }

    vector<string> player1, player2, player3, player4;
    for (int i = 0; i < deck.size(); i++) {
        if (i % 4 == 0) {
            player1.push_back(deck[i]);
        } else if (i % 4 == 1) {
            player2.push_back(deck[i]);
        } else if (i % 4 == 2) {
            player3.push_back(deck[i]);
        } else {
            player4.push_back(deck[i]);
        }
    }

    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"Player 1's hand:"<<endl;
    for (int i = 0; i < player1.size(); i++) {
        cout<<player1[i]<<endl;
    }

    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"Player 2's hand:"<<endl;
    for (int i = 0; i < player2.size(); i++) {
        cout<<player2[i]<<endl;
    }

    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"Player 3's hand:"<<endl;
    for (int i = 0; i < player3.size(); i++) {
        cout<<player3[i]<<endl;
    }

    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"------"<<endl;
    cout<<"Player 4's hand:"<<endl;
    for (int i = 0; i < player4.size(); i++) {
        cout<<player4[i]<<endl;
    }

    return 0;
}
