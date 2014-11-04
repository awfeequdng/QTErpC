#include "visorimagenes.h"
#include "ui_visorimagenes.h"



VisorImagenes::VisorImagenes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VisorImagenes)
{

        connect(this,SIGNAL(my_signal(QString)),parent,SLOT(Ruta(QString)));

    ui->setupUi(this);


    this->setWindowFlags(Qt::Window
                         | Qt::FramelessWindowHint
                         | Qt::WindowMinimizeButtonHint
                         | Qt::WindowMaximizeButtonHint
                         | Qt::WindowCloseButtonHint);

     QPixmap bkgnd(FondoForm);
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);


    FabricaBaseDatos* bd=DefBD::IniciarBD();
    bd->Fabrica->Conectar();
    FabricaImagenes* Img=bd->Fabrica->CrearImagen();
    QMap<QString,ObjetoMaestro*>* mapa=Img->BuscarMapa(Imagen(),TODO);

    QMap<QString,ObjetoMaestro*>::iterator it;


    QMap<QString,int>::iterator itc;

    this->ui->VisorArbol->setColumnCount(1);

    int n=-1;
    for(it=mapa->begin(); it!=mapa->end(); it++)
    {
       Imagen* i=(Imagen*)(it.value());
       QString Carpeta= i->getCarpeta();
       QString Nombre= i->getNombre();


        if(ListaCarpetas.contains(Carpeta))
        {
            itc=ListaCarpetas.find(Carpeta);
          QTreeWidgetItem* carp=ui->VisorArbol->topLevelItem(itc.value());
          QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
          Item->setText(0, Nombre);
        //  DefBD::GuardarImagen(Carpeta+"/"+Nombre);
        }
        else
        {
            n++;
            ListaCarpetas.insert(Carpeta,n);
            QTreeWidgetItem* carp=new QTreeWidgetItem(ui->VisorArbol);
            carp->setText(0,Carpeta);

            QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
             Item->setText(0, Nombre);
           //  DefBD::GuardarImagen(Carpeta+"/"+Nombre);
        }
    }

    bd->Fabrica->Desconectar();

}
VisorImagenes::~VisorImagenes()
{
    delete ui;
}


void VisorImagenes::on_VisorArbol_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(ListaCarpetas.contains(current->text(0)))
    {
      ui->LineCarpeta->setText(current->text(0));
      CarpetaActual=current;
    }

    if(!ListaCarpetas.contains(current->text(0)))
    {
       QTreeWidgetItem*Padre= current->parent();
       CarpetaActual=Padre;
       QString TextP=Padre->text(0);
       ui->LineCarpeta->setText(TextP);
      ui->LineNombre->setText(current->text(0));
     QString ruta=TextP+"/"+current->text(0);
      QPixmap  pix=DefBD::toQpixmap(ruta);
     ui->labelImagen->setPixmap(pix.scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    }


}

void VisorImagenes::on_ButonSeleccion_clicked()
{
fileName=ui->LineCarpeta->text()+"/"+ui->LineNombre->text();
emit my_signal(fileName);
this->close();
}

void VisorImagenes::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
    this->close();
    }
}
