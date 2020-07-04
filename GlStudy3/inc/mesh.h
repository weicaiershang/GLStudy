#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>
#include <glm/glm.hpp>

#include "shader.h"

using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
};

class Mesh
{
public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    void Draw(Shader shader);

    vector<Vertex> vertex();
    void setVertex(vector<Vertex> vertex);

    vector<unsigned int> indices();
    void setIndices(vector<unsigned int> indices);

    vector<Texture> textures();
    void setTextures(vector<Texture> textures);
private:
    void setupMesh();
private:
    /*  网格数据  */
    vector<Vertex> m_vertices;
    vector<unsigned int> m_indices;
    vector<Texture> m_textures;
    /*  渲染数据  */
    unsigned int m_VAO, m_VBO, m_EBO;
};

#endif // MESH_H
