#ifndef FAZE_ARRAY2D_HPP
#define FAZE_ARRAY2D_HPP

#include <faze/Vec2.hpp>

namespace fz
{
    template <class Item, template <class> class Buffer = FixedBuffer>
    class Buffer2D
        : public Buffer<Item>
    {
    public:
        using Parent = Buffer<Item>;

    public:
        /**
         *
         */
        Buffer2D();

        /**
         *
         */
        template <class... Args>
        Buffer2D(BaseOrigin& origin, u32 size, u32 width, Args&&... args);

        /**
         *
         */
        virtual u32
        width() const;

        /**
         *
         */
        virtual u32
        height() const;

        /**
         *
         */
        virtual Item*
        search(u32 col, u32 row) const;

        /**
         *
         */
        virtual Item*
        search(const Vec2u& vec) const;

        /**
         *
         */
        virtual Item&
        find(u32 col, u32 row) const;

        /**
         *
         */
        virtual Item&
        find(const Vec2u& vec) const;

    protected:
        /**
         *
         */
        u32 m_width;

        /**
         *
         */
        u32 m_height;
    };
} // namespace fz

#include <faze/inline/Buffer2D.inl>

#endif // FAZE_ARRAY2D_HPP
