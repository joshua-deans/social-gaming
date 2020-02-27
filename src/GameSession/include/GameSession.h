#ifndef GAME_SESSION_H
#define GAME_SESSION_H

#include <iostream> 
#include <string>
#include <list>
#include "Invitation.h"
#include "GameState.h"
#include "User.h"
#include <queue>
class GameSession { 
    
public:
    explicit GameSession(User& owner);
    Invitation getInvitationCode() const;
    size_t getTotalPlayerCount() const noexcept;
    std::string getSessionName() const;
    bool isGameStarted() const;

    void setConfigurationSettings(std::string jsonSettings);
    void startGame();
    void clearMessages();

    bool operator==(const GameSession& gameSession ) const {
        return invitationCode == gameSession.invitationCode;
    }

    void addMessages(const std::string &message);

    std::queue<std::string> getMessages();
    bool doesUserOwnGame(const User& user) const;

    // WIP
    // std::list<Player> getPlayers();  // TODO: Link with the User class
    // void setPlayerInviteCodes();

private:
    std::list<std::string> listSettingVars;
    std::list<std::string> listPerAudience;
    std::list<std::string> listRules;
    std::string currentGame;

    std::queue<std::string> messages;

    std::string sessionName;
    std::string JSONSetting;

    const Invitation invitationCode;

    GameState gameState;
    User& owner;
};

#endif