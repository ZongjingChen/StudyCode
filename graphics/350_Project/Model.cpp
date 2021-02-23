#include "Model.h"

Model::Model(){
    triangles = vector<Triangle3D>();
}
int Model::numTriangles(){
    return triangles.size();
}

void Model::transform(Matrix4 obj){
    for(int i = 0; i< numTriangles(); i++){
        if(triangles.at(i).shouldDraw){
            triangles.at(i).transform(obj);
        }
    }
}
void Model::readFromOBJFile(string filepath, Color pFillColor){
    vector<Vector4> vertices;
    vector<Triangle3D> faces;
    ifstream myFile(filepath);
    if(myFile.is_open()){
        string line;
        while(getline(myFile, line)){
            istringstream s(line);
            string myWord;
            vector<string> words;
            while(getline(s, myWord, ' ')){
                words.push_back(myWord);
            }
            if(words.at(0) == "v"){
                float x = atof(words.at(1).c_str());
                float y = atof(words.at(2).c_str());
                float z = atof(words.at(3).c_str());
                Vector4 temp(x, y, z, 1);
                vertices.push_back(temp);
            }
            else if(words.at(0) == "f"){
                if(words.size() == 4){
                    Vector4 x = vertices.at(atof((words.at(1).c_str())) - 1);
                    Vector4 y = vertices.at(atof((words.at(2).c_str())) - 1);
                    Vector4 z = vertices.at(atof((words.at(3).c_str())) - 1);
                    Triangle3D temp(x, y, z, pFillColor, pFillColor, pFillColor);
                    triangles.push_back(temp);
                }
                else if(words.size() == 5){
                    Vector4 x = vertices.at(atof((words.at(1).c_str())) - 1);
                    Vector4 y = vertices.at(atof((words.at(2).c_str())) - 1);
                    Vector4 z = vertices.at(atof((words.at(3).c_str())) - 1);
                    Vector4 i = vertices.at(atof((words.at(4).c_str())) - 1);
                    Triangle3D temp1(x, y, z, pFillColor, pFillColor, pFillColor);
                    Triangle3D temp2(x, z, i, pFillColor, pFillColor, pFillColor);
                    triangles.push_back(temp1);
                    triangles.push_back(temp2);
                }
            }
        }
        myFile.close();
    }
}

void Model::homogenize(){
    for(int i = 0; i < numTriangles(); i++){
        triangles[i].v1.x /= triangles[i].v1.w;
        triangles[i].v1.y /= triangles[i].v1.w;
        triangles[i].v1.z /= triangles[i].v1.w;
        triangles[i].v1.w = 1;  

        triangles[i].v2.x /= triangles[i].v2.w;
        triangles[i].v2.y /= triangles[i].v2.w;
        triangles[i].v2.z /= triangles[i].v2.w;
        triangles[i].v2.w = 1;  

        triangles[i].v3.x /= triangles[i].v3.w;
        triangles[i].v3.y /= triangles[i].v3.w;
        triangles[i].v3.z /= triangles[i].v3.w;
        triangles[i].v3.w = 1;  
    }
}

void Model::performBackfaceCulling(Vector4 eye, Vector4 spot){
    Vector4 look = spot - eye;
    for(int i = 0; i < numTriangles(); i++){
        Vector4 a = triangles[i].v2 - triangles[i].v1;
        Vector4 b = triangles[i].v3 - triangles[i].v1;
        Vector4 norm = a.cross(b);
        if(norm.dot(look) <= 0){
            triangles[i].shouldDraw = false;
        }
    }
}