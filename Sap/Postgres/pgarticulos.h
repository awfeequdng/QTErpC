#ifndef PGARTICULOS_H
#define PGARTICULOS_H
#include "../Fabricas/fabricaarticulos.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>

class PgArticulos:public FabricaArticulos
{
public:
    PgArticulos();

    // FabricaArticulos interface
public:
    bool Borrar(Articulos valor);
    bool Insertar(Articulos valor);
    bool Actualizar(Articulos Antiguo, Articulos Nuevo);
    Articulos Buscar(Articulos valor);
    QMap<QString, ObjetoMaestro*> *BuscarMapa(Articulos valor, CONSULTA tipo);
    int Contar();
};

#endif // PGARTICULOS_H
