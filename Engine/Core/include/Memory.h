#ifndef __HOOPOE_ENGINE_CORE_MEMORY_H__
#define __HOOPOE_ENGINE_CORE_MEMORY_H__

namespace Hoopoe
{

    enum MemoryCategory
    {
        MEMCATEGORY_GENERAL = 0,        // General purpose
        MEMCATEGORY_GEOMETRY = 1,       // Geometry held in main memory
        MEMCATEGORY_ANIMATION = 2,      // Animation data like tracks, bone matrices
        MEMCATEGORY_SCENE_CONTROL = 3,  // Nodes, control data
        MEMCATEGORY_SCENE_OBJECTS = 4,  // Scene object instances
        MEMCATEGORY_RESOURCE = 5,       // Other resources
        MEMCATEGORY_SCRIPTING = 6,      // Scripting
        MEMCATEGORY_RENDERSYS = 7       // Rendersystem structures
    };

    template<int Category = MEMCATEGORY_GENERAL> class AllocatedObject {};

    typedef AllocatedObject<MEMCATEGORY_GENERAL>        GeneralAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_GEOMETRY>       GeometryAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_ANIMATION>      AnimationAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_SCENE_CONTROL>  SceneCtlAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_SCENE_OBJECTS>  SceneObjAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_RESOURCE>       ResourceAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_SCRIPTING>      ScriptingAllocatedObject;
    typedef AllocatedObject<MEMCATEGORY_RENDERSYS>      RenderSysAllocatedObject;

    typedef GeneralAllocatedObject      AppicationAlloc;
    typedef GeneralAllocatedObject      StreamAlloc;
    typedef GeneralAllocatedObject      LogAlloc;
    typedef GeneralAllocatedObject      ConfigAlloc;
    typedef ResourceAllocatedObject     ResourceAlloc;
    typedef GeneralAllocatedObject      FileSystemAlloc;

} // Hoopoe

#define HE_ALLOC(bytes) (void*)new char[bytes]
#define HE_ALLOC_T(T, count) (T*)new char[(count) * sizeof(T)]
#define HE_FREE(ptr) delete[] (char*)ptr

#define HE_NEW_T(T) new T
#define HE_NEW_ARRAY_T(T, count) new T[count]
#define HE_DELETE(ptr) delete ptr
#define HE_DELETE_ARRAY(ptr) delete[] ptr

#endif // __HOOPOE_ENGINE_CORE_MEMORY_H__