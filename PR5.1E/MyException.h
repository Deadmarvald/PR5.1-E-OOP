#pragma once

#include <string>
#include <iostream>

using namespace std;

class MyException
{
private:
    string message;

public:
    MyException(string message) : message(message) { }
    string What() { return message; }
};