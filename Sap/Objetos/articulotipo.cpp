#include "articulotipo.h"


QString ArticuloTipo::getCodigo() const
{
    return Codigo;
}

void ArticuloTipo::setCodigo(const QString &value)
{
    Codigo = value;
}

QString ArticuloTipo::getNombre() const
{
    return Nombre;
}

void ArticuloTipo::setNombre(const QString &value)
{
    Nombre = value;
}

QByteArray ArticuloTipo::getImagen() const
{
    return Imagen;
}

void ArticuloTipo::setImagen(const QByteArray &value)
{
    Imagen = value;
}


ArticuloTipo::ArticuloTipo()
{
    this->addPixmap(QPixmap(":/Imagenes/iconos/cat.png"));
}
