#ifndef __HOOPOE_ENGINE_CORE_SHAREDPTR_H__
#define __HOOPOE_ENGINE_CORE_SHAREDPTR_H__

#include <memory>

namespace Hoopoe 
{

template<class T> 
class SharedPtr : public std::shared_ptr<T>
{
public:
    SharedPtr(std::nullptr_t) {}
    SharedPtr() {}
    template<class Y>
    explicit SharedPtr(Y* ptr) : std::shared_ptr<T>(ptr) {}
    template<class Y, class Deleter >
    SharedPtr(Y* ptr, Deleter d) : std::shared_ptr<T>(ptr, d) {}
    SharedPtr(const SharedPtr& r) : std::shared_ptr<T>(r) {}
    template<class Y>
    SharedPtr(const SharedPtr<Y>& r) : std::shared_ptr<T>(r) {}

    // implicit conversion from and to shared_ptr
    template<class Y>
    SharedPtr(const std::shared_ptr<Y>& r) : std::shared_ptr<T>(r) {}
    operator const std::shared_ptr<T>&() { return static_cast<std::shared_ptr<T>&>(*this); }
    SharedPtr<T>& operator=(const Hoopoe::SharedPtr<T>& rhs) { std::shared_ptr<T>::operator=(rhs); return *this; }
    // so swig recognizes it should forward the operators
    T* operator->() const { return std::shared_ptr<T>::operator->(); }

    template<typename Y>
    SharedPtr<Y> staticCast() const { return std::static_pointer_cast<Y>(*this); }

    template<typename Y>
    SharedPtr<Y> dynamicCast() const { return std::dynamic_pointer_cast<Y>(*this); }

    void bind(T* rep) { std::shared_ptr<T>::reset(rep); }
    unsigned int useCount() const { return std::shared_ptr<T>::use_count(); }
    T* getPointer() const { return std::shared_ptr<T>::get(); }
    bool isNull(void) const { return !std::shared_ptr<T>::operator bool(); }
    void setNull() { std::shared_ptr<T>::reset(); }
}; // SharedPtr

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_SHAREDPTR_H__