#include <faze/Vec2.hpp>

namespace fz
{
    template <class Item>
    Vec2<Item>::Vec2()
        : x {}
        , y {}
    { }

    template <class Item>
    Vec2<Item>::Vec2(const Item& x, const Item& y)
        : x {x}
        , y {y}
    { }

    template <class Item>
    Vec2<Item>::Vec2(const Item& i)
        : x {i}
        , y {i}
    { }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator+(const Vec2<Type>& that) const
    {
        return {x + that.x, y + that.y};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator+(const Type& i) const
    {
        return {x + i, y + i};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator-(const Vec2<Type>& that) const
    {
        return {x - that.x, y - that.y};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator-(const Type& i) const
    {
        return {x - i, y - i};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator*(const Vec2<Type>& that) const
    {
        return {x * that.x, y * that.y};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator*(const Type& i) const
    {
        return {x * i, y * i};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator/(const Vec2<Type>& that) const
    {
        return {x / that.x, y / that.y};
    }

    template <class Item>
    template <class Type>
    Vec2<Item>
    Vec2<Item>::operator/(const Type& i) const
    {
        return {x / i, y / i};
    }

    template <class Item>
    template <class Type>
    bool
    Vec2<Item>::operator==(const Vec2<Type>& that) const
    {
        return x == that.x &&
               y == that.y;
    }
} // namespace fz
