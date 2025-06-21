/* snprintf.c - snprintf */

#include <stdarg.h>

static int snprntf(int, int);
extern void _fdoprnt(char *, va_list, int (*func) (int, int), int);

static int max_chars;
static int char_count;

/*------------------------------------------------------------------------
 *  snprintf  -  Format arguments and place output in a string with size limit.
 *------------------------------------------------------------------------
 */
int	snprintf(
	  char		*str,		/* output string		*/
	  int		size,		/* maximum chars to write	*/
	  char		*fmt,		/* format string		*/
	  ...
	)
{
    va_list ap;
    char *s;

    if (size <= 0) {
        return 0;
    }

    s = str;
    max_chars = size - 1;  /* Reserve space for null terminator */
    char_count = 0;
    
    va_start(ap, fmt);
    _fdoprnt(fmt, ap, snprntf, (int)&s);
    va_end(ap);
    
    *s = '\0';  /* Null terminate */

    return char_count;
}

/*------------------------------------------------------------------------
 *  snprntf  -  Routine called by _doprnt to handle each character with bounds checking.
 *------------------------------------------------------------------------
 */
static int	snprntf(
		  int		acpp,
		  int		ac
		)
{
    char **cpp = (char **)acpp;
    char c = (char)ac;

    if (char_count < max_chars) {
        *(*cpp)++ = c;
        char_count++;
        return c;
    }
    
    return 0;  /* Buffer full, stop writing */
}