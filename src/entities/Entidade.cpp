#include "Entidade.hpp"

int Entidade::cont_id = 0;

Entidade::Entidade() : mId(cont_id++) {
	
}

Entidade::~Entidade(){

}

int Entidade::getId() const {
	return mId;
}

void Entidade::setId(int id) {
	mId = id;
}