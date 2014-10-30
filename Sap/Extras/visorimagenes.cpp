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
    QMap<QString,Imagen>* mapa=Img->BuscarMapa(Imagen(),TODO);

    QMap<QString,Imagen>::iterator it;


    QMap<QString,int>::iterator itc;

    this->ui->VisorArbol->setColumnCount(1);

    int n=-1;
    for(it=mapa->begin(); it!=mapa->end(); it++)
    {
       QString Carpeta= it.value().getCarpeta();
       QString Nombre= it.value().getNombre();


        if(ListaCarpetas.contains(Carpeta))
        {
            itc=ListaCarpetas.find(Carpeta);
          QTreeWidgetItem* carp=ui->VisorArbol->topLevelItem(itc.value());
          QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
          Item->setText(0, Nombre);
          DefBD::GuardarImagen(Carpeta+"/"+Nombre);
        }
        else
        {
            n++;
            ListaCarpetas.insert(Carpeta,n);
            QTreeWidgetItem* carp=new QTreeWidgetItem(ui->VisorArbol);
            carp->setText(0,Carpeta);

            QTreeWidgetItem *Item = new QTreeWidgetItem(carp);
             Item->setText(0, Nombre);
             DefBD::GuardarImagen(Carpeta+"/"+Nombre);
        }
    }


/*
    for(int a=0; a<10; a++){
    QTreeWidgetItem *osloItem = new QTreeWidgetItem(carp);
        osloItem->setText(0, tr("Oslo"));
    }*/
  //  ui->VisorArbol->insertTopLevelItem(0,item);


    bd->Fabrica->Desconectar();

}

VisorImagenes::~VisorImagenes()
{
    delete ui;
}

void VisorImagenes::on_BotonImagen_clicked()
{
   fileName = QFileDialog::getOpenFileName(this, tr("Abrir Imagen"),RutaImagenes,tr("Archivo Imagen (*.png)"));

   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(fileName);

       ui->labelImagen->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       //ui->imagen->setText(fileName);

    }

}

void VisorImagenes::on_BotonCarpetaAgregar_clicked()
{
    if(!ui->LineCarpetaNueva->text().isEmpty())
    {
        QTreeWidgetItem* carp=new QTreeWidgetItem(ui->VisorArbol);
        carp->setText(0,ui->LineCarpetaNueva->text());
        ListaCarpetas.insert(ui->LineCarpetaNueva->text(),ListaCarpetas.size()-1);
        ui->LineCarpetaNueva->clear();


    }
}

void VisorImagenes::on_BotonCarpetaBorrar_clicked()
{
//QList<QTreeWidgetItem*> items = treeWidget->findItems("test",Qt::MatchExactly, 3);
    if(CarpetaActual->childCount()>0)
    {
        QMessageBox mensaje;
        mensaje.setText("Error, La Carpeta esta siendo usada");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }

    QTreeWidgetItem* item =CarpetaActual;
    int i = ui->VisorArbol->indexOfTopLevelItem(item);
    ui->VisorArbol->takeTopLevelItem(i);
    delete item;
//    ui->VisorArbol->removeItemWidget(CarpetaActual,0);
}

void VisorImagenes::on_BotonAgregarImagen_clicked()
{
   /**/

    Imagen* Img=new Imagen();
    Img->setPixel(Definiciones::toQByteArray(fileName));

    if(fileName.isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Imagen Necesaria");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }
    if(ui->LineCarpeta->text().isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Carpeta Necesaria");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }
    if(ui->LineNombre->text().isEmpty())
    {
        QMessageBox mensaje;
        mensaje.setText("Error, Nombre Necesario");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
        return;
    }

    Img->setNombre(ui->LineNombre->text()+".png");
    Img->setCarpeta(ui->LineCarpeta->text());

    FabricaBaseDatos* bd=DefBD::IniciarBD();
    bd->Fabrica->Conectar();
    FabricaImagenes*  fi=bd->Fabrica->CrearImagen();
    if(fi->Insertar(*Img))
    {
        QTreeWidgetItem *Item = new QTreeWidgetItem(CarpetaActual);
        Item->setText(0, Img->getNombre());
        DefBD::GuardarImagen(Img->getCarpeta()+"/"+Img->getNombre());

        QMessageBox mensaje;
        mensaje.setText("La imagen fue agregada con Exito");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();

        ui->LineCarpeta->clear();
        ui->LineNombre->clear();
    }
    else
    {
        QMessageBox mensaje;
        mensaje.setText("La imagen no fue agregada, Error");
        mensaje.setIcon(QMessageBox::Information);
        mensaje.exec();
    }
    bd->Fabrica->Desconectar();
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
     QString ruta=RutaImagenes+TextP+"/"+current->text(0);
      QPixmap*  pix=new QPixmap(ruta);
     ui->labelImagen->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));

    }

  //  ui->LineCarpeta->setText(previous->text());
}
