//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_DEER_HPP
#define BIODB_DEER_HPP


class Deer:public Herbivore {
public:
    Deer(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Deer");
    }
};

#endif //BIODB_DEER_HPP