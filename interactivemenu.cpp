#include "interactivemenu.h"

void InteracrtiveMenu::printMenuPoints()
{
    cout << "____________________________" << endl;
    cout << "1 - add position" << endl;
    cout << "2 - delete position" << endl;
    cout << "3 - show all positions" << endl;
    cout << "4 - find position" << endl;
    cout << "5 - exit BatExcel" << endl;
}

void InteracrtiveMenu::setInputPoint(string str)
{
    inputPoint = str;
}

string InteracrtiveMenu::getInputPoint()
{
    return inputPoint;
}

void InteracrtiveMenu::addPositionEmploee()
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

void InteracrtiveMenu::deletePositionEmploee()
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

void InteracrtiveMenu::showAllPositionsEmploee()
{
    Emploee::dataFileSearch dataFile;
    dataFile.showAllRecordsEmploee();
}

void InteracrtiveMenu::findPositionEmploee()
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

void InteracrtiveMenu::findPositionEmploeeByName()
{
    string inputString;
    Emploee::dataFileSearch dataFile;
    cout << "Input string: "; cin >> inputString;
    dataFile.setSearchString(inputString);
    dataFile.searchRecordByName();
}

void InteracrtiveMenu::findPositionEmploeeByAge()
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

void InteracrtiveMenu::findPositionEmploeeByWorkPosition()
{
    string inputString;
    Emploee::dataFileSearch dataFile;
    cout << "Input string: "; cin >> inputString;
    dataFile.setSearchString(inputString);
    dataFile.searchRecordByPosition();
}

void InteracrtiveMenu::findPositionEmploeeBySalary()
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
