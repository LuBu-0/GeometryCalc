#ifndef TRAPEZIORETTANGOLO_H
#define TRAPEZIORETTANGOLO_H

#include "Trapezio.h"
#include "math.h"

class TrapezioRettangolo : public Trapezio
{
public:
    TrapezioRettangolo(const double & M = 0, const double & m = 0, const double & h = 0, const double & l=0) : Trapezio(M,m,h,l) {}
    double altezza()const  override;
    void setArea() override;
    TrapezioRettangolo* clone() const override;
};

#endif // TRAPEZIORETTANGOLO_H
