#include "include/Game.h"

#include <utility>

Game::Game(GameSpecification::GameSpec spec, GameState state) :
    gameSpec{std::move(spec)},
    gameState{std::move(state)},
    messages{}
{}

bool Game::isGameStarted() const {
    return gameState.isGameStarted();
}

void Game::startGame(const std::list<std::weak_ptr<User>>& users) {
    gameSessionUsers.insert(gameSessionUsers.end(), users.begin(), users.end());
    addMessages(" User has started the game...\n");
    importGameSpecRules();

    // Once the game has started, gameTick will end up being called.
    gameState.startGame();
}

void Game::endGame() {
    return gameState.endGame();
}

void Game::addMessages(const std::string &message) noexcept{
    gameState.addMessages(message);
}

std::list<std::string> Game::updateAndGetAllMessages() noexcept{
    return gameState.updateAndGetAllMessages();
}

void Game::gameTick() {
    bool isProgramCounterWithinRange = currentRuleIndex < gameRules.size();
    if (isProgramCounterWithinRange) {
        /*
        bool isCurrentRuleFullyProcessed = processRule(gameRules.at(currentRuleIndex));
        if (isCurrentRuleFullyProcessed) currentRuleIndex += 1;
        */
    } else {
        endGame();
    }
}

void Game::importGameSpecRules() {
    gameRules.clear();
    gameRules = gameSpec.getRules();
}

bool Game::processRule(std::shared_ptr<BaseRule>& rule) {
    /*
    if (rule != nullptr) {
        rule->process(gameState);
        rule = rule->getNextPtr();
        return false;
    }
    */

    return true;
}