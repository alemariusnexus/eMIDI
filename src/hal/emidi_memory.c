#define _DEFAULT_SOURCE
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
#include <string.h>

extern const unsigned char pMidi[];
static uint32_t _fileSize = 0;
static int _filePos = 0;
static char* _pFile = NULL;

int eMidi_timeUs() {
  struct timespec t;
  clock_gettime(CLOCK_MONOTONIC, &t);

  return t.tv_sec * 1000000 + t.tv_nsec / 1000;
}

FILE* eMidi_fopen(const char* pPathName, const char* pMode) {
  char* p = (char*)pMidi;
  memcpy(&_fileSize, p, sizeof(uint32_t));

  _pFile = &p[4];
  _filePos = 0;

  return (FILE*)_pFile;
}

int eMidi_fclose(FILE* pStream) {
  _filePos = -1;

  return 0;
}

long eMidi_ftell(FILE* pStream) {
  return _filePos;
}

int eMidi_fseek(FILE* pStream, long offset, int whence) {
  switch(whence) {
    case SEEK_CUR: _filePos += offset;   break;
    case SEEK_SET: _filePos = 0;         break;
    case SEEK_END: _filePos = _fileSize; break;
      break;

    default:
      return -1;
  }

  return 0;
}

size_t eMidi_fread(void* p, size_t size, size_t nmemb, FILE* pStream) {
  int toRead = nmemb;

  memcpy(p, &_pFile[_filePos], toRead);
  _filePos += toRead;

  return toRead;
}

size_t eMidi_fwrite(const void* p, size_t size, size_t nmemb, FILE* pStream) {
  return -1; // Not supported
}

int eMidi_printf(const char* pFormat, ...) {
  va_list args;
  va_start(args, pFormat);

  vprintf(pFormat, args);

  va_end(args);
}

