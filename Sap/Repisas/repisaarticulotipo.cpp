#include "repisaarticulotipo.h"

RepisaArticuloTipo::RepisaArticuloTipo():Repisa()
{
    ActualizarMapa((ObjetoMaestro*)new ArticuloTipo());
}

RepisaArticuloTipo* RepisaArticuloTipo::mUnico=0;



void RepisaArticuloTipo::NuevoClick()
{
    Dialogo=new FormArticuloTipo(this);
    Dialogo->move(this->x()+this->width(),this->y());
    Dialogo->exec();

}


void RepisaArticuloTipo::BuscarClick()
{
    Busqueda=new BusquedaArticuloTipos(this);
     Busqueda->move(this->x()+this->width(),this->y());
    Busqueda->show();


}
void RepisaArticuloTipo::ActualizarConsulta()
{
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();

    RegistrosTabla=FabricaLocal->Contar();
    // qDebug()<<"elem:"+TotalElementos;
    QString extra="LIMIT 100 offset "+QString::number(TotalElementos);
    qDebug()<<"aqui toy";
    qDebug()<<((ArticuloTipo*)(ObjetoConsulta))->getCodigo();
    Mapa=FabricaLocal->BuscarMapa(ObjetoConsulta,extra,CAMPOS);
    qDebug()<<"aqui luego toy";
    Bd->Fabrica->Desconectar();
    qDebug()<<Mapa->size();
    GrupoBotones=new QButtonGroup(this);
    connect(GrupoBotones, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(GrupoBotonesClick(QAbstractButton*)));
}


void RepisaArticuloTipo::ObjetosIndependientes()
{
    /*
     * Para el Tool Tip
    */
    QPushButton* pp=new QPushButton(this);
    ArticuloTipo *i=(ArticuloTipo*)(it.value());
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

    Dialogo=new FormArticuloTipo(this);
    Dialogo->move(this->x()+this->width(),this->y());

    Bd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
    FabricaLocal=Bd->Fabrica->CrearArticuloTipo();
    Bd->Fabrica->Conectar();

    Bd->Fabrica->Desconectar();
    Dialogo->SetArticuloTipo(*((ArticuloTipo*)Mapa->value(buttonID->objectName())));
    Dialogo->show();


}
