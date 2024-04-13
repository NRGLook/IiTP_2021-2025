#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QStandardItemModel>
#include <sstream>
#include<iostream>

#include"myvector.h"
using namespace std;

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
    void on_pushBack_clicked();

    void on_popBack_clicked();

    void on_clear_clicked();

    void on_insert_clicked();

    void on_erase_clicked();

    void on_assign_clicked();

    void on_emplace_clicked();

    void on_emplaceBack_clicked();

    void on_sizeLine_editingFinished();

    void on_capacityLine_editingFinished();

  //  void on_getAnswer_clicked();
    void updateMyVectorTable();
    MyVector<int> AddNum(const MyVector<int>& a, const MyVector<int>& b, int k);
    void AddZero(MyVector<int>& c, int x);
    void GenerateSequence();
private:
    Ui::MainWindow *ui;
    MyVector<int> vec;
    void Normalize(MyVector<int>& c);
    int GetBit(const MyVector<int>& v, int b);
    MyVector<int> Multiply(const MyVector<int>& a, int x, int k);
    void GenerateSequence(MyVector<int> n, const MyVector<MyVector<int>>& p, int k, int i, MyVector<std::pair<int, MyVector<int>> >& v);
};

#endif // MAINWINDOW_H
