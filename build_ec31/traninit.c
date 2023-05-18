// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _19transoptions()
{
    int _i;
    int _uparg = 0;
    int _s = 0;
    int _10767 = 0;
    int _10770 = 0;
    int _10759 = 0;
    int _0, _1, _2;
    

    //     i = 1
    _i = 1;

    //     while i <= Argc do
L1:
    if (_i > _4Argc)
        goto L2;

    // 	if Argv[i][1] = '-' then
    DeRef(_10759);
    _2 = (int)SEQ_PTR(_4Argv);
    _10759 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_10759);
    _0 = _10759;
    _2 = (int)SEQ_PTR(_10759);
    _10759 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10759);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _10759, 45))
        goto L3;

    // 	    uparg = upper(Argv[i])
    DeRef(_10759);
    _2 = (int)SEQ_PTR(_4Argv);
    _10759 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_10759);
    Ref(_10759);
    _0 = _uparg;
    _uparg = _3upper(_10759);
    DeRef(_0);

    // 	    if ELINUX and 
    if (_4ELINUX == 0) {
        goto L4;
    }
    DeRef(_10767);
    _10767 = e_match(_10766, _uparg);
    if (_10767 != 0) {
        _10767 = 1;
        goto L5;
    }
    DeRef(_10770);
    _10770 = e_match(_10769, _uparg);
    _10767 = (_10770 != 0);
L5:
L6:
    if (_10767 == 0)
        goto L4;

    // 		dll_option = TRUE
    _16dll_option = 1;
    goto L7;
L4:

    // 	    elsif EWINDOWS and match("-DLL", uparg) then
    if (_4EWINDOWS == 0) {
        goto L8;
    }
    DeRef(_10767);
    _10767 = e_match(_10766, _uparg);
L9:
    if (_10767 == 0)
        goto L8;

    // 		dll_option = TRUE
    _16dll_option = 1;
    goto L7;
L8:

    // 	    elsif EWINDOWS and match("-CON", uparg) then
    if (_4EWINDOWS == 0) {
        goto LA;
    }
    DeRef(_10770);
    _10770 = e_match(_10774, _uparg);
LB:
    if (_10770 == 0)
        goto LA;

    // 		con_option = TRUE
    _16con_option = 1;
    goto L7;
LA:

    // 	    elsif (EWINDOWS or EDOS) and match("-WAT", uparg) then
    if (_4EWINDOWS != 0) {
        DeRef(_10770);
        _10770 = 1;
        goto LC;
    }
    _10770 = (_4EDOS != 0);
LC:
    if (_10770 == 0) {
        goto LD;
    }
    DeRef(_10767);
    _10767 = e_match(_10778, _uparg);
LE:
    if (_10767 == 0)
        goto LD;

    // 		wat_option = TRUE
    _19wat_option = 1;
    goto L7;
LD:

    // 	    elsif match("-KEEP", uparg) then
    DeRef(_10767);
    _10767 = e_match(_10780, _uparg);
    if (_10767 == 0)
        goto LF;

    // 		keep = TRUE
    _16keep = 1;
    goto L7;
LF:

    // 	    elsif EDOS and match("-DJG", uparg) then
    if (_4EDOS == 0) {
        goto L10;
    }
    DeRef(_10770);
    _10770 = e_match(_10783, _uparg);
L11:
    if (_10770 == 0)
        goto L10;

    // 		djg_option = TRUE
    _19djg_option = 1;
    goto L7;
L10:

    // 	    elsif EDOS and match("-FASTFP", uparg) then
    if (_4EDOS == 0) {
        goto L12;
    }
    DeRef(_10767);
    _10767 = e_match(_10786, _uparg);
L13:
    if (_10767 == 0)
        goto L12;

    // 		fastfp = TRUE
    _16fastfp = 1;
    goto L7;
L12:

    // 	    elsif EWINDOWS and match("-LCC", uparg) then
    if (_4EWINDOWS == 0) {
        goto L14;
    }
    DeRef(_10770);
    _10770 = e_match(_10789, _uparg);
L15:
    if (_10770 == 0)
        goto L14;

    // 		lcc_option = TRUE
    _19lcc_option = 1;
    goto L7;
L14:

    // 	    elsif EWINDOWS and match("-BOR", uparg) then
    if (_4EWINDOWS == 0) {
        goto L16;
    }
    DeRef(_10767);
    _10767 = e_match(_10792, _uparg);
L17:
    if (_10767 == 0)
        goto L16;

    // 		bor_option = TRUE
    _19bor_option = 1;
    goto L7;
L16:

    // 	    elsif match("-STACK", uparg) then
    DeRef(_10767);
    _10767 = e_match(_10794, _uparg);
    if (_10767 == 0)
        goto L18;

    // 		if i < Argc then
    if (_i >= _4Argc)
        goto L7;

    // 		    s = value(Argv[i+1])
    _10767 = _i + 1;
    _2 = (int)SEQ_PTR(_4Argv);
    _10767 = (int)*(((s1_ptr)_2)->base + _10767);
    Ref(_10767);
    Ref(_10767);
    _0 = _s;
    _s = _20value(_10767);
    DeRef(_0);

    // 		    if s[1] = GET_SUCCESS then
    DeRef(_10767);
    _2 = (int)SEQ_PTR(_s);
    _10767 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10767);
    if (binary_op_a(NOTEQ, _10767, 0))
        goto L19;

    // 			if s[2] >= 16384 then
    DeRef(_10767);
    _2 = (int)SEQ_PTR(_s);
    _10767 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_10767);
    if (binary_op_a(LESS, _10767, 16384))
        goto L1A;

    // 			    total_stack_size = floor(s[2] / 4) * 4
    DeRef(_10767);
    _2 = (int)SEQ_PTR(_s);
    _10767 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_10767);
    _0 = _10767;
    if (IS_ATOM_INT(_10767)) {
        if (4 > 0 && _10767 >= 0) {
            _10767 = _10767 / 4;
        }
        else {
            temp_dbl = floor((double)_10767 / (double)4);
            if (_10767 != MININT)
                _10767 = (long)temp_dbl;
            else
                _10767 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _10767, 4);
        _10767 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_10767)) {
        _16total_stack_size = _10767 * 4;
    }
    else {
        _16total_stack_size = binary_op(MULTIPLY, _10767, 4);
    }
    if (!IS_ATOM_INT(_16total_stack_size)) {
        _1 = (long)(DBL_PTR(_16total_stack_size)->dbl);
        DeRefDS(_16total_stack_size);
        _16total_stack_size = _1;
    }
L1A:
L19:

    // 		    Argc -= 1
    _4Argc = _4Argc - 1;

    // 		    for j = i to Argc do
    DeRef(_10767);
    _10767 = _4Argc;
    { int _j;
        _j = _i;
L1B:
        if (_j > _10767)
            goto L1C;

        // 			Argv[j] = Argv[j+1]
        DeRef(_10770);
        _10770 = _j + 1;
        _2 = (int)SEQ_PTR(_4Argv);
        _10770 = (int)*(((s1_ptr)_2)->base + _10770);
        Ref(_10770);
        Ref(_10770);
        _2 = (int)SEQ_PTR(_4Argv);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4Argv = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _j);
        _1 = *(int *)_2;
        *(int *)_2 = _10770;
        DeRef(_1);

        // 		    end for
        _j = _j + 1;
        goto L1B;
L1C:
        ;
    }
L1D:
    goto L7;
L18:

    // 		OpWarning = TRUE
    _4OpWarning = 1;

    // 		Warning("unknown option: " & Argv[i])
    DeRef(_10770);
    _2 = (int)SEQ_PTR(_4Argv);
    _10770 = (int)*(((s1_ptr)_2)->base + _i);
    Ref(_10770);
    if (IS_SEQUENCE(_10812) && IS_ATOM(_10770)) {
        Ref(_10770);
        Append(&_10770, _10812, _10770);
    }
    else if (IS_ATOM(_10812) && IS_SEQUENCE(_10770)) {
    }
    else {
        Concat((object_ptr)&_10770, _10812, (s1_ptr)_10770);
    }
    RefDS(_10770);
    _6Warning(_10770);
L7:

    // 	    Argc -= 1
    _4Argc = _4Argc - 1;

    // 	    for j = i to Argc do
    DeRef(_10770);
    _10770 = _4Argc;
    { int _j;
        _j = _i;
L1E:
        if (_j > _10770)
            goto L1F;

        // 		Argv[j] = Argv[j+1]
        DeRef(_10767);
        _10767 = _j + 1;
        _2 = (int)SEQ_PTR(_4Argv);
        _10767 = (int)*(((s1_ptr)_2)->base + _10767);
        Ref(_10767);
        Ref(_10767);
        _2 = (int)SEQ_PTR(_4Argv);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4Argv = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _j);
        _1 = *(int *)_2;
        *(int *)_2 = _10767;
        DeRef(_1);

        // 	    end for
        _j = _j + 1;
        goto L1E;
L1F:
        ;
    }
    goto L1;
L3:

    // 	    i += 1 -- ignore non "-" items
    _i = _i + 1;
L20:

    //     end while
    goto L1;
L2:

    // end procedure
    DeRef(_uparg);
    DeRef(_s);
    DeRef(_10767);
    DeRef(_10770);
    DeRef(_10759);
    return 0;
    ;
}


int _19get_bor_path()
{
    int _p = 0;
    int _b;
    int _c;
    int _path = 0;
    int _10821 = 0;
    int _10825 = 0;
    int _0, _1, _2;
    

    //     p = getenv("PATH")
    _p = EGetEnv(_10820);

    //     if atom(p) then
    _10821 = IS_ATOM(_p);
    if (_10821 == 0)
        goto L1;

    // 	return 0
    DeRefi(_p);
    return 0;
L1:

    //     path = upper(p)
    Ref(_p);
    _0 = _path;
    _path = _3upper(_p);
    DeRef(_0);

    //     for i = 1 to length(path) do
    DeRef(_10821);
    _10821 = SEQ_PTR(_path)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _10821)
            goto L3;

        // 	if path[i] = '/' then
        DeRef(_10825);
        _2 = (int)SEQ_PTR(_path);
        _10825 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_10825);
        if (binary_op_a(NOTEQ, _10825, 47))
            goto L4;

        // 	    path[i] = '\\'
        _2 = (int)SEQ_PTR(_path);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _path = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = 92;
        DeRef(_1);
L4:

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     b = match("BORLAND\\BCC", path)
    _b = e_match(_10827, _path);

    //     if b = 0 then
    if (_b != 0)
        goto L5;

    // 	b = match("\\BCC", path)
    _b = e_match(_10830, _path);

    // 	if b = 0 then
    if (_b != 0)
        goto L6;

    // 	    b = match("BORLAND\\", path)
    _b = e_match(_10833, _path);

    // 	    if b = 0 then
    if (_b != 0)
        goto L7;

    // 		return 0
    DeRefi(_p);
    DeRefDS(_path);
    DeRef(_10821);
    DeRef(_10825);
    return 0;
    goto L8;
L7:

    // 		c = b+length("BORLAND\\")
    DeRef(_10825);
    _10825 = 8;
    _c = _b + 8;
L9:
    goto L8;
L6:

    // 	    c = b+length("\\BCC")
    DeRef(_10825);
    _10825 = 4;
    _c = _b + 4;
LA:
    goto L8;
L5:

    // 	c = b+length("BORLAND\\BCC")
    DeRef(_10825);
    _10825 = 11;
    _c = _b + 11;
L8:

    //     while c <= length(path) and not find(path[c], SLASH_CHARS) do
LB:
    DeRef(_10825);
    _10825 = SEQ_PTR(_path)->length;
    _10825 = (_c <= _10825);
    if (_10825 == 0) {
        goto LC;
    }
    DeRef(_10821);
    _2 = (int)SEQ_PTR(_path);
    _10821 = (int)*(((s1_ptr)_2)->base + _c);
    Ref(_10821);
    _0 = _10821;
    _10821 = find(_10821, _4SLASH_CHARS);
    DeRef(_0);
    _10821 = (_10821 == 0);
LD:
    if (_10821 == 0)
        goto LC;

    // 	c += 1
    _c = _c + 1;

    //     end while
    goto LB;
LC:

    //     path = path[1..c-1]
    DeRef(_10821);
    _10821 = _c - 1;
    rhs_slice_target = (object_ptr)&_path;
    RHS_Slice((s1_ptr)_path, 1, _10821);

    //     while b and path[b] != ';' do
LE:
    if (_b == 0) {
        goto LF;
    }
    DeRef(_10825);
    _2 = (int)SEQ_PTR(_path);
    _10825 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_10825);
    _0 = _10825;
    if (IS_ATOM_INT(_10825)) {
        _10825 = (_10825 != 59);
    }
    else {
        _10825 = binary_op(NOTEQ, _10825, 59);
    }
    DeRef(_0);
L10:
    if (_10825 <= 0) {
        if (_10825 == 0) {
            goto LF;
        }
        else {
            if (!IS_ATOM_INT(_10825) && DBL_PTR(_10825)->dbl == 0.0)
                goto LF;
        }
    }

    // 	b -= 1
    _b = _b - 1;

    //     end while
    goto LE;
LF:

    //     if b and path[b] = ';' then
    if (_b == 0) {
        goto L11;
    }
    DeRef(_10821);
    _2 = (int)SEQ_PTR(_path);
    _10821 = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_10821);
    _0 = _10821;
    if (IS_ATOM_INT(_10821)) {
        _10821 = (_10821 == 59);
    }
    else {
        _10821 = binary_op(EQUALS, _10821, 59);
    }
    DeRef(_0);
L12:
    if (_10821 == 0) {
        goto L11;
    }
    else {
        if (!IS_ATOM_INT(_10821) && DBL_PTR(_10821)->dbl == 0.0)
            goto L11;
    }

    // 	b += 1
    _b = _b + 1;
L11:

    //     return path[b..$]
    DeRef(_10821);
    _10821 = SEQ_PTR(_path)->length;
    rhs_slice_target = (object_ptr)&_10821;
    RHS_Slice((s1_ptr)_path, _b, _10821);
    DeRefi(_p);
    DeRefDS(_path);
    DeRef(_10825);
    return _10821;
    ;
}


int _19OpenCFiles()
{
    int _10861 = 0;
    int _0, _1, _2;
    

    //     c_code = open("init-.c", "w")
    _9c_code = EOpen(_10508, _10412);

    //     if c_code = -1 then
    if (_9c_code != -1)
        goto L1;

    // 	CompileErr("Can't open init-.c for output\n")
    RefDS(_10863);
    _6CompileErr(_10863);
L1:

    //     emit_c_output = TRUE
    _9emit_c_output = 1;

    //     c_puts("#include \"")
    RefDS(_10419);
    _9c_puts(_10419);

    //     c_puts(eudir)
    Ref(_4eudir);
    _9c_puts(_4eudir);

    //     c_puts(SLASH & "include" & SLASH & "euphoria.h\"\n")
    {
        int concat_list[4];

        concat_list[0] = _10865;
        concat_list[1] = _4SLASH;
        concat_list[2] = _10864;
        concat_list[3] = _4SLASH;
        Concat_N((object_ptr)&_10861, concat_list, 4);
    }
    RefDS(_10861);
    _9c_puts(_10861);

    //     c_puts("#include \"main-.h\"\n\n")
    RefDS(_10425);
    _9c_puts(_10425);

    //     c_h = open("main-.h", "w")
    _9c_h = EOpen(_10867, _10412);

    //     if c_h = -1 then
    if (_9c_h != -1)
        goto L2;

    // 	CompileErr("Can't open main-.h file for output\n")
    RefDS(_10870);
    _6CompileErr(_10870);
L2:

    // end procedure
    DeRef(_10861);
    return 0;
    ;
}


int _19InitBackEnd(int _c)
{
    int _10871;
    int _10881;
    int _0, _1, _2;
    

    //     if c = 1 then
    if (_c != 1)
        goto L1;

    // 	OpenCFiles()
    _19OpenCFiles();

    // 	return
    return 0;
L1:

    //     init_opcodes()
    _18init_opcodes();

    //     transoptions()
    _19transoptions();

    //     if EDOS then
    if (_4EDOS == 0)
        goto L2;

    // 	wat_path = 0
    DeRefi(_4wat_path);
    _4wat_path = 0;

    // 	dj_path = getenv("DJGPP")
    DeRefi(_4dj_path);
    _4dj_path = EGetEnv(_10872);

    // 	if atom(dj_path) or wat_option then
    _10871 = IS_ATOM(_4dj_path);
    if (_10871 != 0) {
        goto L3;
    }
L4:
    if (_19wat_option == 0)
        goto L5;
L3:

    // 	    wat_path = getenv("WATCOM")
    DeRefi(_4wat_path);
    _4wat_path = EGetEnv(_10876);

    // 	    if atom(wat_path) then
    _10871 = IS_ATOM(_4wat_path);
    if (_10871 == 0)
        goto L6;

    // 		wat_path = "C:\\WATCOM"
    RefDS(_10879);
    DeRefi(_4wat_path);
    _4wat_path = _10879;
L6:

    // 	    dj_path = 0
    DeRefi(_4dj_path);
    _4dj_path = 0;
L5:

    // 	if djg_option and atom(dj_path) then
    if (_19djg_option == 0) {
        goto L7;
    }
    _10881 = IS_ATOM(_4dj_path);
L8:
    if (_10881 == 0)
        goto L7;

    // 	    CompileErr("DJGPP environment variable is not set")
    RefDS(_10882);
    _6CompileErr(_10882);
L7:

    // 	if wat_option and atom(wat_path) then
    if (_19wat_option == 0) {
        goto L9;
    }
    _10871 = IS_ATOM(_4wat_path);
LA:
    if (_10871 == 0)
        goto L9;

    // 	    CompileErr("WATCOM environment variable is not set")
    RefDS(_10885);
    _6CompileErr(_10885);
L9:
L2:

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LB;

    // 	bor_path = 0
    DeRef(_4bor_path);
    _4bor_path = 0;

    // 	wat_path = 0
    DeRefi(_4wat_path);
    _4wat_path = 0;

    // 	if not lcc_option then
    if (_19lcc_option != 0)
        goto LC;

    // 	    if not bor_option then
    if (_19bor_option != 0)
        goto LD;

    // 		wat_path = getenv("WATCOM")
    _4wat_path = EGetEnv(_10876);
LD:

    // 	    bor_path = get_bor_path()
    _0 = _19get_bor_path();
    DeRef(_4bor_path);
    _4bor_path = _0;

    // 	    if sequence(wat_path) then
    _10871 = IS_SEQUENCE(_4wat_path);
    if (_10871 == 0)
        goto LE;

    // 		bor_path = 0
    DeRef(_4bor_path);
    _4bor_path = 0;
LE:

    // 	    if sequence(bor_path) then
    _10871 = IS_SEQUENCE(_4bor_path);
    if (_10871 == 0)
        goto LF;

    // 		wat_path = 0
    DeRefi(_4wat_path);
    _4wat_path = 0;
LF:
LC:

    // 	if bor_option and atom(bor_path) then
    if (_19bor_option == 0) {
        goto L10;
    }
    _10881 = IS_ATOM(_4bor_path);
L11:
    if (_10881 == 0)
        goto L10;

    // 	    CompileErr("Can't find Borland installation directory")
    RefDS(_10894);
    _6CompileErr(_10894);
L10:

    // 	if wat_option and atom(wat_path) then
    if (_19wat_option == 0) {
        goto L12;
    }
    _10871 = IS_ATOM(_4wat_path);
L13:
    if (_10871 == 0)
        goto L12;

    // 	    CompileErr("WATCOM environment variable is not set")
    RefDS(_10885);
    _6CompileErr(_10885);
L12:
LB:

    // end procedure
    return 0;
    ;
}


