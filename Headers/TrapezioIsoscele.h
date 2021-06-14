#ifndef TRAPEZIOISOSCELE_H
#define TRAPEZIOISOSCELE_H

#include "Trapezio.h"
#include "math.h"

class TrapezioIsoscele : public Trapezio
{
public:
    TrapezioIsoscele(const double & M = 0, const double & m = 0, const double & l = 0) : Trapezio(M,m,l,l) {}
    double altezza() const override;
    void setPerimetro() override;
    TrapezioIsoscele* clone() const override;
};

#endif // TRAPEZIOISOSCELE_H
