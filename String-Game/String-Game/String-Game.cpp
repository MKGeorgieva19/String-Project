#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

//Header files
#include "checkGuessTheWord.h"
#include "displayGuessTheWordLetters.h"
#include "extractLetters.h"
#include "game.h"
#include "gameOver.h"
#include "guessTheWord.h"
#include "guessTheWordMenuAndOptions.h"
#include "guessTheWordRules.h"
#include "guessTheWordSign.h"
#include "hangmanGame.h"
#include "hangmanMenuAndOptions.h"
#include "hangmanRules.h"
#include "hangmanSign.h"
#include "hangmanStructure.h"
#include "inGameMenuForGuessTheWord.h"
#include "inGameMenuForHangman.h"
#include "leaveMenuForGuessTheWord.h"
#include "menuAndOptions.h"
#include "playerGameChoice.h"
#include "randomGive.h"
#include "randomize.h"
#include "rulesSign.h"
#include "winMenu.h"

using namespace std;

void winMenuHangman();
void hangmanLost(char choice);

//Function that checks if the player wants to play again or to return to the menu
void checkGuessTheWord(string value)
{
    if (value == "1") guessTheWord();
    else if (value == "2")
    {
        system("cls");
        guessTheWordMenuAndOptions();
    }
    else //If the player enters symbol or another wrong input it displays "Invalid move. Please try again:"
    {
        cout << "Invalid move. Please try again: ";
        cin >> value;
        checkGuessTheWord(value);
    }
}

//Function that displayes the letters from "Guess the word" game
void displayGuessTheWordLetters(string word, string correct)
{
    cout << "\t\t\t\t\t\t\t\t\t\t\t";
    //Displaying the words
    for (size_t i = 0; i < word.size(); i++) cout << "_ ";
    for (size_t i = 0; i < 20 - (word.size()) * 2; i++) cout << " ";
    for (size_t i = 0; i < word.size(); i++) cout << correct[i] << " ";
}

//Function that extract letters for "Guess the word" game
string extractLetters(string str)
{
    int index, temp;
    string holder = str;

    //Swaps random letters
    for (size_t i = 0; i < str.size(); i++)
    {
        index = rand() % str.size();

        temp = str[i];
        str[i] = str[index];
        str[index] = temp;
    }

    //If the letters has not mixed
    while (holder == str) extractLetters(str);

    return str;
}

//The main function for the games
void game()
{
    int gameChoice;

    menuAndOptions();

    cin >> gameChoice;
    playerGameChoice(gameChoice);
}

//Function that displayes "Game Over" if you lose the "Hangman" game and ask you what you want to do next
void gameOver()
{
    system("cls");

    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t" << "           /////////    ///////////   /////          /////   ////////////        ////////////   ///       ///  ////////////  /////////////           \n";
    cout << "\t\t\t\t\t" << "       ////            ///     ///   /// ///      /// ///   ///                 ///      ///   ///       ///  ///           ///       ///             \n";
    cout << "\t\t\t\t\t" << "     ///              ///     ///   ///  ///    ///  ///   ///                 ///      ///   ///       ///  ///           ///       ///             \n";
    cout << "\t\t\t\t\t" << "    ///      //////  ///////////   ///   ///  ///   ///   ////////////        ///      ///   ///       ///  ////////////  ///////////                 \n";
    cout << "\t\t\t\t\t" << "   ///         ///  ///     ///   ///    //////    ///   ///                 ///      ///   ///       ///  ///           ///       ///           \n";
    cout << "\t\t\t\t\t" << "    ////      ///  ///     ///   ///              ///   ///                 ///      ///   ///       ///  ///           ///       ///          \n";
    cout << "\t\t\t\t\t" << "       /////////  ///     ///   ///              ///   ////////////        ////////////    ///////////   ////////////  ///       ///      \n\n\n";

    cout << "\t\t\t\t\t\t" << "     _______________________________________________________________________________________________________________\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++   _____________________________________________________   ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |      W O U L D  Y O U  L I K E  T O  P L A Y        |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |             A N O T H E R  G A M E  ?               |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (1) P L A Y   A G A I N                  |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (2) R E T U R N  T O  T H E  M E N U     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |_____________________________________________________|  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |++++++++++++++++++++++++++                                                           ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t\t" << "    |_______________________________________________________________________________________________________________|\n";

    int answer;
    cin >> answer;
    system("cls");

    if (answer == 1) hangmanGame();
    else if (answer == 2)
    {
        int gameChoice;

        system("cls");
        menuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
}

//"Guess the word" game
void guessTheWord()
{
    string wordBank[] = { "apple", "juice", "banana", "bottle", "hard", "table", "chair", "close", "fox", "person" };
    string word1, word2, word3, word4, word5;
    string placer1, placer2, placer3, placer4, placer5;

    randomGive(&word1, &word2, &word3, &word4, &word5, wordBank);

    placer1 = word1;
    placer2 = word2;
    placer3 = word3;
    placer4 = word4;
    placer5 = word5;

    string choice;

    int counter = 0;

    //Extract the letters for each word
    string correct1 = extractLetters(word1);
    string correct2 = extractLetters(word2);
    string correct3 = extractLetters(word3);
    string correct4 = extractLetters(word4);
    string correct5 = extractLetters(word5);


    displayGuessTheWordLetters(word1, correct1);
    cout << endl << endl;

    displayGuessTheWordLetters(word2, correct2);
    cout << endl << endl;

    displayGuessTheWordLetters(word3, correct3);
    cout << endl << endl;

    displayGuessTheWordLetters(word4, correct4);
    cout << endl << endl;

    displayGuessTheWordLetters(word5, correct5);
    cout << endl << endl;

    //In game
    while (counter < 5)
    {
        getline(cin, choice);
        system("cls");

        cout << "\n\n\n\n\n";
        guessTheWordSign();

        cout << "\n\n\n\n\n";
        inGameMenuForGuessTheWord();

        if (choice == word1 && placer1 != "0")
        {
            counter++;
            placer1 = "0";
        }
        else if (choice == word2 && placer2 != "0")
        {
            counter++;
            placer2 = "0";
        }
        else if (choice == word3 && placer3 != "0")
        {
            counter++;
            placer3 = "0";
        }
        else if (choice == word4 && placer4 != "0")
        {
            counter++;
            placer4 = "0";
        }
        else if (choice == word5 && placer5 != "0")
        {
            counter++;
            placer5 = "0";
        }

        if (placer1 == "0")
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (size_t i = 0; i < word1.size(); i++) cout << word1[i] << " ";
        }
        else displayGuessTheWordLetters(word1, correct1);
        cout << endl << endl;

        if (placer2 == "0")
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (size_t i = 0; i < word2.size(); i++) cout << word2[i] << " ";
        }
        else displayGuessTheWordLetters(word2, correct2);
        cout << endl << endl;

        if (placer3 == "0")
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (size_t i = 0; i < word3.size(); i++) cout << word3[i] << " ";
        }
        else displayGuessTheWordLetters(word3, correct3);
        cout << endl << endl;

        if (placer4 == "0")
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (size_t i = 0; i < word4.size(); i++) cout << word4[i] << " ";
        }
        else displayGuessTheWordLetters(word4, correct4);
        cout << endl << endl;

        if (placer5 == "0")
        {
            cout << "\t\t\t\t\t\t\t\t\t\t\t";
            for (size_t i = 0; i < word5.size(); i++) cout << word5[i] << " ";
        }
        else displayGuessTheWordLetters(word5, correct5);
        cout << endl << endl;

        if (counter == 5 || choice == "leave" || choice == "Leave" || choice == "LEAVE")
        {
            if (counter == 5)
            {
                system("cls");
                winMenuGuessTheWord();
                break;
            }

            else
            {
                int gameChoice;

                system("cls");
                menuAndOptions();
                
                cin >> gameChoice;
                playerGameChoice(gameChoice);
                break;
            }

            cin >> choice;
            checkGuessTheWord(choice);
        }
        cout << "\n\n\n";
        leaveMenuForGuessTheWord();
    }
}

//Menu and options for "Guess the word" game
void guessTheWordMenuAndOptions()
{
    char choice;

    cout << "\n\n\n\n\n";
    guessTheWordSign();
    cout << "\n\n\n";

    cout << setw(166) << "_______________________________________________________________________________________________________________________________________\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *     _____________________________________________________     *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * |      C  H  O  O  S  E   A N   O  P  T  I  O  N      | *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * |              (1) P L A Y  G A M E                   | *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * |              (2) H O W  T O  P L A Y                | *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * |              (3) B A C K  T O  M E N U              | *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *    |_____________________________________________________|    *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     *                                                         *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "                             |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "                             |_______________________________________________________________________________________________________________________________________|\n";

    cin >> choice;

    if (choice == '1')
    {
        system("cls");
        guessTheWord();
    }
    else if (choice == '2') guessTheWordRules();
    else if (choice == '3')
    {
        int GameChoice;

        system("cls");
        menuAndOptions();

        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
    else cout << "Invalid Move. Please Try Again.\n";
}

//Rules for the "Guess the word" game
void guessTheWordRules()
{
    system("cls");
    cout << "\n\n\n";
    rulesSign();

    cout << "\n\n\n";
    cout << setw(149) << "__________________________________________________________________________________________________________________\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()   ________________________________________________________________________________   ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                              H O W  T O  P L A Y                               |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            1) You'll see bunch of words with letters out of order              |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               and your task is to arrange them. For example if the             |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               word is BOTTLE you may see at as ( t t o b e l ) and             |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                           your task is to guess it.                            |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            2) If you don't guess the word from the first time you              |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               have endless chances to guess it.                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            3) Because of the fact that you have endless chances                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               when you type number or another symbol, the console              |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               will delete what you have written and you will have              |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               to start typing again.                                           |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            4) If you guess all the words you will see a message                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               saying that you have won.                                        |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            5) You can always leave the game if you type -leave-                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            6) Enjoy the game :)                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |________________________________________________________________________________|  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|__________________________________________________________________________________________________________________|\n";
    cout << "\n                                                      I F  Y O U  W A N T  T O  R E T U R N  T O  T H E  M E N U  T Y P E  return\n";

    string returnWord;
    cin >> returnWord;

    if (returnWord == "return" || returnWord == "RETURN")
    {
        int gameChoice;

        system("cls");
        guessTheWordMenuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
    else
    {
        cout << "Try again!";
        guessTheWordRules();
    }
}

//Title for "Guess the word" game
void guessTheWordSign()
{
    cout << "             /////////  ///       ///  ////////////  /////////////   /////////////     /////////////////  //        ///  ////////////      ///           ///  /////////////  /////////////  //////////     \n";
    cout << "         ////          ///       ///  ///           ///             ///                      ///         ///       ///  ///               ///           ///  ///       ///  ///       ///  ///      ///    \n";
    cout << "      ///             ///       ///  ///           ///             ///                      ///         ///       ///  ///               ///           ///  ///       ///  ///       ///  ///       ///    \n";
    cout << "     ///     //////  ///       ///  ////////////  /////////////   /////////////            ///         /////////////  ////////////      ///   ////    ///  ///       ///  ///////////    ///        ///    \n";
    cout << "    ///        ///  ///       ///  ///                     ///             ///            ///         ///       ///  ///               /// ///   /// ///  ///       ///  ///      ///   ///        ///     \n";
    cout << "     ////     ///  ///       ///  ///                     ///             ///            ///         ///       ///  ///               //////     //////  ///       ///  ///      ///   ///        ///      \n";
    cout << "       /////////  /////////////  ////////////   ////////////   /////////////            ///         ///       ///  ////////////      /////       /////  /////////////  ///      ///   ////////////     \n\n\n";
}

//The "Hangman" game
void hangmanGame()
{
    system("cls");
    cout << "\n\n\n\n\n";
    hangmanSign();
    cout << "\n\n\n\n\n\n\n";
    inGameMenuForHangman();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    string wordBank[] = { "apple", "juice", "banana", "bottle", "hard", "table", "chair", "close", "fox", "person" };
    string word = randomize(wordBank), holder = word;
    char playerChoice;
    size_t flag = 0;

    for (size_t i = 1; i < word.size() - 1; i++) holder[i] = '_';
    cout << "\t\t\t\t\t\t\t";

    for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
    cout << endl;

    int mistake = 0;

    //In game
    do
    {
        cin >> playerChoice;
        system("cls");

        if ((playerChoice >= 'a' && playerChoice <= 'z') || (playerChoice >= 'A' && playerChoice <= 'Z'))
        {

            cout << "\n\n\n\n\n";
            hangmanSign();
            cout << "\n\n\n\n\n\n\n";

            int counter = 0;
            inGameMenuForHangman();
            cout << "\n\n\n\n";

            for (size_t i = 1; i < word.size() - 1; i++)
            {

                if (word[i] == playerChoice && holder[i] == '_')
                {
                    holder[i] = word[i];
                    flag++;
                }
                else counter++;
            }
            if (counter == word.size() - 2) mistake++;

            if (mistake == 0) cout << "\n\n\n\n\n\n\n\n\n\n";
            else hangmanStructure(mistake);

            cout << "   \t\t\t\t\t\t\t";

            for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
        }
        else
        {
            cout << "\n\n\n\n\n";
            hangmanSign();
            cout << "\n\n\n\n\n";

            if (mistake == 0) cout << "\n\n\n\n\n\n\n\n\n\n";
            else hangmanStructure(mistake);

            cout << "   \t\t\t\t\t\t\t";
            for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
            cout << "\n\n    Invalid Move. Please Try Again.\n";
        }
        cout << endl;

    } while ((flag + 2) != word.size() && mistake < 9);

    for (size_t i = 0; i < word.size(); i++)
    {
        if (mistake < 9)
        {
            system("cls");
            winMenuHangman();

            break;
        }
        else
        {
            char choice;
            string sumWord;

            for (size_t i = 0; i < word.size(); i++)
            {
                sumWord += toupper(word[i]);
                sumWord += " ";
            }

            cout << "\n\n\n\n";
            cout << "S O R R Y, Y O U  L O S E !  T H E  W O R D  W A S  " << sumWord << endl;
            cout << "P R E S S  1  T O  S H O W  T H E  D I A L O G  B O X" << endl;


            cin >> choice;
            hangmanLost(choice);
        }
    }
}

void hangmanLost(char choice)
{
    cin >> choice;

    if (choice == '1')
    {
        gameOver();
    }
    else
    {
        cout << "I N V A L I D  I N P U T.  P L E A S E  T R Y  A G A I N !";
        hangmanLost(choice);
    }
}

//Menu and options for the "Hangman" game
void hangmanMenuAndOptions()
{
    char choice;

    cout << "\n\n\n\n\n";
    hangmanSign();

    cout << setw(152) << "_______________________________________________________________________________________________________________________________________\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *     _____________________________________________________     *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * |      C  H  O  O  S  E   A N   O  P  T  I  O  N      | *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * |              (1) P L A Y  G A M E                   | *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * |              (2) H O W  T O  P L A Y                | *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * |              (3) B A C K  T O  M E N U              | *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *    |                                                     |    *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *    |_____________________________________________________|    *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     *                                                         *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |   *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *       *   |\n";
    cout << "               |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *|\n";
    cout << "               |_______________________________________________________________________________________________________________________________________|\n";

    cin >> choice;

    if (choice == '1')
    {
        system("cls");
        hangmanGame();
    }
    else if (choice == '2') hangmanRules();
    else if (choice == '3')
    {
        int gameChoice;

        system("cls");
        menuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
    else cout << "Invalid Move. Please Try Again.\n";
}

//Rules for the "Hangman" game
void hangmanRules()
{
    system("cls");
    cout << "\n\n\n";
    rulesSign();
    cout << "\n\n\n";
    cout << setw(149) << "__________________________________________________________________________________________________________________\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()   ________________________________________________________________________________   ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                              H O W  T O  P L A Y                               |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            1) You need to enter a letter that might be in the word.            |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            2) Whenever you guess a letter that is in the secret word,          |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               the host fills it into the blank where it occurs.                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               For example, if the word is ZIPPER and the player guesses E      |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               then the host will fill in the 5th blank with an E :             |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                ( _ _ _ _ e _ ).                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            3) If the player guesses a letter that repeats, fill in both        |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               letters. If they guess P you would have to fill in both Ps:      |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                ( _ _ p p e _ ).                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            4) If you input a letter that is not in the secret word,            |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               a line from the hangman will appear. NOTE_1: This is             |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               counted as a mistake.                                            |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            5) You must not enter a number or a symbol, otherwise the           |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               console will display the message - Invalid move.Please           |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               try again - and you will have to enter a new letter.             |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |               NOTE_2: This action will not count as a mistake.                 |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            6) If you guess the word for less than 9 moves, you win.            |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                              Otherwise you lose.                               |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |            7) Enjoy the game :)                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |                                                                                |  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()  |________________________________________________________________________________|  ()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()()|\n";
    cout << setw(150) << "|__________________________________________________________________________________________________________________|\n";

    cout << "\n                                                      I F  Y O U  W A N T  T O  R E T U R N  T O  T H E  M E N U  T Y P E  return\n";

    string returnVariable;
    cin >> returnVariable;

    if (returnVariable == "return" || returnVariable == "RETURN")
    {
        int gameChoice;

        system("cls");
        hangmanMenuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
    else
    {
        cout << "Try again!";
        hangmanRules();
    }
}

//Title for the "Hangman" game
void hangmanSign() 
{
    cout << setw(150) << "        ///       ///    ///////////    //////     ///      /////////     /////          /////    ///////////   //////      ///\n";
    cout << setw(149) << "       ///       ///    ///     ///    /// ///    ///   ////             /// ///      /// ///    ///     ///   /// ///     ///\n";
    cout << setw(148) << "      ///       ///    ///     ///    ///  ///   ///  ///               ///  ///    ///  ///    ///     ///   ///   ///   ///\n";
    cout << setw(147) << "     /////////////    ///////////    ///   ///  ///  ///      //////   ///   ///  ///   ///    ///////////   ///    ///  ///\n";
    cout << setw(146) << "    ///       ///    ///     ///    ///    /// ///  ///         ///   ///    //////    ///    ///     ///   ///     /// ///\n";
    cout << setw(146) << "   ///       ///    ///     ///    ///     //////    ////      ///   ///              ///    ///     ///   ///      ////// \n";
    cout << setw(146) << "  ///       ///    ///     ///    ///      /////        /////////   ///              ///    ///     ///   ///       /////\n\n\n";
}

//Structure of the "Hangman" game
void hangmanStructure(int counter)
{
    system("cls");
    cout << "\n\n\n\n\n";

    hangmanSign();
    cout << "\n\n\n\n\n\n\n";

    inGameMenuForHangman();
    cout << "\n\n\n\n\n";

    if (counter == 1)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 2)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 3)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 4)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 5)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 6)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "/|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "/ |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 7)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(16) << "/|" << "\\" << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(19) << "/ | \\\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 8)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(16) << "/|" << "\\" << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(19) << "/ | \\\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(16) << "/\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(15) << "/\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |\n";
    }
    else if (counter == 9)
    {
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << setw(19) << " _______________\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << " | \n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(18) << "( )\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(16) << "/|" << "\\" << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(19) << "/ | \\\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(17) << "|\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(15) << "/" << setw(2) << "\\" << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << setw(14) << "/" << setw(4) << "\\" << "\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << "  |" << "\n";
    }
}

//"In game" sign for the "Guess the word" game
void inGameMenuForGuessTheWord()
{
    cout << "\t\t\t\t\t\t" << "        _______________________________________________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t\t\t\t" << "       |                                               I N   G A M E                                           | \n";
    cout << "\t\t\t\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |_______________________________________________________________________________________________________| \n";
    cout << "\n\n\n\n\n";
}

//"In game" sign for the "Hangman" game
void inGameMenuForHangman()
{
    cout << "\t\t\t" << "        _______________________________________________________________________________________________________ \n";
    cout << "\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t" << "       |                                               I N   G A M E                                           | \n";
    cout << "\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t" << "       |_______________________________________________________________________________________________________| \n";
    cout << "\n\n\n\n\n";
}

//"Leave the game" instruction
void leaveMenuForGuessTheWord()
{
    cout << "\t\t\t\t\t\t" << "        _______________________________________________________________________________________________________ \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t\t\t\t" << "       |                 I F  Y O U  W A N T  T O  L E A V E  T H E  G A M E, T Y P E  leave                   | \n";
    cout << "\t\t\t\t\t\t" << "       |                                                                                                       | \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |*     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     * *     *| \n";
    cout << "\t\t\t\t\t\t" << "       |   *       *       *       *       *       *       *       *       *       *       *       *       *   | \n";
    cout << "\t\t\t\t\t\t" << "       |_______________________________________________________________________________________________________| \n";
    cout << "\n\n\n\n\n";
}

//The main menu and options
void menuAndOptions()
{
    cout << "\n \n";
    cout << setw(123) << " =================================================================================\n";
    cout << "                                        |                                                                                 |\n";
    cout << "                                        |         /////          /////   ////////////    //////     ///   ///        ///  |\n";
    cout << "                                        |        /// ///      /// ///   ///             /// ///    ///   ///        ///   |\n";
    cout << "                                        |       ///  ///    ///  ///   ///             ///  ///   ///   ///        ///    |\n";
    cout << "                                        |      ///   ///  ///   ///   ////////////    ///   ///  ///   ///        ///     |\n";
    cout << "                                        |     ///    //////    ///   ///             ///    /// ///   ///        ///      |\n";
    cout << "                                        |    ///              ///   ///             ///     //////   ///        ///       |\n";
    cout << "                                        |   ///              ///   ////////////    ///      /////   //////////////        |\n";
    cout << "                                        |                                                                                 |\n";
    cout << setw(122) << "=================================================================================";
    cout << "\n \n \n ";
    cout << setw(148) << "____________________________________________________________________________________________________________________________________\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   _____________________________________________________   ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |      C  H  O  O  S  E   A N   O  P  T  I  O  N      |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |              (1) G U E S S  T H E  W O R D          |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |              (2) H A N G M A N                      |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |              (3) Q U I T                            |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |                                                     |  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |_____________________________________________________|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                                                           ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
    cout << "               |____________________________________________________________________________________________________________________________________|\n";
}

//Function that allowes to choose a game 
void playerGameChoice(int gameChoice)
{
    if (gameChoice == 1)
    {
        system("cls");
        guessTheWordMenuAndOptions();
    }
    else if (gameChoice == 2)
    {
        system("cls");
        hangmanMenuAndOptions();
    }
    else if (gameChoice == 3) 
    {
        system("cls");
        system("exit");
    }
    else 
    {
        int gameChoice;

        cout << "Invalid move. Please try again: ";
        cin >> gameChoice;

        playerGameChoice(gameChoice);
    }
}

//Function that randomizes the letters in the "Guess the word" game
void randomGive(string* word1, string* word2, string* word3, string* word4, string* word5, string wordBank[])
{
    guessTheWordSign();
    srand(time(NULL));

    int index1, index2, index3, index4, index5;
    index1 = rand() % 10;

    while (true)
    {
        index2 = rand() % 10;
        if (index2 != index1) break;
    }
    while (true)
    {
        index3 = rand() % 10;
        if (index3 != index1 && index3 != index2) break;
    }
    while (true)
    {
        index4 = rand() % 10;
        if (index4 != index1 && index4 != index2 && index4 != index3) break;
    }
    while (true)
    {
        index5 = rand() % 10;
        if (index5 != index1 && index5 != index2 && index5 != index3 && index5 != index4) break;
    }

    *word1 = wordBank[index1];
    *word2 = wordBank[index2];
    *word3 = wordBank[index3];
    *word4 = wordBank[index4];
    *word5 = wordBank[index5];
}

//Function that randomizes the words for the "Hangman" game
string randomize(string words[])
{
    srand(time(NULL));

    return words[rand() % 4];
}

//Rules title
void rulesSign()
{
    cout << setw(132) << "       //////////////   ///        ///   ///          //////////   ////////// \n";
    cout << setw(132) << "      ///        ///   ///        ///   ///          ///          ///         \n";
    cout << setw(132) << "     ///        ///   ///        ///   ///          ///          ///          \n";
    cout << setw(132) << "    ////////////     ///        ///   ///          //////////   //////////    \n";
    cout << setw(132) << "   ///       ///    ///        ///   ///          ///                 ///     \n";
    cout << setw(132) << "  ///       ///    ///        ///   ///          ///                 ///      \n";
    cout << setw(132) << " ///       ///    //////////////   //////////   //////////   //////////       \n";
}

void winMenuHangman()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t" << "                    ///      ///  /////////////  ///       ///          ///           ///  ////  //////     ///    \n";
    cout << "\t\t\t\t\t" << "                   ///      ///  ///       ///  ///       ///          ///           ///  ////  /// ///    ///     \n";
    cout << "\t\t\t\t\t" << "                  ///      ///  ///       ///  ///       ///          ///           ///  ////  ///  ///   ///      \n";
    cout << "\t\t\t\t\t" << "                 ////////////  ///       ///  ///       ///          ///   ////    ///  ////  ///   ///  ///       \n";
    cout << "\t\t\t\t\t" << "                         ///  ///       ///  ///       ///          /// ///   /// ///  ////  ///    /// ///        \n";
    cout << "\t\t\t\t\t" << "                        ///  ///       ///  ///       ///          //////     //////  ////  ///     //////         \n";
    cout << "\t\t\t\t\t" << "                //////////  /////////////  /////////////          /////       /////  ////  ///      /////      \n\n\n";

    cout << "\t\t\t\t\t" << "     _______________________________________________________________________________________________________________\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++   _____________________________________________________   ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |      W O U L D  Y O U  L I K E  T O  P L A Y        |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |             A N O T H E R  G A M E  ?               |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (1) P L A Y   A G A I N                  |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (2) R E T U R N  T O  T H E  M E N U     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |_____________________________________________________|  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++                                                           ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |_______________________________________________________________________________________________________________|\n";

    char answer;
    cin >> answer;

    system("cls");

    if (answer == '1') hangmanGame();
    else if (answer == '2')
    {
        int gameChoice;

        system("cls");
        menuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
}

//Function that displayes "You win" and ask us what we want to do next
void winMenuGuessTheWord()
{
    cout << "\n\n\n\n\n";
    cout << "\t\t\t\t\t" << "                    ///      ///  /////////////  ///       ///          ///           ///  ////  //////     ///    \n";
    cout << "\t\t\t\t\t" << "                   ///      ///  ///       ///  ///       ///          ///           ///  ////  /// ///    ///     \n";
    cout << "\t\t\t\t\t" << "                  ///      ///  ///       ///  ///       ///          ///           ///  ////  ///  ///   ///      \n";
    cout << "\t\t\t\t\t" << "                 ////////////  ///       ///  ///       ///          ///   ////    ///  ////  ///   ///  ///       \n";
    cout << "\t\t\t\t\t" << "                         ///  ///       ///  ///       ///          /// ///   /// ///  ////  ///    /// ///        \n";
    cout << "\t\t\t\t\t" << "                        ///  ///       ///  ///       ///          //////     //////  ////  ///     //////         \n";
    cout << "\t\t\t\t\t" << "                //////////  /////////////  /////////////          /////       /////  ////  ///      /////      \n\n\n";

    cout << "\t\t\t\t\t" << "     _______________________________________________________________________________________________________________\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++   _____________________________________________________   ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |      W O U L D  Y O U  L I K E  T O  P L A Y        |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |             A N O T H E R  G A M E  ?               |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (1) P L A Y   A G A I N                  |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |            (2) R E T U R N  T O  T H E  M E N U     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |                                                     |  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++  |_____________________________________________________|  ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |++++++++++++++++++++++++++                                                           ++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++|\n";
    cout << "\t\t\t\t\t" << "    |_______________________________________________________________________________________________________________|\n";

    char answer;
    cin >> answer;

    system("cls");

    if (answer == '1') guessTheWord();
    else if (answer == '2')
    {
        int gameChoice;

        system("cls");
        menuAndOptions();

        cin >> gameChoice;
        playerGameChoice(gameChoice);
    }
}

//The main game
int main()
{
    game();
}