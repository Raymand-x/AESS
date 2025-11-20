//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_LEOPAD_HPP
#define BIODB_LEOPAD_HPP


class Leopad:public Carnivore {

public:
    Leopad(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Leopad");
    }
};//豹子


#endif //BIODB_LEOPAD_HPP