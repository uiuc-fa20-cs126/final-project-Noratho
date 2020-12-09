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

    /**
     * World Class
     * Used to model the overall world for the game
    */
    class World {

    public:

        /**Default constructor*/
        World();

        /**constructor with map and player*/
        World(Map *map, Player *player);

        /**Method that generates the world*/
        void GenerateWorld();

        /**Method that updates the state of the world*/
        void UpdateState();

        /**Method that updates the state of the player*/
        void UpdatePlayer();

        /**Method that updates the state of the player's airborness*/
        void UpdateAirStatus();

        /**The physics world*/
        b2World world_ = b2World(kGravity);

        /**Pixels per meter factor*/
        const float kPixelsPerMeterFactor = 50.0f;

        /**Pointer to the map*/
        Map *map_;

        /**Pointer to the player*/
        Player *player_;

    private:

        const float kTimeStep = 1.0f / 60.0f;

        const int32 kVelocityIterations = 6;
        const int32 kPositionIterations = 2;

        /**The strenght of gravity on the world*/
        const b2Vec2 kGravity = b2Vec2(0.0f, 30.0f);

        const float kWindowLength = 600;
        const float kWindowHeight = 400;

        /**The path to the character json*/
        static const std::string kPlayerJsonPath;


    };

} //namespace models

} //namespace antares

