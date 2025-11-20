//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_HERBIVORE_HPP
#define BIODB_HERBIVORE_HPP


class Herbivore:public Animal{
protected:
    float Food_Needs_Per_Month;//每周期植物需求

public:
    //草食动物
    virtual bool isHerbivore() const {return true;}
    virtual bool isCarnivore() const {return false;}
    //进食
    virtual void eat() override {
        if(!currentTerrain||number <=0 ) return;//无进食者

        float total_needs=Food_Needs_Per_Month*number;
        bool eatsuccess=currentTerrain->consume_plants(total_needs);

        if(eatsuccess){
            set_Hunger(0);
            setbreedCount(breedCount+1);
            cout<<"进食成功，群体饱腹！"<<endl;
        }
        else{
            set_Hunger(hunger+1);
            cout<<"食物资源不足，陷入饥饿！"<<endl;
        }
    }
    //繁殖
    virtual void breed() override{
        if(breedCount>=pre_breed&&number>0){
            int new_members=max(int(number*0.1),1);//增长率：10%，至少增加1
            setNumber(number+new_members);
            setbreedCount(0);
            cout<<"成功繁殖"<<new_members<<"只"<<endl;
        }
    }
    //饥饿死亡
    virtual void update() override{
        if(number<=0)
            cout<<"群体灭绝"<<endl;
        if(hunger>=MAX_hunger){
            int loss=max(int(number*0.1),1);//减员率10%，至少减少1
            setNumber(number-loss);
            cout<<"极度饥饿，减员"<<loss<<"只"<<endl;
        }
    }
    //衰老死亡？，可拓展
};

#endif //BIODB_HERBIVORE_HPP