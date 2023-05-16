#pragma once
#include <CFXS/Base/IPv4.hpp>

namespace CFXS {

    class NetworkPacket {
    public:
        NetworkPacket(const uint8_t* data = nullptr, uint16_t size = 0, bool free_after_use = true) :
            m_Data(data), m_Size(size), m_Free_After_Use(free_after_use) {
        }

        void SetDestinationAddress(const IPv4& address) {
            m_Destination_Address = address;
        }
        void SetDestinationPort(uint16_t port) {
            m_Destination_Port = port;
        }

        void SetFreeAfterUse(bool free_after_use) {
            m_Free_After_Use = free_after_use;
        }

        const uint8_t* GetData() const {
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

        const IPv4& GetDestinationAddress() const {
            return m_Destination_Address;
        }

        uint16_t GetDestinationPort() const {
            return m_Destination_Port;
        }

    private:
        const uint8_t* m_Data;
        uint16_t m_Size;
        uint16_t m_Destination_Port;
        IPv4 m_Destination_Address;
        bool m_Free_After_Use;
    };

} // namespace CFXS