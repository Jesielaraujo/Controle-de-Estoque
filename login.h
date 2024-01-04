#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include"Conexao.h"

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    bool logado;
    Conexao con;
    QString nome,acesso;

    int id;

private slots:
    void on_btn_logar_clicked();

    void on_btn_cancelar_clicked();

	void on_btn_debug_clicked();

private:
    Ui::login *ui;
};

#endif // LOGIN_H
