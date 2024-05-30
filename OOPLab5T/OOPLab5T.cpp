//Task 1
/*

#include <iostream>
#include <string>
using namespace std;
class Point {
protected:
    double x;
    double y;
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    virtual ~Point() {}
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
    void setCoordinates(double newX, double newY) {
        x = newX;
        y = newY;
    }
};

class ColoredPoint : public Point {
protected:
    string color;
public:
    ColoredPoint(double x = 0, double y = 0, const string& color = "black")
        : Point(x, y), color(color) {}
    void setColor(const string& newColor) {
        color = newColor;
    }
    void print() const {
        cout << "(" << x << ", " << y << ") - " << color;
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    // тест1(перевірка класу точка)
    Point p1(3, 4);
    cout << "Точка p1: ";
    p1.print();
    cout << endl;

    // тест2(перевірка класу Кольорова точка)
    ColoredPoint cp1(5, 6, "червоний");
    cout << "Кольорова точка(нащадок) cp1: ";
    cp1.print();
    cout << endl;

    // тест3(перевірка переприсвоєння)
    cp1.setCoordinates(7, 8);
    cp1.setColor("синій");
    cout << "Нові координати кольорової точки cp1: ";
    cp1.print();
    return 0;
}

*/
//Task 2

/*
#include <iostream>
#include <string>
using namespace std;
class Processor {
private:
    int speedMHz;
public:
    Processor(int speedMHz = 0) : speedMHz(speedMHz) {}
    int getSpeedMHz() const {
        return speedMHz;
    }
};

class Computer {
private:
    Processor cpu;
    string brand;
    double price;
public:
    Computer(const Processor& cpu, const string& brand, double price)
        : cpu(cpu), brand(brand), price(price) {}

    void print() const {
        cout << "Марка: " << brand << ", Ціна: " << price << " грн, Швидкість процессора: " << cpu.getSpeedMHz() << " MHz" << endl;
    }
};

class DesktopComputer : public Computer {
private:
    string monitorSize;
public:
    DesktopComputer(const Processor& cpu, const string& brand, double price, const string& monitorSize)
        : Computer(cpu, brand, price), monitorSize(monitorSize) {}

    void print() const {
        Computer::print();
        cout << "Діагональ монітора: " << monitorSize << endl;
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    Processor cpu1(3000);
    Computer comp1(cpu1, "Acer", 10000);
    comp1.print();

    DesktopComputer desktop1(cpu1, "HP", 15000, "24 дюйми");
    desktop1.print();
    return 0;
}

*/

//Task 3
#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name;
    int age;
public:
    Person(const string& name = "", int age = 0) : name(name), age(age) {}

    virtual ~Person() {}

    virtual void input(istream& in) {
        cout << "Enter name: ";
        in >> name;
        cout << "Enter age: ";
        in >> age;
    }

    virtual void output(ostream& out) const {
        out << "Name: " << name << ", Age: " << age;
    }

    Person(const Person& other) : name(other.name), age(other.age) {}

    Person& operator=(const Person& other) {
        if (this != &other) {
            name = other.name;
            age = other.age;
        }
        return *this;
    }
};

class Employee : public Person {
private:
    string position;
public:
    Employee(const string& name = "", int age = 0, const string& position = "")
        : Person(name, age), position(position) {}

    void input(istream& in) override {
        Person::input(in);
        cout << "Enter position: ";
        in >> position;
    }

    void output(ostream& out) const override {
        Person::output(out);
        out << ", Position: " << position;
    }

    Employee(const Employee& other) : Person(other), position(other.position) {}

    Employee& operator=(const Employee& other) {
        if (this != &other) {
            Person::operator=(other);
            position = other.position;
        }
        return *this;
    }
};

int main() {
    setlocale(LC_CTYPE, "Ukr");
    Person person1;
    cout << "Enter information for person1:" << endl;
    person1.input(cin);

    Employee employee1;
    cout << "Enter information for employee1:" << endl;
    employee1.input(cin);

    cout << "\nDetails of person1: ";
    person1.output(cout);
    cout << "\nDetails of employee1: ";
    employee1.output(cout);
    return 0;
}