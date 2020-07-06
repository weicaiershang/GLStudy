#ifndef MODEL_H
#define MODEL_H


#include <stb_image.h>

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>


#include "shader.h"
#include "mesh.h"

using namespace std;


unsigned int TextureFromFile(const char *path, const string &directory, bool gamma = false);

class Model
{
public:
    Model(char *path);

    void draw(Shader shader);

private:
    /*  模型数据  */
    vector<Mesh> m_meshes;
    string m_directory;
    vector<Texture> m_texturesLoaded;
    /*  函数   */
    void loadModel(string path);
    void processNode(aiNode *node, const aiScene *scene);
    Mesh processMesh(aiMesh *mesh, const aiScene *scene);
    vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
                                         string typeName);
};

#endif // MODEL_H
