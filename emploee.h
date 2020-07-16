#ifndef EMPLOEE_H
#define EMPLOEE_H
#include "person.h"
#include "mymathfunctions.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

/*!
    \brief working with emploees positions

    contain object Emploee with name, age, position and salary parameters
    contain class for work with data file emploees
*/
class Emploee: private Person
{
public:
    Emploee(string inName, int inAge, string inPosition, int inSalary);

    string getName();
    int getAge();
    string getPosition();
    int getSalary();


    /*!
        \brief functions for work with data file Emploees

        Contains many functions for editing emploees data file
        Adds, deletes, searches, and displays records
    */
    class dataFileSearch
    {
    public:

        dataFileSearch();

        void setSearchString(string setString);

        /*!
         * \brief finds entries based on the entered name
         */
        void searchRecordByName();

        /*!
         * \brief finds entries based on the entered area age
         *
         * Search and show record that in [start, end] area
         */
        void searchRecordByAge(int startArea, int endArea);

        /*!
         * \brief finds entries based on the entered position
         */
        void searchRecordByPosition();

        /*!
         * \brief finds entries based on the entered area salary
         *
         * Search and show record that in [start, end] area
         */
        void searchRecordBySalary(int startArea, int endArea);

        /*!
         * \brief add position to file
         *
         * add data of current object to data file
         */
        void addRecord(Emploee worker);

        /*!
         * \brief display all records
         *
         * display all record in data file
         * make warning if file is empty
         */
        void showAllRecordsEmploee();

        /*!
         * \brief delete positions from file
         *
         * delete all positions in data file that are similar with input object
         */
        void deleteRecord(Emploee worker);

    private:
        string searchString;///<The substring to search for in the file
    };

private:
    string position;
    int salary;
};

#endif // EMPLOEE_H
