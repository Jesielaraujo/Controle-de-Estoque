#ifndef CONEXAO_H
#define CONEXAO_H
#include<QtSql>
#include<QMessageBox>
class Conexao{

    public:
    QSqlDatabase bancoDeDados;
    QString local;//alt
    QString banco ;//alt
    Conexao()
    {
		local=qApp->applicationDirPath();//alt
		banco = local+"/db/controlestoque.db";//alterar no hydra talvez
		bancoDeDados=QSqlDatabase::addDatabase("QSQLITE");
    }
    void fechar(){
        bancoDeDados.close();
    }
    bool abrir(){

		bancoDeDados.setDatabaseName(banco);

        if(!bancoDeDados.open()){
          return false;

        }else{
            return true;
        }
    }
    bool abert(){
        if(bancoDeDados.isOpen()){
          return true;

        }else{
            return false;
        }
    }

};

#endif // CONEXAO_H
