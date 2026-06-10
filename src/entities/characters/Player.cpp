#include "entities/characters/Player.hpp"

#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "managers/Physics.hpp"
#include "managers/TimeManager.hpp"

Player::Player() {}

Player::~Player() {}

void Player::setup() {
  mVelocity.x = 0.f;
  mVelocity.y = 0.f;

  mMoviment.up = false;
  mMoviment.down = false;
  mMoviment.right = false;
  mMoviment.left = false;

  mCurrentFrame = sf::IntRect({0, 0}, {64, 64});
  this->setTexture("PLAYER_TEXTURE");
  mSprite.setPosition(0.f, 0.f);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
  mSprite.setOrigin(32.f, 32.f);
}
void Player::save() {}
void Player::move(sf::Vector2f move) { mSprite.move(move); }
void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
  // pulo
  if (key == sf::Keyboard::Key::Space && isPressed && mOnGround) {
    mVelocity.y = -550.f;  // Velocidade de pulo (ajuste conforme necessário)
    mOnGround = false;
  }

  if (key == sf::Keyboard::Key::LShift) mRunning = isPressed;

  // movimento(WASD)
  if (key == sf::Keyboard::Key::W)
    mMoviment.up = isPressed;
  else if (key == sf::Keyboard::Key::S)
    mMoviment.down = isPressed;
  else if (key == sf::Keyboard::Key::A)
    mMoviment.left = isPressed;
  else if (key == sf::Keyboard::Key::D)
    mMoviment.right = isPressed;
}

void Player::execute() {
  float dt = TimeManager::getInstance().getDeltaTime();

  sf::Vector2f movement(0.f, 0.f);

  // aplica gravidade ao player, aumentando a velocidade vertical do player
  // cada frame
  Physics::applyGravity(&mVelocity);
  if (mRunning)
    mSpeed = 6.3f;
  else
    mSpeed = 3.7f;

  if (mMoviment.right) {
    movement.x += mSpeed;
    mSprite.setScale(1.f, 1.f);
  }
  if (mMoviment.left) {
    movement.x -= mSpeed;
    mSprite.setScale(-1.f, 1.f);
  }

  if (mMoviment.up && mOnGround) {
    float jumpForce = 870.f;
    mVelocity.y = -jumpForce;
    mOnGround = false;
  }

  if (!mMoviment.up && mVelocity.y < 0.0f) {
    mVelocity.y *= 0.5;
  }
  if (mMoviment.down) {
    mVelocity.y *= 1.02f;
  }

  movement.y = mVelocity.y * dt;

  // dx = v * dt
  mSprite.move(movement);

  if (mOnGround) {
    mVelocity.y = 0.f;
    mOnGround = true;
  }

  updateAnimation(dt);
}

void Player::bounce() {
  float dt = TimeManager::getInstance().getDeltaTime();
  mVelocity = -mVelocity * 0.2f;
  mSprite.move(mVelocity * dt);
}

void Player::slow() { mVelocity *= 0.3f; }
// atualiza a animacao do player, mudando o frame da sprite a cada 0.1 segundos
// (hard coded)
void Player::updateAnimation(float dt) {
  mAnimationTimer += dt;

  if (mAnimationTimer >= 0.09f) {
    mCurrentFrame.left += 64.f;
    if (mCurrentFrame.left >= (64 * 6)) {
      mCurrentFrame.left = 0;
    }
    mSprite.setTextureRect(mCurrentFrame);
    mAnimationTimer = 0.f;
  }
}
sf::Vector2f Player::getVelocity() { return mVelocity; }
CharacterType Player::getCharacterType() const { return CH_PLAYER; }
