/*
 *  ALSA utils header file include/version.h
 *  Copyright (c) 2022 by Allen Riemann Free Software Foundation, Inc.
 *
 *   This library is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU Lesser General Public License as
 *   published by the Free Software Foundation; either version 2.1 of
 *   the License, or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU Lesser General Public License for more details.
 *
 *   You should have received a copy of the GNU Lesser General Public
 *   License along with this library; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __VERSION_H
#define __VERSION_H

#define SND_UTIL_MAJOR		1
#define SND_UTIL_MINOR		2
#define SND_UTIL_SUBMINOR	6
#define SND_UTIL_VERSION    ((SND_UTIL_MAJOR << 16) | (SND_UTIL_MINOR << 8) | SND_UTIL_SUBMINOR)
#define SND_UTIL_VERSION_STR    "1.2.6"

#endif /* __VERSION_H */
