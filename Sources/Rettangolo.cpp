#include "Headers/Rettangolo.h"



double Rettangolo::getBase() const
{
    return base;
}

double Rettangolo::getAltezza() const
{
    return altezza;
}

void Rettangolo::setArea()
{
    area = base * altezza;
}

void Rettangolo::setPerimetro()
{
    perimetro = (base + altezza) * 2;
}

Rettangolo *Rettangolo::clone() const
{
    return new Rettangolo(*this);
}
