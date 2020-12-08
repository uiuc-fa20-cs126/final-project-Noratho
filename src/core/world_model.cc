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
    UpdatePlayer();
}

void World::GenerateWorld() {
    std::vector<float> window_size{kWindowLength, kWindowHeight};

    world_.SetGravity(kGravity);
    map_->GenerateMap(world_, kPixelsPerMeterFactor, window_size);
    player_->GeneratePlayer(world_, kPixelsPerMeterFactor, kPlayerJsonPath, window_size);
}

void World::UpdateAirStatus() {
    float altitude = player_->GetPosition().y * kPixelsPerMeterFactor;
    float altitude2 = player_->GetPosition().x * kPixelsPerMeterFactor;
    float height = map_->GetKGroundHeight();

    if (altitude < kWindowHeight - height - 21.0f) {
        player_->SetIsInAir(true);
    } else {
        player_->SetIsInAir(false);
    }

}

void World::UpdatePlayer() {
    player_->SetPosition(player_->GetPlayerBody()->GetPosition());
    UpdateAirStatus();
}


} //namespace models

} //namespace antares
