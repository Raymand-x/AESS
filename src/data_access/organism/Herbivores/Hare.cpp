//
// Created by lys21 on 2025/11/19.
//

#include "Hare.hpp"


Hare::Hare() {
    name = "野兔";
    this->organismType = OrganismType::Herbivores;
    this->vegetationConsumption = 1.5f;
    this->waterConsumption = 2.0f;
    this->fieldType = FieldType::GRASSLAND;
}

