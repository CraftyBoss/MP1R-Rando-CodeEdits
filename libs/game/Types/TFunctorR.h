#pragma once

template <typename R, typename... Args>
class TFunctorR {
    virtual R InvokeFreeFunction(Args &&...);
    void *unkPtr1;
    R (*pFunction)(Args &&...) = {};
};