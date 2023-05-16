#pragma once

namespace CFXS {

    template<typename DATA_TYPE, typename SIZE_TYPE = unsigned int>
    class Buffer {
    public:
        Buffer(DATA_TYPE* data, SIZE_TYPE size) : m_Data(data), m_Size(size) {
        }

        DATA_TYPE* GetData() const {
            return m_Data;
        }

        template<typename T>
        const T* GetDataCast() const {
            return (T*)m_Data;
        }

        template<typename T>
        T* GetDataCast() {
            return (T*)m_Data;
        }

        uint16_t GetSize() const {
            return m_Size;
        }

    private:
        DATA_TYPE* m_Data;
        SIZE_TYPE m_Size;
    };

} // namespace CFXS