#include "emploee.h"

Emploee::Emploee(string inName, int inAge, string inPosition, int inSalary):
    Person(inName, inAge), position(inPosition), salary(inSalary)
{
}

string Emploee::getName()
{
    return name;
}
int Emploee::getAge()
{
    return age;
}
string Emploee::getPosition()
{
    return position;
}
int Emploee::getSalary()
{
    return salary;
}

Emploee::dataFileSearch::dataFileSearch(){}

void Emploee::dataFileSearch::setSearchString(string setString)
{
    searchString = setString;
}

void Emploee::dataFileSearch::searchRecordByName()
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

void Emploee::dataFileSearch::searchRecordByAge(int startArea, int endArea)
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

void Emploee::dataFileSearch::searchRecordByPosition()
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

void Emploee::dataFileSearch::searchRecordBySalary(int startArea, int endArea)
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

void Emploee::dataFileSearch::addRecord(Emploee worker)
{
    ofstream file("data.txt", ios_base::app);
    file << worker.getName() << " " << worker.getAge() <<
            " " << worker.getPosition() << " " << worker.getSalary() << "\n";
    file.close();
}

void Emploee::dataFileSearch::showAllRecordsEmploee()
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

void Emploee::dataFileSearch::deleteRecord(Emploee worker)
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
