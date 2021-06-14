#include "Headers/TrapezioIsoscele.h"

double TrapezioIsoscele::altezza() const
{
    double x = (getBaseMaggiore() - getBaseMinore()) / 2;
    return sqrt(pow(getLato1(), 2) - pow(x,2));
}

void TrapezioIsoscele::setPerimetro()
{
    perimetro = getLato1() * 2 + getBaseMaggiore() + getBaseMinore();
}

TrapezioIsoscele *TrapezioIsoscele::clone() const
{
    return new TrapezioIsoscele(*this);
}
