#include "Headers/Trapezio.h"


Trapezio::Trapezio(const double &M, const double &m, const double &l1, const double &l2)
    : baseMaggiore(M), baseMinore(m), lato1(l1), lato2(l2){
    if(!isTrapezio())
    {
        setBaseMaggiore(0);
        setBaseMinore(0);
        setLato1(0);
        setLato2(0);
    }

    if (getBaseMinore() > getBaseMaggiore())
        swapBase();
}

void Trapezio::swapBase()
{
    double temp = getBaseMaggiore();
    setBaseMaggiore(getBaseMinore());
    setBaseMinore(temp);
}

bool Trapezio::isTrapezio() const
{
    if((getBaseMaggiore() < getBaseMinore() + getLato1() + getLato2()) &&
        (getBaseMinore() < getBaseMaggiore() + getLato1() + getLato2()) &&
        (getLato1() < getBaseMaggiore() + getBaseMinore() + getLato2()) &&
        (getLato2() < getBaseMaggiore() + getBaseMinore() + getLato1()))
            return true;

     return false;
}

double Trapezio::getLato1() const
{
    return lato1;
}

double Trapezio::getLato2() const
{
    return lato2;
}

double Trapezio::getBaseMaggiore() const
{
    return baseMaggiore;
}

double Trapezio::getBaseMinore() const
{
    return baseMinore;
}

double Trapezio::altezza() const
{
    return (baseMaggiore+baseMinore) / 5;
}

Trapezio *Trapezio::clone() const
{
    return new Trapezio(*this);
}

void Trapezio::setArea()
{
    area = ((baseMaggiore + baseMinore) / 2 ) * sqrt(pow(lato1,2) - (pow(baseMaggiore-baseMinore,2) + pow(lato1,2) - pow(lato2,2)) / 2*(baseMaggiore - baseMinore));
}

void Trapezio::setPerimetro()
{
    perimetro = baseMaggiore + baseMinore + lato1 + lato2;
}

void Trapezio::setBaseMaggiore(double x)
{
    baseMaggiore = x;
}

void Trapezio::setBaseMinore(double x)
{
            baseMinore = x;
}

void Trapezio::setLato1(double x)
{
    lato1 = x;
}

void Trapezio::setLato2(double x)
{
    lato2 = x;
}
