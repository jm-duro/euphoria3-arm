// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _12seek(int _fn, int _pos)
{
    int _1470 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     return machine_func(M_SEEK, {fn, pos})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _fn;
    ((int *)_2)[2] = _pos;
    Ref(_pos);
    _1470 = MAKE_SEQ(_1);
    _0 = _1470;
    _1470 = machine(19, _1470);
    DeRefDS(_0);
    DeRef(_pos);
    return _1470;
    ;
}


int _12where(int _fn)
{
    int _1472 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     return machine_func(M_WHERE, fn)
    _1472 = machine(20, _fn);
    return _1472;
    ;
}


int _12flush(int _fn)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     machine_proc(M_FLUSH, fn)
    machine(60, _fn);

    // end procedure
    return 0;
    ;
}


int _12lock_file(int _fn, int _t, int _r)
{
    int _1485 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }

    //     return machine_func(M_LOCK_FILE, {fn, t, r})
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _fn;
    *((int *)(_2+8)) = _t;
    RefDS(_r);
    *((int *)(_2+12)) = _r;
    _1485 = MAKE_SEQ(_1);
    _0 = _1485;
    _1485 = machine(61, _1485);
    DeRefDS(_0);
    DeRefDS(_r);
    return _1485;
    ;
}


int _12unlock_file(int _fn, int _r)
{
    int _1487 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_fn)) {
        _1 = (long)(DBL_PTR(_fn)->dbl);
        DeRefDS(_fn);
        _fn = _1;
    }

    //     machine_proc(M_UNLOCK_FILE, {fn, r})
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _fn;
    ((int *)_2)[2] = _r;
    RefDS(_r);
    _1487 = MAKE_SEQ(_1);
    machine(62, _1487);

    // end procedure
    DeRefDS(_r);
    DeRefDS(_1487);
    return 0;
    ;
}


int _12dir(int _name)
{
    int _1488 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_DIR, name)
    _1488 = machine(22, _name);
    DeRefDS(_name);
    return _1488;
    ;
}


int _12current_dir()
{
    int _1489 = 0;
    int _0, _1, _2;
    

    //     return machine_func(M_CURRENT_DIR, 0)
    _1489 = machine(23, 0);
    return _1489;
    ;
}


int _12chdir(int _newdir)
{
    int _1490;
    int _0, _1, _2;
    

    //     return machine_func(M_CHDIR, newdir)
    _1490 = machine(63, _newdir);
    DeRefDS(_newdir);
    return _1490;
    ;
}


int _12allow_break(int _b)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     machine_proc(M_ALLOW_BREAK, b)
    machine(42, _b);

    // end procedure
    return 0;
    ;
}


int _12check_break()
{
    int _1491;
    int _0, _1, _2;
    

    //     return machine_func(M_CHECK_BREAK, 0)
    _1491 = machine(43, 0);
    return _1491;
    ;
}


int _12default_dir(int _path)
{
    int _d = 0;
    int _1492 = 0;
    int _0, _1, _2;
    

    //     d = dir(path)
    RefDS(_path);
    _d = _12dir(_path);

    //     if atom(d) then
    _1492 = IS_ATOM(_d);
    if (_1492 == 0)
        goto L1;

    // 	return d
    DeRefDS(_path);
    return _d;
    goto L2;
L1:

    // 	return sort(d)
    Ref(_d);
    _0 = _1492;
    _1492 = _13sort(_d);
    DeRef(_0);
    DeRefDS(_path);
    DeRef(_d);
    return _1492;
L2:
    ;
}


int _12walk_dir(int _path_name, int _your_function, int _scan_subdirs)
{
    int _d = 0;
    int _abort_now = 0;
    int _1504 = 0;
    int _1531;
    int _1496 = 0;
    int _1506 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_your_function)) {
        _1 = (long)(DBL_PTR(_your_function)->dbl);
        DeRefDS(_your_function);
        _your_function = _1;
    }
    if (!IS_ATOM_INT(_scan_subdirs)) {
        _1 = (long)(DBL_PTR(_scan_subdirs)->dbl);
        DeRefDS(_scan_subdirs);
        _scan_subdirs = _1;
    }

    //     if my_dir = DEFAULT then

    // 	d = default_dir(path_name)
    RefDS(_path_name);
    _d = _12default_dir(_path_name);
    goto L1;
L2:

    // 	d = call_func(my_dir, {path_name})
    _0 = _1496;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_path_name);
    *((int *)(_2+4)) = _path_name;
    _1496 = MAKE_SEQ(_1);
    DeRef(_0);
    _1 = (int)SEQ_PTR(_1496);
    _2 = (int)((s1_ptr)_1)->base;
    _0 = (int)_00[-2].addr;
    Ref(*(int *)(_2+4));
    _1 = (*(int (*)())_0)(
                        *(int *)(_2+4)
                         );
    DeRef(_d);
    _d = _1;
L1:

    //     if atom(d) then
    DeRef(_1496);
    _1496 = IS_ATOM(_d);
    if (_1496 == 0)
        goto L3;

    // 	return W_BAD_PATH
    DeRefDS(_path_name);
    DeRef(_d);
    DeRef(_abort_now);
    DeRef(_1504);
    DeRef(_1506);
    return -1;
L3:

    //     while length(path_name) > 0 and 
L4:
    DeRef(_1496);
    _1496 = SEQ_PTR(_path_name)->length;
    _1496 = (_1496 > 0);
    if (_1496 == 0) {
        goto L5;
    }
    DeRef(_1504);
    _1504 = SEQ_PTR(_path_name)->length;
    _2 = (int)SEQ_PTR(_path_name);
    _1504 = (int)*(((s1_ptr)_2)->base + _1504);
    Ref(_1504);
    DeRef(_1506);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 32;
    ((int *)_2)[2] = _12SLASH;
    _1506 = MAKE_SEQ(_1);
    _0 = _1506;
    _1506 = find(_1504, _1506);
    DeRefDSi(_0);
L6:
    if (_1506 == 0)
        goto L5;

    // 	path_name = path_name[1..$-1]
    DeRef(_1506);
    _1506 = SEQ_PTR(_path_name)->length;
    _1506 = _1506 - 1;
    rhs_slice_target = (object_ptr)&_path_name;
    RHS_Slice((s1_ptr)_path_name, 1, _1506);

    //     end while
    goto L4;
L5:

    //     for i = 1 to length(d) do
    DeRef(_1506);
    _1506 = SEQ_PTR(_d)->length;
    { int _i;
        _i = 1;
L7:
        if (_i > _1506)
            goto L8;

        // 	if find('d', d[i][D_ATTRIBUTES]) then
        DeRef(_1504);
        _2 = (int)SEQ_PTR(_d);
        _1504 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1504);
        _0 = _1504;
        _2 = (int)SEQ_PTR(_1504);
        _1504 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_1504);
        DeRef(_0);
        _0 = _1504;
        _1504 = find(100, _1504);
        DeRef(_0);
        if (_1504 == 0)
            goto L9;

        // 	    if not find(d[i][D_NAME], {".", ".."}) then
        _2 = (int)SEQ_PTR(_d);
        _1504 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1504);
        _0 = _1504;
        _2 = (int)SEQ_PTR(_1504);
        _1504 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_1504);
        DeRef(_0);
        DeRef(_1496);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _1517;
        RefDS(_1517);
        ((int *)_2)[2] = _1518;
        RefDS(_1518);
        _1496 = MAKE_SEQ(_1);
        _0 = _1496;
        _1496 = find(_1504, _1496);
        DeRefDS(_0);
        if (_1496 != 0)
            goto LA;

        // 		abort_now = call_func(your_function, {path_name, d[i]})
        _2 = (int)SEQ_PTR(_d);
        _1496 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1496);
        _0 = _1496;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _path_name;
        RefDS(_path_name);
        ((int *)_2)[2] = _1496;
        Ref(_1496);
        _1496 = MAKE_SEQ(_1);
        DeRef(_0);
        _1 = (int)SEQ_PTR(_1496);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_your_function].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_abort_now);
        _abort_now = _1;

        // 		if not equal(abort_now, 0) then
        DeRefDS(_1496);
        if (_abort_now == 0)
            _1496 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _1496 = 0;
        else
            _1496 = (compare(_abort_now, 0) == 0);
        if (_1496 != 0)
            goto LB;

        // 		    return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1504);
        DeRef(_1506);
        return _abort_now;
LB:

        // 		if scan_subdirs then
        if (_scan_subdirs == 0)
            goto LA;

        // 		    abort_now = walk_dir(path_name & SLASH & d[i][D_NAME],
        DeRef(_1496);
        _2 = (int)SEQ_PTR(_d);
        _1496 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1496);
        _0 = _1496;
        _2 = (int)SEQ_PTR(_1496);
        _1496 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_1496);
        DeRef(_0);
        {
            int concat_list[3];

            concat_list[0] = _1496;
            concat_list[1] = _12SLASH;
            concat_list[2] = _path_name;
            Concat_N((object_ptr)&_1496, concat_list, 3);
        }
        DeRef(_1504);
        _1504 = _your_function;
        _1531 = _scan_subdirs;
        RefDS(_1496);
        _0 = _abort_now;
        _abort_now = _12walk_dir(_1496, _1504, _1531);
        DeRef(_0);

        // 		    if not equal(abort_now, 0) and 
        if (_abort_now == 0)
            _1531 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _1531 = 0;
        else
            _1531 = (compare(_abort_now, 0) == 0);
        _1531 = (_1531 == 0);
        if (_1531 == 0) {
            goto LA;
        }
        if (_abort_now == -1)
            _1504 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(-1))
            _1504 = 0;
        else
            _1504 = (compare(_abort_now, -1) == 0);
        _1504 = (_1504 == 0);
LC:
        if (_1504 == 0)
            goto LA;

        // 			return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1504);
        DeRef(_1496);
        DeRef(_1506);
        return _abort_now;
LD:
LE:
LF:
        goto LA;
L9:

        // 	    abort_now = call_func(your_function, {path_name, d[i]})
        DeRef(_1504);
        _2 = (int)SEQ_PTR(_d);
        _1504 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_1504);
        _0 = _1504;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _path_name;
        RefDS(_path_name);
        ((int *)_2)[2] = _1504;
        Ref(_1504);
        _1504 = MAKE_SEQ(_1);
        DeRef(_0);
        _1 = (int)SEQ_PTR(_1504);
        _2 = (int)((s1_ptr)_1)->base;
        _0 = (int)_00[_your_function].addr;
        Ref(*(int *)(_2+4));
        Ref(*(int *)(_2+8));
        _1 = (*(int (*)())_0)(
                            *(int *)(_2+4), 
                            *(int *)(_2+8)
                             );
        DeRef(_abort_now);
        _abort_now = _1;

        // 	    if not equal(abort_now, 0) then
        DeRefDS(_1504);
        if (_abort_now == 0)
            _1504 = 1;
        else if (IS_ATOM_INT(_abort_now) && IS_ATOM_INT(0))
            _1504 = 0;
        else
            _1504 = (compare(_abort_now, 0) == 0);
        if (_1504 != 0)
            goto L10;

        // 		return abort_now
        DeRefDS(_path_name);
        DeRef(_d);
        DeRef(_1496);
        DeRef(_1506);
        return _abort_now;
L10:
LA:

        //     end for
        _i = _i + 1;
        goto L7;
L8:
        ;
    }

    //     return 0
    DeRefDS(_path_name);
    DeRef(_d);
    DeRef(_abort_now);
    DeRef(_1504);
    DeRef(_1496);
    DeRef(_1506);
    return 0;
    ;
}


