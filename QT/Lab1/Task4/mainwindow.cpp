#include "mainwindow.h"

void MainWindow::AddVac()
{
    QString name = firm_name_LE->text(),
            oklad = firm_oklad_LE->text(),
            min_age = min_age_LE->text(),
            max_age = max_age_LE->text(),
            pos_firm = pos_firm_LE->text(),
            vacation_days = vac_days_LE->text(),
            exp = firm_exp_LE->text();

    if (vacation_days.isEmpty() || oklad.isEmpty() || name.isEmpty() ||
            min_age.isEmpty() || max_age.isEmpty() || pos_firm.isEmpty() || exp.isEmpty())
        QMessageBox::critical(this, "", "Enter all parameters:");

    else {

        QRegularExpression reg("^\\d+\\d?\\d?$");

        QRegularExpressionMatch match_oklad = reg.match(oklad),
                match_min_age = reg.match(min_age),
                match_max_age = reg.match(max_age),
                match_vacation_days = reg.match(vacation_days),
                match_exp = reg.match(exp);

        if (!match_oklad.hasMatch() || !match_min_age.hasMatch() ||
                !match_max_age.hasMatch() || !match_vacation_days.hasMatch() ||
                !match_exp.hasMatch())
            QMessageBox::critical(this, "", "Enter correct data:");
        else {
            vacancies.push_back(LaborExchange::Vacancy(name, pos_firm, educ_vac, oklad.toUInt(),
               vacation_days.toUInt(), min_age.toUInt(), max_age.toUInt(), exp.toUInt()));

            statusBar()->showMessage("Vacantion: " + vacancies[vacancies.Size() - 1].Name() + " add!");

            SetItem_vac();
        }
    }
}

void MainWindow::AddCand()
{
    QString name = name_LE->text(),
            oklad = min_oklad_LE->text(),
            bday = bday_LE->text(),
            work_pos = work_pos_LE->text(),
            work = pos_explist_LE->text(),
            exp = exp_explist_LE->text();

    if (name.isEmpty() || oklad.isEmpty() || bday.isEmpty() ||
            work_pos.isEmpty() || (exp.isEmpty() && !work.isEmpty()) ||
            (work.isEmpty() && !exp.isEmpty()))
        QMessageBox::critical(this, "", "Enter all parameters:");

    else {

        QRegularExpression reg("^\\d+\\d?\\d?$"), bdayreg("[0-9]{2}\\.[0-9]{2}\\.[0-9]{4}$");

        QRegularExpressionMatch match = reg.match(exp);

        QRegularExpressionMatch match_oklad = reg.match(oklad);
        QRegularExpressionMatch match_bday = bdayreg.match(bday);

        if (!match_oklad.hasMatch() || !match_bday.hasMatch() || (!exp.isEmpty() && !match.hasMatch()))
            QMessageBox::critical(this, "", "Enter correct data:");

        else {

            candidats.push_back(LaborExchange::Candidat(name, bday, work_pos, oklad.toUInt(), educ_cand, work, exp.toUInt()));
            statusBar()->showMessage("Canditat " + candidats[candidats.Size() - 1].Name() + " add!");

            SetItem_cand();
        }
    }
}

void MainWindow::Find()
{
    wnd_result = new QDialog(this);
    wnd_result->resize(700, 400);

    table_result = new QTableWidget(wnd_result);
    table_result->resize(700, 400);

    table_result->setColumnCount(2);
    table_result->setHorizontalHeaderLabels({"Firm", "Candidat"});

    unsigned Rows = 0;

     table_result->setRowCount(vacancies.Size());

    for (Rows = 0; Rows < vacancies.Size(); ++Rows) {
        QTableWidgetItem *item_name = new QTableWidgetItem(vacancies[Rows].Name());
        table_result->setItem(Rows, 0, item_name);
    }

    for (unsigned i = 0; i < vacancies.Size(); ++i)
        for (unsigned j = 0; j < candidats.Size(); ++j) {

            if (candidats[j].Suit(vacancies[i])) {

                QTableWidgetItem *item_name = new QTableWidgetItem(candidats[j].Name());
                table_result->setItem(i, 1, item_name);
            }
        }

    wnd_result->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{

    resize(1000, 900);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(255,153,51));
    //230,255,199 - желтый

    setAutoFillBackground(true);

    setPalette(pal);

    font.setPixelSize(16);

    inp_firm_name = new QLabel(this);
    inp_firm_name->setFont(font);
    inp_firm_name->setText("Company name:"); inp_firm_name->adjustSize();
    inp_firm_name->move(50, 50);

    inp_pos_firm = new QLabel(this);
    inp_pos_firm->setFont(font);
    inp_pos_firm->setText("Required position:"); inp_pos_firm->adjustSize();
    inp_pos_firm->move(50, 150);

    inp_firm_oklad = new QLabel(this);
    inp_firm_oklad->setFont(font);
    inp_firm_oklad->setText("Minimum salary:"); inp_firm_oklad->adjustSize();
    inp_firm_oklad->move(50, 250);

    inp_min_age = new QLabel(this);
    inp_min_age->setFont(font);
    inp_min_age->setText("Minimum age:"); inp_min_age->adjustSize();
    inp_min_age->move(50, 350);

    inp_max_age = new QLabel(this);
    inp_max_age->setFont(font);
    inp_max_age->setText("Max age:"); inp_max_age->adjustSize();
    inp_max_age->move(50, 450);

    inp_exp = new QLabel(this);
    inp_exp->setFont(font);
    inp_exp->setText("Required experience:"); inp_exp->adjustSize();
    inp_exp->move(50, 550);

    inp_vac_days = new QLabel(this);
    inp_vac_days->setFont(font);
    inp_vac_days->setText("Vacation days:"); inp_vac_days->adjustSize();
    inp_vac_days->move(50, 650);

    inp_educ = new QLabel(this);
    inp_educ->setFont(font);
    inp_educ->setText("Higher education:"); inp_educ->adjustSize();
    inp_educ->move(50, 750);

    educ_firm_Yes = new QRadioButton("Yes", this);
    educ_firm_Yes->setFont(font);
    educ_firm_Yes->adjustSize();
    educ_firm_Yes->move(50, 800);


    educ_firm_No = new QRadioButton("No", this);
    educ_firm_No->setFont(font);
    educ_firm_No->adjustSize();
    educ_firm_No->move(150, 800);

    firm_name_LE = new QLineEdit(this);
    firm_name_LE->resize(70, 30);
    firm_name_LE->move(250, 50);

    pos_firm_LE = new QLineEdit(this);
    pos_firm_LE->resize(70, 30);
    pos_firm_LE->move(250, 150);

    firm_oklad_LE = new QLineEdit(this);
    firm_oklad_LE->resize(70, 30);
    firm_oklad_LE->move(250, 250);

    min_age_LE = new QLineEdit(this);
    min_age_LE->resize(70, 30);
    min_age_LE->move(250, 350);

    max_age_LE = new QLineEdit(this);
    max_age_LE->resize(70, 30);
    max_age_LE->move(250, 450);

    firm_exp_LE = new QLineEdit(this);
    firm_exp_LE->resize(70, 30);
    firm_exp_LE->move(250, 550);

    vac_days_LE = new QLineEdit(this);
    vac_days_LE->resize(70, 30);
    vac_days_LE->move(250, 650);

    unsigned default_x = 400;

    inp_name = new QLabel(this);
    inp_name->setFont(font);
    inp_name->setText("The name of candidat:"); inp_name->adjustSize();
    inp_name->move(default_x, 50);

    inp_bday = new QLabel(this);
    inp_bday->setFont(font);
    inp_bday->setText("Data birthday:"); inp_bday->adjustSize();
    inp_bday->move(default_x, 150);

    inp_work_pos = new QLabel(this);
    inp_work_pos->setFont(font);
    inp_work_pos->setText("Desired position:"); inp_work_pos->adjustSize();
    inp_work_pos->move(default_x, 250);

    inp_min_oklad = new QLabel(this);
    inp_min_oklad->setFont(font);
    inp_min_oklad->setText("Desired salary:"); inp_min_oklad->adjustSize();
    inp_min_oklad->move(default_x, 350);

    inp_candidat_educ = new QLabel(this);
    inp_candidat_educ->setFont(font);
    inp_candidat_educ->setText("Higher education:"); inp_candidat_educ->adjustSize();
    inp_candidat_educ->move(default_x, 450);

    educ_candidat_Yes = new QRadioButton("Yes", this);
    educ_candidat_Yes->setFont(font);
    educ_candidat_Yes->adjustSize();
    educ_candidat_Yes->move(default_x, 500);

    educ_candidat_No = new QRadioButton("No", this);
    educ_candidat_No->setFont(font);
    educ_candidat_No->adjustSize();
    educ_candidat_No->move(default_x + 150, 500);

    explist = new QLabel(this);
    explist->setFont(font);
    explist->setText("List of positions previously held:"); explist->adjustSize();
    explist->move(default_x - 50, 550);

    inp_pos_explist = new QLabel(this);
    inp_pos_explist->setFont(font);
    inp_pos_explist->setText("Position:"); inp_pos_explist->adjustSize();
    inp_pos_explist->move(default_x, 600);

    inp_exp_explist = new QLabel(this);
    inp_exp_explist->setFont(font);
    inp_exp_explist->setText("Experience:"); inp_exp_explist->adjustSize();
    inp_exp_explist->move(default_x, 700);

    name_LE = new QLineEdit(this);
    name_LE->resize(70, 30);
    name_LE->move(default_x + 200, 50);

    bday_LE = new QLineEdit(this);
    bday_LE->resize(70, 30);
    bday_LE->move(default_x + 200, 150);

    work_pos_LE = new QLineEdit(this);
    work_pos_LE->resize(70, 30);
    work_pos_LE->move(default_x + 200, 250);

    min_oklad_LE = new QLineEdit(this);
    min_oklad_LE->resize(70, 30);
    min_oklad_LE->move(default_x + 200, 350);

    pos_explist_LE = new QLineEdit(this);
    pos_explist_LE->resize(70, 30);
    pos_explist_LE->move(default_x + 200, 600);

    exp_explist_LE = new QLineEdit(this);
    exp_explist_LE->resize(70, 30);
    exp_explist_LE->move(default_x + 200, 700);

    AddCandidat = new QPushButton("Add a candidate:", this);
    AddCandidat->setFont(font); AddCandidat->adjustSize();
    AddCandidat->move(default_x, 900);

    AddVacancy = new QPushButton("Post a vacancy:", this);
    AddVacancy->setFont(font); AddVacancy->adjustSize();
    AddVacancy->move(50, 900);

    table_vacancies = new QTableWidget(this);
    table_vacancies->resize(1200, 400);

    table_vacancies->setColumnCount(7);
    table_vacancies->setHorizontalHeaderLabels({"Name:", "Post:", "Salary:",
             "Number of vacation days:", "Higher education:", "Age:", "Min.experience:"});

    for (unsigned i = 0; i < 5; ++i)
        table_vacancies->setColumnWidth(i, 1300/7);

    for (unsigned i = 5; i < 7; ++i)
        table_vacancies->setColumnWidth(i, 130);

    table_vacancies->move(730, 0);

    table_candidats = new QTableWidget(this);
    table_candidats->resize(1200, 400);

    table_candidats->setColumnCount(6);
    table_candidats->setHorizontalHeaderLabels({"Name:", "Data birthday:", "Higher education:",
             "Desired position:", "Desired salary:", "Experience:"});

    for (unsigned i = 0; i < 6; ++i)
        table_candidats->setColumnWidth(i, 1300/7);

    table_candidats->move(730, 450);

    FindVacancy = new QPushButton(this);
    FindVacancy->setFont(font);
    FindVacancy->setText("Find vacancies:");
    FindVacancy->resize(350, 100);
    FindVacancy->move(1100, 880);

    connect(educ_firm_Yes, SIGNAL(clicked()), this, SLOT(EducVac_1()));
    connect(educ_firm_No, SIGNAL(clicked()), this, SLOT(EducVac_0()));
    connect(educ_candidat_Yes, SIGNAL(clicked()), this, SLOT(EducCand_1()));
    connect(educ_candidat_No, SIGNAL(clicked()), this, SLOT(EducCand_0()));

    connect(AddVacancy, SIGNAL(clicked()), this, SLOT(AddVac()));
    connect(AddCandidat, SIGNAL(clicked()), this, SLOT(AddCand()));
    connect(FindVacancy, SIGNAL(clicked()), this, SLOT(Find()));

    ChooseFile = new QPushButton("File:", this);
    ChooseFile->move(1600, 880);

    connect(ChooseFile, SIGNAL(clicked()), this, SLOT(FindFile()));

    edit = new QPushButton("Edit file:", this);
    edit->adjustSize();
    edit->move(1700, 880);
    connect(edit, SIGNAL(clicked()), this, SLOT(correctData()));

}

MainWindow::~MainWindow()
{
}


void MainWindow::correctData()
{
    if (FilePath.isEmpty())
        QMessageBox::critical(this, "Mistake:", "You should choose your file:");
    else {
        file_wnd = new QDialog();
        file_wnd->setModal(true);

        file_wnd->resize(1000, 600);

        QFile file(FilePath);

        file.open(QFile::ReadOnly);

        QTextCodec *defaultTextCodec = QTextCodec::codecForName("Windows-1251");
        QTextDecoder *decoder = new QTextDecoder(defaultTextCodec);

        read_buffer = decoder->toUnicode(file.readAll());

        file.flush();

        file.close();

        QFont font; font.setPointSize(14);

        QPushButton *edit = new QPushButton(file_wnd);

        edit->setFont(font);
        edit->setText("Сохранить"); edit->adjustSize();
        edit->move(430, 500);

        QTextEdit *old_data = new QTextEdit(file_wnd);
        old_data->setFont(font);
        old_data->resize(500, 380);
        old_data->setReadOnly(true);

        QPalette *palette = new QPalette();
        palette->setColor(QPalette::Base,QColor(255,254,164));
        old_data->setPalette(*palette);

        old_data->setPlaceholderText(read_buffer);

        input_here = new QTextEdit(file_wnd);
        input_here->setFont(font);
        input_here->resize(500, 380);
        input_here->move(500, 0);

        connect(edit, SIGNAL(clicked()), this, SLOT(changeFile()));

        file_wnd->show();
    }
}

void MainWindow::changeFile()
{
    QFile file(FilePath);

    QString new_buffer = input_here->toPlainText();

    file.open(QFile::WriteOnly);

    qint64 new_size = new_buffer.length();

    file.resize(new_size);

    file.seek(0);

    QString empty_buffer;
    empty_buffer.resize(read_buffer.size());

    for (unsigned i = 0; i < empty_buffer.size(); ++i)
        empty_buffer[i] = ' ';

    QByteArray ba1 = new_buffer.toLocal8Bit();
    const char *empty_buf = ba1.data();

    file.write(empty_buf);

    file.seek(0);

    QByteArray ba = new_buffer.toLocal8Bit();
    const char *new_buf = ba.data();

    file.write(new_buf);

    file.close();

    file_wnd->close();

}
