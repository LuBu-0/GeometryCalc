#include "Headers/View.h"
#include "Headers/Controller.h"

View::View(QWidget *parent) : QWidget(parent), inizio(new QPushButton("inizio")), precedente(new QPushButton("Precedente")), successivo(new QPushButton("Successivo")), fine(new QPushButton("Fine")), rimuovi(new QPushButton("Rimuovi")), conferma(new QPushButton("SI")), annulla(new QPushButton("NO"))
{
    //mainLayout
    QVBoxLayout* mainLayout = new QVBoxLayout;



    //MenuBar
    QMenuBar* menuBar = new QMenuBar(this);

    QMenu* file = new QMenu("File", menuBar);

    chiudi = new QAction("Chiudi", file);
    file->addAction(chiudi);

    QMenu* cronologia = new QMenu("Cronologia", menuBar);

    mostra = new QAction("Mostra Cronologia", cronologia);
    cancella = new QAction("Cancella Cronologia", cronologia);

    cronologia->addAction(mostra);
    cronologia->addAction(cancella);


    menuBar->addMenu(file);
    menuBar->addMenu(cronologia);

    //label
    QLabel* desc = new QLabel("Geometry Calc ti permette di calcolare l'area e il perimetro delle seguenti figure\nN.B. I valori decimali vanno rappresentati con '.'\nIl carattere ',' non è accettato per la rappresentazione decimale\nESEMPIO: il valore 11.97 verrà accettato. Diversamente il valore 11,97 non verrà accettato.\nN.B. Si ricorda che ogni figura deve avere ciascun lato minore della somma degli altri lati \nPer comnciare scegli una figura:");

    //quadratoTab
    QWidget* quadratoTab = new QWidget;

    QVBoxLayout* quadratoLayout = new QVBoxLayout;

    QVBoxLayout* quadratoImageLayout = new QVBoxLayout;
    QLabel* quadratoImage = new QLabel;
    quadratoImage->setMinimumSize(200,200);
    quadratoImage->setMaximumSize(800,800);
    QPixmap quadratoPic(":/Images/Quadrato.png");
    quadratoImage->setPixmap(quadratoPic);
    quadratoImageLayout->addWidget(quadratoImage);
    quadratoImageLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout* quadratoCalcoloLayout = new QHBoxLayout;
    calcolaQuadrato = new QPushButton("Calcola");
    calcolaQuadrato->setMinimumSize(100,30);
    calcolaQuadrato->setMaximumSize(100,30);
    quadratoCalcoloLayout->addWidget(calcolaQuadrato);
    quadratoCalcoloLayout->setContentsMargins(20,20,20,20);

    QHBoxLayout* quadratoValueLayout = new QHBoxLayout;
    quadratoValueLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertQuadrato = new QLabel("Lato:");
    insertQuadrato->setMaximumSize(60,30);
    lineQuadrato = new QLineEdit;
    lineQuadrato->setMaximumSize(100,30);
    quadratoValueLayout->addWidget(insertQuadrato);
    quadratoValueLayout->addWidget(lineQuadrato);
    quadratoValueLayout->setSpacing(5);

    quadratoLayout->addLayout(quadratoImageLayout);
    quadratoLayout->addLayout(quadratoValueLayout);
    quadratoLayout->addLayout(quadratoCalcoloLayout);

    quadratoTab->setLayout(quadratoLayout);


    //RettangoloTab
    QWidget* rettangoloTab = new QWidget;

    QVBoxLayout* rettangoloLayout = new QVBoxLayout;

    //image
    QVBoxLayout* rettangoloImageLayout = new QVBoxLayout;
    QLabel* rettangoloImage = new QLabel;
    rettangoloImage->setMinimumSize(200,200);
    rettangoloImage->setMaximumSize(800,800);
    QPixmap rettangoloPic(":/Images/Rettangolo.png");
    rettangoloImage->setPixmap(rettangoloPic);
    rettangoloImageLayout->addWidget(rettangoloImage);
    rettangoloImageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* rettangoloCalcoloLayout = new QHBoxLayout;
    calcolaRettangolo = new QPushButton("Calcola");
    calcolaRettangolo->setMinimumSize(100,30);
    calcolaRettangolo->setMaximumSize(100,30);
    rettangoloCalcoloLayout->addWidget(calcolaRettangolo);
    rettangoloCalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* rettangoloValueLayout = new QGridLayout;

    QHBoxLayout* firstRettangoloLayout = new QHBoxLayout;
    firstRettangoloLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertRettangoloBase = new QLabel("Base:");
    insertRettangoloBase->setMaximumSize(60,30);
    lineRettangoloBase = new QLineEdit;
    lineRettangoloBase->setMaximumSize(100,20);

    QHBoxLayout* secondRettangoloLayout = new QHBoxLayout;
    secondRettangoloLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertRettangoloAltezza = new QLabel("Altezza:");
    insertRettangoloAltezza->setMaximumSize(60,30);
    lineRettangoloAltezza = new QLineEdit;
    lineRettangoloAltezza->setMaximumSize(100,20);

    //aggiunta widget ai layout
    firstRettangoloLayout->addWidget(insertRettangoloBase);
    firstRettangoloLayout->addWidget(lineRettangoloBase);
    firstRettangoloLayout->setSpacing(5);

    secondRettangoloLayout->addWidget(insertRettangoloAltezza);
    secondRettangoloLayout->addWidget(lineRettangoloAltezza);
    secondRettangoloLayout->setSpacing(5);

    rettangoloValueLayout->addLayout(firstRettangoloLayout,0,0);
    rettangoloValueLayout->addLayout(secondRettangoloLayout,1,0);

    rettangoloLayout->addLayout(rettangoloImageLayout);
    rettangoloLayout->addLayout(rettangoloValueLayout);
    rettangoloLayout->addLayout(rettangoloCalcoloLayout);

    rettangoloTab->setLayout(rettangoloLayout);





    //cerchioTab
    QWidget* cerchioTab = new QWidget;

    QVBoxLayout* cerchioLayout = new QVBoxLayout;

    QVBoxLayout* imageCerchioLayout = new QVBoxLayout;
    QLabel* cerchioImage = new QLabel;
    cerchioImage->setMinimumSize(200,200);
    cerchioImage->setMaximumSize(800,800);
    QPixmap cerchioPic(":/Images/Cerchio.png");
    cerchioImage->setPixmap(cerchioPic);
    imageCerchioLayout->addWidget(cerchioImage);
    imageCerchioLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout* calcoloCerchioLayout = new QHBoxLayout;
    calcolaCerchio = new QPushButton("Calcola");
    calcolaCerchio->setMinimumSize(100,30);
    calcolaCerchio->setMaximumSize(100,30);
    calcoloCerchioLayout->addWidget(calcolaCerchio);
    calcoloCerchioLayout->setContentsMargins(20,20,20,20);

    QHBoxLayout* cerchioValueLayout = new QHBoxLayout;
    cerchioValueLayout->setAlignment(Qt::AlignCenter);
    QLabel* cerchioInsert = new QLabel("Raggio:");
    cerchioInsert->setMaximumSize(60,30);
    cerchioLine = new QLineEdit;
    cerchioLine->setMaximumSize(100,30);
    cerchioValueLayout->addWidget(cerchioInsert);
    cerchioValueLayout->addWidget(cerchioLine);
    cerchioValueLayout->setSpacing(5);

    cerchioLayout->addLayout(imageCerchioLayout);
    cerchioLayout->addLayout(cerchioValueLayout);
    cerchioLayout->addLayout(calcoloCerchioLayout);

    cerchioTab->setLayout(cerchioLayout);


    //triangoloEquilateroTab
    QWidget* triangoloEQuilateroTab = new QWidget;

    QVBoxLayout* triangoloEquilateroLayout = new QVBoxLayout(this);

    QVBoxLayout* triangoloEQimageLayout = new QVBoxLayout;
    QLabel* triangoloEQimage = new QLabel;
    triangoloEQimage->setMinimumSize(200,200);
    triangoloEQimage->setMaximumSize(800,800);
    QPixmap trinagoloEQpic(":/Images/TriangoloEquilatero.png");
    triangoloEQimage->setPixmap(trinagoloEQpic);
    triangoloEQimageLayout->addWidget(triangoloEQimage);
    triangoloEQimageLayout->setAlignment(Qt::AlignCenter);

    QHBoxLayout* triangoloEQcalcoloLayout = new QHBoxLayout;
    calcolaTriangoloEQ = new QPushButton("Calcola");
    calcolaTriangoloEQ->setMinimumSize(100,30);
    calcolaTriangoloEQ->setMaximumSize(100,30);
    triangoloEQcalcoloLayout->addWidget(calcolaTriangoloEQ);
    triangoloEQcalcoloLayout->setContentsMargins(20,20,20,20);

    QHBoxLayout* triangoloEQ_ValueLayout = new QHBoxLayout;
    triangoloEQ_ValueLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertTriangoloEQ = new QLabel("Lato:");
    insertTriangoloEQ->setMaximumSize(60,30);
    lineTriangoloEQ = new QLineEdit;
    lineTriangoloEQ->setMaximumSize(100,30);
    triangoloEQ_ValueLayout->addWidget(insertTriangoloEQ);
    triangoloEQ_ValueLayout->addWidget(lineTriangoloEQ);
    triangoloEQ_ValueLayout->setSpacing(5);

    triangoloEquilateroLayout->addLayout(triangoloEQimageLayout);
    triangoloEquilateroLayout->addLayout(triangoloEQ_ValueLayout);
    triangoloEquilateroLayout->addLayout(triangoloEQcalcoloLayout);

    triangoloEQuilateroTab->setLayout(triangoloEquilateroLayout);


    //triangoloIsosceleTab
    QWidget* triangoloIsosceleTab = new QWidget;

    QVBoxLayout* triangoloIsosceleLayout = new QVBoxLayout;

    //image
    QVBoxLayout* triangoloISimageLayout = new QVBoxLayout;
    QLabel* triangoloISimage = new QLabel;
    triangoloISimage->setMinimumSize(200,200);
    triangoloISimage->setMaximumSize(800,800);
    QPixmap triangoloISpic(":/Images/TriangoloIsoscele.png");
    triangoloISimage->setPixmap(triangoloISpic);
    triangoloISimageLayout->addWidget(triangoloISimage);
    triangoloISimageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* triangoloIScalcoloLayout = new QHBoxLayout;
    calcolaTriangoloIS = new QPushButton("Calcola");
    calcolaTriangoloIS->setMinimumSize(100,30);
    calcolaTriangoloIS->setMaximumSize(100,30);
    triangoloIScalcoloLayout->addWidget(calcolaTriangoloIS);
    triangoloIScalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* triangoloISlabelLayout = new QGridLayout;

    QHBoxLayout* triangoloISfirstLayout = new QHBoxLayout;
    triangoloISfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertTriangoloISBase = new QLabel("Base:");
    insertTriangoloISBase->setMaximumSize(60,30);
    lineTriangoloISBase = new QLineEdit;
    lineTriangoloISBase->setMaximumSize(100,30);

    QHBoxLayout* triangoloISsecondLayout = new QHBoxLayout;
    triangoloISsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertTriangoloISLato = new QLabel("Lato:");
    insertTriangoloISLato->setMaximumSize(60,30);
    lineTriangoloISLato = new QLineEdit;
    lineTriangoloISLato->setMaximumSize(100,30);

    //aggiunta widget ai layout
    triangoloISfirstLayout->addWidget(insertTriangoloISBase);
    triangoloISfirstLayout->addWidget(lineTriangoloISBase);
    triangoloISfirstLayout->setSpacing(5);

    triangoloISsecondLayout->addWidget(insertTriangoloISLato);
    triangoloISsecondLayout->addWidget(lineTriangoloISLato);
    triangoloISsecondLayout->setSpacing(5);

    triangoloISlabelLayout->addLayout(triangoloISfirstLayout,0,0);
    triangoloISlabelLayout->addLayout(triangoloISsecondLayout,1,0);

    //aggiungi layout al layout principale
    triangoloIsosceleLayout->addLayout(triangoloISimageLayout);
    triangoloIsosceleLayout->addLayout(triangoloISlabelLayout);
    triangoloIsosceleLayout->addLayout(triangoloIScalcoloLayout);

    triangoloIsosceleTab->setLayout(triangoloIsosceleLayout);


    //triangoloScalenoTab
    QWidget* triangoloScalenoTab = new QWidget;

    QVBoxLayout* triangoloScalenoLayout = new QVBoxLayout;

    //image
    QVBoxLayout* triangoloSCimageLayout = new QVBoxLayout;
    QLabel* imageTriangoloSC = new QLabel;
    imageTriangoloSC->setMinimumSize(200,200);
    imageTriangoloSC->setMaximumSize(800,800);
    QPixmap picTriangoloSC(":/Images/TriangoloScaleno.png");
    imageTriangoloSC->setPixmap(picTriangoloSC);
    triangoloSCimageLayout->addWidget(imageTriangoloSC);
    triangoloSCimageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* triangoloSCcalcoloLayout = new QHBoxLayout;
    calcolaTriangoloSC = new QPushButton("Calcola");
    calcolaTriangoloSC->setMinimumSize(100,30);
    calcolaTriangoloSC->setMaximumSize(100,30);
    triangoloSCcalcoloLayout->addWidget(calcolaTriangoloSC);
    triangoloSCcalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* triangoloSClabelLayout = new QGridLayout;

    QHBoxLayout* triangoloSCfirstLayout = new QHBoxLayout;
    triangoloSCfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertLato1TriangoloSC = new QLabel("Lato 1:");
    insertLato1TriangoloSC->setMaximumSize(60,30);
    lineLato1TriangoloSC = new QLineEdit;
    lineLato1TriangoloSC->setMaximumSize(100,30);

    QHBoxLayout* triangoloSCsecondLayout = new QHBoxLayout;
    triangoloSCsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertLato2TriangoloSC = new QLabel("Lato 2:");
    insertLato2TriangoloSC->setMaximumSize(60,30);
    lineLato2TriangoloSC = new QLineEdit;
    lineLato2TriangoloSC->setMaximumSize(100,30);

    QHBoxLayout* triangoloSCthirdLayout = new QHBoxLayout;
    triangoloSCthirdLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertLato3TriangoloSC = new QLabel("Lato 3:");
    insertLato3TriangoloSC->setMaximumSize(60,30);
    lineLato3TriangoloSC = new QLineEdit;
    lineLato3TriangoloSC->setMaximumSize(100,30);

    //aggiunta widget ai layout
    triangoloSCfirstLayout->addWidget(insertLato1TriangoloSC);
    triangoloSCfirstLayout->addWidget(lineLato1TriangoloSC);
    triangoloSCfirstLayout->setSpacing(5);

    triangoloSCsecondLayout->addWidget(insertLato2TriangoloSC);
    triangoloSCsecondLayout->addWidget(lineLato2TriangoloSC);
    triangoloSCsecondLayout->setSpacing(5);

    triangoloSCthirdLayout->addWidget(insertLato3TriangoloSC);
    triangoloSCthirdLayout->addWidget(lineLato3TriangoloSC);
    triangoloSCthirdLayout->setSpacing(5);

    triangoloSClabelLayout->addLayout(triangoloSCfirstLayout,0,0);
    triangoloSClabelLayout->addLayout(triangoloSCsecondLayout,1,0);
    triangoloSClabelLayout->addLayout(triangoloSCthirdLayout,2,0);

    //aggiungi layout al layout principale
    triangoloScalenoLayout->addLayout(triangoloSCimageLayout);
    triangoloScalenoLayout->addLayout(triangoloSClabelLayout);
    triangoloScalenoLayout->addLayout(triangoloSCcalcoloLayout);

    triangoloScalenoTab->setLayout(triangoloScalenoLayout);


    //triangoloRettangoloTab
    QWidget* triangoloRettangoloTab = new QWidget;

    QVBoxLayout* triangoloRettangoloLayout = new QVBoxLayout;

    //image
    QVBoxLayout* triangoloRETTimageLayout = new QVBoxLayout;
    QLabel* imageTriangoloRETT = new QLabel;
    imageTriangoloRETT->setMinimumSize(200,200);
    imageTriangoloRETT->setMaximumSize(800,800);
    QPixmap picTriangoloRETT(":/Images/TriangoloRettangolo.png");
    imageTriangoloRETT->setPixmap(picTriangoloRETT);
    triangoloRETTimageLayout->addWidget(imageTriangoloRETT);
    triangoloRETTimageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* triangoloRETTcalcoloLayout = new QHBoxLayout;
    calcolaTriangoloRETT = new QPushButton("Calcola");
    calcolaTriangoloRETT->setMinimumSize(100,30);
    calcolaTriangoloRETT->setMaximumSize(100,30);
    triangoloRETTcalcoloLayout->addWidget(calcolaTriangoloRETT);
    triangoloRETTcalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* triangoloRETTlabelLayout = new QGridLayout;

    QHBoxLayout* triangoloRETTfirstLayout = new QHBoxLayout;
    triangoloRETTfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertBaseTriangoloRETT = new QLabel("Base:");
    insertBaseTriangoloRETT->setMaximumSize(80,30);
    lineBaseTriangoloRETT = new QLineEdit;
    lineBaseTriangoloRETT->setMaximumSize(100,30);

    QHBoxLayout* triangoloRETTsecondLayout = new QHBoxLayout;
    triangoloRETTsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertAltezzaTriangoloRETT = new QLabel("Altezza:");
    insertAltezzaTriangoloRETT->setMaximumSize(80,30);
    lineAltezzaTriangoloRETT = new QLineEdit;
    lineAltezzaTriangoloRETT->setMaximumSize(100,30);

    QHBoxLayout* triangoloRETTthirdLayout = new QHBoxLayout;
    triangoloRETTthirdLayout->setAlignment(Qt::AlignCenter);
    QLabel* insertIpotenusa = new QLabel("Ipotenusa:");
    insertIpotenusa->setMaximumSize(80,30);
    lineIpotenusa = new QLineEdit;
    lineIpotenusa->setMaximumSize(100,30);

    //aggiunta widget ai layout
    triangoloRETTfirstLayout->addWidget(insertBaseTriangoloRETT);
    triangoloRETTfirstLayout->addWidget(lineBaseTriangoloRETT);
    triangoloRETTfirstLayout->setSpacing(5);

    triangoloRETTsecondLayout->addWidget(insertAltezzaTriangoloRETT);
    triangoloRETTsecondLayout->addWidget(lineAltezzaTriangoloRETT);
    triangoloRETTsecondLayout->setSpacing(5);

    triangoloRETTthirdLayout->addWidget(insertIpotenusa);
    triangoloRETTthirdLayout->addWidget(lineIpotenusa);
    triangoloRETTthirdLayout->setSpacing(5);

    triangoloRETTlabelLayout->addLayout(triangoloRETTfirstLayout,0,0);
    triangoloRETTlabelLayout->addLayout(triangoloRETTsecondLayout,1,0);
    triangoloRETTlabelLayout->addLayout(triangoloRETTthirdLayout,2,0);

    //aggiungi layout al layout principale
    triangoloRettangoloLayout->addLayout(triangoloRETTimageLayout);
    triangoloRettangoloLayout->addLayout(triangoloRETTlabelLayout);
    triangoloRettangoloLayout->addLayout(triangoloRETTcalcoloLayout);

    triangoloRettangoloTab->setLayout(triangoloRettangoloLayout);


    //triangoloTab
    QTabWidget* TriangoloTab = new QTabWidget;
    TriangoloTab->addTab(triangoloEQuilateroTab, "Triangolo Equilatero");
    TriangoloTab->addTab(triangoloIsosceleTab, "Triangolo Isoscele");
    TriangoloTab->addTab(triangoloScalenoTab, "Triangolo Scaleno");
    TriangoloTab->addTab(triangoloRettangoloTab, "Triangolo Rettangolo");



    //trapezioScalenoTab
    QWidget* trapezioScalenoTab = new QWidget;

    QVBoxLayout* trapezioScalenoLayout = new QVBoxLayout;

    //image
    QVBoxLayout* trapezioSCimageLayout = new QVBoxLayout;
    QLabel* imageTrapezioSC = new QLabel;
    imageTrapezioSC->setMinimumSize(200,200);
    imageTrapezioSC->setMaximumSize(800,800);
    QPixmap picTrapezioSC(":/Images/TrapezioScaleno.png");
    imageTrapezioSC->setPixmap(picTrapezioSC);
    trapezioSCimageLayout->addWidget(imageTrapezioSC);
    trapezioSCimageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* trapezioSCcalcoloLayout = new QHBoxLayout;
    calcolaTrapezioSC = new QPushButton("Calcola");
    calcolaTrapezioSC->setMinimumSize(100,30);
    calcolaTrapezioSC->setMaximumSize(100,30);
    trapezioSCcalcoloLayout->addWidget(calcolaTrapezioSC);
    trapezioSCcalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* trapezioSClabelLayout = new QGridLayout;

    QHBoxLayout* tarpezioSCfirstLayout = new QHBoxLayout;
    tarpezioSCfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioSCinsertBaseM = new QLabel("Base maggiore:");
    trapezioSCinsertBaseM->setMaximumSize(120,30);
    trapezioSClineBaseM = new QLineEdit;
    trapezioSClineBaseM->setMaximumSize(100,30);

    QHBoxLayout* trapezioSCsecondLayout = new QHBoxLayout;
    trapezioSCsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioSCinsertBasem = new QLabel("Base minore:");
    trapezioSCinsertBasem->setMaximumSize(120,30);
    trapezioSClineBasem = new QLineEdit;
    trapezioSClineBasem->setMaximumSize(100,30);

    QHBoxLayout* TrapezioSCthirdLayout = new QHBoxLayout;
    TrapezioSCthirdLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioSCinsertLato1 = new QLabel( "Lato 1:");
    trapezioSCinsertLato1->setMaximumSize(120,30);
    trapezioSClineLato1 = new QLineEdit;
    trapezioSClineLato1->setMaximumSize(100,30);

    QHBoxLayout* trapezioSCfourthLayout = new QHBoxLayout;
    trapezioSCfourthLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioSCinsertLato2 = new QLabel("Lato 2:");
    trapezioSCinsertLato2->setMaximumSize(120,30);
    trapezioSClineLato2 = new QLineEdit;
    trapezioSClineLato2->setMaximumSize(100,30);

    //aggiunta widget ai layout
    tarpezioSCfirstLayout->addWidget(trapezioSCinsertBaseM);
    tarpezioSCfirstLayout->addWidget(trapezioSClineBaseM);
    tarpezioSCfirstLayout->setSpacing(5);

    trapezioSCsecondLayout->addWidget(trapezioSCinsertBasem);
    trapezioSCsecondLayout->addWidget(trapezioSClineBasem);
    trapezioSCsecondLayout->setSpacing(5);

    TrapezioSCthirdLayout->addWidget(trapezioSCinsertLato1);
    TrapezioSCthirdLayout->addWidget(trapezioSClineLato1);
    TrapezioSCthirdLayout->setSpacing(5);

    trapezioSCfourthLayout->addWidget(trapezioSCinsertLato2);
    trapezioSCfourthLayout->addWidget(trapezioSClineLato2);

    trapezioSClabelLayout->addLayout(tarpezioSCfirstLayout,0,0);
    trapezioSClabelLayout->addLayout(trapezioSCsecondLayout,1,0);
    trapezioSClabelLayout->addLayout(TrapezioSCthirdLayout,2,0);
    trapezioSClabelLayout->addLayout(trapezioSCfourthLayout,4,0);

    //aggiungi layout al layout principale
    trapezioScalenoLayout->addLayout(trapezioSCimageLayout);
    trapezioScalenoLayout->addLayout(trapezioSClabelLayout);
    trapezioScalenoLayout->addLayout(trapezioSCcalcoloLayout);

    trapezioScalenoTab->setLayout(trapezioScalenoLayout);


    //trapezioIsosceleTab
    QWidget* trapezioIsosceleTab = new QWidget;

    QVBoxLayout* trapezioIsosceleLayout = new QVBoxLayout;

    //image
    QVBoxLayout* imageLayout = new QVBoxLayout;
    QLabel* imageTrapezioIS = new QLabel;
    imageTrapezioIS->setMinimumSize(200,200);
    imageTrapezioIS->setMaximumSize(800,800);
    QPixmap picTrapezioIS(":/Images/TrapezioIsoscele.png");
    imageTrapezioIS->setPixmap(picTrapezioIS);
    imageLayout->addWidget(imageTrapezioIS);
    imageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* trapezioIScalcoloLayout = new QHBoxLayout;
    calcolaTrapezioIS = new QPushButton("Calcola");
    calcolaTrapezioIS->setMinimumSize(100,30);
    calcolaTrapezioIS->setMaximumSize(100,30);
    trapezioIScalcoloLayout->addWidget(calcolaTrapezioIS);
    trapezioIScalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* trapezioISlabelLayout = new QGridLayout;

    QHBoxLayout* trapezioISfirstLayout = new QHBoxLayout;
    trapezioISfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioISinsertBaseM = new QLabel("Base maggiore:");
    trapezioISinsertBaseM->setMaximumSize(120,30);
    trapezioISlineBaseM = new QLineEdit;
    trapezioISlineBaseM->setMaximumSize(100,30);

    QHBoxLayout* trapezioISsecondLayout = new QHBoxLayout;
    trapezioISsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioISinsertBasem = new QLabel("Base minore:");
    trapezioISinsertBasem->setMaximumSize(120,30);
    trapezioISlineBasem = new QLineEdit;
    trapezioISlineBasem->setMaximumSize(100,30);

    QHBoxLayout* trapezioISthirdLayout = new QHBoxLayout;
    trapezioISthirdLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioISinsertLato = new QLabel("Lato:");
    trapezioISinsertLato->setMaximumSize(120,30);
    trapezioISlineLato = new QLineEdit;
    trapezioISlineLato->setMaximumSize(100,30);

    //aggiunta widget ai layout
    trapezioISfirstLayout->addWidget(trapezioISinsertBaseM);
    trapezioISfirstLayout->addWidget(trapezioISlineBaseM);
    trapezioISfirstLayout->setSpacing(5);

    trapezioISsecondLayout->addWidget(trapezioISinsertBasem);
    trapezioISsecondLayout->addWidget(trapezioISlineBasem);
    trapezioISsecondLayout->setSpacing(5);

    trapezioISthirdLayout->addWidget(trapezioISinsertLato);
    trapezioISthirdLayout->addWidget(trapezioISlineLato);
    trapezioISthirdLayout->setSpacing(5);

    trapezioISlabelLayout->addLayout(trapezioISfirstLayout,0,0);
    trapezioISlabelLayout->addLayout(trapezioISsecondLayout,1,0);
    trapezioISlabelLayout->addLayout(trapezioISthirdLayout,2,0);

    //aggiungi layout al layout principale
    trapezioIsosceleLayout->addLayout(imageLayout);
    trapezioIsosceleLayout->addLayout(trapezioISlabelLayout);
    trapezioIsosceleLayout->addLayout(trapezioIScalcoloLayout);

    trapezioIsosceleTab->setLayout(trapezioIsosceleLayout);


    //trapezioRettangoloTab
    QWidget* trapezioRettangoloTab = new QWidget;

    QVBoxLayout* trapezioRettangoloLayout = new QVBoxLayout;

    //image
    QVBoxLayout* trapezioRETTimageLayout = new QVBoxLayout;
    QLabel* imageTrapezioRETT = new QLabel;
    imageTrapezioRETT->setMinimumSize(200,200);
    imageTrapezioRETT->setMaximumSize(800,800);
    QPixmap picTrapezioRETT(":/Images/TrapezioRettangolo.png");
    imageTrapezioRETT->setPixmap(picTrapezioRETT);
    trapezioRETTimageLayout->addWidget(imageTrapezioRETT);
    trapezioRETTimageLayout->setAlignment(Qt::AlignCenter);

    //button
    QHBoxLayout* trapezioRETTcalcoloLayout = new QHBoxLayout;
    calcolaTrapezioRETT = new QPushButton("Calcola");
    calcolaTrapezioRETT->setMinimumSize(100,30);
    calcolaTrapezioRETT->setMaximumSize(100,30);
    trapezioRETTcalcoloLayout->addWidget(calcolaTrapezioRETT);
    trapezioRETTcalcoloLayout->setContentsMargins(20,20,20,20);

    //label + inserimento
    QGridLayout* trapezioRETTlabelLayout = new QGridLayout;

    QHBoxLayout* trapezioRETTfirstLayout = new QHBoxLayout;
    trapezioRETTfirstLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioRETTinsertBaseM = new QLabel("Base maggiore:");
    trapezioRETTinsertBaseM->setMaximumSize(120,30);
    trapezioRETTlineBaseM = new QLineEdit;
    trapezioRETTlineBaseM->setMaximumSize(100,30);

    QHBoxLayout* trapezioRETTsecondLayout = new QHBoxLayout;
    trapezioRETTsecondLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioRETTinsertBasem = new QLabel("Base minore:");
    trapezioRETTinsertBasem->setMaximumSize(120,30);
    trapezioRETTlineBasem = new QLineEdit;
    trapezioRETTlineBasem->setMaximumSize(100,30);

    QHBoxLayout* trapezioRETTthirdLayout = new QHBoxLayout;
    trapezioRETTthirdLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioRETTinsertAltezza = new QLabel("Altezza:");
    trapezioRETTinsertAltezza->setMaximumSize(120,30);
    trapezioRETTlineAltezza = new QLineEdit;
    trapezioRETTlineAltezza->setMaximumSize(100,30);

    QHBoxLayout* trapezioRETTfourthLayout = new QHBoxLayout;
    trapezioRETTfourthLayout->setAlignment(Qt::AlignCenter);
    QLabel* trapezioRETTinsertLato = new QLabel("Lato:");
    trapezioRETTinsertLato->setMaximumSize(120,30);
    trapezioRETTlineLato = new QLineEdit;
    trapezioRETTlineLato->setMaximumSize(100,30);

    //aggiunta widget ai layout
    trapezioRETTfirstLayout->addWidget(trapezioRETTinsertBaseM);
    trapezioRETTfirstLayout->addWidget(trapezioRETTlineBaseM);
    trapezioRETTfirstLayout->setSpacing(5);

    trapezioRETTsecondLayout->addWidget(trapezioRETTinsertBasem);
    trapezioRETTsecondLayout->addWidget(trapezioRETTlineBasem);
    trapezioRETTsecondLayout->setSpacing(5);

    trapezioRETTthirdLayout->addWidget(trapezioRETTinsertAltezza);
    trapezioRETTthirdLayout->addWidget(trapezioRETTlineAltezza);
    trapezioRETTthirdLayout->setSpacing(5);

    trapezioRETTfourthLayout->addWidget(trapezioRETTinsertLato);
    trapezioRETTfourthLayout->addWidget(trapezioRETTlineLato);

    trapezioRETTlabelLayout->addLayout(trapezioRETTfirstLayout,0,0);
    trapezioRETTlabelLayout->addLayout(trapezioRETTsecondLayout,1,0);
    trapezioRETTlabelLayout->addLayout(trapezioRETTthirdLayout,2,0);
    trapezioRETTlabelLayout->addLayout(trapezioRETTfourthLayout,4,0);

    //aggiungi layout al layout principale
    trapezioRettangoloLayout->addLayout(trapezioRETTimageLayout);
    trapezioRettangoloLayout->addLayout(trapezioRETTlabelLayout);
    trapezioRettangoloLayout->addLayout(trapezioRETTcalcoloLayout);

    trapezioRettangoloTab->setLayout(trapezioRettangoloLayout);


    //trapezioTab
    QTabWidget* trapezioTab = new QTabWidget;


    trapezioTab->addTab(trapezioScalenoTab, "Trapezio Scaleno");
    trapezioTab->addTab(trapezioIsosceleTab, "Trapezio Isoscele");
    trapezioTab->addTab(trapezioRettangoloTab, "Trapezio Rettangolo");



    //mainTab
    QTabWidget* mainTab = new QTabWidget(this);

    mainTab->addTab(TriangoloTab, "Triangolo");
    mainTab->addTab(rettangoloTab, "Rettangolo");
    mainTab->addTab(quadratoTab,"Quadrato");
    mainTab->addTab(trapezioTab, "Trapezio");
    mainTab->addTab(cerchioTab, "Cerchio");

    //imposta layout
    mainLayout->addWidget(menuBar);
    mainLayout->addWidget(desc);
    mainLayout->addWidget(mainTab);

    setGeometryCalcStyle();
    setLayout(mainLayout);
}

View::~View() { delete inizio; delete precedente; delete successivo; delete fine; delete rimuovi; delete conferma; delete annulla; }

void View::setController(Controller *c)
{
    controller = c;


    connect(chiudi, SIGNAL(triggered()), this, SLOT(close()));
    connect(calcolaQuadrato, SIGNAL(clicked()), controller, SLOT(onQuadratoClicked()));
    connect(calcolaTriangoloEQ, SIGNAL(clicked()), controller, SLOT(onTriangoloEquilateroClicked()));
    connect(calcolaTriangoloIS, SIGNAL(clicked()), controller, SLOT(onTriangoloIsosceleClicked()));
    connect(calcolaTriangoloSC, SIGNAL(clicked()), controller, SLOT(onTriangoloScalenoClicked()));
    connect(calcolaTriangoloRETT, SIGNAL(clicked()), controller, SLOT(onTriangoloRettangoloClicked()));
    connect(calcolaRettangolo, SIGNAL(clicked()), controller, SLOT(onRettangoloClicked()));
    connect(calcolaTrapezioSC, SIGNAL(clicked()), controller, SLOT(onTrapezioScalenoClicked()));
    connect(calcolaTrapezioIS, SIGNAL(clicked()), controller, SLOT(onTrapezioIsosceleClicked()));
    connect(calcolaTrapezioRETT, SIGNAL(clicked()), controller, SLOT(onTrapezioRettangoloClicked()));
    connect(calcolaCerchio, SIGNAL(clicked()), controller, SLOT(onCerchioClicked()));
    connect(mostra, SIGNAL(triggered()), controller, SLOT(onMostraCronologiaTriggered()));
    connect(cancella, SIGNAL(triggered()), controller, SLOT(onEliminaCronologiaTriggered()));
    connect(inizio, SIGNAL(clicked()), controller, SLOT(onInizioClicked()));
    connect(precedente, SIGNAL(clicked()), controller, SLOT(onPrecedenteClicked()));
    connect(successivo, SIGNAL(clicked()), controller, SLOT(onSuccessivoClicked()));
    connect(fine, SIGNAL(clicked()), controller, SLOT(onFineClicked()));
    connect(rimuovi, SIGNAL(clicked()), controller, SLOT(onRimuoviClicked()));
    connect(conferma, SIGNAL(clicked()), controller, SLOT(onConfermaClicked()));
    connect(annulla, SIGNAL(clicked()), controller, SLOT(onAnnullaClicked()));
}

void View::showDialog()
{
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->setAlignment(Qt::AlignCenter);
    dialog->setWindowTitle("Risultati");
    dialog->setMinimumSize(250,100);
    dialog->setMaximumSize(250,100);
    std::stringstream text;
    text<<"Perimetro = "<<controller->getPerimetro()<<"\nArea = "<<controller->getArea()<<std::endl;
    layout->addWidget(new QLabel(QString::fromStdString(text.str()),dialog));
    dialog->exec();
}

void View::showVuota()
{
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->setAlignment(Qt::AlignCenter);
    dialog->setWindowTitle("Cronologia Vuota");
    dialog->setMinimumSize(250,100);
    dialog->setMaximumSize(500,200);
    std::stringstream text;
    text<<"Nessun elemento è presente nella cronologia."<<std::endl;
    layout->addWidget(new QLabel(QString::fromStdString(text.str()),dialog));
    dialog->exec();

}

void View::showEliminatoUltimo()
{
    cronologia->close();
    QDialog* dialog = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(dialog);
    layout->setAlignment(Qt::AlignCenter);
    dialog->setWindowTitle("Cronologia Vuota");
    dialog->setMinimumSize(250,100);
    dialog->setMaximumSize(500,200);
    std::stringstream text;
    text<<"Cronologia vuota."<<std::endl;
    layout->addWidget(new QLabel(QString::fromStdString(text.str()),dialog));
    dialog->exec();
}

void View::showCronologia()
{
    cronologia = new QDialog(this);
    QVBoxLayout* layout = new QVBoxLayout(cronologia);

    cronologia->setWindowTitle("Cronologia");
    cronologia->setMinimumSize(500,250);
    cronologia->setMaximumSize(500,250);

    std::stringstream text;
    text<<controller->getInfo() << "\n\n\nPerimetro = "<<controller->getPerimetro()<<"\nArea = "<<controller->getArea()<<std::endl;
    layout->addWidget(new QLabel(QString::fromStdString(text.str()),cronologia));
    layout->setAlignment(Qt::AlignCenter);

    QSpacerItem* spacer = new QSpacerItem(25,25);
    inizio->setMinimumSize(70,25);
    precedente->setMinimumSize(70,25);
    successivo->setMinimumSize(70,25);
    fine->setMinimumSize(70,25);
    rimuovi->setMinimumSize(70,25);

    QHBoxLayout* button = new QHBoxLayout;
    button->addWidget(inizio);
    button->addWidget(precedente);
    button->addWidget(successivo);
    button->addWidget(fine);
    button->addSpacerItem(spacer);
    button->addWidget(rimuovi);

    layout->addLayout(button);


    cronologia->exec();
}

void View::updateCronologia()
{
    cronologia->close();
    showCronologia();
}



void View::showWarning(const QString& message){
QDialog* dialog = new QDialog(this);

dialog->setLayout(new QHBoxLayout);
dialog->layout()->addWidget(new QLabel(message, dialog));
dialog->layout()->setAlignment(Qt::AlignCenter);
dialog->setWindowTitle("Errore");
dialog->setMinimumSize(250,70);
dialog->setMaximumSize(250,70);

dialog->exec();
}

void View::showError(const QString& message){
QDialog* dialog = new QDialog(this);

dialog->setLayout(new QHBoxLayout);
dialog->layout()->addWidget(new QLabel(message, dialog));
dialog->layout()->setAlignment(Qt::AlignCenter);
dialog->setWindowTitle("Errore");
dialog->setMinimumSize(250,70);

dialog->exec();
}

void View::showConfirmationDialog()
{
    confirmation = new QDialog(this);
    confirmation->setWindowTitle(" ");
    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->setAlignment(Qt::AlignCenter);
    QHBoxLayout* button = new QHBoxLayout;
    annulla->setMinimumSize(70,25);
    conferma->setMaximumSize(100,30);
    annulla->setMinimumSize(70,15);
    annulla->setMaximumSize(100,20);
    button->addWidget(conferma);
    button->addWidget(annulla);
    QLabel* message = new QLabel("Sei sicuro di voler eliminare l'intera cronologia?");
    QSpacerItem* space = new QSpacerItem(25,25);
    mainLayout->addWidget(message);
    mainLayout->addItem(space);
    mainLayout->addLayout(button);
    confirmation->setLayout(mainLayout);

    confirmation->exec();

}

void View::confirmationClose()
{
    confirmation->close();
}


double View::getTriangoloEquilateroLine() const
{
    QString x = lineTriangoloEQ->text();
    if(x.toDouble()<= 0)
    {
        lineTriangoloEQ->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineTriangoloEQ->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloIsosceleLineBase() const
{
    QString x = lineTriangoloISBase->text();
    if(x.toDouble()<= 0)
    {
        lineTriangoloISBase->setStyleSheet("border: 1px solid red");

        if((lineTriangoloISLato->text()).toDouble() <= 0) lineTriangoloISLato->setStyleSheet("border: 1px solid red");
        else  lineTriangoloISLato->setStyleSheet("border: black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineTriangoloISBase->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloIsosceleLineLato() const
{
    QString x = lineTriangoloISLato->text();
    if(x.toDouble()<= 0)
    {
        if((lineTriangoloISBase->text()).toDouble() <= 0) lineTriangoloISBase->setStyleSheet("border: 1px solid red");
        else  lineTriangoloISBase->setStyleSheet("border: black");

        lineTriangoloISLato->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else  lineTriangoloISLato->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloScalenoLineLato1() const
{
    QString x = lineLato1TriangoloSC->text();
    if(x.toDouble()<= 0)
    {
        lineLato1TriangoloSC->setStyleSheet("border: 1px solid red");

        if((lineLato2TriangoloSC->text()).toDouble() <= 0) lineLato2TriangoloSC->setStyleSheet("border: 1px solid red");
        else lineLato2TriangoloSC->setStyleSheet("border: black");

        if((lineLato3TriangoloSC->text()).toDouble() <= 0) lineLato3TriangoloSC->setStyleSheet("border: 1px solid red");
        else  lineLato3TriangoloSC->setStyleSheet("border: black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineLato1TriangoloSC->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloScalenoLineLato2() const
{
    QString x = lineLato2TriangoloSC->text();
    if(x.toDouble()<= 0)
    {
        if((lineLato1TriangoloSC->text()).toDouble() <= 0) lineLato1TriangoloSC->setStyleSheet("border: 1px solid red");
        else lineLato1TriangoloSC->setStyleSheet("border: black");

        lineLato2TriangoloSC->setStyleSheet("border: 1px solid red");

        if((lineLato3TriangoloSC->text()).toDouble() <= 0) lineLato3TriangoloSC->setStyleSheet("border: 1px solid red");
        else lineLato3TriangoloSC->setStyleSheet("border: black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineLato2TriangoloSC->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloScalenoLineLato3() const
{
    QString x = lineLato3TriangoloSC->text();
    if(x.toDouble()<= 0)
    {
        if((lineLato1TriangoloSC->text()).toDouble() <= 0) lineLato1TriangoloSC->setStyleSheet("border: 1px solid red");
        else lineLato1TriangoloSC->setStyleSheet("border: black");

        if((lineLato2TriangoloSC->text()).toDouble() <= 0) lineLato2TriangoloSC->setStyleSheet("border: 1px solid red");
        else lineLato2TriangoloSC->setStyleSheet("border: black");

        lineLato3TriangoloSC->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineLato3TriangoloSC->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloRettangoloIpotenusa() const
{
    QString x = lineIpotenusa->text();
    if(x.toDouble()<= 0)
    {
        if((lineBaseTriangoloRETT->text()).toDouble() <= 0) lineBaseTriangoloRETT->setStyleSheet("border: 1px solid red");
        else lineBaseTriangoloRETT->setStyleSheet("border: black");

        if((lineAltezzaTriangoloRETT->text()).toDouble() <= 0) lineAltezzaTriangoloRETT->setStyleSheet("border: 1px solid red");
        else lineAltezzaTriangoloRETT->setStyleSheet("border: black");

        lineIpotenusa->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else  lineIpotenusa->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloRettangoloAltezza() const
{
    QString x = lineAltezzaTriangoloRETT->text();
    if(x.toDouble()<= 0)
    {
        if((lineBaseTriangoloRETT->text()).toDouble() <= 0) lineBaseTriangoloRETT->setStyleSheet("border: 1px solid red");
        else lineBaseTriangoloRETT->setStyleSheet("border: black");

        lineAltezzaTriangoloRETT->setStyleSheet("border: 1px solid red");

        if((lineIpotenusa->text()).toDouble() <= 0) lineIpotenusa->setStyleSheet("border: 1px solid red");
        else lineIpotenusa->setStyleSheet("border: black");
        throw std::out_of_range("Valore non ammesso.");
    }

    else lineAltezzaTriangoloRETT->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTriangoloRettangoloBase() const
{
    QString x = lineBaseTriangoloRETT->text();
    if(x.toDouble()<= 0)
    {
        lineBaseTriangoloRETT->setStyleSheet("border: 1px solid red");

        if((lineAltezzaTriangoloRETT->text()).toDouble() <= 0) lineAltezzaTriangoloRETT->setStyleSheet("border: 1px solid red");
        else lineAltezzaTriangoloRETT->setStyleSheet("border: black");

        if((lineIpotenusa->text()).toDouble() <= 0) lineIpotenusa->setStyleSheet("border: 1px solid red");
        else lineIpotenusa->setStyleSheet("border: black");
        throw std::out_of_range("Valore non ammesso.");
    }

    else lineBaseTriangoloRETT->setStyleSheet("border: Black");

    return x.toDouble();
}

double View::getQuadratoLine()const
{
    QString x = lineQuadrato->text();
    if(x.toDouble()<= 0)
    {
        lineQuadrato->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineQuadrato->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getRettangoloBase() const
{
    QString x = lineRettangoloAltezza->text();
    if(x.toDouble()<= 0)
    {
        if((lineRettangoloBase->text()).toDouble() <= 0) lineRettangoloBase->setStyleSheet("border: 1px solid red");
        else lineRettangoloBase->setStyleSheet("border: black");

        lineRettangoloAltezza->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineRettangoloAltezza->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getRettangoloAltezza() const
{
    QString x = lineRettangoloBase->text();
    if(x.toDouble()<= 0)
    {
        lineRettangoloBase->setStyleSheet("border: 1px solid red");

        if((lineRettangoloAltezza->text()).toDouble() <= 0) lineRettangoloAltezza->setStyleSheet("border: 1px solid red");
        else lineRettangoloAltezza->setStyleSheet("border: black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else lineRettangoloBase->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioSCBaseMaggiore() const
{
    QString x = trapezioSClineBaseM->text();
    if(x.toDouble()<= 0)
    {
        trapezioSClineBaseM->setStyleSheet("border: 1px solid red");

        if(trapezioSClineBasem->text().toDouble() <= 0) trapezioSClineBasem->setStyleSheet("border: 1px solid red");
        else trapezioSClineBasem->setStyleSheet("border:black");

        if(trapezioSClineLato1->text().toDouble() <= 0) trapezioSClineLato1->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato1->setStyleSheet("border:black");

        if(trapezioSClineLato2->text().toDouble() <= 0) trapezioSClineLato2->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato2->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioSClineBaseM->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioSCBaseMinore() const
{
    QString x = trapezioSClineBasem->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioSClineBaseM->text().toDouble() <= 0) trapezioSClineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioSClineBaseM->setStyleSheet("border:black");

        trapezioSClineBasem->setStyleSheet("border: 1px solid red");

        if(trapezioSClineLato1->text().toDouble() <= 0) trapezioSClineLato1->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato1->setStyleSheet("border:black");

        if(trapezioSClineLato2->text().toDouble() <= 0) trapezioSClineLato2->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato2->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioSClineBasem->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioSCLato1() const
{
    QString x = trapezioSClineLato1->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioSClineBaseM->text().toDouble() <= 0) trapezioSClineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioSClineBaseM->setStyleSheet("border:black");

        if(trapezioSClineBasem->text().toDouble() <= 0) trapezioSClineBasem->setStyleSheet("border: 1px solid red");
        else trapezioSClineBasem->setStyleSheet("border:black");

        trapezioSClineLato1->setStyleSheet("border: 1px solid red");

        if(trapezioSClineLato2->text().toDouble() <= 0) trapezioSClineLato2->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato2->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioSClineLato1->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioSCLato2() const
{
    QString x = trapezioSClineLato2->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioSClineBaseM->text().toDouble() <= 0) trapezioSClineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioSClineBaseM->setStyleSheet("border:black");

        if(trapezioSClineBasem->text().toDouble() <= 0) trapezioSClineBasem->setStyleSheet("border: 1px solid red");
        else trapezioSClineBasem->setStyleSheet("border:black");

        if(trapezioSClineLato1->text().toDouble() <= 0) trapezioSClineLato1->setStyleSheet("border: 1px solid red");
        else trapezioSClineLato1->setStyleSheet("border:black");

        trapezioSClineLato2->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioSClineLato2->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioISBaseMaggiore() const
{
    QString x = trapezioISlineBaseM->text();
    if(x.toDouble()<= 0)
    {
        trapezioISlineBaseM->setStyleSheet("border: 1px solid red");

        if(trapezioISlineBasem->text().toDouble() <= 0) trapezioISlineBasem->setStyleSheet("border: 1px solid red");
        else trapezioISlineBasem->setStyleSheet("border:black");

        if(trapezioISlineLato->text().toDouble() <= 0) trapezioISlineLato->setStyleSheet("border: 1px solid red");
        else trapezioISlineLato->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioISlineBaseM->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioISBaseMinore() const
{
    QString x = trapezioISlineBasem->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioISlineBaseM->text().toDouble() <= 0) trapezioISlineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioISlineBaseM->setStyleSheet("border:black");

        trapezioISlineBasem->setStyleSheet("border: 1px solid red");

        if(trapezioISlineLato->text().toDouble() <= 0) trapezioISlineLato->setStyleSheet("border: 1px solid red");
        else trapezioISlineLato->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioISlineBasem->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioISLato() const
{
    QString x = trapezioISlineLato->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioISlineBaseM->text().toDouble() <= 0) trapezioISlineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioISlineBaseM->setStyleSheet("border:black");

        if(trapezioISlineBasem->text().toDouble() <= 0) trapezioISlineBasem->setStyleSheet("border: 1px solid red");
        else trapezioISlineBasem->setStyleSheet("border:black");

        trapezioISlineLato->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioISlineLato->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioRETTBaseMaggiore() const
{
    QString x = trapezioRETTlineBaseM->text();
    if(x.toDouble()<= 0)
    {
        trapezioRETTlineBaseM->setStyleSheet("border: 1px solid red");

        if(trapezioRETTlineBasem->text().toDouble() <= 0) trapezioRETTlineBasem->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBasem->setStyleSheet("border:black");

        if(trapezioRETTlineAltezza->text().toDouble() <= 0) trapezioRETTlineAltezza->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineAltezza->setStyleSheet("border:black");

        if(trapezioRETTlineLato->text().toDouble() <= 0) trapezioRETTlineLato->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineLato->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioRETTlineBaseM->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioRETTBaseMinore() const
{
    QString x = trapezioRETTlineBasem->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioRETTlineBaseM->text().toDouble() <= 0) trapezioRETTlineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBaseM->setStyleSheet("border:black");

        trapezioRETTlineBasem->setStyleSheet("border: 1px solid red");

        if(trapezioRETTlineAltezza->text().toDouble() <= 0) trapezioRETTlineAltezza->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineAltezza->setStyleSheet("border:black");

        if(trapezioRETTlineLato->text().toDouble() <= 0) trapezioRETTlineLato->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineLato->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioRETTlineBasem->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioRETTAltezza() const
{
    QString x = trapezioRETTlineAltezza->text();
    if(x.toDouble()<= 0)
    {
        if(trapezioRETTlineBaseM->text().toDouble() <= 0) trapezioRETTlineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBaseM->setStyleSheet("border:black");

        if(trapezioRETTlineBasem->text().toDouble() <= 0) trapezioRETTlineBasem->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBasem->setStyleSheet("border:black");;

        trapezioRETTlineAltezza->setStyleSheet("border: 1px solid red");

        if(trapezioRETTlineLato->text().toDouble() <= 0) trapezioRETTlineLato->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineLato->setStyleSheet("border:black");

        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioRETTlineAltezza->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getTrapezioRETTLato() const
{
    QString x = trapezioRETTlineLato->text();
    if(x.toDouble()<= 0)
    {

        if(trapezioRETTlineBaseM->text().toDouble() <= 0) trapezioRETTlineBaseM->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBaseM->setStyleSheet("border:black");

        if(trapezioRETTlineBasem->text().toDouble() <= 0) trapezioRETTlineBasem->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineBasem->setStyleSheet("border:black");

        if(trapezioRETTlineAltezza->text().toDouble() <= 0) trapezioRETTlineAltezza->setStyleSheet("border: 1px solid red");
        else trapezioRETTlineAltezza->setStyleSheet("border:black");

        trapezioRETTlineLato->setStyleSheet("border: 1px solid red");
        throw std::out_of_range("Valore non ammesso.");
    }

    else trapezioRETTlineLato->setStyleSheet("border: black");

    return x.toDouble();
}

double View::getCerchioRaggio() const
{
    QString x = cerchioLine->text();
    if(x.toDouble()<= 0)
    {
        cerchioLine->setStyleSheet("border: 1px solid red");

        throw std::out_of_range("Valore non ammesso.");
    }
    else cerchioLine->setStyleSheet("border: black");

    return x.toDouble();
}

void View::setGeometryCalcStyle()
{
    QFile file(":/Images/GeometryCalc.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());

        setStyleSheet(styleSheet);

}

