#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    string className;
    char division;
    string dob;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicense;

public:
    // Constructors
    Student(const string& name, int rollNumber, const string& className,
            char division, const string& dob, const string& bloodGroup,
            const string& contactAddress, const string& telephoneNumber,
            const string& drivingLicense)
        : name(name), rollNumber(rollNumber), className(className), division(division),
          dob(dob), bloodGroup(bloodGroup), contactAddress(contactAddress),
          telephoneNumber(telephoneNumber), drivingLicense(drivingLicense) {}

    // Destructor
    ~Student() {
        cout << "Destructor called for student: " << name << endl;
    }

    // Display student information
    void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << className << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No.: " << drivingLicense << endl;
    }
};

int main() {
    const int maxStudents = 10; // Maximum number of students
    Student* students[maxStudents]; // Array of student pointers

    int studentCount = 0; // Current number of students

    while (true) {
        // Display the main menu
        cout << "\nStudent Information System" << endl;
        cout << "1. Add a new student" << endl;
        cout << "2. Display student information" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        if (!(cin >> choice)) {
          
            cout << "Invalid input. Please enter a valid choice." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                // Add a new student
                if (studentCount < maxStudents) {
                    string name, className, dob, bloodGroup, contactAddress, telephoneNumber, drivingLicense;
                    int rollNumber;
                    char division;

                    // Input student information
                    cout << "Enter student information:" << endl;
                    cout << "Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Roll Number: ";
                    cin >> rollNumber;
                    cout << "Class: ";
                    cin.ignore();
                    getline(cin, className);
                    cout << "Division (A/B/C): ";
                    cin >> division;
                    cout << "Date of Birth: ";
                    cin.ignore();
                    getline(cin, dob);
                    cout << "Blood Group: ";
                    cin.ignore();
                    getline(cin, bloodGroup);
                    cout << "Contact Address: ";
                    cin.ignore();
                    getline(cin, contactAddress);
                    cout << "Telephone Number: ";
                    cin.ignore();
                    getline(cin, telephoneNumber);
                    cout << "Driving License No.: ";
                    cin.ignore();
                    getline(cin, drivingLicense);

                    students[studentCount] = new Student(name, rollNumber, className, division, dob, bloodGroup, contactAddress, telephoneNumber, drivingLicense);
                    studentCount++;
                    cout << "Student added successfully." << endl;
                } else {
                    cout << "Maximum number of students reached." << endl;
                }
                break;
            case 2:
                // Display student information
                if (studentCount > 0) {
                    cout << "Enter the student's index (0-" << studentCount - 1 << "): ";
                    int index;
                    if (!(cin >> index) || index < 0 || index >= studentCount) {
                        cout << "Invalid index. Please enter a valid index." << endl;
                    } else {
                        students[index]->displayInfo();
                    }
                } else {
                    cout << "No students in the database." << endl;
                }
                break;
            case 3:
                // Exit the program
                cout << "Exiting the program." << endl;
                // Deallocate memory for student objects and call destructors
                for (int i = 0; i < studentCount; i++) {
                    delete students[i];
                }
                return 0;
            default:
                cerr << "Invalid choice. Please select a valid option." << endl;
                break;
        }
    }

    return 0;
}

