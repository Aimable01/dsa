#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
void displayWord(const string &word, const vector<bool> &guessed);
bool isWordGuessed(const vector<bool> &guessed);
void playGame();
int main()
{
    char playAgain;
    do
    {
        playGame();
        cout << "Do you want to play again! (y/n): ";
        cin >> playAgain;
    } while (tolower(playAgain) == 'y');
    cout << "Thank you for playing! Goodbye." << endl;
    return 0;
}
void playGame()
{
    vector<string> categories = {"animals", "teams", "districs", "films", "books"};
    vector<vector<string>> words = {
        {"elephant", "giraffe", "kangaroo", "dolphin"},
        {"lakers", "warriors", "celtics", "bulls"},
        {"nyabihu", "gasabo", "rusizi", "rulindo"},
        {"inception", "avatar", "titanic", "gladitor"},
        {"hamlet", "1984", "dune", "it"}};
    cout << "Select a category for words: " << endl;
    for (size_t i = 0; i < categories.size(); i++)
    {
        cout << i + 1 << ". " << categories[i] << endl;
    }
    int categoryChoice;
    cout << "Enter category number: ";
    cin >> categoryChoice;
    if (categoryChoice < 1 || categoryChoice > categories.size())
    {
        cout << "Invalid category choice. Exiting game." << endl;
        return;
    }
    srand(static_cast<unsigned int>(time(0)));
    string chosenWord = words[categoryChoice - 1][rand() % words[categoryChoice - 1].size()];
    vector<bool> guessed(chosenWord.length(), false);
    int remainingChances = 6;
    while (remainingChances > 0)
    {
        cout << "\nWord: ";
        displayWord(chosenWord, guessed);
        cout << "Remaining chances: " << remainingChances << endl;
        cout << "Enter a letter (or type 'exit' to quit)";
        string input;
        cin >> input;
        if (input == "exit")
        {
            cout << "Exiting game." << endl;
            return;
        }
        if (input.length() != 1)
        {
            cout << "Please enter a single letter." << endl;
            continue;
        }
        char guessedLetter = tolower(input[0]);
        bool correctGuess = false;
        for (size_t i = 0; i < chosenWord.length(); ++i)
        {
            if (tolower(chosenWord[i] == guessedLetter))
            {
                guessed[i] = true;
                correctGuess = true;
            }
        }
        if (!correctGuess)
        {
            --remainingChances;
            cout << "Incorrect guess!" << endl;
        }
        if (isWordGuessed(guessed))
        {
            cout << "\nCongratulations! you guessed the word: " << chosenWord << endl;
            return;
        }
    }
    cout << "\nYou've run out of chances! The word was: " << chosenWord;
}
void displayWord(const string &word, const vector<bool> &guessed)
{
    for (size_t i = 0; i < word.length(); ++i)
    {
        if (guessed[i])
        {
            cout << word[i];
        }
        else
        {
            cout << "_";
        }
    }
}
bool isWordGuessed(const vector<bool> &guessed)
{
    return all_of(guessed.begin(), guessed.end(), [](bool g)
                  { return g; });
}