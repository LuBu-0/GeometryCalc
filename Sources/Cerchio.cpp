
#include "Headers/Cerchio.h"

double Cerchio::getRaggio() const
{
    return raggio;
}

void Cerchio::setArea()
{
    area = pow(raggio, 2) * M_PI;
}

void Cerchio::setPerimetro()
{
    perimetro = 2 * M_PI * raggio;
}

Cerchio *Cerchio::clone() const
{
    return new Cerchio(*this);
}
