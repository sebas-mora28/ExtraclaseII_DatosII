#include "mainwindow.h"
#include "Client.cpp"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

Client* client = new Client();
QStandardItemModel* model;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{



    ui->setupUi(this);


    //Client* client = new Client();
    client->createSocket();





    //SET THE FONT TO
    QFont font;
    font.setBold(true);
    font.setPointSize(12);
    ui->shortest_path_title->setFont(font);
    ui->title->setFont(font);
    ui->shortest_path_value->setFont(font);

    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    model->setColumnCount(3);
    model->setHorizontalHeaderItem(0,new QStandardItem("Start Nodo"));
    model->setHorizontalHeaderItem(1,new QStandardItem("End Nodo"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Weight") );
    ui->tableView->setColumnWidth(0, 160);
    ui->tableView->setColumnWidth(1, 160);
    ui->tableView->setColumnWidth(2, 143);




   }

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ShortestPath_clicked()
{
    QString start_node_selected = ui->StartNode_box->currentText();
    QString end_node_selected = ui->EndNode_box->currentText();

    QString shortest_path_value = client->sendMessage(start_node_selected.toStdString() + "," + end_node_selected.toStdString());

    ui->shortest_path_value->setText(shortest_path_value);



}

void MainWindow::on_pushButton_clicked(){


    QString bodyTxt =  client->sendMessage(std::string("loadGraph"));
    std::cout << bodyTxt.toStdString() << "\n";

    QStringList bodyTxtList = bodyTxt.split("|");
    model->setRowCount(bodyTxtList.length()-2);

    ui->amount_of_nodos->setText(bodyTxtList[0]);
    for(int i=1; i<= bodyTxtList[0].toInt(); i++){
        ui->StartNode_box->addItem(QString::number(i));
        ui->EndNode_box->addItem(QString::number(i));

    }


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
