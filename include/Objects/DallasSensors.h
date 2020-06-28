#pragma once

#include <Arduino.h>

#include "DallasTemperature.h"

struct DallasSensor_t {
    uint8_t address;
    String name;
    DallasSensor_t(uint8_t address, String name) : address(address), name(name){};
};

class DallasSensors {
   public:
    DallasSensors();
    DallasSensor_t* create(uint8_t address, String name);
    DallasSensor_t* at(size_t index);
    DallasSensor_t* get(uint8_t address);
    DallasSensor_t* get(String name);
    size_t count();

   private:
    std::vector<DallasSensor_t> _items;
};

extern DallasSensors dallasSensors;

extern DallasTemperature* dallasTemperature;
