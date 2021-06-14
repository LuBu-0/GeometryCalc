#ifndef TRIANGOLOISOSCELE_H
#define TRIANGOLOISOSCELE_H

#include "Triangolo.h"
#include "math.h"


class TriangoloIsoscele : public Triangolo
{
public:
    TriangoloIsoscele(const double & l, const double & b) : Triangolo(l, l, b) {}
    void setArea() override;
    void setPerimetro() override;
    double altezza() const override;
    TriangoloIsoscele* clone() const override;
};

#endif // TRIANGOLOISOSCELE_H
