#include "mainwindow.h"
#include "Client.cpp"
#include "ui_mainwindow.h"
#include <QStandardItemModel>

Client* client = new Client();
QStandardItemModel* model;
QStandardItemModel* modelShortestPath;
const QString INF = "99999";


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
    ui->amout_nodes_label->setFont(font);
    ui->amount_of_nodos->setFont(font);
    ui->start_node_title->setFont(font);




    model = new QStandardItemModel(this);
    ui->tableView->setModel(model);
    model->setColumnCount(3);
    model->setHorizontalHeaderItem(0,new QStandardItem("Start Nodo"));
    model->setHorizontalHeaderItem(1,new QStandardItem("End Nodo"));
    model->setHorizontalHeaderItem(2, new QStandardItem("Weight") );
    ui->tableView->setColumnWidth(0, 160);
    ui->tableView->setColumnWidth(1, 160);
    ui->tableView->setColumnWidth(2, 143);


    modelShortestPath = new QStandardItemModel(this);
    ui->shortest_path_tableView->setModel(modelShortestPath);
    modelShortestPath->setColumnCount(2);
    modelShortestPath->setHorizontalHeaderItem(0,new QStandardItem("Start Nodo"));
    modelShortestPath->setHorizontalHeaderItem(1,new QStandardItem("End Nodo"));
    modelShortestPath->setHorizontalHeaderItem(2, new QStandardItem("Weight") );
    ui->shortest_path_tableView->setColumnWidth(0, 90);
    ui->shortest_path_tableView->setColumnWidth(1, 90);
    ui->shortest_path_tableView->setColumnWidth(2, 90);








   }

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ShortestPath_clicked()
{
    QString start_node_selected = ui->StartNode_box->currentText();

    QString shortest_path_values = client->sendMessage(start_node_selected.toStdString() + ",");

    if(shortest_path_values.size() !=0){
    std::cout << shortest_path_values.toStdString() << "\n";


    QStringList shortest_path_list = shortest_path_values.split(",");



    for(int row=0; row< shortest_path_list.length(); row++){
        modelShortestPath->setItem(row, 0, new QStandardItem(start_node_selected));
        modelShortestPath->setItem(row, 1, new QStandardItem(QString::number(row+1)));




    }


    for(int row=0; row < shortest_path_list.length(); row++){

        if(shortest_path_list[row].compare(INF)==0){
            modelShortestPath->setItem(row, 2, new QStandardItem("No path"));

        }else{
            modelShortestPath->setItem(row, 2, new QStandardItem(shortest_path_list[row]));
        }


        }
    }
}




void MainWindow::on_pushButton_clicked(){


    QString bodyTxt =  client->sendMessage(std::string("loadGraph"));
    std::cout << bodyTxt.toStdString() << "\n";

    QStringList bodyTxtList = bodyTxt.split("|");
    model->setRowCount(bodyTxtList.length()-2);

    ui->amount_of_nodos->setText(bodyTxtList[0]);
    for(int i=1; i<= bodyTxtList[0].toInt(); i++){
        ui->StartNode_box->addItem(QString::number(i));

    }

    for(int row=1; row < bodyTxtList.length()-1; row++){
        auto current_values = bodyTxtList[row].split(",");
        for(int column=0; column < model->columnCount(); column++){
            model->setItem(row-1, column, new QStandardItem(current_values[column]));

        }

    }





}
