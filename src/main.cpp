// System includes
#define GLFW_INCLUDE_NONE

#include <windows.h>
#include <iostream>
#include <vector>

// Project includes
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

// Engine includes
#include "string_utils.h"
#include "file_utils.h"
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
    std::cout << "Poneros\n";
    
    if (!glfwInit()) {
        printf("GLFW Init failed\n");
    }  
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    GLFWwindow* window = glfwCreateWindow(640, 480, "Poneros", NULL, NULL); 
    
    glfwMakeContextCurrent(window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }   
    
    glfwSwapInterval(1);
    
    glfwSetKeyCallback(window, key_callback);
    
    init_render();
    
    while (!glfwWindowShouldClose(window)) {
        
        glfwPollEvents();
        glfwSwapBuffers(window);
        
        render();
    } 
    
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return 0;
}   