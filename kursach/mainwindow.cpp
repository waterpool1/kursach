#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   model=new
   QStandardItemModel(1,3,this);
ui->tableView->setModel(model);
model->setHeaderData(0,Qt::Horizontal,"Вес(кг)");
model->setHeaderData(1,Qt::Horizontal,"Рост(см)");
model->setHeaderData(2,Qt::Horizontal,"ППТ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
for(int i=0;i<model->rowCount();i++){
    qDebug()<<"i="<<i;
    index=model->index(i,0);
    int a=index.data().toInt();
    qDebug()<<"a="<<a;
    index=model->index(i,1);
    int b=index.data().toInt();
    qDebug()<<"b="<<b;
    double c=0.007241*a*b;
    index=model->index(i,2);
    qDebug()<<"c="<<c;
    model->setData(index,c);
    qDebug()<<"ЧереПашка";
}
}

void MainWindow::on_pushButton_2_clicked()
{
 model->removeRow(row);
}


void MainWindow::on_pushButton_3_clicked()
{
  model->insertRow(model->rowCount()) ;
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    row = index.row();
}

