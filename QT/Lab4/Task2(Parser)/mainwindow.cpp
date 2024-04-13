#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    setAutoFillBackground(true);

    QPalette pal;
    pal.setBrush(QPalette::Background, QColor(128, 0, 0));
    setPalette(pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_input_2_clicked()
{
    QString code = ui->textEdit->toPlainText();

     if (code.isEmpty())
         return;

     std::string _code = code.toStdString();

     parser prs(_code.c_str());

     prs.parse();

     ui->textEdit_2->setText(prs.get_info());

}


void MainWindow::on_file_2_clicked()
{
    path = QFileDialog::getOpenFileName(this, "", "D:/C++/BsuirOpen/TaskC", "CPP files (*.cpp);");

     if (path.isEmpty())
         return;

     QFile f(path);

     f.open(QFile::ReadOnly);

     QString buf = f.readAll();

     path = "";

     f.close();

     std::string input = buf.toStdString();

     parser prs(input.c_str());

     prs.parse();

     ui->textEdit->setText(buf);

     ui->textEdit_2->setText(prs.get_info());

}

