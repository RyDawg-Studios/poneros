#pragma once

#include "glad/glad.h" 
#include "vector"
#include "game_state.h"
#include "GLFW/glfw3.h"

#include <glm/ext/vector_float3.hpp>

extern GameState* game_state;


struct Vertex {
    glm::vec3 position  = {.0f, .0f, .0f};
    glm::vec3 normal    = {.0f, .0f, .0f};
};

struct Mesh {
    Vertex* vertex_data  = nullptr;
    int32_t vertex_count = 0;
    
    uint32_t*   element_data  = nullptr;
    int32_t     element_count = 0;
};

struct MeshInstance {
    glm::vec3 position = {0, 0, 0};
    // This should eventually hold a pointer to the
    // Entity that will be rendered here.
    
    // Or, use the Entity ID system from JDE
};

struct Model {
    Mesh* mesh_data;
    std::vector<MeshInstance> instances; 
};

struct RenderHandle {
    unsigned int shader_program;
    Model models[];
};

// Render Pipeline
void init_render ();
void create_window ();
void create_renderer ();
void create_shader_program ();
void render ();

// Model Utility
void create_model (Mesh* mesh); 
