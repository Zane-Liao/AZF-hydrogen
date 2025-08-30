#pragma once
#include "world.hpp"
#include "components.hpp"
#include <GLFW/glfw3.h>
// #include <GL/gl.h>
#include <iostream>

namespace ecs {
class RenderSystem {
public:
    void render(World& world) {
        for (auto e : world.getEntities()) {
            auto& pos = world.getPosition(e);
            auto& spr = world.getSprite(e);

            glBegin(GL_QUADS);
                glColor3f(1.0f, 0.0f, 0.0f);
                glVertex2f(pos.x, pos.y);
                glVertex2f(pos.x + spr.width, pos.y);
                glVertex2f(pos.x + spr.width, pos.y + spr.height);
                glVertex2f(pos.x, pos.y + spr.height);
            glEnd();
        }
        // glBegin(GL_TRIANGLES);
        //     glColor3f(0.0f, 1.0f, 0.0f);
        //     glVertex2f(-0.5f, -0.5f);
        //     glVertex2f(0.5f, -0.5f);
        //     glVertex2f(0.0f, 0.5f);
        // glEnd();
        glBegin(GL_TRIANGLES);
            glColor3f(1.0f, 0.0f, 0.0f); // Red
            glVertex2f(-0.5f, -0.5f);

            glColor3f(0.0f, 1.0f, 0.0f); // Green
            glVertex2f(0.5f, -0.5f);

            glColor3f(0.0f, 0.0f, 1.0f); // Blue
            glVertex2f(0.0f, 0.5f);
        glEnd();
    }
  };
}