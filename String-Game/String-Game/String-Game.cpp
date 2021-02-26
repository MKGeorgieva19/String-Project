#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "hangManStructure.h"
#include "randomize.h"
#include "hangManGame.h"
#include "newGame.h"
#include "menuAndOptions.h"
#include "hangmanMenuAndOptions.h"
#include "playerGameChoice.h"
#include "guessTheWordMenuAndOptions.h"
#include "Win.h"
#include "gameOver.h"

using namespace std;

void checkGuessTheWord(string value);
void guessTheWord();

string randomize(string words[])
{
    srand(time(NULL));
    return words[rand() % 4];
}

void hangManSign() {
    cout << setw(150) << "        ///       ///    ///////////    //////     ///      /////////     /////          /////    ///////////   //////      ///\n";
    cout << setw(149) << "       ///       ///    ///     ///    /// ///    ///   ////             /// ///      /// ///    ///     ///   /// ///     ///\n";
    cout << setw(148) << "      ///       ///    ///     ///    ///  ///   ///  ///               ///  ///    ///  ///    ///     ///   ///   ///   ///\n";
    cout << setw(147) << "     /////////////    ///////////    ///   ///  ///  ///      //////   ///   ///  ///   ///    ///////////   ///    ///  ///\n";
    cout << setw(146) << "    ///       ///    ///     ///    ///    /// ///  ///         ///   ///    //////    ///    ///     ///   ///     /// ///\n";
    cout << setw(146) << "   ///       ///    ///     ///    ///     //////    ////      ///   ///              ///    ///     ///   ///      ////// \n";
    cout << setw(146) << "  ///       ///    ///     ///    ///      /////        /////////   ///              ///    ///     ///   ///       /////\n\n\n";
}

void rulesSign() {
    cout << setw(135) << "       //////////////   ///        ///   ///          //////////   ////////// \n";
    cout << setw(135) << "      ///        ///   ///        ///   ///          ///          ///         \n";
    cout << setw(135) << "     ///        ///   ///        ///   ///          ///          ///          \n";
    cout << setw(135) << "    ////////////     ///        ///   ///          //////////   //////////    \n";
    cout << setw(135) << "   ///       ///    ///        ///   ///          ///                 ///     \n";
    cout << setw(135) << "  ///       ///    ///        ///   ///          ///                 ///      \n";
    cout << setw(135) << " ///       ///     ///////////     //////////   //////////   //////////       \n";
}

void hangManStructure(int counter) {
    system("cls");
    cout << "\n\n\n\n\n";
    hangManSign();
    cout << "\n\n\n\n\n\n\n";


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

        //4
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

        //6
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

        //7
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

        //8
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


        //9 - End (Game Over)
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
    if (answer == 1) {
        hangManGame();
    }
    else if (answer == 2) {
        system("cls");
        menuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
}

void hangManGame() {

    cout << "\n\n\n\n\n";
    hangManSign();
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";

    string wordBank[] = { "apple", "banana", "circle", "notebook" };
    string word = randomize(wordBank), holder = word;
    char playerChoice;
    size_t flag = 0;

   
    for (size_t i = 1; i < word.size() - 1; i++) {
        holder[i] = '_';
    }
    cout << "\t\t\t\t\t\t\t";
    for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
    cout << endl;
    int mistake = 0;
    do {
        cin >> playerChoice;
        system("cls");

        if ((playerChoice >= 'a' && playerChoice <= 'z') || (playerChoice >= 'A' && playerChoice <= 'Z')) {
            
            cout << "\n\n\n\n\n";
            hangManSign();

            cout << "\n\n\n\n\n\n";
           
            int counter = 0;
            for (size_t i = 1; i < word.size() - 1; i++) {
                if (word[i] == playerChoice && holder[i] == '_') {
                    holder[i] = word[i];
                    flag++;
                }
                else counter++;
            }
            if (counter == word.size() - 2) mistake++;
            if (mistake == 0) cout << "\n\n\n\n\n\n\n\n\n\n";
            else hangManStructure(mistake);
            cout << "   \t\t\t\t\t\t\t";
            for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
        }
        else {
            cout << "\n\n\n\n\n";
            hangManSign();
            cout << "\n\n\n\n\n";
            if (mistake == 0) cout << "\n\n\n\n\n\n\n\n\n\n";
            else hangManStructure(mistake);
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
            Win();
        }
        else
        {
            int choice;
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
            if (choice == 1) {
                gameOver(); break;
            }
            else cout << "I N V A L I D  I N P U T.  P L E A S E  T R Y  A G A I N !";
          

        }
    }
   
   
   
}

void Win()
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
    if (answer == '1') {
        hangManGame();
    }
    else if (answer == '2') {
        system("cls");
        menuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }

}

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

void randomGive(string* w1, string* w2, string* w3, string* w4, string* w5, string bank[]) {
    srand(time(NULL));
    int a, b, c, d, e;
    a = rand() % 10;
    while (true) {
        b = rand() % 10;
        if (b != a) break;
    }
    while (true) {
        c = rand() % 10;
        if (c != a && c != b) break;
    }
    while (true) {
        d = rand() % 10;
        if (d != a && d != b && d != c) break;

    }
    while (true) {
        e = rand() % 10;
        if (e != a && e != b && e != c && e != d) break;
    }
    *w1 = bank[a];
    *w2 = bank[b];
    *w3 = bank[c];
    *w4 = bank[d];
    *w5 = bank[e];
}

string extract(string str) {
    int index, temp;
    string holder = str;
    for (size_t i = 0; i < str.size(); i++) {
        index = rand() % str.size();
        temp = str[i];
        str[i] = str[index];
        str[index] = temp;
    }
    while (holder == str) {
        extract(str);
    }
    return str;
}

void checkGuessTheWord(string value) {
    if (value == "1") guessTheWord();
    else if (value == "2") {
        system("cls");
        guessTheWordMenuAndOptions();
    }
    else {
        cout << "Invalid move. Please try again: ";
        cin >> value;
        checkGuessTheWord(value);
    }
}

void displayGuessTheWordLetters(string word, string correct) {
    for (size_t i = 0; i < word.size(); i++) cout << "_ ";
    for (size_t i = 0; i < 20 - (word.size()) * 2; i++) cout << " ";
    for (size_t i = 0; i < word.size(); i++) cout << correct[i] << " ";
}

void guessTheWord() {
    string bank[] = { "apple", "juice", "banana", "bottle", "hard", "table", "chair", "close", "fox", "person" };
    string word1, word2, word3, word4, word5;
    string placer1, placer2, placer3, placer4, placer5;

    randomGive(&word1, &word2, &word3, &word4, &word5, bank);

    placer1 = word1;
    placer2 = word2;
    placer3 = word3;
    placer4 = word4;
    placer5 = word5;

    string choice;

    int counter = 0;

    string correct1 = extract(word1);
    string correct2 = extract(word2);
    string correct3 = extract(word3);
    string correct4 = extract(word4);
    string correct5 = extract(word5);

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

    while (counter < 5) {
        getline(cin, choice);
        system("cls");

        if (choice == word1 && placer1 != "0") {
            counter++;
            placer1 = "0";
        }
        else if (choice == word2 && placer2 != "0") {
            counter++;
            placer2 = "0";
        }
        else if (choice == word3 && placer3 != "0") {
            counter++;
            placer3 = "0";
        }
        else if (choice == word4 && placer4 != "0") {
            counter++;
            placer4 = "0";
        }
        else if (choice == word5 && placer5 != "0") {
            counter++;
            placer5 = "0";
        }


        if (placer1 == "0") for (size_t i = 0; i < word1.size(); i++) cout << word1[i] << " ";
        else displayGuessTheWordLetters(word1, correct1);
        cout << endl << endl;

        if (placer2 == "0") for (size_t i = 0; i < word2.size(); i++) cout << word2[i] << " ";
        else displayGuessTheWordLetters(word2, correct2);
        cout << endl << endl;

        if (placer3 == "0") for (size_t i = 0; i < word3.size(); i++) cout << word3[i] << " ";
        else displayGuessTheWordLetters(word3, correct3);
        cout << endl << endl;

        if (placer4 == "0") for (size_t i = 0; i < word4.size(); i++) cout << word4[i] << " ";
        else displayGuessTheWordLetters(word4, correct4);
        cout << endl << endl;

        if (placer5 == "0") for (size_t i = 0; i < word5.size(); i++) cout << word5[i] << " ";
        else displayGuessTheWordLetters(word5, correct5);
        cout << endl << endl;

        if (counter == 5 || choice =="leave") {
            if (counter == 5)cout << "CONGRATULATIONS YOU WON!!!" << endl;
            cout << "[1] Play again [2] Menu" << endl;
            cout << "Your next option here: ";

            cin >> choice;
            checkGuessTheWord(choice);
        }

    }
}

void guessTheWordRules() {
    system("cls");
    rulesSign();
    cout << "\n\n\n";
    cout << "                                                      _________________________________________________________________________________\n";
    cout << "                                                      |                                                                               |\n";
    cout << "                                                      |  1) You'll see bunch of words with letters out of order and your task         |\n";
    cout << "                                                      |  is to arrange them. For example if the word is BOTTLE you may                |\n";
    cout << "                                                      |  see at as ( t t o b e l ) and your task is to guess it.                      |\n";
    cout << "                                                      |  2) If you don't guess the word from the first time you have endless          |\n";;
    cout << "                                                      |  chances to guess it.                                                         |\n";
    cout << "                                                      |  3) Because of the fact that you have endless chances when you                |\n";
    cout << "                                                      |  type number or another symbol, the console will delete what you              |\n";
    cout << "                                                      |  have written and you will have to start typing again.                        |\n";
    cout << "                                                      |  4) If you guess all the words you will see a message saying that             |\n";
    cout << "                                                      |  you have won.                                                                |\n";
    cout << "                                                      |  5) You can always leave the game if you type -leave-                         |\n";
    cout << "                                                      |  5) Enjoy the game :)                                                         |\n";
    cout << "                                                      |_______________________________________________________________________________|\n";

    cout << "\n                                                      I F  Y O U  W A N T  T O  R E T U R N  T O  T H E  M E N U  T Y P E  -R E T U R N-\n";
    string returnWord;
    cin >> returnWord;
    if (returnWord == "return" || returnWord == "RETURN") {
        system("cls");
        guessTheWordMenuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
    else {
        cout << "Try again!";
        guessTheWordRules();
    }

}

void guessTheWordMenuAndOptions()
{

    char choice;

    cout << "\n\n\n\n\n";
    cout << "             /////////  ///       ///  ////////////  /////////////   /////////////     /////////////////  //        ///  ////////////      ///           ///  /////////////  /////////////  //////////     \n";
    cout << "         ////          ///       ///  ///           ///             ///                      ///         ///       ///  ///               ///           ///  ///       ///  ///       ///  ///      ///    \n";
    cout << "      ///             ///       ///  ///           ///             ///                      ///         ///       ///  ///               ///           ///  ///       ///  ///       ///  ///       ///    \n";
    cout << "     ///     //////  ///       ///  ////////////  /////////////   /////////////            ///         /////////////  ////////////      ///   ////    ///  ///       ///  ///////////    ///        ///    \n";
    cout << "    ///        ///  ///       ///  ///                     ///             ///            ///         ///       ///  ///               /// ///   /// ///  ///       ///  ///      ///   ///        ///     \n";
    cout << "     ////     ///  ///       ///  ///                     ///             ///            ///         ///       ///  ///               //////     //////  ///       ///  ///      ///   ///        ///      \n";
    cout << "       /////////  /////////////  ////////////   ////////////   /////////////            ///         ///       ///  ////////////      /////       /////  /////////////  ///      ///   ////////////     \n\n\n";

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
    if (choice == '1') {
        system("cls");
        guessTheWord();
    }
    else if (choice == '2') {
        guessTheWordRules();
    }
    else if (choice == '3') {
        system("cls");
        menuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
    else cout << "Invalid Move. Please Try Again.\n";

}

void hangmanRules() {
    system("cls");
    rulesSign();
    cout << "\n\n\n";
    cout << "                                                      _________________________________________________________________________________\n";
    cout << "                                                      |                                                                               |\n";
    cout << "                                                      |  1) You need to enter a letter that might be in the word.                     |\n";
    cout << "                                                      |  2) Whenever you guess a letter that is in the secret word,                   |\n";
    cout << "                                                      |  the host fills it into the blank where it occurs.                            |\n";
    cout << "                                                      |  For example, if the word is ZIPPER and the players guess E                   |\n";;
    cout << "                                                      |  then the host will fill in the 5th blank with an E : ( _ _ _ _ e _ ).        |\n";
    cout << "                                                      |  3) If the players guess a letter that repeats, fill in both letters.         |\n";
    cout << "                                                      |  If they guess P you would have to fill in both Ps: ( _ _ p p e _ ).          |\n";
    cout << "                                                      |  4) If you input a letter that is not in the secret word, a line from         |\n";
    cout << "                                                      |  he hangman will appear. NOTE_1: This is counted as a mistake.                |\n";
    cout << "                                                      |  5) You must not enter a number or a symbol, otherwise the console            |\n";
    cout << "                                                      |  will display the message - Invalid move.Please try again - and you           |\n";
    cout << "                                                      |  will have to enter a new letter.                                             |\n";
    cout << "                                                      |  NOTE_2: This action will not count as a mistake.                             |\n";
    cout << "                                                      |  6) If you guess the word for less than 9 moves, you win. Otherwise you lose. |\n";
    cout << "                                                      |  7) Enjoy the game :)                                                         |\n";
    cout << "                                                      |_______________________________________________________________________________|\n";

    cout << "\n                                                      I F  Y O U  W A N T  T O  R E T U R N  T O  T H E  M E N U  T Y P E  -R E T U R N-\n";
    string returnVariable;
    cin >> returnVariable;
    if (returnVariable == "return" || returnVariable == "RETURN") {
        system("cls");
        hangmanMenuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
    else {
        cout << "Try again!";
        hangmanRules();
    }
}

void hangmanMenuAndOptions()
{
    char choice;


    cout << "\n\n\n\n\n";
    hangManSign();

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

    if (choice == '1') {
        system("cls");
        hangManGame();
    }
    else if (choice == '2') {
        hangmanRules();
    }
    else if (choice == '3') {
        system("cls");
        menuAndOptions();
        int GameChoice;
        cin >> GameChoice;
        playerGameChoice(GameChoice);
    }
    else cout << "Invalid Move. Please Try Again.\n";
}

void playerGameChoice(int GameChoice)
{
    if (GameChoice == 1)
    {
        system("cls");
        guessTheWordMenuAndOptions();
    }
    else if (GameChoice == 2)
    {
        system("cls");
        hangmanMenuAndOptions();
    }
    else if (GameChoice == 3)
    {
        cout << " ";
    }
}

int main()
{
    menuAndOptions();
    int GameChoice;
    cin >> GameChoice;
    playerGameChoice(GameChoice);
}