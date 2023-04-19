#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

bool checkAnswer(int questionNumber, string answer) { // proverka za dali e odgovorot tocen na prasanjata
    if (questionNumber == 1 && answer == "A") {
        return true;
    } else if (questionNumber == 2 && answer == "C") {
        return true;
    } else if (questionNumber == 3 && answer == "B") {
        return true;
    } else if (questionNumber == 4 && answer == "A") {
        return true;
    } else if (questionNumber == 5 && answer == "A") {
        return true;
    } else if (questionNumber == 6 && answer == "C") {
        return true;
    } else if (questionNumber == 7 && answer == "B") {
        return true;
    } else if (questionNumber == 8 && answer == "B") {
        return true;
    } else if (questionNumber == 9 && answer == "C") {
        return true;
    } else if (questionNumber == 10 && answer == "A") {
        return true;
    } else {
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
        while (getline(questions, question)) {
            cout <<question<<endl;
            getline(cin, answer);
            if (checkAnswer(questionNumber, answer)) { // se dodavaat poeni za tocen odgovor
                points+= 10;
            } 
            questionNumber++; // prefrluvanje na sledno prasanje
        }
        questions.close();
    } else {
        cout <<"Unable to open file"<<endl;
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


    ofstream outfile(fileName.c_str());
    outfile <<"Starting time: "<<startTimeStr<<endl;
    outfile <<"Name: " <<firstName<<" "<<lastName<<endl;
    outfile <<"Index: "<<index<<endl;
    outfile <<"Points: "<<points<<endl;
    outfile <<"Grade: "<<calculateGrade(points)<<endl;
    outfile <<"End of quiz time: "<<endTimeStr<<endl;
    outfile.close();

    printResultsToFile(firstName, lastName, index, startTimeStr, endTimeStr); // pecatenje na rezultati za korisnikot

    return 0;
}
