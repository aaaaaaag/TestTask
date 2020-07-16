#ifndef INTERACTIVEMENU_H
#define INTERACTIVEMENU_H
#include "emploee.h"
#include"mymathfunctions.h"
using namespace std;


/*!
    \brief Menu class. Organize work with main menu

    \param inputPoint - user point choice

    Contain functions for work with menu.
*/
class InteracrtiveMenu
{
public:

    /*!
        \brief Print main menu choice of points
    */
    void printMenuPoints();

    /*!
        \brief Set user choice in param inputPoint
    */
    void setInputPoint(string str);

    /*!
        \brief Get user inputPoint
    */
    string getInputPoint();

    /*!
        \brief add to file emploee record

        Uses the employee class
        to add an object to the employee data file
    */
    void addPositionEmploee();

    /*!
        \brief Delete from emploee data file record

        Uses the employee class
        to add an object to the employee data file
    */
    void deletePositionEmploee();

    /*!
        \brief Show all records in emploee data file
    */
    void showAllPositionsEmploee();

    /*!
        \brief search in emploee data file by inputPoint

        In enhitance of inputPoint organize different searching
        in emploee data file
    */
    void findPositionEmploee();

    /*!
        \brief Search records by name in emploee data file
    */
    void findPositionEmploeeByName();

    /*!
        \brief Search records by age in emploee data file
    */
    void findPositionEmploeeByAge();

    /*!
        \brief Search records by position in emploee data file
    */
    void findPositionEmploeeByWorkPosition();

    /*!
        \brief Search records by salary in emploee data file
    */
    void findPositionEmploeeBySalary();
private:
    string inputPoint;
};

#endif // INTERACTIVEMENU_H
