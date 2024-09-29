#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

// Student Class
class Student {
private:
    string name;
    int age;
    float grade;

public:
    // Constructor to initialize student details
    Student(string n, int a, float g) : name(n), age(a), grade(g) {}

    // Function to display student details
    void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }

    // Function to save student details to a file
    void saveToFile(ofstream &file) const {
        file << name << " " << age << " " << grade << endl;
    }

    // Static function to load student details from a file
    static Student loadFromFile(ifstream &file) {
        string name;
        int age;
        float grade;
        file >> name >> age >> grade;
        return Student(name, age, grade);
    }
};

// Function to display menu
void displayMenu() {
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Save Students to File" << endl;
    cout << "4. Load Students from File" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                // Add a new student
                string name;
                int age;
                float grade;

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter age: ";
                cin >> age;
                cout << "Enter grade: ";
                cin >> grade;

                Student student(name, age, grade);
                students.push_back(student);
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2: {
                // Display all students
                cout << "Students List:" << endl;
                for (const auto &student : students) {
                    student.display();
                }
                break;
            }
            case 3: {
                // Save students to a file
                ofstream file("students.txt");
                if (file.is_open()) {
                    for (const auto &student : students) {
                        student.saveToFile(file);
                    }
                    file.close();
                    cout << "Students saved to file successfully!" << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
                break;
            }
            case 4: {
                // Load students from a file
                ifstream file("students.txt");
                if (file.is_open()) {
                    students.clear(); // Clear the current list of students
                    while (!file.eof()) {
                        Student student = Student::loadFromFile(file);
                        students.push_back(student);
                    }
                    file.close();
                    cout << "Students loaded from file successfully!" << endl;
                } else {
                    cout << "Unable to open file!" << endl;
                }
                break;
            }
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
