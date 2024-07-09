#pragma once

class CSaveGameManager {
public:
    enum class EState {
        NotLoaded,
        Loaded,
        Saved,
        WroteCopy,
        FailedDeleteCorruptedFile,
        FailedLoad,
        FailedCreateInitial,
        FailedWriteInitial,
        FailedWriteCopy,
        DeletingCorruptedFile,
        Reading,
        CreatingInitial,
        FlushingInitial,
        WritingCopy,
        FlushingCopy,

    };
    enum class EErrorCode {
        NoError,
        InsufficientSpace,
        InsufficientNodes,
        NoFile,
        CorruptedFile,
    };
};