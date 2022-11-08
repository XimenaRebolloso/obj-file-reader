#include "../include/Object.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

Object::Object(string file)
{

    string line;

    vector<Vertex> vertices = {};
    vector<Face> faces = {};

    ifstream archivo(file);
    while (getline(archivo, line))
    {
        //enteros para los vertices
        int fx, fy, fz; 
        //enteros para los 
        int indexA, indexB, indexC;
        //Aqui se divide la linea que se leyo, pero debido a la función tokenizer que utlice, tengo 
        //que colocar dos espacios. Espero en la proxima entrega, ya tenerlo corregido. 
        vector<string> words = split(line,"  ");

        if (!words.empty())
        {
            if(words[0].compare("v")== 0)
            {
                //Vertices
                fx = stof(words[1]);
                fy = stof(words[2]);
                fz = stof(words[3]);

                //Se construyen los vertices y se agrega al vector 
                Vertex v (fx,fy,fz);
                vertices.push_back(v);
            }
            if(words[0].compare("f")==0)
            {
                //Se obtienen los indices de los vertices de las caras 
                indexA = stof(split(words[1],"/")[0]) - 1;
                indexB = stof(split(words[2],"/")[0]) - 1;
                indexC = stof(split(words[3],"/")[0]) - 1;
                //cout << indexA << " " << indexB << " " << indexC << endl;
                //Se construyen los vertices 
                Vertex va = vertices[indexA];
                Vertex vb = vertices[indexB];
                Vertex vc = vertices[indexC];
                //Se construyen las aristas
                Edge ea(va, vb);
                Edge eb(vb, vc);
                Edge ec(vc, va);
                //Se construyen las caras y se agregan al vector 
                Face f({ea, eb, ec});
                faces.push_back(f);
            }
        }
    }
    this-> vertices = vertices;
    this-> faces = faces;
    
    //Pruebas de verificación 
    //vertices[7].print();
    //cout <<" "<<endl;
    //faces[2].print();

}

//Funcion tokenizer, se espera poder modificar. 
vector<string> Object::split(string s, string delimiter)
{
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}
