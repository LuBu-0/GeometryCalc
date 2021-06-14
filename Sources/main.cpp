#include "Headers/FiguraPiana.h"
#include "Headers/Triangolo.h"
#include "Headers/TriangoloIsoscele.h"
#include "Headers/TriangoloEquilatero.h"
#include "Headers/TriangoloRettangolo.h"
#include "Headers/Cerchio.h"
#include "Headers/Rettangolo.h"
#include "Headers/Quadrato.h"
#include "Headers/Trapezio.h"
#include "Headers/TrapezioIsoscele.h"
#include "Headers/TrapezioRettangolo.h"
#include "Headers/Contenitore.h"
#include "Headers/DeepPtr.h"


#include <QApplication>

#include "Headers/View.h"
#include "Headers/Model.h"
#include "Headers/Controller.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    View w;
    Controller c;
    FiguraPianaConteiner m;

    c.setModel(&m);
    c.setView(&w);
    w.setController(&c);

    w.setWindowTitle("Geometry Calc");
    w.setMinimumSize(700,650);

    w.show();

    return a.exec();
}
