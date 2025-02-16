#pragma once

#include "glad/glad.h"
#include "vector"
#include "string"
#include "game_state.h"
#include "GLFW/glfw3.h"

#include <glm/ext/vector_float3.hpp>
#include <glm/ext/vector_float2.hpp>

extern GameState* game_state;

struct Vertex {
    glm::vec3 position  = {.0f, .0f, .0f};
    glm::vec3 normal    = {.0f, .0f, .0f};
    glm::vec2 tex_coord = {.0f, .0f};
};

struct MeshNode {
    std::vector<MeshNode>	children;	        // Tree
    std::vector<int>		indices;  	    // Index to the root nodes meshes.				
};

struct Mesh {
    Vertex* vertex_data  = nullptr;
    int32_t vertex_count = 0;

    uint32_t*   element_data  = nullptr;
    int32_t     element_count = 0;
    
    uint32_t VBO;
    uint32_t EBO;
};

struct MeshInstance { 	
    glm::vec3 position = {0, 0, 0};
    // This should eventually hold a pointer to the
    // Entity that will be rendered here.

    // Or, use the Entity ID system from JDE
};

struct Model {
    std::vector<Mesh> meshes;
	std::vector<MeshNode> nodes;
	std::vector<MeshInstance> instances;
	
    uint32_t* VAO;
    
    std::string file_path = "";
};


struct RenderHandle {
    unsigned int shader_program;
    // At compile time, load all mesh data into here.
    std::vector<Model> models;

    unsigned int default_vao;
};

// Render Pipeline
void init_render ();
void create_window ();
void create_renderer ();
void create_shader_program ();
void create_vertex_attributes ();
void render ();

int get_vert_data_size (Mesh* mesh) ;

// Model Utility
Model* create_model (uint32_t* VAO);
void setup_mesh(Model* model, Mesh* mesh);

// int32_t add_model_instance (Model& model, MeshInstance mesh_instance);
