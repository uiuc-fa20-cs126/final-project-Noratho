//
// Created by Nathaniel Smith on 11/16/20.
//
#pragma once

#include "core/world_model.h"
#include "visualizer_helpers.h"

namespace antares {

namespace visualizer {

/**
 * CinderWorld Class
 * Used render and make all of the visuals for the game
*/
class CinderWorld {

public:

    /**default constructor*/
    CinderWorld();

    /**copy constructor*/
    CinderWorld(const models::World &world);

    /**
    * Updates the state for of the container model
    */
    void UpdateState();

    /**
    * Renders the current state of the model
    */
    void Render() const;

    /** container model for the game */
    models::World world_model_;

};

} //namespace visualizer

} //namespace antares
