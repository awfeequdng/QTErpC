#include "formarticulos.h"
#include "ui_formarticulos.h"

#include <QFileDialog>

FormArticulos::FormArticulos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormArticulos)
{
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

    ui->guardar->setIcon(QIcon(BotonGuardar));
    ui->modificar->setIcon(QIcon(BotonModificar));
    ui->eliminar->setIcon(QIcon(BotonEliminar));

    Estado=INSERTAR;
    ui->modificar->setEnabled(false);
    ui->eliminar->setEnabled(false);
    ui->guardar->setEnabled(true);

    mRepisa=RepisaArticulos::Iniciar();
}

void FormArticulos::SetArticulos(Articulos valor)
{

    ui->nombre->setText(valor.getNombre());
    ui->codigo->setText(valor.getCodigo());
    ui->unidad->setText(valor.getUnidad());
    ui->vigencia->setText(valor.getVigencia());
    ui->codigo_tipo->setText(valor.getCodigo_Tipo());
    ui->imagen->setText(valor.getImagen());

    QPixmap pix;
    pix.load(RutaImagenes+valor.getImagen());
    ui->imagenlabel->setPixmap(pix.scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    ui->guardar->setEnabled(false);
    ui->modificar->setEnabled(true);
    ui->eliminar->setEnabled(true);
    ui->nombre->setEnabled(false);
}

FormArticulos::~FormArticulos()
{
    delete ui;
}

void FormArticulos::on_BotonArchivo_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Abrir Imagen"),RutaImagenes,tr("Archivo Imagen (*.png)"));

   if (!fileName.isEmpty())
   {
     QPixmap*  pix=new QPixmap(fileName);

       ui->imagenlabel->setPixmap(pix->scaled(60,60,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
       ui->imagen->setText(fileName);

    }
}

void FormArticulos::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
    this->close();
    }
}

void FormArticulos::on_guardar_clicked()
{
    FabricaBaseDatos* Bd=FabricaBaseDatos::IniciarFabrica(POSTGRES);
    FabricaArticulos* Fobj=Bd->Fabrica->CrearArticulos();

    if(Estado==INSERTAR)
    {
        Articulos* objeto=new Articulos();
        objeto->setImagen(Definiciones::toQByteArray(ui->imagen->text()));
        objeto->setNombre(ui->nombre->text());

        if(Bd->Fabrica->Conectar())
        {
            if(Fobj->Insertar(*objeto))
            {
                QMessageBox mensaje;
                mensaje.setText("El Articulo fue Añadido a la Base de Datos");
                mensaje.setIcon(QMessageBox::Information);
                mensaje.exec();
            }
            else
            {
                QMessageBox mensaje;
                mensaje.setText("Error el articulo no fue añadido");
                mensaje.setIcon(QMessageBox::Warning);
                mensaje.exec();
            }
        }
        else
        {
            QMessageBox mensaje;
            mensaje.setText("Error no hay conexion con la base de datos");
            mensaje.setIcon(QMessageBox::Warning);
            mensaje.exec();

        }
    }

    if(Estado==MODIFICAR)
    {
        Articulos* objAnt=new Articulos();
        objAnt->setCodigo(ui->codigo->text());

        Articulos* objMod=new Articulos();
        objMod->setImagen(Definiciones::toQByteArray(ui->imagen->text()));
        objMod->setNombre(ui->nombre->text());
        objMod->setUnidad(ui->unidad->text());
        objMod->setVigencia(ui->vigencia->text());
        objMod->setCodigo_Tipo(ui->codigo_tipo->text());

        if(Bd->Fabrica->Conectar())
        {
            if(Fobj->Actualizar(*objAnt,*objMod))
            {
                QMessageBox mensaje;
                mensaje.setText("El Articulo fue Modificado con Exito");
                mensaje.setIcon(QMessageBox::Information);
                mensaje.exec();
            }
            else
            {
                QMessageBox mensaje;
                mensaje.setText("Error el articulo no fue Modificado");
                mensaje.setIcon(QMessageBox::Warning);
                mensaje.exec();
            }
        }
        else
        {
            QMessageBox mensaje;
            mensaje.setText("Error no hay conexion con la base de datos");
            mensaje.setIcon(QMessageBox::Warning);
            mensaje.exec();

        }
    }

    ui->guardar->setEnabled(false);
    ui->eliminar->setEnabled(true);
    ui->modificar->setEnabled(true);
    mRepisa->ActualizarMapa();
    this->close();
}

void FormArticulos::on_eliminar_clicked()
{

}

void FormArticulos::on_modificar_clicked()
{
    Estado=MODIFICAR;
    ui->modificar->setEnabled(false);
    ui->guardar->setEnabled(true);
    ui->eliminar->setEnabled(false);
    ui->nombre->setEnabled(true);
}
