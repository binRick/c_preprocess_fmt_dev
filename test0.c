#include <string.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>

char bufs[10][1024];

#define FMT_TEMPLATE "Test #%d> abc:'%s', 123: '%d', 999999999: '%lu'"

#define FMT_buffer(buffer, fmt, ...) fmt_str(sizeof(buffer), (buffer), (fmt), __VA_ARGS__)

#define FMT_len(len, fmt, ...) fmt_len(len, (fmt), __VA_ARGS__)

inline static char *fmt_len(size_t len, const char fmt[restrict],...) {
    char buffer[len];
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buffer, len, fmt, ap);
    va_end(ap);
    return strdup(buffer);
}

inline static char *fmt_str(size_t len, char buffer[restrict static len], const char fmt[restrict],...) {
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(buffer, len, fmt, ap);
    va_end(ap);
    return buffer;
}




int main(void) {
  printf("%s\n", FMT_buffer(bufs[0], FMT_TEMPLATE, 0, "abc", 123, 999999999));
  printf("%s\n", FMT_buffer(bufs[1], FMT_TEMPLATE, 1, "abc", 123, 999999999));
  printf("%s\n", FMT_len(1024, FMT_TEMPLATE, 1, "abc", 123, 999999999));

  return(0);
}
