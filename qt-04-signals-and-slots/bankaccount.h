#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>
#include "bank.h"

class BankAccount : public QObject
{
    Q_OBJECT
public:
    explicit BankAccount(Bank *parentBank);

    void deposit(long amount);
    void withdraw(long amount);

    long balance() const;

private:
    long m_balance;
    void setBalance(long newBalance);

signals:
    void balanceChanged(long newBalance);
    void fail(QString reason);
public slots:
};

#endif // BANKACCOUNT_H
