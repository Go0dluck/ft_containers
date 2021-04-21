#pragma once

namespace ft
{
    template <bool B, class T = void>
    struct enable_if {};

    template <class T>
    struct enable_if<true, T> {
        typedef T type;
    };

    template <class T>
    struct	integral{static const bool value = false;};

    template<>
    struct	integral<bool>{static const bool value = true;};

    template<>
    struct	integral<char>{static const bool value = true;};

    template<>
    struct	integral<short>{static const bool value = true;};

    template<>
    struct	integral<int>{static const bool value = true;};

    template<>
    struct	integral<long>{static const bool value = true;};

    template<>
    struct	integral<long long>{static const bool value = true;};

    template<>
    struct	integral<unsigned char>{static const bool value = true;};

    template<>
    struct	integral<unsigned short>{static const bool value = true;};

    template<>
    struct	integral<unsigned int>{static const bool value = true;};

    template<>
    struct	integral<unsigned long>{static const bool value = true;};

    template<>
    struct	integral<unsigned long long>{static const bool value = true;};

}