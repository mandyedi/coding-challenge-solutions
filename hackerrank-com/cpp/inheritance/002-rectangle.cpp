class Rectangle {
protected:
    int width, height;
public:
    void virtual display() {
        cout << width << " " << height << endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        cin >> width >> height;
    }
    
    void display() {
        cout << width * height << endl;
    }
};