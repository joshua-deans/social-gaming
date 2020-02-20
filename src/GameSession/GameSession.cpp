#include "include/GameSession.h"
#include "GameSessionManager.h"
#include "Game.h"
#include <nlohmann/json.hpp>

GameSession::GameSession(User& owner) : 
    invitationCode (Invitation::createNewInvitation()), 
    owner (owner),
    gameStarted(false)
    // game(nlohmann::json gameSettings) 
{}

Invitation GameSession::getInvitationCode() const {
    return invitationCode;
}

size_t GameSession::getTotalPlayerCount() const noexcept {
    return usersInSession.size();
}

std::string GameSession::getSessionName() const {
    return sessionName;
}

bool GameSession::doesUserOwnGame(const User& user) const {
    return (user == owner);
}

bool GameSession::isGameStarted() const {
    return gameStarted;
}

void GameSession::addUserToSession(User& user) { 
    // TODO: UserList may need to be revised in order to accomodate this operation better.
    usersInSession.addUser(user.getUserId());
    
}

void GameSession::removeUserFromSession(User& user) { 
    // TODO: UserList may need to be revised in order to accomodate this operation better.
    usersInSession.removeUser(user.getUserId());
}

void GameSession::removeAllUsersfromSession(){ 
    usersInSession.removeAllUsers();
}

void GameSession::setConfigurationSettings(std::string jsonSettings) { 
    JSONSetting = jsonSettings;
}

void GameSession::startGame() {
    gameStarted = true;
}

UserList GameSession::getUsersInSession() {
    return usersInSession;
}


void GameSession::addMessages(const std::string &message) {
    messages.push(message);
}

std::queue<std::string> GameSession::getMessages() {
     return messages;
 }

 void GameSession::clearMessages() {
    while(!messages.empty()) {
        messages.pop();
    }
 }