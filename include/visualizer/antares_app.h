//
// Created by Nathaniel Smith on 11/12/20.
//

#pragma once

#include <cinder/app/App.h>
#include <cinder/app/RendererGl.h>

#include "core/world_model.h"


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

        const double kWindowSize = 650;
        const double kMargin = 100;

    private:

        antares::models::Map map_;

        static const std::string kMapPath;

        static const ci::Color kTextColor;

        static const ci::Color8u kBackgroundColor;
    };

} //namespace visualizer

} //namespace antares