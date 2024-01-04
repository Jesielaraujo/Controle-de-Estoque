#include "tela_principal.h"
#include "sobre.h"
#include "ui_tela_principal.h"
#include<QMessageBox>//verificar se tem  no hydra
#include"login.h"
#include"vender.h"
#include"gestao_colaboradores.h"
#include"gestao_estoque.h"
#include"gestao_vendas.h"

#include<QtSql>

//metodos
int tela_principal::id_colab;
QString tela_principal::nome_colab;
QString tela_principal::acesso_colab;
QString tela_principal::username_colab;
bool tela_principal::logado;

tela_principal::tela_principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::tela_principal)
{
    ui->setupUi(this);


    logado=false;
    cadFechado.addFile(":/imagens/img/fechado.png");
    cadAberto->addFile(":/imagens/img/aberto.png");

    ui->btn_bloqueiar->setText("");
    ui->btn_bloqueiar->setIcon(cadFechado);
    ui->statusbar->addWidget(ui->btn_bloqueiar);
    ui->statusbar->addWidget(ui->lb_nome);
   /* login f_logar;
    f_logar.exec();*/
}

tela_principal::~tela_principal()
{
    delete ui;
}


void tela_principal::on_btn_bloqueiar_clicked()//botao bloqueiar
{
    if(!logado){
      login f_logar;
      f_logar.exec();//chamar tela de desbloqueio

      if(logado){
          ui->btn_bloqueiar->setIcon(*cadAberto);
          ui->lb_nome->setText(nome_colab);
      }
    }else{
        logado=true;
         ui->btn_bloqueiar->setIcon(cadFechado);
         ui->lb_nome->setText("Sem Colaborador");
    }
}


void tela_principal::on_pushButton_clicked()
{
    if(logado){
    VENDER f_vender;
    f_vender.exec();
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador Logado");
    }
}


void tela_principal::on_actionEstoque_triggered()
{
/*    if(logado){
        if((acesso_colab=="A")|| (acesso_colab=="B")){*/
    gestao_estoque f_gestaoestoque;
    f_gestaoestoque.exec();
     // }else{
     //       QMessageBox::information(this,"ACESSO","Acesso não Autorizado");
       // }
   // }else{
       // QMessageBox::information(this,"LOGIN","Não existe colaborador Logado");
   // }
}


void tela_principal::on_actionColaboradores_triggered()
{
    if(logado){
        if(acesso_colab=="B"){

    gestao_colaboradores f_gestaocolab;
    f_gestaocolab.exec();
      }else{
            QMessageBox::information(this,"ACESSO","Acesso não Autorizado");
        }
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador Logado");
    }
}


void tela_principal::on_actionVendas_triggered()
{

    if(logado){
        if(acesso_colab== "B" ){

    gestao_vendas f_gestaovendas;
    f_gestaovendas.exec();
      }else{
            QMessageBox::information(this,"ACESSO","Acesso não Autorizado");
        }
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador Logado");
    }
}


void tela_principal::on_actionSair_triggered()
{

    close();
}


void tela_principal::on_actionSobre_triggered()
{
    sobre f_sobre;
    f_sobre.exec();
}

