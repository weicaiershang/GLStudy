#ifndef MESH_H
#define MESH_H


#include <glad/glad.h> // holds all OpenGL type declarations

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <vector>


#include "shader.h"
using namespace std;


using namespace std;

struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh
{
public:
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);

    void draw(Shader shader);

    vector<Vertex> vertices();
    void setVertices(vector<Vertex> vertices);

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
