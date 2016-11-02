/* Tested in FreeBSD 11.0-RELEASE-p1 AMD64,  xorg-server-1.17.4,1 */
/* From disassembly of FreeResource function in xorg server */
/* 461bc4:	ff 14 08             	callq  *(%rax,%rcx,1) */

pid$target:Xorg:FreeResource:f4
{
	@[probefunc]=count();
}
