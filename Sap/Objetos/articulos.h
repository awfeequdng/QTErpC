#ifndef ARTICULOS_H
#define ARTICULOS_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
#include <QFile>
#include <QIcon>

class Articulos:public QIcon
{
protected:
    QString Codigo;
    QString Nombre;
    QString Imagen;
    QString Unidad;
    QString Vigencia;
    QString Codigo_Tipo;
public:
    Articulos();
    QString getVigencia() const;
    void setVigencia(const QString &value);
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getImagen() const;
    void setImagen(const QString &value);
    QString getUnidad() const;
    void setUnidad(const QString &value);
    QString getCodigo_Tipo() const;
    void setCodigo_Tipo(const QString &value);
};

#endif // ARTICULOS_H
