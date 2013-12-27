/* LGPL3 - posixvala glib replacement - 2013 - pancake@nopcode.org */

#ifndef _GLIB_H_
#define _GLIB_H_

#ifdef __cplusplus
 #define G_BEGIN_DECLS	extern "C" {
 #define G_END_DECLS	}
#else
 #define G_BEGIN_DECLS
 #define G_END_DECLS
#endif /* __cplusplus */

G_BEGIN_DECLS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*#define g_malloc malloc
#define g_realloc realloc
#define g_calloc calloc*/

#define GLIB_DEPRECATED_FOR(f)
#define GLIB_DEPRECATED_IN_2_30_FOR(f)
#define GLIB_DEPRECATED_IN_2_34
#define GLIB_DEPRECATED_IN_2_36
#define GLIB_AVAILABLE_IN_ALL
#define GLIB_AVAILABLE_IN_2_30
#define GLIB_AVAILABLE_IN_2_34
#define GLIB_AVAILABLE_IN_2_36

// we have no DTrace. Remove the trace.
#define TRACE(probe)

#define G_STRUCT_OFFSET(struct_type, member) ((glong) ((guint8*) &((struct_type*) 0)->member))
#define G_STRUCT_MEMBER_P(struct_p, struct_offset) ((gpointer) ((guint8*) (struct_p) + (glong) (struct_offset)))
#define G_STRUCT_MEMBER(member_type, struct_p, struct_offset) (*(member_type*) G_STRUCT_MEMBER_P ((struct_p), (struct_offset)))

#define GPOINTER_TO_UINT(p) ((guint) (gulong) (p))
#define GUINT_TO_POINTER(u) ((gpointer) (gulong) (u))

/* ugh */
#define G_STATIC_ASSERT(expr)

#define G_GNUC_EXTENSION
#define G_GNUC_PURE  

/* mad hax (to avoid pulling in gparamspecs.h) */
#define G_TYPE_PARAM_OBJECT G_TYPE_PARAM
#define G_TYPE_PARAM_OVERRIDE (G_TYPE_PARAM + 2)     /* this is dodgy as shit */
typedef struct _GParamSpecOverride   GParamSpecOverride;


#define G_UNLIKELY(expr) (!(expr))
#define G_LIKELY(expr) (expr)
#define G_LOG_DOMAIN "ERROR"
#define G_STRFUNC __func__
#define G_STRLOC "g_strloc not impl; somewhere in glib or gobject..."
#define g_message printf
#define g_warning printf
#define g_error printf
#define g_assertion_message_expr(domain,file,line,func,expr)		\
do {									\
	if (!expr) {							\
		fprintf(stderr, "**\n%s:%s:%d:%s: %s\n",		\
			domain, file, line, func,			\
			"code should not be reached");			\
	} else {							\
		fprintf(stderr, "**\n%s:%s:%d:%s: "			\
				"assertion failed: (%s)\n",		\
				domain, file, line, func, expr);	\
	}								\
	abort();							\
} while (0)

//#define GTypeInterface void*
//#define GData void*
typedef struct _GData GData;  // defined in gobject/gtype.c?????
//#define GQuark unsigned int
//#define g_quark_from_static_string(x) ((GQuark)(size_t)(x))
#define gchar char
#define gpointer void*
#define gconstpointer const void*
#define gboolean int
#define gint int
#define guint unsigned int
#define gdouble double
/*#define gsize unsigned int
#define gssize int*/
/* gets rid of my warnings on 64-bit. changes the api but otherwise harmless. */
#define gsize unsigned long
#define gssize long
#define glong long
#define gulong unsigned long
#define gint8 char
#define guint8 unsigned char
#define gint16 short
#define guint16 unsigned short
#define gint32 int
#define guint32 unsigned int
#define gint64 long long
#define guint64 unsigned long long
#define gfloat float
/*#define g_new0(x,y) (x*)calloc (y, sizeof(x));*/
#define g_slice_new0(x) (x*)calloc (1, sizeof(x));
#define g_slice_new(x) (x*)malloc(sizeof(x));
#define g_slice_alloc(s) (gpointer)malloc(s);
#define g_slice_alloc0(s) (gpointer)calloc(1, s);
#define g_return_if_fail(x) if(!(x)) return;
#define g_return_val_if_fail(x,y) if (!(x)) return y;
#define g_slice_free(x,y) free(y)
#define g_slice_free1(x,y) free(y)
#define g_enum_register_static(x,y) (int)(size_t)(y),0

#define g_critical printf
#define TRUE 1
#define FALSE 0
#define G_GNUC_CONST
//#define GType int

static inline gboolean g_str_has_prefix (const gchar *str, const gchar *prefix)
{
  int str_len;
  int prefix_len;

  if ((str == NULL) || (prefix == NULL))
    return FALSE;

  str_len = strlen (str);
  prefix_len = strlen (prefix);

  if (str_len < prefix_len)
    return FALSE;

  return strncmp (str, prefix, prefix_len) == 0;
}

#define g_print printf
#define g_assert(expr) if (!(expr)) { printf("awful glib: g_assert FAILED\n"); }
/*#define g_strdup strdup*/
/*#define g_free free*/
typedef struct {
	int x;
	const char *n;
	const char *m;
} GEnumValue;

#define g_once_init_enter(x) ((*(x) == 0) ? TRUE : FALSE)
#define g_once_init_leave(x,y) (*(x) = y)
#define g_boxed_type_register_static(x, y, z) g_str_hash(x)

//static inline void g_type_init() {}
static inline void g_boxed() {}
typedef gpointer (*GBoxedCopyFunc)(gpointer s);
typedef void (*GBoxedFreeFunc)(gpointer s);
typedef void (*GFunc)(gpointer data, gpointer user_data);
typedef void (*GDestroyNotify)(gpointer data);

/* mono/eglib stuff */
typedef gint     (*GCompareFunc)   (gconstpointer a, gconstpointer b);
typedef gint     (*GCompareDataFunc) (gconstpointer a, gconstpointer b, gpointer user_data);
typedef void     (*GHFunc)         (gpointer key, gpointer value, gpointer user_data);
typedef gboolean (*GHRFunc)        (gpointer key, gpointer value, gpointer user_data);
typedef guint    (*GHashFunc)      (gconstpointer key);
typedef gboolean (*GEqualFunc)     (gconstpointer a, gconstpointer b);
typedef void     (*GFreeFunc)      (gpointer       data);

#define __GLIB_H_INSIDE__

/* from mono-eglib */
#include "gmem.h"

/* from real GLib source (more or less */
#include "gquark.h"

#include "gdataset.h"

/* original posixvala stuff */
#include "glib-string.h"
#include "glib-list.h"
#include "glib-error.h"

/* from real GLib source (more or less) */
#include "gatomic.h"
#include "gconstructor.h"
//#include "gdataset.h"

/* from mono/eglib (well, the .c was) */
#include "ghashtable.h"

/* real glib */

#undef __GLIB_H_INSIDE__

G_END_DECLS

#endif /* _GLIB_H_ */
