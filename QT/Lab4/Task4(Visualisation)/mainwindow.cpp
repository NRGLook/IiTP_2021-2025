#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("^[a-z]{30}")));
    ui->lineEdit_2->setValidator(new QRegExpValidator(QRegExp("^[a-z]{30}")));
    ui->lineEdit_4->setValidator(new QRegExpValidator(QRegExp("^[0-9].{1}$")));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    char* c=new char[ui->lineEdit->text().size()+1];
        for(int a=0;a<ui->lineEdit->text().size();a++){
            c[a]=ui->lineEdit->text().at(a).toLatin1();
        }
        c[ui->lineEdit->text().size()] = '\0';
        str.setText(c);
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_2_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_strcpy(str.getText(),c);
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_3_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_strncpy(str.getText(),c,ui->lineEdit_4->text().toUInt());
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_5_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_strcat(str.getText(),c);
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_4_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_strncat(str.getText(),c,ui->lineEdit_4->text().toUInt());
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_6_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        ui->textBrowser_2->setText(QString::number(str.my_strcmp(str.getText(),c)));
        delete[] c;
}


void MainWindow::on_pushButton_7_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        ui->textBrowser_2->setText(QString::number(str.my_strncmp(str.getText(),c,ui->lineEdit_4->text().toUInt())));
        delete[] c;

}


void MainWindow::on_pushButton_8_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        ui->textBrowser_2->setText(QString::number(str.my_strcoll(str.getText(),c)));
        delete[] c;
}

void MainWindow::on_pushButton_9_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        ui->textBrowser_2->setText(QString::number(str.my_strxfrm(str.getText(),c,ui->lineEdit_4->text().toUInt())));
        ui->textBrowser->setText(str.getText());
        delete[] c;
}

void MainWindow::on_pushButton_10_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_strtok(str.getText(),c[0]);
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_11_clicked()
{
        ui->textBrowser_2->setText(str.my_strerror(ui->lineEdit_4->text().toInt()));
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->textBrowser_2->setText(QString::number(str.my_strlen(str.getText())));
}


void MainWindow::on_pushButton_13_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_memset(str.getText(),c[0],ui->lineEdit_4->text().toInt());
        ui->textBrowser->setText(str.getText());
        delete[] c;
}


void MainWindow::on_pushButton_14_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        ui->textBrowser_2->setText(QString::number(str.my_memcmp(str.getText(),c,ui->lineEdit_4->text().toUInt())));
        delete[] c;
}


void MainWindow::on_pushButton_15_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_memmove(str.getText(),c,ui->lineEdit_4->text().toUInt());
        ui->textBrowser->setText(str.getText());
        delete[] c;

}


void MainWindow::on_pushButton_16_clicked()
{
    char* c=new char[ui->lineEdit_2->text().size()+1];
        for(int a=0;a<ui->lineEdit_2->text().size();a++){
            c[a]=ui->lineEdit_2->text().at(a).toLatin1();
        }
        c[ui->lineEdit_2->text().size()] = '\0';
        str.my_memcpy(str.getText(),c,ui->lineEdit_4->text().toUInt());
        ui->textBrowser->setText(str.getText());
        delete[] c;

}
