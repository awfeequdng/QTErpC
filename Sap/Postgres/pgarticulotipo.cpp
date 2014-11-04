#include "pgarticulotipo.h"



PgArticuloTipo::PgArticuloTipo()
{
}


bool PgArticuloTipo::Borrar(ArticuloTipo valor)
{
    QSqlQuery query;

    return  query.exec("DELETE FROM articulo_tipo WHERE codigo='"+valor.getCodigo()+"'");

}

bool PgArticuloTipo::Insertar(ArticuloTipo valor)
{

    QSqlQuery query;
      query.prepare("INSERT INTO articulo_tipo("
                    " nombre, imagen)"
            "VALUES (?, ?);");


      query.addBindValue(valor.getNombre());
      query.addBindValue(valor.getImagen());

      return query.exec();
}

bool PgArticuloTipo::Actualizar(ArticuloTipo Antiguo, ArticuloTipo Nuevo)
{
    QSqlQuery query;

    QString consulta;

    consulta="UPDATE articulo_tipo SET ";

    int c=consulta.size();

    if(!Nuevo.getCodigo().isNull())
    {
        consulta=consulta+", codigo='"+Nuevo.getCodigo()+"'";
    }
    if(!Nuevo.getNombre().isNull())
    {
        consulta=consulta+", nombre='"+Nuevo.getNombre()+"'";
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
    if(!Antiguo.getImagen().isNull())
    {
        consulta=consulta+"(imagen='"+Antiguo.getImagen()+"') AND ";
    }

    consulta.replace(consulta.size()-5,5,";");
    qDebug()<<consulta;
    return query.exec(consulta);
}

ArticuloTipo PgArticuloTipo::Buscar(ArticuloTipo valor)
{
    QString consulta;

    consulta="SELECT codigo, nombre, imagen"
            " FROM articulo_tipo WHERE ";



    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getImagen().isNull())
    {
        consulta=consulta+" imagen like '%"+valor.getImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-6,5," ");

    qDebug()<<consulta;

    ArticuloTipo resp;
    QSqlQuery query(consulta);
    bool flag=true;
      while (query.next() && flag ) {
          resp.setCodigo(query.value(0).toString());
          resp.setNombre(query.value(1).toString());
          resp.setImagen(query.value(2).toString());

          /*como es imagen hay q validar*/
          QString Limg=resp.getImagen();

          //DefBD::GuardarImagen(Limg);

         flag=false;
      }


    return resp;
}

QMap<QString, ObjetoMaestro *> *PgArticuloTipo::BuscarMapa(ObjetoMaestro *valor, QString Extra, CONSULTA tipo)
{

    ArticuloTipo* val=(ArticuloTipo*)(valor);
   qDebug()<<val->getCodigo();
    QString consulta;

    if(tipo==TODO)
    {
            consulta="SELECT codigo, nombre, imagen"
            " FROM articulo_tipo ";
    }
   else
    {
        consulta="SELECT codigo, nombre, imagen"
        " FROM articulo_tipo WHERE ";

    if(!val->getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+val->getCodigo()+"%' AND ";
    }
    if(!val->getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+val->getNombre()+"%' AND ";
    }
    if(!val->getImagen().isNull())
    {
        consulta=consulta+" imagen like '%"+val->getImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;

    qDebug()<<consulta;

    QMap<QString,ObjetoMaestro*>* salida=new QMap<QString,ObjetoMaestro*>();


    QSqlQuery query(consulta);

      while (query.next() ) {

          ArticuloTipo* resp=new ArticuloTipo();
          resp->setCodigo(query.value(0).toString());
          resp->setNombre(query.value(1).toString());
          resp->setImagen(query.value(2).toString());

          salida->insert(resp->getCodigo(),(ObjetoMaestro*)resp);

      }

       return salida;
}

int PgArticuloTipo::Contar()
{
      QString consulta="SELECT count(*) FROM articulo_tipo";
      QSqlQuery query(consulta);
    int num=0;
        while (query.next() )
        {
          num=query.value(0).toInt();
        }
    return num;
}


QSqlQueryModel *PgArticuloTipo::BuscarTabla(ArticuloTipo valor, QString Extra, CONSULTA tipo)
{

    QString consulta;
    if(tipo==TODO)
    {
            consulta="SELECT codigo, nombre, imagen"
            " FROM articulo_tipo ";
    }
    else
    {
    consulta="SELECT codigo, nombre, imagen"
            " FROM articulo_tipo WHERE ";

    if(!valor.getCodigo().isNull())
    {
        consulta=consulta+" codigo like '%"+valor.getCodigo()+"%' AND ";
    }
    if(!valor.getNombre().isNull())
    {
        consulta=consulta+" nombre like '%"+valor.getNombre()+"%' AND ";
    }
    if(!valor.getImagen().isNull())
    {
        consulta=consulta+" imagen like '%"+valor.getImagen()+"%' AND ";
    }
    consulta.replace(consulta.size()-5,5," ");
    }

    consulta=consulta+Extra;
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery(consulta);

    qDebug()<<consulta;

    return model;
}
