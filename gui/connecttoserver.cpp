#include "connecttoserver.h"
#include "ui_connecttoserver.h"

ConnectToServer::ConnectToServer(QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::ConnectToServer)
{
    ui->setupUi(this);

    //Set Port from Config
    QString port = Settings::getInstance()->getProperty("network/port");
    ui->porttxt->setText(port);
}

ConnectToServer::~ConnectToServer()
{
    delete ui;
}

void ConnectToServer::gameStarted()
{
    this->close();
}

void ConnectToServer::on_connectbtn_clicked()
{
    emit connectToServer(ui->ipadresstxt->text(), ui->porttxt->text());
    ui->connectbtn->setDisabled(true);
    ui->connectbtn->setText("Waiting...");
}

void ConnectToServer::on_cancelbtn_clicked()
{
    this->close();
}
