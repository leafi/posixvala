posixvala
=========

This fork of the project is posixvala, but with bits of GObject and 
Mono's eGLib (and even real GLib) hacked in.  
Normal posixvala is wonderful and supports classes with [Compact] on 
them.

This fork at least compiles non-[Compact] classes - so that's nice.
We haven't got any signals and our GObject doesn't currently know
about any types at all, though.  And we don't have proper mutex impl.
This is just step one.

Despite the modifications, we still only depend on bog-standard libc calls.

Instead of modifying the compiler, posixvala reimplements the
basic features of GLib in tiny include files to let the generated
C code compile without any other dependency than libc.

Not all features of Vala are currently supported by posixvala
and it is not suposed to perform as well as GLib (lacks slices
and other libraries) and posixvala programs cannot link against
glib libraries.

Current supported features are:

* Vala and Genie
* compact classes
* New: non-compact classes!
* New: somewhat broken version of the GObject type system!
* string processing
* List and SList
* exceptions
* delegates
* structs
