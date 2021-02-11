#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>
#include "hangManGame.h"
#include "menuAndOptions.h"
#include "playerGameChoice.h"
#include "hangmanMenuAndOptions.h"
#include "randomize.h"
#include "hangManStructure.h"


using namespace std;

string randomize(string words[])
{
    srand(time(NULL));
    return words[rand() % 4];
}

void hangManStructure(int counter) {
    if (counter == 1)
    {
        //1
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 2)
    {
        //2
        cout << setw(16) << " _______________\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 3)
    {
        //3
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 4)
    {
        //4
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 5)
    {
        //5
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 6)
    {
        //6
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(17) << "/|\n";
        cout << "|" << setw(17) << "/ |\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }

    else if (counter == 7)
    {
        //7
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(16) << "/|" << "\\" << "\n";
        cout << "|" << setw(19) << "/ | \\\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|\n";
        cout << "|\n";
        cout << "|\n";
    }


    else if (counter == 8)
    {
        //8
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(16) << "/|" << "\\" << "\n";
        cout << "|" << setw(19) << "/ | \\\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(16) << "/\n";
        cout << "|" << setw(15) << "/\n";
        cout << "|\n";
    }

    else if (counter == 9)
    {
        //9 - End (Game Over)
        cout << setw(16) << " _______________\n";
        cout << "|" << setw(18) << " | \n";
        cout << "|" << setw(18) << "( )\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(16) << "/|" << "\\" << "\n";
        cout << "|" << setw(19) << "/ | \\\n";
        cout << "|" << setw(17) << "|\n";
        cout << "|" << setw(15) << "/" << setw(2) << "\\" << "\n";
        cout << "|" << setw(14) << "/" << setw(4) << "\\" << "\n";
        cout << "|" << "\n";
    }
}

void hangManGame() {
    string wordBank[] = { "apple", "banana", "circle", "notebook" };
    string word = randomize(wordBank), holder = word;
    char playerChoice;
    int flag = 0;

    for (size_t i = 1; i < word.size() - 1; i++) {
        holder[i] = '_';
    }
    cout << endl;
    for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
    cout << endl;
    int mistake = 0;
    while ((flag + 2) != word.size()) {
        cin >> playerChoice;
        system("cls");
        hangManStructure(mistake);
        if ((playerChoice >= 'a' && playerChoice <= 'z') || (playerChoice >= 'A' && playerChoice <= 'Z')) {
            int counter = 0;
            for (size_t i = 1; i < word.size() - 1; i++) {
                if (word[i] == playerChoice && holder[i] == '_') {
                    holder[i] = word[i];
                    flag++;
                }
                else  counter++;
            }
            cout << endl;
            if (counter == word.size() - 2) mistake++;
            for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
        }
        else {
            cout << endl;
            for (size_t i = 0; i < word.size(); i++) cout << " " << holder[i];
            cout << "\n Invalid Move. Please Try Again.\n";
        }
        cout << endl;
    }
}

void menuAndOptions()
{
	cout << "\n \n";
	cout << setw(86) << " ============================================================================\n";
	cout << setw(9) << "|" << setw(78) << "|\n";
	cout << "        |        ////         ////   ///////////   /////       ///   ///       ///   |\n";
	cout << "        |      /// ///     /// ///  ///           /// ///     ///   ///       ///    |\n";
	cout << "        |     ///  ///   ///  ///  ///////////   ///   ///   ///   ///       ///     |\n";
	cout << "        |    ///   /// ///   ///  ///           ///     /// ///   ///       ///      |\n";
	cout << "        |   ///    /////    ///  ///////////   ///       /////   /////////////       |\n";
	cout << setw(9) << "|" << setw(78) << "|\n";
	cout << setw(85) << "============================================================================";
	cout << "\n \n \n ";
	cout << setw(59) << "C H O O S E  A N  O P T I O N \n\n";
	cout << setw(42) << "(1) T Y P E  R A C E R" << setw(25) << "(2) H A N G M A N\n\n";
	cout << setw(51) << "(3) Q U I T\n\n";
}

void hangmanMenuAndOptions()
{
    char a;
    

    cout << "\n\n\n\n\n";
    cout << setw(150) << "        ///       ///    ///////////    //////     ///      /////////     /////          /////    ///////////   //////      ///\n";
    cout << setw(149) << "       ///       ///    ///     ///    /// ///    ///   ////             /// ///      /// ///    ///     ///   /// ///     ///\n";
    cout << setw(148) << "      ///       ///    ///     ///    ///  ///   ///  ///               ///  ///    ///  ///    ///     ///   ///   ///   ///\n";
    cout << setw(147) << "     /////////////    ///////////    ///   ///  ///  ///      //////   ///   ///  ///   ///    ///////////   ///    ///  ///\n";
    cout << setw(146) << "    ///       ///    ///     ///    ///    /// ///  ///         ///   ///    //////    ///    ///     ///   ///     /// ///\n";
    cout << setw(146) << "   ///       ///    ///     ///    ///     //////    ////      ///   ///              ///    ///     ///   ///      ////// \n";
    cout << setw(146) << "  ///       ///    ///     ///    ///      /////        /////////   ///              ///    ///     ///   ///       /////\n\n\n";

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

    cin >> a;

    if (a == '1') {
        system("cls");
        hangManGame();
    }
    else if (a == '2') {

    }
    else if (a == '3') {
        menuAndOptions();
    }
    else cout << "Invalid Move. Please Try Again.\n";
}
void playerGameChoice(int GameChoice)
{
	if (GameChoice == 1)
	{
        cout << " ";
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


