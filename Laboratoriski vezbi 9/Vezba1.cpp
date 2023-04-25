#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int main () {
    string sentence;
    int specialCharacters = 0, upperLetter = 0, lowerLetter = 0, numbers = 0;
    cout<<"Napisi recenica"<<endl;
    getline(cin, sentence);
    for (int i = 0; i < sentence.length(); i++) {
        if (isupper(sentence[i])) {
            upperLetter++;
        }

        else if (islower(sentence[i])) {
            lowerLetter++;
        }

        else if (isdigit(sentence[i])) {
            numbers++;
        }

        else {
            specialCharacters++;
        }
    }

    cout<<"Recenicata ima vkupno "<<sentence.length()<<" karakteri"<<endl;
    cout<<"Recenicata ima "<<upperLetter<<" golemi bukvi"<<endl;
    cout<<"Recenicata ima "<<lowerLetter<<" mali bukvi"<<endl;
    cout<<"Recenicata ima "<<numbers<<" broevi"<<endl;
    cout<<"Recenicata ima "<<specialCharacters<<" specialni karakteri"<<endl;
    
    return 0;
}