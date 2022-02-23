#include <iostream>
#include "Generator.h"
#include <vector>
#include <future>
#include <Gorgon/Filesystem.h>
int main() {
    
    std::cout<<"Hello World"<<std::endl;
    Generator  generator;
    generator.GenerateLines();
    generator.ExportDataSet("dataset.csv");
    return 0;

}
