#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.cpp"
#include <QStandardItemModel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);


    Client* client = new Client();
    client->createSocket();




    std::string message = "hola mundo";
    std::string me = client->sendMessage(message);

    QString bodyTxt = QString::fromStdString(me);
    std::cout << bodyTxt.toStdString() << "\n";

    QStringList bodyTxtList = bodyTxt.split("|");


    ui->amount_of_nodos->setText(bodyTxtList[0]);
    QHeaderView* header = new QHeaderView(Qt::Orientation::Horizontal,ui->tableView);
    ui->tableView->setHorizontalHeader(header);



    QStandardItemModel* model = new QStandardItemModel(this);
    model->setColumnCount(2);
    model->setRowCount(bodyTxtList.length()-2);

    for(int i=0; i<bodyTxtList.length()-1; i++){
        std::cout << bodyTxtList[i].toStdString() << "\n";
    }
    ui->tableView->setModel(model);

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
    ui->tableView->showRow(5);

}
















