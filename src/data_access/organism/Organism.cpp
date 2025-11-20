//
// Created by lys21 on 2025/11/19.
//

#include "Organism.hpp"

FieldType Organism::getFieldType() {
    return fieldType;
}

float Organism::getWaterConsumption() {
    return waterConsumption;
}

float Organism::getVegetationConsumption() {
    return vegetationConsumption;
}

float Organism::getPreyConsumption() {
    return preyConsumption;
}

std::string Organism::getName() {
    return name;
}

