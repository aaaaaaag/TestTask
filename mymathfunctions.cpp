#include "mymathfunctions.h"
using namespace std;
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
    return 0;
}

