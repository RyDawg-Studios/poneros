// System includes
#include <windows.h>
#include <iostream>
#include <GL/gl.h>

// Project includes
#include "GLFW/glfw3.h"

int main () {
    std::cout << "Poneros";
    
    glfwInit();  
    GLFWwindow* window = glfwCreateWindow(640, 480, "Poneros", NULL, NULL); 
    
    while (!glfwWindowShouldClose(window)) {
        
    } 
    
    glfwDestroyWindow(window);
    
    return 0;
}   