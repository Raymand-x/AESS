//
// Created by lys21 on 2025/11/19.
//

#ifndef BIODB_FIELD_HPP
#define BIODB_FIELD_HPP
#pragma db object polymorphic
#include "odb/forward.hxx"

class Field {
    friend class odb::access;
protected:
    #pragma db id auto
    unsigned long id_;
    std::string name;
    #pragma db column("Type")
    FieldType type;
    #pragma db column("PlantGeneration")
    float plantGeneration;
    #pragma db column("WaterGeneration")
    float waterGeneration;
public:
    float getWaterGeneration();
    float getPlantGeneration();
    std::string getName();
    FieldType getType();
};
#endif //BIODB_FIELD_HPP