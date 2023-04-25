#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    string nameOfFile, text;
    cout<<"Vnesi ime na fajl"<<endl;
    getline(cin, nameOfFile);
    cout<<"Vnesi go tekstot"<<endl;
    getline(cin, text);

    ofstream outfile;
    outfile.open(nameOfFile.c_str(), ios::out | ios::app);
    if (outfile.is_open()) {
        cout<<"Fajlot vekje postoi, tekstot ke bide dodaden"<<endl;
        outfile<<text<<endl;
        outfile.close();
        cout<<"Tekst dodaden vo fajlot"<<endl;
    }

    else {
        outfile.open(nameOfFile.c_str());
        outfile<<text<<endl;
        outfile.close();
        cout<<"Tekstot e zapisan vo fajlot"<<endl;
    }
    return 0;
}
