#include "vender.h"
#include "ui_vender.h"
#include <QMessageBox>
#include <QTableWidget>
#include "editar_vendas.h"
#include "tela_principal.h"

QString VENDER::g_idprod;
QString VENDER::g_produto;
QString VENDER::g_qtde;
QString VENDER::g_valunit;
QString VENDER::g_vtotal;
bool VENDER::alterar;

VENDER::VENDER(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VENDER)
{
    ui->setupUi(this);
    if(!con.abert())
    {
        if(!con.abrir())
        {
            QMessageBox::warning(this,"Erro","Erro ao acessar o Banco de dados");
        }
    }

    ui->tw_listprodutos->setColumnCount(5);
    ui->tw_listprodutos->setColumnWidth(0,100);
    ui->tw_listprodutos->setColumnWidth(1,200);
    ui->tw_listprodutos->setColumnWidth(2,100);
    ui->tw_listprodutos->setColumnWidth(3,100);
    ui->tw_listprodutos->setColumnWidth(4,100);

    QStringList estrutura={"Código","Produto","Valor Unitario","Quantidade","Total"};
    ui->tw_listprodutos->setHorizontalHeaderLabels(estrutura);
    ui->tw_listprodutos->setStyleSheet("QTableView{selection-background-color:red;}");
    ui->tw_listprodutos->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tw_listprodutos->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tw_listprodutos->verticalHeader()->setVisible(false);

    ui->txt_codprod->setFocus();
    contlinhas = 0;

}

VENDER::~VENDER()
{
    delete ui;
}

/*void VENDER::on_txt_codigoprod_returnPressed()
{
    QSqlQuery query;
    QString id = ui->txt_codprod->text();
    double vtotal;

    query.prepare("select id_produto,produto,valor_venda from tb_produtos where id_produto="+id);
    if(query.exec())
    {
        query.first();
        if(query.value(0).toString()!="")
        {
        ui->tw_listprodutos->insertRow(contlinhas);
        ui->tw_listprodutos->setItem(contlinhas, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 3, new QTableWidgetItem(ui->txt_qtde->text()));
        vtotal = ui->txt_qtde->text().toDouble()*query.value(2).toDouble();
        ui->tw_listprodutos->setItem(contlinhas, 4, new QTableWidgetItem(QString::number(vtotal)));
        ui->tw_listprodutos->setRowHeight(contlinhas,20);
        contlinhas++;
        }
        else
        {
            QMessageBox::warning(this,"Erro","Produto não encontrado");
        }
        ui->txt_codprod->clear();
        ui->txt_qtde->setText("1");
    }
    else
    {
     QMessageBox::warning(this,"Erro","Erro ao inserir o produto");
    }
}*/

void VENDER::on_btn_pesquisarprod_clicked()
{
    QSqlQuery query;
    QString id = ui->txt_codprod->text();
    double vtotal;

    query.prepare("select id_produto,produto,valor_venda from tb_produtos where id_produto="+id);
    if(query.exec())
    {
        query.first();
        if(query.value(0).toString()!="")
        {
        ui->tw_listprodutos->insertRow(contlinhas);
        ui->tw_listprodutos->setItem(contlinhas, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 1, new QTableWidgetItem(query.value(1).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 2, new QTableWidgetItem(query.value(2).toString()));
        ui->tw_listprodutos->setItem(contlinhas, 3, new QTableWidgetItem(ui->txt_qtde->text()));
        vtotal = ui->txt_qtde->text().toDouble()*query.value(2).toDouble();
        ui->tw_listprodutos->setItem(contlinhas, 4, new QTableWidgetItem(QString::number(vtotal)));
        ui->tw_listprodutos->setRowHeight(contlinhas,20);
        contlinhas++;
        ui->lb_vendastotais->setText("RS "+QString::number(calcular_Total(ui->tw_listprodutos,4)));
        }
        else
        {
            QMessageBox::warning(this,"Erro","Produto não encontrado");
        }
        resetar_campos();
    }
    else
    {
     QMessageBox::warning(this,"Erro","Erro ao inserir o produto");
    }
}

void VENDER::resetar_campos()
{
    ui->txt_codprod->clear();
    ui->txt_qtde->setText("1");
    ui->txt_codprod->setFocus();
}
void VENDER::limparvendas(QTableWidget *tw)
{
    while(tw->rowCount()>0)
    {
      tw->removeRow(0);
    }
}

double VENDER::calcular_Total(QTableWidget *tw, int coluna)
{
        int totallines;
        double total;
        int i;

        totallines = tw->rowCount();
        for(i=0;i<totallines;i++)
        {
            total+=tw->item(i,coluna)->text().toDouble();
        }
    return total;
}




void VENDER::on_btn_excluirprod_clicked()
{
    if(ui->tw_listprodutos->currentColumn()!=-1)
    {
        QMessageBox::StandardButton opc=QMessageBox::question(this,"Exclusão?", "Deseja excluir o Produto selecionado?",QMessageBox::Yes|QMessageBox::No);
        if(opc==QMessageBox::Yes)
        {
            ui->tw_listprodutos->removeRow(ui->tw_listprodutos->currentRow());
            ui->lb_vendastotais->setText("RS "+QString::number(calcular_Total(ui->tw_listprodutos,4)));
            contlinhas--;
        }
    }
    else
    {
      QMessageBox::warning(this,"Erro","Selecione um Produto primeiro");

    }
}


void VENDER::on_btn_editarprod_clicked()
{
    if(ui->tw_listprodutos->currentColumn()!=-1)
    {
        int linha=ui->tw_listprodutos->currentRow();
        g_idprod=ui->tw_listprodutos->item(linha,0)->text();
        g_produto=ui->tw_listprodutos->item(linha,1)->text();
        g_qtde=ui->tw_listprodutos->item(linha,3)->text();
        g_valunit=ui->tw_listprodutos->item(linha,2)->text();
        editar_vendas editar;
        editar.exec();


        if(alterar)
        {
            ui->tw_listprodutos->item(linha,2)->setText(g_valunit);
            ui->tw_listprodutos->item(linha,3)->setText(g_qtde);
            ui->tw_listprodutos->item(linha,4)->setText(g_vtotal);
            ui->lb_vendastotais->setText("RS "+QString::number(calcular_Total(ui->tw_listprodutos,4)));

        }
    }
    else
    {
        QMessageBox::warning(this,"Erro", "Nenhum produto Selecionado");
    }

}


void VENDER::on_btn_finalizarvendas_clicked()
{
    if(ui->tw_listprodutos->rowCount()>0)
    {
        int idvenda;
        QString finalizarvenda;
        double total= calcular_Total(ui->tw_listprodutos,4);
        QString data=QDate::currentDate().toString("yyyy-MM-dd");
        QString hora=QTime::currentTime().toString("hh:mm:ss");
        QSqlQuery query;
        query.prepare("insert into tb_vendas (data_venda,hora_venda,id_colaborador,valor_total,id_tipopagamento) values ('"+data+"','"+hora+"',"+QString::number(tela_principal::id_colab)+","+QString::number(total)+"1)");
        if(!query.exec())
        {
            QMessageBox::warning(this,"Erro", "Erro ao finalizar a venda!");

        }
        else
        {
            query.prepare("select id_vendas from tb_vendas order by id_vendas desc limit 1");
            query.exec();
            query.first();
            idvenda=query.value(0).toInt();
            finalizarvenda="ID Venda: "+QString::number(idvenda)+"\nValor total: R$"+QString::number(total);
            QMessageBox::information(this,"Venda Concluida",finalizarvenda);
            resetar_campos();
            limparvendas(ui->tw_listprodutos);
            ui->lb_vendastotais->setText("R$ 0.00");
        }
    }
    else
    {
        QMessageBox::warning(this,"Erro", "Sem produtos a serem vendidos!!");

    }

}

