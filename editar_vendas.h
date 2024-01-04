#ifndef EDITAR_VENDAS_H
#define EDITAR_VENDAS_H

#include <QDialog>

namespace Ui {
class editar_vendas;
}

class editar_vendas : public QDialog
{
    Q_OBJECT

public:
    explicit editar_vendas(QWidget *parent = nullptr);
    ~editar_vendas();
private slots:
	void on_btn_editar_confirmar_clicked();

	void on_btn_editar_cancelar_clicked();

private:
    Ui::editar_vendas *ui;
};

#endif // EDITAR_VENDAS_H
