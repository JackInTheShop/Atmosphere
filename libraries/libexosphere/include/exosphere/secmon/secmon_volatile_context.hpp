/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours.hpp>

namespace ams::secmon {

    /* The VolatileStack page is reserved entirely for use for core 3 SMC handling. */
    constexpr inline const Address Core3SmcStackAddress = MemoryRegionVirtualTzramVolatileStack.GetAddress() + MemoryRegionVirtualTzramVolatileStack.GetSize();

    constexpr inline const size_t CoreExceptionStackSize = 0x80;

    /* Nintendo uses the bottom 0x740 of this as a stack for warmboot setup, and another 0x740 for the core 0/1/2 SMC stacks. */
    /* This is...wasteful. The warmboot stack is not deep. We will thus save 1K+ of nonvolatile storage by keeping the random cache in here. */
    struct VolatileData {
        u8 random_cache[0x400];
        u8 se_work_block[crypto::AesEncryptor128::BlockSize];
        u8 reserved_danger_zone[0x30]; /* This memory is "available", but careful consideration must be taken before declaring it used. */
        u8 warmboot_stack[0x380];
        u8 core012_smc_stack[0x6C0];
        u8 core_exception_stacks[3][CoreExceptionStackSize];
    };
    static_assert(util::is_pod<VolatileData>::value);
    static_assert(sizeof(VolatileData) == 0x1000);

    ALWAYS_INLINE VolatileData &GetVolatileData() {
        return *MemoryRegionVirtualTzramVolatileData.GetPointer<VolatileData>();
    }

    ALWAYS_INLINE u8 *GetRandomBytesCache() {
        return GetVolatileData().random_cache;
    }

    constexpr ALWAYS_INLINE size_t GetRandomBytesCacheSize() {
        return sizeof(VolatileData::random_cache);
    }

    ALWAYS_INLINE u8 *GetSecurityEngineEphemeralWorkBlock() {
        return GetVolatileData().se_work_block;
    }

    constexpr inline const Address WarmbootStackAddress   = MemoryRegionVirtualTzramVolatileData.GetAddress() + offsetof(VolatileData, warmboot_stack)    + sizeof(VolatileData::warmboot_stack);
    constexpr inline const Address Core012SmcStackAddress = MemoryRegionVirtualTzramVolatileData.GetAddress() + offsetof(VolatileData, core012_smc_stack) + sizeof(VolatileData::core012_smc_stack);

    constexpr inline const Address Core0ExceptionStackAddress = MemoryRegionVirtualTzramVolatileData.GetAddress() + offsetof(VolatileData, core_exception_stacks) + CoreExceptionStackSize;
    constexpr inline const Address Core1ExceptionStackAddress = Core0ExceptionStackAddress + CoreExceptionStackSize;
    constexpr inline const Address Core2ExceptionStackAddress = Core1ExceptionStackAddress + CoreExceptionStackSize;

}
