#include "principal.h"
#include <QApplication>
#include "Fabricas.h"
#include "Objetos.h"
#include "Repisas/repisaarticulotipo.h"
#include "Formularios/formarticulotipo.h"

#include "Extras/visorimagenes.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FabricaBaseDatos* mybd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
       mybd->Fabrica->setDataBaseName("Copia_Core");
       mybd->Fabrica->setHostName("localhost");
       mybd->Fabrica->setPort(5432);
       mybd->Fabrica->setUserName("postgres");
       mybd->Fabrica->setPassword("root");
/*
       mybd->Fabrica->Conectar();
       if (mybd->Fabrica->HayConexion())
       {
            qDebug()<<"exito";

           FabricaArticuloTipos * art=mybd->Fabrica->CrearArticuloTipo();

           ArticuloTipo* a=new ArticuloTipo();
           a->setNombre("Dado");
           a->setImagen(Definiciones::toQByteArray("C:/Users/Ripley/Documents/Qt/SapGrafico/Imagenes/iconos/dado.png"));

               if(art->Insertar(*a))
               {
                   qDebug()<<"EXITO SE REALIZO CONSULTA";
               }
               else
               {
                   qDebug()<<"ERROR NO SE REALIZO LA CONSULTA";
               }
       }
       else
       { qDebug()<<"no hay conexion";}
*/

       VisorImagenes w;
   // RepisaArticuloTipo* w=RepisaArticuloTipo::Iniciar();
  w.show();



    return a.exec();
}
