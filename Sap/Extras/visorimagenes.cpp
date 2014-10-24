#include "visorimagenes.h"
#include "ui_visorimagenes.h"

VisorImagenes::VisorImagenes(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VisorImagenes)
{
    ui->setupUi(this);

    FabricaBaseDatos* bd=DefBD::IniciarBD();
    bd->Fabrica->Conectar();
    FabricaImagenes* Img=bd->Fabrica->CrearImagen();
    Img->BuscarMapa(Imagen(),TODO);

    this->ui->VisorArbol->setColumnCount(1);
    QTreeWidgetItem* item=new QTreeWidgetItem(ui->VisorArbol);
    item->setText(0,tr("ciudad"));

    for(int a=0; a<10; a++){
    QTreeWidgetItem *osloItem = new QTreeWidgetItem(item);
        osloItem->setText(0, tr("Oslo"));
    }
    ui->VisorArbol->insertTopLevelItem(0,item);
    bd->Fabrica->Desconectar();

}

VisorImagenes::~VisorImagenes()
{
    delete ui;
}
