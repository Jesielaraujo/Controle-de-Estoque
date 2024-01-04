#ifndef CAMINHOADM_H
#define CAMINHOADM_H

#include <QDialog>

namespace Ui {
class caminhoAdm;
}

class caminhoAdm : public QDialog
{
    Q_OBJECT

public:
    explicit caminhoAdm(QWidget *parent = nullptr);
    ~caminhoAdm();

private slots:
	void on_pushButton_clicked();

	void on_pushButton_3_clicked();

	void on_pushButton_2_clicked();

	void on_pushButton_4_clicked();

private:
    Ui::caminhoAdm *ui;
};

#endif // CAMINHOADM_H
