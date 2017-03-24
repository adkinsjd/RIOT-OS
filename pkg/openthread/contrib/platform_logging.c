/*
 * Copyright (C) 2016 José Ignacio Alamos
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @{
 *
 * @file
 * @author  José Ignacio Alamos <jialamos@uc.cl>
 * @author  Hyung-Sin Kim <hs.kim@berkeley.edu>
 */

#include <ctype.h>
#include <inttypes.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>

#include <openthread/platform/logging.h>

/* adapted from OpenThread posix example:
 * See: https://github.com/openthread/openthread/blob/master/examples/platforms/posix/logging.c */
void otPlatLog(otLogLevel aLogLevel, otLogRegion aLogRegion, const char *aFormat, ...)
{
    va_list args;

	printf("fopen\n");
    switch (aLogLevel) {
        case kLogLevelNone:
            fprintf(stderr, "NONE ");
            break;

        case kLogLevelCrit:
            fprintf(stderr, "CRIT ");
            break;

        case kLogLevelWarn:
            fprintf(stderr, "WARN ");
            break;

        case kLogLevelInfo:
            fprintf(stderr, "INFO ");
            break;

        case kLogLevelDebg:
            fprintf(stderr, "DEBG ");
            break;
    }

    switch (aLogRegion) {
        case kLogRegionApi:
            fprintf(stderr, "API  ");
            break;

        case kLogRegionMle:
            fprintf(stderr, "MLE  ");
            break;

        case kLogRegionArp:
            fprintf(stderr, "ARP  ");
            break;

        case kLogRegionNetData:
            fprintf(stderr, "NETD ");
            break;

        case kLogRegionIp6:
            fprintf(stderr, "IPV6 ");
            break;

        case kLogRegionIcmp:
            fprintf(stderr, "ICMP ");
            break;

        case kLogRegionMac:
            fprintf(stderr, "MAC  ");
            break;

        case kLogRegionMem:
            fprintf(stderr, "MEM  ");
            break;  

		case kLogRegionPlatform:
            fprintf(stderr, "Plat ");
            break;

		case kLogRegionNcp:
            fprintf(stderr, "NCP  ");
            break;

		case kLogRegionMeshCoP:
            fprintf(stderr, "MESH ");
            break;

   		case kLogRegionNetDiag:
            fprintf(stderr, "NETDi");
            break;

    }

    va_start(args, aFormat);
    vfprintf(stderr, aFormat, args);
    fprintf(stderr, "\r");
    va_end(args);
}
/** @} */
