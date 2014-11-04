#include "visorconsultas.h"
#include "ui_visorconsultas.h"

VisorConsultas::VisorConsultas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VisorConsultas)
{
    ui->setupUi(this);

    /*Fondo Madera*/
    this->setWindowFlags(Qt::Window
                         | Qt::CustomizeWindowHint);

     QPixmap bkgnd(FondoForm);
        bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        QPalette palette;
        palette.setBrush(QPalette::Background, bkgnd);
        this->setPalette(palette);

    /*------------------------------------------------*/


}

VisorConsultas::~VisorConsultas()
{
    delete ui;
}

void VisorConsultas::Consulta(QSqlQueryModel *Modelo)
{

    QSortFilterProxyModel* proxy=new QSortFilterProxyModel(this);
    proxy->setSourceModel(Modelo);
   // proxy->setFilterKeyColumn(1);
//    proxy->lessThan("a","b");
 //   proxy->sort(2,Qt::AscendingOrder);
    ui->Tabla->setModel(proxy);
    ui->Tabla->setSortingEnabled(true);
    //ui->Tabla->resizeColumnsToContents();
    //ui->Tabla->resizeRowsToContents();
    //ui->Tabla->sortByColumn(1, Qt::AscendingOrder);

   // ui->Tabla->reset();
    //ui->Tabla->show();
    /*ui->Tabla->resize();
    int ancho=ui->Tabla->width();
    int alto=ui->Tabla->height();
    int xf=this->x();
    int yf=this->y();

    this->setGeometry(xf,yf,ancho,alto);
*/
}
