#include "entities/characters/Player.hpp"

#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/Rect.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include "entities/characters/Enemy.hpp"
#include "managers/Physics.hpp"
#include "managers/TimeManager.hpp"

namespace DinoGame {
namespace Entities {
namespace Characters {

class Enemy;

Player::Player()
    : mAnimationTimer(0.f),
      mConfig(),
      mDamageTimer(0.f),
      mMoviment(),
      mRunning(false),
      score(0) {}

Player::Player(int playerNum) : mConfig(), mMoviment(), score(0) {
  if (playerNum == 1) {
    mConfig.jump = sf::Keyboard::Space;
    mConfig.run = sf::Keyboard::LShift;
    mConfig.up = sf::Keyboard::W;
    mConfig.down = sf::Keyboard::S;
    mConfig.left = sf::Keyboard::A;
    mConfig.right = sf::Keyboard::D;
  } else if (playerNum == 2) {
    mConfig.jump = sf::Keyboard::RControl;
    mConfig.run = sf::Keyboard::RShift;
    mConfig.up = sf::Keyboard::Up;
    mConfig.down = sf::Keyboard::Down;
    mConfig.left = sf::Keyboard::Left;
    mConfig.right = sf::Keyboard::Right;
  }
}

Player::~Player() {}

void Player::setup() {
  mRunning = false;
  mNumberLives = 1929;

  mAnimationTimer = 0.0f;
  mDamageTimer = 0.0f;

  mVelocity.x = 0.f;
  mVelocity.y = 0.f;

  mMoviment.up = false;
  mMoviment.down = false;
  mMoviment.right = false;
  mMoviment.left = false;

  mCurrentFrame = sf::IntRect({0, 0}, {64, 64});
  this->setTexture("PLAYER_TEXTURE");
  // TEXTURA DE USO AUTORAL
  mSprite.setPosition(0.f, 0.f);
  mSprite.setTextureRect(sf::IntRect({0, 0}, {64, 64}));
  mSprite.setOrigin(32.f, 32.f);
}

void Player::save() {}
void Player::move(sf::Vector2f move) { mSprite.move(move); }
void Player::handleInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == mConfig.run) mRunning = isPressed;

  if (key == mConfig.up)
    mMoviment.up = isPressed;
  else if (key == mConfig.down)
    mMoviment.down = isPressed;
  else if (key == mConfig.left)
    mMoviment.left = isPressed;
  else if (key == mConfig.right)
    mMoviment.right = isPressed;
}

void Player::execute() {
  float dt = pTM->getDeltaTime();
  sf::Vector2f moviment(0.f, 0.f);

  // aplica gravidade ao player, aumentando a velocidade vertical do player
  // cada frame
  if (mNumberLives <= 0) {
    mSprite.setPosition(-1111.f, -1111.f);
    return;
  }

  pPhysics->applyGravity(mVelocity);

  if (mDamageTimer > 0.f) {
    moviment.x = mVelocity.x;
    mDamageTimer -= dt;
    mSprite.setColor(sf::Color::Red);
  } else {
    mSprite.setColor(sf::Color::White);
    if (mRunning)
      // mSpeed = 6.3f;
      mSpeed = 16.f;
    else
      mSpeed = 3.7f;

    if (mMoviment.right) {
      moviment.x += mSpeed;
      mSprite.setScale(1.f, 1.f);
    }
    if (mMoviment.left) {
      moviment.x -= mSpeed;
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

    // dx = v * dt
  }
  moviment.y = mVelocity.y * dt;

  mSprite.move(moviment);

  if (mOnGround) {
    mVelocity.y = 0.f;
    mOnGround = true;
  }

  updateAnimation(dt);
}

void Player::takeDamage(int damage, float directionX) {
  if (mDamageTimer > 0.f) return;

  mNumberLives -= damage;

  mDamageTimer = 0.3f;

  mVelocity.y = -580.f;
  mVelocity.x = 2.8f * directionX;

  mOnGround = false;
}

void Player::collide(Enemy* pEnemy) {
  sf::FloatRect intercession;
  mSprite.getGlobalBounds().intersects(pEnemy->getGlobalBounds(), intercession);

  bool verticalCollision = intercession.width > intercession.height;
  if (verticalCollision) {  // Colidiu verticalmente
    if (mVelocity.y > 0.f &&
        mSprite.getPosition().y < pEnemy->getPosition().y) {
      pEnemy->damage();
      mSprite.move(sf::Vector2f(0.f, -intercession.height));
      bounce();
      score += 1;
    }
  } else {  // colidiu pelos lados
    int damage = pEnemy->getBadLevel();
    if (mSprite.getPosition().x < pEnemy->getPosition().x) {
      takeDamage(damage, -1);
    } else {
      takeDamage(damage, 1);
    }
  }
}

void Player::slow() { mVelocity *= 0.3f; }

void Player::bounce() { mVelocity.y = -600.f; }
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
void Player::setScore(int s) { score = s; }
int Player::getScore() const { return score; }
sf::Vector2f Player::getVelocity() { return mVelocity; }

}  // namespace Characters
}  // namespace Entities
}  // namespace DinoGame
