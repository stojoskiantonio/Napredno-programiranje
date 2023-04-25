#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctime>


using namespace std;

int main () {
    srand(time(NULL));
    int randomNumber = rand () % 100 + 1;
    int guess;
    int numberOfGuesses = 0;
    cout<<"Pogodi go brojot od 1 do 100"<<endl;
    while (guess != randomNumber) {
        cin>>guess;
        if (guess > randomNumber) {
            cout<<"Brojot sto go napisavte e pogolem od zamisleniot broj. Probajte pak"<<endl;
            numberOfGuesses++;
        }

        else if (guess < randomNumber) {
            cout<<"Brojot sto go napisavte e pomal od zamisleniot broj. Probajte pak"<<endl;
            numberOfGuesses++;
        }

        else {
            cout<<"Go pogodivte tocniot broj"<<endl;
            numberOfGuesses++;
            cout<<"Broj na obidi za koj vi trebase da go pogodite brojot e "<<numberOfGuesses<<endl;
            return 0;
        }
    }
}