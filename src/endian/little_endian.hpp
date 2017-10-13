// Copyright (c) 2016 Steinwurf ApS
// All Rights Reserved
//
// Distributed under the "BSD License". See the accompanying LICENSE.rst file.

#pragma once

#include <cstdint>
#include <cassert>

#include "types.hpp"

namespace endian
{
// Inserts and extracts integers in little-endian format.
struct little_endian
{
    template<class Type>
    static typename Type::type get(const uint8_t* buffer);

    template<class Type>
    static void put(typename Type::type value, uint8_t* buffer);
};

/// Gets an 8-bit value integer from a byte stream. Only exists for
/// convenience in the template-based getters and putters.
/// @param buffer pointer to the byte stream buffer
/// @return retrieved value from the byte stream
template<>
inline u8::type little_endian::get<u8>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return *buffer;
}

/// Inserts an 8-bit value integer into the byte stream. Only exists
/// for convenience in the template-based getters and putters.
/// @param value to put in the stream
/// @param buffer pointer to the byte stream buffer
template<>
inline void little_endian::put<u8>(u8::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    *buffer = value;
}

template<>
inline i8::type little_endian::get<i8>(const uint8_t* buffer)
{
    return little_endian::get<u8>(buffer);
}

template<>
inline void little_endian::put<i8>(i8::type value, uint8_t* buffer)
{
    little_endian::put<u8>(value, buffer);
}

/// Gets a 16-bit value integer which is in little-endian format from
/// a byte stream.
template<>
inline u16::type little_endian::get<u16>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (buffer[1] << 8) | buffer[0];
}

/// Inserts a 16-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u16>(u16::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = (value >> 8 & 0xFF);
}

template<>
inline i16::type little_endian::get<i16>(const uint8_t* buffer)
{
    return little_endian::get<u16>(buffer);
}

template<>
inline void little_endian::put<i16>(i16::type value, uint8_t* buffer)
{
    little_endian::put<u16>(value, buffer);
}

/// Gets a 24-bit value integer which is in little-endian format from
/// a byte stream.
template<>
inline u24::type little_endian::get<u24>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (buffer[2] << 16) | (buffer[1] << 8)  | buffer[0];
}

/// Inserts a 24-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u24>(u24::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = ((value) & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
}

/// Gets a 32-bit value integer which is in little-endian format from a
/// byte stream.
template<>
inline u32::type little_endian::get<u32>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (buffer[3] << 24) | (buffer[2] << 16) |
           (buffer[1] << 8)  | buffer[0];
}

/// Inserts a 32-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u32>(u32::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
    buffer[3] = ((value >> 24) & 0xFF);
}

template<>
inline i32::type little_endian::get<i32>(const uint8_t* buffer)
{
    return little_endian::get<u32>(buffer);
}

template<>
inline void little_endian::put<i32>(i32::type value, uint8_t* buffer)
{
    little_endian::put<u32>(value, buffer);
}

/// Gets a 40-bit value integer which is in little-endian format from a
/// byte stream.
template<>
inline u40::type little_endian::get<u40>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (((uint64_t) buffer[4]) << 32) |
           (((uint64_t) buffer[3]) << 24) |
           (((uint64_t) buffer[2]) << 16) |
           (((uint64_t) buffer[1]) << 8)  |
           ((uint64_t) buffer[0]);
}


/// Inserts a 64-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u40>(u40::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
    buffer[3] = ((value >> 24) & 0xFF);
    buffer[4] = ((value >> 32) & 0xFF);
}

/// Gets a 48-bit value integer which is in little-endian format from a
/// byte stream.
template<>
inline u48::type little_endian::get<u48>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (((uint64_t) buffer[5]) << 40) |
           (((uint64_t) buffer[4]) << 32) |
           (((uint64_t) buffer[3]) << 24) |
           (((uint64_t) buffer[2]) << 16) |
           (((uint64_t) buffer[1]) << 8)  |
           (((uint64_t) buffer[0]));
}


/// Inserts a 48-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u48>(u48::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
    buffer[3] = ((value >> 24) & 0xFF);
    buffer[4] = ((value >> 32) & 0xFF);
    buffer[5] = ((value >> 40) & 0xFF);
}

/// Gets a 56-bit value integer which is in little-endian format from a
/// byte stream.
template<>
inline u56::type little_endian::get<u56>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (((uint64_t) buffer[6]) << 48) |
           (((uint64_t) buffer[5]) << 40) |
           (((uint64_t) buffer[4]) << 32) |
           (((uint64_t) buffer[3]) << 24) |
           (((uint64_t) buffer[2]) << 16) |
           (((uint64_t) buffer[1]) << 8)  |
           (((uint64_t) buffer[0]));
}


/// Inserts a 56-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u56>(u56::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
    buffer[3] = ((value >> 24) & 0xFF);
    buffer[4] = ((value >> 32) & 0xFF);
    buffer[5] = ((value >> 40) & 0xFF);
    buffer[6] = ((value >> 48) & 0xFF);
}

/// Gets a 64-bit value integer which is in little-endian format from a
/// byte stream.
template<>
inline u64::type little_endian::get<u64>(const uint8_t* buffer)
{
    assert(buffer != nullptr);
    return (((uint64_t) buffer[7]) << 56) |
           (((uint64_t) buffer[6]) << 48) |
           (((uint64_t) buffer[5]) << 40) |
           (((uint64_t) buffer[4]) << 32) |
           (((uint64_t) buffer[3]) << 24) |
           (((uint64_t) buffer[2]) << 16) |
           (((uint64_t) buffer[1]) << 8)  |
           (((uint64_t) buffer[0]));
}


/// Inserts a 64-bit value into a byte stream in little-endian format.
/// @copydetails put8()
template<>
inline void little_endian::put<u64>(u64::type value, uint8_t* buffer)
{
    assert(buffer != nullptr);
    buffer[0] = (value & 0xFF);
    buffer[1] = ((value >> 8) & 0xFF);
    buffer[2] = ((value >> 16) & 0xFF);
    buffer[3] = ((value >> 24) & 0xFF);
    buffer[4] = ((value >> 32) & 0xFF);
    buffer[5] = ((value >> 40) & 0xFF);
    buffer[6] = ((value >> 48) & 0xFF);
    buffer[7] = ((value >> 56) & 0xFF);
}

template<>
inline i64::type little_endian::get<i64>(const uint8_t* buffer)
{
    return little_endian::get<u64>(buffer);
}

template<>
inline void little_endian::put<i64>(i64::type value, uint8_t* buffer)
{
    little_endian::put<u64>(value, buffer);
}
}
