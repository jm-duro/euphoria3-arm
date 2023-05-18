// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _6screen_output(int _f, int _msg)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_f)) {
        _1 = (long)(DBL_PTR(_f)->dbl);
        DeRefDS(_f);
        _f = _1;
    }

    //     puts(f, msg)
    EPuts(_f, _msg);

    // end procedure
    DeRefDS(_msg);
    return 0;
    ;
}


int _6Warning(int _msg)
{
    int _p = 0;
    int _600 = 0;
    int _0, _1, _2;
    

    //     if OpWarning then
    if (_4OpWarning == 0)
        goto L1;

    // 	p = sprintf("Warning: %s\n", {msg})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_msg);
    *((int *)(_2+4)) = _msg;
    _600 = MAKE_SEQ(_1);
    _p = EPrintf(-9999999, _599, _600);

    // 	if find(p, warning_list) then
    DeRefDS(_600);
    _600 = find(_p, _6warning_list);
    if (_600 == 0)
        goto L2;

    // 	    return -- duplicate
    DeRefDS(_msg);
    DeRefDSi(_p);
    return 0;
L2:

    // 	warning_list = append(warning_list, p)          
    RefDS(_p);
    Append(&_6warning_list, _6warning_list, _p);
L1:

    // end procedure
    DeRefDS(_msg);
    DeRefi(_p);
    DeRef(_600);
    return 0;
    ;
}


int _6ShowWarnings(int _errfile)
{
    int _c;
    int _605 = 0;
    int _604;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_errfile)) {
        _1 = (long)(DBL_PTR(_errfile)->dbl);
        DeRefDS(_errfile);
        _errfile = _1;
    }

    //     for i = 1 to length(warning_list) do
    _604 = SEQ_PTR(_6warning_list)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _604)
            goto L2;

        // 	if errfile = 0 then
        if (_errfile != 0)
            goto L3;

        // 	    screen_output(STDERR, warning_list[i])
        DeRef(_605);
        _2 = (int)SEQ_PTR(_6warning_list);
        _605 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_605);
        RefDS(_605);
        _6screen_output(2, _605);

        // 	    if remainder(i, 20) = 0 then
        DeRefDS(_605);
        _605 = (_i % 20);
        if (_605 != 0)
            goto L4;

        // 		puts(STDERR, "\nPress Enter to continue, q to quit\n\n")
        EPuts(2, _609);

        // 		c = getc(0)
        if (0 != last_r_file_no) {
            last_r_file_ptr = which_file(0, EF_READ);
            last_r_file_no = 0;
        }
        if (last_r_file_ptr == xstdin) {
            if (in_from_keyb) {
                _c = getc(xstdin);
            }
            else
                _c = getc(last_r_file_ptr);
        }
        else
            _c = getc(last_r_file_ptr);

        // 		if c = 'q' then
        if (_c != 113)
            goto L4;

        // 		    exit
        goto L2;
L5:
L6:
        goto L4;
L3:

        // 	    puts(errfile, warning_list[i])
        DeRef(_605);
        _2 = (int)SEQ_PTR(_6warning_list);
        _605 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_605);
        EPuts(_errfile, _605);
L4:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return length(warning_list)
    DeRef(_605);
    _605 = SEQ_PTR(_6warning_list)->length;
    return _605;
    ;
}


int _6Cleanup(int _status)
{
    int _w;
    int _614;
    int _617;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_status)) {
        _1 = (long)(DBL_PTR(_status)->dbl);
        DeRefDS(_status);
        _status = _1;
    }

    //     w = ShowWarnings(0) 
    _w = _6ShowWarnings(0);

    //     if not TRANSLATE and 
    _614 = (0 == 0);
    if (_614 == 0) {
        _614 = 0;
        goto L1;
    }
    if (0 != 0) {
        _617 = 1;
        goto L2;
    }
    _617 = (_4EWINDOWS != 0);
L2:
    if (_617 != 0) {
        _617 = 1;
        goto L3;
    }
    _617 = (_4ELINUX != 0);
L3:
    _614 = (_617 != 0);
L1:
    if (_614 == 0) {
        goto L4;
    }
    if (_w != 0) {
        _614 = 1;
        goto L5;
    }
    _614 = (_6Errors != 0);
L5:
L6:
    if (_614 == 0)
        goto L4;

    // 	screen_output(STDERR, "\nPress Enter\n")
    RefDS(_621);
    _6screen_output(2, _621);

    // 	if getc(0) then -- prompt
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _614 = getc(xstdin);
        }
        else
            _614 = getc(last_r_file_ptr);
    }
    else
        _614 = getc(last_r_file_ptr);
    if (_614 == 0)
        goto L7;
L7:
L4:

    //     abort(status)
    UserCleanup(_status);

    // end procedure
    return 0;
    ;
}


int _6OpenErrFile()
{
    int _624;
    int _0, _1, _2;
    

    //     TempErrFile = open(TempErrName, "w")
    _6TempErrFile = EOpen(_6TempErrName, _623);

    //     if TempErrFile = -1 then
    if (_6TempErrFile != -1)
        goto L1;

    // 	if length(TempErrName) > 0 then
    _624 = 6;

    // 	    screen_output(STDERR, "Can't create error message file: ")
    RefDS(_628);
    _6screen_output(2, _628);

    // 	    screen_output(STDERR, TempErrName)
    RefDS(_6TempErrName);
    _6screen_output(2, _6TempErrName);

    // 	    screen_output(STDERR, "\n")
    RefDS(_629);
    _6screen_output(2, _629);
L2:

    // 	abort(1) --Cleanup(1)
    UserCleanup(1);
L1:

    // end procedure
    return 0;
    ;
}


int _6ShowErr(int _f)
{
    int _636;
    int _630 = 0;
    int _0, _1, _2;
    

    //     if length(file_name) = 0 then
    _630 = SEQ_PTR(_4file_name)->length;
    if (_630 != 0)
        goto L1;

    // 	return
    return 0;
L1:

    //     if ThisLine[1] = END_OF_FILE_CHAR then
    DeRef(_630);
    _2 = (int)SEQ_PTR(_6ThisLine);
    _630 = (int)*(((s1_ptr)_2)->base + 1);
    if (_630 != 26)
        goto L2;

    // 	screen_output(f, "<end-of-file>\n")
    RefDS(_634);
    _6screen_output(_f, _634);
    goto L3;
L2:

    // 	screen_output(f, ThisLine)
    Ref(_6ThisLine);
    _6screen_output(_f, _6ThisLine);
L3:

    //     for i = 1 to bp-2 do -- bp-1 points to last character read
    DeRef(_630);
    _630 = _6bp - 2;
    if ((long)((unsigned long)_630 +(unsigned long) HIGH_BITS) >= 0)
        _630 = NewDouble((double)_630);
    { int _i;
        _i = 1;
L4:
        if (binary_op_a(GREATER, _i, _630))
            goto L5;

        // 	if ThisLine[i] = '\t' then
        _2 = (int)SEQ_PTR(_6ThisLine);
        if (!IS_ATOM_INT(_i))
            _636 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _636 = (int)*(((s1_ptr)_2)->base + _i);
        if (_636 != 9)
            goto L6;

        // 	    screen_output(f, "\t")
        RefDS(_638);
        _6screen_output(_f, _638);
        goto L7;
L6:

        // 	    screen_output(f, " ")
        RefDS(_639);
        _6screen_output(_f, _639);
L7:

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
        goto L4;
L5:
        ;
        DeRef(_i);
    }

    //     screen_output(f, "^\n\n") 
    RefDS(_640);
    _6screen_output(_f, _640);

    // end procedure
    DeRef(_630);
    return 0;
    ;
}


int _6CompileErr(int _msg)
{
    int _errmsg = 0;
    int _641 = 0;
    int _0, _1, _2;
    

    //     Errors += 1
    _6Errors = _6Errors + 1;

    //     if length(file_name) then
    _641 = SEQ_PTR(_4file_name)->length;
    if (_641 == 0)
        goto L1;

    // 	errmsg = sprintf("%s:%d\n%s\n", {file_name[current_file_no], 
    _2 = (int)SEQ_PTR(_4file_name);
    _641 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_641);
    _0 = _641;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_641);
    *((int *)(_2+4)) = _641;
    *((int *)(_2+8)) = _4line_number;
    RefDS(_msg);
    *((int *)(_2+12)) = _msg;
    _641 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _errmsg = EPrintf(-9999999, _643, _641);
    goto L2;
L1:

    // 	errmsg = msg
    RefDS(_msg);
    DeRef(_errmsg);
    _errmsg = _msg;
L2:

    //     OpenErrFile() -- exits if error filename is ""
    _6OpenErrFile();

    //     screen_output(STDERR, errmsg)
    RefDS(_errmsg);
    _6screen_output(2, _errmsg);

    //     ShowErr(STDERR)
    _6ShowErr(2);

    //     puts(TempErrFile, errmsg) 
    EPuts(_6TempErrFile, _errmsg);

    //     ShowErr(TempErrFile) 
    _6ShowErr(_6TempErrFile);

    //     if ShowWarnings(TempErrFile) then
    _0 = _641;
    _641 = _6ShowWarnings(_6TempErrFile);
    DeRef(_0);
    if (_641 == 0)
        goto L3;
L3:

    //     puts(TempErrFile, "\n")
    EPuts(_6TempErrFile, _629);

    //     close(TempErrFile)
    EClose(_6TempErrFile);

    //     Cleanup(1)
    _6Cleanup(1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_errmsg);
    DeRef(_641);
    return 0;
    ;
}


int _6InternalErr(int _msg)
{
    int _652 = 0;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    // 	screen_output(STDERR, sprintf("Internal Error at %s:%d - %s\n", 
    _2 = (int)SEQ_PTR(_4file_name);
    _652 = (int)*(((s1_ptr)_2)->base + _4current_file_no);
    RefDS(_652);
    _0 = _652;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_652);
    *((int *)(_2+4)) = _652;
    *((int *)(_2+8)) = _4line_number;
    RefDS(_msg);
    *((int *)(_2+12)) = _msg;
    _652 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _0 = _652;
    _652 = EPrintf(-9999999, _654, _652);
    DeRefDS(_0);
    RefDS(_652);
    _6screen_output(2, _652);
L1:

    //     screen_output(STDERR, "\nPress Enter\n")
    RefDS(_621);
    _6screen_output(2, _621);

    //     if getc(0) then
    DeRef(_652);
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _652 = getc(xstdin);
        }
        else
            _652 = getc(last_r_file_ptr);
    }
    else
        _652 = getc(last_r_file_ptr);
    if (_652 == 0)
        goto L2;
L2:

    //     ?1/0
    DeRef(_652);
    RTFatal("divide by 0");
    StdPrint(1, _652, 1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_652);
    return 0;
    ;
}


