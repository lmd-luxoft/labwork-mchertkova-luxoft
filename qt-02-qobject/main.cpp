#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include "human.h"
void printTreeInfo(QObject *parent)
{
    Human* human = qobject_cast<Human*>(parent);

    qDebug() <<parent->objectName()<< "age:" << human->age()
             << "sex:" << human->sexSymbol();

    for (int i = 0; i < human->children().length(); ++i) {
     printTreeInfo(human->children().at(i) );
    }

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Human* parent = new Human();
    parent->setObjectName("Lucas Grey");
    parent->setAge(54);
    parent->setSexSymbol('M');

    Human* child1 = new Human(parent);
    child1->setObjectName("Mary Grey");
    child1->setAge(28);
    child1->setSexSymbol('F');
    Human* child2 = new Human(parent);
    child2->setObjectName("Jason Grey");
    child2->setAge(32);
    child2->setSexSymbol('M');

    Human* gchild1 = new Human(child1);
    gchild1->setObjectName("Fred Smith");
    gchild1->setAge(2);
    gchild1->setSexSymbol('M');
    Human* gchild2 = new Human(child1);
    gchild2->setObjectName("Jane Smith");
    gchild2->setAge(2);
    gchild2->setSexSymbol('F');
    Human* gchild3 = new Human(child2);
    gchild3->setObjectName("Sean Grey");
    gchild3->setAge(5);
    gchild3->setSexSymbol('M');
    Human* gchild4 = new Human(child2);
    gchild4->setObjectName("Jessica Grey");
    gchild4->setAge(1);
    gchild4->setSexSymbol('F');
    Human* gchild5 = new Human(child2);
    gchild5->setObjectName("Hannah Grey");
    gchild5->setAge(1);
    gchild5->setSexSymbol('F');
	// TODO: dump tree info using standard Qt method
    parent->dumpObjectTree();
    printTreeInfo(parent);

    // TODO: delete here what need only

    return a.exec();
}
