#ifndef TRIANGOLORETTANGOLO_H
#define TRIANGOLORETTANGOLO_H

#include "Triangolo.h"

class TriangoloRettangolo : public Triangolo
{
public:
    TriangoloRettangolo(const double & i, const double & h, const double& b) : Triangolo(i,h,b) {}
    void setArea() override;
    double altezza() const override;
    TriangoloRettangolo* clone() const override;
};

#endif // TRIANGOLORETTANGOLO_H
