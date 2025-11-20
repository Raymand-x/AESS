//
// Created by lys21 on 2025/11/20.
//
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>
#include "../domain/animal/carnivore/BlackFish.h"

int main(){
    //地域资源初始化
    grassLand g1=GrassLand(0,0,10,60,50);
    Forest f1=Forest(10,0,10,55,45);
    waterArea w1=WaterArea(0,10,10,70,75);
    //草食动物初始化
    Rabbit c1=Rabbit(20,&g1);
    Sheep c2=Sheep(10,&g1);
    Squirrel c3=Squirrel(15,&f1);
    Deer c4=Deer(8,&f1);
    grassFish c5=GrassFish(30,&w1);
    wildDuck c6=WildDuck(12,&w1);
    //肉食动物初始化
    Wolf r1=Wolf(5,&g1);
    Eggle r2=Eggle(3,&g1);
    Leopad r3=Leopad(4,&f1);
    Snake r4=Snake(6,&f1);
    blackFish r5=BlackFish(8,&w1);
    grayHeron r6=GrayHeron(4,&w1);
    //做交互的目的不是改变生态系统逻辑，而是加入人为的一些干预

    vector<Animal*> grassani={&c1,&c2,&c3,&c4,&c5,&c6};
    vector<Animal*> hunterani={&r1,&r2,&r3,&r4,&r5,&r6};

    cout<<"=============简易动物生态环境模拟系统==============="<<endl;
    int input=0;
    cout<<"请键入周期数："<<endl;
    cin>>input;
    for(int i=0;i<input;i++)
    {
        switch(i%8){
            case 0:
            {}
            case 1:
            {}
            case 2:
            {}
            case 3:
            {}
            case 4:
            {}
            case 5:
            {}
            case 6:
            {}
            case 7:
            {}
            default:
            {}
        }
    }


}
