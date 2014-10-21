#ifndef BASEDATOS_H
#define BASEDATOS_H
#include <QtSql/QSql>
#include <string>

#include "../Fabricas/fabricaclientes.h"
#include "../Fabricas/fabricaarticulotipos.h"

using namespace std;

class BaseDatos
{
protected:
    string HostName;
    string DataBaseName;
    string UserName;
    string Password;
    int    Port;
    bool   Estado;
public:
    BaseDatos();

    /*Cada tipo de BD debe redefinir estas funciones a su forma*/
    virtual bool        Conectar()=0;
    virtual bool        Desconectar()=0;
    virtual bool        HayConexion()=0;
    /*--------------------------------*/

    /*Esto es para la BD*/

    string getHostName() const;
    void setHostName(const string &value);
    string getDataBaseName() const;
    void setDataBaseName(const string &value);
    string getUserName() const;
    void setUserName(const string &value);
    string getPassword() const;
    void setPassword(const string &value);
    int getPort() const;
    void setPort(int value);
    bool getEstado() const;
    void setEstado(bool value);

    /*---------------------------------*/
    /*Aqui se crean todos los objetos a manejar como metodos virtuales para q en todas las
      fabricas aparescan*/

    virtual FabricaClientes       *CrearCliente()=0;
    virtual FabricaArticuloTipos  *CrearArticuloTipo()=0;


};

#endif // BASEDATOS_H
