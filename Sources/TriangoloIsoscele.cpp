#include "Headers/TriangoloIsoscele.h"
#include <iostream>

double TriangoloIsoscele::altezza() const
{
    return sqrt(pow((getLato1()), 2) - pow((getBase()/2), 2));
}

TriangoloIsoscele *TriangoloIsoscele::clone() const
{
    return new TriangoloIsoscele(*this);
}

void TriangoloIsoscele::setArea()
{

    area = (getBase() * altezza()) / 2;
}

void TriangoloIsoscele::setPerimetro()
{
    perimetro = getLato1() * 2 + getBase();
}
