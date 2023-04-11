#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class date {
    private:
    int day;
    int month;
    int year;
    public:
    date (int day = 20, int month = 12, int year = 2012) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    friend void operator>>(istream &in, date &d); // overload e polimorfizam kade istiot operator moze da se koristi za poveke funkcii
    friend void operator<<(ostream &out, date &d) { // friend funkcijata dava pristap do privatni delovi od klasa, zastiteni, i public delovi
        out<<"\n Date :";
        out<<d.day;
        out<<"/";
        out<<d.month;
        out<<"/";
        out<<d.year;
    }
    ~date() {

    }

};

void operator>>(istream &in, date &d) {
    cout<<"\nEnter day: "<<endl;
    in>>d.day;
    cout<<"Enter month: "<<endl;
    in>>d.month;
    cout<<"Enter year: "<<endl;
    in>>d.year;
    switch (d.month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
    if (d.day > 31) {
        cout<<"Invalid days"<<endl;
        exit(0);
    }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
    if (d.day > 30) {
        cout<<"Invalid days"<<endl;
    }
    break;
    case 2:
    if ((d.year % 100 != 0 && d.year % 4 == 0) || (d.year % 400 == 0)) {
        if (d.day > 29) {
            cout<<"Invalid days"<<endl;
            exit(0);
        }
    }

    else {
        if (d.day > 28) {
            cout<<"Invalid days"<<endl;
            exit(0);
        }
    }
        break;
    }
}
int main () {
    time_t rawtime;
    time (&rawtime);
    date d;
    cout<<"Enter Date"<<endl;
    cin>>d;
    cout<<d;
    cout<<endl;
    printf("Current local time is: %s", ctime(&rawtime));
    return 0;
}
