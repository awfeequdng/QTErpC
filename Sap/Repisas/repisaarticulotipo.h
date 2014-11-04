#ifndef REPISAARTICULOTIPO_H
#define REPISAARTICULOTIPO_H
#include <QMainWindow>
#include <QSet>
#include <vector>
#include <QButtonGroup>
#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Formularios/formarticulotipo.h"
#include "../Busqueda/busquedaarticulotipos.h"
#include "../DefBD.h"
using namespace std;
class FormArticuloTipo;
class RepisaArticuloTipo:public Repisa
{
    Q_OBJECT
private:
  FabricaArticuloTipos*         FabricaLocal;
  FormArticuloTipo*             Dialogo;
  BusquedaArticuloTipos*        Busqueda;
  static RepisaArticuloTipo* mUnico;
  RepisaArticuloTipo();
public:

    void ActualizarConsulta();
    void ObjetosIndependientes();
    static RepisaArticuloTipo* Iniciar();
public slots:
    void NuevoClick();
    void BuscarClick();

    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAARTICULOTIPO_H
