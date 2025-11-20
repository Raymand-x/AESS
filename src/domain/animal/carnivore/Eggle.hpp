//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_EGGLE_HPP
#define BIODB_EGGLE_HPP


class Eggle:public Carnivore {

public:
    Eggle(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Eggle");
    }
};


#endif //BIODB_EGGLE_HPP