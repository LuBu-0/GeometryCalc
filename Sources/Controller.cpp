#include "Headers/Controller.h"

Controller::Controller(QObject *parent) : QObject(parent){}

void Controller::setModel(FiguraPianaConteiner *m)
{
    model = m;
}

void Controller::setView(View *v)
{
    view = v;
}

double Controller::getPerimetro() const
{
    return model->getPerimetro();
}

double Controller::getArea() const
{
    return model->getArea();
}

std::string Controller::getInfo() const
{
    return model->getInfo();
}

void Controller::next()
{
    std::cout<<"next\n";
}

void Controller::onTriangoloEquilateroClicked() const
{
bool ok = true;

try { view->getTriangoloEquilateroLine(); }
catch (const std::out_of_range& exc) {
    view->showWarning(exc.what());
    ok = false;
}

if(ok)
{
    model->addShape(new TriangoloEquilatero(view->getTriangoloEquilateroLine()));
    model->getPerimetro();
    model->getArea();
    view->showDialog();
}
}

void Controller::onTriangoloIsosceleClicked() const
{
    bool ok = true;

    try {
        view->getTriangoloIsosceleLineBase();
        view->getTriangoloIsosceleLineLato();
    }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new TriangoloIsoscele(view->getTriangoloIsosceleLineLato(), view->getTriangoloIsosceleLineBase()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }

        else
            view->showDialog();
    }
}

void Controller::onTriangoloScalenoClicked() const
{
    bool ok = true;

    try {
        view->getTriangoloScalenoLineLato1();
        view->getTriangoloScalenoLineLato2();
        view->getTriangoloScalenoLineLato3();
    }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new Triangolo(view->getTriangoloScalenoLineLato1(), view->getTriangoloScalenoLineLato2(), view->getTriangoloScalenoLineLato3()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }

        else
            view->showDialog();
    }
}

void Controller::onTriangoloRettangoloClicked() const
{
    bool ok = true;

    try {
        view->getTriangoloRettangoloIpotenusa();
        view->getTriangoloRettangoloAltezza();
        view->getTriangoloRettangoloBase();
    }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new TriangoloRettangolo(view->getTriangoloRettangoloIpotenusa(), view->getTriangoloRettangoloAltezza(), view->getTriangoloRettangoloBase()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }

        else
            view->showDialog();
    }
}

void Controller::onRettangoloClicked() const
{
    bool ok = true;

    try {
        view->getRettangoloBase();
        view->getRettangoloAltezza();
    }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new Rettangolo(view->getRettangoloBase(), view->getRettangoloAltezza()));
        model->getPerimetro();
        model->getArea();
        view->showDialog();
    }
}

void Controller::onQuadratoClicked() const
{
    bool ok = true;

    try { view->getQuadratoLine(); }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new Quadrato(view->getQuadratoLine()));
        model->getPerimetro();
        model->getArea();
        view->showDialog();
    }
}

void Controller::onTrapezioScalenoClicked() const
{
    bool ok = true;

    try {
            view->getTrapezioSCBaseMaggiore();
            view->getTrapezioSCBaseMinore();
            view->getTrapezioSCLato1();
            view->getTrapezioSCLato2();
        }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new Trapezio(view->getTrapezioSCBaseMaggiore(),view->getTrapezioSCBaseMinore(),view->getTrapezioSCLato1(),view->getTrapezioSCLato2()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }
        else
            view->showDialog();
    }
}

void Controller::onTrapezioIsosceleClicked() const
{
    bool ok = true;

    try {
            view->getTrapezioISBaseMaggiore();
            view->getTrapezioISBaseMinore();
            view->getTrapezioISLato();
        }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new TrapezioIsoscele(view->getTrapezioISBaseMaggiore(),view->getTrapezioISBaseMinore(),view->getTrapezioISLato()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }

        else
            view->showDialog();
    }
}

void Controller::onTrapezioRettangoloClicked() const
{
    bool ok = true;

    try {
            view->getTrapezioRETTBaseMaggiore();
            view->getTrapezioRETTBaseMinore();
            view->getTrapezioRETTAltezza();
            view->getTrapezioRETTLato();
        }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new TrapezioRettangolo(view->getTrapezioRETTBaseMaggiore(),view->getTrapezioRETTBaseMinore(),view->getTrapezioRETTAltezza(), view->getTrapezioRETTLato()));
        model->getPerimetro();
        model->getArea();
        if(model->getPerimetro() == 0 && model->getArea() == 0)
        {
            view->showError("Errore nei dati:\nLa dimensione di ciascun lato deve essere minore della somma degli altri lati");
            model->removeShape(model->getCurrentShape());
        }

        else
            view->showDialog();
    }
}

void Controller::onCerchioClicked() const
{
    bool ok = true;

    try { view->getCerchioRaggio(); }
    catch (const std::out_of_range& exc) {
        view->showWarning(exc.what());
        ok = false;
    }

    if(ok)
    {
        model->addShape(new Cerchio(view->getCerchioRaggio()));
        model->getPerimetro();
        model->getArea();
        view->showDialog();
    }
}

void Controller::onMostraCronologiaTriggered() const
{
    if (model->getSize() == 0) view->showVuota();
    else view->showCronologia();
}

void Controller::onEliminaCronologiaTriggered() const
{
    view->showConfirmationDialog();
}

void Controller::onConfermaClicked() const
{
    if (model->getSize() != 0)
    {
        model->deleteAll();
    }
    view->confirmationClose();
}

void Controller::onAnnullaClicked() const
{
    view->confirmationClose();
}

void Controller::onInizioClicked() const
{
    if(model->getCurrentShape() != 0)
    {
        model->goFirst();
        view->updateCronologia();
    }
}

void Controller::onPrecedenteClicked() const
{
    if(model->getCurrentShape() > 0)
    {
        model->previous();
        view->updateCronologia();
    }
}

void Controller::onSuccessivoClicked() const
{
    if(model->getCurrentShape() < model->getSize() - 1)
    {
        model->next();
        view->updateCronologia();
    }
}

void Controller::onFineClicked() const
{
    if(model->getCurrentShape() < model->getSize() - 1)
    {
        model->goLast();
        view->updateCronologia();
    }
}

void Controller::onRimuoviClicked() const
{
    if(model->getCurrentShape() == model->getSize() - 1)
    {
        if(model->getSize() == 1)
        {
            model->removeShape(model->getCurrentShape());
            view->showEliminatoUltimo();
        }
        else
        {
            model->previous();
            model->removeShape(model->getCurrentShape() + 1);
            view->updateCronologia();
        }
    }
    else
    {
        model->removeShape(model->getCurrentShape());
        view->updateCronologia();
    }
}
