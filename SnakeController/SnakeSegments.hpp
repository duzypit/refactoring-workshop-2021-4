#pragma once
#include <list>

namespace Snake
{

struct Segment
{
    int x;
    int y;
};

class SnakeSegments
{
public:
    void push_back(Segment);
private:


    std::list<Segment> m_segments;
};
}