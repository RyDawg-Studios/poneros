#pragma once

#include "render.h"
#include "file_utils.h"
#include <cstdio>

Vertex TEST_VERTS[] = {
    {{-.5, -.5, .0}},
    {{ .5, -.5, .0}},
    {{ .0,  .5, .0}},
};

Mesh TEST_MESH = {
    .vertex_data    = TEST_VERTS,
    .vertex_count   = 3
};

void init_render () {
    create_renderer();
    create_window();
    create_shader_program();
    create_vertex_attributes();
    
    uint32_t* default_vao = &game_state->render_handle->default_vao;
    Model* test_model = create_model(default_vao);
    
    setup_mesh(test_model, &TEST_MESH);

    test_model->instances.push_back({});
    MeshNode test_node = {};
    test_node.indices.push_back(0);
    test_model->nodes.push_back(test_node);
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

void create_vertex_attributes () {
    glGenVertexArrays(1, &(game_state->render_handle->default_vao));
    glBindVertexArray(game_state->render_handle->default_vao);
}

void render () {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    for (Model &model : game_state->render_handle->models) {
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE,  sizeof(Vertex), (void*)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(3 * sizeof(float)));
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(6 * sizeof(float)));

        for (MeshNode &node : model.nodes) {
            for (int &id : node.indices) {
                glBindBuffer(GL_ARRAY_BUFFER, model.meshes[id].VBO);
                            
                glDrawArrays(GL_TRIANGLES, 0, 3);
            }
        }

    }
    glfwSwapBuffers(game_state->window);
}

int get_vert_data_size (Mesh* mesh) {
    return mesh->vertex_count * sizeof(Vertex);
}


Model* create_model (uint32_t* VAO) {
    Model model = {};
    model.VAO = VAO;    
    
    game_state->render_handle->models.push_back(model);
    
    return game_state->render_handle->models.data();
}

void setup_mesh(Model* model, Mesh* mesh) {
    uint32_t indx;
    
    model->meshes.push_back(*mesh);
    indx = model->meshes.size() - 1;
    
    Mesh* mp = &model->meshes[indx];
    
    glGenBuffers(1, &mp->VBO);
    glGenBuffers(1, &mp->EBO);
    
    glNamedBufferData(mp->VBO, mp->vertex_count * sizeof(Vertex), mp->vertex_data, GL_STATIC_DRAW);
    glNamedBufferData(mp->EBO, mp->element_count * sizeof(uint32_t), mp->element_data, GL_STATIC_DRAW);    
    
    return;
}
    // glGenBuffers(1, &model.VBO);
    // glGenBuffers(1, &model.EBO);

    // int vbo_size = model.mesh_data->vertex_count * sizeof(Vertex);
    // glNamedBufferData(model.VBO, vbo_size, model.mesh_data->vertex_data, GL_STATIC_DRAW);

// int32_t add_model_instance (Model& model, MeshInstance mesh_instance) {
//     model.instances.push_back(mesh_instance);
//     return model.instances.size();
// }
