//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_GRASSLAND_HPP
#define BIODB_GRASSLAND_HPP


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


#endif //BIODB_GRASSLAND_HPP