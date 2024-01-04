#include "editar_vendas.h"
#include "ui_editar_vendas.h"
#include "vender.h"

editar_vendas::editar_vendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editar_vendas)
{
    ui->setupUi(this);
    ui->txt_editarprod->setText(VENDER::g_produto);
    ui->txt_editarpre->setText(VENDER::g_valunit);
    ui->txt_editarqtde->setText(VENDER::g_qtde);
}


editar_vendas::~editar_vendas()
{
    delete ui;
}

void editar_vendas::on_btn_editar_confirmar_clicked()
{
    QString aux;

    VENDER::alterar=true;
    VENDER::g_qtde=ui->txt_editarqtde->text();

    aux=ui->txt_editarpre->text();
    std::replace(aux.begin(),aux.end(),',','.');
    VENDER::g_valunit=aux;

    VENDER::g_valunit=QString::number(ui->txt_editarqtde->text().toDouble()*aux.toDouble());
    close();
}


void editar_vendas::on_btn_editar_cancelar_clicked()
{
  VENDER::alterar=false;
  close();
}


