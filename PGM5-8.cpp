// Programmer: Christian Paterson

#include <iostream>
using namespace std; 

int main() { 
const int HIGHSCORE = 100; 
double score, total, average;
int numberOfScores = 0;
int totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalF = 0;

score = 0; 
total = 0;

cout << "\nTo stop entering scores, type in any number"; 
cout << "\ngreater than 100.\n\n"; 

while (score <= HIGHSCORE) { 
	total = total + score; 
	cout << "Enter a score: "; 
	cin >> score; 
	
    if (score >= 90 && score <= 100) {
        cout << "The score of " << score << " is an A" << endl;
        totalA++;
    } else if (score >= 80 && score < 90) {
        cout << "The score of " << score << " is a B" << endl;
        totalB++;
    } else if (score >= 70 && score < 80) {
        cout << "The score of " << score << " is a C" << endl;
        totalC++;
    } else if (score >= 60 && score < 70) {
        cout << "The score of " << score << " is a D" << endl;
        totalD++;
    } else if (score >= 0 && score < 60) {
        cout << "The score of " << score << " is an F" << endl;
        totalF++;
    }
    numberOfScores++;
}

numberOfScores--;
average = total / numberOfScores;

cout << "\nThe total of the scores is " << total << endl;
cout << "The average score is " << average << endl;

// Grading Report
cout << "\nGrading Report:" << endl;
cout << "A total of " << totalA << " A's were entered." << endl;
cout << "A total of " << totalB << " B's were entered." << endl;
cout << "A total of " << totalC << " C's were entered." << endl;
cout << "A total of " << totalD << " D's were entered." << endl;
cout << "A total of " << totalF << " F's were entered." << endl;

// No cin.ignore because using gdbonline
return 0; 
}