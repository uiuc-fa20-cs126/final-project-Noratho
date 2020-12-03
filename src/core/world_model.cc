//
// Created by Nathaniel Smith on 11/12/20.
//

#include "core/world_model.h"

namespace antares {

namespace models {


Map::Map() {

}

Map::Map(std::string json_path) {

}

void Map::DeserializeJson() {

}

void Map::GenerateWorld() {
    CreateMap();
}

void Map::CreateMap() {

    b2BodyDef ground_body_def;
    ground_body_def.position.Set(0.0f, -10.0f);
    ground_box_.SetAsBox(50.0f, 10.0f);
    ground_body_ = world_.CreateBody(&ground_body_def);
    ground_body_->CreateFixture(&ground_box_, 0.0f);

}

} //namespace models

} //namespace antares
