#include "gestao_vendas.h"
#include "ui_gestao_vendas.h"
#include<QtSql>
#include<QDebug>
gestao_vendas::gestao_vendas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestao_vendas)
{
    ui->setupUi(this);

    ui->tw_listadeprodutosvendas->horizontalHeader()->setVisible(true);
    ui->tw_listadeprodutosvendas->setColumnCount(5);
    QStringList cabec{"Mov.","Produto","Qtde","valor.Un","valor.To"};
    ui->tw_listadeprodutosvendas->setHorizontalHeaderLabels(cabec);
    ui->tw_listadeprodutosvendas->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//redimensionar de acordo com o conteudo
    ui->tw_listadeprodutosvendas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_listadeprodutosvendas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listadeprodutosvendas->setEditTriggers(QAbstractItemView::NoEditTriggers);


    ui->tw_listavendas->horizontalHeader()->setVisible(true);
    ui->tw_listavendas->setColumnCount(6);
    QStringList cabe{"ID","Data","Hora","Colab","V.Total","T.pgto"};
    ui->tw_listavendas->setHorizontalHeaderLabels(cabe);
    ui->tw_listavendas->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);//redimensionar de acordo com o conteudo
    ui->tw_listavendas->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw_listavendas->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listavendas->setEditTriggers(QAbstractItemView::NoEditTriggers);

     con.abrir();
     int cont=0;
     QSqlQuery query;
     query.prepare("select * from tb_vendas");
     query.exec();
     query.first();
     do {
     ui->tw_listavendas->insertRow(cont);
     ui->tw_listavendas->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
     ui->tw_listavendas->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
     ui->tw_listavendas->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
     ui->tw_listavendas->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
     ui->tw_listavendas->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));
     ui->tw_listavendas->setItem(cont,5,new QTableWidgetItem(query.value(5).toString()));
    }while(query.next());
    con.fechar();

}

gestao_vendas::~gestao_vendas()
{
    delete ui;
}

void gestao_vendas::on_tw_listadeprodutosvendas_itemSelectionChanged()
{
    ui->tw_listadeprodutosvendas->setRowCount(0);
    con.abrir();
    int cont=0;
    QSqlQuery query;
    query.prepare("select id_movimentacao,produto, qtde ,valor_un,valor_total from tb_produtoVendas where id_venda="+ui->tw_listavendas->item(ui->tw_listavendas->currentRow(),0)->text());
    if(!query.exec()){
        qDebug()<<"ERRO:"<< query.lastError().text();

    }
    query.first();
    do {
    ui->tw_listavendas->insertRow(cont);
    ui->tw_listavendas->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
    ui->tw_listavendas->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
    ui->tw_listavendas->setItem(cont,2,new QTableWidgetItem(query.value(2).toString()));
    ui->tw_listavendas->setItem(cont,3,new QTableWidgetItem(query.value(3).toString()));
    ui->tw_listavendas->setItem(cont,4,new QTableWidgetItem(query.value(4).toString()));

   }while(query.next());
   con.fechar();

}

