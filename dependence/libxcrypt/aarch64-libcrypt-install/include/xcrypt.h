/* libxcrypt interfaces for code compatibility.

   Copyright (C) 2018 Björn Esser <besser82@fedoraproject.org>

   Redistribution and use in source and binary forms, with or without
   modification, are permitted.

   THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
   FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
   DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
   OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
   HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
   OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
   SUCH DAMAGE.  */

#ifndef _XCRYPT_H
#define _XCRYPT_H 1

#include <crypt.h>

#include <sys/cdefs.h>

__BEGIN_DECLS

/* For backward compatibility with older versions (v3.1.1 and earlier)
   of libcrypt, this header declares xcrypt, xcrypt_r, xcrypt_gensalt,
   and xcrypt_gensalt_r as alternative names for crypt, crypt_r,
   crypt_gensalt, and crypt_gensalt_rn, respectively.  If glibc's
   <sys/cdefs.h> macro __REDIRECT_NTH (which declares an alternative
   name at the object-file level) is available, we use it.  */
#ifdef __REDIRECT_NTH
extern char * __REDIRECT_NTH (xcrypt, (const char *__phrase,
                              const char *__setting), crypt);

extern char * __REDIRECT_NTH (xcrypt_r, (const char *__phrase,
                              const char *__setting,
                              struct crypt_data *__restrict __data), crypt_r);

extern char * __REDIRECT_NTH (xcrypt_gensalt, (const char *__prefix,
                              unsigned long __count, const char *__rbytes,
                              int __nrbytes), crypt_gensalt);

extern char * __REDIRECT_NTH (xcrypt_gensalt_r, (const char *__prefix,
                              unsigned long __count, const char *__rbytes,
                              int __nrbytes, char *__output,
                              int __output_size), crypt_gensalt_rn);
#else
# define xcrypt           crypt
# define xcrypt_r         crypt_r
# define xcrypt_gensalt   crypt_gensalt
# define xcrypt_gensalt_r crypt_gensalt_rn
#endif

__END_DECLS

#endif /* xcrypt.h */
