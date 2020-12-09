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

void Map::GenerateMap(b2World &world, float pixel_per_meter_factor) {

    float meter_per_pixel_factor = (1.0f / pixel_per_meter_factor);

    //multiply values shown by pixels per meter factor to shrink down

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(kWindowLength / 2.0f * meter_per_pixel_factor,
                         kWindowHeight / 2.0f * meter_per_pixel_factor);
    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f * meter_per_pixel_factor, 10.0f * meter_per_pixel_factor);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

    b2BodyDef ground_body_def;
    ground_body_def.position.Set(kWindowLength / 2.0f * meter_per_pixel_factor,
                                 (kWindowHeight - 10) * meter_per_pixel_factor);
    b2PolygonShape ground_box;
    ground_box.SetAsBox(50.0f * meter_per_pixel_factor, 10.0f * meter_per_pixel_factor);
    b2Body* ground_body = world.CreateBody(&ground_body_def);
    ground_body->CreateFixture(&ground_box, 0.0f);



}

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
    world_.SetGravity(kGravity);
    map_->GenerateMap(world_, kPixelsPerMeterFactor);
}


} //namespace models

} //namespace antares
