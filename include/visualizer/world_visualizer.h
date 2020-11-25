//
// Created by Nathaniel Smith on 11/16/20.
//
#pragma once

#include "core/world_model.h"
#include "visualizer_helpers.h"

namespace antares {

namespace visualizer {

class CinderMap {


public:

    CinderMap();

    CinderMap(const models::World &world);

    /**
    * Updates the state for of the container model
    */
    void UpdateState();

    /**
    * Renders the current state of the model
    */
    void Render() const;

    /**
    * Resets the state of the model
     * Not implemented :(
    */
    void Reset();

    /** container model for the particles */

    models::World world_model_;

};

} //namespace visualizer

} //namespace antares