//
// Created by Nathaniel Smith on 11/12/20.
//

#include <visualizer/antares_app.h>

using antares::visualizer::AntaresApp;

void prepareSettings(AntaresApp::Settings* settings) {
    settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(AntaresApp, ci::app::RendererGl, prepareSettings);