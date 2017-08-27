//
// Created by pedro on 8/26/17.
//

#include "Mafia.h"

Gangster *Mafia::findById(Gangster *gangster, int id) {
    // pre-order
    for (Gangster *g: gangster->getSubordinates()) {
        Gangster *_g = findById(g, id);
        if (_g != nullptr) {
            return _g;
        }
    }
    if (gangster->getId() == id) return gangster;
    return nullptr;
}

Gangster *Mafia::findOldest(const std::list<Gangster *> subordinates, int excludedId = -1) {
    int maxAge = 0;
    Gangster *olderGangster = nullptr;
    for (Gangster *g: subordinates) {
        if (g->getId() != excludedId && g->getAge() > maxAge) {
            maxAge = g->getAge();
            olderGangster = g;
        }
    }
    return olderGangster;
}

void Mafia::sendToJail(int id) {
    Gangster *convict = findById(this->boss, id);
    Gangster *convictBoss = convict->getBoss();
    const std::list<Gangster *> &bossSubordinates = convictBoss->getSubordinates();

    Gangster *newBoss = nullptr;
    if (bossSubordinates.size() == 1) { // Promote a new boss
        newBoss = findOldest(convict->getSubordinates());
        convictBoss->addSubordinate(newBoss);
        // Add the remaining subordinates as subordinates of the promoted boss
        for (Gangster *g: convict->getSubordinates()) {
            if (g->getId() != newBoss->getId()) {
                newBoss->addSubordinate(g);
            }
        }
    } else { // Find a boss in the siblings
        newBoss = findOldest(bossSubordinates, convict->getId());
        for (Gangster *g: convict->getSubordinates()) {
            newBoss->addSubordinate(g);
        }
    }
    convictBoss->removeSubordinate(convict);
    jail.push_back(convict);
}

void Mafia::releaseFromJail(int id) {
    Gangster *releasedGangster = nullptr;
    for (Gangster *g: jail) {
        if (g->getId() == id) {
            releasedGangster = g;
            break;
        }
    }
    if (releasedGangster != nullptr) {
        auto releasedGangsterBoss = releasedGangster->getBoss();
        releasedGangsterBoss->addSubordinate(releasedGangster);
        for (Gangster *g: releasedGangster->getSubordinates()) {
            g->getBoss()->removeSubordinate(g);
            g->setBoss(releasedGangster);
        }
    }
    jail.remove(releasedGangster);
}

bool Mafia::isBigBoss(Gangster *gangster) {
    auto subordinateCount = getSubordinateCount(gangster);
    std::cout << subordinateCount << std::endl;
    return subordinateCount >= 50;
}

std::list<Gangster *>::size_type Mafia::getSubordinateCount(Gangster *gangster) {
    auto subordinateCount = gangster->getSubordinates().size();
    for (Gangster *g: gangster->getSubordinates()) {
        subordinateCount += getSubordinateCount(g);
    }
    return subordinateCount;
}

Gangster *Mafia::getBoss() const {
    return boss;
}

void Mafia::setBoss(Gangster *boss) {
    this->boss = boss;
}

void Mafia::print(Gangster *gangster, std::ostream &os) const {
    os << gangster->getId() << ":";
    for (Gangster *g: gangster->getSubordinates()) {
        os << g->getId() << ",";
    }
    os << std::endl;
    for (Gangster *g: gangster->getSubordinates()) {
        print(g, os);
    }

}
