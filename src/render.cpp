#pragma once

#include "render.h"
#include "file_utils.h"


void init_render () {
    create_renderer();    
    create_shader_program();
};

void create_renderer() {
    game_state->render_handle = new(RenderHandle);
}

void create_shader_program () {
    const GLchar* vertex_shader_data = 
        read_from_file("C:/Users/RyDaw/Documents/poneros/src/shaders/shader.vert");
        
    const GLchar* fragment_shader_data = 
        read_from_file("C:/Users/RyDaw/Documents/poneros/src/shaders/shader.frag");
        
    const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_shader_data, NULL);
    glCompileShader(vertex_shader);
    
    const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_shader_data, NULL);
    glCompileShader(fragment_shader);
    
    game_state->render_handle->shader_program = glCreateProgram();
    unsigned int* shader_program = &game_state->render_handle->shader_program; 
    
    glAttachShader(*shader_program, vertex_shader);
    glAttachShader(*shader_program, fragment_shader);
    glLinkProgram(*shader_program);
    glUseProgram(*shader_program);
    
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
    
}

void render () {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}