#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
using namespace std;

/*!
 * \brief detect can string be int and do it
 *
 * try to make int from string. Do it if can. return error code
 * error codes
 * 1 - OK. make int from string
 * -1 - too long number in string
 * 0 - string contain not digit symbol
 */
int makeStringDigit(string str, int *intStr);

/*!
    \brief Parent class. Shows inheritance

    Inheritance is shown based on it
    and working with virtual functions
*/
class Person
{
public:
    Person(string inName, int inAge): name(inName), age(inAge)
    {
    }

    /*!
     * \brief display info
     *
     * display all argument of class object (name, age)
     */
    virtual void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }

protected:
    string name;
    int age;
};

/*!
    \brief working with emploees positions

    contain object Emploee with name, age, position and salary parameters
    contain class for work with data file emploees
*/
class Emploee: private Person
{
public:
    Emploee(string inName, int inAge, string inPosition, int inSalary):
        Person(inName, inAge), position(inPosition), salary(inSalary)
    {
    }

    /*!
     * \brief display info
     *
     * display all argument of class object (name, age, position, salary)
     */
    void displayInfo() override
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }

    string getName()
    {
        return name;
    }
    int getAge()
    {
        return age;
    }
    string getPosition()
    {
        return position;
    }
    int getSalary()
    {
        return salary;
    }


    /*!
        \brief functions for work with data file Emploees

        Contains many functions for editing emploees data file
        Adds, deletes, searches, and displays records
    */
    class dataFileSearch
    {
    public:

        dataFileSearch(){}

        void setSearchString(string setString)
        {
            searchString = setString;
        }

        /*!
         * \brief finds entries based on the entered name
         */
        void searchRecordByName()
        {
            ifstream file("data.txt");
            if (!file.is_open())
                cout << "\nThere are no records to show\n";
            else
            {
                string curName, curPosition, curAge, curSalary;
                int countIsSimilar = 0;
                while (file)
                {
                    file >> curName >> curAge >> curPosition >> curSalary;
                    if (file && (curName.find(searchString, 0) == 0))
                    {
                        countIsSimilar++;
                        cout << "============================" << endl;
                        cout << "Name: " << curName << endl;
                        cout << "Age: " << curAge << endl;
                        cout << "Position: " << curPosition << endl;
                        cout << "Salary: " << curSalary << endl;
                    }
                }
                if (countIsSimilar == 0)
                    cout << "\nNo matches\n";
                file.close();
            }
        }

        /*!
         * \brief finds entries based on the entered area age
         *
         * Search and show record that in [start, end] area
         */
        void searchRecordByAge(int startArea, int endArea)
        {
            ifstream file("data.txt");
            if (!file.is_open())
                cout << "\nThere are no records to show\n";
            else
            {
                string curName, curPosition, curAge, curSalary;
                int countIsSimilar = 0, curAgeInt;
                while (file)
                {
                    file >> curName >> curAge >> curPosition >> curSalary;

                    if (file && (makeStringDigit(curAge, &curAgeInt)) &&
                            (curAgeInt >= startArea) && (curAgeInt <= endArea))
                    {
                        countIsSimilar++;
                        cout << "============================" << endl;
                        cout << "Name: " << curName << endl;
                        cout << "Age: " << curAge << endl;
                        cout << "Position: " << curPosition << endl;
                        cout << "Salary: " << curSalary << endl;
                    }
                }
                if (countIsSimilar == 0)
                    cout << "\nNo matches\n";
                file.close();
            }
        }

        /*!
         * \brief finds entries based on the entered position
         */
        void searchRecordByPosition()
        {
            ifstream file("data.txt");
            if (!file.is_open())
                cout << "\nThere are no records to show\n";
            else
            {
                string curName, curPosition, curAge, curSalary;
                int countIsSimilar = 0;
                while (file)
                {
                    file >> curName >> curAge >> curPosition >> curSalary;
                    if (file && (curPosition.find(searchString, 0) == 0))
                    {
                        countIsSimilar++;
                        cout << "============================" << endl;
                        cout << "Name: " << curName << endl;
                        cout << "Age: " << curAge << endl;
                        cout << "Position: " << curPosition << endl;
                        cout << "Salary: " << curSalary << endl;
                    }
                }
                if (countIsSimilar == 0)
                    cout << "\nNo matches\n";
                file.close();
            }
        }

        /*!
         * \brief finds entries based on the entered area salary
         *
         * Search and show record that in [start, end] area
         */
        void searchRecordBySalary(int startArea, int endArea)
        {
            ifstream file("data.txt");
            if (!file.is_open())
                cout << "\nThere are no records to show\n";
            else
            {
                string curName, curPosition, curAge, curSalary;
                int countIsSimilar = 0, curSalaryInt;
                while (file)
                {
                    file >> curName >> curAge >> curPosition >> curSalary;

                    if (file && (makeStringDigit(curSalary, &curSalaryInt)) &&
                            (curSalaryInt >= startArea) && (curSalaryInt <= endArea))
                    {
                        countIsSimilar++;
                        cout << "============================" << endl;
                        cout << "Name: " << curName << endl;
                        cout << "Age: " << curAge << endl;
                        cout << "Position: " << curPosition << endl;
                        cout << "Salary: " << curSalary << endl;
                    }
                }
                if (countIsSimilar == 0)
                    cout << "\nNo matches\n";
                file.close();
            }
        }

        /*!
         * \brief add position to file
         *
         * add data of current object to data file
         */
        void addRecord(Emploee worker)
        {
            ofstream file("data.txt", ios_base::app);
            file << worker.getName() << " " << worker.getAge() <<
                    " " << worker.getPosition() << " " << worker.getSalary() << "\n";
            file.close();
        }

        /*!
         * \brief display all records
         *
         * display all record in data file
         * make warning if file is empty
         */
        void showAllRecordsEmploee()
        {
            ifstream file("data.txt");
            if (!file.is_open())
                cout << "\nThere are no records to show\n";
            else
            {
                string curName, curPosition, curAge, curSalary;
                while (file)
                {
                    file >> curName >> curAge >> curPosition >> curSalary;
                    if(file)
                    {
                        cout << "============================" << endl;
                        cout << "Name: " << curName << endl;
                        cout << "Age: " << curAge << endl;
                        cout << "Position: " << curPosition << endl;
                        cout << "Salary: " << curSalary << endl;
                    }
                }
                file.close();
            }
        }

        /*!
         * \brief delete positions from file
         *
         * delete all positions in data file that are similar with input object
         */
        void deleteRecord(Emploee worker)
        {
            ifstream fileOriginal("data.txt");
            if (!fileOriginal.is_open())
                cout << "\nThere are no records\n";
            else
            {
                ofstream fileChange("dataChange.txt");
                int delCount = 0;
                string curName, curPosition, curAge, curSalary;
                while (fileOriginal)
                {
                    fileOriginal >> curName >> curAge >> curPosition >> curSalary;
                    if (fileOriginal &&
                        ((curName != worker.getName()) ||
                        (curAge != to_string(worker.getAge())) ||
                        (curPosition != worker.getPosition()) ||
                        (curSalary != to_string(worker.getSalary()))))
                    {
                        fileChange << curName << " " << curAge
                                 << " " << curPosition << " " << curSalary << "\n";
                    }
                    else
                        delCount++;
                }
                if (delCount < 2)
                    cout << "\nNo records to delete!\n";
                fileOriginal.close();
                fileChange.close();

                ofstream fileOriginal("data.txt");
                ifstream fileChanged("dataChange.txt");
                while (fileChanged)
                {
                    fileChanged >> curName >> curAge >> curPosition >> curSalary;
                    if (fileChanged)
                        fileOriginal << curName << " " << curAge
                                << " " << curPosition << " " << curSalary << "\n";
                }
                fileOriginal.close();
                fileChanged.close();
            }
        }

    private:
        string searchString;///<The substring to search for in the file
    };

private:
    string position;
    int salary;
};

class InteracrtiveMenu
{
public:

    void printMenuPoints()
    {
        cout << "____________________________" << endl;
        cout << "1 - add position" << endl;
        cout << "2 - delete position" << endl;
        cout << "3 - show all positions" << endl;
        cout << "4 - find position" << endl;
        cout << "5 - exit BatExcel" << endl;
    }

    void setInputPoint(string str)
    {
        inputPoint = str;
    }

    string getInputPoint()
    {
        return inputPoint;
    }

    void addPositionEmploee()
    {
        string nameBuf, positionBuf, strAgeBuf, strSalaryBuf;
        int ageBuf = 0, salaryBuf = 0, errorFlag;

        cout << "Input name: "; cin >> nameBuf;

        do
        {
            cout << "Input age: "; cin >> strAgeBuf;
            errorFlag = makeStringDigit(strAgeBuf, &ageBuf);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while (errorFlag != 1);

        cout << "Input position: "; cin >> positionBuf;

        do
        {
            cout << "Input salary: "; cin >> strSalaryBuf;
            errorFlag = makeStringDigit(strSalaryBuf, &salaryBuf);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while(errorFlag != 1);

        Emploee worker(nameBuf, ageBuf, positionBuf, salaryBuf);
        Emploee::dataFileSearch dataFile;
        dataFile.addRecord(worker);
    }

    void deletePositionEmploee()
    {
        string nameBuf, positionBuf, strAgeBuf, strSalaryBuf;
        int ageBuf = 0, salaryBuf = 0, errorFlag;

        cout << "Input name: "; cin >> nameBuf;

        do
        {
            cout << "Input age: "; cin >> strAgeBuf;
            errorFlag = makeStringDigit(strAgeBuf, &ageBuf);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while (errorFlag != 1);

        cout << "Input position: "; cin >> positionBuf;

        do
        {
            cout << "Input salary: "; cin >> strSalaryBuf;
            errorFlag = makeStringDigit(strSalaryBuf, &salaryBuf);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while(errorFlag != 1);

        Emploee worker(nameBuf, ageBuf, positionBuf, salaryBuf);
        Emploee::dataFileSearch dataFile;
        dataFile.deleteRecord(worker);
    }

    void showAllPositionsEmploee()
    {
        Emploee::dataFileSearch dataFile;
        dataFile.showAllRecordsEmploee();
    }

    void findPositionEmploee()
    {
        string inputString;///<String entered by the user
        /*!
            \brief loop until the user enters the desired number
        */
        do
        {
            cout << "\nInput number by that you will search records\n";
            cout << "1 - Name" << endl;
            cout << "2 - Age" << endl;
            cout << "3 - Position" << endl;
            cout << "4 - Salary" << endl;
            cout << "Number: "; cin >> inputString;
            setInputPoint(inputString);
            if ((inputPoint != "1") && (inputPoint != "2") &&
                    (inputPoint != "3") && (inputPoint != "4"))
                cout << "\nERROR INPUT\n";
        }
        while ((inputPoint != "1") && (inputPoint != "2") &&
               (inputPoint != "3") && (inputPoint != "4"));

        if (inputPoint == "1")
            findPositionEmploeeByName();
        else if (inputPoint == "2")
            findPositionEmploeeByAge();
        else if (inputPoint == "3")
            findPositionEmploeeByWorkPosition();
        else if (inputPoint == "4")
            findPositionEmploeeBySalary();
    }

    void findPositionEmploeeByName()
    {
        string inputString;
        Emploee::dataFileSearch dataFile;
        cout << "Input string: "; cin >> inputString;
        dataFile.setSearchString(inputString);
        dataFile.searchRecordByName();
    }

    void findPositionEmploeeByAge()
    {
        Emploee::dataFileSearch dataFile;
        int startArea, endArea, errorFlag;
        string strStartArea, strEndArea;
        do
        {
            cout << "Input start of area age: "; cin >> strStartArea;
            errorFlag = makeStringDigit(strStartArea, &startArea);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while (errorFlag != 1);

        do
        {
            cout << "Input end of area age: "; cin >> strEndArea;
            errorFlag = makeStringDigit(strEndArea, &endArea);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
            if ((errorFlag == 1) && (endArea < startArea))
            {
                errorFlag = 2;
                cout << "Wrong area (end of search < start search)" << endl;
            }
        }
        while (errorFlag != 1);

        dataFile.searchRecordByAge(startArea, endArea);
    }

    void findPositionEmploeeByWorkPosition()
    {
        string inputString;
        Emploee::dataFileSearch dataFile;
        cout << "Input string: "; cin >> inputString;
        dataFile.setSearchString(inputString);
        dataFile.searchRecordByPosition();
    }

    void findPositionEmploeeBySalary()
    {
        Emploee::dataFileSearch dataFile;
        int startArea, endArea, errorFlag;
        string strStartArea, strEndArea;
        do
        {
            cout << "Input start of area salary: "; cin >> strStartArea;
            errorFlag = makeStringDigit(strStartArea, &startArea);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
        }
        while (errorFlag != 1);

        do
        {
            cout << "Input end of area salary: "; cin >> strEndArea;
            errorFlag = makeStringDigit(strEndArea, &endArea);
            if (errorFlag == -1)
                cout << "\nToo long number\n";
            else if (errorFlag == 0)
                cout << "\nError input\n";
            if ((errorFlag == 1) && (endArea < startArea))
            {
                errorFlag = 2;
                cout << "Wrong area (end of search < start search)" << endl;
            }
        }
        while (errorFlag != 1);

        dataFile.searchRecordBySalary(startArea, endArea);
    }

private:
    string inputPoint;
};

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


int makeStringDigit(string str, int *intStr)
{
    *intStr = 0;
    int discharge = 1, isDigit = 1, i = 0;
    //cout << endl << str.length() <<endl;
    for (i = str.length() - 1; (i >= 0 && discharge < 1000000); i--)
    {
        if (str[i] == '1')
            *intStr += 1 * discharge;
        else if (str[i] == '2')
            *intStr += 2 * discharge;
        else if (str[i] == '3')
            *intStr += 3 * discharge;
        else if (str[i] == '4')
            *intStr += 4 * discharge;
        else if (str[i] == '5')
            *intStr += 5 * discharge;
        else if (str[i] == '6')
            *intStr += 6 * discharge;
        else if (str[i] == '7')
            *intStr += 7 * discharge;
        else if (str[i] == '8')
            *intStr += 8 * discharge;
        else if (str[i] == '9')
            *intStr += 9 * discharge;
        else if (str[i] == '0')
            *intStr += 0 * discharge;
        else
        {
            //cout <<endl<< str[i] << endl;
            isDigit = 0;
            break;
        }
        discharge *= 10;
        //cout << endl << str[i] << endl;
    }
    if (isDigit == 1)
    {
        if (discharge >= 1000000)
                return -1;
        return 1;
    }
    else if (isDigit == 0)
        return 0;
}
