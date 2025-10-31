#include<iostream>

using namespace std;


// My Class
class Vector2D{
    private:
        int x;
        int y;
    public:
        int GetX() const {return x;}
        int GetY() const {return y;}

        Vector2D() : x(0), y(0){
            // Intentionally empty
        }
        Vector2D(int x, int y) : x(x), y(y){
            //Intentionally empty
        }

        friend const int operator*(const Vector2D& v1, const Vector2D& v2){
            return (v1.x * v2.x) + (v1.y * v2.y);
        }

        void setX(int newx) {x = newx;}
        void setY(int newy) {y = newy;}
};



int main()
{
    // Some test vectors
    Vector2D v1(10,0), v2(0,10), v3(10,10), v4(5,4);
    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX()
    << "," << v2.GetY() << ") = " << v1*v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX()
    << "," << v3.GetY() << ") = " << v2*v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX()
    << "," << v4.GetY() << ") = " << v3*v4 << endl;
    return 0;
}

/*

Code Of Given in PS

class Vector2D{
    public:
        Vector2D();
        Vector2D(int newx, int newy);
        void SetX(int newx, int newy);
        int GetX();
        int GetY();
        int operator *(const Vector2D& v2);

    private:
        int x,y;
};

Vector2D::Vector2D(){

    x = 0;
    y = 0;
}


Vector2D::Vector2D(int newx, int newy){
    x = newx;
    y = newy;
}

int Vector2D::GetX(){
    return (x);
}

int Vector2D::GetY(){
    return (y);
}

void Vector2D::SetX(int newx, int newy){
    x = newx;
    y = newy
}

int Vector2D::operator *(const Vector2D& v2){
    return (this->x*v2.x) + (this->y * v2.y);
}

*/