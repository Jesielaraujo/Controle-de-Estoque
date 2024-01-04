#ifndef GESTAO_COLABORADORES_H
#define GESTAO_COLABORADORES_H

#include <QDialog>

namespace Ui {
class gestao_colaboradores;
}

class gestao_colaboradores : public QDialog
{
    Q_OBJECT

public:
    explicit gestao_colaboradores(QWidget *parent = nullptr);
    ~gestao_colaboradores();

private:
    Ui::gestao_colaboradores *ui;
};

#endif // GESTAO_COLABORADORES_H
