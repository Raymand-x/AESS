//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_TERRAIN_HPP
#define BIODB_TERRAIN_HPP


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

#endif //BIODB_TERRAIN_HPP