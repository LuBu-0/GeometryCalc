#include "Headers/TriangoloEquilatero.h"
void TriangoloEquilatero::setArea()
{
    area = sqrt(3) / 4 * pow(getLato1(), 2);
}
void TriangoloEquilatero::setPerimetro()
{
    perimetro = getLato2() * 3;
}

double TriangoloEquilatero::altezza() const
{
    return sqrt(pow(getLato1(),2) - pow(getLato1()/2,2));
}

TriangoloEquilatero *TriangoloEquilatero::clone() const
{
    return new TriangoloEquilatero(*this);
}
