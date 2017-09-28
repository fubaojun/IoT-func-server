/*
 * Copyright (c) 2010 Espressif System
 */

#ifndef _OSAPI_H_
#define _OSAPI_H_

#include <string.h>
#include <stdio.h>

//#define os_bzero ets_bzero
//#define os_delay_us ets_delay_us
//#define os_install_putc1 ets_install_putc1

#define os_memcmp memcmp
#define os_memcpy memcpy
#define os_memmove memmove
#define os_memset memset
#define os_strcat strcat
#define os_strchr strchr
#define os_strcmp strcmp
#define os_strcpy strcpy
#define os_strlen strlen
#define os_strncmp strncmp
#define os_strncpy strncpy
#define os_strstr strstr
/* #ifdef USE_US_TIMER
#define os_timer_arm_us(a, b, c) ets_timer_arm_new(a, b, c, 0)
#endif
#define os_timer_arm(a, b, c) ets_timer_arm_new(a, b, c, 1)
#define os_timer_disarm ets_timer_disarm
#define os_timer_setfn ets_timer_setfn
 */
#define os_sprintf  sprintf


#define os_printf	printf

#endif

