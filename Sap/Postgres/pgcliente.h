#ifndef PGCLIENTE_H
#define PGCLIENTE_H
#include "../Fabricas/fabricaclientes.h"
#include <QSqlQuery>
#include <QString>
#include <QVariant>


class PgCliente:public FabricaClientes
{
public:
    PgCliente();

    // FabricaClientes interface
public:
    bool Borrar(Cliente valor);
    bool Insertar(Cliente valor);
    bool Actualizar(Cliente Antiguo, Cliente Nuevo);
    Cliente Buscar(Cliente valor);
    vector<Cliente> BuscarVector(Cliente valor, CONSULTA tipo);
    int Contar();

};

#endif // PGCLIENTE_H
