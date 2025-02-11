// Thinker.cpp
#include "thinker.h"
#include <iostream>
#include <string>
using namespace std;

void ThinkingCap::Slots(string NewLeft, string NewRight) 
{
    LeftString = NewLeft;
    RightString = NewRight;
}

void ThinkingCap::PressLeft() 
{
    cout << LeftString << endl;
}

void ThinkingCap::PressRight() 
{
    cout << RightString << endl;
}