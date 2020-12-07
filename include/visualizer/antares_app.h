//
// Created by Nathaniel Smith on 11/12/20.
//

#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "core/world_model.h"
#include "world_visualizer.h"


namespace antares {

namespace visualizer {

/**
* Allows a user to see the true beauty of particle
 * collisions by creating a container to display it
*/
    class AntaresApp : public ci::app::App {
    public:
        AntaresApp();

        void draw() override;
        void update() override;
        void setup() override;
        void keyDown(ci::app::KeyEvent event) override;

        const double kWindowLength = 600;
        const double kWindowHeight = 400;
        const double kMargin = 100;
        const float kPixelsPerMeterFactor = 50.0f;

    private:

        antares::visualizer::CinderMap cinder_map_;

        antares::models::World *world_model_;

        static const std::string kMapPath;

        static const ci::Color kTextColor;

        static const ci::Color8u kBackgroundColor;

        void RemoveDuplicatesHelper(const std::string& input);

        void UpdateInputTimers();

        static const int kFrameInputDuration;

        int input_hold_;
    };

} //namespace visualizer

} //namespace antares