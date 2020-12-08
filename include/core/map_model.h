//
// Created by Nathaniel Smith on 12/6/20.
//
#pragma once

#include <Box2D/Box2D.h>
#include <string>
#include <vector>

namespace antares {

namespace models {


    class Map {

    public:

        Map();

        Map(std::string json_path);

        std::string map_json_path_;

        void DeserializeJson();

        void GenerateMap(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size);

        float GetKGroundHeight() const;

    private:

        const float kGroundHeight = 10.0f;

    };


} //namespace models

} //namespace antares
