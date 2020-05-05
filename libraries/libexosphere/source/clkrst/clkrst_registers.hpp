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
#include <exosphere.hpp>

namespace ams::clkrst {

    /* Clock source enums. */
    #define CLK_RST_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (CLK_RST_CONTROLLER, NAME)
    #define CLK_RST_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (CLK_RST_CONTROLLER, NAME, VALUE)
    #define CLK_RST_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (CLK_RST_CONTROLLER, NAME, ENUM)
    #define CLK_RST_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(CLK_RST_CONTROLLER, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

    #define DEFINE_CLK_RST_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (CLK_RST_CONTROLLER, NAME, __OFFSET__, __WIDTH__)
    #define DEFINE_CLK_RST_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE)
    #define DEFINE_CLK_RST_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
    #define DEFINE_CLK_RST_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
    #define DEFINE_CLK_RST_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (CLK_RST_CONTROLLER, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)


    #define CLK_RST_CONTROLLER_RST_SOURCE    (0x000)

    #define CLK_RST_CONTROLLER_MISC_CLK_ENB  (0x048)

    DEFINE_CLK_RST_REG(MISC_CLK_ENB_CFG_ALL_VISIBLE, 28, 1);

    /* RST_DEVICES */
    #define CLK_RST_CONTROLLER_RST_DEVICES_L (0x004)
    #define CLK_RST_CONTROLLER_RST_DEVICES_H (0x008)
    #define CLK_RST_CONTROLLER_RST_DEVICES_U (0x00C)
    #define CLK_RST_CONTROLLER_RST_DEVICES_X (0x28C)
    #define CLK_RST_CONTROLLER_RST_DEVICES_Y (0x2A4)
    #define CLK_RST_CONTROLLER_RST_DEVICES_V (0x358)
    #define CLK_RST_CONTROLLER_RST_DEVICES_W (0x35C)

    /* CLK_OUT_ENB */
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_L (0x010)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_H (0x014)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_U (0x018)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_X (0x280)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_Y (0x298)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_V (0x360)
    #define CLK_RST_CONTROLLER_CLK_OUT_ENB_W (0x364)

    /* CLK_SOURCE */
    #define CLK_RST_CONTROLLER_CLK_SOURCE_UARTA (0x178)
    #define CLK_RST_CONTROLLER_CLK_SOURCE_UARTB (0x17C)
    #define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC (0x1A0)

    /* CLK_ENB_*_INDEX */
    #define CLK_RST_CONTROLLER_CLK_ENB_UARTA_INDEX (0x06)
    #define CLK_RST_CONTROLLER_CLK_ENB_UARTB_INDEX (0x07)
    #define CLK_RST_CONTROLLER_CLK_ENB_UARTC_INDEX (0x17)

    DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTA_UARTA_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2)
    DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTB_UARTB_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2)
    DEFINE_CLK_RST_REG_THREE_BIT_ENUM(CLK_SOURCE_UARTC_UARTC_CLK_SRC, 29, PLLP_OUT0, PLLC2_OUT0, PLLC_OUT0, PLLC4_OUT0, RESERVED4, PLLC4_OUT1, CLK_M, PLLC4_OUT2)

}
