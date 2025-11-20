//
// Created by lys21 on 2025/11/20.
//

#ifndef BIODB_SNAKE_HPP
#define BIODB_SNAKE_HPP


class Snake:public Carnivore {

public:
    Snake(int number,Terrain *terrain){
        this->number=number;
        setTerrain(terrain);
        setSpeciesName("Snake");
    }
};

#endif //BIODB_SNAKE_HPP