//
// Created by Ioana Ursu on 05/04/2022.
//

#include "../Entity/Entity.h"
#include <cassert>
#include "iostream"
#include "cstring"
#include "../Repo/Repo.h"
#include "tests.h"
#include "../Service/Service.h"

using namespace std;

void test_constructor_entity() {
    Entity entity;
    assert(entity.getId() == 0);
    assert(entity.getNumber() == 0);
    assert(entity.getSum() == 0);
    assert(entity.getName() == nullptr);
}

void test_constructor2_entity2() {
    const char *s = "gaz";
    Entity entity(s, 1, 10,1);
    assert(strcmp(entity.getName(), s) == 0);

}


void test_getters_setters() {
    const char *s = "apa";
    Entity entity;
    entity.setName(s);
    assert(strcmp(entity.getName(), s) == 0);

}

void test_equal_operator() {
    const char *s = "gaz";
    Entity entity(s, 1, 10,1);
    Entity entity1;
    entity1 = entity;
    assert(entity1.getNumber() == 1);
    assert(entity1.getSum() == 10);
    assert(strcmp(entity.getName(), s) == 0);
    assert(entity1.getId() == 1);

}

void test_repo_add_elem() {
    Repo repo;
    const char *s = "gaz";
    Entity entity(s, 1, 10,1);
    repo.add_entity(entity);
    assert(repo.get_size() == 1);

    const char *s2 = "apa";
    Entity entity1(s2, 2, 11,3);
    repo.add_entity(entity1);
    assert(repo.get_size() == 2);

    const char *s3 = "curent";
    Entity entity2(s3,2,11,0);
    repo.add_entity(entity2);
    assert(repo.get_size() == 3);

}

void test_delete(){
    Repo repo;
    const char*s = "gaz";
    Entity entity(s, 1, 10, 1);
    repo.add_entity(entity);


    const char*s2 = "apa";
    Entity entity1(s2, 2, 11, 3);
    repo.add_entity(entity1);


    repo.delete_entity(entity);
    assert(repo.get_size() == 1);
}


void test_modify(){
    Repo repo1;
    const char*s = "gaz";
    Entity entity(s,1,10,1);


    const char*s2 = "apa";
    Entity entity1(s2, 2, 11, 3);


    const char*s3 = "curent";
    Entity entity2(s3, 2, 11, 0);

    repo1.add_entity(entity);
    repo1.add_entity(entity1);
    repo1.modify_entity(entity, entity2);

    assert(repo1.get_by_Id(0) == entity2);
}

void test_create(){
    Repo repo1;
    Service service(repo1);
    const char*s = "curent";
    Entity entity2(s, 2, 11, 0);

    service.create(entity2);
    assert(service.get_all().size() == 1);
}

void test_update(){
    Repo repo1;
    Service service(repo1);
    const char*s = "gaz";
    Entity entity1(s, 1, 10, 1);
    service.create(entity1);

    const char*s2 = "apa";
    Entity entity2(s2, 2, 11, 3);
    service.update(entity1, entity2);
    assert(service.get_all().size() == 1);
    assert(service.get_by_id(2) == entity2);
}

void test_delete_service(){
    Repo repo;
    Service service(repo);
    const char*s = "gaz";
    Entity entity(s, 1, 10, 1);

    service.create(entity);
    const char*s2 = "apa";
    Entity entity1(s2, 2, 11, 3);
    service.create(entity1);
    assert(service.get_all().size() == 2);

    service.delete_ent(entity);
    assert(service.get_all().size() == 1);
}


void test_all() {

    test_getters_setters();
    test_constructor_entity();
    test_constructor2_entity2();
    test_equal_operator();
    test_repo_add_elem();
    test_delete();
    //test_modify();
    test_create();
   // test_update();
    //test_delete_service();
}
