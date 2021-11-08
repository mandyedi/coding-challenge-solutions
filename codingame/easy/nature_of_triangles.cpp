/*
Title: Nature of Triangles
Tags: easy, conditions, trigonometry, mathematics, geometry
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Used it for angle == 90 tests, but it returned false
// I leave it here for future reference, it might worth a deeper investigation
bool equal(double x, double y) {
    return abs(x - y) < numeric_limits<double>::epsilon();
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

double toRad(double degree)
{
    double pi = 3.14159265;
    return (degree * (pi / 180.0));
}

double toDeg(double radian)
{
    double pi = 3.14159265;
    return(radian * (180.0 / pi));
}

double getAngleA(double a, double b, double c) {
    double cosA = (b*b + c*c - a*a) / (2.0*b*c);
    return toDeg(acos(cosA));
}

double getAngleB(double a, double b, double c) {
    double cosB = (a*a + c*c - b*b) / (2.0*a*c);
    return toDeg(acos(cosB));
}

double getAngleC(double a, double b, double c) {
    double cosC = (a*a + b*b - c*c) / (2.0*a*b);
    return toDeg(acos(cosC));
}

int main()
{
    int n;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        string a;
        double x_a;
        double y_a;
        string b;
        double x_b;
        double y_b;
        string c;
        double x_c;
        double y_c;
        cin >> a >> x_a >> y_a >> b >> x_b >> y_b >> c >> x_c >> y_c; cin.ignore();
        Point A(x_a, y_a);
        Point B(x_b, y_b);
        Point C(x_c, y_c);

        cout << a << b << c << " is ";

        double AB = A.Distance(B);
        double AC = A.Distance(C);
        double BC = B.Distance(C);

        if (AB != AC &&
            AB != BC &&
            AC != BC ) {
                cout << "a scalene";
        }
        else if (AB == AC &&
                 AB != BC &&
                 AC != BC ) {
                cout << "an isosceles in " << a;
        }
        else if (AB != AC &&
                 AB == BC &&
                 AC != BC ) {
                cout << "an isosceles in " << b;
        }
        else if (AB != AC &&
                 AB != BC &&
                 AC == BC ) {
                cout << "an isosceles in " << c;
        }

        double angleA = getAngleA(BC, AC, AB);
        double angleB = getAngleB(BC, AC, AB);
        double angleC = getAngleC(BC, AC, AB);
        cerr << angleA << " " << angleB << " " << angleC << endl;

        if (angleA < 90.0 && angleB < 90.0 && angleC < 90.0) {
            cout << " and an acute triangle.";
        }
        else if (static_cast<int>(angleA) == 90) {
            cout << " and a right in " << a << " triangle.";
        }
        else if (static_cast<int>(angleB) == 90) {
            cout << " and a right in " << b << " triangle.";
        }
        else if (static_cast<int>(angleC) == 90) {
            cout << " and a right in " << c << " triangle.";
        }
        else if (angleA > 90.0) {
            cout << " and an obtuse in " << a << " (" << round(angleA) << "°) triangle.";
        }
        else if (angleB > 90.0) {
            cout << " and an obtuse in " << b << " (" << round(angleB) << "°) triangle.";
        }
        else if (angleC > 90.0) {
            cout << " and an obtuse in " << c << " (" << round(angleC) << "°) triangle.";
        }

        cout << endl;
    }
}
