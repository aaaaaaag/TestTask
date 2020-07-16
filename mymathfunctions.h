#ifndef MYMATHFUNCTIONS_H
#define MYMATHFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>
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

#endif // MYMATHFUNCTIONS_H
