#include <GLFW/glfw3.h>
#include "world.hpp"
#include "systems.hpp"
#include "components.hpp"

using namespace ecs;

int main() {
  if (!glfwInit()) return -1;

  GLFWwindow* window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL);
  if (!window) {
      glfwTerminate();
      return -1;
  }
  glfwMakeContextCurrent(window);

  World world;
  RenderSystem renderer;


  Entity e1 = world.createEntity();
  world.addComponent(e1, Position{-0.3f, -0.3f});
  world.addComponent(e1, Sprite{"", 0.2f, 0.2f});


  while (!glfwWindowShouldClose(window)) {
      glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
      glClear(GL_COLOR_BUFFER_BIT);

      renderer.render(world);

      glfwSwapBuffers(window);
      glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}