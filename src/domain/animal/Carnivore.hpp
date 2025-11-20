//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_CARNIVORE_HPP
#define BIODB_CARNIVORE_HPP


class Carnivore:public Animal{
protected:
    float needs_rate;//群体需求猎物比例，猎物：群体
    int hunt_success_rate;//狩猎成功率
public:
    virtual bool isHerbivore() const override { return false; }
    virtual bool isCarnivore() const override { return true; }
    //进食,即狩猎
    virtual void eat(vector<Animal*> &preylist){

    }

};

#endif //BIODB_CARNIVORE_HPP