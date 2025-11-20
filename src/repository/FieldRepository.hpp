//
// Created by lys21 on 2025/11/19.
//

#ifndef BIODB_FIELDREPOSITORY_HPP
#define BIODB_FIELDREPOSITORY_HPP

#pragma once
#include <odb/database.hxx>
#include "domain/field/Field.hpp"
#include "Field-odb.hxx"
#include "domain/field/FieldType.hpp"

class FieldRepository {
private:
    std::shared_ptr<odb::database> db;
public:
    void save(Field* field);
    float getWaterGeneration(Field* field);
    float getPlantGeneration(Field* field);
    FieldType getFieldType(Field* field);

};


#endif //BIODB_FIELDREPOSITORY_HPP