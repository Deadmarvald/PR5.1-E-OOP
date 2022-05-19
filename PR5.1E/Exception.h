#pragma once

#include <string>
#include <iostream>

using namespace std;

class Exception : public exception
{
private:
    string message;

public:
    Exception(string message) : message(message) { }
    string What() { return message; }
};