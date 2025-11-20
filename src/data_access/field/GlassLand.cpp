//
// Created by lys21 on 2025/11/19.
//

#include "GlassLand.hpp"

#include "Field.hpp"
#include "FieldType.hpp"

GlassLand::GlassLand() {
    name = "草原";
    type = FieldType::GRASSLAND;
    plantGeneration = 10.0f;
    waterGeneration = 8.0f;
}

