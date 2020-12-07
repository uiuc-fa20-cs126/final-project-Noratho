//
// Created by Nathaniel Smith on 11/12/20.
//

#include <fstream>
#include "core/world_model.h"

namespace antares {

namespace models {

const std::string World::kPlayerJsonPath =
        "resources/character_json/player.json";

World::World() {

    Map *empty_map = new Map();
    Player *empty_player = new Player();

    map_ = empty_map;
    player_ = empty_player;
}

World::World(Map *map, Player *player) {
    map_ = map;
    player_ = player;
}

void World::UpdateState() {
    world_.Step(kTimeStep, kVelocityIterations, kPositionIterations);
}

void World::GenerateWorld() {
    std::vector<float> window_size{kWindowLength, kWindowHeight};

    world_.SetGravity(kGravity);
    map_->GenerateMap(world_, kPixelsPerMeterFactor, window_size);
    player_->GeneratePlayer(world_, kPixelsPerMeterFactor, kPlayerJsonPath, window_size);
    std::cout << "good";
}


} //namespace models

} //namespace antares
