#ifndef _MORPHY_LIBMEALY_C_API_H
#define _MORPHY_LIBMEALY_C_API_H

#include "mealy_config.h"
#include "mealy_shared_structs.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum _mealy_dump_type {
    MEALY_DUMP_TO_STDOUT,
    MEALY_DUMP_TO_STDERR,
    MEALY_DUMP_TO_FILE
} mealy_dump_type;

typedef struct _mealy_dump_options {
    mealy_dump_type     type;
    const char*         file_path;
    void*               __reserved1;
    void*               __reserved2;
    void*               __reserved3;
    void*               __reserved4;
} mealy_dump_options;

MEALY_API mealy_descriptor* mealy_open(const char* filePath, int slowAccess, mealy_error* error);
MEALY_API mealy_descriptor* mealy_mmap(const char* filePath, int slowAccess, mealy_error* error);
MEALY_API mealy_descriptor* mealy_attach(const void* data, uint32_t data_size, int slowAccess, mealy_error* error);
MEALY_API void mealy_close(mealy_descriptor* desc);

MEALY_API const mealy_header_info* mealy_header(mealy_descriptor* desc);
MEALY_API int mealy_walk(mealy_descriptor* desc, const void* string, int string_size, const void* start_state, mealy_walk_result* result);
MEALY_API const void* mealy_get_root(mealy_descriptor* desc);
MEALY_API int mealy_has_annot(mealy_descriptor* desc);
MEALY_API uint32_t mealy_collect(mealy_descriptor* desc, const void* start, mealy_collect_callback callback, void* user_data);
MEALY_API uint32_t mealy_collect_annots(mealy_descriptor* desc, mealy_collect_annot_callback callback, void* user_data);
MEALY_API void mealy_version(const char** ver, int* major, int* minor, int* patch);
MEALY_API int mealy_dump(mealy_descriptor* desc, const mealy_dump_options* options);

#ifdef __cplusplus
}
#endif

#endif // _MORPHY_LIBMEALY_C_API_H
