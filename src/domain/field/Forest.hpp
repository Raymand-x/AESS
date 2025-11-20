//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_FOREST_HPP
#define BIODB_FOREST_HPP


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

#endif //BIODB_FOREST_HPP