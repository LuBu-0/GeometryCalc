#include "Headers/Quadrato.h"



void Quadrato::setArea()
{
    area = pow(getBase(), 2);
}

void Quadrato::setPerimetro()
{
    perimetro = getBase() * 4;
}

Quadrato *Quadrato::clone() const
{
    return new Quadrato(*this);
}
