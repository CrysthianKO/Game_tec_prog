#include "LaserBall.hpp"

LaserBall::LaserBall(){

}

LaserBall::~LaserBall(){

}

void LaserBall::update(sf::Time deltaTime){

}

//void LaserBall::draw(sf::RenderWindow* window){
//
//}

sf::FloatRect LaserBall::getBounds() const{
	//temporiariamente retorna um retângulo vazio, já que a laser ball ainda não tem uma sprite ou forma definida
	return sf::FloatRect();
}

ProjectableType LaserBall::getProjectableType() const{
	return ProjectableType::PJ_LASERBALL;
}
