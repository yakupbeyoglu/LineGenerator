#ifndef Types_h
#define Types_h
#include <Gorgon/Geometry/Point.h>
#include <Gorgon/Geometry/Line.h>
#include <Gorgon/Geometry/PointList.h>

namespace Types {
using Line = Gorgon::Geometry::Line<Gorgon::Geometry::Pointf>;
using LineList = std::vector<Line>;
using PointfList = Gorgon::Geometry::PointList<Gorgon::Geometry::Pointf>;
using PointList = Gorgon::Geometry::PointList<Gorgon::Geometry::Point>;

struct AnglePoints { 
    int angle;
    PointfList pointlist;
};
}

#endif
