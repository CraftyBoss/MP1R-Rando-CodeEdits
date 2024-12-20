#pragma once

// not fully implemented forward decls/unverified structs from prime decomp
namespace rstl {
    template <typename T, typename F, typename M>
    class basic_string;
    template <typename T>
    class char_traits;

    template <typename T, int size, class Allocator>
    class growable_reserved_vector;

    template <typename T>
    class less;

    template <typename L, typename R>
    class pair {
    public:
        pair() = default;
        pair(const L& first, const R& second) : mFirst(first), mSecond(second) {}
        bool operator==(const pair& other) const { return mFirst == other.mFirst && mSecond == other.mSecond; }

        L mFirst;
        R mSecond;
    };

    // if i had to guess, these allocators probably all use compile time virtualization
    // to be able to customize how something allocates without needing a reference to an actual allocator class
    class rmemory_allocator;

    template <typename T>
    class shared_owned_memory_allocator;

    class owned_memory_arena_allocator;
}