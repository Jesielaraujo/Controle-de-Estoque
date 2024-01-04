#ifndef VENDER_H
#define VENDER_H

#include <QDialog>
#include "Conexao.h"
#include <QTableWidget>
#include <QtSql>

namespace Ui {
class VENDER;
}

class VENDER : public QDialog
{
    Q_OBJECT

public:
    explicit VENDER(QWidget *parent = nullptr);
    ~VENDER();
    Conexao con;
    int contlinhas;
    void resetar_campos();
    double calcular_Total(QTableWidget *tw, int coluna);
    static QString g_idprod, g_produto,g_qtde,g_valunit,g_vtotal;
    static bool alterar;
    void limparvendas(QTableWidget *tw);

private slots:

    void on_btn_pesquisarprod_clicked();

    void on_btn_excluirprod_clicked();

    void on_btn_editarprod_clicked();

    void on_btn_finalizarvendas_clicked();

private:
    Ui::VENDER *ui;
};

#endif // VENDER_H
