#include "pgarticulos.h"

PgArticulos::PgArticulos()
{
}

bool PgArticulos::Borrar(Articulos valor)
{
    QSqlQuery query;

    return  query.exec("DELETE FROM articulos WHERE codigo='"+valor.getCodigo()+"'");

}

bool PgArticulos::Insertar(Articulos valor)
{

    QSqlQuery query;
      query.prepare("INSERT INTO articulos("
                    " nombre, unidad, vigencia, codigo_tipo, imagen)"
            "VALUES (?, ?, ?, ?, ?);");


      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getUnidad());
      query.addBindValue(valor.getVigencia());
      query.addBindValue(valor.getCodigo_Tipo());
      query.addBindValue(valor.getImagen());

      return query.exec();
}

bool PgArticulos::Actualizar(Articulos Antiguo, Articulos Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE articulos SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
    }
    if(!Nuevo.getUnidad().isNull())
    {
        consulta=consulta+", unidad='"+Nuevo.getUnidad()+"'";
    }
    if(!Nuevo.getVigencia().isNull())
    {
        consulta=consulta+", vigencia='"+Nuevo.getVigencia()+"'";
    }
    if(!Nuevo.getCodigo_Tipo().isNull())
    {
        consulta=consulta+", codigo_tipo='"+Nuevo.getCodigo_Tipo()+"'";
    }
    if(!Nuevo.getImagen().isNull())
    {
        consulta=consulta+", imagen='"+Nuevo.getImagen()+"'";
    }

    /*-------------------------------------*/
    /*contar la cantidad de caracteres desde el inicio hasta set*/
    consulta.replace(c,2," ");
    consulta=consulta+" WHERE ";

    /*-------------------------------------*/
    if(!Antiguo.getCodigo().isNull())
    {
        consulta=consulta+"(codigo='"+Antiguo.getCodigo()+"') AND ";
    }

    if(!Antiguo.getNombre().isNull())
    {
        consulta=consulta+"(nombre='"+Antiguo.getNombre()+"') AND ";
    }
    if(!Antiguo.getUnidad().isNull())
    {
        consulta=consulta+"(unidad='"+Antiguo.getUnidad()+"') AND ";
    }
    if(!Antiguo.getVigencia().isNull())
    {
        consulta=consulta+"(vigencia='"+Antiguo.getVigencia()+"') AND ";
    }
    if(!Antiguo.getCodigo_Tipo().isNull())
    {
        consulta=consulta+"(codigo_tipo='"+Antiguo.getCodigo_Tipo()+"') AND ";
    }
    if(!Antiguo.getImagen().isNull())
    {
        consulta=consulta+"(imagen='"+Antiguo.getImagen()+"') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;
    return query.exec(consulta);
}

Articulos PgArticulos::Buscar(Articulos valor)
{



    QString consulta;

    consulta="SELECT codigo, nombre, unidad, vigencia, codigo_tipo, imagen"
            " FROM articulos WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getUnidad().isNull())
    {
        consulta=consulta+" unidad like '%"+valor.getUnidad()+"%' AND ";
    }
    if(!valor.getVigencia().isNull())
    {
        consulta=consulta+" vigencia like '%"+valor.getVigencia()+"%' AND ";
    }
    if(!valor.getCodigo_Tipo().isNull())
    {
        consulta=consulta+" codigo_tipo like '%"+valor.getCodigo_Tipo()+"%' AND ";
    }
    if(!valor.getImagen().isNull())
    {
        consulta=consulta+" imagen like '%"+valor.getImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5,";");

    qDebug()<<consulta;

    Articulos resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setNombre(query.value(1).toString());
          resp.setUnidad(query.value(2).toString());
          resp.setVigencia(query.value(3).toString());
          resp.setCodigo_Tipo(query.value(4).toString());
          resp.setImagen(query.value(5).toString());

          /*como es imagen hay q validar*/
          QString Limg=resp.getImagen();

          //DefBD::GuardarImagen(Limg);

         flag=false;
      }


    return resp;
}

QMap<QString, ObjetoMaestro *> *PgArticulos::BuscarMapa(Articulos valor, CONSULTA tipo)
{



    QString consulta;

    if(tipo==TODO)
    {
            consulta="SELECT codigo, nombre, unidad, vigencia, codigo_tipo, imagen"
            " FROM articulos ";
    }
   else
    {
        consulta="SELECT codigo, nombre, unidad, vigencia, codigo_tipo, imagen"
        " FROM articulos WHERE ";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getUnidad().isNull())
    {
        consulta=consulta+" unidad like '%"+valor.getUnidad()+"%' AND ";
    }
    if(!valor.getVigencia().isNull())
    {
        consulta=consulta+" vigencia like '%"+valor.getVigencia()+"%' AND ";
    }
    if(!valor.getCodigo_Tipo().isNull())
    {
        consulta=consulta+" codigo_tipo like '%"+valor.getCodigo_Tipo()+"%' AND ";
    }
    if(!valor.getImagen().isNull())
    {
        consulta=consulta+" imagen like '%"+valor.getImagen()+"%' AND ";
    }
 consulta.replace(consulta.size()-5,5,";");
    }

    qDebug()<<consulta;

    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();


    QSqlQuery query(consulta);

      while (query.next() ) {

          Articulos* resp=new Articulos();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setUnidad(query.value(2).toString());
          resp->setVigencia(query.value(3).toString());
          resp->setCodigo_Tipo(query.value(4).toString());
          resp->setImagen(query.value(5).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);

      }
//qDebug()<<salida->begin().key();
       return salida;
}

int PgArticulos::Contar()
{
    return 0;
}
