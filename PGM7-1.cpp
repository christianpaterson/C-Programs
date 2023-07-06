// Programmer: Christian Paterson

#include <iostream>
#include <iomanip>
using namespace std;

// Global constants and function prototypes
const int MAX_GRADES = 10;
const int MAX_GRADE_VALUE = 100;
double calculateAverage(const double grade[], int count);
char getLetterGrade(double grade);

// Main function
int main() {
    double grade[MAX_GRADES];
    int count = 0;
    double sum = 0.0;

    // Get user input
    cout << "Enter your grades below, separating each value by a space: " << endl;
    cout << "Terminate by typing any negative number and pressing enter." << endl;

    // Read grades until a negative value is entered
    while (count < MAX_GRADES) {
        double input;
        cin >> input;

        if (input < 0) {
            break;
        } else if (input > MAX_GRADE_VALUE) {
            continue;
        } else {
            grade[count] = input;
            sum += input;
            count++;
        }
    }

    double average = calculateAverage(grade, count);

    // Display grades
    cout << endl;
    cout << "Sum of grades: " << sum << endl;
    cout << "Average grade: " << average << endl;

    cout << endl;
    cout << "Grades with asterisks for those below average:" << endl;
    for (int i = 0; i < count; i++) {
        cout << fixed << setprecision(2);
        if (grade[i] < average)
            cout << "* ";
        else
            cout << "  ";
        cout << grade[i] << endl;
    }

    cout << endl;
    cout << "Grades with letter equivalents:" << endl;
    for (int i = 0; i < count; i++) {
        cout << fixed << setprecision(2)
            << grade[i] << " -> " << getLetterGrade(grade[i]) << endl;
    }

    return 0;
}

// Calculate average function
double calculateAverage(const double grade[], int count) {
    double sum = 0.0;
    for (int i = 0; i < count; i++) {
        sum += grade[i];
    }
    return sum / count;
}

// Get letter grade function
char getLetterGrade(double grade) {
    if (grade >= 90 && grade <= MAX_GRADE_VALUE)
        return 'A';
    else if (grade >= 80 && grade < 90)
        return 'B';
    else if (grade >= 70 && grade < 80)
        return 'C';
    else if (grade >= 60 && grade < 70)
        return 'D';
    else if (grade >= 0 && grade < 60)
        return 'F';
                
    return ' ';
}