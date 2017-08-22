#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfiledialog.h"
#include "QStringListModel"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}




MainWindow::~MainWindow()
{
    delete ui;
}

//打开文件
void MainWindow::on_btn_open_file_clicked()
{
    QStringList file_names = QFileDialog::getOpenFileNames(this,tr("打开文件"),"C:/Users/admin/Desktop");
    QString temp;
    QStringList list;
    for(int i = 0;i<file_names.length();i++){
        list.append(file_names[i]);
    }
    QStringListModel *model = new QStringListModel(list);

    ui->listView->setModel(model);

}

void MainWindow::on_btn_save_file_clicked()
{
    m_time_id = startTimer(1000);
}

void MainWindow::timerEvent(QTimerEvent *event){
    if(event->timerId()==m_time_id){
        QTime now = QTime::currentTime();
        QString text = now.toString("HH:mm:ss");
    }
}
