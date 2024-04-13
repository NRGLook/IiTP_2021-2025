#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <tree.h>
#include <QMessageBox>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
    void print(const TreeNode* root);
    int rows = 1;
    void preorderPrint(TreeNode *root);//симметричный
    void postorderPrint(TreeNode *root);//прямой обход
    void inorderPrint(TreeNode *root);//в обратном порядке

private:
    Ui::Form *ui;
    Tree tree;
    std::pair<int, QString> arr[5] {{12, "ab"}, {34, "cd"}, {56, "ef"}, {78, "hi"}, {90, "gk"}};

public slots:
    void slot();
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

#endif // FORM_H
