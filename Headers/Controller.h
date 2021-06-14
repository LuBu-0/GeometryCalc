#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <stdexcept>
#include "View.h"
#include "Model.h"
#include "TriangoloEquilatero.h"


class Controller : public QObject
{
    Q_OBJECT
private:
    View* view;
    FiguraPianaConteiner* model;
public:
    explicit Controller(QObject *parent = nullptr);
    void setModel(FiguraPianaConteiner* m);
    void setView(View* v);
    double getPerimetro() const;
    double getArea() const;
    std::string getInfo() const;

public slots:
    void next();

    void onTriangoloEquilateroClicked() const;
    void onTriangoloIsosceleClicked() const;
    void onTriangoloScalenoClicked() const;
    void onTriangoloRettangoloClicked() const;
    void onRettangoloClicked() const;
    void onQuadratoClicked() const;
    void onTrapezioScalenoClicked() const;
    void onTrapezioIsosceleClicked() const;
    void onTrapezioRettangoloClicked() const;
    void onCerchioClicked() const;
    void onMostraCronologiaTriggered() const;
    void onEliminaCronologiaTriggered() const;
    void onConfermaClicked() const;
    void onAnnullaClicked() const;
    void onInizioClicked() const;
    void onPrecedenteClicked() const;
    void onSuccessivoClicked() const;
    void onFineClicked() const;
    void onRimuoviClicked() const;

signals:

};

#endif // CONTROLLER_H
