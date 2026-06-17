#include "state_machine/Ranking.hpp"

#include "entities/characters/Player.hpp"
#include "Game.hpp"
#include "state_machine/Menu.hpp"

Ranking::Ranking() : Ente(), State(), pPlay1(NULL), pPlay2(NULL), playerName(""), playerScore(0), nameEntered(false),
                    highScores()
{
    id = StateID::Ranking;
    if (!font.loadFromFile("media/fonte_teste.ttf"))
    {
        std::cout << "Erro ao carregar a fonte no ranking" << std::endl;
    }

    float posX = pGM->getWindowWidth() - 100.f;
    float posY = pGM->getWindowHeight();

    // Título Principal
    txtTitle.setFont(font);
    txtTitle.setString("RANKING - TOP 10");
    txtTitle.setCharacterSize(40);
    txtTitle.setFillColor(sf::Color::Yellow);
    txtTitle.setPosition(sf::Vector2f(posX / 2 - 125.f, 100.f));

    // Prompt de Input
    txtInputPrompt.setFont(font);
    txtInputPrompt.setString("Digite seu nome e aperte ENTER:");
    txtInputPrompt.setCharacterSize(24);
    txtInputPrompt.setFillColor(sf::Color::White);
    txtInputPrompt.setPosition(sf::Vector2f(posX / 2 - 150.f, 150.f));

    // Texto do Nome digitado
    txtPlayerName.setFont(font);
    txtPlayerName.setString("_");
    txtPlayerName.setCharacterSize(28);
    txtPlayerName.setFillColor(sf::Color::Green);
    txtPlayerName.setPosition(sf::Vector2f(posX / 2 - 50.f, 200.f));

    // Corpo do Leaderboard (Top 10)
    txtLeaderBoard.setFont(font);
    txtLeaderBoard.setCharacterSize(22);
    txtLeaderBoard.setFillColor(sf::Color::White);
    txtLeaderBoard.setPosition(sf::Vector2f(posX / 2 - 150.f, 280.f));

    // Instruções de rodapé
    txtInstructions.setFont(font);
    txtInstructions.setString("Pressione ESC para voltar ao Menu Principal");
    txtInstructions.setCharacterSize(18);
    txtInstructions.setFillColor(sf::Color::Cyan);
    txtInstructions.setPosition(sf::Vector2f(posX / 2 - 180.f, posY - 100.f));

    loadLeaderBoard();
}

Ranking::~Ranking()
{
}

void Ranking::loadLeaderBoard()
{
    //highScores.clear();
    //std::ifstream file("ranking.txt");
    //if (file.is_open())
    //{
    //    RankingItem item;
    //    while (file >> item.name >> item.score)
    //    {
    //        highScores.push_back(item);
    //    }
    //    file.close();
    //}
    //updateLeaderBoardText();
}

void Ranking::saveLeaderBoard()
{
    //std::ofstream file("ranking.txt");
    //if (file.is_open())
    //{
    //    for (const auto& item : highScores)
    //    {
    //        file << item.name << " " << item.score << "\n";
    //    }
    //    file.close();
    //}
}

void Ranking::insertNewScore()
{
    if (playerName.empty())
    {
        playerName = "Anonimo";
    }
    RankingItem newItem{ playerName, playerScore };
    highScores.push_back(newItem);

    std::sort(highScores.begin(), highScores.end(), [](const RankingItem& a, const RankingItem& b) {
        return a.score > b.score; });

    if (highScores.size() > 10)
    {
        highScores.resize(10);
    }
    saveLeaderBoard();
    updateLeaderBoardText();
}

void Ranking::updateLeaderBoardText()
{
    std::string leaderboardStr = "";
    for (size_t i = 0; i < highScores.size(); ++i)
    {
        leaderboardStr += std::to_string(i + 1) + ". " + highScores[i].name + " ...... " + std::to_string(highScores[i].score) + "\n";
    }

    if (highScores.empty()) {
        leaderboardStr = "Nenhum recorde registrado ainda!";
    }

    txtLeaderBoard.setString(leaderboardStr);
}

void Ranking::execute()
{
    update();
}

void Ranking::processEvents(const sf::Event& event)
{
    // 1. Lógica de digitação (Só acontece se ainda não confirmou o nome)
    if (!nameEntered && event.type == sf::Event::TextEntered)
    {
        // Se for Backspace (código 8 ascii) e a string não estiver vazia, apaga um caractere
        if (event.text.unicode == 8)
        {
            if (!playerName.empty())
                playerName.pop_back();
        }
        // Se for uma tecla normal válida (Evita espaços em branco para não quebrar a leitura do arquivo)
        else if (event.text.unicode < 127 && event.text.unicode != 13 && event.text.unicode >= 32)
        {
            // Limita o nome a 10 caracteres
            if (playerName.size() < 10)
                playerName += static_cast<char>(event.text.unicode);
        }
    }
    // 2. Lógica de botões do teclado
    if (event.type == sf::Event::KeyPressed)
    {
        // Confirmar nome
        if (event.key.code == sf::Keyboard::Enter && !nameEntered)
        {
            nameEntered = true;
            insertNewScore();
        }
        // Sair do estado de ranking e voltar para o Menu
        else if (event.key.code == sf::Keyboard::Escape)
        {
            pGame->changeState(new Menu());
        }
    }
}

void Ranking::update()
{
    // Efeito visual simples de "cursor piscando" na caixa de texto
    if (!nameEntered)
    {
        txtPlayerName.setString(playerName + "_");
    }
    else
    {
        txtPlayerName.setString(playerName + " (Salvo!)");
    }
}

void Ranking::render()
{
    float posX = pGM->getWindowWidth() / 2;
    float posY = pGM->getWindowHeight() / 2;
    pGM->updateCameraPos({ posX, posY });
    sf::RenderWindow* window = pGM->getWindow();
    if (window)
    {
        window->draw(txtTitle);
        window->draw(txtInstructions);
        //window->draw(txtLeaderBoard);

        // Se ainda não salvou, mostra os prompts de digitação
        if (!nameEntered)
        {
            window->draw(txtInputPrompt);
            window->draw(txtPlayerName);
        }

        // Sempre desenha a tabela do Top 10 atualizada
        window->draw(txtLeaderBoard);
    }
}

//void Ranking::setPlayers(Player* pP1, Player* pP2, int score)
//{
//    pPlay1 = pP1;
//    pPlay2 = pP2;
//    playerScore = score;
//}

void Ranking::setGameContext(Game* game)
{
    State::setGameContext(game);
    if (pGame)
    {
        pPlay1 = pGame->getPlayer1();
        pPlay2 = pGame->getPlayer2();
        if (pPlay1)
        {
            playerScore = pPlay1->getScore();
            if (pPlay2)
            {
                int score2 = pPlay2->getScore();
                playerScore = (playerScore + score2) / 2;
            }
        }
    }
    loadLeaderBoard();
    updateLeaderBoardText();
}
