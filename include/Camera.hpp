#pragma once
#include <SFML/Graphics.hpp>

class Camera {
private:
    sf::Vector2f mTarget;
	sf::View mView;
public:
    Camera();
    ~Camera();
    
    void setTarget(const sf::Vector2f& target);
	const sf::Vector2f getTarget() const;
	void move(const sf::Vector2f& offset);

    sf::View getView(const sf::Vector2u& virtualSize) const;

};