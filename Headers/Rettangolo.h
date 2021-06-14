#ifndef RETTANGOLO_H
#define RETTANGOLO_H

#include "FiguraPiana.h"

class Rettangolo : public FiguraPiana
{
private:
    double base, altezza;
public:
    Rettangolo(const double & b, const double & h) : base(b), altezza(h) {}
    double getBase() const;
    double getAltezza() const;
    void setArea() override;
    void setPerimetro() override;
    Rettangolo* clone() const override;
};

#endif // RETTANGOLO_H
