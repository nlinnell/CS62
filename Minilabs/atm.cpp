#include "atm.h"
#include "ui_atm.h"

ATM::ATM(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ATM)
{
    ui->setupUi(this);

    b=BankAccount(199181, 75, 198278722, "Shweta Agarwal");
    ui->balanceBox->setValue(b.get_balance());
    connect(ui->withdrawButton, &QPushButton::clicked, this, &ATM::withdraw);
}
//Where can you imagine doing stuff with our BankAccount field?
ATM::~ATM()
{
    delete ui;
}

void ATM::withdraw(){
    int amount = ui->transactionBox->value();
    b.withdraw(amount);
    ui->balanceBox->setValue(b.get_balance());
}
















/*constructor
    ui->balanceBox->setVisible(false);
    ui->transactionBox->setVisible(false);
    ui->depositButton->setVisible(false);
    ui->withdrawButton->setVisible(false);
    */

/*initialize
    ui->balanceBox->setVisible(true);
    ui->transactionBox->setVisible(true);
    ui->depositButton->setVisible(true);
    ui->withdrawButton->setVisible(true);
    ui->initialBalanceSpinBox->setVisible(false);
    ui->initialButton->setVisible(false);
    */
