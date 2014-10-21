#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include <stdlib.h>
#include <string>
#include <QDate>
#include <QString>
using namespace std;

class Cliente
{
protected:
    QString Codigo;
    QString Tipo;
    QString Nombre;
    QString Direccion;
    QString Pais;
    QString Contacto;
    QString Telefono;
    QString Email;
    QString Web;
    float  Descuento;
    QDate  Fecha;
public:
    Cliente();

    QString getCodigo() const;
    void setCodigo(const QString &value);
    QString getTipo() const;
    void setTipo(const QString &value);
    QString getNombre() const;
    void setNombre(const QString &value);
    QString getDireccion() const;
    void setDireccion(const QString &value);
    QString getPais() const;
    void setPais(const QString &value);
    QString getContacto() const;
    void setContacto(const QString &value);
    QString getTelefono() const;
    void setTelefono(const QString &value);
    QString getEmail() const;
    void setEmail(const QString &value);
    QString getWeb() const;
    void setWeb(const QString &value);
    float getDescuento() const;
    void setDescuento(float value);
    QDate getFecha() const;
    void setFecha(const QDate &value);

    //Cliente & operator= (Cliente & valor);   //asignacion

};

#endif // CLIENTE_H
