#ifndef ARTICULOTIPO_H
#define ARTICULOTIPO_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
#include <QFile>
#include <QIcon>


using namespace std;

class ArticuloTipo:public QIcon
{
protected:
    QString Codigo;
    QString Nombre;
    QByteArray Imagen;
public:
    ArticuloTipo();
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QByteArray getImagen() const;
    void setImagen(const QByteArray &value);


};

#endif // ARTICULOTIPO_H
