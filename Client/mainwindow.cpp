#include "mainwindow.h"
#include "Client.cpp"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

Client* client = new Client();

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);


    //Client* client = new Client();
    client->createSocket();


    std::string message = "hola mundo";
    std::string me = client->sendMessage(message);

    QString bodyTxt = QString::fromStdString(me);
    std::cout << bodyTxt.toStdString() << "\n";

    QStringList bodyTxtList = bodyTxt.split("|");

    ui->amount_of_nodos->setText(bodyTxtList[0]);
    for(int i=1; i<= bodyTxtList[0].toInt(); i++){
        ui->StartNode_box->addItem(QString::number(i));
        ui->EndNode_box->addItem(QString::number(i));

    }


    QStandardItemModel* model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    model->setColumnCount(2);
    model->setRowCount(bodyTxtList.length()-2);
    model->setHorizontalHeaderItem(0,new QStandardItem("Start Nodo"));
    model->setHorizontalHeaderItem(1,new QStandardItem("End Nodo"));
    ui->tableView->setColumnWidth(0, 240);
    ui->tableView->setColumnWidth(1, 223);



    for(int i=0; i<bodyTxtList.length()-1; i++){
        std::cout << bodyTxtList[i].toStdString() << "\n";
    }


    for(int row=1; row < bodyTxtList.length()-1; row++){
        auto current_values = bodyTxtList[row].split(",");
        for(int column=0; column < model->columnCount(); column++){
            model->setItem(row-1, column, new QStandardItem(current_values[column]));

        }

    }

   }

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString start_node_selected = ui->StartNode_box->currentText();
    QString end_node_selected = ui->EndNode_box->currentText();

    client->sendMessage(start_node_selected.toStdString() + "," + end_node_selected.toStdString());


   }
