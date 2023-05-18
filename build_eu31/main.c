// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _19ProcessOptions()
{
    int _src_file;
    int _dot_found;
    int _src_name = 0;
    int _raw_name = 0;
    int _exts = 0;
    int _6967 = 0;
    int _7023 = 0;
    int _6964 = 0;
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
    if (1 == 0) {
        goto L3;
    }
    DeRef(_6967);
    _6967 = (0 == 0);
L4:
    if (_6967 == 0)
        goto L3;

    // 	    screen_output(STDERR, "Euphoria Interpreter " & 
    {
        int concat_list[3];

        concat_list[0] = _6969;
        concat_list[1] = _4INTERPRETER_VERSION;
        concat_list[2] = _6968;
        Concat_N((object_ptr)&_6967, concat_list, 3);
    }
    RefDS(_6967);
    _6screen_output(2, _6967);
    goto L5;
L3:

    // 	elsif TRANSLATE then

    // 	elsif BIND then
L5:

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L6;

    // 	    if BIND then

    // 		if EBSD then

    // 		    screen_output(STDERR, "for Linux.\n")
    RefDS(_6977);
    _6screen_output(2, _6977);
L7:
L8:
    goto L9;
L6:

    // 	    if BIND then

    // 	    elsif EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LA;

    // 		screen_output(STDERR, "for 32-bit Windows.\n")
    RefDS(_6979);
    _6screen_output(2, _6979);
    goto LB;
LA:

    // 		screen_output(STDERR, "for 32-bit DOS.\n")
    RefDS(_6980);
    _6screen_output(2, _6980);
LB:
L9:

    // 	screen_output(STDERR, "Copyright (c) Rapid Deployment Software 2007 \n")
    RefDS(_6981);
    _6screen_output(2, _6981);

    // 	screen_output(STDERR, 
    RefDS(_6982);
    _6screen_output(2, _6982);

    // 	if BIND then

    // 	elsif INTERPRET then

    // 	    screen_output(STDERR, "\nfile name to execute? ")
    RefDS(_6984);
    _6screen_output(2, _6984);
    goto LC;
LD:

    // 	elsif TRANSLATE then
LC:

    // 	src_name = gets(STDIN)
    DeRef(_src_name);
    _src_name = EGets(0);

    // 	screen_output(STDERR, "\n")
    RefDS(_629);
    _6screen_output(2, _629);

    // 	while length(src_name) and find(src_name[1], " \t\n") do
LE:
    DeRef(_6967);
    _6967 = SEQ_PTR(_src_name)->length;
    if (_6967 == 0) {
        goto LF;
    }
    DeRef(_6964);
    _2 = (int)SEQ_PTR(_src_name);
    _6964 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6964);
    _0 = _6964;
    _6964 = find(_6964, _6990);
    DeRef(_0);
L10:
    if (_6964 == 0)
        goto LF;

    // 	    src_name = src_name[2..$]
    DeRef(_6964);
    _6964 = SEQ_PTR(_src_name)->length;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 2, _6964);

    // 	end while
    goto LE;
LF:

    // 	if length(src_name) = 0 then
    DeRef(_6964);
    _6964 = SEQ_PTR(_src_name)->length;
    if (_6964 != 0)
        goto L11;

    // 	    Cleanup(1)
    _6Cleanup(1);
L11:

    // 	while length(src_name) and find(src_name[$], " \t\n") do
L12:
    DeRef(_6964);
    _6964 = SEQ_PTR(_src_name)->length;
    if (_6964 == 0) {
        goto L13;
    }
    DeRef(_6967);
    _6967 = SEQ_PTR(_src_name)->length;
    _2 = (int)SEQ_PTR(_src_name);
    _6967 = (int)*(((s1_ptr)_2)->base + _6967);
    Ref(_6967);
    _0 = _6967;
    _6967 = find(_6967, _6990);
    DeRef(_0);
L14:
    if (_6967 == 0)
        goto L13;

    // 	    src_name = src_name[1..$-1]
    DeRef(_6967);
    _6967 = SEQ_PTR(_src_name)->length;
    _6967 = _6967 - 1;
    rhs_slice_target = (object_ptr)&_src_name;
    RHS_Slice((s1_ptr)_src_name, 1, _6967);

    // 	end while
    goto L12;
L13:

    // 	Argc = 2
    _4Argc = 2;

    // 	Argv = {Argv[1], src_name}
    DeRef(_6967);
    _2 = (int)SEQ_PTR(_4Argv);
    _6967 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6967);
    DeRefDS(_4Argv);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6967;
    Ref(_6967);
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
    DeRef(_6967);
    _6967 = SEQ_PTR(_src_name)->length;
    { int _p;
        _p = 1;
L15:
        if (_p > _6967)
            goto L16;

        // 	if src_name[p] = '.' then
        DeRef(_6964);
        _2 = (int)SEQ_PTR(_src_name);
        _6964 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_6964);
        if (binary_op_a(NOTEQ, _6964, 46))
            goto L17;

        // 	   dot_found = TRUE
        _dot_found = 1;
        goto L18;
L17:

        // 	elsif find(src_name[p], SLASH_CHARS) then
        DeRef(_6964);
        _2 = (int)SEQ_PTR(_src_name);
        _6964 = (int)*(((s1_ptr)_2)->base + _p);
        Ref(_6964);
        _0 = _6964;
        _6964 = find(_6964, _4SLASH_CHARS);
        DeRef(_0);
        if (_6964 == 0)
            goto L19;

        // 	   dot_found = FALSE
        _dot_found = 0;
L19:
L18:

        //     end for 
        _p = _p + 1;
        goto L15;
L16:
        ;
    }

    //     raw_name = src_name
    RefDS(_src_name);
    DeRef(_raw_name);
    _raw_name = _src_name;

    //     if not dot_found then
    if (_dot_found != 0)
        goto L1A;

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L1B;

    // 	    exts = { ".exu", ".exw", ".ex", "" }
    _0 = _exts;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7012);
    *((int *)(_2+4)) = _7012;
    RefDS(_7013);
    *((int *)(_2+8)) = _7013;
    RefDS(_7014);
    *((int *)(_2+12)) = _7014;
    RefDS(_39);
    *((int *)(_2+16)) = _39;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
    goto L1C;
L1B:

    // 	elsif BIND then

    // 	    if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L1D;

    // 		exts = { ".exw", ".ex", ".exu" }
    _0 = _exts;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7013);
    *((int *)(_2+4)) = _7013;
    RefDS(_7014);
    *((int *)(_2+8)) = _7014;
    RefDS(_7012);
    *((int *)(_2+12)) = _7012;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
    goto L1E;
L1D:

    // 		exts = { ".ex", ".exw", ".exu" }
    _0 = _exts;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7014);
    *((int *)(_2+4)) = _7014;
    RefDS(_7013);
    *((int *)(_2+8)) = _7013;
    RefDS(_7012);
    *((int *)(_2+12)) = _7012;
    _exts = MAKE_SEQ(_1);
    DeRef(_0);
L1E:
L1C:

    // 	file_name = append(file_name, src_name)
    RefDS(_src_name);
    Append(&_4file_name, _4file_name, _src_name);

    // 	for i = 1 to length( exts ) do
    DeRef(_6964);
    _6964 = SEQ_PTR(_exts)->length;
    { int _i;
        _i = 1;
L1F:
        if (_i > _6964)
            goto L20;

        // 	    file_name[$] = src_name & exts[i]
        DeRef(_6967);
        _6967 = SEQ_PTR(_4file_name)->length;
        DeRef(_7023);
        _2 = (int)SEQ_PTR(_exts);
        _7023 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_7023);
        Concat((object_ptr)&_7023, _src_name, (s1_ptr)_7023);
        RefDS(_7023);
        _2 = (int)SEQ_PTR(_4file_name);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4file_name = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _6967);
        _1 = *(int *)_2;
        *(int *)_2 = _7023;
        DeRefDS(_1);

        // 	    src_file = e_path_open(src_name & exts[i], "r")
        DeRefDS(_7023);
        _2 = (int)SEQ_PTR(_exts);
        _7023 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_7023);
        Concat((object_ptr)&_7023, _src_name, (s1_ptr)_7023);
        RefDS(_7023);
        RefDS(_1669);
        _src_file = _21e_path_open(_7023, _1669);

        // 	    if src_file != -1 then
        if (_src_file == -1)
            goto L21;

        // 		src_name &= exts[i]
        DeRefDS(_7023);
        _2 = (int)SEQ_PTR(_exts);
        _7023 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_7023);
        Concat((object_ptr)&_src_name, _src_name, (s1_ptr)_7023);

        // 		exit
        goto L20;
L21:

        // 	end for
        _i = _i + 1;
        goto L1F;
L20:
        ;
    }

    // 	if src_file = -1 then
    if (_src_file != -1)
        goto L22;

    // 	    file_name[$] = src_name & exts[1]	
    DeRef(_7023);
    _7023 = SEQ_PTR(_4file_name)->length;
    DeRef(_6967);
    _2 = (int)SEQ_PTR(_exts);
    _6967 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_6967);
    Concat((object_ptr)&_6967, _src_name, (s1_ptr)_6967);
    RefDS(_6967);
    _2 = (int)SEQ_PTR(_4file_name);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4file_name = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _7023);
    _1 = *(int *)_2;
    *(int *)_2 = _6967;
    DeRefDS(_1);
L23:
    goto L22;
L1A:

    // 	file_name = append(file_name, src_name)
    RefDS(_src_name);
    Append(&_4file_name, _4file_name, _src_name);

    // 	src_file = e_path_open(src_name, "r")
    RefDS(_src_name);
    RefDS(_1669);
    _src_file = _21e_path_open(_src_name, _1669);
L22:

    //     return src_file
    DeRef(_src_name);
    DeRef(_raw_name);
    DeRef(_exts);
    DeRef(_6967);
    DeRef(_7023);
    DeRef(_6964);
    return _src_file;
    ;
}


int _19full_path(int _filename)
{
    int _p;
    int _7037 = 0;
    int _0, _1, _2;
    

    //     p = length(filename)
    _p = SEQ_PTR(_filename)->length;

    //     while p >= 1 do
L1:
    if (_p < 1)
        goto L2;

    // 	if find(filename[p], SLASH_CHARS) then
    DeRef(_7037);
    _2 = (int)SEQ_PTR(_filename);
    _7037 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_7037);
    _0 = _7037;
    _7037 = find(_7037, _4SLASH_CHARS);
    DeRef(_0);
    if (_7037 == 0)
        goto L3;

    // 	    return filename[1..p]
    rhs_slice_target = (object_ptr)&_7037;
    RHS_Slice((s1_ptr)_filename, 1, _p);
    DeRefDS(_filename);
    return _7037;
L3:

    // 	p -= 1
    _p = _p - 1;

    //     end while
    goto L1;
L2:

    //     return '.' & SLASH  
    Concat((object_ptr)&_7037, 46, (s1_ptr)_4SLASH);
    DeRefDS(_filename);
    return _7037;
    ;
}


int _19main()
{
    int _argc;
    int _argv = 0;
    int _7044 = 0;
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
    _4eudir = EGetEnv(_7047);

    //     if atom(eudir) then
    _7044 = IS_ATOM(_4eudir);
    if (_7044 == 0)
        goto L1;

    // 	if ELINUX then
    if (_4ELINUX == 0)
        goto L2;

    // 	    eudir = getenv("HOME")
    DeRefi(_4eudir);
    _4eudir = EGetEnv(_7050);

    // 	    if atom(eudir) then
    _7044 = IS_ATOM(_4eudir);
    if (_7044 == 0)
        goto L3;

    // 		eudir = "euphoria"  
    RefDS(_7053);
    DeRefi(_4eudir);
    _4eudir = _7053;
    goto L4;
L3:

    // 		eudir = eudir & "/euphoria"
    if (IS_SEQUENCE(_4eudir) && IS_ATOM(_7054)) {
    }
    else if (IS_ATOM(_4eudir) && IS_SEQUENCE(_7054)) {
        Ref(_4eudir);
        Prepend(&_4eudir, _7054, _4eudir);
    }
    else {
        Concat((object_ptr)&_4eudir, _4eudir, (s1_ptr)_7054);
    }
L5:
    goto L4;
L2:

    // 	    eudir = "\\EUPHORIA"
    RefDS(_7056);
    DeRefi(_4eudir);
    _4eudir = _7056;
L6:
    goto L4;
L1:

    // 	mybsd = match("/usr231/home/r/h/rhc", eudir) > 0 --RapidEuphoria.com
    DeRef(_7044);
    _7044 = e_match(_7057, _4eudir);
    _4mybsd = (_7044 > 0);
L4:

    //     TempErrName = "ex.err"           
    RefDS(_4163);
    DeRefi(_6TempErrName);
    _6TempErrName = _4163;

    //     if TRANSLATE then

    //     src_file = ProcessOptions()
    _0 = _19ProcessOptions();
    _11src_file = _0;

    //     if src_file = -1 then
    if (_11src_file != -1)
        goto L7;

    // 	screen_output(STDERR, sprintf("Can't open %s\n", {file_name[1]}))
    DeRef(_7044);
    _2 = (int)SEQ_PTR(_4file_name);
    _7044 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_7044);
    _0 = _7044;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_7044);
    *((int *)(_2+4)) = _7044;
    _7044 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _7044;
    _7044 = EPrintf(-9999999, _7062, _7044);
    DeRefDS(_0);
    RefDS(_7044);
    _6screen_output(2, _7044);

    // 	if BIND or EWINDOWS or ELINUX then
    if (0 != 0) {
        DeRefDS(_7044);
        _7044 = 1;
        goto L8;
    }
    _7044 = (_4EWINDOWS != 0);
L8:
    if (_7044 != 0) {
        goto L9;
    }
LA:
    if (_4ELINUX == 0)
        goto LB;
L9:

    // 	    screen_output(STDERR, "\nPress Enter\n")
    RefDS(_7068);
    _6screen_output(2, _7068);

    // 	    if getc(0) then
    DeRef(_7044);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _7044 = getc(xstdin);
        }
        else
            _7044 = getc(last_r_file_ptr);
    }
    else
        _7044 = getc(last_r_file_ptr);
    if (_7044 == 0)
        goto LC;
LC:
LB:

    // 	Cleanup(1)
    _6Cleanup(1);
L7:

    //     main_path = full_path(file_name[1])  
    DeRef(_7044);
    _2 = (int)SEQ_PTR(_4file_name);
    _7044 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_7044);
    RefDS(_7044);
    _0 = _19full_path(_7044);
    DeRef(_11main_path);
    _11main_path = _0;

    //     if TRANSLATE then

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

    //     elsif BIND then

    //     elsif INTERPRET then

    // 	InitBackEnd(0)
    _16InitBackEnd(0);

    // 	BackEnd(0) -- execute IL using Euphoria-coded back-end
    _16BackEnd(0);
LD:
LE:

    //     Cleanup(0) -- does warnings
    _6Cleanup(0);

    // end procedure
    DeRef(_argv);
    DeRef(_7044);
    return 0;
    ;
}


