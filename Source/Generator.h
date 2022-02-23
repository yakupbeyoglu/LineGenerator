#ifndef Generator_h
#define Generator_h
#include <fstream>
#include <filesystem>
#include <Gorgon/Filesystem.h>
#include <vector>
#include <math.h>
#include<random>
#include <thread>
#include "Types.h"

class Generator {
public :
    Generator() {}
    
    Generator(const Generator &) = delete;
    
    Generator& operator = (const Generator &) = delete;

    void GenerateLines(int n = 20);
    
    void ExportDataSet(std::string path, int n = 9);
    
private:
    Types::PointfList DDA (Gorgon::Geometry::Pointf &startpoint, Gorgon::Geometry::Pointf &endpoint);
    std::vector<Types::AnglePoints> dataset;
    std::string exportpath;
    

};





#endif
