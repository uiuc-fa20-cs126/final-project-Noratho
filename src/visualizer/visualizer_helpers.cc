//
// Created by Nathaniel Smith on 11/21/20.
//

#include "visualizer/visualizer_helpers.h"
#include <cinder/Color.h>
#include <cinder/PolyLine.h>
#include <glm/glm.hpp>
#include "cinder/gl/gl.h"

namespace antares {

namespace visualizer {

    void DrawPolygon(const b2Body *body, float pixels_per_meter_factor,  const ci::Color8u& color) {

        b2Vec2 pos = body->GetPosition();
        //iterate through all of the fixtures for a body
        for (const b2Fixture* fixture = body->GetFixtureList(); fixture; fixture = fixture->GetNext()) {

            b2Shape::Type shape_type = fixture->GetType();

            //logic for polygons
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
                ci::gl::color(ci::Color8u(0, 0, 0));
                ci::gl::draw(poly_line);
            }

            //logic for circles
            if (shape_type == b2Shape::e_circle) {

                b2CircleShape* circle = (b2CircleShape*)fixture->GetShape();

                ci::vec2 center((circle->m_p.x + pos.x) * pixels_per_meter_factor,
                                (2 * (circle->m_p.y) + pos.y) * pixels_per_meter_factor);

                //extract user data
                std::vector<int>* rgb = (std::vector<int>*)fixture->GetUserData();

                ci::gl::color( ci::Color( rgb->at(0),
                                          rgb->at(1),
                                          rgb->at(2) ) );;

                ci::gl::drawSolidCircle(center, circle->m_radius * pixels_per_meter_factor);
            }
        }
    }

} //namespace visualizer

} //namespace antares
