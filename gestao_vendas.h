#ifndef GESTAO_VENDAS_H
#define GESTAO_VENDAS_H

#include <QDialog>
#include"Conexao.h"
namespace Ui {
class gestao_vendas;
}

class gestao_vendas : public QDialog
{
    Q_OBJECT

public:
    explicit gestao_vendas(QWidget *parent = nullptr);
    ~gestao_vendas();
    Conexao con;
private slots:
    void on_tw_listadeprodutosvendas_itemSelectionChanged();

private:
    Ui::gestao_vendas *ui;
};

#endif // GESTAO_VENDAS_H
