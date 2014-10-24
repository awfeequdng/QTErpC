#ifndef VISORIMAGENES_H
#define VISORIMAGENES_H

#include <QMainWindow>
#include "../Fabricas.h"
#include "../DefBD.h"
namespace Ui {
class VisorImagenes;
}

class VisorImagenes : public QMainWindow
{
    Q_OBJECT

public:
    explicit VisorImagenes(QWidget *parent = 0);
    ~VisorImagenes();

private:
    Ui::VisorImagenes *ui;
};

#endif // VISORIMAGENES_H
