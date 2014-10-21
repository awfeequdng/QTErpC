#ifndef FORMARTICULOTIPO_H
#define FORMARTICULOTIPO_H

#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include "../Definiciones.h"
#include "../Fabricas.h"
#include "../Objetos.h"
namespace Ui {
class FormArticuloTipo;
}

class FormArticuloTipo : public QWidget
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

private:
    Ui::FormArticuloTipo *ui;
    ESTADO Estado;

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
