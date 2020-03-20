#include "GlobalMessage.h"
#include "../Game/include/Game.h"

using GameSpecification::GlobalMessage;
using json = nlohmann::json;
GlobalMessage::GlobalMessage(): BaseRule(RuleType::GlobalMessageType), value(""){}

GlobalMessage::GlobalMessage(const json &ruleJson) : BaseRule(RuleType::GlobalMessageType){
    parseRule(ruleJson);
}

std::string GlobalMessage::getValue() const{
    return value;
}

void GlobalMessage::process(GameState& gameState) {
    auto variables = gameState.getVariable(value);
    if (auto retrievedValue = variables->lock()) {
        auto val = boost::apply_visitor(Visit_Type(), retrievedValue.get()->value);
        if(val.i){
            //add message to the game
        }
        if(val.str.size()>0){
            //add message to the game
        }
    }
}
void GlobalMessage::parseRule(const json &ruleJson){
    try{
       value = ruleJson.at("value").get<std::string>(); 
    }catch(json::exception &e){
        //TODO: Handle exception more properly
        std::cout << e.what() << "\n";
    }
}