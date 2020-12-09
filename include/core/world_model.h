//
// Created by Nathaniel Smith on 11/12/20.
//

#pragma once

#include <nlohmann/json.hpp>

#include <Box2D/Box2D.h>
#include <cinder/Color.h>

#include "player_model.h"

namespace antares {

namespace models {

    class Map {

    public:

        Map();

        Map(std::string json_path);

        std::string map_json_path_;

        void DeserializeJson();

        void GenerateMap(b2World &world, float pixel_per_meter_factor);

    private:

        const double kWindowLength = 600;
        const double kWindowHeight = 400;

    };


    class World {


    public:

        World();

        World(Map *map, Player *player);

        void GenerateWorld();

        void UpdateState();

        b2World world_ = b2World(kGravity);

        const float kPixelsPerMeterFactor = 50.0f;

        Map *map_;

        Player *player_;


    private:

        const float kTimeStep = 1.0f / 60.0f;

        const int32 kVelocityIterations = 6;
        const int32 kPositionIterations = 2;

        const b2Vec2 kGravity = b2Vec2(0.0f, 30.0f);

        const double kWindowLength = 600;
        const double kWindowHeight = 400;


    };

} //namespace models

} //namespace antares

