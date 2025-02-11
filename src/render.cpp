#pragma once

#include "render.h"
#include "file_utils.h"

Vertex TEST_VERTS[] = {
    {{-.5, -.5, .0}},
    {{ .5, -.5, .0}},
    {{ .0,  .5, .0}},
};

Mesh TEST_MESH = {
    .vertex_data    = TEST_VERTS,
    .vertex_count   = 3
};

Model TEST_MODEL = {
    .mesh_data = &TEST_MESH,
    .instances = {
        {}
    }
};


void init_render () {
    create_renderer();    
    create_window();
    create_shader_program();
    
};

void create_window () {
    if (!glfwInit()) {
        printf("GLFW Init failed\n");
    }  
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4); 
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    game_state->window = glfwCreateWindow(640, 480, "Poneros", NULL, NULL); 
    
    glfwMakeContextCurrent(game_state->window);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }   
    
    return;
}

void create_renderer () {
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
    glfwSwapBuffers(game_state->window);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void create_model (Mesh* mesh) {
    
}