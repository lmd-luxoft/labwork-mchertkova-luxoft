#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QObject>

class BankAccount : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString holderName READ holderName WRITE setHolderName);
    Q_PROPERTY(
    qint64 balance MEMBER m_balance READ balance CONSTANT
    )

public:
    explicit BankAccount(QObject *parent = 0);

    void deposit(long amount);
    void withdraw(long amount);

    QString holderName() const
    {
        return m_holderName;
    }

    qint64 balance() const
    {
        return m_balance;
    }

public slots:
    void setHolderName(QString holderName)
    {
        m_holderName = holderName;
    }

private:
    long m_balance;
    QString m_holderName;
};

#endif // BANKACCOUNT_H
