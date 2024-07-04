#pragma once

#include "rstl/misc.h"
#include "lib.hpp"

// TODO: find out how much from https://github.com/PrimeDecomp/prime/blob/530b4540f00a0c8b8917b231dd0d20736c0bdebb/include/rstl/vector.hpp is still present in this header

namespace rstl {
    template < typename T, typename Alloc = rmemory_allocator >
    class vector {
    private:
        int mCount;
        int mCapacity;
        T* mItems;
    public:

        T* data() { return mItems; }
        const T* data() const { return mItems; }
        int size() const { return mCount; }
        bool empty() const { return mCount == 0; }
        int capacity() const { return mCapacity; }
        T& at(int idx) {
            if(idx < mCapacity)
                return mItems[idx];
            EXL_ABORT(0, "Index out of Range! Value: %d (%d/%d)", idx, mCount, mCapacity);
        }
        const T& at(int idx) const {
            if(idx < mCapacity)
                return mItems[idx];
            EXL_ABORT(0, "Index out of Range! Value: %d/%d (%d/%d)", idx, mCount, mCapacity);
        }
        T& front() { return at(0); }
        const T& front() const { return at(0); }
        T& back() { return at(mCount - 1); }
        const T& back() const { return at(mCount - 1); }
        T& operator[](int idx) { return mItems[idx]; }
        const T& operator[](int idx) const { return mItems[idx]; }
    };
}