#pragma once

#include "types.h"
#include "rstl/string.h"

// unsure how many of these virtual funcs are from this interface, or from CGameFile's own implementation
class IFileBase {
public:
    enum class ESeekOrigin {};
    enum class EPriority {};

    virtual ~IFileBase() = 0;
    virtual bool IsOpen(void) const = 0;
    virtual void Close(void) = 0;
    virtual rstl::string* GetFileName(void) const = 0;
    virtual int GetFileSize(void) const = 0;
    virtual int GetFilePosition(void) const = 0;
    virtual ulong GetReadAlignment(void) const = 0;
    virtual ulong GetWriteAlignment(void) const = 0;
    virtual void Read(void *,ulong) = 0;
    virtual void Write(void const*,ulong) = 0;
    virtual void AsyncRead(void *,ulong,IFileBase::ESeekOrigin,long,IFileBase::EPriority) = 0;
    virtual void Seek(IFileBase::ESeekOrigin,long) = 0;
    virtual void SeekRead(void *,ulong,IFileBase::ESeekOrigin,long) = 0;
    virtual void SeekWrite(void const*,ulong,IFileBase::ESeekOrigin,long) = 0;
    virtual void FlushToDisk(void) = 0;
};

class CGameFile : public IFileBase {
private:

public:
    virtual ~CGameFile();
    virtual bool IsOpen(void) const;
    virtual void Close(void);
    virtual rstl::string* GetFileName(void) const;
    virtual int GetFileSize(void) const;
    virtual int GetFilePosition(void) const;
    virtual ulong GetReadAlignment(void) const;
    virtual ulong GetWriteAlignment(void) const;
    virtual void Read(void *,ulong);
    virtual void Write(void const*,ulong);
    virtual void AsyncRead(void *,ulong,IFileBase::ESeekOrigin,long,IFileBase::EPriority);
    virtual void Seek(IFileBase::ESeekOrigin,long);
    virtual void SeekRead(void *,ulong,IFileBase::ESeekOrigin,long);
    virtual void SeekWrite(void const*,ulong,IFileBase::ESeekOrigin,long);
    virtual void FlushToDisk(void);
};