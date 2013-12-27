/* from mono/eglib/src/glib.h, for mono/eglib/src/gmem.c */

#ifndef __G_MEM_H__
#define __G_MEM_H__


/*
 * Allocation
 */
void g_free (void *ptr);
gpointer g_realloc (gpointer obj, gsize size);
gpointer g_malloc (gsize x);
gpointer g_malloc0 (gsize x);
gpointer g_try_malloc (gsize x);
gpointer g_try_realloc (gpointer obj, gsize size);

#define g_new(type,size)        ((type *) g_malloc (sizeof (type) * (size)))
#define g_new0(type,size)       ((type *) g_malloc0 (sizeof (type)* (size)))
#define g_newa(type,size)       ((type *) alloca (sizeof (type) * (size)))

#define g_memmove(dest,src,len) memmove (dest, src, len)
#define g_renew(struct_type, mem, n_structs) g_realloc (mem, sizeof (struct_type) * n_structs)
#define g_alloca(size)                alloca (size)

gpointer g_memdup (gconstpointer mem, guint byte_size);
static inline gchar   *g_strdup (const gchar *str) { if (str) {return strdup (str);} return NULL; }
gchar **g_strdupv (gchar **str_array);

typedef struct {
        gpointer (*malloc)      (gsize    n_bytes);
        gpointer (*realloc)     (gpointer mem, gsize n_bytes);
        void     (*free)        (gpointer mem);
        gpointer (*calloc)      (gsize    n_blocks, gsize n_block_bytes);
        gpointer (*try_malloc)  (gsize    n_bytes);
        gpointer (*try_realloc) (gpointer mem, gsize n_bytes);
} GMemVTable;

#define g_mem_set_vtable(x)

struct _GMemChunk {
        guint alloc_size;
};

typedef struct _GMemChunk GMemChunk;


#endif
