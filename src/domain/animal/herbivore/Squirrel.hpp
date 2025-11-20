//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_SQUIRREL_HPP
#define BIODB_SQUIRREL_HPP


class Squirrel:public Herbivore {
public:
    Squirrel(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Squirrel");
    }
};


#endif //BIODB_SQUIRREL_HPP