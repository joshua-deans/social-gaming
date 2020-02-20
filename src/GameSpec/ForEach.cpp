#include "ForEach.h"

using GameSpecification::ForEach;
using GameSpecification::SpecValue;
using GameSpecification::ControlStructRule;
ForEach::ForEach() : ControlStructRule("foreach"), element(""){}

ForEach::ForEach(const SpecValue& list, const std::string& element) : ControlStructRule("foreach"), 
    list(list), element(element){}

SpecValue ForEach::getList() const{
    return list;
}

std::string ForEach::getElement() const{
    return element;
}



void ForEach::process(){
	//TODO: Add code to process foreach rule
}
