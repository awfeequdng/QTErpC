#ifndef REPISAARTICULOTIPO_H
#define REPISAARTICULOTIPO_H
#include <QMainWindow>
#include <QSet>
#include <vector>
#include <QButtonGroup>
#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Fabricas/fabricabasedatos.h"

#include "../Formularios/formarticulotipo.h"
#include "../DefBD.h"
using namespace std;
class FormArticuloTipo;
class RepisaArticuloTipo:public Repisa
{
    Q_OBJECT
private:
  FabricaBaseDatos*             Bd;
  FabricaArticuloTipos*         FabricaLocal;
  QMap<QString,ArticuloTipo>*   Mapa;
  QMap<QString,ArticuloTipo>::iterator it;
  vector<QPushButton*>          Botones;
  QButtonGroup*                 GrupoBotones;
  FormArticuloTipo*              Dialogo;

  int elementos;
  static RepisaArticuloTipo* mUnico;
  RepisaArticuloTipo();
public:

    void LlenarRepisa();
    void ActualizarMapa();
    static RepisaArticuloTipo* Iniciar();
public slots:
    void NuevoClick();
    void BuscarClick();
    void AtrasClick();
    void SiguienteClick();
    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAARTICULOTIPO_H
