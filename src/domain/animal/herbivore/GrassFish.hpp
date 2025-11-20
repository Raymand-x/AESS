//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_GRASSFISH_HPP
#define BIODB_GRASSFISH_HPP


class GrassFish:public Herbivore {
public:
    grassFish(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("GrassFish");
    }
};

#endif //BIODB_GRASSFISH_HPP