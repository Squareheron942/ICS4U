#pragma once

#include <unordered_map>
#include <utility>
#include "script.h"
#include "entt.hpp"
#include <stdio.h>
#include "gameobject.h"
#include "console.h"
#include <string>


class ComponentManager {
    ComponentManager() {}
    template<typename T> static Script* createScriptInstance(GameObject& owner) { return new T(owner); }
    template<typename T> static void createComponentInstance(GameObject& obj, const void* data) { obj.reg.emplace_or_replace<T>(obj.id, obj, data); }
    
    public:
    /**
     * @brief Register component to component manager
     * 
     * @tparam T The component class type
     * @param name The name of the component
     * @return true 
     * @return false 
     */
    template<typename T> static bool registerComponent(const char* name) {
        if constexpr (std::is_base_of_v<Script, T>) getScriptMap()[name] = ComponentManager::createScriptInstance<T>;
        else getComponentMap()[name] = ComponentManager::createComponentInstance<T>;
        return true;
    }

    /**
     * @brief Adds a component to a GameObject
     * 
     * @param name Name of the component to add
     * @param obj GameObject to add component to
     * @param data Pointer to struct which contains the parameters
     * @return true 
     * @return false 
     */
    static bool addComponent(const char* name, GameObject& obj, const void* data = NULL);

    /**
     * @brief Add script to GameObject
     * 
     * @param name Name of the script to add
     * @param obj GameObject to add the script to
     * @return true 
     * @return false 
     */
    static bool addScript(const char* name, GameObject& obj);

    private:
        // Use Meyer's singleton to prevent SIOF
        static std::unordered_map<std::string, Script*(*)(GameObject&)>& getScriptMap() { static std::unordered_map<std::string, Script*(*)(GameObject&)> map; return map; }
        static std::unordered_map<std::string, void(*)(GameObject&, const void*)>& getComponentMap() { static std::unordered_map<std::string, void(*)(GameObject&, const void*)> map; return map; }
};

#define COMPONENT_REGISTER(component) bool component ## _component = ComponentManager::registerComponent<component>(#component);