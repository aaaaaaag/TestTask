#ifndef INTERACTIVEMENU_H
#define INTERACTIVEMENU_H
#include "emploee.h"
#include"mymathfunctions.h"
using namespace std;

class InteracrtiveMenu
{
public:

    void printMenuPoints();

    void setInputPoint(string str);

    string getInputPoint();

    void addPositionEmploee();

    void deletePositionEmploee();

    void showAllPositionsEmploee();

    void findPositionEmploee();

    void findPositionEmploeeByName();

    void findPositionEmploeeByAge();

    void findPositionEmploeeByWorkPosition();

    void findPositionEmploeeBySalary();
private:
    string inputPoint;
};

#endif // INTERACTIVEMENU_H
