#ifndef TELA_PRINCIPAL_H
#define TELA_PRINCIPAL_H

#include <QMainWindow>
#include<QtSql>
#include<QDebug>
#include<QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class tela_principal; }
QT_END_NAMESPACE

class tela_principal : public QMainWindow
{
    Q_OBJECT

public:
    tela_principal(QWidget *parent = nullptr);
    ~tela_principal();
    QIcon cadFechado;
    QIcon *cadAberto=new QIcon;
    bool bloqueado;
   static bool logado;
   static QString nome_colab,acesso_colab,username_colab;
   static int id_colab;

private slots:
    void on_btn_bloqueiar_clicked();

    void on_pushButton_clicked();

    void on_actionEstoque_triggered();

    void on_actionColaboradores_triggered();

    void on_actionVendas_triggered();

    void on_actionSair_triggered();

    void on_actionSobre_triggered();

private:
    Ui::tela_principal *ui;
};
#endif // TELA_PRINCIPAL_H
