#pragma once
#include <list>
#include <algorithm>
#include "SnakeInterface.hpp"

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
    bool isSegmentAtPosition(int x, int y) const;
    Segment calculateNewHead() const;
    void setCurrentDirection(Direction);
private:
    bool isHorizontal(Direction) const;
    bool isVertical(Direction) const;
    bool isPositive(Direction) const;

    std::list<Segment> m_segments;
    Direction m_currentDirection;
};
}