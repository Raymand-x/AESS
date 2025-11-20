//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_BLACKFISH_HPP
#define BIODB_BLACKFISH_HPP


class blackFish:public Carnivore {

public:
    blackFish(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("blackFish");
    }
};


#endif //BIODB_BLACKFISH_HPP