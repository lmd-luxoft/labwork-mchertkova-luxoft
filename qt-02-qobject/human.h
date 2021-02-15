#ifndef HUMAN_H
#define HUMAN_H

#include <QObject>

class Human: public QObject
{
    Q_OBJECT
private:
quint8 m_age;
char m_sexSymbol;

public:
quint8 age();
void setAge(quint8 a);
char sexSymbol();
void setSexSymbol(char s);

//public:
Human(QObject *parent = 0): QObject(parent){};
};

#endif // HUMAN_H
