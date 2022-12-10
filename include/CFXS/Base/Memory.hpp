#pragma once

#define __mem8(x)  (*(__rw uint8_t*)(x))
#define __mem16(x) (*(__rw uint16_t*)(x))
#define __mem32(x) (*(__rw uint32_t*)(x))
#define __mem64(x) (*(__rw uint64_t*)(x))