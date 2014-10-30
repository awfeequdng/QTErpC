#ifndef ARTICULOTIPO_H
#define ARTICULOTIPO_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
#include <QFile>
#include <QIcon>
#include "objetomaestro.h"

using namespace std;

class ArticuloTipo:public QIcon,ObjetoMaestro
{
protected:
    QString Codigo;
    QString Nombre;
    QString Imagen;
public:
    ArticuloTipo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getImagen() const;
    void setImagen(const QString &value);


};

#endif // ARTICULOTIPO_H
