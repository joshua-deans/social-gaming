#include "GameParser.h"
#include "GameConfig.h"
#include <vector>

namespace Tags{


}
////public methods
GameParser::GameParser(const std::string& path) :
    hasGame(true) 
    {
    nlohmann::json gameJson = fileToJson(path);
    GameState gameState = createGameState(gameJson);
    GameSpecification::GameSpec gameSpec(gameJson);

    game = std::make_unique<Game> (gameSpec, gameState);
}

std::unique_ptr<Game> GameParser::getGame() noexcept{
    assert(hasGame);
    hasGame = false;
    return std::move(game);
}

nlohmann::json GameParser::fileToJson(const std::string& pathName) {
    std::ifstream jsonStream(pathName);
    nlohmann::json jsonConfig = nlohmann::json::parse(jsonStream);    
    return jsonConfig;
}

GameState  GameParser::createGameState(nlohmann::json gameJson) {

    GameState gameState;
    //TODO make it more generic to support more games
    auto gameConfig = GameConfig();
    auto config = gameJson.at(CONFIGURATION);

    for(const auto& item : config.items()){
        if(item.key() == NAME){
            gameConfig.setName(item.value());
        }
        else if (item.key() == AUDIENCE) {
            gameConfig.setAudience(item.value());
        }
        else if (item.key() == PLAYER_COUNT){
            auto playerCount = Configuration::PlayerCount{item.value().at(MAX), item.value().at(MIN)};
            gameConfig.setPlayerCount(playerCount);
        }
        else if(item.key() == SETUP){
            Setup setup = item.value();
            gameConfig.setSetup(setup);
        }
    }

    auto constants = gameJson.at(CONSTANTS);

    StateValueMap map1;
    StateValueMap map2;
    StateValueMap map3;
    StateValueMap map4;
    StateValueMap map5;
    StateValueList list1;
    StateValueList list2;
    for(const auto& constant : constants.items()){
        if(constant.key() == WEAPONS){
            for(auto constantValue : constant.value()){
                for(const auto r : constantValue.items()){

                    auto e = StateValueString(r.value());

                    if(map1.getMap().size() != 2) {
                        map1.addValue(r.key(), e);
                    }
                    else if(map2.getMap().size()!=2){
                        map2.addValue(r.key(), e);
                    }
                    else if(map3.getMap().size()!=2){
                        map3.addValue(r.key(), e);
                    }
                }
            }
        }else{
			auto constantType = GameState::ValueType::CONSTANT;
			auto s = constant.value();
			if(s.is_number_integer()){
                StateValueNumber val(s.get<int>());
                gameState.addValue(constant.key(), val, constantType);
            }else if(s.is_number_float()){
                StateValueNumber val(s.get<double>());
                gameState.addValue(constant.key(), val, constantType);
            }else if(s.is_string()){
                StateValueString val(s.get<std::string>());
                gameState.addValue(constant.key(), val, constantType);
            }else if(s.is_boolean()){
                StateValueBoolean val(s.get<bool>());
                gameState.addValue(constant.key(), val, constantType);
            }
		}
    }
    list1.addValue(map1);
    list1.addValue(map2);
    list1.addValue(map3);

    gameState.addValue(WEAPONS, list1, GameState::ValueType::CONSTANT);


    auto variable = gameJson.at(VARIABLES);
    for(const auto& value: variable.items()){
        GameState::ValueType variableType = GameState::ValueType::VARIABLE;
        auto s = value.value();
        if(value.key() == WINNERS){
            list1.addValue(map4);
            gameState.addValue(WINNERS, list1, variableType);
        } else{
            if(s.is_number_integer()){
                StateValueNumber val(s.get<int>());
                gameState.addValue(value.key(), val, variableType);
            }else if(s.is_number_float()){
                StateValueNumber val(s.get<double>());
                gameState.addValue(value.key(), val, variableType);
            }else if(s.is_string()){
                StateValueString val(s.get<std::string>());
                gameState.addValue(value.key(), val, variableType);
            }else if(s.is_boolean()){
                StateValueBoolean val(s.get<bool>());
                gameState.addValue(value.key(), val, variableType);
            }
            //TODO: Add more code to handle other types
        }
    }

    auto perPlayer = gameJson.at(PER_PLAYER);
    for(const auto& pPlayer : perPlayer.items()){
        if(pPlayer.key() == WINS){
            auto num = static_cast<int>(pPlayer.value());
            gameState.addValue(WINS, StateValueNumber(num), GameState::ValueType::PER_PLAYER);
        } else if (pPlayer.key() == WEAPON) {
            gameState.addValue(WEAPON, StateValueString(""), GameState::ValueType::PER_PLAYER);
        }
    }

    auto perAudience = gameJson.at(PER_AUDIENCE);
    for(const auto& pAudience : perPlayer.items()){
        gameState.addValue("",StateValueMap(map5),GameState::ValueType::PER_AUDIENCE);
    }

    return gameState;

}

//void GameParser::createStateValueString(const std::string& key, const std::string& value, const GameState::ValueType& type, GameState& gameState) {
//    StateValueString stringValue(value);
//    gameState.addValue(key, stringValue, type);
//}
//
//void GameParser::createStateValueNumber(const std::string& key, const int& value, const GameState::ValueType& type, GameState& gameState) {
//    StateValueNumber numberValue(value);
//    gameState.addValue(key, numberValue, type);
//}
//
//void GameParser::createStateValueBoolean(const std::string& key, const bool& value, const GameState::ValueType& type, GameState& gameState) {
//    StateValueBoolean boolValue(value);
//    gameState.addValue(key, boolValue, type);
//}
