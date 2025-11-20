//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_SHEEP_HPP
#define BIODB_SHEEP_HPP


class Sheep:public Herbivore {
public:
    Sheep(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Sheep");
    }
};

#endif //BIODB_SHEEP_HPP