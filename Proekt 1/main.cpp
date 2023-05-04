#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main () {
    int index;
    string name, artist, lyrics;
    vector<string> lyrics_vector;

    cout<<"Vnesi go brojot na indeks"<<endl;
    cin>>index;
    int index1 = index;
    cin.ignore();
    cout<<"Vnesi ime"<<endl;
    getline(cin, name);
    cout<<"Vnesi ime na artist"<<endl;
    getline(cin, artist);
    cout<<"Vnesi tekst na pesna"<<endl;
    getline(cin, lyrics);

    int maxDigit = 0;
    while (index > 0) {
        if (index % 10 > maxDigit) {
            maxDigit = index % 10;
        }

        index /= 10;
    }

    for (int i = 0; i < lyrics.length(); i++) {
        lyrics[i] = lyrics[i] + maxDigit;
    }

    string song = artist + " - " + lyrics;
    lyrics_vector.push_back(song);
    sort(lyrics_vector.begin(), lyrics_vector.end());
    
    cout<<"Izmenetiot tekst izgleda vaka:"<<endl;
    for (int i = 0; i < lyrics_vector.size(); i++) {
        cout<<lyrics_vector[i]<<endl;
    }

    ofstream output_file(to_string(index1) +  ".proekt2");
    if (output_file.is_open()) {
        for (int i = 0; i < lyrics_vector.size(); i++) {
            output_file<<lyrics_vector[i]<<endl;
        }
        output_file.close();
    }
    return 0;
}