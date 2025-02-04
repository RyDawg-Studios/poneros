#pragma once

#include "glad/glad.h" 
#include "glad.c"

struct GameState;
extern GameState* game_state;

using namespace glm;

struct RenderHandle {
    unsigned int shader_program;
};

struct Vertex {
    vec3 pos;
    vec3 color; 
};

struct Mesh {
    std::vector<Vertex>* vertex_data;
    std::vector<int32>*  element_data;
};


void init_render();
void create_renderer();
void create_shader_program();
void render();
