#include<iostream>
using namespace std;

struct Rectangle{
    private:
        int width;
        int length;

    public:
        Rectangle(){}
        Rectangle(int w, int l){
            width = w;
            length = l;
        }

        int area(){
            return width * length;
        }

        void setWidth(int w){
            width = w;
        }

        int getWidth(){
            return width;
        }

        void setBoth(int w, int l){
            width = w;
            length = l;
        }
};

int main(){

    /*
        Recatangle rect{10,20}
        Rectangle rect = {10,20}
        Rectangle *rect = new Rectangle(10,20)
    */

    // parameterized constructor
    Rectangle rectA(10, 20);
    cout << "Rectangle area of rectangle A is: " << rectA.area() << endl;

    // non-parameterized constructor
    Rectangle rectB;
    rectB.setBoth(10, 30);
    cout << "Rectangle area of rectangle B is: " << rectB.area() << endl;

    // use of new keyword
    Rectangle *rectC = new Rectangle(10, 40);
    cout << "The area of rectangle C is: " << rectC->area() << endl;

    return 0;
}