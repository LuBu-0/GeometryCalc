#ifndef TRIANGOLOEQUILATERO_H
#define TRIANGOLOEQUILATERO_H

#include "Triangolo.h"

class TriangoloEquilatero : public Triangolo
{
public:
    TriangoloEquilatero(const double & l) : Triangolo(l, l, l){}
    void setArea() override;
    void setPerimetro() override;
    double altezza() const override;
    TriangoloEquilatero* clone() const override;
};
#endif // TRIANGOLOEQUILATERO_H
