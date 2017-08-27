#include <iostream>
#include "Gangster.h"
#include "Mafia.h"


std::ostream &operator<<(std::ostream &os, const Mafia &mafia) {
    mafia.print(mafia.getBoss(), os);
}

int main() {

    auto g1 = new Gangster(1, 1);
    auto g2 = new Gangster(2, 2);
    auto g3 = new Gangster(3, 3);
    auto g4 = new Gangster(4, 6);
    auto g5 = new Gangster(5, 5);
    auto g6 = new Gangster(6, 5);
    g1->addSubordinate(g2);
    g1->addSubordinate(g3);
    g3->addSubordinate(g4);
    g3->addSubordinate(g5);
    g3->addSubordinate(g6);

    Mafia mafia;
    mafia.setBoss(g1);
    mafia.isBigBoss(g1);

    mafia.sendToJail(5);
    std::cout << mafia;
    std::cout << ".------------." << std::endl;
    mafia.releaseFromJail(5);
    std::cout << mafia;

    /*Gangster* _g = mafia.findById(mafia.getBoss(), 3);
    if(_g) {
        std::cout << _g->getId();
    } else {
        std::cout << "Not found";
    }*/
}