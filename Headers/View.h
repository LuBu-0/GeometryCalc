#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QAction>
#include <QMenuBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QTabWidget>
#include <QLabel>
#include <QLineEdit>
#include <QFrame>
#include <QImage>
#include <QDialog>
#include <sstream>
#include <QFile>


class Controller;

class View : public QWidget
{
    Q_OBJECT
private:
    Controller* controller;
    QAction* chiudi;
    QAction* mostra;
    QAction* cancella;
    QLineEdit* lineTriangoloEQ;
    QPushButton* calcolaTriangoloEQ;
    QLineEdit* lineTriangoloISBase;
    QLineEdit* lineTriangoloISLato;
    QPushButton* calcolaTriangoloIS;
    QLineEdit* lineLato1TriangoloSC;
    QLineEdit* lineLato2TriangoloSC;
    QLineEdit* lineLato3TriangoloSC;
    QPushButton* calcolaTriangoloSC;
    QLineEdit* lineBaseTriangoloRETT;
    QLineEdit* lineAltezzaTriangoloRETT;
    QLineEdit* lineIpotenusa;
    QPushButton* calcolaTriangoloRETT;
    QLineEdit* lineQuadrato;
    QPushButton* calcolaQuadrato;
    QLineEdit* lineRettangoloBase;
    QPushButton* calcolaRettangolo;
    QLineEdit* lineRettangoloAltezza;
    QLineEdit* trapezioSClineBaseM;
    QLineEdit* trapezioSClineBasem;
    QLineEdit* trapezioSClineLato1;
    QLineEdit* trapezioSClineLato2;
    QPushButton* calcolaTrapezioSC;
    QLineEdit* trapezioISlineBaseM;
    QLineEdit* trapezioISlineBasem;
    QLineEdit* trapezioISlineLato;
    QPushButton* calcolaTrapezioIS;
    QLineEdit* trapezioRETTlineBaseM;
    QLineEdit* trapezioRETTlineBasem;
    QLineEdit* trapezioRETTlineAltezza;
    QLineEdit* trapezioRETTlineLato;
    QPushButton* calcolaTrapezioRETT;
    QLineEdit* cerchioLine;
    QPushButton* calcolaCerchio;
    QDialog* cronologia;
    QPushButton* inizio;
    QPushButton* precedente;
    QPushButton* successivo;
    QPushButton* fine;
    QPushButton* rimuovi;
    QDialog* confirmation;
    QPushButton* conferma;
    QPushButton* annulla;

public:
    explicit View(QWidget *parent = nullptr);
    ~View();
    void setController(Controller* c);
    void showDialog();
    void showDeleteDialog();
    void showCronologia();
    void updateCronologia();
    void showVuota();
    void showEliminatoUltimo();
    void showWarning(const QString& message);
    void showError(const QString& message);
    void showConfirmationDialog();
    void confirmationClose();
    double getTriangoloEquilateroLine() const;
    double getTriangoloIsosceleLineBase() const;
    double getTriangoloIsosceleLineLato() const;
    double getTriangoloScalenoLineLato1() const;
    double getTriangoloScalenoLineLato2() const;
    double getTriangoloScalenoLineLato3() const;
    double getTriangoloRettangoloIpotenusa() const;
    double getTriangoloRettangoloAltezza() const;
    double getTriangoloRettangoloBase() const;
    double getQuadratoLine() const;
    double getRettangoloBase() const;
    double getRettangoloAltezza() const;
    double getTrapezioSCBaseMaggiore() const;
    double getTrapezioSCBaseMinore() const;
    double getTrapezioSCLato1() const;
    double getTrapezioSCLato2() const;
    double getTrapezioISBaseMaggiore() const;
    double getTrapezioISBaseMinore() const;
    double getTrapezioISLato() const;
    double getTrapezioRETTBaseMaggiore() const;
    double getTrapezioRETTBaseMinore() const;
    double getTrapezioRETTAltezza() const;
    double getTrapezioRETTLato() const;
    double getCerchioRaggio() const;
    void setGeometryCalcStyle();


signals:

};
#endif // VIEW_H
