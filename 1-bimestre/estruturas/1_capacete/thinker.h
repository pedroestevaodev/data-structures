// Thinker.h
#ifndef THINK_H // Atualmente a definição `#pragma once` é uma escolha mais segura e consistente 
#define THINK_H
#include <string>
using namespace std;

class ThinkingCap
{
    public:
        void Slots(string NewLeft, string NewRight);
        void PressLeft();
        void PressRight();

    private:
        string LeftString;
        string RightString;
};

#endif