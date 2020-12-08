//
// Created by Nathaniel Smith on 11/12/20.
//

#pragma once

#include <nlohmann/json.hpp>

#include <Box2D/Box2D.h>
#include <cinder/Color.h>

#include "player_model.h"
#include "map_model.h"

namespace antares {

namespace models {

    class World {


    public:

        World();

        World(Map *map, Player *player);

        void GenerateWorld();

        void UpdateState();

        void UpdatePlayer();

        void UpdateAirStatus();

        b2World world_ = b2World(kGravity);

        const float kPixelsPerMeterFactor = 50.0f;

        Map *map_;

        Player *player_;

    private:

        const float kTimeStep = 1.0f / 60.0f;

        const int32 kVelocityIterations = 6;
        const int32 kPositionIterations = 2;

        const b2Vec2 kGravity = b2Vec2(0.0f, 30.0f);

        const float kWindowLength = 600;
        const float kWindowHeight = 400;

        static const std::string kPlayerJsonPath;


    };

} //namespace models

} //namespace antares

