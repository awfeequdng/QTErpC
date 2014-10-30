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

    SiguienteClick();
}

void RepisaArticuloTipo::ObjetosIndependientes()
{
    QPushButton* pp=new QPushButton(this);
    ArticuloTipo *i=(ArticuloTipo*)(it.value());

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

RepisaArticuloTipo *RepisaArticuloTipo::Iniciar()
{
    if(mUnico==NULL)
    {
        mUnico=new RepisaArticuloTipo();
    }

    return mUnico;

}




void RepisaArticuloTipo::GrupoBotonesClick(QAbstractButton* buttonID)
{

    Dialogo=new FormArticuloTipo();

    Bd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();

    Bd->Fabrica->Desconectar();
    Dialogo->SetArticuloTipo(*((ArticuloTipo*)Mapa->value(buttonID->objectName())));
    Dialogo->show();


}
