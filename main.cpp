#include "interactivemenu.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Welcome to BatExcel " << endl;
    string inputPoint = "1"; ///<///<Digit in menu entered by the user
    while (inputPoint != "5")
    {
        InteracrtiveMenu mainMenu;
        mainMenu.printMenuPoints();
        cout << "\nInput number of your choice: ";
        cin >> inputPoint;
        mainMenu.setInputPoint(inputPoint);
        if (mainMenu.getInputPoint() == "1")
            mainMenu.addPositionEmploee();
        else if (mainMenu.getInputPoint() == "2")
            mainMenu.deletePositionEmploee();
        else if (mainMenu.getInputPoint() == "3")
            mainMenu.showAllPositionsEmploee();
        else if (mainMenu.getInputPoint() == "4")
            mainMenu.findPositionEmploee();
        else
            cout << endl << "Incorrect input" << endl;
    }
    return 0;
}
