#ifndef EMIDI_TYPES_H
#define EMIDI_TYPES_H

#include <stdint.h>

enum {
  EMIDI_OK                     = 0x0000,
  EMIDI_OK_END_OF_FILE         = 0x0001,
  EMIDI_OK_END_OF_PORTS        = 0x0002,

  EMIDI_INVALID_HANDLE         = 0x1000,
  EMIDI_CANNOT_OPEN_FILE       = 0x1001,
  EMIDI_INVALID_MIDI_FILE      = 0x1002,
  EMIDI_SYNTAX_ERROR           = 0x1003,
  EMIDI_UNEXPECTED_END_OF_FILE = 0x1004,

  // remove as soon as supported:
  EMIDI_FORMAT_1_NOT_SUPPORTED        = 0x2000,
  EMIDI_FORMAT_2_NOT_SUPPORTED        = 0x2001,
  EMIDI_DIVISION_FORMAT_NOT_SUPPORTED = 0x2002
};

typedef uint32_t Error;

#endif // EMIDI_TYPES_H
