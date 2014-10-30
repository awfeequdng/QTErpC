#include "articulos.h"


QString Articulos::getVigencia() const
{
    return Vigencia;
}

void Articulos::setVigencia(const QString &value)
{
    Vigencia = value;
}

QString Articulos::getCodigo() const
{
    return Codigo;
}

void Articulos::setCodigo(const QString &value)
{
    Codigo = value;
}

QString Articulos::getNombre() const
{
    return Nombre;
}

void Articulos::setNombre(const QString &value)
{
    Nombre = value;
}

QString Articulos::getImagen() const
{
    return Imagen;
}

void Articulos::setImagen(const QString &value)
{
    Imagen = value;
}

QString Articulos::getUnidad() const
{
    return Unidad;
}

void Articulos::setUnidad(const QString &value)
{
    Unidad = value;
}

QString Articulos::getCodigo_Tipo() const
{
    return Codigo_Tipo;
}

void Articulos::setCodigo_Tipo(const QString &value)
{
    Codigo_Tipo = value;
}

Articulos::Articulos()
{
    this->addPixmap(QPixmap(":/Imagenes/iconos/cat.png"));
}
