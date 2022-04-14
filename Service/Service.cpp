//
// Created by Ioana Ursu on 14/04/2022.
//

#include "Service.h"

Service::Service() {

}

Service::Service(Repo &r) {
    this->repo = r;
}

void Service::create(Entity &ent) {
    repo.add_entity(ent);

}

void Service::update(Entity &old_ent, Entity &new_ent) {
    repo.modify_entity(old_ent, new_ent);

}

void Service::delete_ent(Entity &ent) {
    repo.delete_entity(ent);

}

vector<Entity> Service::get_all() {
    vector<Entity> v = this->repo.getAll();
    return v;
}

Entity Service::get_by_id(int id) {
    return repo.get_by_Id(id);
}

Service::~Service() = default;
