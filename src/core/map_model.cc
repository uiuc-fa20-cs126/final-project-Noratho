//
// Created by Nathaniel Smith on 12/6/20.
//
#include <iostream>
#include "core/map_model.h"


namespace antares {

namespace models {

Map::Map() {

}

Map::Map(std::string json_path) {

}

void Map::DeserializeJson() {

}

void Map::GenerateMap(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size) {

    float meter_per_pixel_factor = (1.0f / pixel_per_meter_factor);

    float window_length = window_size[0];
    float window_height = window_size[1];

    //multiply values shown by pixels per meter factor to shrink down

    //    b2Vec2 throw_test = b2Vec2(1, 1);
    //
    //    body->SetLinearVelocity(throw_test);

    //Bottom platform

    b2BodyDef ground_body_def;
    ground_body_def.position.Set(window_length / 2.0f * meter_per_pixel_factor,
                                     (window_height - kGroundHeight) * meter_per_pixel_factor);
    b2PolygonShape ground_box;
    ground_box.SetAsBox((window_length/2) * meter_per_pixel_factor, kGroundHeight * meter_per_pixel_factor);
    b2Body* ground_body = world.CreateBody(&ground_body_def);
    ground_body->CreateFixture(&ground_box, 0.0f);
}

float Map::GetKGroundHeight() const {
    return kGroundHeight;
}


} //namespace models

} //namespace antares
