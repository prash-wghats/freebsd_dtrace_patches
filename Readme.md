Patches for DTrace in FreeBSD that i find useful.
Tested in FreeBSD 11.0-RELEASE-p1 AMD64.

*) uregs.diff - (AMD64)
	In illumos SS is the highest numbered register from regset.h (i386). 
But in FreeBSD it is GS.

*) libproc_PGRAB_RDONLY.diff. 
	If PGRAB_RDONLY is set while calling Pgrab() (proc_attach), dtrace only needs access
to symbol of the process. But in FreeBSD (PGRAB_RDONLY == 0) control thread is created and it is
not cached.For example for ustack() action for each invocation of ustack 
the process is grabbed (control thread created) and detached
(control thread deleted).

*) fasttrap_isa_modrm.diff. 
	condition missing for FASTTRAP_GROUP5_OP.

*) fasttrap_signals.diff. 
	This is a implementation of asynchronous and synchronous signal handling for
 pid provider.
 http://dtrace.org/blogs/bmc/2011/03/09/when-magic-collides/
 http://www.archivum.info/dtrace-discuss@opensolaris.org/2007-02/00098/Re-%28dtrace-discuss%29-Asynchronous-signal-handling-in-fasttrap-provider.html
 
