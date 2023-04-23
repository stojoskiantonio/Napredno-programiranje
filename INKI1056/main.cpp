#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include <algorithm>

using namespace std;

bool checkAnswer(int questionNumber, std::string answer) {
    std::transform(answer.begin(), answer.end(), answer.begin(), ::toupper); // algoritam za odgovorite da ne bidat case sensitive
    
    switch (questionNumber) {
        case 1:
            return answer == "A";
        case 2:
            return answer == "C";
        case 3:
            return answer == "B";
        case 4:
            return answer == "A";
        case 5:
            return answer == "A";
        case 6:
            return answer == "C";
        case 7:
            return answer == "B";
        case 8:
            return answer == "B";
        case 9:
            return answer == "C";
        case 10:
            return answer == "A";
        default:
            return false;
    }
}

int calculateGrade(int points) { // presmetuvanje na ocenka 
    if (points < 50) {
        return 5;
    } else if (points < 61) {
        return 6;
    } else if (points < 71) {
        return 7;
    } else if (points < 81) {
        return 8;
    } else if (points < 91) {
        return 9;
    } else {
        return 10;
    }
}

void printResultsToFile(string firstName, string lastName, string index, string startTime, string endTime) {
    ofstream results("results.txt", ios::app);
    if (results.is_open()) {
        results <<"Start time: "<<startTime<<endl;
        results <<"First Name: "<< firstName<<endl;
        results <<"Last Name: "<<lastName<<endl;
        results <<"Index: " <<index<<endl;
        results <<"End time: "<<endTime<<endl;
        results <<endl;
        results.close();
    } else {
        cout << "Neuspesno otvoranje na fajlot" <<endl;
    }
}

int main() {
    string firstName, lastName, index;
    bool exists = false;
    int points = 0;
    cout <<"Vnesi ime: "<<endl;
    getline(cin, firstName);
    cout <<"Vnesi prezime: "<<endl;
    getline(cin, lastName);
    cout <<"Vnesi go tvojot indeks: ";
    getline(cin, index);
    string fileName = firstName + "_" + lastName + "_" + index + ".txt";

    ifstream infile(fileName.c_str());
    if (infile.good()) {
        exists = true;
        cout <<"Vie veke ste igrale ednas!"<<endl;
        return 0;
    }   


    auto now = chrono::system_clock::now();
    time_t startTime = chrono::system_clock::to_time_t(now);

    ifstream questions("questions.txt");
    if (questions.is_open()) {
        string question, answer;
        int questionNumber = 1;
        ofstream outfile(fileName.c_str(), ios_base::app);
        while (getline(questions, question)) {
            cout <<question<<endl;
            getline(cin, answer);
            if (checkAnswer(questionNumber, answer)) { // se dodavaat poeni za tocen odgovor
                points+= 10;
            }
            outfile <<"Odgovor: "<<answer<<endl; //  Zapisuvanje na odgovor
            questionNumber++; // prefrluvanje na sledno prasanje
        }
        questions.close();
        outfile.close();
    } else {
        cout <<"Ne moze da se otvori fajlot"<<endl;
        return 1;
    }

    
    now = chrono::system_clock::now();
    time_t endTime = chrono::system_clock::to_time_t(now); // Tuka go dobivam krajnoto vreme na kvizot

    cout <<"Osvoivte " <<points<<" poeni"<<endl;
    cout <<"Vasata ocenka e "<<calculateGrade(points)<<endl;
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&startTime)); // konverzija na pocetno vreme vo string
    string startTimeStr = buffer;
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&endTime)); // konverzija na krajno vreme vo string
    string endTimeStr = buffer;


    ofstream outfile(fileName.c_str(), ios_base::app);
    outfile <<"Vreme za pocetok: "<<startTimeStr<<endl;
    outfile <<"Ime: " <<firstName<<" Prezime: "<<lastName<<endl;
    outfile <<"Indeks: "<<index<<endl;
    outfile <<"Poeni: "<<points<<endl;
    outfile <<"Ocena: "<<calculateGrade(points)<<endl;
    outfile <<"Kraj na kviz: "<<endTimeStr<<endl;
    outfile.close();

    printResultsToFile(firstName, lastName, index, startTimeStr, endTimeStr); // pecatenje na rezultati za korisnikot

    return 0;
}


