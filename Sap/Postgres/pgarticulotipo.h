#ifndef PGARTICULOTIPO_H
#define PGARTICULOTIPO_H
#include "../Fabricas/fabricaarticulotipos.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <qdebug.h>
#include <QMap>

class PgArticuloTipo:public FabricaArticuloTipos
{
public:
    PgArticuloTipo();

    // FabricaArticuloTipos interface
public:
    bool Borrar(ArticuloTipo valor);
    bool Insertar(ArticuloTipo valor);
    bool Actualizar(ArticuloTipo Antiguo, ArticuloTipo Nuevo);
    ArticuloTipo Buscar(ArticuloTipo valor);
    QMap<QString, ObjetoMaestro*> *BuscarMapa(ArticuloTipo valor, CONSULTA tipo);
    int Contar();
};

#endif // PGARTICULOTIPO_H
