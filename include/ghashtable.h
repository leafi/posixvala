/* from mono/eglib/src/glib.h, for mono/eglib/src/ghashtable.c */

#ifndef __G_HASHTABLE_H__
#define __G_HASHTABLE_H__

/*
 * Hashtables
 */
typedef struct _GHashTable GHashTable;
typedef struct _GHashTableIter GHashTableIter;

/* Private, but needed for stack allocation */
struct _GHashTableIter
{
        gpointer dummy [8];
};

GHashTable     *g_hash_table_new             (GHashFunc hash_func, GEqualFunc key_equal_func);
GHashTable     *g_hash_table_new_full        (GHashFunc hash_func, GEqualFunc key_equal_func,
                                              GDestroyNotify key_destroy_func, GDestroyNotify value_destroy_func);
void            g_hash_table_insert_replace  (GHashTable *hash, gpointer key, gpointer value, gboolean replace);
guint           g_hash_table_size            (GHashTable *hash);
GList          *g_hash_table_get_keys        (GHashTable *hash);
GList          *g_hash_table_get_values      (GHashTable *hash);
gpointer        g_hash_table_lookup          (GHashTable *hash, gconstpointer key);
gboolean        g_hash_table_lookup_extended (GHashTable *hash, gconstpointer key, gpointer *orig_key, gpointer *value);
void            g_hash_table_foreach         (GHashTable *hash, GHFunc func, gpointer user_data);
gpointer        g_hash_table_find            (GHashTable *hash, GHRFunc predicate, gpointer user_data);
gboolean        g_hash_table_remove          (GHashTable *hash, gconstpointer key);
gboolean        g_hash_table_steal           (GHashTable *hash, gconstpointer key);
void            g_hash_table_remove_all      (GHashTable *hash);
guint           g_hash_table_foreach_remove  (GHashTable *hash, GHRFunc func, gpointer user_data);
guint           g_hash_table_foreach_steal   (GHashTable *hash, GHRFunc func, gpointer user_data);
void            g_hash_table_destroy         (GHashTable *hash);
void            g_hash_table_print_stats     (GHashTable *table);

void            g_hash_table_iter_init       (GHashTableIter *iter, GHashTable *hash_table);
gboolean        g_hash_table_iter_next       (GHashTableIter *iter, gpointer *key, gpointer *value);

guint           g_spaced_primes_closest      (guint x);

#define g_hash_table_insert(h,k,v)    g_hash_table_insert_replace ((h),(k),(v),FALSE)
#define g_hash_table_replace(h,k,v)   g_hash_table_insert_replace ((h),(k),(v),TRUE)

gboolean g_direct_equal (gconstpointer v1, gconstpointer v2);
guint    g_direct_hash  (gconstpointer v1);
gboolean g_int_equal    (gconstpointer v1, gconstpointer v2);
guint    g_int_hash     (gconstpointer v1);
gboolean g_str_equal    (gconstpointer v1, gconstpointer v2);
guint    g_str_hash     (gconstpointer v1);

#endif
