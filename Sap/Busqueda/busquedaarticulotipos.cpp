#include "busquedaarticulotipos.h"
#include "ui_busquedaarticulotipos.h"

BusquedaArticuloTipos::BusquedaArticuloTipos(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BusquedaArticuloTipos)
{
    ui->setupUi(this);
    /*conexion con el visor*/
    VisorConsulta=new VisorConsultas(this);

     connect(this,SIGNAL(my_signal(QSqlQueryModel *)),VisorConsulta,SLOT(Consulta(QSqlQueryModel *)));
     connect(this,SIGNAL(SignalRepisa(ObjetoMaestro*)),parent,SLOT(ActualizarRepisa(ObjetoMaestro *)));

     /**/

    /*Fondo Madera*/
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

    /*------------------------------------------------*/

/*Conexio con la BD y Fabrica*/
        BD=DefBD::IniciarBD();
        Fab=BD->Fabrica->CrearArticuloTipo();
/*------------------*/

        /*Autocompletar*/
        QSqlQueryModel* Model;
        BD->Fabrica->Conectar();


        Model=new QSqlQueryModel();
        Model->setQuery("SELECT distinct nombre FROM articulo_tipo;");
        Completar=new QCompleter(Model,this);
        Completar->setCaseSensitivity(Qt::CaseInsensitive);
        Completar->setCompletionColumn(0);
        ui->LineNombre->setCompleter(Completar);

        BD->Fabrica->Desconectar();
        /**/


        VisorConsulta->show();
        VisorConsulta->setGeometry(parent->x()+parent->width(),parent->y()+this->height(),300,300);

}

BusquedaArticuloTipos::~BusquedaArticuloTipos()
{

    delete ui;

}

void BusquedaArticuloTipos::ObtenerConsulta()
{
    ArticuloTipo ObjetoConsulta;

    if(ui->CheckNombre->isChecked())
    {
        ObjetoConsulta.setNombre(ui->LineNombre->text());
      //  FlagConsulta=CAMPOS;
    }

    BD->Fabrica->Conectar();

    QString ini=ui->LineInicio->text();
    QString fin=ui->LineFin->text();
    QString Extra="LIMIT "+fin+" offset "+ini;
    QSqlQueryModel* Model= Fab->BuscarTabla(ObjetoConsulta,Extra,CAMPOS);

    BD->Fabrica->Desconectar();

    emit my_signal(Model);
   // emit SignalRepisa((ObjetoMaestro*)(&ObjetoConsulta));
    VisorConsulta->move(this->x(),this->y()+this->height());

}

void BusquedaArticuloTipos::on_BotonConsultar_clicked()
{
    ObtenerConsulta();
}

void BusquedaArticuloTipos::on_tabWidget_tabBarClicked(int index)
{
    if(index==1)
    {
        VisorConsulta->close();
        this->close();
    }
}

void BusquedaArticuloTipos::on_CheckNombre_stateChanged(int arg1)
{
    if(arg1)
    {
        ui->LineNombre->setEnabled(true);
    }
    else
    {

        ui->LineNombre->setEnabled(false);
    }
}

void BusquedaArticuloTipos::on_LineNombre_textChanged(const QString &arg1)
{
  // ObtenerConsulta();
}
