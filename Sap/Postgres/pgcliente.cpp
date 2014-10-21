#include "pgcliente.h"

#include <qdebug.h>

PgCliente::PgCliente()
{
}


bool PgCliente::Borrar(Cliente valor)
{
    QSqlQuery query;

    return  query.exec("DELETE FROM clientes WHERE codigo='"+valor.getCodigo()+"'");

}

bool PgCliente::Insertar(Cliente valor)
{
    if(valor.getDescuento()==(-1))
    {
        valor.setDescuento(0);
    }
    QSqlQuery query;
      query.prepare("INSERT INTO clientes("
                        "codigo, tipo, nombre, direccion, pais, contacto, telefono, email, "
                        "web, descuento, fecha)"
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?,"
                        "?, ?, ?);");

      query.addBindValue(valor.getCodigo());
      query.addBindValue(valor.getTipo());
      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getDireccion());
      query.addBindValue(valor.getPais());
      query.addBindValue(valor.getContacto());
      query.addBindValue(valor.getTelefono());
      query.addBindValue(valor.getEmail());
      query.addBindValue(valor.getWeb());
      query.addBindValue(valor.getDescuento());
      query.addBindValue(valor.getFecha());

      return query.exec();
}

bool PgCliente::Actualizar(Cliente Antiguo, Cliente Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE clientes SET ";

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getTipo().isNull())
    {
        consulta=consulta+", tipo='"+Nuevo.getTipo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getDireccion().isNull())
    {
        consulta=consulta+", direccion='"+Nuevo.getDireccion()+"'";
    }
    if(!Nuevo.getPais().isNull())
    {
        consulta=consulta+", pais='"+Nuevo.getPais()+"'";
    }
    if(!Nuevo.getContacto().isNull())
    {
        consulta=consulta+", contacto='"+Nuevo.getContacto()+"'";
    }
    if(!Nuevo.getTelefono().isNull())
    {
        consulta=consulta+", telefono='"+Nuevo.getTelefono()+"'";
    }
    if(!Nuevo.getEmail().isNull())
    {
        consulta=consulta+", email='"+Nuevo.getEmail()+"'";
    }
    if(!Nuevo.getWeb().isNull())
    {
        consulta=consulta+", web='"+Nuevo.getWeb()+"'";
    }
    if(!(Nuevo.getDescuento()==(-1)))
    {
        consulta=consulta+", descuento='"+QString::number(Nuevo.getDescuento())+"'";
    }

    if(!(Nuevo.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+", fecha='"+(Nuevo.getFecha()).toString("dd-MM-yyyy")+"'";
    }

    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(20,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/

    if(!Antiguo.getCodigo().isNull())
    {
        consulta=consulta+"(codigo='"+Antiguo.getCodigo()+"') AND ";
    }
    if(!Antiguo.getTipo().isNull())
    {
        consulta=consulta+"(tipo='"+Antiguo.getTipo()+"') AND ";
    }
    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"(nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getDireccion().isNull())
    {
        consulta=consulta+"(direccion='"+Antiguo.getDireccion()+"') AND ";
    }
    if(!Antiguo.getPais().isNull())
    {
        consulta=consulta+"(pais='"+Antiguo.getPais()+"') AND ";
    }
    if(!Antiguo.getContacto().isNull())
    {
        consulta=consulta+"(contacto='"+Antiguo.getContacto()+"') AND ";
    }
    if(!Antiguo.getTelefono().isNull())
    {
        consulta=consulta+"(telefono='"+Antiguo.getTelefono()+"') AND ";
    }
    if(!Antiguo.getEmail().isNull())
    {
        consulta=consulta+"(email='"+Antiguo.getEmail()+"') AND ";
    }
    if(!Antiguo.getWeb().isNull())
    {
        consulta=consulta+"(web='"+Antiguo.getWeb()+"') AND ";
    }
    if(!(Antiguo.getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento='"+QString::number(Antiguo.getDescuento())+"') AND ";
    }

    if(!(Antiguo.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(Antiguo.getFecha()).toString("dd-MM-yyyy")+"') AND ";
    }
    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;
    return query.exec(consulta);
}

Cliente PgCliente::Buscar(Cliente valor)
{


    QString consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
            " web, descuento, fecha"
            " FROM clientes"
            " WHERE ";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+"(codigo like '%"+valor.getCodigo()+"%') AND ";
    }
    if(!valor.getTipo().isNull())
    {
        consulta=consulta+"(tipo like '%"+valor.getTipo()+"%') AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+"(nombre like '%"+valor.getNombre()+"%') AND ";
    }
    if(!valor.getDireccion().isNull())
    {
        consulta=consulta+"(direccion like '%"+valor.getDireccion()+"%') AND ";
    }
    if(!valor.getPais().isNull())
    {
        consulta=consulta+"(pais like '%"+valor.getPais()+"%') AND ";
    }
    if(!valor.getContacto().isNull())
    {
        consulta=consulta+"(contacto like '%"+valor.getContacto()+"%') AND ";
    }
    if(!valor.getTelefono().isNull())
    {
        consulta=consulta+"(telefono like '%"+valor.getTelefono()+"%') AND ";
    }
    if(!valor.getEmail().isNull())
    {
        consulta=consulta+"(email like '%"+valor.getEmail()+"%') AND ";
    }
    if(!valor.getWeb().isNull())
    {
        consulta=consulta+"(web like '%"+valor.getWeb()+"%') AND ";
    }
    if(!(valor.getDescuento()==(-1)))
    {
        consulta=consulta+"(descuento like '%"+QString::number(valor.getDescuento())+"%') AND ";
    }

    if(!(valor.getFecha()==QDate(1,1,1)))
    {
        consulta=consulta+"(fecha='"+(valor.getFecha()).toString("yyyy-MM-dd")+"') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;

    Cliente resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setTipo(query.value(1).toString());
          resp.setNombre(query.value(2).toString());
          resp.setDireccion(query.value(3).toString());
          resp.setPais(query.value(4).toString());
          resp.setContacto(query.value(5).toString());
          resp.setTelefono(query.value(6).toString());
          resp.setEmail(query.value(7).toString());
          resp.setWeb(query.value(8).toString());
          resp.setDescuento(query.value(9).toFloat());
          resp.setFecha(query.value(10).toDate());

          flag=false;
      }


    return resp;
}

vector<Cliente> PgCliente::BuscarVector(Cliente valor, CONSULTA tipo)
{
    QString consulta;

    if (tipo==TODO)
    {
    consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
            " web, descuento, fecha"
            " FROM clientes ";

    }
    else
    {
        consulta="SELECT codigo, tipo, nombre, direccion, pais, contacto, telefono, email,"
                " web, descuento, fecha"
                " FROM clientes "
                " WHERE ";

        if(!valor.getCodigo().isNull())
        {
            consulta=consulta+"(codigo like '%"+valor.getCodigo()+"%') AND ";
        }
        if(!valor.getTipo().isNull())
        {
            consulta=consulta+"(tipo like '%"+valor.getTipo()+"%') AND ";
        }
        if(!valor.getNombre().isNull())
        {
            consulta=consulta+"(nombre like '%"+valor.getNombre()+"%') AND ";
        }
        if(!valor.getDireccion().isNull())
        {
            consulta=consulta+"(direccion like '%"+valor.getDireccion()+"%') AND ";
        }
        if(!valor.getPais().isNull())
        {
            consulta=consulta+"(pais like '%"+valor.getPais()+"%') AND ";
        }
        if(!valor.getContacto().isNull())
        {
            consulta=consulta+"(contacto like '%"+valor.getContacto()+"%') AND ";
        }
        if(!valor.getTelefono().isNull())
        {
            consulta=consulta+"(telefono like '%"+valor.getTelefono()+"%') AND ";
        }
        if(!valor.getEmail().isNull())
        {
            consulta=consulta+"(email like '%"+valor.getEmail()+"%') AND ";
        }
        if(!valor.getWeb().isNull())
        {
            consulta=consulta+"(web like '%"+valor.getWeb()+"%') AND ";
        }
        if(!(valor.getDescuento()==(-1)))
        {
            consulta=consulta+"(descuento like '%"+QString::number(valor.getDescuento())+"%') AND ";
        }

        if(!(valor.getFecha()==QDate(1,1,1)))
        {
            consulta=consulta+"(fecha='"+(valor.getFecha()).toString("yyyy-MM-dd")+"') AND ";
        }

        consulta.replace(consulta.size()-5,5,";");
    }


    qDebug()<<consulta;

    vector<Cliente> salida;


    QSqlQuery query(consulta);

      while (query.next() ) {

          Cliente resp;
          resp.setCodigo(query.value(0).toString());
          resp.setTipo(query.value(1).toString());
          resp.setNombre(query.value(2).toString());
          resp.setDireccion(query.value(3).toString());
          resp.setPais(query.value(4).toString());
          resp.setContacto(query.value(5).toString());
          resp.setTelefono(query.value(6).toString());
          resp.setEmail(query.value(7).toString());
          resp.setWeb(query.value(8).toString());
          resp.setDescuento(query.value(9).toFloat());
          resp.setFecha(query.value(10).toDate());
          salida.push_back(resp);
      }

       return salida;
}

int PgCliente::Contar()
{
    return 0;
}

