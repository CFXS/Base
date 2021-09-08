// [CFXS] //
#pragma once
#include <CFXS/Base/Debug.hpp>

namespace CFXS {

    template<typename T, typename Inheriter>
    class RefCounter {
    public:
        T GetRefCount() {
            return m_RefCount;
        }

        void IncRefCount() {
            m_RefCount++;
        }

        void DecRefCount() {
            CFXS_ASSERT(m_RefCount, "Reference count is 0");
            m_RefCount--;
            if (!m_RefCount) {
                static_cast<Inheriter*>(this)->RefCountZero();
            }
        }

    private:
        T m_RefCount = 0;
    };

} // namespace CFXS