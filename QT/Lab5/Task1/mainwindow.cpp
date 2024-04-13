#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(prevButton_clicked()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextButton_clicked()));

    QFile file("D:/C++/QT/two semester/Lab 5/Task1/paths_images.txt");
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            while (!stream.atEnd())
            {
                list.push(stream.readLine());
            }
            open_file_flag = true;
            iterator = list.begin();
        }
        else
        {
            QMessageBox::warning(this, "Error", "File not opened.");
            open_file_flag = false;
        }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::prevButton_clicked()
{
    if (open_file_flag)
    {
        --iterator;
        QString line = *iterator;
        QPixmap pm(line); // path to image file
        ui->picture->setPixmap(pm);
        ui->picture->setScaledContents(true);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Incorrect action");
    }
}

void MainWindow::nextButton_clicked()
{
    if (open_file_flag)
    {
        ++iterator;
        QString line = *iterator;
        QPixmap pm(line); // path to image file
        ui->picture->setPixmap(pm);
        ui->picture->setScaledContents(true);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Incorrect action");
    }
}
