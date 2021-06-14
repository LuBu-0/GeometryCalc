#ifndef FIGURAPIANA_H
#define FIGURAPIANA_H



class FiguraPiana
{
protected:
    double area, perimetro;
public:
    FiguraPiana(double a = 0, double p = 0);
    virtual ~FiguraPiana() = default;
    double getArea() const;
    double getPerimetro() const;
    virtual void setArea() = 0;
    virtual void setPerimetro() = 0;
    virtual FiguraPiana* clone() const = 0;
};

#endif // FIGURAPIANA_H
