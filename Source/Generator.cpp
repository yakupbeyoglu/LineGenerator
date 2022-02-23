#include "Generator.h"
#include <Gorgon/Geometry/Point.h>
void Generator::GenerateLines(int n) {
    
    auto calculate_radian = [&](int degree) {
        return (M_PI / 180) * degree;
    };

    for(int angle = 0; angle <= 355; angle +=5) {
        Gorgon::Geometry::Pointf initial = {0, 0};
        Gorgon::Geometry::Pointf endpoint = { std::cos(calculate_radian(angle)) * n,  std::sin(calculate_radian(angle)) * n} ;
        dataset.push_back({});
        auto &back = dataset.back();
        back.angle = angle;
        back.pointlist = DDA(initial, endpoint);
    }
    
}

Types::PointfList Generator::DDA (Gorgon::Geometry::Pointf &startpoint, Gorgon::Geometry::Pointf &endpoint) {
    int dx = endpoint.X - startpoint.X;
    int dy = endpoint.Y - startpoint.Y;
    
    int numberofstep  = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);
    
    float xrate = dx / float(numberofstep);
    float yrate = dy / float(numberofstep);
    Types::PointfList newlist;
    newlist.Push(startpoint);
    Gorgon::Geometry::Pointf position = startpoint;
    for (int step = 0; step < numberofstep - 1; step++) {
            position += { xrate, yrate};
            newlist.Push(position);
    }
    
    newlist.Push(endpoint);
    return newlist;
}

void Generator::ExportDataSet(std::string path, int n) {
    std::ofstream file(path);
    if(!file.is_open())
        throw std::runtime_error("path is not open");
    
    for(auto &data : dataset) {
        if(data.pointlist.GetSize() < n)
            throw std::runtime_error("Point list size is less than n parameter");
        for(int point = 0; point < n; point++) {
            auto current = data.pointlist[point];
            file << current.X << "," << current.Y << ",";
        }
        file << data.angle << std::endl;
    }
}
