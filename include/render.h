#pragma once

#include "glad/glad.h" 
#include "vector"
#include "game_state.h"

#include <glm/ext/vector_float3.hpp>

extern GameState* game_state;

struct RenderHandle {
    unsigned int shader_program;
};

struct Vertex {
    glm::vec3 pos;
    glm::vec3 color; 
};

struct Mesh {
    std::vector<Vertex>* vertex_data;
    std::vector<uint32_t>*  element_data;
};


void init_render();
void create_renderer();
void create_shader_program();
void render();
