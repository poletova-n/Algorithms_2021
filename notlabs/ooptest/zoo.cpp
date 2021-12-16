#include <iostream>

class Heart
{
private:
    int height;
    int beatsPerMunit;
    bool isTasty;
public:

    Heart(int height, int beatsPerMunit, bool isTasty) : height(height), beatsPerMunit(beatsPerMunit),
                                                         isTasty(isTasty) {}
};

class Animal{

private:
    Heart heart;
    const char* name = "a";
    int age;
public:
    enum SEX{
        MALE,
        FEMALE
    };

    Animal(const Heart &heart, const char *name, int age) : heart(heart), name(name), age(age) {}

    const Heart &getHeart() const {
        return heart;
    }

    void setHeart(const Heart &heart) {
        Animal::heart = heart;
    }

    const char *getName() const {
        return name;
    }

    void setName(const char *name) {
        Animal::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Animal::age = age;
    }

};

class Cage{
private:
    Animal animal;
};

class Zebra : public Animal{
private:
    bool blackAndWhite;
    char* favoriteGrass;
public:
    Zebra(const Heart &heart, const char *name, int age) : Animal(heart, name, age) {}
};

class Crocodile: public Animal{
private:
    char* favorite;
public:
    enum FAVORITE_FOOD{
    };

    void eat(){

    }
};

int main()
{
    Heart heart{2,3,true};
    Animal animal{heart, "a", 1};
    Zebra zebra{heart, "a", 1};
    animal = zebra;
    return 0;
}