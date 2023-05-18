// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _21ProcessOptions()
{
    int _src_file;
    int _dot_found;
    int _src_name = 0;
    int _raw_name = 0;
    int _exts = 0;
    int _10936 = 0;
    int _10992 = 0;
    int _10933 = 0;
    int _0, _1, _2;
    

    //     if Argc >= 3 then
    if (_4Argc < 3)
        goto L1;

    // 	src_name = Argv[3]
    _2 = (int)SEQ_PTR(_4Argv);
    _src_name = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_src_name);
    goto L2;
L1:

    // 	if INTERPRET and not BIND then
    if (0 == 0) {
        goto L3;
    }
    DeRef(_10936);
    _10936 = (0 == 0);
L4:
    if (_10936 == 0)
        goto L3;

    // 	    screen_output(STDERR, "Euphoria Interpreter " & 
    {
        int concat_list[3];

        concat_list[0] = _10938;
        concat_list[1] = _4INTERPRETER_VERSION;
        concat_list[2] = _10937;
        Concat_N((object_ptr)&_10936, concat_list, 3);
    }
    RefDS(_10936);
    _6screen_output(2, _10936);
    goto L5;
L3:

    // 	elsif TRANSLATE then

    // 	    screen_output(STDERR, "Euphoria to C Translator " & 
    {
        int concat_list[3];

        concat_list[0] = _10938;
        concat_list[1] = _4TRANSLATOR_VERSION;
        concat_list[2] = _10940;
        Concat_N((object_ptr)&_10936, concat_list, 3);
    }
    RefDS(_10936);
    _6screen_output(2, _10936);
    goto L5;
L6:

    // 	elsif BIND then
L5:

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L7;

    // 	    if BIND then

    // 		if EBSD then

    // 		    screen_output(STDERR, "for Linux.\n")
    RefDS(_10946);
    _6screen_output(2, _10946);
L8:
L9:
    goto LA;
L7:

    // 	    if BIND then

    // 	    elsif EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LB;

    // 		screen_output(STDERR, "for 32-bit Windows.\n")
    RefDS(_10948);
    _6screen_output(2, _10948);
    goto LC;
LB:

    // 		screen_output(STDERR, "for 32-bit DOS.\n")
    RefDS(_10949);
    _6screen_output(2, _10949);
LC:
LA:

    // 	screen_output(STDERR, "Copyright (c) Rapid Deployment Software 2007 \n")
    RefDS(_10950);
    _6screen_output(2, _10950);

    // 	screen_output(STDERR, 
    RefDS(_10951);
    _6screen_output(2, _10951);

    // 	if BIND then

    // 	elsif INTERPRET then

    // 	elsif TRANSLATE then

    // 	    screen_output(STDERR, "\nfile name to translate to C? ")
    RefDS(_10954);
    _6screen_output(2, _10954);
LD:
LE:

    // 	src_name = gets(STDIN)
    DeRef(_src_name);
    _src_name = EGets(0);

    // 	screen_output(STDERR, "\n")
    RefDS(_629);
    _6screen_output(2, _629);

    // 	while length(src_name) and find(src_name[1], " \t\n") do
LF:
    DeRef(_10936);
    _10936 = SEQ_PTR(_src_name)->length;
    if (_10936 == 0) {
        goto L10;
    }
    DeRef(_10933);
    _2 = (int)SEQ_PTR(_src_name);
    _10933 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10933);
    _0 = _10933;
    _10933 = find(_10933, _10959);
    DeRef(_0);
L11:
    if (_10933 == 0)
        goto L10;

    // 	    src_name = src_name[2..$]
    DeRef(_10933);
    _10933 = SEQ_PTR(_src_name)->length;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 2, _10933);

    // 	end while
    goto LF;
L10:

    // 	if length(src_name) = 0 then
    DeRef(_10933);
    _10933 = SEQ_PTR(_src_name)->length;
    if (_10933 != 0)
        goto L12;

    // 	    Cleanup(1)
    _6Cleanup(1);
L12:

    // 	while length(src_name) and find(src_name[$], " \t\n") do
L13:
    DeRef(_10933);
    _10933 = SEQ_PTR(_src_name)->length;
    if (_10933 == 0) {
        goto L14;
    }
    DeRef(_10936);
    _10936 = SEQ_PTR(_src_name)->length;
    _2 = (int)SEQ_PTR(_src_name);
    _10936 = (int)*(((s1_ptr)_2)->base + _10936);
    Ref(_10936);
    _0 = _10936;
    _10936 = find(_10936, _10959);
    DeRef(_0);
L15:
    if (_10936 == 0)
        goto L14;

    // 	    src_name = src_name[1..$-1]
    DeRef(_10936);
    _10936 = SEQ_PTR(_src_name)->length;
    _10936 = _10936 - 1;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 1, _10936);

    // 	end while
    goto L13;
L14:

    // 	Argc = 2
    _4Argc = 2;

    // 	Argv = {Argv[1], src_name}
    DeRef(_10936);
    _2 = (int)SEQ_PTR(_4Argv);
    _10936 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10936);
    DeRefDS(_4Argv);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _10936;
    Ref(_10936);
    ((int *)_2)[2] = _src_name;
    RefDS(_src_name);
    _4Argv = MAKE_SEQ(_1);

    // 	file_name_entered = src_name -- passed to back-end for command_line()
    RefDS(_src_name);
    DeRef(_4file_name_entered);
    _4file_name_entered = _src_name;
L2:

    //     dot_found = FALSE
    _dot_found = 0;

    //     for p = 1 to length(src_name) do
    DeRef(_10936);
    _10936 = SEQ_PTR(_src_name)->length;
    { int _p;
        _p = 1;
L16:
        if (_p > _10936)
            goto L17;

        // 	if src_name[p] = '.' then
        DeRef(_10933);
        _2 = (int)SEQ_PTR(_src_name);
        _10933 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_10933);
        if (binary_op_a(NOTEQ, _10933, 46))
            goto L18;

        // 	   dot_found = TRUE
        _dot_found = 1;
        goto L19;
L18:

        // 	elsif find(src_name[p], SLASH_CHARS) then
        DeRef(_10933);
        _2 = (int)SEQ_PTR(_src_name);
        _10933 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_10933);
        _0 = _10933;
        _10933 = find(_10933, _4SLASH_CHARS);
        DeRef(_0);
        if (_10933 == 0)
            goto L1A;

        // 	   dot_found = FALSE
        _dot_found = 0;
L1A:
L19:

        //     end for 
        _p = _p + 1;
        goto L16;
L17:
        ;
    }

    //     raw_name = src_name
    RefDS(_src_name);
    DeRef(_raw_name);
    _raw_name = _src_name;

    //     if not dot_found then
    if (_dot_found != 0)
        goto L1B;

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L1C;

    // 	    exts = { ".exu", ".exw", ".ex", "" }
    _0 = _exts;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_10981);
    *((int *)(_2+4)) = _10981;
    RefDS(_10982);
    *((int *)(_2+8)) = _10982;
    RefDS(_10983);
    *((int *)(_2+12)) = _10983;
    RefDS(_39);
    *((int *)(_2+16)) = _39;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
    goto L1D;
L1C:

    // 	elsif BIND then

    // 	    if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L1E;

    // 		exts = { ".exw", ".ex", ".exu" }
    _0 = _exts;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_10982);
    *((int *)(_2+4)) = _10982;
    RefDS(_10983);
    *((int *)(_2+8)) = _10983;
    RefDS(_10981);
    *((int *)(_2+12)) = _10981;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
    goto L1F;
L1E:

    // 		exts = { ".ex", ".exw", ".exu" }
    _0 = _exts;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_10983);
    *((int *)(_2+4)) = _10983;
    RefDS(_10982);
    *((int *)(_2+8)) = _10982;
    RefDS(_10981);
    *((int *)(_2+12)) = _10981;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
L1F:
L1D:

    // 	file_name = append(file_name, src_name)
    RefDS(_src_name);
    Append(&_4file_name, _4file_name, _src_name);

    // 	for i = 1 to length( exts ) do
    DeRef(_10933);
    _10933 = SEQ_PTR(_exts)->length;
    { int _i;
        _i = 1;
L20:
        if (_i > _10933)
            goto L21;

        // 	    file_name[$] = src_name & exts[i]
        DeRef(_10936);
        _10936 = SEQ_PTR(_4file_name)->length;
        DeRef(_10992);
        _2 = (int)SEQ_PTR(_exts);
        _10992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_10992);
        Concat((object_ptr)&_10992, _src_name, (s1_ptr)_10992);
        RefDS(_10992);
        _2 = (int)SEQ_PTR(_4file_name);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4file_name = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _10936);
        _1 = *(int *)_2;
        *(int *)_2 = _10992;
        DeRefDS(_1);

        // 	    src_file = e_path_open(src_name & exts[i], "r")
        DeRefDS(_10992);
        _2 = (int)SEQ_PTR(_exts);
        _10992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_10992);
        Concat((object_ptr)&_10992, _src_name, (s1_ptr)_10992);
        RefDS(_10992);
        RefDS(_10996);
        _src_file = _22e_path_open(_10992, _10996);

        // 	    if src_file != -1 then
        if (_src_file == -1)
            goto L22;

        // 		src_name &= exts[i]
        DeRefDS(_10992);
        _2 = (int)SEQ_PTR(_exts);
        _10992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_10992);
        Concat((object_ptr)&_src_name, _src_name, (s1_ptr)_10992);

        // 		exit
        goto L21;
L22:

        // 	end for
        _i = _i + 1;
        goto L20;
L21:
        ;
    }

    // 	if src_file = -1 then
    if (_src_file != -1)
        goto L23;

    // 	    file_name[$] = src_name & exts[1]	
    DeRef(_10992);
    _10992 = SEQ_PTR(_4file_name)->length;
    DeRef(_10936);
    _2 = (int)SEQ_PTR(_exts);
    _10936 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_10936);
    Concat((object_ptr)&_10936, _src_name, (s1_ptr)_10936);
    RefDS(_10936);
    _2 = (int)SEQ_PTR(_4file_name);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4file_name = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _10992);
    _1 = *(int *)_2;
    *(int *)_2 = _10936;
    DeRefDS(_1);
L24:
    goto L23;
L1B:

    // 	file_name = append(file_name, src_name)
    RefDS(_src_name);
    Append(&_4file_name, _4file_name, _src_name);

    // 	src_file = e_path_open(src_name, "r")
    RefDS(_src_name);
    RefDS(_10996);
    _src_file = _22e_path_open(_src_name, _10996);
L23:

    //     return src_file
    DeRef(_src_name);
    DeRef(_raw_name);
    DeRef(_exts);
    DeRef(_10936);
    DeRef(_10992);
    DeRef(_10933);
    return _src_file;
    ;
}


int _21full_path(int _filename)
{
    int _p;
    int _11007 = 0;
    int _0, _1, _2;
    

    //     p = length(filename)
    _p = SEQ_PTR(_filename)->length;

    //     while p >= 1 do
L1:
    if (_p < 1)
        goto L2;

    // 	if find(filename[p], SLASH_CHARS) then
    DeRef(_11007);
    _2 = (int)SEQ_PTR(_filename);
    _11007 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_11007);
    _0 = _11007;
    _11007 = find(_11007, _4SLASH_CHARS);
    DeRef(_0);
    if (_11007 == 0)
        goto L3;

    // 	    return filename[1..p]
    rhs_slice_target = (object_ptr)&_11007;
    RHS_Slice((s1_ptr)_filename, 1, _p);
    DeRefDS(_filename);
    return _11007;
L3:

    // 	p -= 1
    _p = _p - 1;

    //     end while
    goto L1;
L2:

    //     return '.' & SLASH  
    Concat((object_ptr)&_11007, 46, (s1_ptr)_4SLASH);
    DeRefDS(_filename);
    return _11007;
    ;
}


int _21main()
{
    int _argc;
    int _argv = 0;
    int _11014 = 0;
    int _0, _1, _2;
    

    //     argv = command_line()
    _argv = Command_Line();

    //     if BIND then

    //     argc = length(argv)  
    _argc = SEQ_PTR(_argv)->length;

    //     Argv = argv
    RefDS(_argv);
    DeRef(_4Argv);
    _4Argv = _argv;

    //     Argc = argc
    _4Argc = _argc;

    //     eudir = getenv("EUDIR")
    DeRefi(_4eudir);
    _4eudir = EGetEnv(_11017);

    //     if atom(eudir) then
    _11014 = IS_ATOM(_4eudir);
    if (_11014 == 0)
        goto L1;

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L2;

    // 	    eudir = getenv("HOME")
    DeRefi(_4eudir);
    _4eudir = EGetEnv(_11020);

    // 	    if atom(eudir) then
    _11014 = IS_ATOM(_4eudir);
    if (_11014 == 0)
        goto L3;

    // 		eudir = "euphoria"  
    RefDS(_11023);
    DeRefi(_4eudir);
    _4eudir = _11023;
    goto L4;
L3:

    // 		eudir = eudir & "/euphoria"
    if (IS_SEQUENCE(_4eudir) && IS_ATOM(_11024)) {
    }
    else if (IS_ATOM(_4eudir) && IS_SEQUENCE(_11024)) {
        Ref(_4eudir);
        Prepend(&_4eudir, _11024, _4eudir);
    }
    else {
        Concat((object_ptr)&_4eudir, _4eudir, (s1_ptr)_11024);
    }
L5:
    goto L4;
L2:

    // 	    eudir = "\\EUPHORIA"
    RefDS(_11026);
    DeRefi(_4eudir);
    _4eudir = _11026;
L6:
    goto L4;
L1:

    // 	mybsd = match("/usr231/home/r/h/rhc", eudir) > 0 --RapidEuphoria.com
    DeRef(_11014);
    _11014 = e_match(_11027, _4eudir);
    _4mybsd = (_11014 > 0);
L4:

    //     TempErrName = "ex.err"           
    RefDS(_11030);
    DeRefi(_6TempErrName);
    _6TempErrName = _11030;

    //     if TRANSLATE then

    // 	InitBackEnd(0)
    _19InitBackEnd(0);
L7:

    //     src_file = ProcessOptions()
    _0 = _21ProcessOptions();
    _11src_file = _0;

    //     if src_file = -1 then
    if (_11src_file != -1)
        goto L8;

    // 	screen_output(STDERR, sprintf("Can't open %s\n", {file_name[1]}))
    DeRef(_11014);
    _2 = (int)SEQ_PTR(_4file_name);
    _11014 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_11014);
    _0 = _11014;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_11014);
    *((int *)(_2+4)) = _11014;
    _11014 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _11014;
    _11014 = EPrintf(-9999999, _11033, _11014);
    DeRefDS(_0);
    RefDS(_11014);
    _6screen_output(2, _11014);

    // 	if BIND or EWINDOWS or ELINUX then
    if (0 != 0) {
        DeRefDS(_11014);
        _11014 = 1;
        goto L9;
    }
    _11014 = (_4EWINDOWS != 0);
L9:
    if (_11014 != 0) {
        goto LA;
    }
LB:
    if (_4ELINUX == 0)
        goto LC;
LA:

    // 	    screen_output(STDERR, "\nPress Enter\n")
    RefDS(_11039);
    _6screen_output(2, _11039);

    // 	    if getc(0) then
    DeRef(_11014);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _11014 = getc(xstdin);
        }
        else
            _11014 = getc(last_r_file_ptr);
    }
    else
        _11014 = getc(last_r_file_ptr);
    if (_11014 == 0)
        goto LD;
LD:
LC:

    // 	Cleanup(1)
    _6Cleanup(1);
L8:

    //     main_path = full_path(file_name[1])  
    DeRef(_11014);
    _2 = (int)SEQ_PTR(_4file_name);
    _11014 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_11014);
    RefDS(_11014);
    _0 = _21full_path(_11014);
    DeRef(_11main_path);
    _11main_path = _0;

    //     if TRANSLATE then

    // 	InitBackEnd(1)
    _19InitBackEnd(1);
LE:

    //     InitGlobals()
    _15InitGlobals();

    //     InitSymTab()
    _10InitSymTab();

    //     InitEmit()
    _14InitEmit();

    //     InitParser()
    _15InitParser();

    //     InitLex()
    _11InitLex();

    //     read_line()
    _11read_line();

    //     parser()
    _15parser();

    //     if TRANSLATE then

    // 	BackEnd(0) -- translate IL to C
    _18BackEnd(0);
    goto LF;
L10:

    //     elsif BIND then

    //     elsif INTERPRET then
LF:

    //     Cleanup(0) -- does warnings
    _6Cleanup(0);

    // end procedure
    DeRef(_argv);
    DeRef(_11014);
    return 0;
    ;
}


