#ifndef FABRICACLIENTES_H
#define FABRICACLIENTES_H
#include "../Objetos/cliente.h"
#include <vector>
#include "../Definiciones.h"
using namespace std;

class FabricaClientes
{
public:
    FabricaClientes();
    virtual bool Borrar(Cliente valor)=0;
    virtual bool Insertar(Cliente valor)=0;
    virtual bool Actualizar(Cliente Antiguo, Cliente Nuevo)=0;
    virtual Cliente Buscar(Cliente valor)=0;
    virtual vector<Cliente> BuscarVector(Cliente valor, CONSULTA tipo)=0;
    virtual int Contar()=0;
};

#endif // FABRICACLIENTES_H
