#include "Camera.hpp"

Camera::Camera() : mTarget({ 0.f, 0.f }), mView()
{
}

Camera::~Camera()
{
}

void Camera::setTarget(const sf::Vector2f& target)
{
	mTarget = target;
}

const sf::Vector2f Camera::getTarget() const
{
	return mTarget;
}

void Camera::move(const sf::Vector2f& offset)
{
	mTarget += offset;
}

sf::View Camera::getView(const sf::Vector2u& virtualSize) const
{
	float halfWidth = virtualSize.x / 2.f;
	float halfHeight = virtualSize.y / 2.f;
	
	sf::View localView;
	localView.setSize(sf::Vector2f(static_cast<float>(virtualSize.x), static_cast<float>(virtualSize.y)));

	sf::Vector2f centerPosition(mTarget.x + halfWidth, mTarget.y + halfHeight);
	localView.setCenter(centerPosition);
	return localView;
}
