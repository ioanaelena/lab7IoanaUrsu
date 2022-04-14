//
// Created by Ioana Ursu on 05/04/2022.
//

#include "Repo.h"
#include <vector>
#include "cstring"

using namespace std;

Repo::Repo() {
    this->entities;
    this->n_entities=0;
}

Repo::~Repo() {

}

int Repo::get_size() {
    return this -> n_entities;
}

void Repo::add_entity(Entity &e) {
    this->entities[this->n_entities++]=e;

}

vector<Entity> Repo::getAll() {
    vector <Entity> v;
    for(int i=0;i<this->get_size();i++)
    {
        v.push_back(this->entities[i]);
    }
    return v;
}



void Repo::modify_entity(Entity &old_e, Entity &new_e) {
    for (int i = 0; i < n_entities; i++)
        if (entities[i].getId() == old_e.getId())
            entities[i] = new_e;

}

void Repo::delete_entity(Entity &e) {
    int idDelete = e.getId();
    for (int i = 0; i < n_entities; i++)
        if (entities[i].getId() == idDelete) {
            for (int j = i; j < n_entities - 1; j++)
                entities[j] = entities[j + 1];
            n_entities--;
        }

}

Entity Repo::get_e_from_pos(int pos) {
    return this->entities[pos];
}

Entity Repo::get_by_Id(int id) {
    for (Entity &e: entities) {
        if (e.getId() == id) {
            return e;
        }
    }
}

Entity Repo::get_by_name(const char *name) {
    for (Entity &e: entities) {
        if (strcmp(e.getName(), name) == 0) {
            return e;
        }
    }
}

Repo &Repo::operator=(const Repo &repo) {
    if(this != &repo)
    {
        this->n_entities = repo.n_entities;
        for(int i = 0; i < n_entities; i++)
            this->entities[i] = repo.entities[i];
    }
    return *this;
}

