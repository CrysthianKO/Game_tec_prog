#pragma once
#include <string>
#include <map>

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
		std::map<Identifier, ResourceType*> mResourceMap;
	};

	template<typename ResourceType, typename Identifier>
	bool ResourceManager<ResourceType, Identifier>::load(const Identifier& id, const std::string& filename)
	{
		if (mResources.find(id) != mResources.end()) {
			std::count << "Resource with ID " << id << " already loaded." << std::endl;
			return false;
		}

		auto resource = new ResourceType(); //trocar auto para c++2003
		if (!resource->loadFromFile(filename)) {
			std::cout << "Failed to load resource from " << filename << std::endl;
			delete resource;
			return false;
		}

		mResourcesMap.insert(std::make_pair(id, resource));
		return true;
	}

	template<typename ResourceType, typename Identifier>
	ResourceType* ResourceManager<ResourceType, Identifier>::get(const Identifier& id) const
	{
		auto it = mResourcesMap.find(id); //trocar auto
		if (it != mResourcesMap.end()) {
			return it->second;
		}
		std::count << "Resource with ID " << id << " not found." << std::endl;
		return NULL;
	}

	template<typename ResourceType, typename Identifier>
	bool ResourceManager<ResourceType, Identifier>::exists(const Identifier& id) const
	{
		return mResourcesMap.find(id) != mResourcesMap.end();
	}

	template<typename ResourceType, typename Identifier>
	void ResourceManager<ResourceType, Identifier>::clear()
	{
		std::map<Identifier, ResourceType*>::iterator it = mResourcesMap.begin();
		while (it != mResourcesMap.end()) {
			delete it->second;
			++it;
		}
		mResourcesMap.clear();
	}


