#pragma once

#include <lwip/pbuf.h>
struct pbuf;

namespace CFXS {

    template<typename IP_TYPE>
    class NetworkPacketRef {
    public:
        NetworkPacketRef(pbuf* packet_buffer,
                         const IP_TYPE& source_address,
                         uint16_t source_port,
                         const IP_TYPE& destination_address,
                         uint16_t destination_port) :
            m_Buffer(packet_buffer),
            m_Source_Address(source_address),
            m_Destination_Address(destination_address),
            m_Source_Port(source_port),
            m_Destination_Port(destination_port) {
        }

        NetworkPacketRef(NetworkPacketRef&&)      = delete;
        NetworkPacketRef(const NetworkPacketRef&) = delete;
        auto operator=(const NetworkPacketRef&)   = delete;

        /// @brief Get destination address
        /// @return destination address
        const IP_TYPE& GetDestinationAddress() const {
            return m_Destination_Address;
        }

        /// @brief Get destination port
        /// @return destination port
        uint16_t GetDestinationPort() const {
            return m_Destination_Port;
        }

        /// @brief Get source address
        /// @return source address
        const IP_TYPE& GetSourceAddress() const {
            return m_Source_Address;
        }

        /// @brief Get source port
        /// @return source port
        uint16_t GetSourcePort() const {
            return m_Source_Port;
        }

        /// @brief Get full buffer size
        /// @return buffer size
        size_t GetSize() const {
            return m_Buffer->tot_len;
        }

        /// @brief Get raw data pointer from first buffer (not safe if there are multiple chained buffers)
        /// @return first buffer data pointer
        const uint8_t* GetRawData() const {
            return (const uint8_t*)m_Buffer->payload;
        }

        /// @brief Get raw data pointer from first buffer (not safe if there are multiple chained buffers)
        /// @return first buffer data pointer
        template<typename T>
        const T* GetRawDataCast() const {
            return (const T*)m_Buffer->payload;
        }

        /// @brief Copy data out of buffer
        /// @param copyTo buffer to copy to
        /// @param copy_size bytes to copy
        /// @param offset start offset
        void CopyData(uint8_t* copyTo, size_t copy_size, size_t offset) {
            pbuf_copy_partial(m_Buffer, copyTo, copy_size, offset);
        }

    private:
        pbuf* m_Buffer;
        IP_TYPE m_Source_Address;
        IP_TYPE m_Destination_Address;
        uint16_t m_Source_Port;
        uint16_t m_Destination_Port;
    };

} // namespace CFXS