#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QString"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "QTreeWidgetItem"
#include "QStringList"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load_data_from_sql();
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load_data_from_sql(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("database");
    db.setUserName("root");
    db.setPassword("123546");
    db.open();
    QSqlQuery query;
    query.exec("select * from qtzl");
    while(query.next())
    {
        QString title = query.value(1).toString();
        QString url =  query.value(2).toString();
        QTreeWidgetItem* item = new QTreeWidgetItem(QStringList()<<title<<url);
        ui->treeWidget->addTopLevelItem(item);
    }
    db.close();
}


void MainWindow::on_btn_search_clicked()
{

}
