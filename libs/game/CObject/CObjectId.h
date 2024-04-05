#pragma once
#include "rstl/misc.h"
#include <rstl/string.h>

class CInputStream;
class COutputStream;

class CGuid {
public:

    CGuid(CInputStream &);
    CGuid(char const(&)[37]);

    void PutTo(COutputStream &) const;
    int GetPutToSize(void) const; // return 0x10;
    void FromString(rstl::string const&);
    void SetFromString(rstl::string const&);
    void IsGuidString(rstl::string const&);
    rstl::string AsString(void) const;
    int GetHashValue(void) const;
    void HexDWord(char const*);

    union {
        char data[16];
        struct {
            uint64_t low;
            uint64_t high;
        };
    };
};

class CObjectId : public CGuid {
public:
    CObjectId(CInputStream &);

    explicit inline CObjectId(char const(&str)[37]) : CGuid(str) {}

    static CObjectId* Invalid(void);
    static CObjectId* FromString(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&);

    void PutTo(COutputStream &);
    void GetPutToSize(void);
    void operator<(CObjectId const&);
};