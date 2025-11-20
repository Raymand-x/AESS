//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_GRAYHERON_HPP
#define BIODB_GRAYHERON_HPP


class GrayHeron:public Carnivore {
public:
    grayHeron(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("GrayHeron");
    }
    void move(bool direction,int num){};
};//苍鹭


#endif //BIODB_GRAYHERON_HPP