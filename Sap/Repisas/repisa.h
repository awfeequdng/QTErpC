#ifndef REPISA_H
#define REPISA_H
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QtWidgets>


class Repisa:public QMainWindow
{
Q_OBJECT
protected:
    QPushButton*    Nuevo;
    QPushButton*    Buscar;
  static  QMainWindow* Formulario;
  QPushButton*    Atras;
  QPushButton*    Siguiente;
  QPushButton*    Cerrar;
private:




public slots:

    virtual void AtrasClick();
    virtual void SiguienteClick();
    virtual void NuevoClick();
    virtual void BuscarClick();
public:

    Repisa();
    void DibujarRepisa();
    void Dibujar();
  //  virtual void LlenarRepisa();
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

#endif // REPISA_H
