#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

public:
    Fraction() {
        numerator = 0;
        denominator = 1;
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        
        while (denominator == 0) {
            cout << "Error! Denominator cannot be 0. Enter again: ";
            cin >> denominator;
        }
    }

    void print() {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction add(Fraction other) {
        Fraction result;
        result.numerator = (this->numerator * other.denominator) + (other.numerator * this->denominator);
        result.denominator = this->denominator * other.denominator;
        return result;
    }

    Fraction subtract(Fraction other) {
        Fraction result;
        result.numerator = (this->numerator * other.denominator) - (other.numerator * this->denominator);
        result.denominator = this->denominator * other.denominator;
        return result;
    }

    Fraction multiply(Fraction other) {
        Fraction result;
        result.numerator = this->numerator * other.numerator;
        result.denominator = this->denominator * other.denominator;
        return result;
    }

    Fraction divide(Fraction other) {
        Fraction result;
        if (other.numerator == 0) {
            cout << "Error! Division by zero." << endl;
            return result;
        }
        result.numerator = this->numerator * other.denominator;
        result.denominator = this->denominator * other.numerator;
        return result;
    }
};

int main() {
    Fraction fraction1;
    Fraction fraction2;

    cout << "Entering the first fraction" << endl;
    fraction1.input();

    cout << "\n Entering the second fraction" << endl;
    fraction2.input();

    cout << "\nFractions entered:" << endl;
    cout << "Fraction 1: "; fraction1.print();
    cout << "Fraction 2: "; fraction2.print();
    
    cout << "\n Results" << endl;

    Fraction sum = fraction1.add(fraction2);
    cout << "Sum: "; sum.print();

    Fraction diff = fraction1.subtract(fraction2);
    cout << "Difference: "; diff.print();

    Fraction prod = fraction1.multiply(fraction2);
    cout << "Product: "; prod.print();

    Fraction quot = fraction1.divide(fraction2);
    cout << "Quotient: "; quot.print();

    return 0;
}