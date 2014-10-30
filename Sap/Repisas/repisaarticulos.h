#ifndef REPISAARTICULOS_H
#define REPISAARTICULOS_H
#include <QMainWindow>
#include <QSet>
#include <vector>
#include <QButtonGroup>
#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaarticulos.h"

#include "../Formularios/formarticulos.h"
#include "../DefBD.h"
using namespace std;
class FormArticulos;
class RepisaArticulos:public Repisa
{
    Q_OBJECT
private:
  FabricaArticulos*         FabricaLocal;
  FormArticulos*              Dialogo;
  static RepisaArticulos* mUnico;
  RepisaArticulos();
public:

    void ActualizarMapa();
    void ObjetosIndependientes();
    static RepisaArticulos* Iniciar();
public slots:
    void NuevoClick();
    void BuscarClick();

    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAARTICULOS_H
