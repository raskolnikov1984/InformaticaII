#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "usuario.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    miUsuario = new Usuario();

    ui->ComidaComboBox->addItem("");
    ui->ComidaComboBox->addItem("Desayuno.");
    ui->ComidaComboBox->addItem("Almuerzo.");
    ui->ComidaComboBox->addItem("Cena.");

    QStringList dias;

    dias << "" << "Lunes" << "Martes" << "Miercoles" << "Jueves" << "Viernes" << "Sabado" << "Domingo";
    ui->DiaComboBox->addItems(dias);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_enviarButton_clicked()
{
    miUsuario->setNombre(ui->NombreEdit->text());
    miUsuario->setCorreo(ui->NombreEdit->text());
    miUsuario->setTelefono(ui->TelefonoEdit->text());
    miUsuario->setComidapreferida(ui->ComidaPreferidaEdit->toPlainText());
    miUsuario->setDia(ui->DiaComboBox->currentText());
}


void MainWindow::on_verButton_clicked()
{
    QString Informacion = "Nombre: " + miUsuario->getNombre()+
                          "\n Correo: " + miUsuario->getCorreo()+
                          "\n Telefono: " + miUsuario->getTelefono()+
                          "\n Voy a un restaurante a: " + miUsuario->getComidaDia()+
                          "\n Preferiblemente los dias: " + miUsuario->getDia()+
                          "\n Mi Comida Preferida es: " + miUsuario->getComidapreferida();

    ui->InformacionEdit->append(Informacion);
}

