#ifndef BUSQUEDAARTICULOTIPOS_H
#define BUSQUEDAARTICULOTIPOS_H

#include <QWidget>
#include <QtGui>
#include <QCompleter>
#include "../Definiciones.h"
#include "../Fabricas/fabricaarticulotipos.h"
#include "../Fabricas/fabricabasedatos.h"
#include "../Extras/visorconsultas.h"
#include "../DefBD.h"
namespace Ui {
class BusquedaArticuloTipos;
}

class BusquedaArticuloTipos : public QWidget
{
    Q_OBJECT

public:
    explicit BusquedaArticuloTipos(QWidget *parent = 0);
    ~BusquedaArticuloTipos();
signals:
    void my_signal(QSqlQueryModel *);
    void SignalRepisa(ObjetoMaestro *);
private:
    Ui::BusquedaArticuloTipos *ui;
    FabricaArticuloTipos* Fab;
    FabricaBaseDatos* BD;
    VisorConsultas* VisorConsulta;
    QCompleter*     Completar;
    CONSULTA        FlagConsulta;

    void ObtenerConsulta();

private slots:
    void on_BotonConsultar_clicked();

 /*Para la movilidad del formulario*/
    void on_tabWidget_tabBarClicked(int index);

    void on_CheckNombre_stateChanged(int arg1);

    void on_LineNombre_textChanged(const QString &arg1);

protected:
    void mousePressEvent(QMouseEvent *evt)
    {
        oldPos = evt->globalPos();
    }

    void mouseMoveEvent(QMouseEvent *evt)
    {
        const QPoint delta = evt->globalPos() - oldPos;
        move(x()+delta.x(), y()+delta.y());
        oldPos = evt->globalPos();
    }


private:
    QPoint oldPos;
/*---------------------------------------------*/
};

#endif // BUSQUEDAARTICULOTIPOS_H
