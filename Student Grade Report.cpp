#include <iostream>
using namespace std;
int main() {
    
    const int MAX_STUDENTS = 5000;
    int rollNumber[MAX_STUDENTS];
    int csMarks[MAX_STUDENTS];
    int mathMarks[MAX_STUDENTS];
    double percentage[MAX_STUDENTS];
    char grade[MAX_STUDENTS];

    int count = 0;

    char choice;
    do {
        cout << "Enter Roll Number: ";
        cin >> rollNumber[count];

        cout << "Enter Marks for Computer Science: ";
        cin >> csMarks[count];
        while (csMarks[count] > 100) {
            cout << "Invalid input. Enter Marks for Computer Science: ";
            cin >> csMarks[count];
        }

        cout << "Enter Marks for Mathematics: ";
        cin >> mathMarks[count];
        while (mathMarks[count] > 100) {
            cout << "Invalid input. Enter Marks for Mathematics: ";
            cin >> mathMarks[count];
        }

        percentage[count] = (csMarks[count] + mathMarks[count]) / 2.0;

        if (percentage[count] < 50)
            grade[count] = 'F';
        else if (percentage[count] < 60)
            grade[count] = 'D';
        else if (percentage[count] < 75)
            grade[count] = 'C';
        else if (percentage[count] <= 90)
            grade[count] = 'B';
        else
            grade[count] = 'A';

        count++;

        if (count >= MAX_STUDENTS) {
            cout << "Maximum limit reached. Exiting enrollment process.\n";
            break;
        }

        cout << "Do you want to continue enrolling students? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Student Grade Report:\n";
    cout << "---------------------\n";
    for (int i = 0; i < count; i++) {
        cout << "Roll Number: " << rollNumber[i] << endl;
        cout << "CS Marks: " << csMarks[i] << endl;
        cout << "Math Marks: " << mathMarks[i] << endl;
        cout << "Percentage: " << percentage[i] << endl;
        cout << "Grade: " << grade[i] << endl;
        cout << "---------------------\n";
    }

    char advancedChoice;
    do {
        cout << "Advanced Options:\n";
        cout << "1. Update Roll Number of a particular student\n";
        cout << "2. Update marks of a particular student for CS\n";
        cout << "3. Update marks of CS for all students who are already enrolled\n";
        cout << "4. Update marks for Mathematics\n";
        cout << "5. Update marks of Mathematics for all students who are already enrolled\n";
        cout << "6. Sort the data on the basis of generated percentages\n";
        cout << "7. Delete the record of a particular student\n";
        cout << "8. Exit\n";

        cout << "Enter your choice (1-8): ";
        cin >> advancedChoice;

        int rollNum;
        int newMarks;
        bool found;

        if (advancedChoice == '1') {
            cout << "Enter the Roll Number of the student: ";
            cin >> rollNum;

            found = false;
            for (int i = 0; i < count; i++) {
                if (rollNumber[i] == rollNum) {
                    cout << "Enter the new Roll Number: ";
                    cin >> rollNumber[i];
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Roll Number " << rollNum << " not found.\n";
            }
        }
        else if (advancedChoice == '2') {
            cout << "Enter the Roll Number of the student: ";
            cin >> rollNum;

            found = false;
            for (int i = 0; i < count; i++) {
                if (rollNumber[i] == rollNum) {
                    cout << "Enter the new marks for Computer Science: ";
                    cin >> newMarks;
                    while (newMarks > 100) {
                        cout << "Invalid input. Enter the new marks for Computer Science: ";
                        cin >> newMarks;
                    }
                    csMarks[i] = newMarks;
                    percentage[i] = (csMarks[i] + mathMarks[i]) / 2.0;
                    if (percentage[i] < 50)
                        grade[i] = 'F';
                    else if (percentage[i] < 60)
                        grade[i] = 'D';
                    else if (percentage[i] < 75)
                        grade[i] = 'C';
                    else if (percentage[i] <= 90)
                        grade[i] = 'B';
                    else
                        grade[i] = 'A';
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Roll Number " << rollNum << " not found.\n";
            }
        }
        else if (advancedChoice == '3') {
            cout << "Enter the new marks for Computer Science: ";
            cin >> newMarks;
            while (newMarks > 100) {
                cout << "Invalid input. Enter the new marks for Computer Science: ";
                cin >> newMarks;
            }

            for (int i = 0; i < count; i++) {
                csMarks[i] = newMarks;
                percentage[i] = (csMarks[i] + mathMarks[i]) / 2.0;
                if (percentage[i] < 50)
                    grade[i] = 'F';
                else if (percentage[i] < 60)
                    grade[i] = 'D';
                else if (percentage[i] < 75)
                    grade[i] = 'C';
                else if (percentage[i] <= 90)
                    grade[i] = 'B';
                else
                    grade[i] = 'A';
            }
        }
        else if (advancedChoice == '4') {
            cout << "Enter the Roll Number of the student: ";
            cin >> rollNum;

            found = false;
            for (int i = 0; i < count; i++) {
                if (rollNumber[i] == rollNum) {
                    cout << "Enter the new marks for Mathematics: ";
                    cin >> newMarks;
                    while (newMarks > 100) {
                        cout << "Invalid input. Enter the new marks for Mathematics: ";
                        cin >> newMarks;
                    }
                    mathMarks[i] = newMarks;
                    percentage[i] = (csMarks[i] + mathMarks[i]) / 2.0;
                    if (percentage[i] < 50)
                        grade[i] = 'F';
                    else if (percentage[i] < 60)
                        grade[i] = 'D';
                    else if (percentage[i] < 75)
                        grade[i] = 'C';
                    else if (percentage[i] <= 90)
                        grade[i] = 'B';
                    else
                        grade[i] = 'A';
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Roll Number " << rollNum << " not found.\n";
            }
        }
        else if (advancedChoice == '5') {
            cout << "Enter the new marks for Mathematics: ";
            cin >> newMarks;
            while (newMarks > 100) {
                cout << "Invalid input. Enter the new marks for Mathematics: ";
                cin >> newMarks;
            }

            for (int i = 0; i < count; i++) {
                mathMarks[i] = newMarks;
                percentage[i] = (csMarks[i] + mathMarks[i]) / 2.0;
                if (percentage[i] < 50)
                    grade[i] = 'F';
                else if (percentage[i] < 60)
                    grade[i] = 'D';
                else if (percentage[i] < 75)
                    grade[i] = 'C';
                else if (percentage[i] <= 90)
                    grade[i] = 'B';
                else
                    grade[i] = 'A';
            }
        }
        else if (advancedChoice == '6') {
            for (int i = 0; i < count - 1; i++) {
                for (int j = 0; j < count - i - 1; j++) {
                    if (percentage[j] > percentage[j + 1]) {
                        swap(rollNumber[j], rollNumber[j + 1]);
                        swap(csMarks[j], csMarks[j + 1]);
                        swap(mathMarks[j], mathMarks[j + 1]);
                        swap(percentage[j], percentage[j + 1]);
                        swap(grade[j], grade[j + 1]);
                    }
                }
            }
        }
        else if (advancedChoice == '7') {
            cout << "Enter the Roll Number of the student: ";
            cin >> rollNum;

            found = false;
            for (int i = 0; i < count; i++) {
                if (rollNumber[i] == rollNum) {
                    for (int j = i; j < count - 1; j++) {
                        rollNumber[j] = rollNumber[j + 1];
                        csMarks[j] = csMarks[j + 1];
                        mathMarks[j] = mathMarks[j + 1];
                        percentage[j] = percentage[j + 1];
                        grade[j] = grade[j + 1];
                    }
                    count--;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "Student with Roll Number " << rollNum << " not found.\n";
            }
        }
        else if (advancedChoice == '8') {
            cout << "Exiting program.\n";
            return 0;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

        cout << "Student Grade Report:\n";
        cout << "---------------------\n";
        for (int i = 0; i < count; i++) {
            cout << "Roll Number: " << rollNumber[i] << endl;
            cout << "CS Marks: " << csMarks[i] << endl;
            cout << "Math Marks: " << mathMarks[i] << endl;
            cout << "Percentage: " << percentage[i] << endl;
            cout << "Grade: " << grade[i] << endl;
            cout << "---------------------\n";
        }

        cout << "Do you want to perform another operation? (Y/N): ";
        cin >> advancedChoice;

    } while (advancedChoice == 'Y' || advancedChoice == 'y');

    return 0;
}
