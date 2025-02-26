// System includes
#define GLFW_INCLUDE_NONE

#include <windows.h>
#include <iostream>
#include <vector>

// Project includes
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

// Engine includes
#include "game_state.h"
#include "render.h"

// Move this to input.
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
};

GameState* game_state = new(GameState);

int main () {
    init_render();

    glfwSwapInterval(1);
    glfwSetKeyCallback(game_state->window, key_callback);


    while (!glfwWindowShouldClose(game_state->window)) {
        glfwPollEvents();
        render();

    }

    glfwDestroyWindow(game_state->window);
    glfwTerminate();

    return 0;
}
