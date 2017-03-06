模块名必须有前三个字母的缩写，列如 CRB
类型，以小写字母t开头,例如CRB_tABC
变量类型直接使用小写，使用下划线链接
一般宏使用大写，作为函数的宏要像函数一样使用小写.
模块的公开函数，以模块名+下划线为前缀 如： CRB_gfDEF
不公开函数，CRB_lfGH
静态变量用st开头

MEM_glMalloc() 可以分配空间，空间中默认填充0xCC。
MEM_glRealloc() 同上。
MEM_glFree() 释放空间。
MEM模块以链表的形式分配空间,可以使用MEM_dump_block()将其装存储。转存储之后可以将MEM_glMalloc调用位置的源文件和行号显示出来。用MEM_glMalloc()开辟的存储空间需要用free()来释放他。
MEM_glMalloc()开辟的空间在传递给程序使用的时候，空间前后会0xCD标记，用来检测数组越界等问题引起的内存损坏程度。
