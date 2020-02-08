#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"

class GameSession { 
    
public:
    GameSession(uintptr_t ownerID);
    Invitation getInvitationCode() const;
    std::string getSessionName() const;
    void setCurrentGame(std::string name);
    void addUserToSession(uintptr_t userID);
    void removeUserFromSession(uintptr_t userID);
    void removeAllUsersfromSession();
    size_t totalPlayerCount() const noexcept;
    int sessionConfigureSettings(std::string jsonSettings);
    void setOwner(uintptr_t ownerID);
    // std::list<Player> GetPlayers(); // TODO: Link with the User class
    void SetPlayerInviteCodes();
    void SetTotalNumPlayers(int totalPlayers);
    void addUserIDToSession(int userID);
    // std::list<Player> getPlayers();  // TODO: Link with the User class

    bool operator==(const GameSession& gameSession ) const {
        return _invitationCode == gameSession._invitationCode;
    }

private:
 
    std::list<std::string> _ListSettingVars;
    std::list<std::string> _ListPerAudience;
    std::list<std::string> _ListRules;
    std::string _currentGame;
    std::list<uintptr_t> _playersIDInSession;
    // std::list<Player> _playersList;  // TODO: Link with the User class

    std::string _sessionName;
    const Invitation _invitationCode;
    int _gameID;
    int _totalNumPlayers;
    uintptr_t _ownerID;
    std::string _JSONSetting;

};

#endif