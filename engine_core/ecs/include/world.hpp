#pragma once
#include <unordered_map>
#include <vector>
#include <cstdint>
#include "components.hpp"

using Entity = std::uint32_t;

namespace ecs {
  class World {
    public:
        Entity createEntity() {
            Entity e = nextId++;
            return e;
        }
    
        void addComponent(Entity e, const Position& p) { positions[e] = p; }
        void addComponent(Entity e, const Sprite& s) { sprites[e] = s; }
    
        Position& getPosition(Entity e) { return positions[e]; }
        Sprite& getSprite(Entity e) { return sprites[e]; }
    
        std::vector<Entity> getEntities() {
            std::vector<Entity> ents;
            for (auto& [e, _] : positions) {
                if (sprites.find(e) != sprites.end())
                    ents.push_back(e);
            }
            return ents;
        }

    private:
        Entity nextId = 0;
        std::unordered_map<Entity, Position> positions;
        std::unordered_map<Entity, Sprite> sprites;
  };
}