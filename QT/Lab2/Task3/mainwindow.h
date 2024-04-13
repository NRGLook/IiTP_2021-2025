#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QDate>
#include <QItemDelegate>
#include <QFile>
#include <QDebug>
#include <QTextStream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

struct info{
    QString a[6];
};


struct Stack {
    char info;
    Stack * next;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_perev_clicked();

    void on_solve_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
bool cheak=0;
    Stack* ben=new Stack;
    void FormCreate();
    int Prior (char);
    Stack* InStack( Stack*,char);
    Stack* OutStack( Stack*,char*);
    double Rezult(QString);
    double mas [201];
    QStandardItemModel *model;
    QVector<info> inf;
    info in;
};
#endif // MAINWINDOW_H
