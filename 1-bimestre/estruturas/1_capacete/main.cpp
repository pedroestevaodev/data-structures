// Main.cpp
#include "thinker.h"

int main()
{
    ThinkingCap Estudante, Festa;

    Estudante.Slots("Hello", "Goodbye");
    Festa.Slots("Hooray!", "Boo!");
    Estudante.PressLeft();
    Festa.PressLeft();
    Estudante.PressRight();

    return 0;
}