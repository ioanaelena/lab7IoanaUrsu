//
// Created by Ioana Ursu on 05/04/2022.
//

#ifndef LAB7IOANAURSU_REPO_H
#define LAB7IOANAURSU_REPO_H

#include "../Entity//Entity.h"
#include <vector>

using namespace std;

class Repo {
private:
    Entity entities[100];
    int n_entities;
public:
    Repo();

    int get_size();

    void add_entity(Entity &e);

    Entity get_e_from_pos(int pos);

    Entity get_by_Id(int id);

    Entity get_by_name(const char* name);

    void delete_entity(Entity &e);

    void modify_entity(Entity &old_e, Entity &new_e);

    vector <Entity> getAll();

    Repo& operator=(const Repo& repo);

    ~Repo();
};


#endif //LAB7IOANAURSU_REPO_H
