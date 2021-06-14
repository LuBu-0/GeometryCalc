#ifndef MODEL_H
#define MODEL_H

#include "Contenitore.h"
#include "DeepPtr.h"
#include "FiguraPiana.h"
#include "Cerchio.h"
#include "Quadrato.h"
#include "Rettangolo.h"
#include "Triangolo.h"
#include "TriangoloIsoscele.h"
#include "TriangoloEquilatero.h"
#include "TriangoloRettangolo.h"
#include "Trapezio.h"
#include "TrapezioIsoscele.h"
#include "TrapezioRettangolo.h"
#include <QString>



class FiguraPianaConteiner
{
private:
    Contenitore<DeepPtr<FiguraPiana>> shape;
    unsigned int currentShape;
public:
    FiguraPianaConteiner();

    void addShape(const DeepPtr<FiguraPiana>& f);
    void removeShape(unsigned int index);
    unsigned int getCurrentShape() const;
    DeepPtr<FiguraPiana>& getShape(unsigned int index) const;
    void previous();
    void next();
    void goFirst();
    void goLast();
    double getPerimetro() const;
    double getArea() const;
    unsigned int getSize() const;
    void deleteAll();
    std::string getInfo() const;
};

#endif // MODEL_H
