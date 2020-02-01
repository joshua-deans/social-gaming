#include "include/GameSession.h"

GameSession::GameSession(int ownerID) : 
    _invitationCode (Invitation()), 
    _ownerID (ownerID) {}

Invitation GameSession::getInvitationCode() const {
    return _invitationCode;
}

void GameSession::setCurrentGame(std::string name) {
    this->_currentGame = name;
}

void GameSession::addUserIDToSession(int userID) { 
    _playersIDInSession.push_back(userID);
}
void GameSession::addUserToSession(Player player) { 
    _playersList.push_back(player);
}

size_t GameSession::totalPlayerCount(){
    return _playersInSession.size();
}

void GameSession::removeUserFromSession(int userID) { 
    _playersInSession.remove(userID);
}

void GameSession::removeAllUsersfromSession(){ 
    _playersInSession.clear();
}

int GameSession::sessionConfigureSettings(std::string jsonSettings) { 
    this->_JSONSetting = jsonSettings;
    return 123;
}

void  GameSession::SetTotalNumPlayers(int totalPlayers) { 
    this->_totalNumPlayers = totalPlayers
}

void  GameSession::createInviteCode() { 
    Invitation codeGenerator;
    this->_invitationCode = codeGenerator.generateInvitationCode();
}

void  GameSession::setOwner(int ownerID) { 
    this->_ownerID = ownerID;
}

void  GameSession::getPlayers(int ownerID) { 
    return this->_playersList;
