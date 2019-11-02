#include "sprite.hpp"

void Sprite::set_offset(int x, int y) {
    m_offset.x = x;
    m_offset.y = y;
}

void Sprite::set_position(int x, int y) {
    m_position.x = x;
    m_position.y = y;
}
