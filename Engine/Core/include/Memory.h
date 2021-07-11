#ifndef __HOOPOE_ENGINE_CORE_MEMORY_H__
#define __HOOPOE_ENGINE_CORE_MEMORY_H__

#define HE_ALLOC(bytes) (void*)new char[bytes]
#define HE_ALLOC_T(T, count) (T*)new char[(count) * sizeof(T)]
#define HE_FREE(ptr) delete[] (char*)ptr

#define HE_NEW_T(T) new T
#define HE_NEW_ARRAY_T(T, count) new T[count]
#define HE_DELETE(ptr) delete ptr
#define HE_DELETE_ARRAY(ptr) delete[] ptr

#endif // __HOOPOE_ENGINE_CORE_MEMORY_H__