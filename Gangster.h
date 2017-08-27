//
// Created by pedro on 8/26/17.
//

#ifndef MAFIAC_GANGSTER_H
#define MAFIAC_GANGSTER_H


#include <list>

class Gangster {

public:

    explicit Gangster(int id, int age);

    Gangster *getBoss() const;

    void setBoss(Gangster *boss);

    void addSubordinate(Gangster *gangster);

    void removeSubordinate(Gangster *gangster);

    int getId() const;

    std::list<Gangster *> &getSubordinates();

    int getAge() const;

private:
    int id;
    int age;
    Gangster *boss;
    std::list<Gangster *> subordinates;

};


#endif //MAFIAC_GANGSTER_H
