//
// Created by pedro on 8/26/17.
//

#include "Gangster.h"

Gangster *Gangster::getBoss() const {
    return boss;
}

void Gangster::setBoss(Gangster *boss) {
    Gangster::boss = boss;
}

int Gangster::getId() const {
    return id;
}

Gangster::Gangster(int id, int age) {
    this->id = id;
    this->age = age;
}

void Gangster::addSubordinate(Gangster *gangster) {
    subordinates.push_back(gangster);
    gangster->setBoss(this);

}

std::list<Gangster *> &Gangster::getSubordinates() {
    return subordinates;
}

int Gangster::getAge() const {
    return age;
}

void Gangster::removeSubordinate(Gangster *gangster) {
    subordinates.remove(gangster);
}


