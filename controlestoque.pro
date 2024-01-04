QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
TARGET = ex12.out

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    gestao_colaboradores.cpp \
    gestao_estoque.cpp \
    gestao_vendas.cpp \
    ex12.cpp \
    sobre.cpp \
    tela_principal.cpp \
	vender.cpp \
	editar_vendas.cpp \
	login.cpp \
	caminhoadm.cpp \

HEADERS += \
    Conexao.h \
    gestao_colaboradores.h \
    gestao_estoque.h \
    gestao_vendas.h \
    sobre.h \
    tela_principal.h \
    vender.h \
	editar_vendas.h \
	login.h \
	caminhoadm.h \

FORMS += \
    gestao_colaboradores.ui \
    gestao_estoque.ui \
    gestao_vendas.ui \
    sobre.ui \
    tela_principal.ui \
    vender.ui \
	editar_vendas.ui \
	login.ui \
	caminhoadm.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    arquivoderec.qrc
