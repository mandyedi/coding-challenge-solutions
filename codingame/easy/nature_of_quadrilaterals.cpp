/*
Title: Nature of Quadrilaterals
Tags: easy, strings, trigonometry, mathematics, geometry
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double toDeg(double radian) {
    double pi = 3.14159265;
    return(radian * (180.0 / pi));
}

class Point {
public:
    Point(double x, double y) : x(x), y(y) {}
    double Distance(const Point &p) {
        double d = sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
        return d;
    }
    double x, y;
};

class Vec {
public:
    Vec(double x, double y) : x(x), y(y) {}
    Vec(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}
    double Dot(const Vec &v) const {
        return v.x * x + v.y * y;
    }
    double Length() const {
        return sqrt(x*x + y*y);
    }
    Vec Normal() const {
        double length = sqrt(x * x + y * y);
        if (length > 0.0f) {
            return { x / length, y / length };
        }
        return { x, y };
    }
    double x, y;
};

ostream& operator<<(ostream& os, const Vec &v) {
    return os;
}

double getAngle(const Vec &a, const Vec &b) {
    // alpha = arcos( (a dot b ) / ( |a|*|b| ) )
    Vec aNormal = a.Normal();
    Vec bNormal = b.Normal();
    return toDeg(acos(aNormal.Dot(bNormal) / (aNormal.Length() * bNormal.Length())));
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string a;
        int x_a;
        int y_a;
        string b;
        int x_b;
        int y_b;
        string c;
        int x_c;
        int y_c;
        string d;
        int x_d;
        int y_d;
        cin >> a >> x_a >> y_a >> b >> x_b >> y_b >> c >> x_c >> y_c >> d >> x_d >> y_d; cin.ignore();

        Point A(x_a, y_a);
        Point B(x_b, y_b);
        Point C(x_c, y_c);
        Point D(x_d, y_d);

        Vec AB(A, B);
        Vec AD(A, D);
        Vec BA(B, A);
        Vec BC(B, C);
        Vec DA(D, A);
        Vec DC(D, C);

        int angleA = getAngle(AB, AD);
        int angleB = getAngle(BA, BC);
        int angleD = getAngle(DC, DA);
        int angleC = 360 - (angleA + angleB + angleD);

        cout << a << b << c << d << " is a ";

        bool rhombus = A.Distance(B) == B.Distance(C) && C.Distance(D) == D.Distance(A);

        bool rectangle = angleA == angleB && angleB == angleC && angleC == angleD && angleD == angleA;

        if (rhombus && rectangle) {
            cout << "square.";
        }
        else if (rhombus) {
            cout << "rhombus.";
        }
        else if (rectangle) {
            cout << "rectangle.";
        }
        else if (A.Distance(B) == D.Distance(C) && A.Distance(D) == B.Distance(C)) {
            cout << "parallelogram.";
        }
        else {
            cout << "quadrilateral.";
        }

        cout << endl;
    }
}
