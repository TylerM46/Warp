/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "fsl_misc_utilities.h"
#if (defined(__GNUC__) && (!defined(KDS)) && (!defined(ATOLLIC)))
#include <errno.h>
#endif
#include "fsl_debug_console.h"

#if (defined(__CC_ARM))

/*FUNCTION**********************************************************************
 *
 * Function Name : __aeabi_assert
 * Description   : called by assert in KEIL
 * This function is called by the assert function in KEIL.
 *
 *END**************************************************************************/
void __aeabi_assert(const char *expr, const char *file, int line)
{
    printf("assert failed:%s, file %s:%d\r\n",expr,file,line);
}

#elif (defined(KDS))

/*FUNCTION**********************************************************************
 *
 * Function Name : _isatty
 * Description   : used to enable the overwrite of the _write
 * This function is used to enable the overwrite of the _write.
 *
 *END**************************************************************************/
int _isatty (int fd) 
{ 
	return 1; 
}

#endif

#if (defined(__GNUC__) && (!defined(KDS)) && (!defined(ATOLLIC)))
void *
_sbrk (int incr)
{
  extern char   end asm ("end");
  extern char   heap_limit asm ("__HeapLimit");
  static char * heap_end;
  char *        prev_heap_end;

  if (heap_end == NULL)
    heap_end = & end;

  prev_heap_end = heap_end;

  if (heap_end + incr > &heap_limit)
    {
      errno = ENOMEM;
      return (void *) -1;
    }

  heap_end += incr;

  return (void *) prev_heap_end;
}
#endif

/*FUNCTION**********************************************************************
 *
 * Function Name : assert_func
 * Description   : Print out failure messages.
 * This function is used to print out failure messages.
 *
 *END**************************************************************************/
void assert_func(const char *file, int line, const char *func, const char *failedExpr)
{
    PRINTF("ASSERT ERROR \" %s \": file \"%s\" Line \"%d\" function name \"%s\" \n", failedExpr, file , line, func);

    for (;;)
    {}

}
/*******************************************************************************
 * EOF
 ******************************************************************************/
