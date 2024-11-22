#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int getChoice() {
    int choice;
    cout << "Welcome to the word guessing game." << endl;
    cout << "We have different categories." << endl;
    cout << "1 - names of animals" << endl;
    cout << "2 - names of teams" << endl;
    cout << "3 - names of districts" << endl;
    cout << "4 - names of books" << endl;
    cout << "5 - names of films" << endl;
    cout << "Enter the number corresponding to your desired category: ";
    cin >> choice;
    
    while (choice < 1 || choice > 5) {
        cout << "Invalid category. Please enter a number between 1 and 5: ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> choice;
    }
    return choice;
}

string getRandomWord(int choice) {
    vector<vector<string>> categories = {
        {"elephant", "tiger", "giraffe", "monkey"},
        {"warriors", "lakers", "bulls", "spurs"},
        {"kigali", "musanze", "nyanza", "rulindo"},
        {"hamlet", "macbeth", "1984", "it"},
        {"inception", "avatar", "titanic", "gladiator"}
    };
    
    srand(time(0));
    int randomIndex = rand() % categories[choice - 1].size();
    return categories[choice - 1][randomIndex];
}

void displayWord(const string& word, const string& guessedLetters) {
    for (char c : word) {
        if (guessedLetters.find(c) != string::npos)
            cout << c;
        else
            cout << '_';
    }
    cout << endl;
}

char guessLetter() {
    string input;
    cout << "Enter a letter to guess (or type 'exit' to quit): ";
    cin >> input;
    if (input == "exit")
        return '\0';
    return input[0];
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return choice == 'y' || choice == 'Y';
}

void playGame() {
    int choice = getChoice();
    if (choice < 1 || choice > 5) {
        cout << "Invalid category selected. Game terminated." << endl;
        return;
    }

    vector<string> categoryNames = {"names of animals", "names of teams", "names of districts", "names of books", "names of films"};
    cout << "You have selected the category: " << categoryNames[choice - 1] << endl;

    string word = getRandomWord(choice);
    string guessedLetters = "";
    int chances = 7;
    bool won = false;

    cout << "You have " << chances << " chances to guess the word." << endl;

    while (chances > 0) {
        displayWord(word, guessedLetters);

        char letter = guessLetter();
        if (letter == '\0') return;

        if (word.find(letter) != string::npos) {
            if (guessedLetters.find(letter) == string::npos) {
                guessedLetters += letter;
            } else {
                cout << "You've already guessed that letter." << endl;
            }
        } else {
            chances--;
            cout << "Incorrect guess. " << chances << " chances left." << endl;
            cout << "The letter '" << letter << "' is not in the word." << endl;
        }

        bool allGuessed = true;
        for (char c : word) {
            if (guessedLetters.find(c) == string::npos) {
                allGuessed = false;
                break;
            }
        }

        if (allGuessed) {
            cout << "Congratulations! You've guessed the word: " << word << endl;
            won = true;
            break;
        }
    }

    if (!won) {
        cout << "Sorry, you've run out of chances. The word was: " << word << endl;
        cout << "Restarting the game..." << endl;
        playGame(); // Restart the game
    }
}

int main() {
    do {
        playGame();
    } while (playAgain());

    cout << "Thank you for playing!" << endl;
    return 0;
}

