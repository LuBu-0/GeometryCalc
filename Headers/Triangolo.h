#ifndef TRIANGOLO_H
#define TRIANGOLO_H

#include "FiguraPiana.h"
#include <math.h>

class Triangolo : public FiguraPiana
{
private:
    double lato1, lato2, base;
public:
    Triangolo(const double & l1 = 0, const double & l2 = 0, const double & b = 0);
    bool isTriangle() const;
    double getLato1() const;
    double getLato2() const;
    double getBase() const;
    virtual double altezza() const;
    Triangolo* clone() const override;
    void setArea() override;
    void setPerimetro() override;
};

#endif // TRIANGOLO_H
