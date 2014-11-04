#ifndef FORMARTICULOTIPO_H
#define FORMARTICULOTIPO_H

#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include "../Definiciones.h"
#include "../Fabricas.h"
#include "../Objetos.h"
#include "../Repisas/repisaarticulotipo.h"
#include "../DefBD.h"
#include "../Extras/visorimagenes.h"
namespace Ui {
class FormArticuloTipo;
}
class RepisaArticuloTipo;

class FormArticuloTipo : public QDialog
{
    Q_OBJECT

public:
    explicit FormArticuloTipo(QWidget *parent = 0);
    void SetArticuloTipo(ArticuloTipo valor);
    ~FormArticuloTipo();

private slots:
    void on_BotonArchivo_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_guardar_clicked();

    void on_eliminar_clicked();

    void on_modificar_clicked();

    /*Agregar esto para cada ves que se desee llamar una imagen*/
    void Ruta(QString Cadena);
    /*-------------------------*/

private:
    Ui::FormArticuloTipo *ui;
    ESTADO Estado;
    RepisaArticuloTipo* mRepisa;

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
};

#endif // FORMARTICULOTIPO_H
