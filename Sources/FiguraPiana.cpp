#include "Headers/FiguraPiana.h"

FiguraPiana::FiguraPiana(double a, double p) : area(a), perimetro(p) {}

double FiguraPiana::getArea() const { return area; }

double FiguraPiana::getPerimetro() const { return perimetro; }
