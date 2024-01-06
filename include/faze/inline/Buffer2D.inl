#include <faze/Buffer2D.hpp>

namespace fz
{
    template <class Item, template <class> class Buffer>
    Buffer2D<Item, Buffer>::Buffer2D()
        : Buffer<Item>()
        , m_width {0}
    { }

    template <class Item, template <class> class Buffer>
    template <class... Args>
    Buffer2D<Item, Buffer>::Buffer2D(BaseOrigin& origin, u32 size, u32 width, Args&&... args)
        : Buffer<Item>(origin, size, forw<Args>(args)...)
        , m_width {0}
    {
        if ( width == 0 )
            width = 1;

        m_width = width;
    }

    template <class Item, template <class> class Buffer>
    u32
    Buffer2D<Item, Buffer>::width() const
    {
        return m_width;
    }

    template <class Item, template <class> class Buffer>
    u32
    Buffer2D<Item, Buffer>::height() const
    {
        auto& self = (Buffer<Item>&) *this;
        u32   size = self.size();

        return size / m_width;
    }

    template <class Item, template <class> class Buffer>
    Item*
    Buffer2D<Item, Buffer>::search(u32 col, u32 row) const
    {
        auto& self = (Buffer<Item>&) *this;

        if ( col < m_width && row < height() )
            return self.search(row * m_width + col);

        return 0;
    }

    template <class Item, template <class> class Buffer>
    Item*
    Buffer2D<Item, Buffer>::search(const Vec2u& vec) const
    {
        return search(vec.x, vec.y);
    }

    template <class Item, template <class> class Buffer>
    Item&
    Buffer2D<Item, Buffer>::find(u32 col, u32 row) const
    {
        return *search(col, row);
    }

    template <class Item, template <class> class Buffer>
    Item&
    Buffer2D<Item, Buffer>::find(const Vec2u& vec) const
    {
        return *search(vec.x, vec.y);
    }
} // namespace fz
