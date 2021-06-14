#ifndef CERCHIO_H
#define CERCHIO_H

#include "FiguraPiana.h"
#include "math.h"

class Cerchio : public FiguraPiana
{
private:
    double raggio;
public:
    Cerchio(const double & r) : raggio(r) {}
    double getRaggio() const;
    void setArea() override;
    void setPerimetro() override;
    Cerchio* clone() const override;

};

#endif // CERCHIO_H
