#include <faze/ServiceHolder.hpp>

namespace fz
{
    template <class Service>
    ServiceHolder<Service>::ServiceHolder(ma::BaseOrigin* origin, ma::usize size)
        : ma::HashMap<ma::u32, Service*>(origin, size)
    { }

    template <class Service>
    bool
    ServiceHolder<Service>::insert(ma::u32 index, Service* service)
    {
        auto& super = (ma::HashMap<ma::u32, Service*>&) *this;

        if ( index != 0 && service != 0 )
            return super.insert(index, service);

        return false;
    }
} // namespace fz
