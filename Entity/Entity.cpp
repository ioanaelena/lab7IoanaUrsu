//
// Created by Ioana Ursu on 05/04/2022.
//

#include "Entity.h"
#include "cstring"

Entity::Entity() {
  this-> name = nullptr;
  this-> number = 0;
  this-> sum = 0;
}

Entity::Entity(const char* name, int number, int sum, int id) {
    this ->name = new char[strlen(name)+1];
    strcpy_s(this-> name, sizeof this->name, name);
    this-> number = number;
    this-> sum = sum;
    this->id = id;
}

Entity::Entity(const Entity &e) {
    this ->name = new char[strlen(name)+1];
    strcpy_s(this-> name, sizeof this->name, name);
    this-> number = e.number;
    this-> sum = e.sum;
}

Entity::~Entity() {
    if (this->name) {
        delete[] this->name;
        this-> name = nullptr;
    }
}

int Entity::getNumber() const {
    return number;
}

int Entity::getSum() const {
    return sum;
}

void Entity::setSum(int sum) {
    Entity::sum = sum;
}

void Entity::setNumber(int number) {
    Entity::number = number;
}


Entity &Entity::operator=(const Entity &e) {
    if(this->name != nullptr){
        delete[] this->name;
    }
    this->name = new char[strlen(e.name) +1];
    strcpy(this->name, e.name);
    //this->setName(e.name);
    this->setSum(e.sum);
    this->setNumber(e.number);
    this->setId(e.id);
    return *this;
}

char *Entity::getName() const {
    return this->name;
}

void Entity::setName(const char *name) {
    if(this->name) {
        delete[]this->name;
    }
    this->name = new char[strlen(name) + 1];
    strcpy_s(this->name,sizeof this->name,name);
}

void Entity::setId(int id) {
    this->id = id;

}

int Entity::getId() {
    return id;
}

bool Entity::operator==(const Entity &e) {
    return this->number == e.number && this->sum == e.sum && strcmp(this->name, e.name) == 0;
}


