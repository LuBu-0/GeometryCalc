#include "Headers/TriangoloRettangolo.h"

void TriangoloRettangolo::setArea()
{
    area = getBase() * getLato2() / 2;
}

double TriangoloRettangolo::altezza() const
{
    return getLato2();
}

TriangoloRettangolo *TriangoloRettangolo::clone() const
{
    return new TriangoloRettangolo(*this);
}
