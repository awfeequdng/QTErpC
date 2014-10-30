#include "principal.h"
#include <QApplication>
#include "Fabricas.h"
#include "Objetos.h"
#include "Repisas/repisaarticulotipo.h"
#include "Repisas/repisaarticulos.h"
#include "Formularios/formarticulotipo.h"

#include "Extras/visorimagenes.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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

       //VisorImagenes w;
    RepisaArticulos* w =RepisaArticulos::Iniciar();

   // RepisaArticuloTipo* w=RepisaArticuloTipo::Iniciar();
  //w.show();



    return a.exec();
}
