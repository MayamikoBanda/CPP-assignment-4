#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[50];
    int studentID;
    int age;

public:
    void init(const char* n, int id, int a) {
        strcpy(name, n);   // copy name
        studentID = id;    // assign ID
        age = a;           // assign age
    }

    void printStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Age: " << age << endl;
    }

    int getID() {
        return studentID;
    }

    int getAge() {
        return age;
    }

    const char* getName() {
        return name;
    }
};

// swap function
void personSwap(Person &p1, Person &p2) {
    Person temp = p1;
    p1 = p2;
    p2 = temp;
}

// test
int main() {
    Person p1, p2;

    p1.init("Alice", 101, 20);
    p2.init("Bob", 202, 22);

    cout << "Before swap:\n";
    p1.printStudentInfo();
    cout << endl;
    p2.printStudentInfo();

    personSwap(p1, p2);

    cout << "\nAfter swap:\n";
    p1.printStudentInfo();
    cout << endl;
    p2.printStudentInfo();

    return 0;
}