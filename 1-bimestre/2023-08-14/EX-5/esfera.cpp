#include "esfera.h"
#include <iostream>
#include <cmath>
using namespace std;

void Esfera::pegaOpcao(int o)
{
    opcao = o;
}

void Esfera::pegaDiametro(double d)
{
    diametro = d;
}

int Esfera::devolveOpcao()
{
    return opcao;
}

double Esfera::devolveDiametro()
{
    return diametro;
}

double Esfera::calculaRaio()
{
    return diametro/2;
}

double Esfera::calculaArea()
{
    return ((1/4) * M_PI * pow(diametro,2));
}

double Esfera::calculaVolume()
{
    return ((4/3) * M_PI * pow(calculaRaio(), 3));
}