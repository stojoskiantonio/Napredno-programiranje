#include <iostream>
using namespace std;

class Shape { // klasa za dolzina, visina i sirina koja e zastitena i e mozen pristap samo so inheritance 
    protected:
    float width, height, length;
    public:
    void insertDimensions () {
        cout<<"Insert dimensions:"<<endl;
        cin>>width>>height>>length;
    }
    void setDimensions(float w, float h, float l) { 
        cout<<"The dimensions are:"<<w<<", "<<h<<" and "<<l<<endl; // ke bide ispecateno koi dimenzii nie ke gi vnesime vo kodot podolu
        width = w;
        height = h;
        length = l;
    }
};

class triangle:public Shape { // klasa za triagolnik
    public:
    float area () {
        return (width * height * length / 2); // area za triagolnik so hipotenuza
    }
};

class rectangle : public Shape { // klasa za pravoaglnik
    public:
    float area (float width, float height) {
        return (width * height); // area za pravoagolnik
    }
};

int main () {
    triangle triangle; // triagolnik od klasata triagolnik
    rectangle rectangle; // pravoagolnik od klasata pravoagolnik
    triangle.setDimensions(10, 5, 6); // zadavame dmenzii za triagolnik

    cout<<"Area of triangle is "<<triangle.area()<<endl;
    cout<<"Area of rectangle is "<<rectangle.area(10, 5)<<endl;
    return 0;
}
