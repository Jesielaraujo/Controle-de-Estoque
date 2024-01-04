#ifndef GESTAO_ESTOQUE_H
#define GESTAO_ESTOQUE_H
#include <QDialog>
#include <QMessageBox>
#include"Conexao.h"
#include <QtSql>
#include<QTableWidget>

namespace Ui {
class gestao_estoque;
}

class gestao_estoque : public QDialog
{
    Q_OBJECT

public:
    explicit gestao_estoque(QWidget *parent = nullptr);
    ~gestao_estoque();
    Conexao con;
    void removerlinhas(QTableWidget *tw);

private slots:
    void on_btn_novoproduto_clicked();

    void on_btn_gravraproduto_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_tw_ge_produtos_itemSelectionChanged();

    void on_btn_ge_gravar_clicked();

    void on_btn_ge_excluir_clicked();

    void on_btn_ge_filtrar_clicked();

private:
    Ui::gestao_estoque *ui;
};

#endif // GESTAO_ESTOQUE_H
