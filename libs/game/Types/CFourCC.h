#pragma once

#include "types.h"
#include "Stream/CInputStream.h"
#include "rstl/string.h"

struct CFourCC {
    uint value;

    enum EPeekConstructor { };

    inline CFourCC() { value = 0; }

    static void TryParse(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&,CFourCC&);
    static CFourCC PeekFourCC(CInputStream &);

    CFourCC(rstl::basic_string<char,rstl::char_traits<char>,rstl::rmemory_allocator> const&);
    CFourCC(CInputStream &);
    CFourCC(CInputStream &,CFourCC::EPeekConstructor);
    void PutTo(COutputStream &);
    ulong GetPutToSize(void); // 0x4

    // custom funcs
    static void ToString(char (&outStr)[5], CFourCC& val) {
        char *bytes = reinterpret_cast<char*>(&val);

        outStr[0] = bytes[0];
        outStr[1] = bytes[1];
        outStr[2] = bytes[2];
        outStr[3] = bytes[3];
        outStr[4] = '\0';
    }

    static CFourCC FromString(const char (&inStr)[5]) {
        CFourCC outVal = {};
        char *bytes = reinterpret_cast<char*>(&outVal.value);

        bytes[0] = inStr[0];
        bytes[1] = inStr[1];
        bytes[2] = inStr[2];
        bytes[3] = inStr[3];

        return outVal;
    }

    bool operator ==(const CFourCC& right) const {
        return value == right.value;
    }
};
