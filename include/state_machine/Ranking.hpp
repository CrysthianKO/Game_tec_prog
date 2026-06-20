#pragma once
#include <string>
#include <vector>

#include "entities/Ente.hpp"
#include "state_machine/State.hpp"

namespace DinoGame {
namespace StateMachine {

class Player;
class Game;

struct RankingItem {
  std::string name;
  int score;
};

class Ranking : public State, public Ente {
 private:
  Player* pPlay1;
  Player* pPlay2;
  std::string playerName;
  int playerScore;
  bool nameEntered;
  sf::Font font;
  sf::Text txtTitle;
  sf::Text txtInputPrompt;
  sf::Text txtPlayerName;
  sf::Text txtLeaderBoard;
  sf::Text txtInstructions;
  std::vector<RankingItem> highScores;

 private:
  void loadLeaderBoard();
  void saveLeaderBoard();
  void insertNewScore();
  void updateLeaderBoardText();

 public:
  Ranking();
  virtual ~Ranking();
  void execute();
  void processEvents(const sf::Event& event);
  void update();
  void render();
  // void setPlayers(Player* pP1, Player* pP2, int score);
  void setGameContext(Game* game);
};

}  // namespace StateMachine
}  // namespace DinoGame
