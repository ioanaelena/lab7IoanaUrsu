//
// Created by Ioana Ursu on 05/04/2022.
//



#ifndef LAB7IOANAURSU_ENTITY_H
#define LAB7IOANAURSU_ENTITY_H


class Entity {

private:
    char* name;
    int number;
    int sum;
    int id;

public:
    Entity();

    Entity(const char* name, int number, int sum, int id);

    Entity(const Entity &e);

    int getNumber() const;

    void setNumber(int number);

    int getSum() const;

    void setSum(int sum);

    void setId(int id);

    int getId();

    ~Entity();

    Entity& operator = (const Entity& e);

    bool operator==(const Entity& e);

    char *getName() const;

    void setName(const char *name);

};


#endif //LAB7IOANAURSU_ENTITY_H
