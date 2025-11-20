//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_RABBIT_HPP
#define BIODB_RABBIT_HPP


class Rabbit:public Herbivore {
public:
    Rabbit(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Rabbit");
        cout<<"Rabbit"<<" "<<number<<" "<<"is born in"<<terrain->get_typeName()<<endl;
    }

    int deathmark=0;
    void hunt(){
        int a=rand()%100;
        //周期单只的饥饿判定
        if (a<10){
            number--;
            deathmark=0;
            cout<<"饿死"<<endl;
        }
        else if(a<20)
            deathmark++;

        else
            deathmark=0;
        //死亡
        if(deathmark>=2)
        {
            number--;
            deathmark=0;
        }
    }
    /*
    进食
    void eat(){

        cout<<"Rabbit eat grass"<<endl;
    }
    移动
    void move(){}
    狩猎：成功率x%
    void hunt(){}
    饥饿值，死亡
    void die(){}
    */

};

#endif //BIODB_RABBIT_HPP