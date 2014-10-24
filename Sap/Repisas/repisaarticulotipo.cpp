#include "repisaarticulotipo.h"

RepisaArticuloTipo::RepisaArticuloTipo():Repisa()
{
    ActualizarMapa();
}

RepisaArticuloTipo* RepisaArticuloTipo::mUnico=0;



void RepisaArticuloTipo::NuevoClick()
{
    Dialogo=new FormArticuloTipo();
    Dialogo->show();
}


void RepisaArticuloTipo::BuscarClick()
{
     qDebug()<<"buscar desde repisa nueva";
}

void RepisaArticuloTipo::LlenarRepisa()
{
    int fil=1;
    int col=1;
    int x=40;
    int y=48;
    elementos=0;
    if(it==Mapa->begin())
    {
        Atras->setEnabled(false);
    }
    else
    {
          Atras->setEnabled(true);
    }
    while (it!=Mapa->end()&&fil<=5)
    {

        if(col<=4)
        {
            QPushButton* pp=new QPushButton(this);
            // qDebug()<<it.value().getCodigo();
            pp->setObjectName(it.value().getCodigo());

            /*como es imagen hay q validar si la tenemos o no*/
            QString Limg=it.value().getImagen();
            DefBD::GuardarImagen(Limg);
            /*-------------------------------------------------*/
            pp->setIcon(Definiciones::toQicon(it.value().getImagen()));

            pp->setIconSize(QSize(55,55));
            pp->setFlat(true);
            pp->setGeometry(x,y,55,55);
            pp->setToolTip("Codigo: "+it.value().getCodigo()+"\n"+"Nombre: "+it.value().getNombre());
            x=x+60;
            GrupoBotones->addButton(pp);
            Botones.push_back(pp);
            col++;
            it++;
            pp->setVisible(true);
            elementos++;
        }
        else
        {
            x=40;
            col=1;
            y=y+104;
            fil++;
        }


   }

    if(it==Mapa->end())
    {
        Siguiente->setEnabled(false);
    }
    else
    {
         Siguiente->setEnabled(true);
    }
}

void RepisaArticuloTipo::ActualizarMapa()
{
    Bd=DefBD::IniciarBD();
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();
    Mapa=FabricaLocal->BuscarMapa(ArticuloTipo(),TODO);
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    it=Mapa->begin();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

    elementos=0;
    SiguienteClick();
}

RepisaArticuloTipo *RepisaArticuloTipo::Iniciar()
{
    if(mUnico==NULL)
    {
        mUnico=new RepisaArticuloTipo();
    }

    return mUnico;

}


void RepisaArticuloTipo::AtrasClick()
{

    it-=elementos+5;

    for(int a=0; a<Botones.size(); a++)
    {

        GrupoBotones->removeButton(Botones[a]);
        delete Botones[a];
    }
     Botones.clear();
     LlenarRepisa();
}

void RepisaArticuloTipo::SiguienteClick()
{


    for(int a=0; a<Botones.size(); a++)
    {

        GrupoBotones->removeButton(Botones[a]);
        delete Botones[a];

    }

    Botones.clear();
    LlenarRepisa();

}


void RepisaArticuloTipo::GrupoBotonesClick(QAbstractButton* buttonID)
{

    Dialogo=new FormArticuloTipo();

    Bd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();


    Bd->Fabrica->Desconectar();
    Dialogo->SetArticuloTipo(Mapa->value(buttonID->objectName()));
    Dialogo->show();


}
