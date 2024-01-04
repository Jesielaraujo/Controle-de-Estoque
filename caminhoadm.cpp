#include "caminhoadm.h"
#include "ui_caminhoadm.h"
#include"gestao_colaboradores.h"
#include"gestao_vendas.h"
#include"gestao_estoque.h"
#include "vender.h"

caminhoAdm::caminhoAdm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::caminhoAdm)
{
    ui->setupUi(this);
}

caminhoAdm::~caminhoAdm()
{
    delete ui;
}

void caminhoAdm::on_pushButton_clicked()
{
    gestao_estoque f_gestaoestoque;
    f_gestaoestoque.exec();
}


void caminhoAdm::on_pushButton_3_clicked()
{

    gestao_vendas f_gestaovendas;
    f_gestaovendas.exec();
}


void caminhoAdm::on_pushButton_2_clicked()
{
    gestao_colaboradores f_gestaocolab;
    f_gestaocolab.exec();
}


void caminhoAdm::on_pushButton_4_clicked()
{
	VENDER f_vender;
	f_vender.exec();

}
