//
// Created by josh on 2020-03-19.
//

#include "StateValueMap.h"

StateValueMap::StateValueMap() :
        valueType(StateValue::MAP)
{}

StateValue::ValueType StateValueMap::getValueType() {
    return valueType;
}

std::unordered_map<std::string, std::shared_ptr<StateValue>>& StateValueMap::getMap() {
    return stateValueMap;
}

std::optional<std::weak_ptr<StateValue>> StateValueMap::getValue(const std::string& key) {
    auto it = stateValueMap.find(key);
    return (it != stateValueMap.end()) ?
           std::make_optional(std::weak_ptr(it->second)) :
           std::nullopt;
}
