#pragma once

#include "rstl/vector.h"

namespace rstl {
    template <typename K, typename V, typename SortFunc = rstl::less<K>, typename Alloc = rmemory_allocator>
    class key_value_vector {
    public:
        rstl::vector<K, Alloc> mKeys;
        rstl::vector<V, Alloc> mValues;
        void* mSomething; // SortFunc?
    };
}