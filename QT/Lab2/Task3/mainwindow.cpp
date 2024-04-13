#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //ограничиваем пользовательский ввод
    ui->setupUi(this);
    model = new QStandardItemModel(26,2,this);
    ui->tableView->setModel(model);
    model->setHeaderData(0,Qt::Horizontal, "Переменная:");
    model->setHeaderData(1,Qt::Horizontal, "Значение:");
    ui->Edit1->setValidator(new QRegExpValidator(QRegExp("^[a-z*+/^()-]{255}$")));
    ui->tableView->setEditTriggers(0);
    ui->change->setValidator(new QRegExpValidator(QRegExp("^[0-9].{3}$")));
    ui->Edit1->setMaxLength(255);

    FormCreate();

        QFile text("D:/C++/QT/two semester/Lab 2/Task3/info.txt");
        text.open(QIODevice::ReadOnly);
        while (!text.atEnd()){
            inf.push_back(in);
            in.a[0]=text.readLine();
            in.a[1]=text.readLine();
            in.a[2]=text.readLine();
            in.a[3]=text.readLine();
            in.a[4]=text.readLine();
            in.a[5]=text.readLine();
            for(int a=0;a<6;a++){
                in.a[a].remove(in.a[a].size()-2,2);
            }
            text.readLine();
        }
        text.close();

        for(int a=0;a<inf.size();a++){
            ui->comboBox->addItem(inf[a].a[0]);
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}


Stack* MainWindow::InStack(Stack *p, char in) { //вход в стек
    Stack *t = new Stack;
    t->info = in;
    t->next = p;
    return t;
}

Stack * MainWindow::OutStack ( Stack * p ,  char * out )  { //выход из стека
    Stack * t =  p ;
    if (p==0x0) cheak=1;
    else{
    *out = p->info ;
    p = p->next ;
    }
    delete t ;
    return p ;
}


void MainWindow::FormCreate()
{
char a = 'a';
QModelIndex index;
for(int i = 0; i<26; i++) {
    index = model->index(i,0);
    model->setData(index,QString(a++));
    index = model->index(i,1);
    model->setData(index,QString::number(i+1));
}
}


void MainWindow::on_perev_clicked()
{
    ben =  NULL ;
    char ss, a;
    QString InStr ,  OutStr ;
    OutStr = "";
    ui->Edit2->clear();
    InStr = ui->Edit1->text();
    int len = InStr.length(), k;
    for (k = 0; k < len; k++) {
        ss =  InStr[k].toLatin1();
        if (ss == '(')
            ben =  InStack(ben,ss);
        if (  ss == ')' ) {
            while ( (ben->info) != '(' ) {

                ben =  OutStack(ben, &a);
                OutStr +=  a ;
            }
            ben = OutStack(ben, &a);
        }
        if (ss >=  'a' && ss <= 'z' )
            OutStr += ss;
        if (ss=='-' || ss=='+' || ss=='*' || ss=='/' || ss=='^') {
            while ( ben != NULL && Prior (ben->info) >= Prior (ss) ) {
                ben = OutStack(ben, &a);
                OutStr += a;
            }
            ben =  InStack ( ben ,  ss );
        }
    }
    while ( ben != NULL){
        ben = OutStack(ben, &a);
        OutStr +=  a ;
    }
    ui->Edit2->setText(OutStr);
}


void MainWindow::on_solve_clicked()
{
    if(ui->Edit2->toPlainText()=="") {
        ui->Edit3->setText("Данные не были введены:");
    }
    else{
    char ch ;
    QString OutStr = ui->Edit1->text(),buf;
    for(int a=0;a<OutStr.length()-1;a++){
        if((OutStr[a]>='a' && OutStr[a]<='z') && (OutStr[a+1]>='a' && OutStr[a+1]<='z')){
              ui->Edit3->setText("Выражение введено не верно:");
              return;
}
    }
    OutStr = ui->Edit2->toPlainText();
    for (int i=0; i<26; i++) {
        QModelIndex ind=model->index(i,0);
        buf=ind.data().toString();
        ch = buf[0].toLatin1();
        ind=model->index(i,1);
        mas[int(ch)]=ind.data().toFloat();
    }
    double rez=Rezult(OutStr);
    qDebug() << 213;
    /*
    if(rez<1e-300) ui->Edit3->setText("Неверное выражение");
        else
    */
    ui->Edit3->setText(QString::number(rez));
    }
}


int MainWindow::Prior (char a)
{
    switch ( a ) {
    case '^':  return 4;
    case '*': case '/':  return 3;
    case '-': case '+':  return 2;
    case '(':  return 1;
    }
    return 0;
}



double MainWindow::Rezult ( QString Str )
{
    char ch, ch1, ch2;
    double op1, op2, rez;
    char chr = 'z'+1;
    for (int i=0; i < Str.length(); i++){
        ch=Str[i].toLatin1();
            if (ch!='-' && ch!='*' && ch!='/' && ch!='+' && ch!='^'){
             ben = InStack(ben, ch);
        }
        else {
            ben = OutStack(ben,&ch1);
            ben = OutStack(ben,&ch2);
            if(cheak){
                cheak=0;
                return 0;
            }
            QModelIndex ind;
            op1 = mas[int (ch1)];
            op2 = mas[int (ch2)];
            for(int a='a';a<='z';a++){
                if(a==int(ch1)){
                    ind=model->index(a-'a',1);
                    op1=ind.data().toDouble();
                    break;
            }
            }
                for(int a='a';a<='z';a++){
                    if(a==int(ch2)){
                        ind=model->index(a-'a',1);
                        op2=ind.data().toDouble();
                        break;
                }
                }
            switch (ch){
            case '+' :  rez=op2+op1;
                break;
            case '-' :  rez=op2 - op1;
                break;
            case '*' :  rez=op2*op1;
                break;
            case '/' :  rez=op2/op1;
                break;
            case '^' :  rez=pow(op2,op1);
                break;
            }
            mas[int (chr)] = rez;
            ben = InStack(ben,chr);
            chr ++;
            }
    }

    return rez ;
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    if(index.column()==0)
    ui->word->setText(index.data().toString());
}


void MainWindow::on_pushButton_clicked()
{
    int buf = int(ui->word->toPlainText()[0].toLatin1())-'a';
    QModelIndex index;
    index = model->index(buf,1);
    if(ui->change->text()=="e") model->setData(index,"1");
    else model->setData(index,ui->change->text());
}

void MainWindow::on_comboBox_activated(int index)
{

    QModelIndex indexx;
    indexx = model->index(0,1);
    ui->Edit1->setText(inf[index].a[0]);
    for(int s=1; s<6;s++){
        indexx = model->index(s-1,1);
        model->setData(indexx,inf[index].a[s]);
    }

}

