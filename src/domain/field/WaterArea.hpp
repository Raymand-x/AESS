//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_WATERAREA_HPP
#define BIODB_WATERAREA_HPP

class WaterArea:public Terrain {
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

#endif //BIODB_WATERAREA_HPP