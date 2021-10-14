#include "SnakeSegments.hpp"

namespace Snake
{

void SnakeSegments::push_back(Segment seg)
{
    m_segments.push_back(seg);
}

bool SnakeSegments::isSegmentAtPosition(int x, int y) const
{
    return m_segments.end() !=  std::find_if(m_segments.cbegin(), m_segments.cend(),
        [x, y](auto const& segment){ return segment.x == x and segment.y == y; });
}

void SnakeSegments::setCurrentDirection(Direction dir)
{
    m_currentDirection = dir;
}

bool SnakeSegments::isHorizontal(Direction direction) const
{
    return Direction_LEFT == direction or Direction_RIGHT == direction;
}

bool SnakeSegments::isVertical(Direction direction) const
{
    return Direction_UP == direction or Direction_DOWN == direction;
}

bool SnakeSegments::isPositive(Direction direction) const
{
    return (isVertical(direction) and Direction_DOWN == direction)
        or (isHorizontal(direction) and Direction_RIGHT == direction);
}

Segment SnakeSegments::calculateNewHead() const{
    Segment const& currentHead = m_segments.front();

    Segment newHead;
    newHead.x = currentHead.x + (isHorizontal(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);
    newHead.y = currentHead.y + (isVertical(m_currentDirection) ? isPositive(m_currentDirection) ? 1 : -1 : 0);

    return newHead;
}
}