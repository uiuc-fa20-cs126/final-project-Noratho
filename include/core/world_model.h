//
// Created by Nathaniel Smith on 11/12/20.
//

#pragma once



#include <nlohmann/json.hpp>

#include <Box2D/Box2D.h>
#include <cinder/Color.h>

namespace antares {

namespace models {

    class Map {

    public:

        Map();

        Map(std::string json_path);

        std::string map_json_path_;

        void DeserializeJson();

        void GenerateWorld();

        void CreateMap();

        b2Body* ground_body_;

        b2PolygonShape ground_box_;


    private:

        const b2Vec2 kGravity = b2Vec2(0.0f, -10.0f);

        b2World world_ = b2World(kGravity);

    };

} //namespace models

} //namespace antares

