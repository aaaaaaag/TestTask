#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

class Emploee
{
public:
    Emploee(string inName, int inAge, string inPosition, int inSalary):
        name(inName), age(inAge), position(inPosition), salary(inSalary)
    {
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
private:
    string name;
    int age;
    string position;
    int salary;
};

int main()
{
    Emploee Denis("Denis", 19, "Junior developer", 35000);
    Denis.displayInfo();
    return 0;
}
