#ifndef FAZE_VEC2_HPP
#define FAZE_VEC2_HPP

#include <faze/define.hpp>

namespace fz
{
    template <class Item>
    class Vec2
    {
    public:
        /**
         *
         */
        Item x;

        /**
         *
         */
        Item y;

    public:
        /**
         *
         */
        Vec2();

        /**
         *
         */
        Vec2(const Item& x, const Item& y);

        /**
         *
         */
        Vec2(const Item& i);

        /**
         *
         */
        template <class Type>
        Vec2
        operator+(const Vec2<Type>& that) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator+(const Type& i) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator-(const Vec2<Type>& that) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator-(const Type& i) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator*(const Vec2<Type>& that) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator*(const Type& i) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator/(const Vec2<Type>& that) const;

        /**
         *
         */
        template <class Type>
        Vec2
        operator/(const Type& i) const;

        /**
         *
         */
        template <class Type>
        bool
        operator==(const Vec2<Type>& that) const;
    };

    using Vec2i = Vec2<i32>;
    using Vec2u = Vec2<u32>;
} // namespace fz

#include <faze/inline/Vec2.inl>

#endif // FAZE_VEC2_HPP
