// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16delete_files(int _doit)
{
    int _3950 = 0;
    int _3946;
    int _0, _1, _2;
    

    //     if not keep then
    if (_16keep != 0)
        goto L1;

    // 	for i = 1 to length(files_to_delete) do
    _3946 = SEQ_PTR(_16files_to_delete)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _3946)
            goto L3;

        // 	    if ELINUX then
        if (_4ELINUX == 0)
            goto L4;

        // 		puts(doit, "rm ")
        EPuts(_doit, _3948);
        goto L5;
L4:

        // 		puts(doit, "del ")
        EPuts(_doit, _3949);
L5:

        // 	    puts(doit, files_to_delete[i] & '\n')
        DeRef(_3950);
        _2 = (int)SEQ_PTR(_16files_to_delete);
        _3950 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3950);
        Append(&_3950, _3950, 10);
        EPuts(_doit, _3950);

        // 	end for 
        _i = _i + 1;
        goto L2;
L3:
        ;
    }
L1:

    // end procedure
    DeRef(_3950);
    return 0;
    ;
}


int _16NewBB(int _a_call, int _mask, int _sub)
{
    int _s;
    int _3953 = 0;
    int _3963 = 0;
    int _3959 = 0;
    int _3952;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_a_call)) {
        _1 = (long)(DBL_PTR(_a_call)->dbl);
        DeRefDS(_a_call);
        _a_call = _1;
    }
    if (!IS_ATOM_INT(_mask)) {
        _1 = (long)(DBL_PTR(_mask)->dbl);
        DeRefDS(_mask);
        _mask = _1;
    }
    if (!IS_ATOM_INT(_sub)) {
        _1 = (long)(DBL_PTR(_sub)->dbl);
        DeRefDS(_sub);
        _sub = _1;
    }

    //     if a_call then
    if (_a_call == 0)
        goto L1;

    // 	for i = 1 to length(BB_info) do
    _3952 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _3952)
            goto L3;

        // 	    s = BB_info[i][BB_VAR]
        DeRef(_3953);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3953 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3953);
        _2 = (int)SEQ_PTR(_3953);
        _s = (int)*(((s1_ptr)_2)->base + 1);
        if (!IS_ATOM_INT(_s))
            _s = (long)DBL_PTR(_s)->dbl;

        // 	    if SymTab[s][S_MODE] = M_NORMAL and
        DeRefDS(_3953);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3953 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_3953);
        _0 = _3953;
        _2 = (int)SEQ_PTR(_3953);
        _3953 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_3953);
        DeRefDS(_0);
        _0 = _3953;
        if (IS_ATOM_INT(_3953)) {
            _3953 = (_3953 == 1);
        }
        else {
            _3953 = binary_op(EQUALS, _3953, 1);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_3953)) {
            if (_3953 == 0) {
                goto L4;
            }
        }
        else {
            if (DBL_PTR(_3953)->dbl == 0.0) {
                goto L4;
            }
        }
        DeRef(_3959);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3959 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_3959);
        _0 = _3959;
        _2 = (int)SEQ_PTR(_3959);
        _3959 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_3959);
        DeRefDS(_0);
        _0 = _3959;
        if (IS_ATOM_INT(_3959)) {
            _3959 = (_3959 == 6);
        }
        else {
            _3959 = binary_op(EQUALS, _3959, 6);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_3959)) {
            if (_3959 != 0) {
                DeRef(_3959);
                _3959 = 1;
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_3959)->dbl != 0.0) {
                DeRef(_3959);
                _3959 = 1;
                goto L5;
            }
        }
        DeRef(_3963);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3963 = (int)*(((s1_ptr)_2)->base + _s);
        RefDS(_3963);
        _0 = _3963;
        _2 = (int)SEQ_PTR(_3963);
        _3963 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_3963);
        DeRefDS(_0);
        _0 = _3963;
        if (IS_ATOM_INT(_3963)) {
            _3963 = (_3963 == 5);
        }
        else {
            _3963 = binary_op(EQUALS, _3963, 5);
        }
        DeRef(_0);
        DeRef(_3959);
        if (IS_ATOM_INT(_3963))
            _3959 = (_3963 != 0);
        else
            _3959 = DBL_PTR(_3963)->dbl != 0.0;
L5:
L6:
        if (_3959 == 0)
            goto L4;

        // 		  if and_bits(mask, power(2, remainder(s, E_SIZE))) then
        DeRef(_3963);
        _3963 = (_s % 29);
        _3963 = power(2, _3963);
        _0 = _3963;
        if (IS_ATOM_INT(_3963)) {
            _3963 = (_mask & _3963);
        }
        else {
            temp_d.dbl = (double)_mask;
            _3963 = Dand_bits(&temp_d, DBL_PTR(_3963));
        }
        DeRef(_0);
        if (_3963 == 0) {
            goto L7;
        }
        else {
            if (!IS_ATOM_INT(_3963) && DBL_PTR(_3963)->dbl == 0.0)
                goto L7;
        }

        // 		      if mask = E_ALL_EFFECT or s < sub then
        DeRef(_3963);
        _3963 = (_mask == 1073741823);
        if (_3963 != 0) {
            goto L8;
        }
        DeRef(_3959);
        _3959 = (_s < _sub);
L9:
        if (_3959 == 0)
            goto LA;
L8:

        // 			  BB_info[i][BB_TYPE..BB_OBJ] = 
        _2 = (int)SEQ_PTR(_16BB_info);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _16BB_info = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_3953);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = -1073741824;
        ((int *)_2)[2] = 1073741823;
        _3953 = MAKE_SEQ(_1);
        _0 = _3953;
        _1 = NewS1(4);
        _2 = (int)((s1_ptr)_1)->base;
        *((int *)(_2+4)) = 0;
        *((int *)(_2+8)) = 0;
        RefDS(_4NOVALUE);
        *((int *)(_2+12)) = _4NOVALUE;
        RefDS(_3953);
        *((int *)(_2+16)) = _3953;
        _3953 = MAKE_SEQ(_1);
        DeRefDSi(_0);
        assign_slice_seq = (s1_ptr *)_3;
        AssignSlice(2, 5, _3953);
LA:
L7:
L4:

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }
    goto LB;
L1:

    // 	BB_info = {}
    RefDS(_39);
    DeRef(_16BB_info);
    _16BB_info = _39;
LB:

    // end procedure
    DeRef(_3953);
    DeRef(_3963);
    DeRef(_3959);
    return 0;
    ;
}


int _16BB_var_obj(int _var)
{
    int _fail = 0;
    int _3982 = 0;
    int _3976 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     fail = {NOVALUE, NOVALUE}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = _4NOVALUE;
    RefDS(_4NOVALUE);
    _fail = MAKE_SEQ(_1);

    //     for i = length(BB_info) to 1 by -1 do
    _3976 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _3976;
L1:
        if (_i < 1)
            goto L2;

        // 	if BB_info[i][BB_VAR] = var and
        DeRef(_3976);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3976 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3976);
        _0 = _3976;
        _2 = (int)SEQ_PTR(_3976);
        _3976 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3976);
        DeRefDS(_0);
        _0 = _3976;
        if (IS_ATOM_INT(_3976)) {
            _3976 = (_3976 == _var);
        }
        else {
            _3976 = binary_op(EQUALS, _3976, _var);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_3976)) {
            if (_3976 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_3976)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_3982);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3982 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3982);
        _0 = _3982;
        _2 = (int)SEQ_PTR(_3982);
        _3982 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3982);
        DeRefDS(_0);
        _0 = _3982;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_3982))
            _3982 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3982)->dbl));
        else
            _3982 = (int)*(((s1_ptr)_2)->base + _3982);
        RefDS(_3982);
        DeRef(_0);
        _0 = _3982;
        _2 = (int)SEQ_PTR(_3982);
        _3982 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_3982);
        DeRefDS(_0);
        _0 = _3982;
        if (IS_ATOM_INT(_3982)) {
            _3982 = (_3982 == 1);
        }
        else {
            _3982 = binary_op(EQUALS, _3982, 1);
        }
        DeRef(_0);
L4:
        if (_3982 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_3982) && DBL_PTR(_3982)->dbl == 0.0)
                goto L3;
        }

        // 		if BB_info[i][BB_TYPE] != TYPE_INTEGER then
        DeRef(_3982);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3982 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3982);
        _0 = _3982;
        _2 = (int)SEQ_PTR(_3982);
        _3982 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3982);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _3982, 1))
            goto L5;

        // 		    return fail
        DeRef(_3982);
        DeRef(_3976);
        return _fail;
L5:

        // 		return BB_info[i][BB_OBJ]
        DeRef(_3982);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3982 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3982);
        _0 = _3982;
        _2 = (int)SEQ_PTR(_3982);
        _3982 = (int)*(((s1_ptr)_2)->base + 5);
        Ref(_3982);
        DeRefDS(_0);
        DeRef(_fail);
        DeRef(_3976);
        return _3982;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return fail
    DeRef(_3982);
    DeRef(_3976);
    return _fail;
    ;
}


int _16BB_var_type(int _var)
{
    int _3992 = 0;
    int _3997 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     for i = length(BB_info) to 1 by -1 do
    _3992 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _3992;
L1:
        if (_i < 1)
            goto L2;

        // 	if BB_info[i][BB_VAR] = var and
        DeRef(_3992);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3992);
        _0 = _3992;
        _2 = (int)SEQ_PTR(_3992);
        _3992 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3992);
        DeRefDS(_0);
        _0 = _3992;
        if (IS_ATOM_INT(_3992)) {
            _3992 = (_3992 == _var);
        }
        else {
            _3992 = binary_op(EQUALS, _3992, _var);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_3992)) {
            if (_3992 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_3992)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_3997);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3997 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3997);
        _0 = _3997;
        _2 = (int)SEQ_PTR(_3997);
        _3997 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_3997);
        DeRefDS(_0);
        _0 = _3997;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_3997))
            _3997 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_3997)->dbl));
        else
            _3997 = (int)*(((s1_ptr)_2)->base + _3997);
        RefDS(_3997);
        DeRef(_0);
        _0 = _3997;
        _2 = (int)SEQ_PTR(_3997);
        _3997 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_3997);
        DeRefDS(_0);
        _0 = _3997;
        if (IS_ATOM_INT(_3997)) {
            _3997 = (_3997 == 1);
        }
        else {
            _3997 = binary_op(EQUALS, _3997, 1);
        }
        DeRef(_0);
L4:
        if (_3997 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_3997) && DBL_PTR(_3997)->dbl == 0.0)
                goto L3;
        }

        // 	    if BB_info[i][BB_TYPE] < 0 or
        DeRef(_3997);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3997 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3997);
        _0 = _3997;
        _2 = (int)SEQ_PTR(_3997);
        _3997 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3997);
        DeRefDS(_0);
        _0 = _3997;
        if (IS_ATOM_INT(_3997)) {
            _3997 = (_3997 < 0);
        }
        else {
            _3997 = binary_op(LESS, _3997, 0);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_3997)) {
            if (_3997 != 0) {
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_3997)->dbl != 0.0) {
                goto L5;
            }
        }
        DeRef(_3992);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3992);
        _0 = _3992;
        _2 = (int)SEQ_PTR(_3992);
        _3992 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3992);
        DeRefDS(_0);
        _0 = _3992;
        if (IS_ATOM_INT(_3992)) {
            _3992 = (_3992 > 16);
        }
        else {
            _3992 = binary_op(GREATER, _3992, 16);
        }
        DeRef(_0);
L6:
        if (_3992 == 0) {
            goto L7;
        }
        else {
            if (!IS_ATOM_INT(_3992) && DBL_PTR(_3992)->dbl == 0.0)
                goto L7;
        }
L5:

        // 		InternalErr("Bad BB_var_type")
        RefDS(_4009);
        _6InternalErr(_4009);
L7:

        // 	    if BB_info[i][BB_TYPE] = TYPE_NULL then  -- var has only been read
        DeRef(_3992);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3992);
        _0 = _3992;
        _2 = (int)SEQ_PTR(_3992);
        _3992 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3992);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _3992, 0))
            goto L8;

        // 		return TYPE_OBJECT
        DeRef(_3992);
        DeRef(_3997);
        return 16;
        goto L9;
L8:

        // 		return BB_info[i][BB_TYPE]
        DeRef(_3992);
        _2 = (int)SEQ_PTR(_16BB_info);
        _3992 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_3992);
        _0 = _3992;
        _2 = (int)SEQ_PTR(_3992);
        _3992 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_3992);
        DeRefDS(_0);
        DeRef(_3997);
        return _3992;
L9:
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return TYPE_OBJECT
    DeRef(_3992);
    DeRef(_3997);
    return 16;
    ;
}


int _16GType(int _s)
{
    int _t;
    int _local_t;
    int _4019 = 0;
    int _4015 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     t = SymTab[s][S_GTYPE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4015 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4015);
    _2 = (int)SEQ_PTR(_4015);
    _t = (int)*(((s1_ptr)_2)->base + 26);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     if t < 0 or t > TYPE_OBJECT then
    DeRefDS(_4015);
    _4015 = (_t < 0);
    if (_4015 != 0) {
        goto L1;
    }
    _4019 = (_t > 16);
L2:
    if (_4019 == 0)
        goto L3;
L1:

    // 	InternalErr("Bad GType")
    RefDS(_4020);
    _6InternalErr(_4020);
L3:

    //     if SymTab[s][S_MODE] != M_NORMAL then
    DeRef(_4019);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4019 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4019);
    _0 = _4019;
    _2 = (int)SEQ_PTR(_4019);
    _4019 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4019);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4019, 1))
        goto L4;

    // 	return t
    DeRef(_4019);
    DeRef(_4015);
    return _t;
L4:

    //     local_t = BB_var_type(s)
    _local_t = _16BB_var_type(_s);
    if (!IS_ATOM_INT(_local_t)) {
        _1 = (long)(DBL_PTR(_local_t)->dbl);
        DeRefDS(_local_t);
        _local_t = _1;
    }

    //     if local_t = TYPE_OBJECT then
    if (_local_t != 16)
        goto L5;

    // 	return t
    DeRef(_4019);
    DeRef(_4015);
    return _t;
L5:

    //     if t = TYPE_INTEGER then
    if (_t != 1)
        goto L6;

    // 	return TYPE_INTEGER
    DeRef(_4019);
    DeRef(_4015);
    return 1;
L6:

    //     return local_t
    DeRef(_4019);
    DeRef(_4015);
    return _local_t;
    ;
}


int _16ObjValue(int _s)
{
    int _t = 0;
    int _local_t = 0;
    int _4044 = 0;
    int _4029 = 0;
    int _4027 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     t = {SymTab[s][S_OBJ_MIN], SymTab[s][S_OBJ_MAX]}
    _2 = (int)SEQ_PTR(_4SymTab);
    _4027 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4027);
    _0 = _4027;
    _2 = (int)SEQ_PTR(_4027);
    _4027 = (int)*(((s1_ptr)_2)->base + 27);
    Ref(_4027);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4029 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4029);
    _0 = _4029;
    _2 = (int)SEQ_PTR(_4029);
    _4029 = (int)*(((s1_ptr)_2)->base + 28);
    Ref(_4029);
    DeRefDS(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4027;
    Ref(_4027);
    ((int *)_2)[2] = _4029;
    Ref(_4029);
    _t = MAKE_SEQ(_1);

    //     if t[MIN] != t[MAX] then
    DeRef(_4029);
    _2 = (int)SEQ_PTR(_t);
    _4029 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4029);
    DeRef(_4027);
    _2 = (int)SEQ_PTR(_t);
    _4027 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4027);
    if (binary_op_a(EQUALS, _4029, _4027))
        goto L1;

    // 	t[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_t);
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L1:

    //     if SymTab[s][S_MODE] != M_NORMAL then
    DeRef(_4027);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4027 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4027);
    _0 = _4027;
    _2 = (int)SEQ_PTR(_4027);
    _4027 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4027);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4027, 1))
        goto L2;

    // 	return t[MIN]
    DeRef(_4027);
    _2 = (int)SEQ_PTR(_t);
    _4027 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4027);
    DeRefDS(_t);
    DeRef(_local_t);
    DeRef(_4044);
    DeRef(_4029);
    return _4027;
L2:

    //     local_t = BB_var_obj(s)
    _0 = _local_t;
    _local_t = _16BB_var_obj(_s);
    DeRef(_0);

    //     if local_t[MIN] = NOVALUE or 
    DeRef(_4027);
    _2 = (int)SEQ_PTR(_local_t);
    _4027 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4027);
    _0 = _4027;
    _4027 = binary_op(EQUALS, _4027, _4NOVALUE);
    DeRef(_0);
    if (IS_ATOM_INT(_4027)) {
        if (_4027 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4027)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_4029);
    _2 = (int)SEQ_PTR(_local_t);
    _4029 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4029);
    DeRef(_4044);
    _2 = (int)SEQ_PTR(_local_t);
    _4044 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4044);
    _0 = _4044;
    if (IS_ATOM_INT(_4029) && IS_ATOM_INT(_4044)) {
        _4044 = (_4029 != _4044);
    }
    else {
        _4044 = binary_op(NOTEQ, _4029, _4044);
    }
    DeRef(_0);
L4:
    if (_4044 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_4044) && DBL_PTR(_4044)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	return t[MIN]
    DeRef(_4044);
    _2 = (int)SEQ_PTR(_t);
    _4044 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4044);
    DeRefDS(_t);
    DeRef(_local_t);
    DeRef(_4029);
    DeRef(_4027);
    return _4044;
    goto L6;
L5:

    // 	return local_t[MIN]
    DeRef(_4044);
    _2 = (int)SEQ_PTR(_local_t);
    _4044 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4044);
    DeRef(_t);
    DeRefDS(_local_t);
    DeRef(_4029);
    DeRef(_4027);
    return _4044;
L6:
    ;
}


int _16TypeIs(int _x, int _types)
{
    int _4048 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     if atom(types) then
    _4048 = IS_ATOM(_types);
    if (_4048 == 0)
        goto L1;

    // 	return GType(x) = types
    _4048 = _16GType(_x);
    if (IS_ATOM_INT(_types)) {
        _4048 = (_4048 == _types);
    }
    else {
        _4048 = binary_op(EQUALS, _4048, _types);
    }
    DeRef(_types);
    return _4048;
    goto L2;
L1:

    // 	return find(GType(x), types)
    _0 = _4048;
    _4048 = _16GType(_x);
    DeRef(_0);
    _4048 = find(_4048, _types);
    DeRef(_types);
    return _4048;
L2:
    ;
}


int _16TypeIsNot(int _x, int _types)
{
    int _4053 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     if atom(types) then
    _4053 = IS_ATOM(_types);
    if (_4053 == 0)
        goto L1;

    // 	return GType(x) != types
    _4053 = _16GType(_x);
    if (IS_ATOM_INT(_types)) {
        _4053 = (_4053 != _types);
    }
    else {
        _4053 = binary_op(NOTEQ, _4053, _types);
    }
    DeRef(_types);
    return _4053;
    goto L2;
L1:

    // 	return not find(GType(x), types)
    _0 = _4053;
    _4053 = _16GType(_x);
    DeRef(_0);
    _4053 = find(_4053, _types);
    _4053 = (_4053 == 0);
    DeRef(_types);
    return _4053;
L2:
    ;
}


int _16or_type(int _t1, int _t2)
{
    int _4063 = 0;
    int _4059;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_t1)) {
        _1 = (long)(DBL_PTR(_t1)->dbl);
        DeRefDS(_t1);
        _t1 = _1;
    }
    if (!IS_ATOM_INT(_t2)) {
        _1 = (long)(DBL_PTR(_t2)->dbl);
        DeRefDS(_t2);
        _t2 = _1;
    }

    //     if t1 = TYPE_NULL then
    if (_t1 != 0)
        goto L1;

    // 	return t2
    return _t2;
    goto L2;
L1:

    //     elsif t2 = TYPE_NULL then
    if (_t2 != 0)
        goto L3;

    // 	return t1
    DeRef(_4063);
    return _t1;
    goto L2;
L3:

    //     elsif t1 = TYPE_OBJECT or t2 = TYPE_OBJECT then
    _4059 = (_t1 == 16);
    if (_4059 != 0) {
        goto L4;
    }
    DeRef(_4063);
    _4063 = (_t2 == 16);
L5:
    if (_4063 == 0)
        goto L6;
L4:

    // 	return TYPE_OBJECT
    DeRef(_4063);
    return 16;
    goto L2;
L6:

    //     elsif t1 = TYPE_SEQUENCE then
    if (_t1 != 8)
        goto L7;

    // 	if t2 = TYPE_SEQUENCE then
    if (_t2 != 8)
        goto L8;

    // 	    return TYPE_SEQUENCE
    DeRef(_4063);
    return 8;
    goto L2;
L8:

    // 	    return TYPE_OBJECT
    DeRef(_4063);
    return 16;
L9:
    goto L2;
L7:

    //     elsif t2 = TYPE_SEQUENCE then
    if (_t2 != 8)
        goto LA;

    // 	if t1 = TYPE_SEQUENCE then
    if (_t1 != 8)
        goto LB;

    // 	    return TYPE_SEQUENCE
    DeRef(_4063);
    return 8;
    goto L2;
LB:

    // 	    return TYPE_OBJECT
    DeRef(_4063);
    return 16;
LC:
    goto L2;
LA:

    //     elsif t1 = TYPE_ATOM or t2 = TYPE_ATOM then
    DeRef(_4063);
    _4063 = (_t1 == 4);
    if (_4063 != 0) {
        goto LD;
    }
    _4059 = (_t2 == 4);
LE:
    if (_4059 == 0)
        goto LF;
LD:

    // 	return TYPE_ATOM   
    DeRef(_4063);
    return 4;
    goto L2;
LF:

    //     elsif t1 = TYPE_DOUBLE then
    if (_t1 != 2)
        goto L10;

    // 	if t2 = TYPE_INTEGER then
    if (_t2 != 1)
        goto L11;

    // 	    return TYPE_ATOM
    DeRef(_4063);
    return 4;
    goto L2;
L11:

    // 	    return TYPE_DOUBLE
    DeRef(_4063);
    return 2;
L12:
    goto L2;
L10:

    //     elsif t2 = TYPE_DOUBLE then
    if (_t2 != 2)
        goto L13;

    // 	if t1 = TYPE_INTEGER then
    if (_t1 != 1)
        goto L14;

    // 	    return TYPE_ATOM
    DeRef(_4063);
    return 4;
    goto L2;
L14:

    // 	    return TYPE_DOUBLE
    DeRef(_4063);
    return 2;
L15:
    goto L2;
L13:

    //     elsif t1 = TYPE_INTEGER and t2 = TYPE_INTEGER then
    _4059 = (_t1 == 1);
    if (_4059 == 0) {
        goto L16;
    }
    DeRef(_4063);
    _4063 = (_t2 == 1);
L17:
    if (_4063 == 0)
        goto L16;

    // 	return TYPE_INTEGER
    DeRef(_4063);
    return 1;
    goto L2;
L16:

    // 	InternalErr(sprintf("or_type: t1 is %d, t2 is %d\n", {t1, t2}))
    DeRef(_4063);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _t1;
    ((int *)_2)[2] = _t2;
    _4063 = MAKE_SEQ(_1);
    _0 = _4063;
    _4063 = EPrintf(-9999999, _4078, _4063);
    DeRefDSi(_0);
    RefDS(_4063);
    _6InternalErr(_4063);
L2:
    ;
}


int _16SetBBType(int _s, int _t, int _val, int _etype)
{
    int _found;
    int _i;
    int _tn;
    int _4089 = 0;
    int _4102 = 0;
    int _4081 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }
    if (!IS_ATOM_INT(_etype)) {
        _1 = (long)(DBL_PTR(_etype)->dbl);
        DeRefDS(_etype);
        _etype = _1;
    }

    //     if find(SymTab[s][S_MODE], {M_TEMP, M_NORMAL}) then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4081);
    DeRefDS(_0);
    _0 = _4081;
    _4081 = find(_4081, _4083);
    DeRef(_0);
    if (_4081 == 0)
        goto L1;

    // 	found = FALSE
    _found = 0;

    // 	if SymTab[s][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4081);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4081, 3))
        goto L2;

    // 	    SymTab[s][S_GTYPE] = t
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
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = _t;
    DeRef(_1);

    // 	    SymTab[s][S_SEQ_ELEM] = etype
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
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = _etype;
    DeRef(_1);

    // 	    if find(SymTab[s][S_GTYPE], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4081);
    DeRefDS(_0);
    _0 = _4081;
    _4081 = find(_4081, _4094);
    DeRef(_0);
    if (_4081 == 0)
        goto L3;

    // 		if val[MIN] < 0 then
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    if (binary_op_a(GREATEREQ, _4081, 0))
        goto L4;

    // 		    SymTab[s][S_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L5;
L4:

    // 		    SymTab[s][S_SEQ_LEN] = val[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    Ref(_4102);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRef(_1);
L5:

    // 		SymTab[s][S_OBJ] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L6;
L3:

    // 		SymTab[s][S_OBJ_MIN] = val[MIN] 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    Ref(_4089);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);

    // 		SymTab[s][S_OBJ_MAX] = val[MAX] 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4081);
    Ref(_4081);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);

    // 		SymTab[s][S_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L6:

    // 	    if not Initializing then
    if (_4Initializing != 0)
        goto L7;

    // 		temp_name_type[SymTab[s][S_TEMP_NAME]][T_GTYPE_NEW] =
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4102 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_4102);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_4temp_name_type);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4temp_name_type = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_4102))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4102)->dbl));
    else
        _3 = (int)(_4102 + ((s1_ptr)_2)->base);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_4089);
    DeRefDS(_0);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4temp_name_type);
    if (!IS_ATOM_INT(_4089))
        _4089 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4089)->dbl));
    else
        _4089 = (int)*(((s1_ptr)_2)->base + _4089);
    RefDS(_4089);
    DeRef(_0);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4089);
    DeRefDS(_0);
    Ref(_4089);
    _0 = _4089;
    _4089 = _16or_type(_4089, _t);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);
L7:

    // 	    tn = SymTab[s][S_TEMP_NAME]
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _2 = (int)SEQ_PTR(_4089);
    _tn = (int)*(((s1_ptr)_2)->base + 31);
    if (!IS_ATOM_INT(_tn))
        _tn = (long)DBL_PTR(_tn)->dbl;

    // 	    i = 1
    _i = 1;

    // 	    while i <= length(BB_info) do
L8:
    DeRef(_4089);
    _4089 = SEQ_PTR(_16BB_info)->length;
    if (_i > _4089)
        goto L9;

    // 		if SymTab[BB_info[i][BB_VAR]][S_MODE] = M_TEMP and
    _2 = (int)SEQ_PTR(_16BB_info);
    _4089 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    DeRefDS(_0);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_4089))
        _4089 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4089)->dbl));
    else
        _4089 = (int)*(((s1_ptr)_2)->base + _4089);
    RefDS(_4089);
    DeRef(_0);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4089);
    DeRefDS(_0);
    _0 = _4089;
    if (IS_ATOM_INT(_4089)) {
        _4089 = (_4089 == 3);
    }
    else {
        _4089 = binary_op(EQUALS, _4089, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4089)) {
        if (_4089 == 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_4089)->dbl == 0.0) {
            goto LA;
        }
    }
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_16BB_info);
    _4081 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    DeRefDS(_0);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_4081))
        _4081 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4081)->dbl));
    else
        _4081 = (int)*(((s1_ptr)_2)->base + _4081);
    RefDS(_4081);
    DeRef(_0);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_4081);
    DeRefDS(_0);
    _0 = _4081;
    if (IS_ATOM_INT(_4081)) {
        _4081 = (_4081 == _tn);
    }
    else {
        _4081 = binary_op(EQUALS, _4081, _tn);
    }
    DeRef(_0);
LB:
    if (_4081 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_4081) && DBL_PTR(_4081)->dbl == 0.0)
            goto LA;
    }

    // 		    found = TRUE
    _found = 1;

    // 		    exit
    goto L9;
LA:

    // 		i += 1
    _i = _i + 1;

    // 	    end while
    goto L8;
LC:
    goto L9;
L2:

    // 	    if t != TYPE_NULL then
    if (_t == 0)
        goto LD;

    // 		if not Initializing then
    if (_4Initializing != 0)
        goto LE;

    // 		    SymTab[s][S_GTYPE_NEW] = or_type(SymTab[s][S_GTYPE_NEW], t)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4102 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_4102);
    DeRefDS(_0);
    Ref(_4102);
    _0 = _4102;
    _4102 = _16or_type(_4102, _t);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 35);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRef(_1);
LE:

    // 		if t = TYPE_SEQUENCE then
    if (_t != 8)
        goto LF;

    // 		    SymTab[s][S_SEQ_ELEM_NEW] = 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_4081);
    DeRefDS(_0);
    Ref(_4081);
    _0 = _4081;
    _4081 = _16or_type(_4081, _etype);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);

    // 		    if val[MIN] != -1 then
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    if (binary_op_a(EQUALS, _4081, -1))
        goto L10;

    // 			if SymTab[s][S_SEQ_LEN_NEW] = -NOVALUE then
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_4081);
    DeRefDS(_0);
    DeRef(_4089);
    _4089 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _4081, _4089))
        goto L11;

    // 			    if val[MIN] < 0 then
    DeRefDS(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    if (binary_op_a(GREATEREQ, _4089, 0))
        goto L12;

    // 				SymTab[s][S_SEQ_LEN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L10;
L12:

    // 				SymTab[s][S_SEQ_LEN_NEW] = val[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    Ref(_4102);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRef(_1);
L13:
    goto L10;
L11:

    // 			elsif val[MIN] != SymTab[s][S_SEQ_LEN_NEW] then
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_4089);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4102, _4089))
        goto L10;

    // 			    SymTab[s][S_SEQ_LEN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L14:
L15:
L16:
    goto L10;
LF:

    // 		elsif t = TYPE_INTEGER then
    if (_t != 1)
        goto L17;

    // 		    if SymTab[s][S_OBJ_MIN_NEW] = -NOVALUE then
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4102 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4102);
    DeRefDS(_0);
    DeRef(_4089);
    _4089 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _4102, _4089))
        goto L18;

    // 			SymTab[s][S_OBJ_MIN_NEW] = val[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    Ref(_4081);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);

    // 			SymTab[s][S_OBJ_MAX_NEW] = val[MAX]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRefDS(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4089);
    Ref(_4089);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 39);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);
    goto L10;
L18:

    // 		    elsif SymTab[s][S_OBJ_MIN_NEW] != NOVALUE then
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4089);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4089, _4NOVALUE))
        goto L10;

    // 			if val[MIN] < SymTab[s][S_OBJ_MIN_NEW] then
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4102 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_4102);
    DeRefDS(_0);
    if (binary_op_a(GREATEREQ, _4089, _4102))
        goto L19;

    // 			    SymTab[s][S_OBJ_MIN_NEW] = val[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    Ref(_4081);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);
L19:

    // 			if val[MAX] > SymTab[s][S_OBJ_MAX_NEW] then
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4081);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 39);
    Ref(_4089);
    DeRefDS(_0);
    if (binary_op_a(LESSEQ, _4081, _4089))
        goto L10;

    // 			    SymTab[s][S_OBJ_MAX_NEW] = val[MAX]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4102);
    Ref(_4102);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 39);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRef(_1);
L1A:
L1B:
L1C:
    goto L10;
L17:

    // 		    SymTab[s][S_OBJ_MIN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 		    if t = TYPE_OBJECT then
    if (_t != 16)
        goto L1D;

    // 			SymTab[s][S_SEQ_ELEM_NEW] = 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4089 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4089);
    _0 = _4089;
    _2 = (int)SEQ_PTR(_4089);
    _4089 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_4089);
    DeRefDS(_0);
    Ref(_4089);
    _0 = _4089;
    _4089 = _16or_type(_4089, _etype);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);

    // 			SymTab[s][S_SEQ_LEN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L1D:
L10:
LD:

    // 	    i = 1
    _i = 1;

    // 	    while i <= length(BB_info) do
L1E:
    DeRef(_4102);
    _4102 = SEQ_PTR(_16BB_info)->length;
    if (_i > _4102)
        goto L1F;

    // 		if BB_info[i][BB_VAR] = s then
    _2 = (int)SEQ_PTR(_16BB_info);
    _4102 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4102, _s))
        goto L20;

    // 		    found = TRUE
    _found = 1;

    // 		    exit
    goto L1F;
L20:

    // 		i += 1
    _i = _i + 1;

    // 	    end while
    goto L1E;
L1F:
L9:

    // 	if not found then
    if (_found != 0)
        goto L21;

    // 	    BB_info = append(BB_info, repeat(0, 5))
    DeRef(_4102);
    _4102 = Repeat(0, 5);
    RefDS(_4102);
    Append(&_16BB_info, _16BB_info, _4102);
L21:

    // 	if t = TYPE_NULL then
    if (_t != 0)
        goto L22;

    // 	    if not found then
    if (_found != 0)
        goto L23;

    // 		BB_info[i] = {s, t, TYPE_OBJECT, NOVALUE, {MININT, MAXINT}}
    DeRef(_4102);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1073741824;
    ((int *)_2)[2] = 1073741823;
    _4102 = MAKE_SEQ(_1);
    _0 = _4102;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _s;
    *((int *)(_2+8)) = _t;
    *((int *)(_2+12)) = 16;
    RefDS(_4NOVALUE);
    *((int *)(_2+16)) = _4NOVALUE;
    RefDS(_4102);
    *((int *)(_2+20)) = _4102;
    _4102 = MAKE_SEQ(_1);
    DeRefDSi(_0);
    RefDS(_4102);
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _i);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRefDS(_1);
L24:
    goto L23;
L22:

    // 	    BB_info[i][BB_VAR] = s
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _s;
    DeRef(_1);

    // 	    BB_info[i][BB_TYPE] = t
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _t;
    DeRef(_1);

    // 	    if t = TYPE_SEQUENCE and val[MIN] = -1 then
    DeRef(_4102);
    _4102 = (_t == 8);
    if (_4102 == 0) {
        goto L25;
    }
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    _0 = _4089;
    if (IS_ATOM_INT(_4089)) {
        _4089 = (_4089 == -1);
    }
    else {
        _4089 = binary_op(EQUALS, _4089, -1);
    }
    DeRef(_0);
L26:
    if (_4089 == 0) {
        goto L25;
    }
    else {
        if (!IS_ATOM_INT(_4089) && DBL_PTR(_4089)->dbl == 0.0)
            goto L25;
    }

    // 		if found and BB_info[i][BB_ELEM] != TYPE_NULL then
    if (_found == 0) {
        goto L27;
    }
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_16BB_info);
    _4102 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4102);
    DeRefDS(_0);
    _0 = _4102;
    if (IS_ATOM_INT(_4102)) {
        _4102 = (_4102 != 0);
    }
    else {
        _4102 = binary_op(NOTEQ, _4102, 0);
    }
    DeRef(_0);
L28:
    if (_4102 == 0) {
        goto L27;
    }
    else {
        if (!IS_ATOM_INT(_4102) && DBL_PTR(_4102)->dbl == 0.0)
            goto L27;
    }

    // 		    BB_info[i][BB_ELEM] = or_type(BB_info[i][BB_ELEM], etype) 
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_16BB_info);
    _4081 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4081);
    DeRefDS(_0);
    Ref(_4081);
    _0 = _4081;
    _4081 = _16or_type(_4081, _etype);
    DeRef(_0);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);
    goto L29;
L27:

    // 		    BB_info[i][BB_ELEM] = TYPE_NULL
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L29:

    // 		if not found then
    if (_found != 0)
        goto L23;

    // 		    BB_info[i][BB_SEQLEN] = NOVALUE
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L2A:
    goto L23;
L25:

    // 		BB_info[i][BB_ELEM] = etype
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = _etype;
    DeRef(_1);

    // 		if t = TYPE_SEQUENCE or t = TYPE_OBJECT then 
    DeRef(_4089);
    _4089 = (_t == 8);
    if (_4089 != 0) {
        goto L2B;
    }
    DeRef(_4081);
    _4081 = (_t == 16);
L2C:
    if (_4081 == 0)
        goto L2D;
L2B:

    // 		    if val[MIN] < 0 then
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    if (binary_op_a(GREATEREQ, _4081, 0))
        goto L2E;

    // 			BB_info[i][BB_SEQLEN] = NOVALUE
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L23;
L2E:

    // 			BB_info[i][BB_SEQLEN] = val[MIN]
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    Ref(_4102);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = _4102;
    DeRef(_1);
L2F:
    goto L23;
L2D:

    // 		    BB_info[i][BB_OBJ] = val
    _2 = (int)SEQ_PTR(_16BB_info);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16BB_info = MAKE_SEQ(_2);
    }
    _3 = (int)(_i + ((s1_ptr)_2)->base);
    RefDS(_val);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _val;
    DeRef(_1);
L30:
L31:
L32:
    goto L23;
L1:

    //     elsif SymTab[s][S_MODE] = M_CONSTANT then
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4081);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4081, 2))
        goto L33;

    // 	SymTab[s][S_GTYPE] = t
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
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = _t;
    DeRef(_1);

    // 	SymTab[s][S_SEQ_ELEM] = etype
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
    _2 = (int)(((s1_ptr)_2)->base + 30);
    _1 = *(int *)_2;
    *(int *)_2 = _etype;
    DeRef(_1);

    // 	if SymTab[s][S_GTYPE] = TYPE_SEQUENCE or 
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4081 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4081);
    _0 = _4081;
    _2 = (int)SEQ_PTR(_4081);
    _4081 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4081);
    DeRefDS(_0);
    _0 = _4081;
    if (IS_ATOM_INT(_4081)) {
        _4081 = (_4081 == 8);
    }
    else {
        _4081 = binary_op(EQUALS, _4081, 8);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4081)) {
        if (_4081 != 0) {
            goto L34;
        }
    }
    else {
        if (DBL_PTR(_4081)->dbl != 0.0) {
            goto L34;
        }
    }
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4102 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4102);
    _0 = _4102;
    _2 = (int)SEQ_PTR(_4102);
    _4102 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_4102);
    DeRefDS(_0);
    _0 = _4102;
    if (IS_ATOM_INT(_4102)) {
        _4102 = (_4102 == 16);
    }
    else {
        _4102 = binary_op(EQUALS, _4102, 16);
    }
    DeRef(_0);
L35:
    if (_4102 == 0) {
        goto L36;
    }
    else {
        if (!IS_ATOM_INT(_4102) && DBL_PTR(_4102)->dbl == 0.0)
            goto L36;
    }
L34:

    // 	    if val[MIN] < 0 then
    DeRef(_4102);
    _2 = (int)SEQ_PTR(_val);
    _4102 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4102);
    if (binary_op_a(GREATEREQ, _4102, 0))
        goto L37;

    // 		SymTab[s][S_SEQ_LEN] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L38;
L37:

    // 		SymTab[s][S_SEQ_LEN] = val[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4089);
    Ref(_4089);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 29);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);
L39:
    goto L38;
L36:

    // 	    SymTab[s][S_OBJ_MIN] = val[MIN] 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4081);
    _2 = (int)SEQ_PTR(_val);
    _4081 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4081);
    Ref(_4081);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _4081;
    DeRef(_1);

    // 	    SymTab[s][S_OBJ_MAX] = val[MAX] 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4089);
    _2 = (int)SEQ_PTR(_val);
    _4089 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4089);
    Ref(_4089);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _4089;
    DeRef(_1);
L38:
L33:
L23:

    // end procedure
    DeRefDS(_val);
    DeRef(_4089);
    DeRef(_4102);
    DeRef(_4081);
    return 0;
    ;
}


int _16ok_name(int _name)
{
    int _4285 = 0;
    int _0, _1, _2;
    

    //     if name[1] <= 'f' then
    _2 = (int)SEQ_PTR(_name);
    _4285 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4285);
    if (binary_op_a(GREATER, _4285, 102))
        goto L1;

    // 	if    equal(name, "Bool") then
    DeRef(_4285);
    if (_name == _4287)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4287))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4287) == 0);
    if (_4285 == 0)
        goto L2;

    // 	    return "Bool97531"
    RefDS(_4289);
    DeRefDS(_name);
    return _4289;
    goto L3;
L2:

    // 	elsif equal(name, "Seg16") then
    DeRef(_4285);
    if (_name == _4290)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4290))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4290) == 0);
    if (_4285 == 0)
        goto L4;

    // 	    return "Seg1697531"
    RefDS(_4292);
    DeRefDS(_name);
    return _4292;
    goto L3;
L4:

    // 	elsif equal(name, "Packed") then
    DeRef(_4285);
    if (_name == _4293)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4293))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4293) == 0);
    if (_4285 == 0)
        goto L5;

    // 	    return "Packed97531"
    RefDS(_4295);
    DeRefDS(_name);
    return _4295;
    goto L3;
L5:

    // 	elsif equal(name, "Try") then
    DeRef(_4285);
    if (_name == _4296)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4296))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4296) == 0);
    if (_4285 == 0)
        goto L6;

    // 	    return "Try97531"
    RefDS(_4298);
    DeRefDS(_name);
    return _4298;
    goto L3;
L6:

    // 	elsif equal(name, "cdecl") then
    DeRef(_4285);
    if (_name == _4299)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4299))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4299) == 0);
    if (_4285 == 0)
        goto L7;

    // 	    return "cdecl97531"
    RefDS(_4301);
    DeRefDS(_name);
    return _4301;
    goto L3;
L7:

    // 	elsif equal(name, "far") then
    DeRef(_4285);
    if (_name == _4302)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4302))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4302) == 0);
    if (_4285 == 0)
        goto L8;

    // 	    return "far97531"
    RefDS(_4304);
    DeRefDS(_name);
    return _4304;
    goto L3;
L8:

    // 	elsif equal(name, "far16") then
    DeRef(_4285);
    if (_name == _4305)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4305))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4305) == 0);
    if (_4285 == 0)
        goto L9;

    // 	    return "far1697531"
    RefDS(_4307);
    DeRefDS(_name);
    return _4307;
    goto L3;
L9:

    // 	elsif equal(name, "asm") then
    DeRef(_4285);
    if (_name == _4308)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4308))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4308) == 0);
    if (_4285 == 0)
        goto LA;

    // 	    return "asm97531"
    RefDS(_4310);
    DeRefDS(_name);
    return _4310;
    goto L3;
LA:

    // 	    return name
    DeRef(_4285);
    return _name;
LB:
    goto L3;
L1:

    // 	if    equal(name, "stdcall") then
    DeRef(_4285);
    if (_name == _4311)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4311))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4311) == 0);
    if (_4285 == 0)
        goto LC;

    // 	    return "stdcall97531"
    RefDS(_4313);
    DeRefDS(_name);
    return _4313;
    goto LD;
LC:

    // 	elsif equal(name, "fastcall") then
    DeRef(_4285);
    if (_name == _4314)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4314))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4314) == 0);
    if (_4285 == 0)
        goto LE;

    // 	    return "fastcall97531"
    RefDS(_4316);
    DeRefDS(_name);
    return _4316;
    goto LD;
LE:

    // 	elsif equal(name, "pascal") then
    DeRef(_4285);
    if (_name == _4317)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4317))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4317) == 0);
    if (_4285 == 0)
        goto LF;

    // 	    return "pascal97531"
    RefDS(_4319);
    DeRefDS(_name);
    return _4319;
    goto LD;
LF:

    // 	elsif equal(name, "try") then
    DeRef(_4285);
    if (_name == _4320)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4320))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4320) == 0);
    if (_4285 == 0)
        goto L10;

    // 	    return "try97531"
    RefDS(_4322);
    DeRefDS(_name);
    return _4322;
    goto LD;
L10:

    // 	elsif equal(name, "near") then
    DeRef(_4285);
    if (_name == _4323)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4323))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4323) == 0);
    if (_4285 == 0)
        goto L11;

    // 	    return "near97531"
    RefDS(_4325);
    DeRefDS(_name);
    return _4325;
    goto LD;
L11:

    // 	elsif equal(name, "interrupt") then
    DeRef(_4285);
    if (_name == _4326)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4326))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4326) == 0);
    if (_4285 == 0)
        goto L12;

    // 	    return "interrupt97531"
    RefDS(_4328);
    DeRefDS(_name);
    return _4328;
    goto LD;
L12:

    // 	elsif equal(name, "huge") then
    DeRef(_4285);
    if (_name == _4329)
        _4285 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4329))
        _4285 = 0;
    else
        _4285 = (compare(_name, _4329) == 0);
    if (_4285 == 0)
        goto L13;

    // 	    return "huge97531"
    RefDS(_4331);
    DeRefDS(_name);
    return _4331;
    goto LD;
L13:

    // 	    return name
    DeRef(_4285);
    return _name;
LD:
L3:
    ;
}


int _16CName(int _s)
{
    int _v = 0;
    int _4338 = 0;
    int _4332 = 0;
    int _4361 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     v = ObjValue(s)
    _v = _16ObjValue(_s);

    //     if SymTab[s][S_MODE] = M_NORMAL then
    _2 = (int)SEQ_PTR(_4SymTab);
    _4332 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4332);
    _0 = _4332;
    _2 = (int)SEQ_PTR(_4332);
    _4332 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4332);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4332, 1))
        goto L1;

    // 	if LeftSym = FALSE and GType(s) = TYPE_INTEGER and v != NOVALUE then
    DeRef(_4332);
    _4332 = (_16LeftSym == 0);
    if (_4332 == 0) {
        _4332 = 0;
        goto L2;
    }
    _4338 = _16GType(_s);
    _4338 = (_4338 == 1);
    _4332 = (_4338 != 0);
L2:
    if (_4332 == 0) {
        goto L3;
    }
    DeRef(_4332);
    _4332 = binary_op(NOTEQ, _v, _4NOVALUE);
L4:
    if (_4332 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_4332) && DBL_PTR(_4332)->dbl == 0.0)
            goto L3;
    }

    // 	    c_printf("%d", v)
    RefDS(_122);
    Ref(_v);
    _9c_printf(_122, _v);
    goto L5;
L3:

    // 	    if SymTab[s][S_SCOPE] > SC_PRIVATE then 
    DeRef(_4332);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4332 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4332);
    _0 = _4332;
    _2 = (int)SEQ_PTR(_4332);
    _4332 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4332);
    DeRefDS(_0);
    if (binary_op_a(LESSEQ, _4332, 3))
        goto L6;

    // 		c_printf("_%d", SymTab[s][S_FILE_NO])
    DeRef(_4332);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4332 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4332);
    _0 = _4332;
    _2 = (int)SEQ_PTR(_4332);
    _4332 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4332);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_4332);
    _9c_printf(_4345, _4332);

    // 		c_puts(SymTab[s][S_NAME])
    DeRef(_4332);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4332 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4332);
    _0 = _4332;
    _2 = (int)SEQ_PTR(_4332);
    _4332 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4332);
    DeRefDS(_0);
    Ref(_4332);
    _9c_puts(_4332);
    goto L7;
L6:

    // 		c_puts("_")
    RefDS(_4350);
    _9c_puts(_4350);

    // 		c_puts(ok_name(SymTab[s][S_NAME]))
    DeRef(_4332);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4332 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4332);
    _0 = _4332;
    _2 = (int)SEQ_PTR(_4332);
    _4332 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4332);
    DeRefDS(_0);
    Ref(_4332);
    _0 = _4332;
    _4332 = _16ok_name(_4332);
    DeRef(_0);
    RefDS(_4332);
    _9c_puts(_4332);
L7:
L5:

    // 	if s != CurrentSub and SymTab[s][S_NREFS] < 2 then
    DeRef(_4332);
    _4332 = (_s != _4CurrentSub);
    if (_4332 == 0) {
        goto L8;
    }
    DeRef(_4338);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4338 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4338);
    _0 = _4338;
    _2 = (int)SEQ_PTR(_4338);
    _4338 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4338);
    DeRefDS(_0);
    _0 = _4338;
    if (IS_ATOM_INT(_4338)) {
        _4338 = (_4338 < 2);
    }
    else {
        _4338 = binary_op(LESS, _4338, 2);
    }
    DeRef(_0);
L9:
    if (_4338 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_4338) && DBL_PTR(_4338)->dbl == 0.0)
            goto L8;
    }

    // 	    SymTab[s][S_NREFS] += 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4361);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _4361 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4361);
    _0 = _4361;
    if (IS_ATOM_INT(_4361)) {
        _4361 = _4361 + 1;
        if (_4361 > MAXINT)
            _4361 = NewDouble((double)_4361);
    }
    else
        _4361 = binary_op(PLUS, 1, _4361);
    DeRef(_0);
    Ref(_4361);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _4361;
    DeRef(_1);
L8:

    // 	SetBBType(s, TYPE_NULL, novalue, TYPE_OBJECT) -- record that this var was referenced in this BB
    RefDS(_9novalue);
    _16SetBBType(_s, 0, _9novalue, 16);
    goto LA;
L1:

    //     elsif SymTab[s][S_MODE] = M_CONSTANT then
    DeRef(_4361);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4361 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4361);
    _0 = _4361;
    _2 = (int)SEQ_PTR(_4361);
    _4361 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4361);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4361, 2))
        goto LB;

    // 	if LeftSym = FALSE and TypeIs(s, TYPE_INTEGER) and v != NOVALUE then
    DeRef(_4361);
    _4361 = (_16LeftSym == 0);
    if (_4361 == 0) {
        _4361 = 0;
        goto LC;
    }
    _0 = _4332;
    _4332 = _16TypeIs(_s, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_4332))
        _4361 = (_4332 != 0);
    else
        _4361 = DBL_PTR(_4332)->dbl != 0.0;
LC:
    if (_4361 == 0) {
        goto LD;
    }
    DeRef(_4361);
    _4361 = binary_op(NOTEQ, _v, _4NOVALUE);
LE:
    if (_4361 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_4361) && DBL_PTR(_4361)->dbl == 0.0)
            goto LD;
    }

    // 	    c_printf("%d", v) 
    RefDS(_122);
    Ref(_v);
    _9c_printf(_122, _v);
    goto LA;
LD:

    // 	    c_printf("_%d", SymTab[s][S_FILE_NO])
    DeRef(_4361);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4361 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4361);
    _0 = _4361;
    _2 = (int)SEQ_PTR(_4361);
    _4361 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4361);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_4361);
    _9c_printf(_4345, _4361);

    // 	    c_puts(SymTab[s][S_NAME])
    DeRef(_4361);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4361 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4361);
    _0 = _4361;
    _2 = (int)SEQ_PTR(_4361);
    _4361 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4361);
    DeRefDS(_0);
    Ref(_4361);
    _9c_puts(_4361);

    // 	    if SymTab[s][S_NREFS] < 2 then
    DeRef(_4361);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4361 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4361);
    _0 = _4361;
    _2 = (int)SEQ_PTR(_4361);
    _4361 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4361);
    DeRefDS(_0);
    if (binary_op_a(GREATEREQ, _4361, 2))
        goto LA;

    // 		SymTab[s][S_NREFS] += 1
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_s + ((s1_ptr)_2)->base);
    DeRef(_4338);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _4338 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4338);
    _0 = _4338;
    if (IS_ATOM_INT(_4338)) {
        _4338 = _4338 + 1;
        if (_4338 > MAXINT)
            _4338 = NewDouble((double)_4338);
    }
    else
        _4338 = binary_op(PLUS, 1, _4338);
    DeRef(_0);
    Ref(_4338);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _4338;
    DeRef(_1);
LF:
L10:
    goto LA;
LB:

    // 	if LeftSym = FALSE and GType(s) = TYPE_INTEGER and v != NOVALUE then
    DeRef(_4338);
    _4338 = (_16LeftSym == 0);
    if (_4338 == 0) {
        _4338 = 0;
        goto L11;
    }
    _0 = _4332;
    _4332 = _16GType(_s);
    DeRef(_0);
    _4332 = (_4332 == 1);
    _4338 = (_4332 != 0);
L11:
    if (_4338 == 0) {
        goto L12;
    }
    DeRef(_4338);
    _4338 = binary_op(NOTEQ, _v, _4NOVALUE);
L13:
    if (_4338 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_4338) && DBL_PTR(_4338)->dbl == 0.0)
            goto L12;
    }

    // 	    c_printf("%d", v)
    RefDS(_122);
    Ref(_v);
    _9c_printf(_122, _v);
    goto L14;
L12:

    // 	    c_printf("_%d", SymTab[s][S_TEMP_NAME])
    DeRef(_4338);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4338 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_4338);
    _0 = _4338;
    _2 = (int)SEQ_PTR(_4338);
    _4338 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_4338);
    DeRefDS(_0);
    RefDS(_4345);
    Ref(_4338);
    _9c_printf(_4345, _4338);
L14:
LA:

    //     LeftSym = FALSE
    _16LeftSym = 0;

    // end procedure
    DeRef(_v);
    DeRef(_4338);
    DeRef(_4332);
    DeRef(_4361);
    return 0;
    ;
}


