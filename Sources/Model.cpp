#include "Headers/Model.h"

FiguraPianaConteiner::FiguraPianaConteiner()
{

}

void FiguraPianaConteiner::addShape(const DeepPtr<FiguraPiana>& f)
{
    shape.pushBack(f);
    currentShape = shape.size() - 1;
}

void FiguraPianaConteiner::removeShape(unsigned int index)
{
    if(index >= shape.size())
        throw std::out_of_range("Index out of range");
    shape.erase(index);
}

unsigned int FiguraPianaConteiner::getCurrentShape() const
{
    return currentShape;
}

DeepPtr<FiguraPiana>& FiguraPianaConteiner::getShape(unsigned int index) const
{
    if(index >= shape.size())
        throw std::out_of_range("Index out of range");
    return shape[index];
}

void FiguraPianaConteiner::previous()
{
    if (currentShape > 0)
        currentShape--;
}

void FiguraPianaConteiner::next()
{
    if(currentShape < shape.size() - 1)
        currentShape++;
}

void FiguraPianaConteiner::goFirst()
{
    currentShape = 0;
}

void FiguraPianaConteiner::goLast()
{
    currentShape = shape.size() - 1;
}

double FiguraPianaConteiner::getPerimetro() const
{
    getShape(currentShape)->setPerimetro();
    return getShape(currentShape)->getPerimetro();
}

double FiguraPianaConteiner::getArea() const
{
    getShape(currentShape)->setArea();
    return getShape(currentShape)->getArea();
}

unsigned int FiguraPianaConteiner::getSize() const
{
    return shape.size();
}

void FiguraPianaConteiner::deleteAll()
{
    while(shape.size() > 0)
        shape.popBack();
}

std::string FiguraPianaConteiner::getInfo() const
{
    std::string text;

    if (dynamic_cast<Triangolo*>(&*(this->getShape(currentShape)))) {

        if (dynamic_cast<TriangoloEquilatero *>(&*(this->getShape(currentShape)))) {
            TriangoloEquilatero* tmp = static_cast<TriangoloEquilatero*>(&*(this->getShape(currentShape)));
            text += "Triangolo Equilatero\n\nLato = " + std::to_string(tmp->getLato1());
            return text;
        }

        else if (dynamic_cast<TriangoloIsoscele *>(&*(this->getShape(currentShape)))) {
            TriangoloIsoscele* tmp = static_cast<TriangoloIsoscele*>(&*(this->getShape(currentShape)));
            text += "Triangolo Isoscele\n\nBase = " + std::to_string(tmp->getBase()) + "\nLato =" + std::to_string(tmp->getLato1());
            return text;
        }

        else if (dynamic_cast<TriangoloRettangolo *>(&*(this->getShape(currentShape)))) {
            TriangoloRettangolo* tmp = static_cast<TriangoloRettangolo*>(&*(this->getShape(currentShape)));
            text += "Triangolo Rettangolo\n\nBase = " + std::to_string(tmp->getBase()) + "\nAltezza =" + std::to_string(tmp->getLato2()) + "\nIpotenusa = " + std::to_string(tmp->getLato1());
            return text;
        }

        else {
            Triangolo* tmp = static_cast<Triangolo*>(&*(this->getShape(currentShape)));
            text += "Triangolo Scaleno\n\nLato 1 = " + std::to_string(tmp->getLato1()) + "\nLato 2 = " + std::to_string(tmp->getLato2()) + "\nLato 3 = " + std::to_string(tmp->getBase());
            return text;
        }
    }


    else if(dynamic_cast<Rettangolo  *>(&*(this->getShape(currentShape)))) {

        if(dynamic_cast<Quadrato  *>(&*(this->getShape(currentShape)))) {
            Quadrato* tmp = static_cast<Quadrato*>(&*(this->getShape(currentShape)));
            text += "Quadrato\n\nLato = " + std::to_string(tmp->getBase());
            return text;
        }

        else {
            Rettangolo* tmp = static_cast<Rettangolo*>(&*(this->getShape(currentShape)));
            text += "Rettangolo\n\nBase = " + std::to_string(tmp->getBase()) + "\nAltezza =" + std::to_string(tmp->getAltezza());
            return text;
        }
}

    else if(dynamic_cast<Trapezio*>(&*(this->getShape(currentShape)))) {
        if(dynamic_cast<TrapezioIsoscele*>(&*(this->getShape(currentShape)))) {
            TrapezioIsoscele* tmp = static_cast<TrapezioIsoscele*>(&*(this->getShape(currentShape)));
            text += "Trapezio Isoscele\n\nBase Maggiore = " + std::to_string(tmp->getBaseMaggiore()) + "\nBase Minore = " + std::to_string(tmp->getBaseMinore()) + "\nLato = " + std::to_string(tmp->getLato1());
            return text;
        }

        else if(dynamic_cast<TrapezioRettangolo*>(&*(this->getShape(currentShape)))) {
            TrapezioRettangolo* tmp = static_cast<TrapezioRettangolo*>(&*(this->getShape(currentShape)));
            text += "Trapezio Rettangolo\n\nBase Maggiore = " + std::to_string(tmp->getBaseMaggiore()) + "\nBase Minore = " + std::to_string(tmp->getBaseMinore()) + "\nAltezza = " + std::to_string(tmp->getLato1()) + "\nLato = " + std::to_string(tmp->getLato2());
            return text;
        }

        else {
            Trapezio* tmp = static_cast<Trapezio*>(&*(this->getShape(currentShape)));
            text += "Trapezio Scaleno\n\nBase Maggiore = " + std::to_string(tmp->getBaseMaggiore()) + "\nBase Minore = " + std::to_string(tmp->getBaseMinore()) + "\nLato 1 = " + std::to_string(tmp->getLato1()) + "\nLato 2 = " + std::to_string(tmp->getLato2());
            return text;
        }
    }

    else if(dynamic_cast<Cerchio*>(&*(this->getShape(currentShape)))) {
        Cerchio* tmp = static_cast<Cerchio*>(&*(this->getShape(currentShape)));
        std::string text;
        text += "Cerchio\n\nRaggio = " + std::to_string(tmp->getRaggio());
        return text;
    }
    return "Figura sconosciuta";
}
