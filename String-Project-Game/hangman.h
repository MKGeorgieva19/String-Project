#include <iostream>
#include<iomanip>
using namespace std;

void hangman1()
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

void hangman2()
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

void hangman3()
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

void hangman4()
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

void hangman5()
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

void hangman6()
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

void hangman7()
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


void hangman8()
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
    cout << "|" << setw(14) << "/\n";
}

void hangman9()
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
    cout << "|" << setw(13) << "/" << setw(6) << "\\" << "\n";
}






