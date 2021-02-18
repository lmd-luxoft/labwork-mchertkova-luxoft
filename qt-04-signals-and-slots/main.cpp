#include <QCoreApplication>
#include <QDebug>

#include "bank.h"
#include "bankaccount.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Bank bank;
    Logger logger;

QList<BankAccount*> accounts;
accounts<<new BankAccount(&bank)<<new BankAccount(&bank)<<new BankAccount(&bank);
for(auto acc:accounts){
    QObject::connect(
     acc, &BankAccount::balanceChanged,
     &logger, &Logger::logAccountChange
    );
    QObject::connect(
     acc, &BankAccount::fail,
     &logger, &Logger::logFail
    );
}

    accounts[0]->deposit(1000); // you must be notified about account changes
    accounts[2]->deposit(500);  // you must be notified about account changes

    QObject::connect(&bank, &Bank::totalBalanceChanged,
     &logger, &Logger::logTotalBalance);

    accounts[0]->withdraw(100); // you must be notified about account changes and that total balance is changed
    accounts[2]->withdraw(200); // you must be notified about account changes and that total balance is changed
accounts[1]->withdraw(200);

    return a.exec();
}
