#ifndef IMAGEN_H
#define IMAGEN_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
using namespace std;
class Imagen
{
private:
    QString Codigo;
    QString Carpeta;
    QString Nombre;
    QByteArray Pixel;
public:
    Imagen();
    QString getCarpeta() const;
    void setCarpeta(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getCodigo() const;
    void setCodigo(const QString &value);
    QByteArray getPixel() const;
    void setPixel(const QByteArray &value);
};

#endif // IMAGEN_H
