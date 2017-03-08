#ifndef PUBLIC_SDY_DEV_H_INCLUDED
#define PUBLIC_SDY_DEV_H_INCLUDED
#include "SDY.h"

typedef enum {
    SDY_FALSE = 0,
    SDY_TRUE  = 1,
}SDY_BOOLEAN;

typedef enum {
    SDY_BOOLEAN_VALUE = 1,
    SDY_INT_VALUE,
    SDY_DOUBLE_VALUE,
    SDY_STRING_VALUE,
    SDY_NATIVE_POINTER_VALUE,
    SDY_NULL_VALUE,
}SDY_ValueType;

typedef struct {
    SDY_ValueType type;
    union {
        SDY_BOOLEAN boolean_value;
    }
};

#endif 