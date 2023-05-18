// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16version()
{
    int _4812 = 0;
    int _0, _1, _2;
    

    //     c_puts("// Euphoria To C version " & TRANSLATOR_VERSION & "\n")
    {
        int concat_list[3];

        concat_list[0] = _629;
        concat_list[1] = _4TRANSLATOR_VERSION;
        concat_list[2] = _4811;
        Concat_N((object_ptr)&_4812, concat_list, 3);
    }
    RefDS(_4812);
    _9c_puts(_4812);

    // end procedure
    DeRefDSi(_4812);
    return 0;
    ;
}


int _16new_c_file(int _name)
{
    int _4821 = 0;
    int _4813 = 0;
    int _0, _1, _2;
    

    //     cfile_size = 0
    _4cfile_size = 0;

    //     if Pass != LAST_PASS then
    if (_16Pass == 7)
        goto L1;

    // 	return
    DeRefDS(_name);
    return 0;
L1:

    //     close(c_code)
    EClose(_9c_code);

    //     c_code = open(name & ".c", "w")
    Concat((object_ptr)&_4813, _name, (s1_ptr)_4814);
    _9c_code = EOpen(_4813, _623);

    //     if c_code = -1 then
    if (_9c_code != -1)
        goto L2;

    // 	CompileErr("Couldn't open .c file for output")
    RefDS(_4818);
    _6CompileErr(_4818);
L2:

    //     cfile_count += 1
    _4cfile_count = _4cfile_count + 1;

    //     version()
    _16version();

    //     if EDOS and sequence(dj_path) then
    if (_4EDOS == 0) {
        goto L3;
    }
    DeRef(_4821);
    _4821 = IS_SEQUENCE(_4dj_path);
L4:
    if (_4821 == 0)
        goto L3;

    // 	c_puts("#include <go32.h>\n")
    RefDS(_4822);
    _9c_puts(_4822);
L3:

    //     c_puts("#include \"")
    RefDS(_4823);
    _9c_puts(_4823);

    //     c_puts(eudir & SLASH & "include" & SLASH & "euphoria.h\"\n")
    {
        int concat_list[5];

        concat_list[0] = _4824;
        concat_list[1] = _4SLASH;
        concat_list[2] = _700;
        concat_list[3] = _4SLASH;
        concat_list[4] = _4eudir;
        Concat_N((object_ptr)&_4821, concat_list, 5);
    }
    RefDS(_4821);
    _9c_puts(_4821);

    //     c_puts("#include \"main-.h\"\n\n")
    RefDS(_4826);
    _9c_puts(_4826);

    //     if not ELINUX then
    if (_4ELINUX != 0)
        goto L5;

    // 	name = lower(name)  -- for faster compare later
    RefDS(_name);
    _0 = _name;
    _name = _3lower(_name);
    DeRefDS(_0);
L5:

    //     files_to_delete = append(files_to_delete, name & ".c")
    Concat((object_ptr)&_4821, _name, (s1_ptr)_4814);
    RefDS(_4821);
    Append(&_16files_to_delete, _16files_to_delete, _4821);

    // end procedure
    DeRefDS(_name);
    DeRefDS(_4821);
    DeRef(_4813);
    return 0;
    ;
}


int _16unique_c_name(int _name)
{
    int _i;
    int _compare_name = 0;
    int _next_fc;
    int _4832 = 0;
    int _0, _1, _2;
    

    //     compare_name = name & ".c"
    Concat((object_ptr)&_compare_name, _name, (s1_ptr)_4814);

    //     if not ELINUX then
    if (_4ELINUX != 0)
        goto L1;

    // 	compare_name = lower(compare_name)
    RefDS(_compare_name);
    _0 = _compare_name;
    _compare_name = _3lower(_compare_name);
    DeRefDS(_0);
L1:

    //     next_fc = 1
    _next_fc = 1;

    //     i = 1
    _i = 1;

    //     while i <= length(files_to_delete) do
L2:
    DeRef(_4832);
    _4832 = SEQ_PTR(_16files_to_delete)->length;
    if (_i > _4832)
        goto L3;

    // 	if equal(files_to_delete[i], compare_name) then
    _2 = (int)SEQ_PTR(_16files_to_delete);
    _4832 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4832);
    _0 = _4832;
    if (_4832 == _compare_name)
        _4832 = 1;
    else if (IS_ATOM_INT(_4832) && IS_ATOM_INT(_compare_name))
        _4832 = 0;
    else
        _4832 = (compare(_4832, _compare_name) == 0);
    DeRefDS(_0);
    if (_4832 == 0)
        goto L4;

    // 	    if next_fc > length(file_chars) then
    _4832 = 36;
    if (_next_fc <= 36)
        goto L5;

    // 		CompileErr("Sorry, too many .c files with the same base name")
    RefDS(_4841);
    _6CompileErr(_4841);
L5:

    // 	    name[1] = file_chars[next_fc]
    DeRef(_4832);
    _2 = (int)SEQ_PTR(_16file_chars);
    _4832 = (int)*(((s1_ptr)_2)->base + _next_fc);
    _2 = (int)SEQ_PTR(_name);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _name = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4832;
    DeRef(_1);

    // 	    compare_name = name & ".c"
    Concat((object_ptr)&_compare_name, _name, (s1_ptr)_4814);

    // 	    if not ELINUX then
    if (_4ELINUX != 0)
        goto L6;

    // 		compare_name = lower(compare_name)
    RefDS(_compare_name);
    _0 = _compare_name;
    _compare_name = _3lower(_compare_name);
    DeRefDS(_0);
L6:

    // 	    next_fc += 1
    _next_fc = _next_fc + 1;

    // 	    i = 1 -- start over and compare again
    _i = 1;
    goto L2;
L4:

    // 	    i += 1
    _i = _i + 1;
L7:

    //     end while
    goto L2;
L3:

    //     return name
    DeRef(_compare_name);
    DeRef(_4832);
    return _name;
    ;
}


int _16add_file(int _filename)
{
    int _4849 = 0;
    int _0, _1, _2;
    

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L1;

    // 	link_line &= filename & ".o "
    Concat((object_ptr)&_4849, _filename, (s1_ptr)_4848);
    Concat((object_ptr)&_16link_line, _16link_line, (s1_ptr)_4849);
    goto L2;
L1:

    //     elsif EDOS then
    if (_4EDOS == 0)
        goto L3;

    // 	if atom(dj_path) then
    DeRef(_4849);
    _4849 = IS_ATOM(_4dj_path);
    if (_4849 == 0)
        goto L4;

    // 	    printf(link_file, "FILE %s.obj\n", {filename})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_filename);
    *((int *)(_2+4)) = _filename;
    _4849 = MAKE_SEQ(_1);
    EPrintf(_16link_file, _4852, _4849);
    goto L2;
L4:

    // 	    printf(link_file, "%s.o\n", {filename})
    _0 = _4849;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_filename);
    *((int *)(_2+4)) = _filename;
    _4849 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16link_file, _4854, _4849);
L5:
    goto L2;
L3:

    // 	if sequence(wat_path) then
    DeRef(_4849);
    _4849 = IS_SEQUENCE(_4wat_path);
    if (_4849 == 0)
        goto L6;

    // 	    printf(link_file, "FILE %s.obj\n", {filename})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_filename);
    *((int *)(_2+4)) = _filename;
    _4849 = MAKE_SEQ(_1);
    EPrintf(_16link_file, _4852, _4849);
    goto L7;
L6:

    // 	elsif sequence(bor_path) then
    DeRef(_4849);
    _4849 = IS_SEQUENCE(_4bor_path);
    if (_4849 == 0)
        goto L8;

    // 	    printf(link_file, "%s.c\n", {filename})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_filename);
    *((int *)(_2+4)) = _filename;
    _4849 = MAKE_SEQ(_1);
    EPrintf(_16link_file, _4859, _4849);
    goto L7;
L8:

    // 	    printf(link_file, "%s.obj\n", {filename})
    _0 = _4849;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_filename);
    *((int *)(_2+4)) = _filename;
    _4849 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16link_file, _4861, _4849);
L7:
L2:

    // end procedure
    DeRefDS(_filename);
    DeRef(_4849);
    return 0;
    ;
}


int _16any_code(int _file_no)
{
    int _s;
    int _4875 = 0;
    int _4863 = 0;
    int _4869 = 0;
    int _0, _1, _2;
    

    //     s = SymTab[TopLevelSub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4863 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4863);
    _2 = (int)SEQ_PTR(_4863);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     while s do
L1:
    if (_s == 0)
        goto L2;

    // 	if SymTab[s][S_FILE_NO] = file_no and 
    DeRef(_4863);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4863 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4863);
    _0 = _4863;
    _2 = (int)SEQ_PTR(_4863);
    _4863 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4863);
    DeRefDS(_0);
    _0 = _4863;
    if (IS_ATOM_INT(_4863)) {
        _4863 = (_4863 == _file_no);
    }
    else {
        _4863 = binary_op(EQUALS, _4863, _file_no);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4863)) {
        if (_4863 == 0) {
            DeRef(_4863);
            _4863 = 0;
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4863)->dbl == 0.0) {
            DeRef(_4863);
            _4863 = 0;
            goto L3;
        }
    }
    DeRef(_4869);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4869 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4869);
    _0 = _4869;
    _2 = (int)SEQ_PTR(_4869);
    _4869 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4869);
    DeRefDS(_0);
    _0 = _4869;
    if (IS_ATOM_INT(_4869)) {
        _4869 = (_4869 != 99);
    }
    else {
        _4869 = binary_op(NOTEQ, _4869, 99);
    }
    DeRef(_0);
    DeRef(_4863);
    if (IS_ATOM_INT(_4869))
        _4863 = (_4869 != 0);
    else
        _4863 = DBL_PTR(_4869)->dbl != 0.0;
L3:
    if (_4863 == 0) {
        goto L4;
    }
    DeRef(_4863);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4863 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4863);
    _0 = _4863;
    _2 = (int)SEQ_PTR(_4863);
    _4863 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4863);
    DeRefDS(_0);
    _0 = _4875;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _4875 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _4875;
    _4875 = find(_4863, _4875);
    DeRefDSi(_0);
L5:
    if (_4875 == 0)
        goto L4;

    // 	    return TRUE -- found a non-deleted routine in this file
    DeRef(_4875);
    DeRef(_4863);
    DeRef(_4869);
    return 1;
L4:

    // 	s = SymTab[s][S_NEXT]
    DeRef(_4875);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4875 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4875);
    _2 = (int)SEQ_PTR(_4875);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     end while
    goto L1;
L2:

    //     return FALSE
    DeRef(_4875);
    DeRef(_4863);
    DeRef(_4869);
    return 0;
    ;
}


int _16start_emake()
{
    int _4880 = 0;
    int _0, _1, _2;
    

    //     if ELINUX then      
    if (_4ELINUX == 0)
        goto L1;

    // 	doit = open("emake", "w")
    _16doit = EOpen(_4879, _623);
    goto L2;
L1:

    // 	doit = open("emake.bat", "w")
    _16doit = EOpen(_4881, _623);
L2:

    //     if doit = -1 then
    if (_16doit != -1)
        goto L3;

    // 	CompileErr("Couldn't create batch file for compile.\n")
    RefDS(_4884);
    _6CompileErr(_4884);
L3:

    //     if not ELINUX then
    if (_4ELINUX != 0)
        goto L4;

    // 	puts(doit, "@echo off\n")
    EPuts(_16doit, _4886);

    // 	puts(doit, "if not exist main-.c goto nofiles\n")
    EPuts(_16doit, _4887);
L4:

    //     if EDOS then
    if (_4EDOS == 0)
        goto L5;

    // 	if atom(dj_path) then
    DeRef(_4880);
    _4880 = IS_ATOM(_4dj_path);
    if (_4880 == 0)
        goto L6;

    // 	    puts(doit, "echo compiling with WATCOM\n")
    EPuts(_16doit, _4889);

    // 	    if fastfp then
    if (_16fastfp == 0)
        goto L7;

    // 		c_opts = "/w0 /zq /j /zp4 /fp5 /fpi87 /5r /otimra /s"
    RefDS(_4890);
    DeRef(_16c_opts);
    _16c_opts = _4890;
    goto L8;
L7:

    // 		c_opts = "/w0 /zq /j /zp4 /fpc /5r /otimra /s"
    RefDS(_4891);
    DeRef(_16c_opts);
    _16c_opts = _4891;
L9:
    goto L8;
L6:

    // 	    puts(doit, "echo compiling with DJGPP\n")
    EPuts(_16doit, _4892);

    // 	    c_opts = "-c -w -fsigned-char -O2 -ffast-math -fomit-frame-pointer"
    RefDS(_4893);
    DeRef(_16c_opts);
    _16c_opts = _4893;
L8:
L5:

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LA;

    // 	if sequence(wat_path) then
    DeRef(_4880);
    _4880 = IS_SEQUENCE(_4wat_path);
    if (_4880 == 0)
        goto LB;

    // 	    puts(doit, "echo compiling with WATCOM\n")
    EPuts(_16doit, _4889);

    // 	    if dll_option then
    if (_16dll_option == 0)
        goto LC;

    // 		c_opts = "/bd /bt=nt /mf /w0 /zq /j /zp4 /fp5 /fpi87 /5r /otimra /s"
    RefDS(_4895);
    DeRef(_16c_opts);
    _16c_opts = _4895;
    goto LD;
LC:

    // 		c_opts = "/bt=nt /mf /w0 /zq /j /zp4 /fp5 /fpi87 /5r /otimra /s"
    RefDS(_4896);
    DeRef(_16c_opts);
    _16c_opts = _4896;
LE:
    goto LD;
LB:

    // 	elsif sequence(bor_path) then
    DeRef(_4880);
    _4880 = IS_SEQUENCE(_4bor_path);
    if (_4880 == 0)
        goto LF;

    // 	    puts(doit, "echo compiling with BORLAND\n")
    EPuts(_16doit, _4898);

    // 	    c_opts = " -q -w- -O2 -5 -a4 -I"
    RefDS(_4899);
    DeRef(_16c_opts);
    _16c_opts = _4899;

    // 	    if dll_option then
    if (_16dll_option == 0)
        goto L10;

    // 		c_opts = "-tWD" & c_opts
    Concat((object_ptr)&_16c_opts, _4900, (s1_ptr)_16c_opts);
    goto L11;
L10:

    // 	    elsif con_option then
    if (_16con_option == 0)
        goto L12;

    // 		c_opts = "-tWC" & c_opts
    Concat((object_ptr)&_16c_opts, _4902, (s1_ptr)_16c_opts);
    goto L11;
L12:

    // 		c_opts = "-tW" & c_opts
    Concat((object_ptr)&_16c_opts, _4904, (s1_ptr)_16c_opts);
L11:

    // 	    c_opts &= bor_path & "\\include -L" & bor_path & "\\lib"
    {
        int concat_list[4];

        concat_list[0] = _4907;
        concat_list[1] = _4bor_path;
        concat_list[2] = _4906;
        concat_list[3] = _4bor_path;
        Concat_N((object_ptr)&_4880, concat_list, 4);
    }
    Concat((object_ptr)&_16c_opts, _16c_opts, (s1_ptr)_4880);
    goto LD;
LF:

    // 	    puts(doit, "echo compiling with LCCWIN\n")
    EPuts(_16doit, _4910);

    // 	    c_opts = "-w -O -Zp4" -- -O is sometimes buggy
    RefDS(_4911);
    DeRef(_16c_opts);
    _16c_opts = _4911;
LD:
LA:

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L13;

    // 	puts(doit, "echo compiling with GNU C\n")
    EPuts(_16doit, _4912);

    // 	cc_name = "gcc"
    RefDS(_4913);
    DeRefi(_16cc_name);
    _16cc_name = _4913;

    // 	echo = "echo"
    RefDS(_4914);
    DeRefi(_16echo);
    _16echo = _4914;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L14;

    // 	    c_opts = "-c -w -fPIC -fsigned-char -O2 -ffast-math -fomit-frame-pointer"
    RefDS(_4915);
    DeRef(_16c_opts);
    _16c_opts = _4915;
    goto L15;
L14:

    // 	    c_opts = "-c -w -fsigned-char -O2 -ffast-math -fomit-frame-pointer"
    RefDS(_4893);
    DeRef(_16c_opts);
    _16c_opts = _4893;
L15:

    // 	link_line = ""
    RefDS(_39);
    DeRef(_16link_line);
    _16link_line = _39;
    goto L16;
L13:

    // 	echo = "echo"
    RefDS(_4914);
    DeRefi(_16echo);
    _16echo = _4914;

    // 	link_file = open("objfiles.lnk", "w")
    _16link_file = EOpen(_4916, _623);

    // 	files_to_delete = append(files_to_delete, "objfiles.lnk")
    RefDS(_4916);
    Append(&_16files_to_delete, _16files_to_delete, _4916);

    // 	if link_file = -1 then
    if (_16link_file != -1)
        goto L17;

    // 	    CompileErr("Couldn't open objfiles.lnk for output")
    RefDS(_4920);
    _6CompileErr(_4920);
L17:
L16:

    //     if EDOS then
    if (_4EDOS == 0)
        goto L18;

    // 	if atom(dj_path) then  
    DeRef(_4880);
    _4880 = IS_ATOM(_4dj_path);
    if (_4880 == 0)
        goto L19;

    // 	    cc_name = "wcc386"
    RefDS(_4922);
    DeRefi(_16cc_name);
    _16cc_name = _4922;

    // 	    puts(link_file, "option osname='CauseWay'\n")
    EPuts(_16link_file, _4923);

    // 	    printf(link_file, "libpath %s\\lib386\n", {wat_path})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4wat_path);
    *((int *)(_2+4)) = _4wat_path;
    _4880 = MAKE_SEQ(_1);
    EPrintf(_16link_file, _4924, _4880);

    // 	    printf(link_file, "libpath %s\\lib386\\dos\n", {wat_path})
    _0 = _4880;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4wat_path);
    *((int *)(_2+4)) = _4wat_path;
    _4880 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _4926, _4880);

    // 	    printf(link_file, "OPTION stub=%s\\bin\\cwstub.exe\n", {eudir})
    _0 = _4880;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4880 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _4928, _4880);

    // 	    puts(link_file, "format os2 le ^\n")
    EPuts(_16link_file, _4930);

    // 	    printf(link_file, "OPTION STACK=%d\n", total_stack_size) 
    EPrintf(_16link_file, _4931, _16total_stack_size);

    // 	    puts(link_file, "OPTION QUIET\n") 
    EPuts(_16link_file, _4932);

    // 	    puts(link_file, "OPTION ELIMINATE\n") 
    EPuts(_16link_file, _4933);

    // 	    puts(link_file, "OPTION CASEEXACT\n") 
    EPuts(_16link_file, _4934);
    goto L1A;
L19:

    // 	    cc_name = "gcc"
    RefDS(_4913);
    DeRefi(_16cc_name);
    _16cc_name = _4913;
L1A:
L18:

    //     if EWINDOWS then    
    if (_4EWINDOWS == 0)
        goto L1B;

    // 	if sequence(wat_path) then
    DeRef(_4880);
    _4880 = IS_SEQUENCE(_4wat_path);
    if (_4880 == 0)
        goto L1C;

    // 	    cc_name = "wcc386"
    RefDS(_4922);
    DeRefi(_16cc_name);
    _16cc_name = _4922;

    // 	    if dll_option then    
    if (_16dll_option == 0)
        goto L1D;

    // 		puts(link_file, "SYSTEM NT_DLL initinstance terminstance\n")
    EPuts(_16link_file, _4936);
    goto L1E;
L1D:

    // 	    elsif con_option then
    if (_16con_option == 0)
        goto L1F;

    // 		puts(link_file, "SYSTEM NT\n")
    EPuts(_16link_file, _4937);
    goto L1E;
L1F:

    // 		puts(link_file, "SYSTEM NT_WIN\n")
    EPuts(_16link_file, _4938);

    // 		puts(link_file, "RUNTIME WINDOWS=4.0\n") 
    EPuts(_16link_file, _4939);
L1E:

    // 	    printf(link_file, "OPTION STACK=%d\n", total_stack_size) 
    EPrintf(_16link_file, _4931, _16total_stack_size);

    // 	    printf(link_file, "COMMIT STACK=%d\n", total_stack_size) 
    EPrintf(_16link_file, _4940, _16total_stack_size);

    // 	    puts(link_file, "OPTION QUIET\n") 
    EPuts(_16link_file, _4932);

    // 	    puts(link_file, "OPTION ELIMINATE\n") 
    EPuts(_16link_file, _4933);

    // 	    puts(link_file, "OPTION CASEEXACT\n") 
    EPuts(_16link_file, _4934);
    goto L20;
L1C:

    // 	elsif sequence(bor_path) then
    DeRef(_4880);
    _4880 = IS_SEQUENCE(_4bor_path);
    if (_4880 == 0)
        goto L21;

    // 	    cc_name = "bcc32"
    RefDS(_4942);
    DeRefi(_16cc_name);
    _16cc_name = _4942;
    goto L20;
L21:

    // 	    cc_name = "lcc"
    RefDS(_4943);
    DeRefi(_16cc_name);
    _16cc_name = _4943;
L20:
L1B:

    // end procedure       
    DeRef(_4880);
    return 0;
    ;
}


int _16finish_emake()
{
    int _path = 0;
    int _def_name = 0;
    int _dll_flag = 0;
    int _exe_suffix = 0;
    int _buff = 0;
    int _subsystem = 0;
    int _fp;
    int _def_file;
    int _4944 = 0;
    int _4951 = 0;
    int _0, _1, _2;
    

    //     if atom(bor_path) then
    _4944 = IS_ATOM(_4bor_path);
    if (_4944 == 0)
        goto L1;

    // 	printf(doit, "%s init-.c\n", {echo})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16echo);
    *((int *)(_2+4)) = _16echo;
    _4944 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4945, _4944);

    // 	printf(doit, "%s %s init-.c\n", {cc_name, c_opts})
    DeRefDS(_4944);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16cc_name;
    RefDS(_16cc_name);
    ((int *)_2)[2] = _16c_opts;
    RefDS(_16c_opts);
    _4944 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4947, _4944);
L1:

    //     add_file("init-")
    RefDS(_4949);
    _16add_file(_4949);

    //     for i = 0 to init_name_num-1 do -- now that we know init_name_num
    DeRef(_4944);
    _4944 = _9init_name_num - 1;
    if ((long)((unsigned long)_4944 +(unsigned long) HIGH_BITS) >= 0)
        _4944 = NewDouble((double)_4944);
    { int _i;
        _i = 0;
L2:
        if (binary_op_a(GREATER, _i, _4944))
            goto L3;

        // 	if atom(bor_path) then
        DeRef(_4951);
        _4951 = IS_ATOM(_4bor_path);
        if (_4951 == 0)
            goto L4;

        // 	    printf(doit, "%s init-%d.c\n", {echo, i})
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _16echo;
        RefDS(_16echo);
        ((int *)_2)[2] = _i;
        Ref(_i);
        _4951 = MAKE_SEQ(_1);
        EPrintf(_16doit, _4952, _4951);

        // 	    printf(doit, "%s %s init-%d.c\n", {cc_name, c_opts, i})
        _0 = _4951;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_16cc_name);
        *((int *)(_2+4)) = _16cc_name;
        RefDS(_16c_opts);
        *((int *)(_2+8)) = _16c_opts;
        Ref(_i);
        *((int *)(_2+12)) = _i;
        _4951 = MAKE_SEQ(_1);
        DeRefDS(_0);
        EPrintf(_16doit, _4954, _4951);
L4:

        // 	buff = sprintf("init-%d", i)
        DeRefi(_buff);
        _buff = EPrintf(-9999999, _4956, _i);

        // 	add_file(buff)
        RefDS(_buff);
        _16add_file(_buff);

        //     end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef(_0);
        goto L2;
L3:
        ;
        DeRef(_i);
    }

    //     if atom(bor_path) then
    DeRef(_4951);
    _4951 = IS_ATOM(_4bor_path);
    if (_4951 == 0)
        goto L5;

    // 	printf(doit, "%s linking\n", {echo})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16echo);
    *((int *)(_2+4)) = _16echo;
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4959, _4951);
L5:

    //     if EDOS then    
    if (_4EDOS == 0)
        goto L6;

    // 	if atom(dj_path) then
    DeRef(_4951);
    _4951 = IS_ATOM(_4dj_path);
    if (_4951 == 0)
        goto L7;

    // 	    printf(doit, "wlink FILE %s.obj @objfiles.lnk\n", {file0})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4962, _4951);

    // 	    printf(link_file, "FILE %s\\bin\\", {eudir})
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _4964, _4951);

    // 	    if fastfp then
    if (_16fastfp == 0)
        goto L8;

    // 		puts(link_file, "ecfastfp.lib\n") 
    EPuts(_16link_file, _4966);
    goto L9;
L8:

    // 		puts(link_file, "ec.lib\n") 
    EPuts(_16link_file, _4967);
L9:

    // 	    if not keep then
    if (_16keep != 0)
        goto LA;

    // 		puts(doit, "del *.obj > NUL\n")
    EPuts(_16doit, _4969);
LA:

    // 	    path = eudir & "\\bin\\le23p.exe"
    if (IS_SEQUENCE(_4eudir) && IS_ATOM(_4970)) {
    }
    else if (IS_ATOM(_4eudir) && IS_SEQUENCE(_4970)) {
        Ref(_4eudir);
        Prepend(&_path, _4970, _4eudir);
    }
    else {
        Concat((object_ptr)&_path, _4eudir, (s1_ptr)_4970);
    }

    // 	    fp = open(path, "rb")
    _fp = EOpen(_path, _4972);

    // 	    if fp != -1 then
    if (_fp == -1)
        goto LB;

    // 		close(fp)
    EClose(_fp);

    // 		path = eudir & "\\bin\\cwc.exe"
    if (IS_SEQUENCE(_4eudir) && IS_ATOM(_4975)) {
    }
    else if (IS_ATOM(_4eudir) && IS_SEQUENCE(_4975)) {
        Ref(_4eudir);
        Prepend(&_path, _4975, _4eudir);
    }
    else {
        Concat((object_ptr)&_path, _4eudir, (s1_ptr)_4975);
    }

    // 		fp = open(path, "rb")
    _fp = EOpen(_path, _4972);

    // 		if fp != -1 then
    if (_fp == -1)
        goto LC;

    // 		    close(fp)
    EClose(_fp);

    // 		    printf(doit, "le23p %s.exe\n", {file0})
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _4979, _4951);

    // 		    printf(doit, "cwc %s.exe\n", {file0})
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16doit, _4981, _4951);
LC:
LB:

    // 	    close(link_file)
    EClose(_16link_file);
    goto LD;
L7:

    // 	    printf(link_file, "%s\\bin\\ec.a\n", {eudir}) 
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16link_file, _4983, _4951);

    // 	    printf(link_file, "%s\\bin\\liballeg.a\n", {eudir}) 
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _4985, _4951);

    // 	    printf(doit, "gcc %s.o -o%s.exe @objfiles.lnk\n", {file0, file0})
    DeRefDS(_4951);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16file0;
    RefDS(_16file0);
    ((int *)_2)[2] = _16file0;
    RefDS(_16file0);
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4987, _4951);

    // 	    if not keep then
    if (_16keep != 0)
        goto LE;

    // 		puts(doit, "del *.o\n")
    EPuts(_16doit, _4990);
LE:

    // 	    puts(doit, "set LFN=n\n")
    EPuts(_16doit, _4991);

    // 	    printf(doit, "strip %s.exe\n", {file0})
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _4992, _4951);

    // 	    puts(doit, "set LFN=\n")
    EPuts(_16doit, _4994);
LD:
L6:

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LF;

    // 	if sequence(wat_path) then     
    DeRef(_4951);
    _4951 = IS_SEQUENCE(_4wat_path);
    if (_4951 == 0)
        goto L10;

    // 	    printf(doit, "wlink FILE %s.obj @objfiles.lnk\n", {file0})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _4962, _4951);

    // 	    printf(link_file, "FILE %s\\bin\\ecw.lib\n", {eudir}) 
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _4997, _4951);
    goto L11;
L10:

    // 	elsif sequence(bor_path) then
    DeRef(_4951);
    _4951 = IS_SEQUENCE(_4bor_path);
    if (_4951 == 0)
        goto L12;

    // 	    printf(doit, "bcc32 %s %s.c @objfiles.lnk\n", {c_opts, file0})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16c_opts;
    RefDS(_16c_opts);
    ((int *)_2)[2] = _16file0;
    RefDS(_16file0);
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _5000, _4951);

    // 	    printf(link_file, "%s\\bin\\ecwb.lib\n", {eudir}) 
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16link_file, _5002, _4951);

    // 	    if not keep then
    if (_16keep != 0)
        goto L11;

    // 		puts(doit, "del *.tds > NUL\n")
    EPuts(_16doit, _5005);
L13:
    goto L11;
L12:

    // 	    if dll_option then
    if (_16dll_option == 0)
        goto L14;

    // 		printf(doit, 
    DeRef(_4951);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16file0;
    RefDS(_16file0);
    ((int *)_2)[2] = _16file0;
    RefDS(_16file0);
    _4951 = MAKE_SEQ(_1);
    EPrintf(_16doit, _5006, _4951);
    goto L15;
L14:

    // 		if con_option then
    if (_16con_option == 0)
        goto L16;

    // 		    subsystem = "console"
    RefDS(_5008);
    DeRefi(_subsystem);
    _subsystem = _5008;
    goto L17;
L16:

    // 		    subsystem = "windows"
    RefDS(_5009);
    DeRefi(_subsystem);
    _subsystem = _5009;
L17:

    // 		printf(doit, 
    _0 = _4951;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_subsystem);
    *((int *)(_2+4)) = _subsystem;
    *((int *)(_2+8)) = _16total_stack_size;
    *((int *)(_2+12)) = _16total_stack_size;
    RefDS(_16file0);
    *((int *)(_2+16)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5010, _4951);
L15:

    // 	    printf(link_file, "%s\\bin\\ecwl.lib\n", {eudir}) 
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4eudir);
    *((int *)(_2+4)) = _4eudir;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16link_file, _5012, _4951);
L11:

    // 	if not keep then
    if (_16keep != 0)
        goto L18;

    // 	    puts(doit, "del *.obj > NUL\n")
    EPuts(_16doit, _4969);
L18:

    // 	def_name = sprintf("%s.def", {file0})
    _0 = _4951;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4951 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_def_name);
    _def_name = EPrintf(-9999999, _5015, _4951);

    // 	def_file = -1
    _def_file = -1;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L19;

    // 	    if sequence(bor_path) or atom(wat_path) then
    DeRefDS(_4951);
    _4951 = IS_SEQUENCE(_4bor_path);
    if (_4951 != 0) {
        goto L1A;
    }
    DeRef(_4944);
    _4944 = IS_ATOM(_4wat_path);
L1B:
    if (_4944 == 0)
        goto L1C;
L1A:

    // 		def_file= open(def_name, "w")
    _def_file = EOpen(_def_name, _623);

    // 		if def_file = -1 then
    if (_def_file != -1)
        goto L1D;

    // 		    CompileErr("Couldn't open .def file for output")
    RefDS(_5023);
    _6CompileErr(_5023);
L1D:

    // 		Write_def_file(def_file)
    _16Write_def_file(_def_file);
    goto L1E;
L1C:

    // 		Write_def_file(link_file)
    _16Write_def_file(_16link_file);
L1F:
    goto L1E;
L19:

    // 	    if sequence(bor_path) then
    DeRef(_4944);
    _4944 = IS_SEQUENCE(_4bor_path);
    if (_4944 == 0)
        goto L20;

    // 		def_file= open(def_name, "w")
    _def_file = EOpen(_def_name, _623);

    // 		if def_file = -1 then
    if (_def_file != -1)
        goto L21;

    // 		    CompileErr("Couldn't open .def file for output")
    RefDS(_5023);
    _6CompileErr(_5023);
L21:

    // 		printf(def_file, "STACKSIZE %d,%d\n", 
    DeRef(_4944);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16total_stack_size;
    ((int *)_2)[2] = _16total_stack_size;
    _4944 = MAKE_SEQ(_1);
    EPrintf(_def_file, _5027, _4944);
L20:
L1E:

    // 	if def_file != -1 then
    if (_def_file == -1)
        goto L22;

    // 	    files_to_delete = append(files_to_delete, def_name)
    RefDS(_def_name);
    Append(&_16files_to_delete, _16files_to_delete, _def_name);

    // 	    close(def_file)
    EClose(_def_file);
L22:

    // 	close(link_file)
    EClose(_16link_file);
LF:

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L23;

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L24;

    // 	    dll_flag = "-shared -nostartfiles"
    RefDS(_5031);
    DeRefi(_dll_flag);
    _dll_flag = _5031;

    // 	    exe_suffix = ".so" 
    RefDS(_5032);
    DeRefi(_exe_suffix);
    _exe_suffix = _5032;
    goto L25;
L24:

    // 	    dll_flag = ""
    RefDS(_39);
    DeRefi(_dll_flag);
    _dll_flag = _39;

    // 	    exe_suffix = ""
    RefDS(_39);
    DeRefi(_exe_suffix);
    _exe_suffix = _39;
L25:

    // 	printf(doit, 
    _0 = _4944;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_dll_flag);
    *((int *)(_2+4)) = _dll_flag;
    RefDS(_16file0);
    *((int *)(_2+8)) = _16file0;
    RefDS(_16link_line);
    *((int *)(_2+12)) = _16link_line;
    Ref(_4eudir);
    *((int *)(_2+16)) = _4eudir;
    _4944 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5033, _4944);

    // 	if not EBSD then

    // 	    puts(doit, " -ldl")
    EPuts(_16doit, _5036);
L26:

    // 	printf(doit, " -o%s%s\n", {file0, exe_suffix})
    DeRef(_4944);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16file0;
    RefDS(_16file0);
    ((int *)_2)[2] = _exe_suffix;
    RefDS(_exe_suffix);
    _4944 = MAKE_SEQ(_1);
    EPrintf(_16doit, _5037, _4944);

    // 	if not keep then
    if (_16keep != 0)
        goto L27;

    // 	    puts(doit, "rm -f *.o\n")
    EPuts(_16doit, _5040);
L27:

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L28;

    // 	    printf(doit, "echo you can now link with: ./%s.so\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5041, _4944);
    goto L29;
L28:

    // 	    printf(doit, "echo you can now execute: ./%s\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5043, _4944);
L29:

    // 	delete_files(doit)
    _16delete_files(_16doit);
    goto L2A;
L23:

    // 	if dll_option then
    if (_16dll_option == 0)
        goto L2B;

    // 	    printf(doit, "if not exist %s.dll goto done\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5045, _4944);

    // 	    printf(doit, "echo you can now link with: %s.dll\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16doit, _5047, _4944);
    goto L2C;
L2B:

    // 	    printf(doit, "if not exist %s.exe goto done\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16doit, _5049, _4944);

    // 	    printf(doit, "echo you can now execute: %s.exe\n", {file0})
    _0 = _4944;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_16file0);
    *((int *)(_2+4)) = _16file0;
    _4944 = MAKE_SEQ(_1);
    DeRefDS(_0);
    EPrintf(_16doit, _5051, _4944);
L2C:

    // 	delete_files(doit)
    _16delete_files(_16doit);

    // 	puts(doit, "goto done\n")
    EPuts(_16doit, _5053);

    // 	puts(doit, ":nofiles\n")
    EPuts(_16doit, _5054);

    // 	puts(doit, "echo Run the translator to create new .c files\n")
    EPuts(_16doit, _5055);

    // 	puts(doit, ":done\n")
    EPuts(_16doit, _5056);
L2A:

    //     close(doit)
    EClose(_16doit);

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L2D;

    // 	system("chmod +x emake", 2)
    system_call(_5057, 2);
L2D:

    // end procedure
    DeRef(_path);
    DeRefi(_def_name);
    DeRefi(_dll_flag);
    DeRefi(_exe_suffix);
    DeRefi(_buff);
    DeRefi(_subsystem);
    DeRef(_4944);
    DeRef(_4951);
    return 0;
    ;
}


int _16GenerateUserRoutines()
{
    int _s;
    int _sp;
    int _next_c_char;
    int _q;
    int _temps;
    int _buff = 0;
    int _base_name = 0;
    int _c_file = 0;
    int _5059 = 0;
    int _5061 = 0;
    int _5114 = 0;
    int _5058;
    int _0, _1, _2, _3;
    

    //     for file_no = 1 to length(file_name) do
    _5058 = SEQ_PTR(_4file_name)->length;
    { int _file_no;
        _file_no = 1;
L1:
        if (_file_no > _5058)
            goto L2;

        // 	if file_no = 1 or any_code(file_no) then 
        DeRef(_5059);
        _5059 = (_file_no == 1);
        if (_5059 != 0) {
            goto L3;
        }
        _0 = _5061;
        _5061 = _16any_code(_file_no);
        DeRef(_0);
L4:
        if (_5061 == 0)
            goto L5;
L3:

        // 	    next_c_char = 1
        _next_c_char = 1;

        // 	    base_name = name_ext(file_name[file_no])
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4file_name);
        _5061 = (int)*(((s1_ptr)_2)->base + _file_no);
        RefDS(_5061);
        RefDS(_5061);
        _0 = _base_name;
        _base_name = _10name_ext(_5061);
        DeRef(_0);

        // 	    c_file = base_name
        RefDS(_base_name);
        DeRef(_c_file);
        _c_file = _base_name;

        // 	    q = length(c_file)
        _q = SEQ_PTR(_c_file)->length;

        // 	    while q >= 1 do
L6:
        if (_q < 1)
            goto L7;

        // 		if c_file[q] = '.' then
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_c_file);
        _5061 = (int)*(((s1_ptr)_2)->base + _q);
        Ref(_5061);
        if (binary_op_a(NOTEQ, _5061, 46))
            goto L8;

        // 		    c_file = c_file[1..q-1]
        DeRef(_5061);
        _5061 = _q - 1;
        rhs_slice_target = (object_ptr)&_c_file;
        RHS_Slice((s1_ptr)_c_file, 1, _5061);

        // 		    exit
        goto L7;
L8:

        // 		q -= 1
        _q = _q - 1;

        // 	    end while
        goto L6;
L7:

        // 	    if find(lower(c_file), {"main-", "init-"})  then
        RefDS(_c_file);
        _0 = _5061;
        _5061 = _3lower(_c_file);
        DeRef(_0);
        DeRef(_5059);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5072;
        RefDS(_5072);
        ((int *)_2)[2] = _4949;
        RefDS(_4949);
        _5059 = MAKE_SEQ(_1);
        _0 = _5059;
        _5059 = find(_5061, _5059);
        DeRefDS(_0);
        if (_5059 == 0)
            goto L9;

        // 		CompileErr(base_name & " conflicts with a file name used internally by the Translator")
        Concat((object_ptr)&_5059, _base_name, (s1_ptr)_5075);
        RefDS(_5059);
        _6CompileErr(_5059);
L9:

        // 	    if Pass = LAST_PASS and file_no > 1 then
        DeRef(_5059);
        _5059 = (_16Pass == 7);
        if (_5059 == 0) {
            goto LA;
        }
        DeRef(_5061);
        _5061 = (_file_no > 1);
LB:
        if (_5061 == 0)
            goto LA;

        // 		c_file = unique_c_name(c_file)
        RefDS(_c_file);
        _0 = _c_file;
        _c_file = _16unique_c_name(_c_file);
        DeRefDS(_0);

        // 		add_file(c_file)
        RefDS(_c_file);
        _16add_file(_c_file);
LA:

        // 	    if file_no = 1 then
        if (_file_no != 1)
            goto LC;

        // 		if Pass = LAST_PASS then
        if (_16Pass != 7)
            goto LD;

        // 		    if atom(bor_path) then
        DeRef(_5061);
        _5061 = IS_ATOM(_4bor_path);
        if (_5061 == 0)
            goto LE;

        // 			printf(doit, "%s main-.c\n", {echo})                
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_16echo);
        *((int *)(_2+4)) = _16echo;
        _5061 = MAKE_SEQ(_1);
        EPrintf(_16doit, _5084, _5061);

        // 			printf(doit, "%s %s main-.c\n", {cc_name, c_opts})
        DeRefDS(_5061);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _16cc_name;
        RefDS(_16cc_name);
        ((int *)_2)[2] = _16c_opts;
        RefDS(_16c_opts);
        _5061 = MAKE_SEQ(_1);
        EPrintf(_16doit, _5086, _5061);
LE:

        // 		    add_file("main-")
        RefDS(_5072);
        _16add_file(_5072);

        // 		    for i = 0 to main_name_num-1 do
        DeRef(_5061);
        _5061 = _9main_name_num - 1;
        if ((long)((unsigned long)_5061 +(unsigned long) HIGH_BITS) >= 0)
            _5061 = NewDouble((double)_5061);
        { int _i;
            _i = 0;
LF:
            if (binary_op_a(GREATER, _i, _5061))
                goto L10;

            // 			if atom(bor_path) then
            DeRef(_5059);
            _5059 = IS_ATOM(_4bor_path);
            if (_5059 == 0)
                goto L11;

            // 			    printf(doit, "%s main-%d.c\n", {echo, i})               
            _1 = NewS1(2);
            _2 = (int)((s1_ptr)_1)->base;
            ((int *)_2)[1] = _16echo;
            RefDS(_16echo);
            ((int *)_2)[2] = _i;
            Ref(_i);
            _5059 = MAKE_SEQ(_1);
            EPrintf(_16doit, _5090, _5059);

            // 			    printf(doit, "%s %s main-%d.c\n", {cc_name, c_opts, i})
            _0 = _5059;
            _1 = NewS1(3);
            _2 = (int)((s1_ptr)_1)->base;
            RefDS(_16cc_name);
            *((int *)(_2+4)) = _16cc_name;
            RefDS(_16c_opts);
            *((int *)(_2+8)) = _16c_opts;
            Ref(_i);
            *((int *)(_2+12)) = _i;
            _5059 = MAKE_SEQ(_1);
            DeRefDS(_0);
            EPrintf(_16doit, _5092, _5059);
L11:

            // 			buff = sprintf("main-%d", i)
            DeRefi(_buff);
            _buff = EPrintf(-9999999, _5094, _i);

            // 			add_file(buff)
            RefDS(_buff);
            _16add_file(_buff);

            // 		    end for
            _0 = _i;
            if (IS_ATOM_INT(_i)) {
                _i = _i + 1;
                if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                    _i = NewDouble((double)_i);
            }
            else {
                _i = binary_op_a(PLUS, _i, 1);
            }
            DeRef(_0);
            goto LF;
L10:
            ;
            DeRef(_i);
        }
LD:

        // 		file0 = c_file
        RefDS(_c_file);
        DeRef(_16file0);
        _16file0 = _c_file;
LC:

        // 	    if Pass = LAST_PASS then
        if (_16Pass != 7)
            goto L12;

        // 		if atom(bor_path) then
        DeRef(_5059);
        _5059 = IS_ATOM(_4bor_path);
        if (_5059 == 0)
            goto L13;

        // 		    printf(doit, "%s %s.c\n", {echo, c_file})
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _16echo;
        RefDS(_16echo);
        ((int *)_2)[2] = _c_file;
        RefDS(_c_file);
        _5059 = MAKE_SEQ(_1);
        EPrintf(_16doit, _5098, _5059);

        // 		    printf(doit, "%s %s %s.c\n", {cc_name, c_opts, c_file})
        _0 = _5059;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_16cc_name);
        *((int *)(_2+4)) = _16cc_name;
        RefDS(_16c_opts);
        *((int *)(_2+8)) = _16c_opts;
        RefDS(_c_file);
        *((int *)(_2+12)) = _c_file;
        _5059 = MAKE_SEQ(_1);
        DeRefDS(_0);
        EPrintf(_16doit, _5100, _5059);
L13:
L12:

        // 	    new_c_file(c_file)
        RefDS(_c_file);
        _16new_c_file(_c_file);

        // 	    s = SymTab[TopLevelSub][S_NEXT]
        DeRef(_5059);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5059 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
        RefDS(_5059);
        _2 = (int)SEQ_PTR(_5059);
        _s = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    while s do
L14:
        if (_s == 0)
            goto L15;

        // 		if SymTab[s][S_FILE_NO] = file_no and 
        DeRef(_5059);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5059 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5059);
        _0 = _5059;
        _2 = (int)SEQ_PTR(_5059);
        _5059 = (int)*(((s1_ptr)_2)->base + 6);
        Ref(_5059);
        DeRefDS(_0);
        _0 = _5059;
        if (IS_ATOM_INT(_5059)) {
            _5059 = (_5059 == _file_no);
        }
        else {
            _5059 = binary_op(EQUALS, _5059, _file_no);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5059)) {
            if (_5059 == 0) {
                DeRef(_5059);
                _5059 = 0;
                goto L16;
            }
        }
        else {
            if (DBL_PTR(_5059)->dbl == 0.0) {
                DeRef(_5059);
                _5059 = 0;
                goto L16;
            }
        }
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_5061);
        DeRefDS(_0);
        _0 = _5061;
        if (IS_ATOM_INT(_5061)) {
            _5061 = (_5061 != 99);
        }
        else {
            _5061 = binary_op(NOTEQ, _5061, 99);
        }
        DeRef(_0);
        DeRef(_5059);
        if (IS_ATOM_INT(_5061))
            _5059 = (_5061 != 0);
        else
            _5059 = DBL_PTR(_5061)->dbl != 0.0;
L16:
        if (_5059 == 0) {
            goto L17;
        }
        DeRef(_5059);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5059 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5059);
        _0 = _5059;
        _2 = (int)SEQ_PTR(_5059);
        _5059 = (int)*(((s1_ptr)_2)->base + 9);
        Ref(_5059);
        DeRefDS(_0);
        _0 = _5114;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 27;
        *((int *)(_2+8)) = 501;
        *((int *)(_2+12)) = 504;
        _5114 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _5114;
        _5114 = find(_5059, _5114);
        DeRefDSi(_0);
L18:
        if (_5114 == 0)
            goto L17;

        // 		    if Pass = LAST_PASS and 
        DeRef(_5114);
        _5114 = (_16Pass == 7);
        if (_5114 == 0) {
            _5114 = 0;
            goto L19;
        }
        DeRef(_5059);
        _5059 = (_4cfile_size > 2500);
        _5114 = (_5059 != 0);
L19:
        if (_5114 != 0) {
            goto L1A;
        }
        DeRef(_5114);
        _5114 = (2500 % 4) ? NewDouble((double)2500 / 4) : (2500 / 4);
        _0 = _5114;
        if (IS_ATOM_INT(_5114)) {
            _5114 = (_4cfile_size > _5114);
        }
        else {
            _5114 = ((double)_4cfile_size > DBL_PTR(_5114)->dbl);
        }
        DeRef(_0);
        if (_5114 == 0) {
            _5114 = 0;
            goto L1B;
        }
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 15);
        Ref(_5061);
        DeRefDS(_0);
        _0 = _5061;
        _5061 = SEQ_PTR(_5061)->length;
        DeRef(_0);
        _5061 = (_5061 > 2500);
        _5114 = (_5061 != 0);
L1B:
L1C:
        if (_5114 == 0)
            goto L1D;
L1A:

        // 			if length(c_file) = 7 then
        DeRef(_5061);
        _5061 = SEQ_PTR(_c_file)->length;
        if (_5061 != 7)
            goto L1E;

        // 			    c_file &= " "
        Concat((object_ptr)&_c_file, _c_file, (s1_ptr)_639);
L1E:

        // 			if length(c_file) >= 8 then
        DeRef(_5061);
        _5061 = SEQ_PTR(_c_file)->length;
        if (_5061 < 8)
            goto L1F;

        // 			    c_file[7] = '_'
        _2 = (int)SEQ_PTR(_c_file);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _c_file = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 7);
        _1 = *(int *)_2;
        *(int *)_2 = 95;
        DeRef(_1);

        // 			    c_file[8] = file_chars[next_c_char]
        _2 = (int)SEQ_PTR(_16file_chars);
        _5061 = (int)*(((s1_ptr)_2)->base + _next_c_char);
        _2 = (int)SEQ_PTR(_c_file);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _c_file = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _5061;
        DeRef(_1);
        goto L20;
L1F:

        // 			    if find('_', c_file) = 0 then
        DeRef(_5061);
        _5061 = find(95, _c_file);
        if (_5061 != 0)
            goto L21;

        // 				c_file &= "_ "
        Concat((object_ptr)&_c_file, _c_file, (s1_ptr)_5135);
L21:

        // 			    c_file[$] = file_chars[next_c_char]
        DeRef(_5061);
        _5061 = SEQ_PTR(_c_file)->length;
        DeRef(_5114);
        _2 = (int)SEQ_PTR(_16file_chars);
        _5114 = (int)*(((s1_ptr)_2)->base + _next_c_char);
        _2 = (int)SEQ_PTR(_c_file);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _c_file = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _5061);
        _1 = *(int *)_2;
        *(int *)_2 = _5114;
        DeRef(_1);
L20:

        // 			c_file = unique_c_name(c_file)
        RefDS(_c_file);
        _0 = _c_file;
        _c_file = _16unique_c_name(_c_file);
        DeRefDS(_0);

        // 			new_c_file(c_file)
        RefDS(_c_file);
        _16new_c_file(_c_file);

        // 			next_c_char += 1
        _next_c_char = _next_c_char + 1;

        // 			if next_c_char > length(file_chars) then
        DeRef(_5114);
        _5114 = 36;
        if (_next_c_char <= 36)
            goto L22;

        // 			    next_c_char = 1  -- (unique_c_name will resolve)
        _next_c_char = 1;
L22:

        // 			if atom(bor_path) then
        DeRef(_5114);
        _5114 = IS_ATOM(_4bor_path);
        if (_5114 == 0)
            goto L23;

        // 			    printf(doit, "%s %s.c\n", {echo, c_file})
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _16echo;
        RefDS(_16echo);
        ((int *)_2)[2] = _c_file;
        RefDS(_c_file);
        _5114 = MAKE_SEQ(_1);
        EPrintf(_16doit, _5098, _5114);

        // 			    printf(doit, "%s %s %s.c\n", {cc_name, c_opts, c_file})
        _0 = _5114;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_16cc_name);
        *((int *)(_2+4)) = _16cc_name;
        RefDS(_16c_opts);
        *((int *)(_2+8)) = _16c_opts;
        RefDS(_c_file);
        *((int *)(_2+12)) = _c_file;
        _5114 = MAKE_SEQ(_1);
        DeRefDS(_0);
        EPrintf(_16doit, _5100, _5114);
L23:

        // 			add_file(c_file)
        RefDS(_c_file);
        _16add_file(_c_file);
L1D:

        // 		    if SymTab[s][S_SCOPE] = SC_GLOBAL and dll_option then
        DeRef(_5114);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5114 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5114);
        _0 = _5114;
        _2 = (int)SEQ_PTR(_5114);
        _5114 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_5114);
        DeRefDS(_0);
        _0 = _5114;
        if (IS_ATOM_INT(_5114)) {
            _5114 = (_5114 == 6);
        }
        else {
            _5114 = binary_op(EQUALS, _5114, 6);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5114)) {
            if (_5114 == 0) {
                goto L24;
            }
        }
        else {
            if (DBL_PTR(_5114)->dbl == 0.0) {
                goto L24;
            }
        }
L25:
        if (_16dll_option == 0)
            goto L24;

        // 			if EWINDOWS then      
        if (_4EWINDOWS == 0)
            goto L26;

        // 			    c_stmt0("int __stdcall\n")
        RefDS(_4664);
        _16c_stmt0(_4664);
L26:

        // 			SymTab[s][S_RI_TARGET] = TRUE
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_s + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 33);
        _1 = *(int *)_2;
        *(int *)_2 = 1;
        DeRef(_1);

        // 			LeftSym = TRUE
        _16LeftSym = 1;

        // 			c_stmt("@(", s)
        RefDS(_5152);
        _16c_stmt(_5152, _s);
        goto L27;
L24:

        // 			LeftSym = TRUE
        _16LeftSym = 1;

        // 			c_stmt("int @(", s)
        RefDS(_5153);
        _16c_stmt(_5153, _s);
L27:

        // 		    sp = SymTab[s][S_NEXT]
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5061);
        _2 = (int)SEQ_PTR(_5061);
        _sp = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sp))
            _sp = (long)DBL_PTR(_sp)->dbl;

        // 		    for p = 1 to SymTab[s][S_NUM_ARGS] do
        DeRefDS(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 20);
        Ref(_5061);
        DeRefDS(_0);
        { int _p;
            _p = 1;
L28:
            if (binary_op_a(GREATER, _p, _5061))
                goto L29;

            // 			c_puts("int _")
            RefDS(_5158);
            _9c_puts(_5158);

            // 			c_puts(ok_name(SymTab[sp][S_NAME]))  
            DeRef(_5114);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5114 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5114);
            _0 = _5114;
            _2 = (int)SEQ_PTR(_5114);
            _5114 = (int)*(((s1_ptr)_2)->base + 7);
            Ref(_5114);
            DeRefDS(_0);
            Ref(_5114);
            _0 = _5114;
            _5114 = _16ok_name(_5114);
            DeRef(_0);
            RefDS(_5114);
            _9c_puts(_5114);

            // 			if p != SymTab[s][S_NUM_ARGS] then
            DeRefDS(_5114);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5114 = (int)*(((s1_ptr)_2)->base + _s);
            RefDS(_5114);
            _0 = _5114;
            _2 = (int)SEQ_PTR(_5114);
            _5114 = (int)*(((s1_ptr)_2)->base + 20);
            Ref(_5114);
            DeRefDS(_0);
            if (binary_op_a(EQUALS, _p, _5114))
                goto L2A;

            // 			    c_puts(", ")
            RefDS(_5165);
            _9c_puts(_5165);
L2A:

            // 			sp = SymTab[sp][S_NEXT]
            DeRef(_5114);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5114 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5114);
            _2 = (int)SEQ_PTR(_5114);
            _sp = (int)*(((s1_ptr)_2)->base + 2);
            if (!IS_ATOM_INT(_sp))
                _sp = (long)DBL_PTR(_sp)->dbl;

            // 		    end for
            _0 = _p;
            if (IS_ATOM_INT(_p)) {
                _p = _p + 1;
                if ((long)((unsigned long)_p +(unsigned long) HIGH_BITS) >= 0) 
                    _p = NewDouble((double)_p);
            }
            else {
                _p = binary_op_a(PLUS, _p, 1);
            }
            DeRef(_0);
            goto L28;
L29:
            ;
            DeRef(_p);
        }

        // 		    c_puts(")\n")
        RefDS(_5168);
        _9c_puts(_5168);

        // 		    c_stmt0("{\n")
        RefDS(_5169);
        _16c_stmt0(_5169);

        // 		    NewBB(0, E_ALL_EFFECT, 0)
        _16NewBB(0, 1073741823, 0);

        // 		    Initializing = TRUE
        _4Initializing = 1;

        // 		    while sp and SymTab[sp][S_SCOPE] = SC_PRIVATE do
L2B:
        if (_sp == 0) {
            goto L2C;
        }
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _sp);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_5061);
        DeRefDS(_0);
        _0 = _5061;
        if (IS_ATOM_INT(_5061)) {
            _5061 = (_5061 == 3);
        }
        else {
            _5061 = binary_op(EQUALS, _5061, 3);
        }
        DeRef(_0);
L2D:
        if (_5061 <= 0) {
            if (_5061 == 0) {
                goto L2C;
            }
            else {
                if (!IS_ATOM_INT(_5061) && DBL_PTR(_5061)->dbl == 0.0)
                    goto L2C;
            }
        }

        // 			c_stmt0("int ")
        RefDS(_4457);
        _16c_stmt0(_4457);

        // 			c_puts("_")
        RefDS(_4350);
        _9c_puts(_4350);

        // 			c_puts(ok_name(SymTab[sp][S_NAME]))
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _sp);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 7);
        Ref(_5061);
        DeRefDS(_0);
        Ref(_5061);
        _0 = _5061;
        _5061 = _16ok_name(_5061);
        DeRef(_0);
        RefDS(_5061);
        _9c_puts(_5061);

        // 			if SymTab[sp][S_GTYPE] != TYPE_INTEGER then
        DeRefDS(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _sp);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 26);
        Ref(_5061);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _5061, 1))
            goto L2E;

        // 			    c_puts(" = 0")
        RefDS(_5180);
        _9c_puts(_5180);

        // 			    target[MIN] = 0
        _2 = (int)SEQ_PTR(_9target);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _9target = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 1);
        _1 = *(int *)_2;
        *(int *)_2 = 0;
        DeRef(_1);

        // 			    target[MAX] = 0
        _2 = (int)SEQ_PTR(_9target);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _9target = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 2);
        _1 = *(int *)_2;
        *(int *)_2 = 0;
        DeRef(_1);

        // 			    SetBBType(sp, TYPE_INTEGER, target, TYPE_OBJECT)
        RefDS(_9target);
        _16SetBBType(_sp, 1, _9target, 16);
L2E:

        // 			c_puts(";\n")
        RefDS(_4460);
        _9c_puts(_4460);

        // 			sp = SymTab[sp][S_NEXT]
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _sp);
        RefDS(_5061);
        _2 = (int)SEQ_PTR(_5061);
        _sp = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sp))
            _sp = (long)DBL_PTR(_sp)->dbl;

        // 		    end while
        goto L2B;
L2C:

        // 		    temps = SymTab[s][S_TEMPS]
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5061);
        _2 = (int)SEQ_PTR(_5061);
        _temps = (int)*(((s1_ptr)_2)->base + 18);
        if (!IS_ATOM_INT(_temps))
            _temps = (long)DBL_PTR(_temps)->dbl;

        // 		    while temps != 0 do
L2F:
        if (_temps == 0)
            goto L30;

        // 			if SymTab[temps][S_SCOPE] != DELETED then
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _temps);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_5061);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _5061, 2))
            goto L31;

        // 			    if temp_name_type[SymTab[temps][S_TEMP_NAME]][T_GTYPE] 
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _temps);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 31);
        Ref(_5061);
        DeRefDS(_0);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_4temp_name_type);
        if (!IS_ATOM_INT(_5061))
            _5061 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5061)->dbl));
        else
            _5061 = (int)*(((s1_ptr)_2)->base + _5061);
        RefDS(_5061);
        DeRef(_0);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5061);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _5061, 0))
            goto L32;

        // 				c_stmt0("int ")
        RefDS(_4457);
        _16c_stmt0(_4457);

        // 				c_printf("_%d", SymTab[temps][S_TEMP_NAME])
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _temps);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 31);
        Ref(_5061);
        DeRefDS(_0);
        RefDS(_4345);
        Ref(_5061);
        _9c_printf(_4345, _5061);

        // 				if temp_name_type[SymTab[temps][S_TEMP_NAME]][T_GTYPE] 
        DeRef(_5061);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5061 = (int)*(((s1_ptr)_2)->base + _temps);
        RefDS(_5061);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 31);
        Ref(_5061);
        DeRefDS(_0);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_4temp_name_type);
        if (!IS_ATOM_INT(_5061))
            _5061 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5061)->dbl));
        else
            _5061 = (int)*(((s1_ptr)_2)->base + _5061);
        RefDS(_5061);
        DeRef(_0);
        _0 = _5061;
        _2 = (int)SEQ_PTR(_5061);
        _5061 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5061);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _5061, 1))
            goto L33;

        // 				    c_puts(" = 0")
        RefDS(_5180);
        _9c_puts(_5180);

        // 				    target = {0, 0}
        DeRef(_9target);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = 0;
        ((int *)_2)[2] = 0;
        _9target = MAKE_SEQ(_1);

        // 				    SetBBType(temps, TYPE_INTEGER, target, TYPE_OBJECT)
        RefDS(_9target);
        _16SetBBType(_temps, 1, _9target, 16);
L33:

        // 				c_puts(";\n")
        RefDS(_4460);
        _9c_puts(_4460);
L32:
L31:

        // 			SymTab[temps][S_GTYPE] = TYPE_OBJECT
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_temps + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 26);
        _1 = *(int *)_2;
        *(int *)_2 = 16;
        DeRef(_1);

        // 			temps = SymTab[temps][S_NEXT]
        DeRef(_5114);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5114 = (int)*(((s1_ptr)_2)->base + _temps);
        RefDS(_5114);
        _2 = (int)SEQ_PTR(_5114);
        _temps = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_temps))
            _temps = (long)DBL_PTR(_temps)->dbl;

        // 		    end while
        goto L2F;
L30:

        // 		    Initializing = FALSE
        _4Initializing = 0;

        // 		    if SymTab[s][S_LHS_SUBS2] then
        DeRef(_5114);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5114 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5114);
        _0 = _5114;
        _2 = (int)SEQ_PTR(_5114);
        _5114 = (int)*(((s1_ptr)_2)->base + 34);
        Ref(_5114);
        DeRefDS(_0);
        if (_5114 == 0) {
            goto L34;
        }
        else {
            if (!IS_ATOM_INT(_5114) && DBL_PTR(_5114)->dbl == 0.0)
                goto L34;
        }

        // 			c_stmt0("int _0, _1, _2, _3;\n\n")
        RefDS(_5208);
        _16c_stmt0(_5208);
        goto L35;
L34:

        // 			c_stmt0("int _0, _1, _2;\n\n")
        RefDS(_5209);
        _16c_stmt0(_5209);
L35:

        // 		    sp = SymTab[s][S_NEXT]
        DeRef(_5114);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5114 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5114);
        _2 = (int)SEQ_PTR(_5114);
        _sp = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sp))
            _sp = (long)DBL_PTR(_sp)->dbl;

        // 		    for p = 1 to SymTab[s][S_NUM_ARGS] do
        DeRefDS(_5114);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5114 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5114);
        _0 = _5114;
        _2 = (int)SEQ_PTR(_5114);
        _5114 = (int)*(((s1_ptr)_2)->base + 20);
        Ref(_5114);
        DeRefDS(_0);
        { int _p;
            _p = 1;
L36:
            if (binary_op_a(GREATER, _p, _5114))
                goto L37;

            // 			SymTab[sp][S_ONE_REF] = FALSE
            _2 = (int)SEQ_PTR(_4SymTab);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _4SymTab = MAKE_SEQ(_2);
            }
            _3 = (int)(_sp + ((s1_ptr)_2)->base);
            _2 = (int)SEQ_PTR(*(int *)_3);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                *(int *)_3 = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 32);
            _1 = *(int *)_2;
            *(int *)_2 = 0;
            DeRef(_1);

            // 			if SymTab[sp][S_ARG_TYPE] = TYPE_SEQUENCE then
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _0 = _5059;
            _2 = (int)SEQ_PTR(_5059);
            _5059 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5059);
            DeRefDS(_0);
            if (binary_op_a(NOTEQ, _5059, 8))
                goto L38;

            // 			    target[MIN] = SymTab[sp][S_ARG_SEQ_LEN]
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _0 = _5059;
            _2 = (int)SEQ_PTR(_5059);
            _5059 = (int)*(((s1_ptr)_2)->base + 48);
            Ref(_5059);
            DeRefDS(_0);
            Ref(_5059);
            _2 = (int)SEQ_PTR(_9target);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _9target = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 1);
            _1 = *(int *)_2;
            *(int *)_2 = _5059;
            DeRef(_1);

            // 			    SetBBType(sp, SymTab[sp][S_ARG_TYPE], target, 
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _0 = _5059;
            _2 = (int)SEQ_PTR(_5059);
            _5059 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5059);
            DeRefDS(_0);
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 42);
            Ref(_5061);
            DeRefDS(_0);
            Ref(_5059);
            RefDS(_9target);
            Ref(_5061);
            _16SetBBType(_sp, _5059, _9target, _5061);
            goto L39;
L38:

            // 			elsif SymTab[sp][S_ARG_TYPE] = TYPE_INTEGER then
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5061);
            DeRefDS(_0);
            if (binary_op_a(NOTEQ, _5061, 1))
                goto L3A;

            // 			    if SymTab[sp][S_ARG_MIN] = NOVALUE then
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 44);
            Ref(_5061);
            DeRefDS(_0);
            if (binary_op_a(NOTEQ, _5061, _4NOVALUE))
                goto L3B;

            // 				target[MIN] = MININT
            _2 = (int)SEQ_PTR(_9target);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _9target = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 1);
            _1 = *(int *)_2;
            *(int *)_2 = -1073741824;
            DeRef(_1);

            // 				target[MAX] = MAXINT
            _2 = (int)SEQ_PTR(_9target);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _9target = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = 1073741823;
            DeRef(_1);
            goto L3C;
L3B:

            // 				target[MIN] = SymTab[sp][S_ARG_MIN]
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 44);
            Ref(_5061);
            DeRefDS(_0);
            Ref(_5061);
            _2 = (int)SEQ_PTR(_9target);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _9target = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 1);
            _1 = *(int *)_2;
            *(int *)_2 = _5061;
            DeRef(_1);

            // 				target[MAX] = SymTab[sp][S_ARG_MAX]
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 45);
            Ref(_5061);
            DeRefDS(_0);
            Ref(_5061);
            _2 = (int)SEQ_PTR(_9target);
            if (!UNIQUE(_2)) {
                _2 = (int)SequenceCopy((s1_ptr)_2);
                _9target = MAKE_SEQ(_2);
            }
            _2 = (int)(((s1_ptr)_2)->base + 2);
            _1 = *(int *)_2;
            *(int *)_2 = _5061;
            DeRef(_1);
L3C:

            // 			    SetBBType(sp, SymTab[sp][S_ARG_TYPE], target, TYPE_OBJECT)
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5061);
            DeRefDS(_0);
            Ref(_5061);
            RefDS(_9target);
            _16SetBBType(_sp, _5061, _9target, 16);
            goto L39;
L3A:

            // 			elsif SymTab[sp][S_ARG_TYPE] = TYPE_OBJECT then
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5061);
            DeRefDS(_0);
            if (binary_op_a(NOTEQ, _5061, 16))
                goto L3D;

            // 			    SetBBType(sp, SymTab[sp][S_ARG_TYPE], novalue, 
            DeRef(_5061);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5061 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5061);
            _0 = _5061;
            _2 = (int)SEQ_PTR(_5061);
            _5061 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5061);
            DeRefDS(_0);
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _0 = _5059;
            _2 = (int)SEQ_PTR(_5059);
            _5059 = (int)*(((s1_ptr)_2)->base + 42);
            Ref(_5059);
            DeRefDS(_0);
            Ref(_5061);
            RefDS(_9novalue);
            Ref(_5059);
            _16SetBBType(_sp, _5061, _9novalue, _5059);
            goto L39;
L3D:

            // 			    SetBBType(sp, SymTab[sp][S_ARG_TYPE], novalue, TYPE_OBJECT) 
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _0 = _5059;
            _2 = (int)SEQ_PTR(_5059);
            _5059 = (int)*(((s1_ptr)_2)->base + 40);
            Ref(_5059);
            DeRefDS(_0);
            Ref(_5059);
            RefDS(_9novalue);
            _16SetBBType(_sp, _5059, _9novalue, 16);
L39:

            // 			sp = SymTab[sp][S_NEXT]
            DeRef(_5059);
            _2 = (int)SEQ_PTR(_4SymTab);
            _5059 = (int)*(((s1_ptr)_2)->base + _sp);
            RefDS(_5059);
            _2 = (int)SEQ_PTR(_5059);
            _sp = (int)*(((s1_ptr)_2)->base + 2);
            if (!IS_ATOM_INT(_sp))
                _sp = (long)DBL_PTR(_sp)->dbl;

            // 		    end for
            _0 = _p;
            if (IS_ATOM_INT(_p)) {
                _p = _p + 1;
                if ((long)((unsigned long)_p +(unsigned long) HIGH_BITS) >= 0) 
                    _p = NewDouble((double)_p);
            }
            else {
                _p = binary_op_a(PLUS, _p, 1);
            }
            DeRef(_0);
            goto L36;
L37:
            ;
            DeRef(_p);
        }

        // 		    call_proc(Execute_id, {s})
        _0 = _5059;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = _s;
        _5059 = MAKE_SEQ(_1);
        DeRef(_0);
        _1 = (int)SEQ_PTR(_5059);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_4Execute_id].addr;
        Ref(*(int *)(_2+4));
        (*(int (*)())_0)(
                            *(int *)(_2+4)
                             );

        // 		    c_puts("    ;\n}\n\n\n")
        RefDS(_5249);
        _9c_puts(_5249);
L17:

        // 		s = SymTab[s][S_NEXT]
        DeRef(_5059);
        _2 = (int)SEQ_PTR(_4SymTab);
        _5059 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_5059);
        _2 = (int)SEQ_PTR(_5059);
        _s = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    end while
        goto L14;
L15:
L5:

        //     end for   
        _file_no = _file_no + 1;
        goto L1;
L2:
        ;
    }

    // end procedure
    DeRef1(_buff);
    DeRef1(_base_name);
    DeRef1(_c_file);
    DeRef(_5059);
    DeRef(_5061);
    DeRef(_5114);
    return 0;
    ;
}


