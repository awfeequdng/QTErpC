#ifndef REPISAARTICULOTIPO_H
#define REPISAARTICULOTIPO_H
#include <QMainWindow>
#include  "../Repisas/repisa.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Fabricas/fabricabasedatos.h"
#include <QSet>
#include <vector>
#include <QButtonGroup>
#include "../Formularios/formarticulotipo.h"

using namespace std;
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
public:
    RepisaArticuloTipo();


    void LlenarRepisa();
    void ActualizarMapa();
public slots:
    void NuevoClick();
    void BuscarClick();
    void AtrasClick();
    void SiguienteClick();
    void GrupoBotonesClick(QAbstractButton *buttonID);
};

#endif // REPISAARTICULOTIPO_H
