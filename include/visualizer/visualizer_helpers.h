//
// Created by Nathaniel Smith on 11/21/20.
//

#pragma once

#include <Box2D/Box2D.h>
#include <cinder/Color.h>

namespace antares {

namespace visualizer {

    void DrawPolygon(const b2Body *body, float pixels_per_meter_factor, const ci::Color8u& color);


} //namespace visualizer

} //namespace antares
