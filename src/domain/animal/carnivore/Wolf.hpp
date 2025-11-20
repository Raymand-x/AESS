//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_WOLF_HPP
#define BIODB_WOLF_HPP


class Wolf:public Carnivore {
public:
    Wolf(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Wolf");
    }
    void hunt(Animal *animal){};
};


#endif //BIODB_WOLF_HPP