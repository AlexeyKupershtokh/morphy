#ifndef _MORPHY_LIBMEALY_SHARED_STRUCTS_H
#define _MORPHY_LIBMEALY_SHARED_STRUCTS_H

#include "mealy_config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _mealy_header_info_flags {
    int is_tree;
    int is_hash;
    int is_sparse;
    int is_be;
} mealy_header_info_flags;

typedef struct _mealy_header_info {
    char                        four_cc[5];
    uint32_t                    ver;
    mealy_header_info_flags     flags;
    
    uint32_t                    alphabet_offset;
    uint32_t                    fsa_offset;
    uint32_t                    annot_offset;
    
    uint32_t                    alphabet_size;
    uint32_t                    transes_count;
    
    uint32_t                    annot_length_size;
    uint32_t                    annot_chunk_size;
    uint32_t                    annot_chunks_count;
    
    uint32_t                    char_size;
    uint32_t                    padding_size;
    uint32_t                    dest_size;
    uint32_t                    hash_size;
    uint32_t                    trans_size;
} mealy_header_info;

typedef struct _mealy_walk_result_annot {
    const void* data;
    uint32_t    size;
    uint32_t    offset;
} mealy_walk_result_annot;

typedef struct _mealy_walk_result {
    uint32_t                walked;
    const void*             last_state;
    
    mealy_walk_result_annot annot;
} mealy_walk_result;

typedef struct _mealy_descriptor {
    void*   dict;
    void*   source;
} mealy_descriptor;

typedef struct _mealy_error {
    char what[MEALY_ERROR_MAX_LENGTH];
} mealy_error;

#define MEALY_NO_ERROR NULL

typedef int (MEALY_CALLCONV *mealy_collect_callback)(const void *data, uint32_t dataSize, const mealy_walk_result_annot* annot, void* usedData);
typedef int (MEALY_CALLCONV *mealy_collect_annot_callback)(const mealy_walk_result_annot* annot, void* userData);

#ifdef __cplusplus
}
#endif

#endif // _MORPHY_LIBMEALY_SHARED_STRUCTS_H
