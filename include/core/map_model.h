//
// Created by Nathaniel Smith on 12/6/20.
//
#pragma once

#include <Box2D/Box2D.h>
#include <string>
#include <vector>

namespace antares {

namespace models {

/**
* Map Class
* Stores data for the map
*/
    class Map {

    public:

        /**Default constructor*/
        Map();
        /**
         * Method that generates the map and attaches it to the world as a fixed body
         * @param world the world to fix the map bodies to
         * @param pixel_per_meter_factor the factor to downscale the physics value for better running
         * @param window_size the size of the window
        */

        void GenerateMap(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size);

        /**Getters and setters*/
        float GetKGroundHeight() const;

    private:

        /**Height of the ground in pixels*/
        const float kGroundHeight = 10.0f;

    };

} //namespace models

} //namespace antares
