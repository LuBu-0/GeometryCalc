#include "Headers/TrapezioRettangolo.h"

double TrapezioRettangolo::altezza() const
{
    return getLato1();
}

void TrapezioRettangolo::setArea()
{
    area = ((getBaseMaggiore()+getBaseMinore())*altezza())/2;
}

TrapezioRettangolo *TrapezioRettangolo::clone() const
{
    return new TrapezioRettangolo(*this);
}
