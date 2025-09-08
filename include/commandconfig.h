#ifndef LYT_COMMAND_CONFIG_H
#define LYT_COMMAND_CONFIG_H

#include <stdint.h>
#include <stdbool.h>

struct lytCommandConfig {
    uint16_t opcode_id;
    uint8_t domain;
    uint16_t mode_mask;
    uint16_t attrib_flags;
    uint8_t impl_class;
    uint64_t hash_key;
};

#endif


