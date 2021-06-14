#ifndef QUADRATO_H
#define QUADRATO_H

#include "Rettangolo.h"
#include "math.h"

class Quadrato : public Rettangolo
{
public:
    Quadrato(const double & l = 0) : Rettangolo(l,l) {}
//protected:
    void setArea() override;
    void setPerimetro() override;
    Quadrato* clone() const override;
};

#endif // QUADRATO_H
