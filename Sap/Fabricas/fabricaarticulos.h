#ifndef FABRICAARTICULOS_H
#define FABRICAARTICULOS_H
#include "../Objetos/articulos.h"
#include <QMap>
#include "../Definiciones.h"

class FabricaArticulos
{
public:
    FabricaArticulos();
    virtual bool Borrar(Articulos valor)=0;
    virtual bool Insertar(Articulos valor)=0;
    virtual bool Actualizar(Articulos Antiguo, Articulos Nuevo)=0;
    virtual Articulos Buscar(Articulos valor)=0;
    virtual QMap<QString,Articulos>* BuscarMapa(Articulos valor, CONSULTA tipo)=0;
    virtual int Contar()=0;
};

#endif // FABRICAARTICULOS_H
