#pragma once

#include <fstream>
#include <iostream>
#include <sstream> //std::stringstream

#include "glad/glad.h" 
#include "./../glad.c"

const GLchar* read_from_file(const GLchar* pathToFile)
{
    std::string content;
    std::ifstream fileStream(pathToFile, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << pathToFile << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    
    return content.c_str();
}

void create_shader_programs () {
    const GLchar* vertex_shader_data;
    
    vertex_shader_data = read_from_file("C:/Users/RyDaw/Documents/poneros/src/shaders/shader.vert");
    
    std::cout << vertex_shader_data << std::endl;
    
    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_data, NULL);
    glCompileShader(vertex_shader);
}

void render () {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}