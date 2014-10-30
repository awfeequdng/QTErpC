#ifndef FORMARTICULOS_H
#define FORMARTICULOS_H
#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include "../Definiciones.h"
#include "../Fabricas.h"
#include "../Objetos.h"
#include "../Repisas/repisaarticulos.h"
#include "../DefBD.h"
namespace Ui {
class FormArticulos;
}
class RepisaArticulos;

class FormArticulos
{
    Q_OBJECT

public:
    explicit FormArticulos(QWidget *parent = 0);
    void SetArticulos(Articulos valor);
    ~FormArticulos();

private slots:
    void on_BotonArchivo_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_guardar_clicked();

    void on_eliminar_clicked();

    void on_modificar_clicked();

private:
    Ui::FormArticulos *ui;
    ESTADO Estado;
    RepisaArticulos* mRepisa;

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

#endif // FORMARTICULOS_H
