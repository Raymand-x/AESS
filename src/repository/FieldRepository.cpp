//
// Created by lys21 on 2025/11/19.
//

#include "FieldRepository.hpp"

FieldType FieldRepository::getFieldType(Field *field) {
    return field->getType();
}

void FieldRepository::save(Field *field) {
    db->persist(field);
}

