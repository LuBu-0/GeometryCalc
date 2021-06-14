#ifndef TRAPEZIO_H
#define TRAPEZIO_H

#include "FiguraPiana.h"
#include "math.h"

class Trapezio : public FiguraPiana
{
private:
    double baseMaggiore, baseMinore, lato1, lato2;
public:
    Trapezio(const double & M=0, const double & m=0, const double & l1=0, const double & l2=0);
    void swapBase();
    bool isTrapezio() const;
    double getLato1() const;
    double getLato2() const;
    double getBaseMaggiore() const;
    double getBaseMinore() const;
    virtual double altezza() const;
    Trapezio* clone() const override;
    void setArea() override;
    void setPerimetro() override;
    void setBaseMaggiore(double x);
    void setBaseMinore(double x);
    void setLato1(double x);
    void setLato2(double x);
};

#endif // TRAPEZIO_H
