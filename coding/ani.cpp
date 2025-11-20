#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<algorithm>

using namespace std;
//1、地形：草原-森林、水域===========================================
class Terrain{
    //资源：
protected:
    float plants;//植物
    float water;
    int x,y,size;//拓展用*，来得及做就做
    string typeName;
    const float MAX_plants;
    const float MAX_water;
    const float Regrow_Rate;

public:
    Terrain(float MAX_plants,float MAX_water,float Regrow_Rate):
    plants(0),water(0),x(0),y(0),size(0),typeName(""),MAX_plants(MAX_plants),MAX_water(MAX_water),Regrow_Rate(Regrow_Rate){}
    //资源再生与展示
    virtual void generate_resource()=0;
    void show_resource(){
        cout<<"plants:"<<plants<<"kg,water:"<<water<<"L"<<endl;
    }
    //protected getter...
    bool consume_plants(float needs){ 
        if(plants>=needs){
            plants-=needs;
            return true;
        }
        return false;
    }
    string get_typeName() const {return typeName;}
    float get_plants() const {return plants;}

};
class grassLand:public Terrain{    
public:
    grassLand(int x,int y,int size,int plants,int water):
    Terrain(100.0f,80.0f,0.15f)//最大值初始化
    {
        this->x=x;
        this->y=y;
        this->size=size;
        this->plants=plants;
        this->typeName="grassLand";
    }
    virtual void generate_resource(){
        //基于现有资源数的比例再生
        plants=min(plants*(1+Regrow_Rate),MAX_plants);//0.15
        water=min(water*(1+Regrow_Rate*0.8f),MAX_water);//0.12
    }
};
class Forest:public Terrain{
public:
    Forest(int x,int y,int size,int plants,int water):
    Terrain(80.0f,70.0f,0.10f)//最大值初始化
    {
        this->x=x;
        this->y=y;
        this->size=size;
        this->plants=plants;
        this->typeName="Forest";
    }
    virtual void generate_resource(){
        //基于现有资源数的比例再生
        plants=min(plants*(1+Regrow_Rate),MAX_plants);//0.10
        water=min(water*(1+Regrow_Rate*1.2f),MAX_water);//0.12
    }
};
class waterArea:public Terrain{
public:
    waterArea(int x,int y,int size,int plants,int water):
    Terrain(50.0f,100.0f,0.08f)//最大值初始化
    {
        this->x=x;
        this->y=y;
        this->size=size;
        this->plants=plants;
        this->typeName="waterArea";
    }
    virtual void generate_resource(){
        //基于现有资源数的比例再生
        plants=min(plants*(1+Regrow_Rate),MAX_plants);//0.08
        water=MAX_water;//水域无缺
    }
};
//2、动物==========================================================
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
//草食动物-----------------
class Rabbit:public Animal{
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
class Sheep:public Animal{
public:
    Sheep(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Sheep");
    }
};
class Squirrel:public Animal{
public:
    Squirrel(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Squirrel");
    }
};
class Deer:public Animal{
public:
    Deer(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Deer");
    }
};
class grassFish:public Animal{
public:
    grassFish(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("grassFish");
    }
};
class wildDuck:public Animal{
public:
    wildDuck(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("wildDuck");
    }
    void move(bool direction,int num){};
};
//肉食动物------------------------
class Wolf:public Animal{
public:
    Wolf(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Wolf");
    }
    void hunt(Animal *animal){};
};
class Eggle:public Animal{
    
public:
    Eggle(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Eggle");
    }
};
class Leopad:public Animal{
    
public:
    Leopad(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Leopad");
    }
};//豹子
class Snake:public Animal{
    
public:
    Snake(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Snake");
    }
};
class blackFish:public Animal{
    
public:
    blackFish(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("blackFish");
    }
};
class grayHeron:public Animal{
public:
    grayHeron(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("grayHeron");
    }
    void move(bool direction,int num){};
};//苍鹭
//3、函数============================================================
int main(){
    //地域资源初始化
    grassLand g1=grassLand(0,0,10,60,50);
    Forest f1=Forest(10,0,10,55,45);
    waterArea w1=waterArea(0,10,10,70,75);
    //草食动物初始化
    Rabbit c1=Rabbit(20,&g1);
    Sheep c2=Sheep(10,&g1);
    Squirrel c3=Squirrel(15,&f1);
    Deer c4=Deer(8,&f1);
    grassFish c5=grassFish(30,&w1);
    wildDuck c6=wildDuck(12,&w1);
    //肉食动物初始化
    Wolf r1=Wolf(5,&g1);
    Eggle r2=Eggle(3,&g1);
    Leopad r3=Leopad(4,&f1);
    Snake r4=Snake(6,&f1);
    blackFish r5=blackFish(8,&w1); 
    grayHeron r6=grayHeron(4,&w1);
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

