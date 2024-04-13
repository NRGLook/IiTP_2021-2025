#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //defence
    ui->setupUi(this);
    t = new MyDeque<int>(4);

    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->lineEdit->setValidator(new QIntValidator(1, 100, this));
    ui->lineEdit_2->setValidator(new QIntValidator(1, 100, this));
    ui->lineEdit_3->setValidator(new QIntValidator(1, 10000, this));
    ui->lineEdit_4->setValidator(new QIntValidator(1, 10000, this));
    ui->lineEdit->setText("4");
    listBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::listBox()
{
    ui->listWidget->clear();
    ui->end->clear();
    ui->begin->clear();
    ui->pluss->clear();
    ui->pluss_2->clear();
    ui->pluss_3->clear();
    ui->pluss_4->clear();

    ui->op->clear();
    ui->op_2->clear();
    ui->op_3->clear();
    ui->op_4->clear();
    if(!t->empty()){
    for(int a=1; a<=t->size();a++){
        ui->listWidget->addItem(QString::number(t->at(a)));
    }
    std::ostringstream oss,ass; //string output stream supports output to strings in memory
    oss<< &t->begin();
    ui->begin->setText(QString::fromStdString(oss.str()));
    ass<< &t->end();
    ui->end->setText(QString::fromStdString(ass.str()));
    ui->pluss->setText(QString::number(*t->begins()+*t->end()));
    ui->pluss_2->setText(QString::number(*t->begins()-*t->end()));
    ui->pluss_3->setText(QString::number(double(*t->begins())*double(*t->end())));
    ui->pluss_4->setText(QString::number(double(*t->begins())/double(*t->end())));

    ui->op->setText(QString::number(*t->begins()>*t->end()));
    ui->op_2->setText(QString::number(*t->begins()<*t->end()));
    ui->op_3->setText(QString::number(*t->begins()>=*t->end()));
    ui->op_4->setText(QString::number(*t->begins()<=*t->end()));
    }
    ui->textBrowser->setText(QString::number(t->empty()));
    ui->textBrowser_2->setText(QString::number(t->size()));

}

//push-front
void MainWindow::on_pushButton_3_clicked()
{
    t->push_front(qrand());//random fulling
    listBox();
}

//pop-front
void MainWindow::on_pushButton_4_clicked()
{
    if(!t->empty()) t->pop_front();
    listBox();
}

//push-back
void MainWindow::on_pushButton_clicked()
{
    t->push_back(qrand());
    listBox();
}

//pop-back
void MainWindow::on_pushButton_2_clicked()
{
    if(!t->empty()) t->pop_back();
    listBox();
}

//clear
void MainWindow::on_pushButton_5_clicked()
{
    t->clear();
    listBox();
}


//resize
void MainWindow::on_pushButton_6_clicked()
{
    if(ui->lineEdit->text().toInt()>0) t->resize(ui->lineEdit->text().toInt());
    listBox();
}

//at
void MainWindow::on_pushButton_7_clicked()
{
if(ui->lineEdit_2->text().toInt()>0 && ui->lineEdit_2->text().toInt()<=t->size()){
    ui->textBrowser_3->setText(QString::number(t->at(ui->lineEdit_2->text().toInt())));
}
else ui->textBrowser_3->setText("error");
}

//insert
void MainWindow::on_pushButton_8_clicked()
{
    if(ui->lineEdit_3->text().toInt()>0 && ui->lineEdit_3->text().toInt() <= t->size()+1)
        t->insert(ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt());
    listBox();
}

