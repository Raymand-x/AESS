//
// Created by lys21 on 2025/11/19.
//

#ifndef BIODB_ORGANISM_HPP
#define BIODB_ORGANISM_HPP
#include <string>

#include "OrganismType.hpp"
#include "../field/FieldType.hpp"
#include "domain/field/Field.hpp"
#include "odb/forward.hxx"

// 生物基类
#pragma db object polymorphic
class Organism {
private:
    friend class odb::access;
protected:
    #pragma db id auto
    unsigned long id_;

    #pragma db column("Name")
    std::string name; // 名称，应继承
    #pragma db column("FieldType") type("INT")
    FieldType fieldType; // 生存的地形
    #pragma db column("organismType") type("INT")
    OrganismType organismType; // 草食 or 肉食

    #pragma db column("VegetationConsumption")
    float vegetationConsumption; // 植物资源消耗 单位 kg / 只 / 月
    #pragma db column("PreyConsumption")
    float preyConsumption; // 动物捕食量消耗，单位 只 / 只 / 月
    #pragma db column("WaterConsumption")
    float waterConsumption; // 水消耗量 单位 L / 只 / 月
public:
    virtual ~Organism() {}
    int getVegetationConsumption();
    int getPreyConsumption();
    int getWaterConsumption();
    std::string getName();
    FieldType getFieldType();
};

#endif //BIODB_ORGANISM_HPP