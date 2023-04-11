#include <iostream>
#include <cmath>
using namespace std;

class operations {
    int num1;
    int num2;
    public:
    operations(int num1 = 4, int num2 = 5) {
        this->num1 = num1;
        this->num2 = num2;
    }

    void input () {
        cout<<"Enter two numbers"<<endl;
        cin>>num1>>num2;
        cout<<endl;
    }

    void power () {
        cout<<"Num 1 to the power of Num 2 is "<<pow(num1,num2)<<endl;
    }

    void euler () {
        cout<<"E raised to num1 + num 2 is "<<exp(num1+num2)<<endl;
    }

    void addition () {
        cout<<"Addition = "<<num1+num2<<endl;
    }

    void substraction () {
        cout<<"Substraction = "<<num1-num2<<endl;
    }

    void multiplication () {
        cout<<"Multiplication = "<<num1*num2<<endl;
    }

    void division () {
        cout<<"Division = "<<(float)num1/num2<<endl;
    }
};

int main () {
    operations op;
    op.input();
    op.power();
    op.euler();
    op.addition();
    op.substraction();
    op.multiplication();
    op.division();
    return 0;
}   
