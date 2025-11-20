//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_WILDDUCK_HPP
#define BIODB_WILDDUCK_HPP



class WildDuck:public Herbivore {
public:
    wildDuck(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("WildDuck");
    }
    void move(bool direction,int num){};
};

#endif //BIODB_WILDDUCK_HPP