#ifndef POSTGRES_H
#define POSTGRES_H
#include "../Objetos/basedatos.h"
#include <QSqlDatabase>
#include "pgcliente.h"
#include "pgarticulotipo.h"
class Postgres:public BaseDatos
{
private:
    QSqlDatabase   mDriver;

public:

    Postgres();

    // BaseDatos interface
    bool Conectar();
    bool Desconectar();
    bool HayConexion();

    // BaseDatos interface
public:
    FabricaClientes *CrearCliente();
    FabricaArticuloTipos *CrearArticuloTipo();
};

#endif // POSTGRES_H
