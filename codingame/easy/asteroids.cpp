/*
Title: Asteroids
Tags: easy, coordinate geometry
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

class Vec2 {
public:
    Vec2 () : x(0.0f), y(0.0f) {}
    Vec2 (float x, float y) : x(x), y(y) {}
    void Normalize() {
        float length = sqrt(x * x + y * y);
        if (length > 0.0f) {
            x /= length;
            y /= length;
        }
    }
    float Distance(const Vec2 &v) {
        return sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
    }
    Vec2 operator + (const Vec2 &v) {
        return {x + v.x, y + v.y};
    }
    Vec2 operator - (const Vec2 &v) {
        return {x - v.x, y - v.y};
    }
    Vec2 operator * (float k) {
        return {x * k, y * k};
    }
    float x;
    float y;
};


ostream& operator<<(ostream& os, const Vec2 &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

class Asteroid {
public:
    Asteroid()
        : Position({0.0f, 0.0f})
        , Direction({0.0f, 0.0f})
        , Speed(0.0f)
        , Name('-') {}
    Asteroid(const Vec2 &position, char name)
        : Position(position)
        , Direction({0.0f, 0.0f})
        , Speed(0.0f)
        , Name(name) {}
    Vec2 Position;
    Vec2 Direction;
    float Speed;
    char Name;
};

int main()
{
    int w;
    int h;
    int t1;
    int t2;
    int t3;
    vector<string> first_picture;
    vector<string> second_picture;
    vector<string> third_picture;
    cin >> w >> h >> t1 >> t2 >> t3; cin.ignore();
    for (int i = 0; i < h; i++) {
        string first_picture_row;
        string second_picture_row;
        cin >> first_picture_row >> second_picture_row; cin.ignore();
        first_picture.push_back(first_picture_row);
        second_picture.push_back(second_picture_row);
        third_picture.push_back("");
        for (int j = 0; j < w; j++) {
            third_picture[i] += '.';
        }
    }

    unordered_map<char, Asteroid> asteroids;
    for (int col = 0; col < h; col++) {
        for (int row = 0; row < w; row++) {
            char c = first_picture[row][col];
            if ( c != '.') {
                Asteroid a({static_cast<float>(col), static_cast<float>(row)}, c);
                asteroids.insert({c, a});
            }
        }
    }

    for (int col = 0; col < h; col++) {
        for (int row = 0; row < w; row++) {
            char c = second_picture[row][col];
            if ( c != '.') {
                Asteroid &a = asteroids.at(c);
                Vec2 currentPosition(col, row);
                a.Direction = currentPosition - a.Position;
                a.Direction.Normalize();
                a.Speed = a.Position.Distance(currentPosition) / (t2 - t1);
            }
        }
    }

    for (auto &item : asteroids) {
        Asteroid &asteroid = item.second;
        Vec2 nextPos = asteroid.Position + (asteroid.Direction * asteroid.Speed * static_cast<float>(t3 - t1));
        int x = static_cast<int>(floor(nextPos.x + 0.001f));
        int y = static_cast<int>(floor(nextPos.y + 0.001f));
        if (x >= 0 && x < w && y >= 0 && y < h) {
            char c = third_picture[y][x];
            if ((c != '.' && asteroid.Name < c) || c == '.') {
                third_picture[y][x] = asteroid.Name;
            }
        }
    }

    for (int row = 0; row < h; row++) {
        for (int col = 0; col < w; col++) {
            cout << third_picture[row][col];
        }
        cout << endl;
    }
}
