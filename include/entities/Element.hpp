#pragma once
#include <cstddef>

namespace DinoGame {
namespace Lists {

template <class TYPE>
class Element {
 private:
  Element<TYPE>* pNext;
  TYPE* pInfo;

 public:
  Element() : pNext(NULL), pInfo(NULL) {}
  ~Element() {}

  void setNext(Element<TYPE>* pE) { pNext = pE; }
  Element<TYPE>* getNext() { return pNext; }

  void setInfo(TYPE* pI) { pInfo = pI; }
  TYPE* getInfo() { return pInfo; }
};

}  // namespace Lists
}  // namespace DinoGame
