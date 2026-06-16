#include <iostream>
#include <fstream>

using namespace std;

class Point {
public:
    double x;
    double y;
    double z;

    Point() {
        x = 0.0;
        y = 0.0;
        z = 0.0;
    }

    void input() {
        cout << "Write x, y, z (with space): ";
        cin >> x >> y >> z;
    }

    void print() {
        cout << "Point: (" << x << ", " << y << ", " << z << ")\n";
    }

    void saveToFile(const char* filename) {
        ofstream out(filename);
        out << x << " " << y << " " << z;
        out.close();
    }

    void loadFromFile(const char* filename) {
        ifstream in(filename);
        in >> x >> y >> z;
        in.close();
    }
};

int main() {
    Point p; 

    p.input();
    p.print();

    p.saveToFile("point.txt");

    cout << "Changed coordinate x: " << p.x << "\n";

    p.loadFromFile("point.txt");
    cout << "Data loaded from file: ";
    p.print();

    return 0;
}