#ifndef ATM_H
#define ATM_H

#include <QMainWindow>
#include "bankaccount.h"
QT_BEGIN_NAMESPACE
namespace Ui { class ATM; }
QT_END_NAMESPACE

class ATM : public QMainWindow
{
    Q_OBJECT

public:
    ATM(QWidget *parent = nullptr);
    ~ATM();
    void withdraw();//ADDED!
private:
    Ui::ATM *ui;
    BankAccount b;//ADDED!
};
#endif // ATM_H
