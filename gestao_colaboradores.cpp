#include "gestao_colaboradores.h"
#include "ui_gestao_colaboradores.h"

gestao_colaboradores::gestao_colaboradores(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestao_colaboradores)
{
    ui->setupUi(this);
}

gestao_colaboradores::~gestao_colaboradores()
{
    delete ui;
}
