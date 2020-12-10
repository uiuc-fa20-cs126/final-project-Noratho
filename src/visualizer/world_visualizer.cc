//
// Created by Nathaniel Smith on 11/16/20.
//

#include "visualizer/world_visualizer.h"

namespace antares {

namespace visualizer {

    visualizer::CinderWorld::CinderWorld() {

    }

    visualizer::CinderWorld::CinderWorld(const models::World &world) {

    }

    void visualizer::CinderWorld::UpdateState() {
        world_model_.UpdateState();
    }

    void visualizer::CinderWorld::Render() const {

        //draws the fixtures of the game
        int color_differentiator = 0;
        for (const b2Body* body = world_model_.world_.GetBodyList(); body; body = body->GetNext()) {
            DrawPolygon(body, world_model_.kPixelsPerMeterFactor,
                        ci::Color8u(255 - color_differentiator , color_differentiator, 150));
            color_differentiator = 75;
        }
    }

} //namespace visualizer

} //namespace antares