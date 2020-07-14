#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using namespace std;

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

private:
    string position;
    int salary;
};

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

    void searchRecordByAge()
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
                if (file && (curAge.find(searchString, 0) == 0))
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

    void searchRecordBySalary()
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
                if (file && (curSalary.find(searchString, 0) == 0))
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
    string searchString;
};

int main()
{
    cout << "Welcome to BatExcel" << endl;
    string inputPoint = "1";
    while (inputPoint != "5")
    {
        cout << "____________________________" << endl;
        cout << "1 - add position" << endl;
        cout << "2 - delete position" << endl;
        cout << "3 - show all positions" << endl;
        cout << "4 - find position" << endl;
        cout << "5 - exit BatExcel" << endl;
        cout << "\nInput number of your choice: ";
        cin >> inputPoint;
        if (inputPoint == "1")
        {
            string nameBuf, positionBuf;
            int ageBuf, salaryBuf;
            cout << "Input name: "; cin >> nameBuf;
            cout << "Input age: "; cin >> ageBuf;
            cout << "Input position: "; cin >> positionBuf;
            cout << "Input salary: "; cin >> salaryBuf;
            Emploee worker(nameBuf, ageBuf, positionBuf, salaryBuf);
            dataFileSearch dataFile;
            dataFile.addRecord(worker);
        }
        else if (inputPoint == "2")
        {
            string nameBuf, positionBuf;
            int ageBuf, salaryBuf;
            cout << "Input name: "; cin >> nameBuf;
            cout << "Input age: "; cin >> ageBuf;
            cout << "Input position: "; cin >> positionBuf;
            cout << "Input salary: "; cin >> salaryBuf;
            Emploee worker(nameBuf, ageBuf, positionBuf, salaryBuf);
            dataFileSearch dataFile;
            dataFile.deleteRecord(worker);
        }
        else if (inputPoint == "3")
        {
            dataFileSearch dataFile;
            dataFile.showAllRecordsEmploee();
        }
        else if (inputPoint == "4")
        {
            string inputString;
            char inputPointStr;
            do
            {
                cout << "\nInput number by that you will search records\n";
                cout << "1 - Name" << endl;
                cout << "2 - Age" << endl;
                cout << "3 - Position" << endl;
                cout << "4 - Salary" << endl;
                cout << "Number: "; cin >> inputPointStr;
                if ((inputPointStr != '1') && (inputPointStr != '2') &&
                        (inputPointStr != '3') && (inputPointStr != '4'))
                    cout << "\nERROR INPUT\n";
            }
            while ((inputPointStr != '1') && (inputPointStr != '2') &&
                   (inputPointStr != '3') && (inputPointStr != '4'));

            cout << "Input string: "; cin >> inputString;
            dataFileSearch dataFile;
            dataFile.setSearchString(inputString);
            if (inputPointStr == '1')
                dataFile.searchRecordByName();
            else if (inputPointStr == '2')
                dataFile.searchRecordByAge();
            else if (inputPointStr == '3')
                dataFile.searchRecordByPosition();
            else if (inputPointStr == '4')
                dataFile.searchRecordBySalary();
        }
    }
    return 0;
}
