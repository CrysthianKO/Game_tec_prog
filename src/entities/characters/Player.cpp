#include "Player.hpp"

#include "Character.hpp"
#include "Physics.hpp"
#include "SFML/System/Vector2.hpp"

// (hard coded)
Player::Player(const sf::Texture& texture)
    : Character(texture) {  // A responsabilidade de passar a Textura fica pra
                            // outra classe
  y = 200;                  // posicao inicial
  x = 200;
  mSprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
  mSprite.setPosition({x, y});
  mSprite.setOrigin({32.f, 32.f});
  mSprite.setScale({1.f, 1.f});
  mCurrentFrame = sf::IntRect({0, 0}, {64, 64});
}

Player::~Player() {}

//// retorna os limites do sprite do jogador para detecção de colisão
//sf::FloatRect Player::getBounds() const { return mSprite.getGlobalBounds(); }

// implementação inputs do usuario (hard coded)
void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
  // pulo
  if (key == sf::Keyboard::Key::Space && isPressed && mIsGrounded) {
    mVelocity.y = -1000.f;  // Velocidade de pulo (ajuste conforme necessário)
    mIsGrounded = false;
  }

  // movimento(WASD)
  if (key == sf::Keyboard::Key::W)
    mIsMovingUp = isPressed;
  else if (key == sf::Keyboard::Key::S)
    mIsMovingDown = isPressed;
  else if (key == sf::Keyboard::Key::A)
    mIsMovingLeft = isPressed;
  else if (key == sf::Keyboard::Key::D)
    mIsMovingRight = isPressed;
}

sf::Vector2f Player::getPosition() { return sf::Vector2f({x, y}); }
// atualiza a posição do player com base nos inputs do usuario e atualiza a
// animacao do player
// void Player::update(sf::Time dt) {
//   sf::Vector2f movement(0.f, 0.f);
//   sf::Vector2f accelaration(0.f, 9.f);
//   sf::Vector2f velocity(0.f, 0.f);

//   // aplica gravidade ao player, aumentando a velocidade vertical do player a
//   // cada frame
//   Physics::applyGravity(mVelocity, dt);

//   if (mIsMovingUp) movement.y -= mPlayerSpeed;
//   if (mIsMovingDown) movement.y += mPlayerSpeed;
//   if (mIsMovingLeft) movement.x -= mPlayerSpeed;
//   if (mIsMovingRight) movement.x += mPlayerSpeed;

//   // dx = v * dt
//   mSprite.move(movement * dt.asSeconds());

//   // move player na verticao pela gravidade
//   mSprite.move(mVelocity * dt.asSeconds());

//   // colisão com o chão (janela)
//   float groundLevel = 768.f - mSprite.getGlobalBounds().size.y;
//   if (mSprite.getPosition().y > groundLevel) {
//     mSprite.setPosition({mSprite.getPosition().x, groundLevel});
//     mVelocity.y = 0.f;
//     // flag para pulo
//     mIsGrounded = true;
//   }

//   updateAnimation(dt);
// }

// atualiza a animacao do player, mudando o frame da sprite a cada 0.1 segundos
// (hard coded)
// void Player::updateAnimation(sf::Time dt) {
//   mAnimationTimer += dt;

//   if (mAnimationTimer >= sf::seconds(0.1)) {
//     mCurrentFrame.position.x += 64;
//     if (mCurrentFrame.position.x >= (64 * 6)) {
//       mCurrentFrame.position.x = 0;
//     }

//     mSprite.setTextureRect(mCurrentFrame);
//     mAnimationTimer -= sf::seconds(0.1);
//   }
// }

CharacterType Player::getCharacterType() const { return CH_PLAYER; }