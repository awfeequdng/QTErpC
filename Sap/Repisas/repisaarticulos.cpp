#include "repisaarticulos.h"

RepisaArticulos::RepisaArticulos():Repisa()
{
    ActualizarMapa();
}

RepisaArticulos* RepisaArticulos::mUnico=0;



void RepisaArticulos::NuevoClick()
{
    Dialogo=new FormArticulos();
    Dialogo->show();
}


void RepisaArticulos::BuscarClick()
{
     qDebug()<<"buscar desde repisa nueva";
}



void RepisaArticulos::ActualizarMapa()
{
    Bd=DefBD::IniciarBD();
    FabricaLocal=Bd->Fabrica->CrearArticulos();
    Bd->Fabrica->Conectar();
    Mapa=FabricaLocal->BuscarMapa(Articulos(),TODO);
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    it=Mapa->begin();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));

    SiguienteClick();
}

void RepisaArticulos::ObjetosIndependientes()
{
    QPushButton* pp=new QPushButton(this);
    Articulos *i=(Articulos*)(it.value());

    // qDebug()<<it.value().getCodigo();
    pp->setObjectName(i->getCodigo());
    pp->setIcon(DefBD::toQicon(i->getImagen()));
    pp->setIconSize(QSize(55,55));
    pp->setFlat(true);
    pp->setGeometry(ix,iy,55,55);
    pp->setToolTip("Codigo: "+i->getCodigo()+"\n"+"Nombre: "+i->getNombre());
    GrupoBotones->addButton(pp);
    Botones.push_back(pp);
    pp->setVisible(true);
}

RepisaArticulos *RepisaArticulos::Iniciar()
{
    if(mUnico==NULL)
    {
        mUnico=new RepisaArticulos();
    }

    return mUnico;

}




void RepisaArticulos::GrupoBotonesClick(QAbstractButton* buttonID)
{

    Dialogo=new FormArticulos();

    Bd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
    FabricaLocal=Bd->Fabrica->CrearArticulos();
    Bd->Fabrica->Conectar();

    Bd->Fabrica->Desconectar();
    Dialogo->SetArticulos(*((Articulos*)Mapa->value(buttonID->objectName())));
    Dialogo->show();


}
