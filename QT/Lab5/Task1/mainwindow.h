#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include "circular_doubly_linked_list.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void prevButton_clicked();

    void nextButton_clicked();

private:
    Ui::MainWindow *ui;
    DoublyLinkedList<QString> list;
    DoublyLinkedList<QString>::Iterator iterator;
    bool open_file_flag;
};
#endif // MAINWINDOW_H
