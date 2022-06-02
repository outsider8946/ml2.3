#ifndef POINT_H
#define POINT_H
class QPainter;

class Point
{
private:
    int x=0;
    int y=0;
    int size =3;
    int thickness =1;
public:
    Point();
    int GetX();
    void SetX(int x);
    int GetY();
    void SetY(int y);
    int GetSize();
    void SetSize(int size=3);
    void draw(QPainter *painter);
    void SetThickness(int thickness =1);
    int GetThickness();
};

#endif // POINT_H
