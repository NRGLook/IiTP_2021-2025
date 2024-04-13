#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>

#include <QTableWidget>

#include <QDialog>
#include <QMessageBox>

#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QTextEdit>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QTextCodec>

#include "Structure.h"

class LaborExchange {

public:

    class Candidat;

    class Vacancy {

    private:
        QString name, work_pos;

        bool education;

        unsigned oklad, vacation_days, min_age, max_age, experience;



    public:
        Vacancy() : name(""), work_pos(""), education(false), oklad(0), vacation_days(0), min_age(0), max_age(0), experience(0)  {}

        Vacancy(QString name_, QString work_pos_, bool education_ = false, unsigned oklad_ = 0,
                unsigned vacation_days_ = 0, unsigned min_age_ = 18, unsigned max_age_ = 65, unsigned experience_ = 0) :
            name(name_), work_pos(work_pos_), education(education_), oklad(oklad_), vacation_days(vacation_days_),
            min_age(min_age_), max_age(max_age_), experience(experience_) {}


        QString Name() {
            return name;
        }

        QString WorkPos() {
            return work_pos;
        }

        QString Education() {
            return (education) ? "Yes" : "No";
        }

        QString Oklad() {
            return QString::number(oklad) + " $";
        }

        QString MinAge() {
            return QString::number(min_age);
        }

        QString MaxAge() {
            return QString::number(max_age);
        }

        QString AgeDiapason() {
            return MinAge() + " - " + MaxAge();
        }

        QString VacationDays() {
            return QString::number(vacation_days);
        }

        QString Exp() {
            return QString::number(experience);
        }

        friend class Candidat;
    };

    class Candidat{

    private:
        QString name, bday, work_pos, job;
        unsigned oklad, exp;
        bool education;


    public:
        Candidat() : name(""), bday("01.01.2000"), work_pos(""), oklad(0), education(false), job(""), exp(0) {}

        Candidat(QString name_, QString bday_, QString work_pos_, unsigned oklad_, bool education_, QString exp_job = "", unsigned exp_ = 0) :
            name(name_), bday(bday_), work_pos(work_pos_), oklad(oklad_), education(education_), job(exp_job), exp(exp_) {}

        QString Name() {
            return name;
        }

        QString Bday() {
            return bday;
        }

        unsigned Age() {

            QString year = bday;

            year.remove(0, 6);

            return (2022 - year.toUInt());
        }


        QString WorkPos() {
            return work_pos;
        }

        QString Education() {
            return (education) ? "Yes" : "No";
        }

        QString Oklad() {
            return QString::number(oklad) + " $";
        }

        bool Suit(Vacancy &vacancy) {

            if (work_pos != vacancy.work_pos || (Age() < vacancy.MinAge().toUInt() || Age() > vacancy.MaxAge().toUInt())) {

                return false;
            }

            return true;

        }


        QString ExpList() {
            return job + ", " + QString::number(exp);
        }

    };
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

private slots:
    void EducVac_0() {
        educ_vac = false;
    }
    void EducVac_1() {
        educ_vac = true;
    }
    void EducCand_0() {
        educ_cand = false;
    }

    void EducCand_1() {
        educ_cand = true;
    }

    void AddVac();
    void AddCand();

    void Find();
    void changeFile();
    void correctData();
    void FindFile() {

        FilePath = QFileDialog::getOpenFileName(this, "Choose your file:",
                                                "D:/C++/QT/two semester/Lab 1/LR-1-4(official)-1/Task4",
                                                "TXT File (*.txt);");
    }

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void SetItem_cand() {
        static unsigned row = 0;

        table_candidats->setRowCount(row + 1);

        QTableWidgetItem *itm_name = new QTableWidgetItem(candidats[row].Name());
        table_candidats->setItem(row, 0, itm_name);

        QTableWidgetItem *itm_bday = new QTableWidgetItem(candidats[row].Bday());
        table_candidats->setItem(row, 1, itm_bday);

        QTableWidgetItem *itm_educ = new QTableWidgetItem(candidats[row].Education());
        table_candidats->setItem(row, 2, itm_educ);

        QTableWidgetItem *itm_pos = new QTableWidgetItem(candidats[row].WorkPos());
        table_candidats->setItem(row, 3, itm_pos);

        QTableWidgetItem *itm_okl = new QTableWidgetItem(candidats[row].Oklad());
        table_candidats->setItem(row, 4, itm_okl);

        QTableWidgetItem *itm_exp = new QTableWidgetItem(candidats[row].ExpList());
        table_candidats->setItem(row, 5, itm_exp);

        ++row;

    }

    void SetItem_vac() {

        static unsigned row = 0;

        table_vacancies->setRowCount(row + 1);

        QTableWidgetItem *itm_name = new QTableWidgetItem(vacancies[row].Name());
        table_vacancies->setItem(row, 0, itm_name);


        QTableWidgetItem *itm_pos = new QTableWidgetItem(vacancies[row].WorkPos());
        table_vacancies->setItem(row, 1, itm_pos);


        QTableWidgetItem *itm_oklad = new QTableWidgetItem(vacancies[row].Oklad());
        table_vacancies->setItem(row, 2, itm_oklad);


        QTableWidgetItem *itm_days = new QTableWidgetItem(vacancies[row].VacationDays());
        table_vacancies->setItem(row, 3, itm_days);


        QTableWidgetItem *itm_educ = new QTableWidgetItem(vacancies[row].Education());
        table_vacancies->setItem(row, 4, itm_educ);


        QTableWidgetItem *itm_age = new QTableWidgetItem(vacancies[row].AgeDiapason());
        table_vacancies->setItem(row, 5, itm_age);


        QTableWidgetItem *itm_exp = new QTableWidgetItem(vacancies[row].Exp());
        table_vacancies->setItem(row, 6, itm_exp);

        ++row;
    }

private:
    QFont font;

    QPushButton *AddVacancy, *AddCandidat, *FindVacancy, *edit, *ChooseFile;

    QLabel *inp_firm_name, *inp_firm_oklad, *inp_min_age, *inp_max_age,
            *inp_vac_days, *inp_exp, *inp_educ, *inp_pos_firm;

    QLabel *inp_name, *inp_exp_list, *inp_bday, *inp_work_pos, *inp_min_oklad,
            *inp_candidat_educ, *inp_pos_explist, *inp_exp_explist, *explist;

    QTableWidget *table_vacancies, *table_candidats, *table_result;
    QDialog *wnd_result;

    QLineEdit *firm_name_LE, *firm_oklad_LE, *min_age_LE, *max_age_LE, *pos_firm_LE,
                *vac_days_LE, *firm_exp_LE;

    QLineEdit *name_LE, *bday_LE, *min_oklad_LE, *pos_explist_LE, *exp_explist_LE, *work_pos_LE;

    QRadioButton *educ_firm_Yes, *educ_firm_No,
                    *educ_candidat_Yes, *educ_candidat_No;

    bool educ_cand = false, educ_vac = false;

    vector<LaborExchange::Vacancy> vacancies;
    vector<LaborExchange::Candidat> candidats;

    QTextEdit *input_here;

    QString FilePath;

    QString read_buffer;

    QDialog *file_wnd;

};
#endif // MAINWINDOW_H
