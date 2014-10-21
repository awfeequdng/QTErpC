

#ifndef DEFINICIONES_H
#define DEFINICIONES_H

#include <QBuffer>
#include <QByteArray>
#include <QImage>
#include <QIcon>
#include <QPixmap>
enum ESTADO
{
    INSERTAR,
    MODIFICAR
};

enum CONSULTA
{
    CAMPOS,
    TODO
};
struct Definiciones
{
static QIcon   toQicon(QByteArray bytea)
{
    QPixmap p;
    p.loadFromData(bytea,"PNG");
    QIcon ic;
    ic.addPixmap(p);
    return ic;
}
static QPixmap  toQpixmap(QByteArray bytea)
{
    QPixmap p;
    p.loadFromData(bytea,"PNG");
    return p;
}
static QByteArray toQByteArray(QImage image)
{
    //QImage img;
    //img.load("C:/Users/Ripley/Documents/Qt/SapGrafico/Imagenes/iconos/globo.png");
    QByteArray arr;
    QBuffer buf(&arr);
    buf.open(QIODevice::WriteOnly);
    image.save(&buf, "PNG");
    buf.close();
    return arr;
}

static QByteArray toQByteArray(QString image)
{
    QImage img;
    img.load(image);
    QByteArray arr;
    QBuffer buf(&arr);
    buf.open(QIODevice::WriteOnly);
    img.save(&buf, "PNG");
    buf.close();
    return arr;
}

};

/*      BOTONES DE FORMULARIOS */
static QString BotonGuardar=":/Imagenes/iconos/guardar.png";
static QString BotonModificar=":/Imagenes/iconos/editar.png";
static QString BotonEliminar=":/Imagenes/iconos/delete.png";
static QString BotonDerecha;
static QString BotonIzquierda;
static QString BotonNuevo;
static QString BotonBuscar;
static QString FondoForm=":/Imagenes/fondos/madera4";



#endif // DEFINICIONES_H
