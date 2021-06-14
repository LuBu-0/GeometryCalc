#include "Headers/Triangolo.h"


void Triangolo::setArea()
{
   setPerimetro();
   double semiP = perimetro/2;
   area = sqrt(semiP * (semiP - lato1) * (semiP - lato2) * (semiP - base));
}

void Triangolo::setPerimetro()
{
    perimetro = base + lato1 + lato2;
}

Triangolo::Triangolo(const double &l1, const double &l2, const double &b) : lato1(l1), lato2(l2), base(b) {
    if(!isTriangle())
    {
        lato1 = 0;
        lato2 = 0;
        base = 0;
    }
}

bool Triangolo::isTriangle() const
{
    if((getBase() < getLato1() + getLato2()) && (getLato1() < getBase() + getLato2()) && (getLato2() < getBase() + getLato1()))
            return true;

     return false;
}

double Triangolo::getLato1() const
{
    return lato1;
}

double Triangolo::getLato2() const
{
    return lato2;
}

double Triangolo::getBase() const
{
    return base;
}

double Triangolo::altezza() const
{
    return (2*area)/base;
}

Triangolo *Triangolo::clone() const
{
    return new Triangolo(*this);
}
