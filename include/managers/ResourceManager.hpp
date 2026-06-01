#pragma once
#include <iostream>
#include <map>
#include <string>

using namespace std;
template <typename ResourceType, typename Identifier>
class ResourceManager {
 public:
  ResourceManager() {}
  ~ResourceManager() { clear(); }
  bool load(const Identifier& id, const std::string& filename);
  ResourceType* get(const Identifier& id) const;
  bool exists(const Identifier& id) const;
  void clear();

 private:
  map<Identifier, ResourceType*> mResourceMap;
};

template <typename ResourceType, typename Identifier>
bool ResourceManager<ResourceType, Identifier>::load(
    const Identifier& id, const std::string& filename) {
  if (mResourceMap.find(id) != mResourceMap.end()) {
    cout << "Recurso com o ID " << id << " ja carregado." << endl;
    return false;
  }

  ResourceType* resource = new ResourceType();
  if (!resource->loadFromFile(filename)) {
    cout << "Falha ao carregar arquivo do diretório " << filename << std::endl;
    delete resource;
    return false;
  }

  mResourceMap.insert(std::make_pair(id, resource));
  return true;
}

template <typename ResourceType, typename Identifier>
ResourceType* ResourceManager<ResourceType, Identifier>::get(
    const Identifier& id) const {
  class map<Identifier, ResourceType*>::const_iterator it =
      mResourceMap.find(id);
  if (it != mResourceMap.end()) {
    return it->second;
  }
  cout << "Recurso com o ID " << id << " nao encontrado." << endl;
  return NULL;
}

template <typename ResourceType, typename Identifier>
bool ResourceManager<ResourceType, Identifier>::exists(
    const Identifier& id) const {
  return mResourceMap.find(id) != mResourceMap.end();
}

template <typename ResourceType, typename Identifier>
void ResourceManager<ResourceType, Identifier>::clear() {
  class map<Identifier, ResourceType*>::iterator it = mResourceMap.begin();
  while (it != mResourceMap.end()) {
    delete it->second;
    ++it;
  }
  mResourceMap.clear();
}
