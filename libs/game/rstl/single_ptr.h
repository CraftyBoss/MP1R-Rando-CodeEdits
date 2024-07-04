#pragma once

namespace rstl {
    struct single_ptr_details {
        struct default_traits;
    };

    template <typename T, typename Traits = single_ptr_details::default_traits>
    class single_ptr {
    private:
        mutable T* mPtr;
    public:
        T* get() const { return mPtr; }
        T* operator->() const { return mPtr; }
        T& operator*() { return *mPtr; }
        const T& operator*() const { return *mPtr; }

        bool null() const { return mPtr == nullptr; }
    };
}