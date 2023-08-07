// Bundle API auto-generated header file. Do not edit!
// Glow Tools version: 2023-01-13 (b91adff10) ()

#ifndef _GLOW_BUNDLE_NET_5_H
#define _GLOW_BUNDLE_NET_5_H

#include <stdint.h>

// ---------------------------------------------------------------
//                       Common definitions
// ---------------------------------------------------------------
#ifndef _GLOW_BUNDLE_COMMON_DEFS
#define _GLOW_BUNDLE_COMMON_DEFS

// Glow bundle error code for correct execution.
#define GLOW_SUCCESS 0

// Memory alignment definition with given alignment size
// for static allocation of memory.
#define GLOW_MEM_ALIGN(size)  __attribute__((aligned(size)))

// Macro function to get the absolute address of a
// placeholder using the base address of the mutable
// weight buffer and placeholder offset definition.
#define GLOW_GET_ADDR(mutableBaseAddr, placeholderOff)  (((uint8_t*)(mutableBaseAddr)) + placeholderOff)

#endif

// ---------------------------------------------------------------
//                          Bundle API
// ---------------------------------------------------------------
// Model name: "net_5"
// Total data size: 9280 (bytes)
// Activations allocation efficiency: 1.0000
// Placeholders:
//
//   Name: "net_input"
//   Type: float<1 x 1>
//   Size: 1 (elements)
//   Size: 4 (bytes)
//   Offset: 0 (bytes)
//
//   Name: "net_output"
//   Type: float<1 x 1>
//   Size: 1 (elements)
//   Size: 4 (bytes)
//   Offset: 64 (bytes)
//
// NOTE: Placeholders are allocated within the "mutableWeight"
// buffer and are identified using an offset relative to base.
// ---------------------------------------------------------------
#ifdef __cplusplus
extern "C" {
#endif

// Placeholder address offsets within mutable buffer (bytes).
#define NET_5_net_input   0
#define NET_5_net_output  64

// Memory sizes (bytes).
#define NET_5_CONSTANT_MEM_SIZE     8896
#define NET_5_MUTABLE_MEM_SIZE      128
#define NET_5_ACTIVATIONS_MEM_SIZE  256

// Memory alignment (bytes).
#define NET_5_MEM_ALIGN  64

// Bundle entry point (inference function). Returns 0
// for correct execution or some error code otherwise.
int net_5(uint8_t *constantWeight, uint8_t *mutableWeight, uint8_t *activations);

#ifdef __cplusplus
}
#endif
#endif