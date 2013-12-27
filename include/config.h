#ifndef __G_CONFIG_H__
#define __G_CONFIG_H__

#define GLIB_COMPILATION
#define GOBJECT_COMPILATION

/* I need this because my OS doesn't have pthreads. If problematic for you, delete. */
#define G_ATOMIC_LOCK_FREE

/* wtf */
#include "glib.h"



/* BAD THINGS */
/* gtype.c keeps wanting to talk to mutexes. ehh... */
/* people who aren't me should crib from gthread-posix.c here. */
typedef union _GMutex GMutex;
typedef struct _GRecMutex GRecMutex;
typedef struct _GRWLock GRWLock;

union _GMutex
{
  gpointer p;
  guint i[2];
};

struct _GRWLock
{
  gpointer p;
  guint i[2];
};

struct _GRecMutex
{
  gpointer p;
  guint i[2];
};

static inline void g_rec_mutex_init(GRecMutex *r) { }
static inline void g_rec_mutex_clear(GRecMutex *r) { }
static inline void g_rec_mutex_lock(GRecMutex *r) { }
static inline void g_rec_mutex_trylock(GRecMutex *r) { }
static inline void g_rec_mutex_unlock(GRecMutex *r) { }

static inline void g_rw_lock_writer_lock(GRWLock *rw) { }
static inline void g_rw_lock_writer_unlock(GRWLock *rw) { }
static inline void g_rw_lock_reader_lock(GRWLock *rw) { }
static inline void g_rw_lock_reader_unlock(GRWLock *rw) { }

static inline void g_mutex_lock(GMutex *m) { }
static inline void g_mutex_unlock(GMutex *m) { }

#define g_pointer_bit_lock(a,b)
#define g_pointer_bit_unlock(a,b)

#define G_LOCK_DEFINE_STATIC(lock)
#define G_LOCK(lock)
#define G_UNLOCK(lock)


#endif
