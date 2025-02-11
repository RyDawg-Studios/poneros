#pragma once
#include "GLFW/glfw3.h"

struct RenderHandle;

struct GameState {
    struct RenderHandle* render_handle = nullptr;
    GLFWwindow* window = nullptr;
};