// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16open_err_file()
{
    int _4164 = 0;
    int _0, _1, _2;
    

    //     err_file = open(err_file_name, "w")
    _16err_file = EOpen(_16err_file_name, _623);

    //     if err_file = -1 then
    if (_16err_file != -1)
        goto L1;

    // 	puts(2, "Can't open " & err_file_name & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _16err_file_name;
        concat_list[2] = _4166;
        Concat_N((object_ptr)&_4164, concat_list, 3);
    }
    EPuts(2, _4164);

    // 	abort(1)
    UserCleanup(1);
L1:

    // end procedure
    DeRef(_4164);
    return 0;
    ;
}


int _16both_puts(int _s)
{
    int _0, _1, _2;
    

    //     if screen_err_out then
    if (_16screen_err_out == 0)
        goto L1;

    // 	puts(2, s)
    EPuts(2, _s);
L1:

    //     puts(err_file, s)
    EPuts(_16err_file, _s);

    // end procedure
    DeRef(_s);
    return 0;
    ;
}


int _16both_printf(int _format, int _items)
{
    int _0, _1, _2;
    

    //     if screen_err_out then
    if (_16screen_err_out == 0)
        goto L1;

    // 	printf(2, format, items)
    EPrintf(2, _format, _items);
L1:

    //     printf(err_file, format, items)
    EPrintf(_16err_file, _format, _items);

    // end procedure
    DeRefDS(_format);
    DeRefDS(_items);
    return 0;
    ;
}


int _16find_line(int _sub, int _pc)
{
    int _linetab = 0;
    int _line;
    int _gline;
    int _4174 = 0;
    int _4171 = 0;
    int _4168 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    //     linetab = SymTab[sub][S_LINETAB]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4168 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4168);
    _2 = (int)SEQ_PTR(_4168);
    _linetab = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_linetab);

    //     line = 1
    _line = 1;

    //     for i = 1 to length(linetab) do
    DeRefDS(_4168);
    _4168 = SEQ_PTR(_linetab)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _4168)
            goto L2;

        // 	if linetab[i] >= pc or linetab[i] = -2 then
        DeRef(_4171);
        _2 = (int)SEQ_PTR(_linetab);
        _4171 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_4171);
        _0 = _4171;
        if (IS_ATOM_INT(_4171)) {
            _4171 = (_4171 >= _pc);
        }
        else {
            _4171 = binary_op(GREATEREQ, _4171, _pc);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_4171)) {
            if (_4171 != 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_4171)->dbl != 0.0) {
                goto L3;
            }
        }
        DeRef(_4174);
        _2 = (int)SEQ_PTR(_linetab);
        _4174 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_4174);
        _0 = _4174;
        if (IS_ATOM_INT(_4174)) {
            _4174 = (_4174 == -2);
        }
        else {
            _4174 = binary_op(EQUALS, _4174, -2);
        }
        DeRef(_0);
L4:
        if (_4174 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_4174) && DBL_PTR(_4174)->dbl == 0.0)
                goto L5;
        }
L3:

        // 	    line = i-1
        _line = _i - 1;

        // 	    while line > 1 and linetab[line] = -1 do
L6:
        DeRef(_4174);
        _4174 = (_line > 1);
        if (_4174 == 0) {
            goto L2;
        }
        DeRef(_4171);
        _2 = (int)SEQ_PTR(_linetab);
        _4171 = (int)*(((s1_ptr)_2)->base + _line);
        Ref(_4171);
        _0 = _4171;
        if (IS_ATOM_INT(_4171)) {
            _4171 = (_4171 == -1);
        }
        else {
            _4171 = binary_op(EQUALS, _4171, -1);
        }
        DeRef(_0);
L7:
        if (_4171 <= 0) {
            if (_4171 == 0) {
                goto L2;
            }
            else {
                if (!IS_ATOM_INT(_4171) && DBL_PTR(_4171)->dbl == 0.0)
                    goto L2;
            }
        }

        // 		line -= 1
        _line = _line - 1;

        // 	    end while
        goto L6;
L8:

        // 	    exit
        goto L2;
L5:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     gline = SymTab[sub][S_FIRSTLINE] + line - 1
    DeRef(_4171);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4171 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4171);
    _0 = _4171;
    _2 = (int)SEQ_PTR(_4171);
    _4171 = (int)*(((s1_ptr)_2)->base + 17);
    Ref(_4171);
    DeRefDS(_0);
    _0 = _4171;
    if (IS_ATOM_INT(_4171)) {
        _4171 = _4171 + _line;
        if ((long)((unsigned long)_4171 + (unsigned long)HIGH_BITS) >= 0) 
            _4171 = NewDouble((double)_4171);
    }
    else {
        _4171 = binary_op(PLUS, _4171, _line);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4171)) {
        _gline = _4171 - 1;
    }
    else {
        _gline = binary_op(MINUS, _4171, 1);
    }
    if (!IS_ATOM_INT(_gline)) {
        _1 = (long)(DBL_PTR(_gline)->dbl);
        DeRefDS(_gline);
        _gline = _1;
    }

    //     return {file_name[slist[gline][LOCAL_FILE_NO]], slist[gline][LINE]}
    DeRef(_4171);
    _2 = (int)SEQ_PTR(_4slist);
    _4171 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_4171);
    _0 = _4171;
    _2 = (int)SEQ_PTR(_4171);
    _4171 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4171);
    DeRef(_0);
    _0 = _4171;
    _2 = (int)SEQ_PTR(_4file_name);
    if (!IS_ATOM_INT(_4171))
        _4171 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4171)->dbl));
    else
        _4171 = (int)*(((s1_ptr)_2)->base + _4171);
    RefDS(_4171);
    DeRef(_0);
    DeRef(_4174);
    _2 = (int)SEQ_PTR(_4slist);
    _4174 = (int)*(((s1_ptr)_2)->base + _gline);
    Ref(_4174);
    _0 = _4174;
    _2 = (int)SEQ_PTR(_4174);
    _4174 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4174);
    DeRef(_0);
    _0 = _4174;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4171;
    RefDS(_4171);
    ((int *)_2)[2] = _4174;
    Ref(_4174);
    _4174 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_linetab);
    DeRefDS(_4171);
    DeRef(_4168);
    return _4174;
    ;
}


int _16show_var(int _x)
{
    int _4200 = 0;
    int _4192 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     puts(err_file, "    " & SymTab[x][S_NAME] & " = ")
    _2 = (int)SEQ_PTR(_4SymTab);
    _4192 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_4192);
    _0 = _4192;
    _2 = (int)SEQ_PTR(_4192);
    _4192 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4192);
    DeRefDS(_0);
    {
        int concat_list[3];

        concat_list[0] = _4194;
        concat_list[1] = _4192;
        concat_list[2] = _913;
        Concat_N((object_ptr)&_4192, concat_list, 3);
    }
    EPuts(_16err_file, _4192);

    //     if equal(val[x], NOVALUE) then
    DeRefDS(_4192);
    _2 = (int)SEQ_PTR(_16val);
    _4192 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_4192);
    _0 = _4192;
    if (_4192 == _4NOVALUE)
        _4192 = 1;
    else if (IS_ATOM_INT(_4192) && IS_ATOM_INT(_4NOVALUE))
        _4192 = 0;
    else
        _4192 = (compare(_4192, _4NOVALUE) == 0);
    DeRef(_0);
    if (_4192 == 0)
        goto L1;

    // 	puts(err_file, "<no value>")
    EPuts(_16err_file, _4198);
    goto L2;
L1:

    // 	pretty_print(err_file, val[x], 
    DeRef(_4192);
    _2 = (int)SEQ_PTR(_16val);
    _4192 = (int)*(((s1_ptr)_2)->base + _x);
    Ref(_4192);
    DeRef(_4200);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4200 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_4200);
    _0 = _4200;
    _2 = (int)SEQ_PTR(_4200);
    _4200 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4200);
    DeRefDS(_0);
    _0 = _4200;
    _4200 = SEQ_PTR(_4200)->length;
    DeRef(_0);
    _4200 = _4200 + 7;
    _1 = NewS1(9);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 1;
    *((int *)(_2+8)) = 2;
    *((int *)(_2+12)) = _4200;
    *((int *)(_2+16)) = 78;
    RefDS(_122);
    *((int *)(_2+20)) = _122;
    RefDS(_23);
    *((int *)(_2+24)) = _23;
    *((int *)(_2+28)) = 32;
    *((int *)(_2+32)) = 127;
    *((int *)(_2+36)) = 500;
    _4200 = MAKE_SEQ(_1);
    Ref(_4192);
    RefDS(_4200);
    _2pretty_print(_16err_file, _4192, _4200);
L2:

    //     puts(err_file, '\n')
    EPuts(_16err_file, 10);

    // end procedure
    DeRef(_4200);
    DeRef(_4192);
    return 0;
    ;
}


int _16save_private_block(int _routine, int _block)
{
    int _saved = 0;
    int _saved_list = 0;
    int _entry = 0;
    int _task;
    int _spot;
    int _tn;
    int _4222 = 0;
    int _4224 = 0;
    int _4218 = 0;
    int _4205 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_routine)) {
        _1 = (long)(DBL_PTR(_routine)->dbl);
        DeRefDS(_routine);
        _routine = _1;
    }

    //     task = SymTab[routine][S_RESIDENT_TASK]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4205 = (int)*(((s1_ptr)_2)->base + _routine);
    RefDS(_4205);
    _2 = (int)SEQ_PTR(_4205);
    _task = (int)*(((s1_ptr)_2)->base + 23);
    if (!IS_ATOM_INT(_task))
        _task = (long)DBL_PTR(_task)->dbl;

    //     entry = {task, tcb[task][TASK_TID], block, 0}
    DeRefDS(_4205);
    _2 = (int)SEQ_PTR(_16tcb);
    _4205 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4205);
    _0 = _4205;
    _2 = (int)SEQ_PTR(_4205);
    _4205 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4205);
    DeRefDS(_0);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _task;
    Ref(_4205);
    *((int *)(_2+8)) = _4205;
    RefDS(_block);
    *((int *)(_2+12)) = _block;
    *((int *)(_2+16)) = 0;
    _entry = MAKE_SEQ(_1);

    //     saved = SymTab[routine][S_SAVED_PRIVATES]
    DeRef(_4205);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4205 = (int)*(((s1_ptr)_2)->base + _routine);
    RefDS(_4205);
    _2 = (int)SEQ_PTR(_4205);
    _saved = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_saved);

    //     if length(saved) = 0 then
    DeRefDS(_4205);
    _4205 = SEQ_PTR(_saved)->length;
    if (_4205 != 0)
        goto L1;

    // 	saved = {1, -- index of first item
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_entry);
    *((int *)(_2+4)) = _entry;
    _4205 = MAKE_SEQ(_1);
    DeRefDS(_saved);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _4205;
    RefDS(_4205);
    _saved = MAKE_SEQ(_1);
    goto L2;
L1:

    // 	saved_list = saved[2]
    DeRef(_saved_list);
    _2 = (int)SEQ_PTR(_saved);
    _saved_list = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_saved_list);

    // 	spot = 0
    _spot = 0;

    // 	for i = 1 to length(saved_list) do
    DeRef(_4205);
    _4205 = SEQ_PTR(_saved_list)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _4205)
            goto L4;

        // 	    tn = saved_list[i][SP_TASK_NUMBER]
        DeRef(_4218);
        _2 = (int)SEQ_PTR(_saved_list);
        _4218 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_4218);
        _2 = (int)SEQ_PTR(_4218);
        _tn = (int)*(((s1_ptr)_2)->base + 1);
        if (!IS_ATOM_INT(_tn))
            _tn = (long)DBL_PTR(_tn)->dbl;

        // 	    if tn = -1 or 
        DeRef(_4218);
        _4218 = (_tn == -1);
        if (_4218 != 0) {
            goto L5;
        }
        DeRef(_4222);
        _2 = (int)SEQ_PTR(_saved_list);
        _4222 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_4222);
        _0 = _4222;
        _2 = (int)SEQ_PTR(_4222);
        _4222 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4222);
        DeRef(_0);
        DeRef(_4224);
        _2 = (int)SEQ_PTR(_16tcb);
        _4224 = (int)*(((s1_ptr)_2)->base + _tn);
        RefDS(_4224);
        _0 = _4224;
        _2 = (int)SEQ_PTR(_4224);
        _4224 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4224);
        DeRefDS(_0);
        _0 = _4224;
        if (IS_ATOM_INT(_4222) && IS_ATOM_INT(_4224)) {
            _4224 = (_4222 != _4224);
        }
        else {
            _4224 = binary_op(NOTEQ, _4222, _4224);
        }
        DeRef(_0);
L6:
        if (_4224 == 0) {
            goto L7;
        }
        else {
            if (!IS_ATOM_INT(_4224) && DBL_PTR(_4224)->dbl == 0.0)
                goto L7;
        }
L5:

        // 		spot = i
        _spot = _i;

        // 		exit
        goto L4;
L7:

        // 	end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // 	entry[SP_NEXT] = saved[1] -- new entry points to previous first
    DeRef(_4224);
    _2 = (int)SEQ_PTR(_saved);
    _4224 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4224);
    Ref(_4224);
    _2 = (int)SEQ_PTR(_entry);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _entry = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _4224;
    DeRef(_1);

    // 	if spot = 0 then
    if (_spot != 0)
        goto L8;

    // 	    saved_list = append(saved_list, entry)
    RefDS(_entry);
    Append(&_saved_list, _saved_list, _entry);

    // 	    spot = length(saved_list)
    _spot = SEQ_PTR(_saved_list)->length;
    goto L9;
L8:

    // 	    saved_list[spot] = entry
    RefDS(_entry);
    _2 = (int)SEQ_PTR(_saved_list);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved_list = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _spot);
    _1 = *(int *)_2;
    *(int *)_2 = _entry;
    DeRef(_1);
L9:

    // 	saved[1] = spot -- it becomes the first on the list
    _2 = (int)SEQ_PTR(_saved);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _spot;
    DeRef(_1);

    // 	saved[2] = saved_list
    RefDS(_saved_list);
    _2 = (int)SEQ_PTR(_saved);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _saved_list;
    DeRef(_1);
L2:

    //     SymTab[routine][S_SAVED_PRIVATES] = saved
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_routine + ((s1_ptr)_2)->base);
    RefDS(_saved);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _saved;
    DeRef(_1);

    // end procedure
    DeRefDS(_block);
    DeRefDS(_saved);
    DeRef(_saved_list);
    DeRef(_entry);
    DeRef(_4222);
    DeRef(_4224);
    DeRef(_4218);
    DeRef(_4205);
    return 0;
    ;
}


int _16load_private_block(int _routine, int _task)
{
    int _saved = 0;
    int _saved_list = 0;
    int _block = 0;
    int _p;
    int _prev_p;
    int _first;
    int _4233 = 0;
    int _4249 = 0;
    int _4243 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_routine)) {
        _1 = (long)(DBL_PTR(_routine)->dbl);
        DeRefDS(_routine);
        _routine = _1;
    }
    if (!IS_ATOM_INT(_task)) {
        _1 = (long)(DBL_PTR(_task)->dbl);
        DeRefDS(_task);
        _task = _1;
    }

    //     saved = SymTab[routine][S_SAVED_PRIVATES]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4233 = (int)*(((s1_ptr)_2)->base + _routine);
    RefDS(_4233);
    _2 = (int)SEQ_PTR(_4233);
    _saved = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_saved);

    //     first = saved[1]
    _2 = (int)SEQ_PTR(_saved);
    _first = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_first))
        _first = (long)DBL_PTR(_first)->dbl;

    //     p = first -- won't be 0
    _p = _first;

    //     prev_p = -1
    _prev_p = -1;

    //     saved_list = saved[2]
    _2 = (int)SEQ_PTR(_saved);
    _saved_list = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_saved_list);

    //     while TRUE do
L1:

    // 	if saved_list[p][SP_TASK_NUMBER] = task then
    DeRef(_4233);
    _2 = (int)SEQ_PTR(_saved_list);
    _4233 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_4233);
    _0 = _4233;
    _2 = (int)SEQ_PTR(_4233);
    _4233 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4233);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _4233, _task))
        goto L2;

    // 	    block = saved_list[p][SP_BLOCK]
    DeRef(_4233);
    _2 = (int)SEQ_PTR(_saved_list);
    _4233 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_4233);
    DeRef(_block);
    _2 = (int)SEQ_PTR(_4233);
    _block = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_block);

    // 	    saved_list[p][SP_TASK_NUMBER] = -1 -- mark it as deleted
    _2 = (int)SEQ_PTR(_saved_list);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved_list = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	    if prev_p = -1 then
    if (_prev_p != -1)
        goto L3;

    // 		first = saved_list[p][SP_NEXT]
    DeRef(_4243);
    _2 = (int)SEQ_PTR(_saved_list);
    _4243 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_4243);
    _2 = (int)SEQ_PTR(_4243);
    _first = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_first))
        _first = (long)DBL_PTR(_first)->dbl;
    goto L4;
L3:

    // 		saved_list[prev_p][SP_NEXT] = saved_list[p][SP_NEXT]
    _2 = (int)SEQ_PTR(_saved_list);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved_list = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev_p + ((s1_ptr)_2)->base);
    DeRef(_4249);
    _2 = (int)SEQ_PTR(_saved_list);
    _4249 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_4249);
    _0 = _4249;
    _2 = (int)SEQ_PTR(_4249);
    _4249 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4249);
    DeRef(_0);
    Ref(_4249);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _4249;
    DeRef(_1);
L4:

    // 	    saved[1] = first
    _2 = (int)SEQ_PTR(_saved);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _first;
    DeRef(_1);

    // 	    saved[2] = saved_list
    RefDS(_saved_list);
    _2 = (int)SEQ_PTR(_saved);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _saved = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _saved_list;
    DeRef(_1);

    // 	    SymTab[routine][S_SAVED_PRIVATES] = saved
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_routine + ((s1_ptr)_2)->base);
    RefDS(_saved);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _saved;
    DeRef(_1);

    // 	    return block
    DeRefDS(_saved);
    DeRefDS(_saved_list);
    DeRef(_4233);
    DeRef(_4249);
    DeRef(_4243);
    return _block;
L2:

    // 	prev_p = p
    _prev_p = _p;

    // 	p = saved_list[p][SP_NEXT]
    DeRef(_4233);
    _2 = (int)SEQ_PTR(_saved_list);
    _4233 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_4233);
    _2 = (int)SEQ_PTR(_4233);
    _p = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L5:
    ;
}


int _16restore_privates(int _this_routine)
{
    int _arg;
    int _private_block = 0;
    int _base;
    int _4265 = 0;
    int _4255 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_this_routine)) {
        _1 = (long)(DBL_PTR(_this_routine)->dbl);
        DeRefDS(_this_routine);
        _this_routine = _1;
    }

    //     if SymTab[this_routine][S_RESIDENT_TASK] != current_task then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4255);
    _0 = _4255;
    _2 = (int)SEQ_PTR(_4255);
    _4255 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_4255);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4255, _16current_task))
        goto L1;

    // 	if SymTab[this_routine][S_RESIDENT_TASK] != 0 then 
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4255);
    _0 = _4255;
    _2 = (int)SEQ_PTR(_4255);
    _4255 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_4255);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4255, 0))
        goto L2;

    // 	    arg = SymTab[this_routine][S_NEXT]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4255);
    _2 = (int)SEQ_PTR(_4255);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	    private_block = {}
    RefDS(_39);
    _private_block = _39;

    // 	    while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L3:
    DeRef(_4255);
    _4255 = (_arg != 0);
    if (_4255 == 0) {
        goto L4;
    }
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4265 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4265);
    _0 = _4265;
    _2 = (int)SEQ_PTR(_4265);
    _4265 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4265);
    DeRefDS(_0);
    _0 = _4265;
    if (IS_ATOM_INT(_4265)) {
        _4265 = (_4265 <= 3);
    }
    else {
        _4265 = binary_op(LESSEQ, _4265, 3);
    }
    DeRef(_0);
L5:
    if (_4265 <= 0) {
        if (_4265 == 0) {
            goto L4;
        }
        else {
            if (!IS_ATOM_INT(_4265) && DBL_PTR(_4265)->dbl == 0.0)
                goto L4;
        }
    }

    // 		private_block = append(private_block, val[arg])   
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_16val);
    _4265 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_4265);
    Ref(_4265);
    Append(&_private_block, _private_block, _4265);

    // 		arg = SymTab[arg][S_NEXT]
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4265 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4265);
    _2 = (int)SEQ_PTR(_4265);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	    end while
    goto L3;
L4:

    // 	    arg = SymTab[this_routine][S_TEMPS]
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4265 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4265);
    _2 = (int)SEQ_PTR(_4265);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	    while arg != 0 do
L6:
    if (_arg == 0)
        goto L7;

    // 		private_block = append(private_block, val[arg])   
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_16val);
    _4265 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_4265);
    Ref(_4265);
    Append(&_private_block, _private_block, _4265);

    // 		arg = SymTab[arg][S_NEXT]
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4265 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4265);
    _2 = (int)SEQ_PTR(_4265);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	    end while
    goto L6;
L7:

    // 	    save_private_block(this_routine, private_block)
    RefDS(_private_block);
    _16save_private_block(_this_routine, _private_block);
L2:

    // 	private_block = load_private_block(this_routine, current_task)
    _0 = _private_block;
    _private_block = _16load_private_block(_this_routine, _16current_task);
    DeRef(_0);

    // 	base = 1
    _base = 1;

    // 	arg = SymTab[this_routine][S_NEXT]
    DeRef(_4265);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4265 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4265);
    _2 = (int)SEQ_PTR(_4265);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L8:
    if (_arg == 0) {
        goto L9;
    }
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4255);
    _0 = _4255;
    _2 = (int)SEQ_PTR(_4255);
    _4255 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4255);
    DeRefDS(_0);
    _0 = _4255;
    if (IS_ATOM_INT(_4255)) {
        _4255 = (_4255 <= 3);
    }
    else {
        _4255 = binary_op(LESSEQ, _4255, 3);
    }
    DeRef(_0);
LA:
    if (_4255 <= 0) {
        if (_4255 == 0) {
            goto L9;
        }
        else {
            if (!IS_ATOM_INT(_4255) && DBL_PTR(_4255)->dbl == 0.0)
                goto L9;
        }
    }

    // 	    val[arg] = private_block[base]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_private_block);
    _4255 = (int)*(((s1_ptr)_2)->base + _base);
    Ref(_4255);
    Ref(_4255);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4255;
    DeRef(_1);

    // 	    base += 1
    _base = _base + 1;

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4255);
    _2 = (int)SEQ_PTR(_4255);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto L8;
L9:

    // 	arg = SymTab[this_routine][S_TEMPS]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _this_routine);
    RefDS(_4255);
    _2 = (int)SEQ_PTR(_4255);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	while arg != 0 do
LB:
    if (_arg == 0)
        goto LC;

    // 	    val[arg] = private_block[base]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_private_block);
    _4255 = (int)*(((s1_ptr)_2)->base + _base);
    Ref(_4255);
    Ref(_4255);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4255;
    DeRef(_1);

    // 	    base += 1
    _base = _base + 1;

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_4255);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4255 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4255);
    _2 = (int)SEQ_PTR(_4255);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto LB;
LC:

    // 	SymTab[this_routine][S_RESIDENT_TASK] = current_task
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_this_routine + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _16current_task;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_private_block);
    DeRef(_4265);
    DeRef(_4255);
    return 0;
    ;
}


int _16trace_back(int _msg)
{
    int _sub;
    int _v;
    int _levels;
    int _prev_file_no;
    int _task;
    int _dash_count;
    int _routine_name = 0;
    int _title = 0;
    int _show_message;
    int _4325 = 0;
    int _4374 = 0;
    int _4299 = 0;
    int _0, _1, _2, _3;
    

    //     if atom(slist[$]) then
    _4299 = SEQ_PTR(_4slist)->length;
    _2 = (int)SEQ_PTR(_4slist);
    _4299 = (int)*(((s1_ptr)_2)->base + _4299);
    Ref(_4299);
    _0 = _4299;
    _4299 = IS_ATOM(_4299);
    DeRef(_0);
    if (_4299 == 0)
        goto L1;

    // 	slist = s_expand(slist)
    RefDS(_4slist);
    _0 = _11s_expand(_4slist);
    DeRefDS(_4slist);
    _4slist = _0;
L1:

    //     show_message = TRUE
    _show_message = 1;

    //     screen_err_out = atom(crash_msg)
    _16screen_err_out = IS_ATOM(_16crash_msg);

    //     while TRUE do
L2:

    // 	if length(tcb) > 1 then
    DeRef(_4299);
    _4299 = SEQ_PTR(_16tcb)->length;
    if (_4299 <= 1)
        goto L3;

    // 	    if current_task = 1 then
    if (_16current_task != 1)
        goto L4;

    // 		routine_name = "initial task"
    RefDS(_4307);
    DeRef(_routine_name);
    _routine_name = _4307;
    goto L5;
L4:

    // 		routine_name = SymTab[e_routine[1+tcb[current_task][TASK_RID]]][S_NAME]
    DeRef(_4299);
    _2 = (int)SEQ_PTR(_16tcb);
    _4299 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4299);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_4299);
    _4299 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4299);
    DeRefDS(_0);
    _0 = _4299;
    if (IS_ATOM_INT(_4299)) {
        _4299 = _4299 + 1;
    }
    else
        _4299 = binary_op(PLUS, 1, _4299);
    DeRef(_0);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_16e_routine);
    if (!IS_ATOM_INT(_4299))
        _4299 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4299)->dbl));
    else
        _4299 = (int)*(((s1_ptr)_2)->base + _4299);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4299 = (int)*(((s1_ptr)_2)->base + _4299);
    RefDS(_4299);
    DeRef(_routine_name);
    _2 = (int)SEQ_PTR(_4299);
    _routine_name = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_routine_name);
L5:

    // 	    title = sprintf(" TASK ID %d: %s ", 
    DeRef(_4299);
    _2 = (int)SEQ_PTR(_16tcb);
    _4299 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4299);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_4299);
    _4299 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4299);
    DeRefDS(_0);
    _0 = _4299;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4299;
    Ref(_4299);
    ((int *)_2)[2] = _routine_name;
    RefDS(_routine_name);
    _4299 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefi(_title);
    _title = EPrintf(-9999999, _4314, _4299);

    // 	    dash_count = 60
    _dash_count = 60;

    // 	    if length(title) < dash_count then
    DeRefDS(_4299);
    _4299 = SEQ_PTR(_title)->length;
    if (_4299 >= 60)
        goto L6;

    // 		dash_count = 52 - length(title)
    _4299 = SEQ_PTR(_title)->length;
    _dash_count = 52 - _4299;
L6:

    // 	    if dash_count < 1 then
    if (_dash_count >= 1)
        goto L7;

    // 		dash_count = 1
    _dash_count = 1;
L7:

    // 	    both_puts(repeat('-', 22) & title & repeat('-', dash_count) & "\n")
    DeRef(_4299);
    _4299 = Repeat(45, 22);
    DeRef(_4325);
    _4325 = Repeat(45, _dash_count);
    {
        int concat_list[4];

        concat_list[0] = _629;
        concat_list[1] = _4325;
        concat_list[2] = _title;
        concat_list[3] = _4299;
        Concat_N((object_ptr)&_4325, concat_list, 4);
    }
    RefDS(_4325);
    _16both_puts(_4325);
L3:

    // 	levels = 1
    _levels = 1;

    // 	while length(call_stack) > 0 do
L8:
    DeRef(_4325);
    _4325 = SEQ_PTR(_16call_stack)->length;
    if (_4325 <= 0)
        goto L9;

    // 	    sub = call_stack[$]
    _4325 = SEQ_PTR(_16call_stack)->length;
    _2 = (int)SEQ_PTR(_16call_stack);
    _sub = (int)*(((s1_ptr)_2)->base + _4325);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    // 	    if levels = 1 then
    if (_levels != 1)
        goto LA;

    // 		puts(2, '\n')
    EPuts(2, 10);
    goto LB;
LA:

    // 	    elsif sub != call_back_routine then
    if (_sub == _16call_back_routine)
        goto LC;

    // 		both_puts("... called from ")
    RefDS(_4333);
    _16both_puts(_4333);
LC:
LB:

    // 	    if sub = call_back_routine then
    if (_sub != _16call_back_routine)
        goto LD;

    // 		if crash_count > 0 then
    if (_16crash_count <= 0)
        goto LE;

    // 		    both_puts("^^^ called to handle run-time crash\n")
    RefDS(_4336);
    _16both_puts(_4336);

    // 		    exit
    goto L9;
    goto LF;
LE:

    // 		    both_puts("^^^ call-back from ")
    RefDS(_4337);
    _16both_puts(_4337);

    // 		    if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L10;

    // 			both_puts("Windows\n")
    RefDS(_4338);
    _16both_puts(_4338);
    goto LF;
L10:

    // 			both_puts("external program\n")
    RefDS(_4339);
    _16both_puts(_4339);
L11:
L12:
    goto LF;
LD:

    // 		both_printf("%s:%d ", find_line(sub, pc)) 
    _0 = _4325;
    _4325 = _16find_line(_sub, _16pc);
    DeRef(_0);
    RefDS(_4340);
    RefDS(_4325);
    _16both_printf(_4340, _4325);

    // 		if not equal(SymTab[sub][S_NAME], "_toplevel_") then
    DeRefDS(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4325);
    DeRefDS(_0);
    _0 = _4325;
    if (_4325 == _862)
        _4325 = 1;
    else if (IS_ATOM_INT(_4325) && IS_ATOM_INT(_862))
        _4325 = 0;
    else
        _4325 = (compare(_4325, _862) == 0);
    DeRef(_0);
    if (_4325 != 0)
        goto L13;

    // 		    if SymTab[sub][S_TOKEN] = PROC then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4325);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4325, 27))
        goto L14;

    // 			both_puts("in procedure ")
    RefDS(_4349);
    _16both_puts(_4349);
    goto L15;
L14:

    // 		    elsif SymTab[sub][S_TOKEN] = FUNC then
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4325);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4325, 501))
        goto L16;

    // 			both_puts("in function ")
    RefDS(_4353);
    _16both_puts(_4353);
    goto L15;
L16:

    // 		    elsif SymTab[sub][S_TOKEN] = TYPE then
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4325);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4325, 504))
        goto L17;

    // 			both_puts("in type ")
    RefDS(_4357);
    _16both_puts(_4357);
L17:
L15:

    // 		    both_printf("%s()", {SymTab[sub][S_NAME]})
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4325);
    DeRefDS(_0);
    _0 = _4325;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4325);
    *((int *)(_2+4)) = _4325;
    _4325 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_4358);
    RefDS(_4325);
    _16both_printf(_4358, _4325);
L13:

    // 		both_puts("\n")
    RefDS(_629);
    _16both_puts(_629);

    // 		if show_message then
    if (_show_message == 0)
        goto L18;

    // 		    if sequence(crash_msg) then
    DeRef(_4325);
    _4325 = IS_SEQUENCE(_16crash_msg);
    if (_4325 == 0)
        goto L19;

    // 			clear_screen()
    ClearScreen();

    // 			puts(2, crash_msg)
    EPuts(2, _16crash_msg);
L19:

    // 		    both_puts(msg & '\n')
    Append(&_4325, _msg, 10);
    RefDS(_4325);
    _16both_puts(_4325);

    // 		    show_message = FALSE
    _show_message = 0;
L18:

    // 		if length(call_stack) < 2 then
    DeRef(_4325);
    _4325 = SEQ_PTR(_16call_stack)->length;
    if (_4325 >= 2)
        goto L1A;

    // 		    both_puts('\n')
    _16both_puts(10);

    // 		    exit
    goto L9;
L1A:

    // 		v = SymTab[sub][S_NEXT]
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4325);
    _2 = (int)SEQ_PTR(_4325);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    // 		while v != 0 and 
L1B:
    DeRef(_4325);
    _4325 = (_v != 0);
    if (_4325 == 0) {
        goto L1C;
    }
    DeRef(_4299);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4299 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4299);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_4299);
    _4299 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4299);
    DeRefDS(_0);
    _0 = _4299;
    if (IS_ATOM_INT(_4299)) {
        _4299 = (_4299 == 3);
    }
    else {
        _4299 = binary_op(EQUALS, _4299, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4299)) {
        if (_4299 != 0) {
            DeRef(_4299);
            _4299 = 1;
            goto L1D;
        }
    }
    else {
        if (DBL_PTR(_4299)->dbl != 0.0) {
            DeRef(_4299);
            _4299 = 1;
            goto L1D;
        }
    }
    DeRef(_4374);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4374 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4374);
    _0 = _4374;
    _2 = (int)SEQ_PTR(_4374);
    _4374 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4374);
    DeRefDS(_0);
    _0 = _4374;
    if (IS_ATOM_INT(_4374)) {
        _4374 = (_4374 == 2);
    }
    else {
        _4374 = binary_op(EQUALS, _4374, 2);
    }
    DeRef(_0);
    DeRef(_4299);
    if (IS_ATOM_INT(_4374))
        _4299 = (_4374 != 0);
    else
        _4299 = DBL_PTR(_4374)->dbl != 0.0;
L1D:
L1E:
    if (_4299 == 0)
        goto L1C;

    // 		    show_var(v)
    _16show_var(_v);

    // 		    v = SymTab[v][S_NEXT]
    DeRef(_4374);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4374 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4374);
    _2 = (int)SEQ_PTR(_4374);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    // 		end while
    goto L1B;
L1C:

    // 		if length(SymTab[sub][S_SAVED_PRIVATES]) > 0 and
    DeRef(_4374);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4374 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4374);
    _0 = _4374;
    _2 = (int)SEQ_PTR(_4374);
    _4374 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4374);
    DeRefDS(_0);
    _0 = _4374;
    _4374 = SEQ_PTR(_4374)->length;
    DeRef(_0);
    _4374 = (_4374 > 0);
    if (_4374 == 0) {
        goto L1F;
    }
    DeRef(_4299);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4299 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4299);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_4299);
    _4299 = (int)*(((s1_ptr)_2)->base + 24);
    Ref(_4299);
    DeRefDS(_0);
    _0 = _4299;
    _2 = (int)SEQ_PTR(_4299);
    _4299 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4299);
    DeRef(_0);
    _0 = _4299;
    if (IS_ATOM_INT(_4299)) {
        _4299 = (_4299 != 0);
    }
    else {
        _4299 = binary_op(NOTEQ, _4299, 0);
    }
    DeRef(_0);
L20:
    if (_4299 == 0) {
        goto L1F;
    }
    else {
        if (!IS_ATOM_INT(_4299) && DBL_PTR(_4299)->dbl == 0.0)
            goto L1F;
    }

    // 		    SymTab[sub][S_RESIDENT_TASK] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 		    restore_privates(sub)
    _16restore_privates(_sub);
L1F:
LF:

    // 	    puts(err_file, '\n')
    EPuts(_16err_file, 10);

    // 	    pc = call_stack[$-1] - 1
    DeRef(_4374);
    _4374 = SEQ_PTR(_16call_stack)->length;
    _4374 = _4374 - 1;
    _2 = (int)SEQ_PTR(_16call_stack);
    _4374 = (int)*(((s1_ptr)_2)->base + _4374);
    Ref(_4374);
    if (IS_ATOM_INT(_4374)) {
        _16pc = _4374 - 1;
    }
    else {
        _16pc = binary_op(MINUS, _4374, 1);
    }
    if (!IS_ATOM_INT(_16pc)) {
        _1 = (long)(DBL_PTR(_16pc)->dbl);
        DeRefDS(_16pc);
        _16pc = _1;
    }

    // 	    call_stack = call_stack[1..$-2]
    DeRef(_4374);
    _4374 = SEQ_PTR(_16call_stack)->length;
    _4374 = _4374 - 2;
    rhs_slice_target = (object_ptr)&_16call_stack;
    RHS_Slice((s1_ptr)_16call_stack, 1, _4374);

    // 	    levels += 1
    _levels = _levels + 1;

    // 	end while
    goto L8;
L9:

    // 	tcb[current_task][TASK_STATUS] = ST_DEAD -- mark as "deleted"
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	task = current_task
    _task = _16current_task;

    // 	for i = 1 to length(tcb) do
    DeRef(_4299);
    _4299 = SEQ_PTR(_16tcb)->length;
    { int _i;
        _i = 1;
L21:
        if (_i > _4299)
            goto L22;

        // 	    if tcb[i][TASK_STATUS] != ST_DEAD and 
        DeRef(_4374);
        _2 = (int)SEQ_PTR(_16tcb);
        _4374 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4374);
        _0 = _4374;
        _2 = (int)SEQ_PTR(_4374);
        _4374 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_4374);
        DeRefDS(_0);
        _0 = _4374;
        if (IS_ATOM_INT(_4374)) {
            _4374 = (_4374 != 2);
        }
        else {
            _4374 = binary_op(NOTEQ, _4374, 2);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_4374)) {
            if (_4374 == 0) {
                goto L23;
            }
        }
        else {
            if (DBL_PTR(_4374)->dbl == 0.0) {
                goto L23;
            }
        }
        DeRef(_4325);
        _2 = (int)SEQ_PTR(_16tcb);
        _4325 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4325);
        _0 = _4325;
        _2 = (int)SEQ_PTR(_4325);
        _4325 = (int)*(((s1_ptr)_2)->base + 16);
        Ref(_4325);
        DeRefDS(_0);
        _0 = _4325;
        _4325 = SEQ_PTR(_4325)->length;
        DeRef(_0);
        _4325 = (_4325 > 0);
L24:
        if (_4325 == 0)
            goto L23;

        // 		current_task = i
        _16current_task = _i;

        // 		call_stack = tcb[i][TASK_STACK]
        DeRef(_4325);
        _2 = (int)SEQ_PTR(_16tcb);
        _4325 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4325);
        DeRef(_16call_stack);
        _2 = (int)SEQ_PTR(_4325);
        _16call_stack = (int)*(((s1_ptr)_2)->base + 16);
        Ref(_16call_stack);

        // 		pc = tcb[i][TASK_PC]
        DeRefDS(_4325);
        _2 = (int)SEQ_PTR(_16tcb);
        _4325 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4325);
        _2 = (int)SEQ_PTR(_4325);
        _16pc = (int)*(((s1_ptr)_2)->base + 14);
        if (!IS_ATOM_INT(_16pc))
            _16pc = (long)DBL_PTR(_16pc)->dbl;

        // 		Code = tcb[i][TASK_CODE]
        DeRefDS(_4325);
        _2 = (int)SEQ_PTR(_16tcb);
        _4325 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4325);
        DeRef(_4Code);
        _2 = (int)SEQ_PTR(_4325);
        _4Code = (int)*(((s1_ptr)_2)->base + 15);
        Ref(_4Code);

        // 		screen_err_out = FALSE  -- just show offending task on screen
        _16screen_err_out = 0;

        // 		exit
        goto L22;
L23:

        // 	end for 
        _i = _i + 1;
        goto L21;
L22:
        ;
    }

    // 	if task = current_task then
    if (_task != _16current_task)
        goto L25;

    // 	    exit
    goto L26;
L25:

    // 	both_puts("\n")
    RefDS(_629);
    _16both_puts(_629);

    //     end while
    goto L2;
L26:

    //     puts(2, "\n--> see " & err_file_name & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _16err_file_name;
        concat_list[2] = _4416;
        Concat_N((object_ptr)&_4325, concat_list, 3);
    }
    EPuts(2, _4325);

    //     puts(err_file, "\n\nGlobal & Local Variables\n")
    EPuts(_16err_file, _4418);

    //     prev_file_no = -1
    _prev_file_no = -1;

    //     v = SymTab[TopLevelSub][S_NEXT]
    DeRefDS(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_4325);
    _2 = (int)SEQ_PTR(_4325);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    //     while v do
L27:
    if (_v == 0)
        goto L28;

    // 	if SymTab[v][S_TOKEN] = VARIABLE and 
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4325);
    DeRefDS(_0);
    _0 = _4325;
    if (IS_ATOM_INT(_4325)) {
        _4325 = (_4325 == -100);
    }
    else {
        _4325 = binary_op(EQUALS, _4325, -100);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4325)) {
        if (_4325 == 0) {
            DeRef(_4325);
            _4325 = 0;
            goto L29;
        }
    }
    else {
        if (DBL_PTR(_4325)->dbl == 0.0) {
            DeRef(_4325);
            _4325 = 0;
            goto L29;
        }
    }
    DeRef(_4374);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4374 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4374);
    _0 = _4374;
    _2 = (int)SEQ_PTR(_4374);
    _4374 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4374);
    DeRefDS(_0);
    _0 = _4374;
    if (IS_ATOM_INT(_4374)) {
        _4374 = (_4374 == 1);
    }
    else {
        _4374 = binary_op(EQUALS, _4374, 1);
    }
    DeRef(_0);
    DeRef(_4325);
    if (IS_ATOM_INT(_4374))
        _4325 = (_4374 != 0);
    else
        _4325 = DBL_PTR(_4374)->dbl != 0.0;
L29:
    if (_4325 == 0) {
        goto L2A;
    }
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4325);
    DeRefDS(_0);
    _0 = _4325;
    _4325 = find(_4325, _4431);
    DeRef(_0);
L2B:
    if (_4325 == 0)
        goto L2A;

    // 	    if SymTab[v][S_FILE_NO] != prev_file_no then
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4325);
    _0 = _4325;
    _2 = (int)SEQ_PTR(_4325);
    _4325 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4325);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4325, _prev_file_no))
        goto L2C;

    // 		prev_file_no = SymTab[v][S_FILE_NO]
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4325);
    _2 = (int)SEQ_PTR(_4325);
    _prev_file_no = (int)*(((s1_ptr)_2)->base + 6);
    if (!IS_ATOM_INT(_prev_file_no))
        _prev_file_no = (long)DBL_PTR(_prev_file_no)->dbl;

    // 		puts(err_file, "\n " & file_name[prev_file_no] & ":\n")
    DeRefDS(_4325);
    _2 = (int)SEQ_PTR(_4file_name);
    _4325 = (int)*(((s1_ptr)_2)->base + _prev_file_no);
    RefDS(_4325);
    {
        int concat_list[3];

        concat_list[0] = _4440;
        concat_list[1] = _4325;
        concat_list[2] = _4438;
        Concat_N((object_ptr)&_4325, concat_list, 3);
    }
    EPuts(_16err_file, _4325);
L2C:

    // 	    show_var(v)
    _16show_var(_v);
L2A:

    // 	v = SymTab[v][S_NEXT]
    DeRef(_4325);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4325 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_4325);
    _2 = (int)SEQ_PTR(_4325);
    _v = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_v))
        _v = (long)DBL_PTR(_v)->dbl;

    //     end while
    goto L27;
L28:

    //     puts(err_file, '\n')
    EPuts(_16err_file, 10);

    //     close(err_file)
    EClose(_16err_file);

    // end procedure
    DeRefDS(_msg);
    DeRef(_routine_name);
    DeRefi(_title);
    DeRef(_4325);
    DeRef(_4374);
    DeRef(_4299);
    return 0;
    ;
}


int _16call_crash_routines()
{
    int _quit = 0;
    int _4450 = 0;
    int _4444 = 0;
    int _0, _1, _2;
    

    //     if crash_count > 0 then
    if (_16crash_count <= 0)
        goto L1;

    // 	return
    return 0;
L1:

    //     crash_count += 1
    _16crash_count = _16crash_count + 1;

    //     err_file_name = "ex_crash.err"
    RefDS(_4446);
    DeRef(_16err_file_name);
    _16err_file_name = _4446;

    //     for i = length(crash_list) to 1 by -1 do
    DeRef(_4444);
    _4444 = SEQ_PTR(_16crash_list)->length;
    { int _i;
        _i = _4444;
L2:
        if (_i < 1)
            goto L3;

        // 	quit = call_func(forward_general_callback, 
        DeRef(_4444);
        _2 = (int)SEQ_PTR(_16crash_list);
        _4444 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_4444);
        _0 = _4444;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        Ref(_4444);
        *((int *)(_2+8)) = _4444;
        *((int *)(_2+12)) = 1;
        _4444 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _4450;
        _1 = NewS1(1);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        _4450 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _4450;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4444;
        RefDS(_4444);
        ((int *)_2)[2] = _4450;
        RefDS(_4450);
        _4450 = MAKE_SEQ(_1);
        DeRefDSi(_0);
        _1 = (int)SEQ_PTR(_4450);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_16forward_general_callback].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_quit);
        _quit = _1;

        // 	if not equal(quit, 0) then
        DeRefDS(_4450);
        if (_quit == 0)
            _4450 = 1;
        else if (IS_ATOM_INT(_quit) && IS_ATOM_INT(0))
            _4450 = 0;
        else
            _4450 = (compare(_quit, 0) == 0);
        if (_4450 != 0)
            goto L4;

        // 	    return -- don't call the others
        DeRef(_quit);
        DeRefDS(_4444);
        return 0;
L4:

        //     end for
        _i = _i + -1;
        goto L2;
L3:
        ;
    }

    // end procedure
    DeRef(_quit);
    DeRef(_4450);
    DeRef(_4444);
    return 0;
    ;
}


int _16quit_after_error()
{
    int _4456;
    int _0, _1, _2;
    

    //     if EWINDOWS then
    if (_4EWINDOWS == 0)
        goto L1;

    // 	puts(2, "\nPress Enter...\n")
    EPuts(2, _4455);

    // 	if getc(0) then
    if (0 != last_r_file_no) {
        last_r_file_ptr = which_file(0, EF_READ);
        last_r_file_no = 0;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _4456 = getc(xstdin);
        }
        else
            _4456 = getc(last_r_file_ptr);
    }
    else
        _4456 = getc(last_r_file_ptr);
    if (_4456 == 0)
        goto L2;
L2:
L1:

    //     abort(1)
    UserCleanup(1);

    // end procedure
    return 0;
    ;
}


int _16RTFatalType(int _x)
{
    int _msg = 0;
    int _v = 0;
    int _vname = 0;
    int _4457 = 0;
    int _4466;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     open_err_file()
    _16open_err_file();

    //     a = Code[x]
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _x);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     vname = SymTab[a][S_NAME]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4457 = (int)*(((s1_ptr)_2)->base + _16a);
    RefDS(_4457);
    _2 = (int)SEQ_PTR(_4457);
    _vname = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_vname);

    //     msg = sprintf("type_check error\n%s is ", {vname}) 
    _0 = _4457;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_vname);
    *((int *)(_2+4)) = _vname;
    _4457 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _msg = EPrintf(-9999999, _4460, _4457);

    //     v = sprint(val[a])
    DeRefDS(_4457);
    _2 = (int)SEQ_PTR(_16val);
    _4457 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4457);
    Ref(_4457);
    _v = _2sprint(_4457);

    //     if length(v) > 70 - length(vname) then
    DeRef(_4457);
    _4457 = SEQ_PTR(_v)->length;
    _4466 = SEQ_PTR(_vname)->length;
    _4466 = 70 - _4466;
    if (_4457 <= _4466)
        goto L1;

    // 	v = v[1..70 - length(vname)]
    _4466 = SEQ_PTR(_vname)->length;
    _4466 = 70 - _4466;
    rhs_slice_target = (object_ptr)&_v;
    RHS_Slice((s1_ptr)_v, 1, _4466);

    // 	while length(v) and not find(v[$], ",}")  do
L2:
    _4466 = SEQ_PTR(_v)->length;
    if (_4466 == 0) {
        goto L3;
    }
    DeRef(_4457);
    _4457 = SEQ_PTR(_v)->length;
    _2 = (int)SEQ_PTR(_v);
    _4457 = (int)*(((s1_ptr)_2)->base + _4457);
    Ref(_4457);
    _0 = _4457;
    _4457 = find(_4457, _4476);
    DeRef(_0);
    _4457 = (_4457 == 0);
L4:
    if (_4457 == 0)
        goto L3;

    // 	    v = v[1..$-1]
    DeRef(_4457);
    _4457 = SEQ_PTR(_v)->length;
    _4457 = _4457 - 1;
    rhs_slice_target = (object_ptr)&_v;
    RHS_Slice((s1_ptr)_v, 1, _4457);

    // 	end while
    goto L2;
L3:

    // 	v = v & " ..."
    Concat((object_ptr)&_v, _v, (s1_ptr)_113);
L1:

    //     trace_back(msg & v)
    Concat((object_ptr)&_4457, _msg, (s1_ptr)_v);
    RefDS(_4457);
    _16trace_back(_4457);

    //     call_crash_routines()
    _16call_crash_routines();

    //     quit_after_error()
    _16quit_after_error();

    // end procedure
    DeRefDSi(_msg);
    DeRefDS(_v);
    DeRef(_vname);
    DeRefDS(_4457);
    return 0;
    ;
}


int _16RTFatal(int _msg)
{
    int _0, _1, _2;
    

    //     open_err_file()
    _16open_err_file();

    //     trace_back(msg)
    RefDS(_msg);
    _16trace_back(_msg);

    //     call_crash_routines()
    _16call_crash_routines();

    //     quit_after_error()
    _16quit_after_error();

    // end procedure
    DeRefDS(_msg);
    return 0;
    ;
}


int _16RTInternal(int _msg)
{
    int _4484 = 0;
    int _0, _1, _2;
    

    //     puts(2, '\n' & msg & '\n')
    {
        int concat_list[3];

        concat_list[0] = 10;
        concat_list[1] = _msg;
        concat_list[2] = 10;
        Concat_N((object_ptr)&_4484, concat_list, 3);
    }
    EPuts(2, _4484);

    //     ? 1/0
    DeRefDS(_4484);
    RTFatal("divide by 0");
    StdPrint(1, _4484, 1);

    // end procedure
    DeRefDS(_msg);
    DeRef(_4484);
    return 0;
    ;
}


int _16wait(int _t)
{
    int _t1 = 0;
    int _t2 = 0;
    int _4486 = 0;
    int _0, _1, _2;
    

    //     t1 = floor(t)
    if (IS_ATOM_INT(_t))
        _t1 = e_floor(_t);
    else
        _t1 = unary_op(FLOOR, _t);

    //     if t1 >= 1 then
    if (binary_op_a(LESS, _t1, 1))
        goto L1;

    // 	sleep(t1)
    Ref(_t1);
    _2sleep(_t1);

    // 	t -= t1
    _0 = _t;
    if (IS_ATOM_INT(_t) && IS_ATOM_INT(_t1)) {
        _t = _t - _t1;
        if ((long)((unsigned long)_t +(unsigned long) HIGH_BITS) >= 0)
            _t = NewDouble((double)_t);
    }
    else {
        if (IS_ATOM_INT(_t)) {
            _t = NewDouble((double)_t - DBL_PTR(_t1)->dbl);
        }
        else {
            if (IS_ATOM_INT(_t1)) {
                _t = NewDouble(DBL_PTR(_t)->dbl - (double)_t1);
            }
            else
                _t = NewDouble(DBL_PTR(_t)->dbl - DBL_PTR(_t1)->dbl);
        }
    }
    DeRef(_0);
L1:

    //     t2 = time() + t
    DeRef(_4486);
    _4486 = NewDouble(current_time());
    DeRef(_t2);
    if (IS_ATOM_INT(_t)) {
        _t2 = NewDouble(DBL_PTR(_4486)->dbl + (double)_t);
    }
    else
        _t2 = NewDouble(DBL_PTR(_4486)->dbl + DBL_PTR(_t)->dbl);

    //     while time() < t2 do
L2:
    DeRef(_4486);
    _4486 = NewDouble(current_time());
    if (binary_op_a(GREATEREQ, _4486, _t2))
        goto L3;

    //     end while
    goto L2;
L3:

    // end procedure
    DeRef(_t);
    DeRef(_t1);
    DeRef(_t2);
    DeRef(_4486);
    return 0;
    ;
}


int _16scheduler()
{
    int _earliest_time = 0;
    int _start_time = 0;
    int _now = 0;
    int _ts_found;
    int _tp = 0;
    int _p;
    int _earliest_task;
    int _4493 = 0;
    int _4520 = 0;
    int _4494 = 0;
    int _0, _1, _2, _3;
    

    //     earliest_task = rt_first
    _earliest_task = _16rt_first;

    //     if clock_stopped or earliest_task = 0 then
    if (_16clock_stopped != 0) {
        goto L1;
    }
    _4494 = (_earliest_task == 0);
L2:
    if (_4494 == 0)
        goto L3;
L1:

    // 	start_time = 1
    DeRef(_start_time);
    _start_time = 1;

    // 	now = -1
    DeRef(_now);
    _now = -1;
    goto L4;
L3:

    // 	earliest_time = tcb[earliest_task][TASK_MAX_TIME]
    DeRef(_4494);
    _2 = (int)SEQ_PTR(_16tcb);
    _4494 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4494);
    DeRef(_earliest_time);
    _2 = (int)SEQ_PTR(_4494);
    _earliest_time = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_earliest_time);

    // 	p = tcb[rt_first][TASK_NEXT]
    DeRefDS(_4494);
    _2 = (int)SEQ_PTR(_16tcb);
    _4494 = (int)*(((s1_ptr)_2)->base + _16rt_first);
    RefDS(_4494);
    _2 = (int)SEQ_PTR(_4494);
    _p = (int)*(((s1_ptr)_2)->base + 12);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	while p != 0 do
L5:
    if (_p == 0)
        goto L6;

    // 	    tp = tcb[p]
    DeRef(_tp);
    _2 = (int)SEQ_PTR(_16tcb);
    _tp = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_tp);

    // 	    if tp[TASK_MAX_TIME] < earliest_time then
    DeRef(_4494);
    _2 = (int)SEQ_PTR(_tp);
    _4494 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4494);
    if (binary_op_a(GREATEREQ, _4494, _earliest_time))
        goto L7;

    // 		earliest_task = p
    _earliest_task = _p;

    // 		earliest_time = tp[TASK_MAX_TIME]
    DeRef(_earliest_time);
    _2 = (int)SEQ_PTR(_tp);
    _earliest_time = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_earliest_time);
L7:

    // 	    p = tp[TASK_NEXT]
    _2 = (int)SEQ_PTR(_tp);
    _p = (int)*(((s1_ptr)_2)->base + 12);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	end while
    goto L5;
L6:

    // 	now = time()
    DeRef(_now);
    _now = NewDouble(current_time());

    // 	start_time = tcb[earliest_task][TASK_MIN_TIME]
    DeRef(_4494);
    _2 = (int)SEQ_PTR(_16tcb);
    _4494 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4494);
    DeRef(_start_time);
    _2 = (int)SEQ_PTR(_4494);
    _start_time = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_start_time);

    // 	if earliest_task = current_task and 
    DeRefDS(_4494);
    _4494 = (_earliest_task == _16current_task);
    if (_4494 == 0) {
        goto L8;
    }
    DeRef(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4493);
    _0 = _4493;
    _2 = (int)SEQ_PTR(_4493);
    _4493 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4493);
    DeRefDS(_0);
    _0 = _4493;
    if (IS_ATOM_INT(_4493)) {
        _4493 = (_4493 > 0);
    }
    else {
        _4493 = binary_op(GREATER, _4493, 0);
    }
    DeRef(_0);
L9:
    if (_4493 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_4493) && DBL_PTR(_4493)->dbl == 0.0)
            goto L8;
    }
    goto LA;
L8:

    // 	    if tcb[current_task][TASK_TYPE] = T_REAL_TIME then
    DeRef(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4493);
    _0 = _4493;
    _2 = (int)SEQ_PTR(_4493);
    _4493 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4493);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4493, 1))
        goto LB;

    // 		tcb[current_task][TASK_RUNS_LEFT] = 0
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
LB:

    // 	    tcb[earliest_task][TASK_RUNS_LEFT] = tcb[earliest_task][TASK_RUNS_MAX]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_earliest_task + ((s1_ptr)_2)->base);
    DeRef(_4520);
    _2 = (int)SEQ_PTR(_16tcb);
    _4520 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4520);
    _0 = _4520;
    _2 = (int)SEQ_PTR(_4520);
    _4520 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4520);
    DeRefDS(_0);
    Ref(_4520);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _4520;
    DeRef(_1);
LA:
L4:

    //     if start_time > now then
    if (binary_op_a(LESSEQ, _start_time, _now))
        goto LC;

    // 	ts_found = FALSE
    _ts_found = 0;

    // 	p = ts_first
    _p = _16ts_first;

    // 	while p != 0 do
LD:
    if (_p == 0)
        goto LE;

    // 	    tp = tcb[p]
    DeRef(_tp);
    _2 = (int)SEQ_PTR(_16tcb);
    _tp = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_tp);

    // 	    if tp[TASK_RUNS_LEFT] > 0 then
    DeRef(_4520);
    _2 = (int)SEQ_PTR(_tp);
    _4520 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4520);
    if (binary_op_a(LESSEQ, _4520, 0))
        goto LF;

    // 		  earliest_task = p
    _earliest_task = _p;

    // 		  ts_found = TRUE
    _ts_found = 1;

    // 		  exit
    goto LE;
LF:

    // 	    p = tp[TASK_NEXT]
    _2 = (int)SEQ_PTR(_tp);
    _p = (int)*(((s1_ptr)_2)->base + 12);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	end while
    goto LD;
LE:

    // 	if not ts_found then
    if (_ts_found != 0)
        goto L10;

    // 	    p = ts_first
    _p = _16ts_first;

    // 	    while p != 0 do
L11:
    if (_p == 0)
        goto L12;

    // 		tp = tcb[p]
    DeRef(_tp);
    _2 = (int)SEQ_PTR(_16tcb);
    _tp = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_tp);

    // 		earliest_task = p
    _earliest_task = _p;

    // 		tcb[p][TASK_RUNS_LEFT] = tp[TASK_RUNS_MAX]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_4494);
    _2 = (int)SEQ_PTR(_tp);
    _4494 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4494);
    Ref(_4494);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _4494;
    DeRef(_1);

    // 		p = tp[TASK_NEXT]
    _2 = (int)SEQ_PTR(_tp);
    _p = (int)*(((s1_ptr)_2)->base + 12);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	    end while
    goto L11;
L12:
L10:

    // 	if earliest_task = 0 then
    if (_earliest_task != 0)
        goto L13;

    // 	    abort(0)
    UserCleanup(0);
L13:

    // 	if tcb[earliest_task][TASK_TYPE] = T_REAL_TIME then
    DeRef(_4494);
    _2 = (int)SEQ_PTR(_16tcb);
    _4494 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4494);
    _0 = _4494;
    _2 = (int)SEQ_PTR(_4494);
    _4494 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4494);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4494, 1))
        goto L14;

    // 	    wait(start_time - now)
    DeRef(_4494);
    if (IS_ATOM_INT(_start_time) && IS_ATOM_INT(_now)) {
        _4494 = _start_time - _now;
        if ((long)((unsigned long)_4494 +(unsigned long) HIGH_BITS) >= 0)
            _4494 = NewDouble((double)_4494);
    }
    else {
        if (IS_ATOM_INT(_start_time)) {
            _4494 = NewDouble((double)_start_time - DBL_PTR(_now)->dbl);
        }
        else {
            if (IS_ATOM_INT(_now)) {
                _4494 = NewDouble(DBL_PTR(_start_time)->dbl - (double)_now);
            }
            else
                _4494 = NewDouble(DBL_PTR(_start_time)->dbl - DBL_PTR(_now)->dbl);
        }
    }
    Ref(_4494);
    _16wait(_4494);
L14:
LC:

    //     tcb[earliest_task][TASK_START] = time()
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_earliest_task + ((s1_ptr)_2)->base);
    DeRef(_4520);
    _4520 = NewDouble(current_time());
    RefDS(_4520);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _4520;
    DeRef(_1);

    //     if earliest_task = current_task then
    if (_earliest_task != _16current_task)
        goto L15;

    // 	pc += 1  -- continue with current task
    _16pc = _16pc + 1;
    goto L16;
L15:

    // 	tcb[current_task][TASK_CODE] = Code
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    RefDS(_4Code);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = _4Code;
    DeRef(_1);

    // 	tcb[current_task][TASK_PC] = pc
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _16pc;
    DeRef(_1);

    // 	tcb[current_task][TASK_STACK] = call_stack
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    RefDS(_16call_stack);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = _16call_stack;
    DeRef(_1);

    // 	Code = tcb[earliest_task][TASK_CODE]
    DeRef(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4493);
    DeRefDS(_4Code);
    _2 = (int)SEQ_PTR(_4493);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    // 	pc = tcb[earliest_task][TASK_PC]
    DeRefDS(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4493);
    _2 = (int)SEQ_PTR(_4493);
    _16pc = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // 	call_stack = tcb[earliest_task][TASK_STACK]
    DeRefDS(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _earliest_task);
    RefDS(_4493);
    DeRefDS(_16call_stack);
    _2 = (int)SEQ_PTR(_4493);
    _16call_stack = (int)*(((s1_ptr)_2)->base + 16);
    Ref(_16call_stack);

    // 	current_task = earliest_task
    _16current_task = _earliest_task;

    // 	if tcb[current_task][TASK_PC] = 0 then
    DeRefDS(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4493);
    _0 = _4493;
    _2 = (int)SEQ_PTR(_4493);
    _4493 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_4493);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4493, 0))
        goto L17;

    // 	    pc = 1
    _16pc = 1;

    // 	    val[t_id] = tcb[current_task][TASK_RID]
    DeRef(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4493);
    _0 = _4493;
    _2 = (int)SEQ_PTR(_4493);
    _4493 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4493);
    DeRefDS(_0);
    Ref(_4493);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16t_id);
    _1 = *(int *)_2;
    *(int *)_2 = _4493;
    DeRef(_1);

    // 	    val[t_arglist] = tcb[current_task][TASK_ARGS]
    DeRef(_4493);
    _2 = (int)SEQ_PTR(_16tcb);
    _4493 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4493);
    _0 = _4493;
    _2 = (int)SEQ_PTR(_4493);
    _4493 = (int)*(((s1_ptr)_2)->base + 13);
    Ref(_4493);
    DeRefDS(_0);
    Ref(_4493);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16t_arglist);
    _1 = *(int *)_2;
    *(int *)_2 = _4493;
    DeRef(_1);

    // 	    Code = {CALL_PROC, t_id, t_arglist}
    _0 = _4Code;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 138;
    *((int *)(_2+8)) = _16t_id;
    *((int *)(_2+12)) = _16t_arglist;
    _4Code = MAKE_SEQ(_1);
    DeRefDS(_0);
    goto L18;
L17:

    // 	    pc += 1
    _16pc = _16pc + 1;

    // 	    restore_privates(call_stack[$])
    DeRef(_4493);
    _4493 = SEQ_PTR(_16call_stack)->length;
    _2 = (int)SEQ_PTR(_16call_stack);
    _4493 = (int)*(((s1_ptr)_2)->base + _4493);
    Ref(_4493);
    Ref(_4493);
    _16restore_privates(_4493);
L18:
L16:

    // end procedure
    DeRef(_earliest_time);
    DeRef(_start_time);
    DeRef(_now);
    DeRef(_tp);
    DeRef(_4493);
    DeRef(_4520);
    DeRef(_4494);
    return 0;
    ;
}


