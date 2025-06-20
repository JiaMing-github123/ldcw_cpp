#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int score = 0;
    int answer;

    cout << "===== Welcome to the C++ Quiz =====\n";
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "\nHi, " << name << "! Let's start the quiz. There are 3 questions, 1 point each.\n\n";

    // Question 1
    cout << "1. Which object is used to output text to the console in C++?\n";
    cout << "1) cin\n";
    cout << "2) cout\n";
    cout << "3) printf\n";
    cout << "4) print\n";
    cout << "Your answer (enter the option number): ";
    cin >> answer;
    if (answer == 2) {
        cout << "Correct!\n\n";
        score++;
    } else {
        cout << "Wrong! The correct answer is 2) cout.\n\n";
    }

    // Question 2
    cout << "2. Which of the following is a loop statement in C++?\n";
    cout << "1) if\n";
    cout << "2) switch\n";
    cout << "3) while\n";
    cout << "4) break\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 3) {
        cout << "Correct!\n\n";
        score++;
    } else {
        cout << "Wrong! The correct answer is 3) while.\n\n";
    }

    // Question 3
    cout << "3. Which symbol is used to access a class member function in C++?\n";
    cout << "1) . (dot)\n";
    cout << "2) -> (arrow)\n";
    cout << "3) :: (scope resolution)\n";
    cout << "4) All of the above\n";
    cout << "Your answer: ";
    cin >> answer;
    if (answer == 4) {
        cout << "Correct!\n\n";
        score++;
    } else {
        cout << "Wrong! The correct answer is 4) All of the above.\n\n";
    }

    // Final score
    cout << "===== Quiz Finished =====\n";
    cout << name << ", your total score is: " << score << "/3\n";

    if (score == 3)
        cout << "Excellent! You got all answers right!\n";
    else if (score == 2)
        cout << "Good job! You missed just one.\n";
    else
        cout << "Keep practicing! You'll improve.\n";

    return 0;
}