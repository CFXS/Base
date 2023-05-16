#pragma once
#include <CFXS/Base/IPv4.hpp>
#include <CFXS/Base/Buffer.hpp>

namespace CFXS {

    class NetworkPacket : public Buffer<const uint8_t, uint16_t> {
    public:
        NetworkPacket(const uint8_t* data = nullptr, uint16_t size = 0) : Buffer(data, size) {
        }

        void SetDestinationAddress(const IPv4& address) {
            m_Destination_Address = address;
        }
        void SetDestinationPort(uint16_t port) {
            m_Destination_Port = port;
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
    };

} // namespace CFXS