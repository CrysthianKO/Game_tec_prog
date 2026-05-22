#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Personagem.hpp"

class Player : public Personagem {
 public:
  Player();
  virtual ~Player() override;
  void handleInput(sf::Keyboard::Key key, bool isPressed);
  virtual void update(sf::Time dt) override;
  //virtual void draw(sf::RenderWindow* window) override;
  void updateAnimation(sf::Time dt);
  virtual sf::FloatRect getBounds() const override;

  virtual PersonagemType getPersonagemType() const override;


 private:
  //sf::Sprite mSprite; //herdado de Ente
  sf::IntRect mCurrentFrame;
  sf::Texture mTexture;

  bool mIsMovingUp = false;
  bool mIsMovingDown = false;
  bool mIsMovingLeft = false;
  bool mIsMovingRight = false;
  const float mPlayerSpeed = 500.f;
  sf::Time mAnimationTimer = sf::Time::Zero;
  sf::Vector2f mVelocity{ 0.f, 0.f };
  bool mIsGrounded = false;
};
