#ifndef VISORIMAGENES_H
#define VISORIMAGENES_H

#include <QMainWindow>
#include "../Fabricas.h"
#include "../DefBD.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTreeWidget>
namespace Ui {
class VisorImagenes;
}

class VisorImagenes : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisorImagenes(QWidget *parent = 0);
    ~VisorImagenes();

private slots:
    void on_BotonImagen_clicked();

    void on_BotonCarpetaAgregar_clicked();

    void on_BotonCarpetaBorrar_clicked();

    void on_BotonAgregarImagen_clicked();

    void on_VisorArbol_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    QString fileName;
    Ui::VisorImagenes *ui;
    QMap<QString,int> ListaCarpetas;
    QTreeWidgetItem*  CarpetaActual;
};

#endif // VISORIMAGENES_H
