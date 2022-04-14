//
// Created by Ioana Ursu on 14/04/2022.
//

#ifndef LAB7IOANAURSU_SERVICE_H
#define LAB7IOANAURSU_SERVICE_H


#include "../Repo/Repo.h"
#include <vector>

using namespace std;

class Service {
private:
    Repo repo;
public:
    Service();

    Service(Repo &r);

    ~Service();

    void create(Entity &ent);

    void update(Entity& old_ent, Entity& new_ent);

    void delete_ent(Entity &ent);

    vector <Entity> get_all();

    Entity get_by_id(int id);


};


#endif //LAB7IOANAURSU_SERVICE_H
