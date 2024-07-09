#pragma once

template<typename A, typename B, typename C, uint D, uint E>
struct CValueVersionId {
    A value;
};

typedef CValueVersionId<uint,uint,ushort,16u,16u> TUniqueId;