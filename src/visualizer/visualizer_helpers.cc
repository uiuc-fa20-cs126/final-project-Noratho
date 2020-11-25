//
// Created by Nathaniel Smith on 11/21/20.
//

#include "visualizer/visualizer_helpers.h"
#include <cinder/Color.h>
#include <cinder/PolyLine.h>
#include <glm/glm.hpp>
#include "cinder/gl/gl.h"

//make method that draws a polygon when given a body by iterating through the fixtures and getting the vertices
// of the shapes that the fixture binds to the body and drawing them.

namespace antares {

namespace visualizer {


    //add color value to customize
    void DrawPolygon(const b2Body *body, float pixels_per_meter_factor,  const ci::Color8u& color) {

        b2Vec2 pos = body->GetPosition();
        std::cout << pos.x << " " << pos.y << std::endl;
        for (const b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {

            b2Shape::Type shape_type = fixture->GetType();

            if (shape_type == b2Shape::e_polygon ) {

                b2PolygonShape* polygon = (b2PolygonShape*)fixture->GetShape();

                ci::PolyLine2f poly_line;

                for (int vertex_index = 0; vertex_index < polygon->GetVertexCount(); vertex_index++) {

                    b2Vec2 b2_vertex = polygon->GetVertex(vertex_index);
                    glm::vec2 glm_vertex;

                    glm_vertex.x = (b2_vertex.x + pos.x) * pixels_per_meter_factor;
                    glm_vertex.y = (b2_vertex.y + pos.y) * pixels_per_meter_factor;

                    poly_line.push_back(glm_vertex);
                }

                ci::gl::color(color);

                ci::gl::drawSolid(poly_line);


            }
        }

    }



} //namespace visualizer

} //namespace antares
