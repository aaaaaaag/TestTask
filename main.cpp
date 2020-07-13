#include <iostream>
#include <string>
#include <fstream>
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

    Main class in program.
    Adds, deletes, searches, and displays records
*/
class Emploee:public Person
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
    int addPosition()
    {
        ofstream file("data.txt", ios_base::app);
        file << name << " " << age << " " << position << " " << salary << "\n";
        file.close();
    }
private:
    string position;
    int salary;
};

int main()
{
    cout << "Welcome to BatExcel" << endl;
    int inputPoint = 1;
    while (inputPoint)
    {
        cout << "____________________________" << endl;
        cout << "1 - add position" << endl;
        cout << "2 - delete position" << endl;
        cout << "3 - show all positions" << endl;
        cout << "4 - find position" << endl;
        cout << "5 - exit BatExcel" << endl;
        cout << "Input number of your choice: ";
        cin >> inputPoint;
        if (inputPoint == 1)
        {
            string nameBuf;
            int ageBuf;
            string positionBuf;
            int salaryBuf;
            cout << "Input name: ";
            cin >> nameBuf;
            cout << "Input age: ";
            cin >> ageBuf;
            cout << "Input position: ";
            cin >> positionBuf;
            cout << "Input salary: ";
            cin >> salaryBuf;
            Emploee emploeeBuf(nameBuf, ageBuf, positionBuf, salaryBuf);
            emploeeBuf.addPosition();
        }
        else if (inputPoint == 5)
            break;
    }
    return 0;
}
