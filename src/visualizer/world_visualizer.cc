//
// Created by Nathaniel Smith on 11/16/20.
//

#include "visualizer/world_visualizer.h"

namespace antares {

namespace visualizer {

    visualizer::CinderMap::CinderMap() {

    }

    visualizer::CinderMap::CinderMap(const models::World &world) {

    }

    void visualizer::CinderMap::UpdateState() {
        world_model_.UpdateState();
    }

    void visualizer::CinderMap::Render() const {

        int color_differentiator = 0;
        for (const b2Body* body = world_model_.world_.GetBodyList(); body; body = body->GetNext()) {
            DrawPolygon(body, world_model_.kPixelsPerMeterFactor,
                        ci::Color8u(255 - color_differentiator , color_differentiator, 150));
            color_differentiator = 75;
        }
    }

    void visualizer::CinderMap::Reset() {

    }

} //namespace visualizer

} //namespace antares