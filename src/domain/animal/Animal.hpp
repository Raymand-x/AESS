//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_ANIMAL_HPP
#define BIODB_ANIMAL_HPP


class Animal{
protected:
    int number;
    Terrain *currentTerrain;//当前所在区域
    string speciesName;

    int hunger;//饥饿值
    int breedCount;//饱腹计数，用于繁殖
    int MAX_hunger;//最大饥饿值
    int pre_breed;//繁殖前提:累计饱腹次数

public:
    Animal():
    number(0),currentTerrain(NULL),speciesName(""),hunger(0),breedCount(0),MAX_hunger(0),pre_breed(0){}
    void setTerrain(Terrain *terrain){
        currentTerrain=terrain;
    }
    //种群数量
    int getNumber() const {return number;}
    void setNumber(int number)
    {this->number={number<=0?0:number};}//非负
    //物种名
    string getSpeciesName() const {return speciesName;}
    void setSpeciesName(string speciesName)
    {this->speciesName=speciesName;}
    //饥饿值
    int get_Hunger() const {return hunger;}
    void set_Hunger(int hunger)
    {this->hunger=hunger;}
    //繁殖与饱腹
    int getbreedCount() const {return breedCount;}
    void setbreedCount(int breedCount)
    {this->breedCount=breedCount;}

    //虚函数
    virtual void eat()=0;//进食
    virtual void breed()=0;//繁育
    virtual void move()=0;//移动，孙子类中
    virtual void update()=0;//更新
    virtual bool isHerbivore() const=0;//草食
    virtual bool isCarnivore() const=0;//肉食
};

#endif //BIODB_ANIMAL_HPP