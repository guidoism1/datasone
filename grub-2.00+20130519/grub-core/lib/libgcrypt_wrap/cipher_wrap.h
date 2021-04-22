/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2009  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_GCRY_WRAP_HEADER
#define GRUB_GCRY_WRAP_HEADER 1

#include <grub/types.h>
#include <grub/mm.h>
#include <grub/misc.h>
#include <grub/dl.h>
#include <grub/crypto.h>

#include <sys/types.h>

#undef __GNU_LIBRARY__
#define __GNU_LIBRARY__ 1

#define U64_C(c) (c ## ULL)

#define PUBKEY_FLAG_NO_BLINDING    (1 << 0)

#define CIPHER_INFO_NO_WEAK_KEY    1

#define HAVE_U64_TYPEDEF 1

/* Selftests are in separate modules.  */
static inline char *
selftest (void)
{
  return NULL;
}

static inline int
fips_mode (void)
{
  return 0;
}

#ifdef GRUB_UTIL
#pragma GCC diagnostic ignored "-Wshadow"

static inline void *
memset (void *s, int c, grub_size_t n)
{
  return grub_memset (s, c, n);
}

#pragma GCC diagnostic error "-Wshadow"
#endif


#define DBG_CIPHER 0

#include <string.h>
#pragma GCC diagnostic ignored "-Wredundant-decls"
#include <grub/gcrypt/g10lib.h>
#include <grub/gcrypt/gcrypt.h>

#define gcry_mpi_mod _gcry_mpi_mod

#endif
