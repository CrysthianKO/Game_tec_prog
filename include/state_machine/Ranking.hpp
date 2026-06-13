//#pragma once
//#include <string>
//#include <vector>
//#include <algorithm> // sort dos scores
//#include "entities/Ente.hpp"
//#include "state_machine/State.hpp"
//class Player;
//
//struct RankingItem {
//    std::string name;
//    int score;
//};
//
//class Ranking :
//    public Ente, public State
//{
//private:
//    Player* pPlay;
//    std::string playerName;
//    int playerScore;
//    bool nameEntered;
//    sf::Font font;
//    sf::Text txtTitle;
//    sf::Text txtInputPrompt;
//    sf::Text txtPlayerName;
//    sf::Text txtLeaderBoard;
//    sf::Text txtInstructions;
//    std::vector<RankingItem> highScores;
//private:
//    void loadLeaderBoard();
//    void saveLeaderBoard();
//    void insertNewScore();
//    void updateLeaderBoardText();
//public:
//    Ranking();
//    virtual ~Ranking();
//    void execute();
//    void processEvents(const sf::Event& event);
//    void update();
//    void render();
//    void setPlayer(Player* pP, int score);
//};