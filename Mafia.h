//
// Created by pedro on 8/26/17.
//

#ifndef MAFIAC_MAFIA_H
#define MAFIAC_MAFIA_H


#include "Gangster.h"
#include <iostream>

class Mafia {

private:
    Gangster *boss;
    std::list<Gangster *> jail;

    Gangster *findOldest(std::list<Gangster *> subordinates, int excludedId);

public:

    Gangster *getBoss() const;

    void setBoss(Gangster *boss);

    Gangster *findById(Gangster *gangster, int id);

    void sendToJail(int id);

    void print(Gangster *gangster, std::ostream &os) const;

    void releaseFromJail(int id);

    bool isBigBoss(Gangster *boss);

    std::list<Gangster *>::size_type getSubordinateCount(Gangster *gangster);
};


#endif //MAFIAC_MAFIA_H
