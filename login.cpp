#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include "tela_principal.h"
#include "caminhoadm.h"
#include "vender.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    logado=false;

}

login::~login()
{
    delete ui;
}

void login::on_btn_logar_clicked()
{
    if(ui->txt_username->text() == "adm" && ui->txt_senha->text() == "123")
    {
        caminhoAdm f_camiadm;
        close();
        f_camiadm.exec();

    }
    else if(ui->txt_username->text() == "cxa" && ui->txt_senha->text() == "3")
    {
        VENDER f_vender;
        close();
        f_vender.exec();

    }
    else
    {
        QMessageBox::warning(this,"ERRO", "Falha no Login");

    }

}
/*void login::on_btn_logar_clicked()
{
    if(!con.abrir()){
        QMessageBox::warning(this,"ERRO", "Erro ao abrir o banco de Dados");
    }else{
        QString username,senha;
        username=ui->txt_username->text();
        senha=ui->txt_senha->text();
        QSqlQuery query;
        query.prepare("Select * from tb_colaboradores where username_colab='"+username+"' and senha_colab='"+senha+"'");
        if(query.exec()){
            query.first();
            if(query.value(1).toString()!=""){
               tela_principal::logado=true;
               tela_principal::nome_colab=query.value(1).toString();
               tela_principal::id_colab=query.value(0).toInt();
               tela_principal::acesso_colab=query.value(4).toString();

                // nome=query.value(1).toString();
                //acesso=query.value(4).toString();
                con.fechar();
                close();
            }else{

                QMessageBox::warning(this,"ERRO", "Falha no Login");
            }
        }
    }
    //Login
    con.fechar();
}*/


void login::on_btn_cancelar_clicked()
{
    logado=false;
    close();
}
/*
bool login::getLogado(){

return logado;
}
QString login::getNome(){
    return nome;
}
QString login::getAcesso(){
    return acesso;
}*/

void login::on_btn_debug_clicked()
{
    caminhoAdm f_camiadm;
    close();
    f_camiadm.exec();

}
