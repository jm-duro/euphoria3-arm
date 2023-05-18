// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18min(int _a, int _b)
{
    int _0, _1, _2;
    

    //     if a < b then 
    if (binary_op_a(GREATEREQ, _a, _b))
        goto L1;

    // 	return a
    DeRef(_b);
    return _a;
    goto L2;
L1:

    // 	return b
    DeRef(_a);
    return _b;
L2:
    ;
}


int _18max(int _a, int _b)
{
    int _0, _1, _2;
    

    //     if a > b then 
    if (binary_op_a(LESSEQ, _a, _b))
        goto L1;

    // 	return a
    DeRef(_b);
    return _a;
    goto L2;
L1:

    // 	return b
    DeRef(_a);
    return _b;
L2:
    ;
}


int _18abs(int _a)
{
    int _5439 = 0;
    int _0, _1, _2;
    

    //     if a < 0 then
    if (binary_op_a(GREATEREQ, _a, 0))
        goto L1;

    // 	return -a
    if (IS_ATOM_INT(_a)) {
        if (_a == 0xC0000000)
            _5439 = (int)NewDouble((double)-0xC0000000);
        else
            _5439 = - _a;
    }
    else {
        _5439 = unary_op(UMINUS, _a);
    }
    DeRef(_a);
    return _5439;
    goto L2;
L1:

    // 	return a
    DeRef(_5439);
    return _a;
L2:
    ;
}


int _18savespace()
{
    int _5447 = 0;
    int _5444 = 0;
    int _5443;
    int _5441;
    int _0, _1, _2;
    

    //    return length(in_loop) = 0 and (CurrentSub = TopLevelSub or
    _5441 = SEQ_PTR(_18in_loop)->length;
    _5441 = (_5441 == 0);
    _5443 = (_4CurrentSub == _4TopLevelSub);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5444 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_5444);
    _0 = _5444;
    _2 = (int)SEQ_PTR(_5444);
    _5444 = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_5444);
    DeRefDS(_0);
    _0 = _5444;
    _5444 = SEQ_PTR(_5444)->length;
    DeRef(_0);
    if (2500 & 1) {
        _5447 = NewDouble((2500 >> 1) + 0.5);
    }
    else
        _5447 = 2500 >> 1;
    _0 = _5447;
    if (IS_ATOM_INT(_5447)) {
        _5447 = (_5444 > _5447);
    }
    else {
        _5447 = ((double)_5444 > DBL_PTR(_5447)->dbl);
    }
    DeRef(_0);
    _5447 = (_5443 != 0 || _5447 != 0);
    _5447 = (_5441 != 0 && _5447 != 0);
    return _5447;
    ;
}


int _18BB_temp_type(int _var)
{
    int _t;
    int _tn;
    int _5451 = 0;
    int _5460 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     tn = SymTab[var][S_TEMP_NAME]
    _2 = (int)SEQ_PTR(_4SymTab);
    _5451 = (int)*(((s1_ptr)_2)->base + _var);
    RefDS(_5451);
    _2 = (int)SEQ_PTR(_5451);
    _tn = (int)*(((s1_ptr)_2)->base + 31);
    if (!IS_ATOM_INT(_tn))
        _tn = (long)DBL_PTR(_tn)->dbl;

    //     for i = length(BB_info) to 1 by -1 do
    DeRefDS(_5451);
    _5451 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _5451;
L1:
        if (_i < 1)
            goto L2;

        // 	if SymTab[BB_info[i][BB_VAR]][S_MODE] = M_TEMP and
        DeRef(_5451);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5451 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5451);
        _0 = _5451;
        _2 = (int)SEQ_PTR(_5451);
        _5451 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5451);
        DeRefDS(_0);
        _0 = _5451;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5451))
            _5451 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5451)->dbl));
        else
            _5451 = (int)*(((s1_ptr)_2)->base + _5451);
        RefDS(_5451);
        DeRef(_0);
        _0 = _5451;
        _2 = (int)SEQ_PTR(_5451);
        _5451 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5451);
        DeRefDS(_0);
        _0 = _5451;
        if (IS_ATOM_INT(_5451)) {
            _5451 = (_5451 == 3);
        }
        else {
            _5451 = binary_op(EQUALS, _5451, 3);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5451)) {
            if (_5451 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_5451)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_5460);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5460 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5460);
        _0 = _5460;
        _2 = (int)SEQ_PTR(_5460);
        _5460 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5460);
        DeRefDS(_0);
        _0 = _5460;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5460))
            _5460 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5460)->dbl));
        else
            _5460 = (int)*(((s1_ptr)_2)->base + _5460);
        RefDS(_5460);
        DeRef(_0);
        _0 = _5460;
        _2 = (int)SEQ_PTR(_5460);
        _5460 = (int)*(((s1_ptr)_2)->base + 31);
        Ref(_5460);
        DeRefDS(_0);
        _0 = _5460;
        if (IS_ATOM_INT(_5460)) {
            _5460 = (_5460 == _tn);
        }
        else {
            _5460 = binary_op(EQUALS, _5460, _tn);
        }
        DeRef(_0);
L4:
        if (_5460 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_5460) && DBL_PTR(_5460)->dbl == 0.0)
                goto L3;
        }

        // 	    t = BB_info[i][BB_TYPE]
        DeRef(_5460);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5460 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5460);
        _2 = (int)SEQ_PTR(_5460);
        _t = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_t))
            _t = (long)DBL_PTR(_t)->dbl;

        // 	    if t <= 0 or t > TYPE_OBJECT then
        DeRefDS(_5460);
        _5460 = (_t <= 0);
        if (_5460 != 0) {
            goto L5;
        }
        DeRef(_5451);
        _5451 = (_t > 16);
L6:
        if (_5451 == 0)
            goto L7;
L5:

        // 		InternalErr("Bad BB_temp_type")
        RefDS(_5470);
        _6InternalErr(_5470);
L7:

        // 	    return t
        DeRef(_5451);
        DeRef(_5460);
        return _t;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return or_type(TYPE_INTEGER,   -- for initialization = 0
    DeRef(_5451);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5451 = (int)*(((s1_ptr)_2)->base + _var);
    RefDS(_5451);
    _0 = _5451;
    _2 = (int)SEQ_PTR(_5451);
    _5451 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5451);
    DeRefDS(_0);
    _0 = _5451;
    _2 = (int)SEQ_PTR(_4temp_name_type);
    if (!IS_ATOM_INT(_5451))
        _5451 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5451)->dbl));
    else
        _5451 = (int)*(((s1_ptr)_2)->base + _5451);
    RefDS(_5451);
    DeRef(_0);
    _0 = _5451;
    _2 = (int)SEQ_PTR(_5451);
    _5451 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5451);
    DeRefDS(_0);
    Ref(_5451);
    _0 = _5451;
    _5451 = _16or_type(1, _5451);
    DeRef(_0);
    DeRef(_5460);
    return _5451;
    ;
}


int _18BB_temp_elem(int _var)
{
    int _t;
    int _tn;
    int _5476 = 0;
    int _5485 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     tn = SymTab[var][S_TEMP_NAME]
    _2 = (int)SEQ_PTR(_4SymTab);
    _5476 = (int)*(((s1_ptr)_2)->base + _var);
    RefDS(_5476);
    _2 = (int)SEQ_PTR(_5476);
    _tn = (int)*(((s1_ptr)_2)->base + 31);
    if (!IS_ATOM_INT(_tn))
        _tn = (long)DBL_PTR(_tn)->dbl;

    //     for i = length(BB_info) to 1 by -1 do 
    DeRefDS(_5476);
    _5476 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _5476;
L1:
        if (_i < 1)
            goto L2;

        // 	if SymTab[BB_info[i][BB_VAR]][S_MODE] = M_TEMP and
        DeRef(_5476);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5476 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5476);
        _0 = _5476;
        _2 = (int)SEQ_PTR(_5476);
        _5476 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5476);
        DeRefDS(_0);
        _0 = _5476;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5476))
            _5476 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5476)->dbl));
        else
            _5476 = (int)*(((s1_ptr)_2)->base + _5476);
        RefDS(_5476);
        DeRef(_0);
        _0 = _5476;
        _2 = (int)SEQ_PTR(_5476);
        _5476 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5476);
        DeRefDS(_0);
        _0 = _5476;
        if (IS_ATOM_INT(_5476)) {
            _5476 = (_5476 == 3);
        }
        else {
            _5476 = binary_op(EQUALS, _5476, 3);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5476)) {
            if (_5476 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_5476)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_5485);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5485 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5485);
        _0 = _5485;
        _2 = (int)SEQ_PTR(_5485);
        _5485 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5485);
        DeRefDS(_0);
        _0 = _5485;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5485))
            _5485 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5485)->dbl));
        else
            _5485 = (int)*(((s1_ptr)_2)->base + _5485);
        RefDS(_5485);
        DeRef(_0);
        _0 = _5485;
        _2 = (int)SEQ_PTR(_5485);
        _5485 = (int)*(((s1_ptr)_2)->base + 31);
        Ref(_5485);
        DeRefDS(_0);
        _0 = _5485;
        if (IS_ATOM_INT(_5485)) {
            _5485 = (_5485 == _tn);
        }
        else {
            _5485 = binary_op(EQUALS, _5485, _tn);
        }
        DeRef(_0);
L4:
        if (_5485 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_5485) && DBL_PTR(_5485)->dbl == 0.0)
                goto L3;
        }

        // 	    t = BB_info[i][BB_ELEM]
        DeRef(_5485);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5485 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5485);
        _2 = (int)SEQ_PTR(_5485);
        _t = (int)*(((s1_ptr)_2)->base + 3);
        if (!IS_ATOM_INT(_t))
            _t = (long)DBL_PTR(_t)->dbl;

        // 	    if t = TYPE_NULL then
        if (_t != 0)
            goto L5;

        // 		t = TYPE_OBJECT
        _t = 16;
L5:

        // 	    if t <= 0 or t > TYPE_OBJECT then
        DeRef(_5485);
        _5485 = (_t <= 0);
        if (_5485 != 0) {
            goto L6;
        }
        DeRef(_5476);
        _5476 = (_t > 16);
L7:
        if (_5476 == 0)
            goto L8;
L6:

        // 		InternalErr("Bad BB_elem type")
        RefDS(_5496);
        _6InternalErr(_5496);
L8:

        // 	    return t
        DeRef(_5476);
        DeRef(_5485);
        return _t;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return TYPE_OBJECT -- Later we might track temp element types globally
    DeRef(_5476);
    DeRef(_5485);
    return 16;
    ;
}


int _18BB_var_elem(int _var)
{
    int _t;
    int _5497 = 0;
    int _5504 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     for i = length(BB_info) to 1 by -1 do 
    _5497 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _5497;
L1:
        if (_i < 1)
            goto L2;

        // 	if SymTab[BB_info[i][BB_VAR]][S_MODE] = M_NORMAL and
        DeRef(_5497);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5497 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5497);
        _0 = _5497;
        _2 = (int)SEQ_PTR(_5497);
        _5497 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5497);
        DeRefDS(_0);
        _0 = _5497;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5497))
            _5497 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5497)->dbl));
        else
            _5497 = (int)*(((s1_ptr)_2)->base + _5497);
        RefDS(_5497);
        DeRef(_0);
        _0 = _5497;
        _2 = (int)SEQ_PTR(_5497);
        _5497 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5497);
        DeRefDS(_0);
        _0 = _5497;
        if (IS_ATOM_INT(_5497)) {
            _5497 = (_5497 == 1);
        }
        else {
            _5497 = binary_op(EQUALS, _5497, 1);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5497)) {
            if (_5497 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_5497)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_5504);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5504 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5504);
        _0 = _5504;
        _2 = (int)SEQ_PTR(_5504);
        _5504 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5504);
        DeRefDS(_0);
        _0 = _5504;
        if (IS_ATOM_INT(_5504)) {
            _5504 = (_5504 == _var);
        }
        else {
            _5504 = binary_op(EQUALS, _5504, _var);
        }
        DeRef(_0);
L4:
        if (_5504 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_5504) && DBL_PTR(_5504)->dbl == 0.0)
                goto L3;
        }

        // 	    t = BB_info[i][BB_ELEM]
        DeRef(_5504);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5504 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5504);
        _2 = (int)SEQ_PTR(_5504);
        _t = (int)*(((s1_ptr)_2)->base + 3);
        if (!IS_ATOM_INT(_t))
            _t = (long)DBL_PTR(_t)->dbl;

        // 	    if t < 0 or t > TYPE_OBJECT then
        DeRefDS(_5504);
        _5504 = (_t < 0);
        if (_5504 != 0) {
            goto L5;
        }
        DeRef(_5497);
        _5497 = (_t > 16);
L6:
        if (_5497 == 0)
            goto L7;
L5:

        // 		InternalErr("Bad BB_elem")
        RefDS(_5512);
        _6InternalErr(_5512);
L7:

        // 	    if t = TYPE_NULL then   -- var has only been read
        if (_t != 0)
            goto L8;

        // 		return TYPE_OBJECT
        DeRef(_5497);
        DeRef(_5504);
        return 16;
        goto L9;
L8:

        // 		return t
        DeRef(_5497);
        DeRef(_5504);
        return _t;
L9:
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return TYPE_OBJECT
    DeRef(_5497);
    DeRef(_5504);
    return 16;
    ;
}


int _18BB_var_seqlen(int _var)
{
    int _5514 = 0;
    int _5521 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     for i = length(BB_info) to 1 by -1 do 
    _5514 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _5514;
L1:
        if (_i < 1)
            goto L2;

        // 	if SymTab[BB_info[i][BB_VAR]][S_MODE] = M_NORMAL and
        DeRef(_5514);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5514 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5514);
        _0 = _5514;
        _2 = (int)SEQ_PTR(_5514);
        _5514 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5514);
        DeRefDS(_0);
        _0 = _5514;
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!IS_ATOM_INT(_5514))
            _5514 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5514)->dbl));
        else
            _5514 = (int)*(((s1_ptr)_2)->base + _5514);
        RefDS(_5514);
        DeRef(_0);
        _0 = _5514;
        _2 = (int)SEQ_PTR(_5514);
        _5514 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_5514);
        DeRefDS(_0);
        _0 = _5514;
        if (IS_ATOM_INT(_5514)) {
            _5514 = (_5514 == 1);
        }
        else {
            _5514 = binary_op(EQUALS, _5514, 1);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5514)) {
            if (_5514 == 0) {
                goto L3;
            }
        }
        else {
            if (DBL_PTR(_5514)->dbl == 0.0) {
                goto L3;
            }
        }
        DeRef(_5521);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5521 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5521);
        _0 = _5521;
        _2 = (int)SEQ_PTR(_5521);
        _5521 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5521);
        DeRefDS(_0);
        _0 = _5521;
        if (IS_ATOM_INT(_5521)) {
            _5521 = (_5521 == _var);
        }
        else {
            _5521 = binary_op(EQUALS, _5521, _var);
        }
        DeRef(_0);
L4:
        if (_5521 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_5521) && DBL_PTR(_5521)->dbl == 0.0)
                goto L3;
        }

        // 	    if BB_info[i][BB_TYPE] != TYPE_SEQUENCE and -- makes sense? (was or)
        DeRef(_5521);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5521 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5521);
        _0 = _5521;
        _2 = (int)SEQ_PTR(_5521);
        _5521 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5521);
        DeRefDS(_0);
        _0 = _5521;
        if (IS_ATOM_INT(_5521)) {
            _5521 = (_5521 != 8);
        }
        else {
            _5521 = binary_op(NOTEQ, _5521, 8);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_5521)) {
            if (_5521 == 0) {
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_5521)->dbl == 0.0) {
                goto L5;
            }
        }
        DeRef(_5514);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5514 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5514);
        _0 = _5514;
        _2 = (int)SEQ_PTR(_5514);
        _5514 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_5514);
        DeRefDS(_0);
        _0 = _5514;
        if (IS_ATOM_INT(_5514)) {
            _5514 = (_5514 != 16);
        }
        else {
            _5514 = binary_op(NOTEQ, _5514, 16);
        }
        DeRef(_0);
L6:
        if (_5514 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_5514) && DBL_PTR(_5514)->dbl == 0.0)
                goto L5;
        }

        // 		return NOVALUE
        RefDS(_4NOVALUE);
        DeRef(_5514);
        DeRef(_5521);
        return _4NOVALUE;
L5:

        // 	    return BB_info[i][BB_SEQLEN]
        DeRef(_5514);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5514 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5514);
        _0 = _5514;
        _2 = (int)SEQ_PTR(_5514);
        _5514 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_5514);
        DeRefDS(_0);
        DeRef(_5521);
        return _5514;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return NOVALUE
    RefDS(_4NOVALUE);
    DeRef(_5514);
    DeRef(_5521);
    return _4NOVALUE;
    ;
}


int _18SeqElem(int _x)
{
    int _s;
    int _t;
    int _local_t;
    int _5537 = 0;
    int _5533 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     s = x
    _s = _x;

    //     t = SymTab[s][S_SEQ_ELEM]
    _2 = (int)SEQ_PTR(_4SymTab);
    _5533 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5533);
    _2 = (int)SEQ_PTR(_5533);
    _t = (int)*(((s1_ptr)_2)->base + 30);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     if t < 0 or t > TYPE_OBJECT then
    DeRefDS(_5533);
    _5533 = (_t < 0);
    if (_5533 != 0) {
        goto L1;
    }
    _5537 = (_t > 16);
L2:
    if (_5537 == 0)
        goto L3;
L1:

    // 	InternalErr("Bad seq_elem")
    RefDS(_5538);
    _6InternalErr(_5538);
L3:

    //     if SymTab[s][S_MODE] != M_NORMAL then
    DeRef(_5537);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5537 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5537);
    _0 = _5537;
    _2 = (int)SEQ_PTR(_5537);
    _5537 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5537);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5537, 1))
        goto L4;

    // 	return t
    DeRef(_5537);
    DeRef(_5533);
    return _t;
L4:

    //     local_t = BB_var_elem(x)
    _local_t = _18BB_var_elem(_x);

    //     if local_t = TYPE_OBJECT then 
    if (_local_t != 16)
        goto L5;

    // 	return t
    DeRef(_5537);
    DeRef(_5533);
    return _t;
L5:

    //     if t = TYPE_INTEGER then
    if (_t != 1)
        goto L6;

    // 	return TYPE_INTEGER
    DeRef(_5537);
    DeRef(_5533);
    return 1;
L6:

    //     return local_t
    DeRef(_5537);
    DeRef(_5533);
    return _local_t;
    ;
}


int _18SeqLen(int _x)
{
    int _s;
    int _len = 0;
    int _local_len = 0;
    int _5545 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     s = x
    _s = _x;

    //     len = SymTab[s][S_SEQ_LEN]
    _2 = (int)SEQ_PTR(_4SymTab);
    _5545 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5545);
    _2 = (int)SEQ_PTR(_5545);
    _len = (int)*(((s1_ptr)_2)->base + 29);
    Ref(_len);

    //     if SymTab[s][S_MODE] != M_NORMAL then
    DeRefDS(_5545);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5545 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5545);
    _0 = _5545;
    _2 = (int)SEQ_PTR(_5545);
    _5545 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5545);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5545, 1))
        goto L1;

    // 	return len
    DeRef(_5545);
    return _len;
L1:

    //     local_len = BB_var_seqlen(x)
    _0 = _local_len;
    _local_len = _18BB_var_seqlen(_x);
    DeRef(_0);

    //     if local_len = NOVALUE then 
    if (binary_op_a(NOTEQ, _local_len, _4NOVALUE))
        goto L2;

    // 	return len
    DeRef(_local_len);
    DeRef(_5545);
    return _len;
    goto L3;
L2:

    // 	return local_len
    DeRef(_len);
    DeRef(_5545);
    return _local_len;
L3:
    ;
}


int _18ObjMinMax(int _x)
{
    int _s;
    int _t = 0;
    int _local_t = 0;
    int _5554 = 0;
    int _5552 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //     s = x
    _s = _x;

    //     t = {SymTab[s][S_OBJ_MIN], SymTab[s][S_OBJ_MAX]}
    _2 = (int)SEQ_PTR(_4SymTab);
    _5552 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5552);
    _0 = _5552;
    _2 = (int)SEQ_PTR(_5552);
    _5552 = (int)*(((s1_ptr)_2)->base + 27);
    Ref(_5552);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5554 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5554);
    _0 = _5554;
    _2 = (int)SEQ_PTR(_5554);
    _5554 = (int)*(((s1_ptr)_2)->base + 28);
    Ref(_5554);
    DeRefDS(_0);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5552;
    Ref(_5552);
    ((int *)_2)[2] = _5554;
    Ref(_5554);
    _t = MAKE_SEQ(_1);

    //     if SymTab[s][S_MODE] != M_NORMAL then
    DeRef(_5554);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5554 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5554);
    _0 = _5554;
    _2 = (int)SEQ_PTR(_5554);
    _5554 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5554);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _5554, 1))
        goto L1;

    // 	return t
    DeRef(_5554);
    DeRef(_5552);
    return _t;
L1:

    //     local_t = BB_var_obj(x)
    _0 = _local_t;
    _local_t = _16BB_var_obj(_x);
    DeRef(_0);

    //     if local_t[MIN] = NOVALUE then 
    DeRef(_5554);
    _2 = (int)SEQ_PTR(_local_t);
    _5554 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5554);
    if (binary_op_a(NOTEQ, _5554, _4NOVALUE))
        goto L2;

    // 	return t
    DeRefDS(_local_t);
    DeRef(_5554);
    DeRef(_5552);
    return _t;
    goto L3;
L2:

    // 	return local_t
    DeRef(_t);
    DeRef(_5554);
    DeRef(_5552);
    return _local_t;
L3:
    ;
}


int _18IntegerSize(int _pc, int _var)
{
    int _op;
    int _5563 = 0;
    int _5571 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     op = Code[pc]
    _2 = (int)SEQ_PTR(_4Code);
    _op = (int)*(((s1_ptr)_2)->base + _pc);
    if (!IS_ATOM_INT(_op))
        _op = (long)DBL_PTR(_op)->dbl;

    //     if find(op, {ASSIGN_OP_SUBS, PASSIGN_OP_SUBS, RHS_SUBS_CHECK, RHS_SUBS,
    _5563 = find(_op, _5564);
    if (_5563 == 0)
        goto L1;

    // 	return Code[pc+2] = var
    _5563 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    return _5563;
    goto L2;
L1:

    //     elsif op = LHS_SUBS or op = LHS_SUBS1 or op = LHS_SUBS1_COPY then
    DeRef(_5563);
    _5563 = (_op == 95);
    if (_5563 != 0) {
        _5563 = 1;
        goto L3;
    }
    DeRef(_5571);
    _5571 = (_op == 163);
    _5563 = (_5571 != 0);
L3:
    if (_5563 != 0) {
        goto L4;
    }
    DeRef(_5563);
    _5563 = (_op == 168);
L5:
    if (_5563 == 0)
        goto L6;
L4:

    // 	return Code[pc+2] = var
    DeRef(_5563);
    _5563 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    DeRef(_5571);
    return _5563;
    goto L2;
L6:

    //     elsif op = REPEAT then
    if (_op != 32)
        goto L7;

    // 	return Code[pc+2] = var
    DeRef(_5563);
    _5563 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    DeRef(_5571);
    return _5563;
    goto L2;
L7:

    //     elsif op = RHS_SLICE or op = ASSIGN_SLICE then 
    DeRef(_5563);
    _5563 = (_op == 46);
    if (_5563 != 0) {
        goto L8;
    }
    DeRef(_5571);
    _5571 = (_op == 45);
L9:
    if (_5571 == 0)
        goto LA;
L8:

    // 	return Code[pc+2] = var or Code[pc+3] = var
    DeRef(_5571);
    _5571 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5571 = (int)*(((s1_ptr)_2)->base + _5571);
    Ref(_5571);
    _0 = _5571;
    if (IS_ATOM_INT(_5571)) {
        _5571 = (_5571 == _var);
    }
    else {
        _5571 = binary_op(EQUALS, _5571, _var);
    }
    DeRef(_0);
    DeRef(_5563);
    _5563 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    _0 = _5563;
    if (IS_ATOM_INT(_5571) && IS_ATOM_INT(_5563)) {
        _5563 = (_5571 != 0 || _5563 != 0);
    }
    else {
        _5563 = binary_op(OR, _5571, _5563);
    }
    DeRef(_0);
    DeRef(_5571);
    return _5563;
    goto L2;
LA:

    //     elsif op = POSITION then
    if (_op != 60)
        goto LB;

    // 	return Code[pc+1] = var or Code[pc+2] = var
    DeRef(_5563);
    _5563 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    DeRef(_5571);
    _5571 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5571 = (int)*(((s1_ptr)_2)->base + _5571);
    Ref(_5571);
    _0 = _5571;
    if (IS_ATOM_INT(_5571)) {
        _5571 = (_5571 == _var);
    }
    else {
        _5571 = binary_op(EQUALS, _5571, _var);
    }
    DeRef(_0);
    _0 = _5571;
    if (IS_ATOM_INT(_5563) && IS_ATOM_INT(_5571)) {
        _5571 = (_5563 != 0 || _5571 != 0);
    }
    else {
        _5571 = binary_op(OR, _5563, _5571);
    }
    DeRef(_0);
    DeRef(_5563);
    return _5571;
    goto L2;
LB:

    //     elsif op = MEM_COPY or op = MEM_SET then
    DeRef(_5571);
    _5571 = (_op == 132);
    if (_5571 != 0) {
        goto LC;
    }
    DeRef(_5563);
    _5563 = (_op == 133);
LD:
    if (_5563 == 0)
        goto LE;
LC:

    // 	return Code[pc+3] = var
    DeRef(_5563);
    _5563 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _5563 = (int)*(((s1_ptr)_2)->base + _5563);
    Ref(_5563);
    _0 = _5563;
    if (IS_ATOM_INT(_5563)) {
        _5563 = (_5563 == _var);
    }
    else {
        _5563 = binary_op(EQUALS, _5563, _var);
    }
    DeRef(_0);
    DeRef(_5571);
    return _5563;
    goto L2;
LE:

    // 	return FALSE
    DeRef(_5563);
    DeRef(_5571);
    return 0;
L2:
    ;
}


int _18find_label(int _addr)
{
    int _m;
    int _5605;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_addr)) {
        _1 = (long)(DBL_PTR(_addr)->dbl);
        DeRefDS(_addr);
        _addr = _1;
    }

    //     m = find(addr, label_map)
    _m = find(_addr, _18label_map);

    //     if m then
    if (_m == 0)
        goto L1;

    // 	return m
    return _m;
L1:

    //     label_map = append(label_map, addr)
    Append(&_18label_map, _18label_map, _addr);

    //     return length(label_map)
    _5605 = SEQ_PTR(_18label_map)->length;
    return _5605;
    ;
}


int _18forward_branch_into(int _addr1, int _addr2)
{
    int _5613 = 0;
    int _5612;
    int _5609;
    int _5608;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_addr1)) {
        _1 = (long)(DBL_PTR(_addr1)->dbl);
        DeRefDS(_addr1);
        _addr1 = _1;
    }
    if (!IS_ATOM_INT(_addr2)) {
        _1 = (long)(DBL_PTR(_addr2)->dbl);
        DeRefDS(_addr2);
        _addr2 = _1;
    }

    //     for i = 1 to length(label_map) do
    _5608 = SEQ_PTR(_18label_map)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _5608)
            goto L2;

        // 	if label_map[i] >= addr1 and label_map[i] <= addr2+1 then
        _2 = (int)SEQ_PTR(_18label_map);
        _5609 = (int)*(((s1_ptr)_2)->base + _i);
        _5609 = (_5609 >= _addr1);
        if (_5609 == 0) {
            goto L3;
        }
        _2 = (int)SEQ_PTR(_18label_map);
        _5612 = (int)*(((s1_ptr)_2)->base + _i);
        DeRef(_5613);
        _5613 = _addr2 + 1;
        if (_5613 > MAXINT)
            _5613 = NewDouble((double)_5613);
        _0 = _5613;
        if (IS_ATOM_INT(_5613)) {
            _5613 = (_5612 <= _5613);
        }
        else {
            _5613 = ((double)_5612 <= DBL_PTR(_5613)->dbl);
        }
        DeRef(_0);
L4:
        if (_5613 == 0)
            goto L3;

        // 	    return TRUE
        DeRef(_5613);
        return 1;
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     return FALSE
    DeRef(_5613);
    return 0;
    ;
}


int _18Label(int _addr)
{
    int _label_index;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_addr)) {
        _1 = (long)(DBL_PTR(_addr)->dbl);
        DeRefDS(_addr);
        _addr = _1;
    }

    //     NewBB(0, E_ALL_EFFECT, 0)
    _16NewBB(0, 1073741823, 0);

    //     label_index = find_label(addr)
    _label_index = _18find_label(_addr);

    //     c_printf("L%x:\n", label_index)
    RefDS(_5616);
    _9c_printf(_5616, _label_index);

    // end procedure               
    return 0;
    ;
}


int _18Goto(int _addr)
{
    int _label_index;
    int _br;
    int _new_addr;
    int _5620 = 0;
    int _5617;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_addr)) {
        _1 = (long)(DBL_PTR(_addr)->dbl);
        DeRefDS(_addr);
        _addr = _1;
    }

    //     while TRUE do
L1:

    // 	new_addr = addr
    _new_addr = _addr;

    // 	br = Code[new_addr]
    _2 = (int)SEQ_PTR(_4Code);
    _br = (int)*(((s1_ptr)_2)->base + _new_addr);
    if (!IS_ATOM_INT(_br))
        _br = (long)DBL_PTR(_br)->dbl;

    // 	while (br = NOP1 or br = STARTLINE) and new_addr < length(Code)-2 do
L2:
    _5617 = (_br == 161);
    if (_5617 != 0) {
        _5617 = 1;
        goto L3;
    }
    DeRef(_5620);
    _5620 = (_br == 58);
    _5617 = (_5620 != 0);
L3:
    if (_5617 == 0) {
        goto L4;
    }
    _5617 = SEQ_PTR(_4Code)->length;
    _5617 = _5617 - 2;
    _5617 = (_new_addr < _5617);
L5:
    if (_5617 == 0)
        goto L4;

    // 	    if br = NOP1 then
    if (_br != 161)
        goto L6;

    // 		new_addr += 1
    _new_addr = _new_addr + 1;
    goto L7;
L6:

    // 		new_addr += 2
    _new_addr = _new_addr + 2;
L7:

    // 	    br = Code[new_addr]
    _2 = (int)SEQ_PTR(_4Code);
    _br = (int)*(((s1_ptr)_2)->base + _new_addr);
    if (!IS_ATOM_INT(_br))
        _br = (long)DBL_PTR(_br)->dbl;

    // 	end while
    goto L2;
L4:

    // 	if addr < 6 or 
    _5617 = (_addr < 6);
    if (_5617 != 0) {
        goto L8;
    }
    DeRef(_5620);
    _5620 = _addr - 5;
    _2 = (int)SEQ_PTR(_4Code);
    _5620 = (int)*(((s1_ptr)_2)->base + _5620);
    Ref(_5620);
    _0 = _5620;
    _5620 = find(_5620, _5633);
    DeRef(_0);
    _5620 = (_5620 == 0);
L9:
    if (_5620 == 0)
        goto LA;
L8:

    // 	    if find(br, {ELSE, ENDWHILE, EXIT}) then
    DeRef(_5620);
    _5620 = find(_br, _5636);
    if (_5620 == 0)
        goto LA;

    // 		addr = Code[new_addr+1]
    _5620 = _new_addr + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _addr = (int)*(((s1_ptr)_2)->base + _5620);
    if (!IS_ATOM_INT(_addr))
        _addr = (long)DBL_PTR(_addr)->dbl;
    goto L1;
LB:

    // 		exit
    goto LA;
LC:
    goto L1;
LD:

    // 	    exit
    goto LA;
LE:

    //     end while
    goto L1;
LA:

    //     label_index = find_label(addr)
    _label_index = _18find_label(_addr);

    //     c_stmt0("goto ")
    RefDS(_5641);
    _16c_stmt0(_5641);

    //     c_printf("L%x;\n", label_index)
    RefDS(_5642);
    _9c_printf(_5642, _label_index);

    // end procedure
    DeRef(_5620);
    return 0;
    ;
}


int _18BB_exist(int _var)
{
    int _5643 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_var)) {
        _1 = (long)(DBL_PTR(_var)->dbl);
        DeRefDS(_var);
        _var = _1;
    }

    //     for i = length(BB_info) to 1 by -1 do 
    _5643 = SEQ_PTR(_16BB_info)->length;
    { int _i;
        _i = _5643;
L1:
        if (_i < 1)
            goto L2;

        // 	if BB_info[i][BB_VAR] = var then
        DeRef(_5643);
        _2 = (int)SEQ_PTR(_16BB_info);
        _5643 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_5643);
        _0 = _5643;
        _2 = (int)SEQ_PTR(_5643);
        _5643 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_5643);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _5643, _var))
            goto L3;

        // 	    return TRUE
        DeRef(_5643);
        return 1;
L3:

        //     end for
        _i = _i + -1;
        goto L1;
L2:
        ;
    }

    //     return FALSE
    DeRef(_5643);
    return 0;
    ;
}


int _18c_fixquote(int _c_source)
{
    int _c;
    int _5648;
    int _5651;
    int _5647;
    int _0, _1, _2;
    

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	for p = 1 to length(c_source) do
    _5647 = SEQ_PTR(_c_source)->length;
    { int _p;
        _p = 1;
L2:
        if (_p > _5647)
            goto L3;

        // 	    c = c_source[p]
        _2 = (int)SEQ_PTR(_c_source);
        _c = (int)*(((s1_ptr)_2)->base + _p);
        if (!IS_ATOM_INT(_c))
            _c = (long)DBL_PTR(_c)->dbl;

        // 	    if c = '"' or c = '\\' then
        _5648 = (_c == 34);
        if (_5648 != 0) {
            goto L4;
        }
        _5651 = (_c == 92);
L5:
        if (_5651 == 0)
            goto L6;
L4:

        // 		puts(c_code, '\\')
        EPuts(_9c_code, 92);
L6:

        // 	    if c != '\n' and c != '\r' then
        _5651 = (_c != 10);
        if (_5651 == 0) {
            goto L7;
        }
        _5648 = (_c != 13);
L8:
        if (_5648 == 0)
            goto L7;

        // 		puts(c_code, c)
        EPuts(_9c_code, _c);
L7:

        // 	end for
        _p = _p + 1;
        goto L2;
L3:
        ;
    }
L1:

    // end procedure
    DeRefDS(_c_source);
    return 0;
    ;
}


int _18IsParameter(int _v)
{
    int _5665 = 0;
    int _5655 = 0;
    int _5659 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_v)) {
        _1 = (long)(DBL_PTR(_v)->dbl);
        DeRefDS(_v);
        _v = _1;
    }

    //     if SymTab[v][S_MODE] = M_NORMAL and 
    _2 = (int)SEQ_PTR(_4SymTab);
    _5655 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5655);
    _0 = _5655;
    _2 = (int)SEQ_PTR(_5655);
    _5655 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5655);
    DeRefDS(_0);
    _0 = _5655;
    if (IS_ATOM_INT(_5655)) {
        _5655 = (_5655 == 1);
    }
    else {
        _5655 = binary_op(EQUALS, _5655, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5655)) {
        if (_5655 == 0) {
            DeRef(_5655);
            _5655 = 0;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_5655)->dbl == 0.0) {
            DeRef(_5655);
            _5655 = 0;
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_4SymTab);
    _5659 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5659);
    _0 = _5659;
    _2 = (int)SEQ_PTR(_5659);
    _5659 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5659);
    DeRefDS(_0);
    _0 = _5659;
    if (IS_ATOM_INT(_5659)) {
        _5659 = (_5659 == 3);
    }
    else {
        _5659 = binary_op(EQUALS, _5659, 3);
    }
    DeRef(_0);
    DeRef(_5655);
    if (IS_ATOM_INT(_5659))
        _5655 = (_5659 != 0);
    else
        _5655 = DBL_PTR(_5659)->dbl != 0.0;
L1:
    if (_5655 == 0) {
        goto L2;
    }
    DeRef(_5655);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5655 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5655);
    _0 = _5655;
    _2 = (int)SEQ_PTR(_5655);
    _5655 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_5655);
    DeRefDS(_0);
    DeRef(_5665);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5665 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_5665);
    _0 = _5665;
    _2 = (int)SEQ_PTR(_5665);
    _5665 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_5665);
    DeRefDS(_0);
    _0 = _5665;
    if (IS_ATOM_INT(_5655) && IS_ATOM_INT(_5665)) {
        _5665 = (_5655 < _5665);
    }
    else {
        _5665 = binary_op(LESS, _5655, _5665);
    }
    DeRef(_0);
L3:
    if (_5665 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_5665) && DBL_PTR(_5665)->dbl == 0.0)
            goto L2;
    }

    // 	return TRUE
    DeRef(_5665);
    DeRef(_5655);
    DeRef(_5659);
    return 1;
    goto L4;
L2:

    // 	return FALSE
    DeRef(_5665);
    DeRef(_5655);
    DeRef(_5659);
    return 0;
L4:
    ;
}


int _18CRef(int _v)
{
    int _5668 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_v)) {
        _1 = (long)(DBL_PTR(_v)->dbl);
        DeRefDS(_v);
        _v = _1;
    }

    //     if TypeIs(v, TYPE_INTEGER) then 
    _5668 = _16TypeIs(_v, 1);
    if (_5668 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_5668) && DBL_PTR(_5668)->dbl == 0.0)
            goto L1;
    }

    // 	return
    DeRef(_5668);
    return 0;
L1:

    //     if TypeIs(v, {TYPE_DOUBLE, TYPE_SEQUENCE}) then
    RefDS(_5669);
    _0 = _5668;
    _5668 = _16TypeIs(_v, _5669);
    DeRef(_0);
    if (_5668 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_5668) && DBL_PTR(_5668)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt0("RefDS(")
    RefDS(_5671);
    _16c_stmt0(_5671);
    goto L3;
L2:

    // 	c_stmt0("Ref(") -- TYPE_ATOM, TYPE_OBJECT
    RefDS(_5672);
    _16c_stmt0(_5672);
L3:

    //     LeftSym = TRUE
    _16LeftSym = 1;

    //     CName(v)
    _16CName(_v);

    //     c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);

    // end procedure
    DeRef(_5668);
    return 0;
    ;
}


int _18CRefn(int _v, int _n)
{
    int _5673 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_v)) {
        _1 = (long)(DBL_PTR(_v)->dbl);
        DeRefDS(_v);
        _v = _1;
    }
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     if TypeIs(v, TYPE_INTEGER) then 
    _5673 = _16TypeIs(_v, 1);
    if (_5673 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_5673) && DBL_PTR(_5673)->dbl == 0.0)
            goto L1;
    }

    // 	return
    DeRef(_5673);
    return 0;
L1:

    //     if TypeIs(v, {TYPE_DOUBLE, TYPE_SEQUENCE}) then
    RefDS(_5669);
    _0 = _5673;
    _5673 = _16TypeIs(_v, _5669);
    DeRef(_0);
    if (_5673 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_5673) && DBL_PTR(_5673)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt0("RefDSn(")
    RefDS(_5675);
    _16c_stmt0(_5675);
    goto L3;
L2:

    // 	c_stmt0("Refn(") -- TYPE_ATOM, TYPE_OBJECT
    RefDS(_5676);
    _16c_stmt0(_5676);
L3:

    //     LeftSym = TRUE
    _16LeftSym = 1;

    //     CName(v)
    _16CName(_v);

    //     c_printf(", %d);\n", n)
    RefDS(_5677);
    _9c_printf(_5677, _n);

    // end procedure
    DeRef(_5673);
    return 0;
    ;
}


int _18target_differs(int _target, int _opnd1, int _opnd2, int _opnd3)
{
    int _5693 = 0;
    int _5682 = 0;
    int _5678 = 0;
    int _5701 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_target)) {
        _1 = (long)(DBL_PTR(_target)->dbl);
        DeRefDS(_target);
        _target = _1;
    }
    if (!IS_ATOM_INT(_opnd1)) {
        _1 = (long)(DBL_PTR(_opnd1)->dbl);
        DeRefDS(_opnd1);
        _opnd1 = _1;
    }
    if (!IS_ATOM_INT(_opnd2)) {
        _1 = (long)(DBL_PTR(_opnd2)->dbl);
        DeRefDS(_opnd2);
        _opnd2 = _1;
    }
    if (!IS_ATOM_INT(_opnd3)) {
        _1 = (long)(DBL_PTR(_opnd3)->dbl);
        DeRefDS(_opnd3);
        _opnd3 = _1;
    }

    //     if SymTab[target][S_MODE] = M_NORMAL then
    _2 = (int)SEQ_PTR(_4SymTab);
    _5678 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_5678);
    _0 = _5678;
    _2 = (int)SEQ_PTR(_5678);
    _5678 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5678);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5678, 1))
        goto L1;

    // 	return target != opnd1 and target != opnd2 and target != opnd3
    DeRef(_5678);
    _5678 = (_target != _opnd1);
    _5682 = (_target != _opnd2);
    _5682 = (_5678 != 0 && _5682 != 0);
    _5678 = (_target != _opnd3);
    _5678 = (_5682 != 0 && _5678 != 0);
    return _5678;
    goto L2;
L1:

    //     elsif SymTab[target][S_MODE] = M_TEMP then
    DeRef(_5678);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5678 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_5678);
    _0 = _5678;
    _2 = (int)SEQ_PTR(_5678);
    _5678 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5678);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5678, 3))
        goto L3;

    // 	if (opnd1 = 0 or
    DeRef(_5678);
    _5678 = (_opnd1 == 0);
    if (_5678 != 0) {
        _5678 = 1;
        goto L4;
    }
    DeRef(_5682);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5682 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_5682);
    _0 = _5682;
    _2 = (int)SEQ_PTR(_5682);
    _5682 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5682);
    DeRefDS(_0);
    DeRef(_5693);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5693 = (int)*(((s1_ptr)_2)->base + _opnd1);
    RefDS(_5693);
    _0 = _5693;
    _2 = (int)SEQ_PTR(_5693);
    _5693 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5693);
    DeRefDS(_0);
    _0 = _5693;
    if (IS_ATOM_INT(_5682) && IS_ATOM_INT(_5693)) {
        _5693 = (_5682 != _5693);
    }
    else {
        _5693 = binary_op(NOTEQ, _5682, _5693);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5693))
        _5678 = (_5693 != 0);
    else
        _5678 = DBL_PTR(_5693)->dbl != 0.0;
L4:
    if (_5678 == 0) {
        DeRef(_5693);
        _5693 = 0;
        goto L5;
    }
    DeRef(_5682);
    _5682 = (_opnd2 == 0);
    if (_5682 != 0) {
        _5682 = 1;
        goto L6;
    }
    DeRef(_5678);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5678 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_5678);
    _0 = _5678;
    _2 = (int)SEQ_PTR(_5678);
    _5678 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5678);
    DeRefDS(_0);
    DeRef(_5701);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5701 = (int)*(((s1_ptr)_2)->base + _opnd2);
    RefDS(_5701);
    _0 = _5701;
    _2 = (int)SEQ_PTR(_5701);
    _5701 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5701);
    DeRefDS(_0);
    _0 = _5701;
    if (IS_ATOM_INT(_5678) && IS_ATOM_INT(_5701)) {
        _5701 = (_5678 != _5701);
    }
    else {
        _5701 = binary_op(NOTEQ, _5678, _5701);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5701))
        _5682 = (_5701 != 0);
    else
        _5682 = DBL_PTR(_5701)->dbl != 0.0;
L6:
    DeRef(_5693);
    _5693 = (_5682 != 0);
L5:
    if (_5693 == 0) {
        goto L7;
    }
    DeRef(_5678);
    _5678 = (_opnd3 == 0);
    if (_5678 != 0) {
        _5678 = 1;
        goto L8;
    }
    DeRef(_5682);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5682 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_5682);
    _0 = _5682;
    _2 = (int)SEQ_PTR(_5682);
    _5682 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5682);
    DeRefDS(_0);
    DeRef(_5693);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5693 = (int)*(((s1_ptr)_2)->base + _opnd3);
    RefDS(_5693);
    _0 = _5693;
    _2 = (int)SEQ_PTR(_5693);
    _5693 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_5693);
    DeRefDS(_0);
    _0 = _5693;
    if (IS_ATOM_INT(_5682) && IS_ATOM_INT(_5693)) {
        _5693 = (_5682 != _5693);
    }
    else {
        _5693 = binary_op(NOTEQ, _5682, _5693);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5693))
        _5678 = (_5693 != 0);
    else
        _5678 = DBL_PTR(_5693)->dbl != 0.0;
L8:
L9:
    if (_5678 == 0)
        goto L7;

    // 	    return TRUE
    DeRef(_5693);
    DeRef(_5682);
    DeRef(_5678);
    DeRef(_5701);
    return 1;
    goto L2;
L7:

    // 	    return FALSE
    DeRef(_5693);
    DeRef(_5682);
    DeRef(_5678);
    DeRef(_5701);
    return 0;
LA:
    goto L2;
L3:

    // 	return FALSE
    DeRef(_5693);
    DeRef(_5682);
    DeRef(_5678);
    DeRef(_5701);
    return 0;
L2:
    ;
}


int _18CSaveStr(int _target, int _v, int _a, int _b, int _c)
{
    int _deref_exist;
    int _5730 = 0;
    int _5712 = 0;
    int _5725;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_v)) {
        _1 = (long)(DBL_PTR(_v)->dbl);
        DeRefDS(_v);
        _v = _1;
    }
    if (!IS_ATOM_INT(_a)) {
        _1 = (long)(DBL_PTR(_a)->dbl);
        DeRefDS(_a);
        _a = _1;
    }
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }
    if (!IS_ATOM_INT(_c)) {
        _1 = (long)(DBL_PTR(_c)->dbl);
        DeRefDS(_c);
        _c = _1;
    }

    //     deref_str = target
    RefDS(_target);
    DeRef(_18deref_str);
    _18deref_str = _target;

    //     deref_exist = FALSE
    _deref_exist = 0;

    //     if SymTab[v][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _5712 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5712);
    _0 = _5712;
    _2 = (int)SEQ_PTR(_5712);
    _5712 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5712);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5712, 3))
        goto L1;

    // 	deref_type = BB_temp_type(v)
    _0 = _18BB_temp_type(_v);
    _18deref_type = _0;

    // 	deref_elem_type = BB_temp_elem(v)
    _0 = _18BB_temp_elem(_v);
    _18deref_elem_type = _0;
    goto L2;
L1:

    //     elsif SymTab[v][S_MODE] = M_NORMAL then 
    DeRef(_5712);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5712 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5712);
    _0 = _5712;
    _2 = (int)SEQ_PTR(_5712);
    _5712 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5712);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5712, 1))
        goto L3;

    // 	deref_type = GType(v)
    _0 = _16GType(_v);
    _18deref_type = _0;

    // 	if deref_type != TYPE_INTEGER then
    if (_18deref_type == 1)
        goto L4;

    // 	    deref_exist = BB_exist(v)
    _deref_exist = _18BB_exist(_v);
L4:

    // 	deref_elem_type = SeqElem(v)
    _0 = _18SeqElem(_v);
    _18deref_elem_type = _0;
    goto L2;
L3:

    // 	deref_type = TYPE_INTEGER
    _18deref_type = 1;
L2:

    //     deref_short = (deref_type = TYPE_DOUBLE or 
    DeRef(_5712);
    _5712 = (_18deref_type == 2);
    _5725 = (_18deref_type == 8);
    _5725 = (_5712 != 0 || _5725 != 0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5712 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5712);
    _0 = _5712;
    _2 = (int)SEQ_PTR(_5712);
    _5712 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5712);
    DeRefDS(_0);
    _0 = _5712;
    if (IS_ATOM_INT(_5712)) {
        _5712 = (_5712 == 3);
    }
    else {
        _5712 = binary_op(EQUALS, _5712, 3);
    }
    DeRef(_0);
    _0 = _5730;
    _5730 = _18IsParameter(_v);
    DeRef(_0);
    if (IS_ATOM_INT(_5712)) {
        _5730 = (_5712 != 0 || _5730 != 0);
    }
    else {
        _5730 = binary_op(OR, _5712, _5730);
    }
    _0 = _5730;
    if (IS_ATOM_INT(_5730)) {
        _5730 = (_5730 != 0 || _deref_exist != 0);
    }
    else {
        _5730 = binary_op(OR, _5730, _deref_exist);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5730)) {
        _18deref_short = (_5725 != 0 && _5730 != 0);
    }
    else {
        _18deref_short = binary_op(AND, _5725, _5730);
    }
    if (!IS_ATOM_INT(_18deref_short)) {
        _1 = (long)(DBL_PTR(_18deref_short)->dbl);
        DeRefDS(_18deref_short);
        _18deref_short = _1;
    }

    //     if deref_type != TYPE_INTEGER then
    if (_18deref_type == 1)
        goto L5;

    // 	if target_differs(v, a, b, c) then
    _0 = _5730;
    _5730 = _18target_differs(_v, _a, _b, _c);
    DeRef(_0);
    if (_5730 == 0)
        goto L6;

    // 	    if savespace() then
    _5730 = _18savespace();
    if (_5730 == 0)
        goto L7;

    // 		c_stmt0("DeRef1(")  -- less machine code
    RefDS(_5737);
    _16c_stmt0(_5737);
    goto L8;
L7:

    // 		if deref_short then 
    if (_18deref_short == 0)
        goto L9;

    // 		    if deref_elem_type = TYPE_INTEGER then  -- could do all-sequence/all-double dref later
    if (_18deref_elem_type != 1)
        goto LA;

    // 			c_stmt0("DeRefDSi(")
    RefDS(_5739);
    _16c_stmt0(_5739);
    goto LB;
LA:

    // 			c_stmt0("DeRefDS(")
    RefDS(_5740);
    _16c_stmt0(_5740);
LC:
    goto LB;
L9:

    // 		    if deref_elem_type = TYPE_INTEGER then
    if (_18deref_elem_type != 1)
        goto LD;

    // 			c_stmt0("DeRefi(")
    RefDS(_5742);
    _16c_stmt0(_5742);
    goto LE;
LD:

    // 			c_stmt0("DeRef(")
    RefDS(_5743);
    _16c_stmt0(_5743);
LE:
LB:
L8:

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    CName(v)
    _16CName(_v);

    // 	    c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);

    // 	    deref_str = ""  -- cancel it
    RefDS(_39);
    DeRef(_18deref_str);
    _18deref_str = _39;
    goto LF;
L6:

    // 	    c_stmt0(target)
    RefDS(_target);
    _16c_stmt0(_target);

    // 	    c_puts(" = ")
    RefDS(_5744);
    _9c_puts(_5744);

    // 	    CName(v)
    _16CName(_v);

    // 	    c_puts(";\n")
    RefDS(_4460);
    _9c_puts(_4460);
LF:
L5:

    // end procedure                               
    DeRefDS(_target);
    DeRef(_5730);
    DeRef(_5712);
    return 0;
    ;
}


int _18CDeRefStr(int _s)
{
    int _5745;
    int _0, _1, _2;
    

    //     if length(deref_str) = 0 then
    _5745 = SEQ_PTR(_18deref_str)->length;
    if (_5745 != 0)
        goto L1;

    // 	return
    DeRefDS(_s);
    return 0;
L1:

    //     if not equal(s, deref_str) then
    if (_s == _18deref_str)
        _5745 = 1;
    else if (IS_ATOM_INT(_s) && IS_ATOM_INT(_18deref_str))
        _5745 = 0;
    else
        _5745 = (compare(_s, _18deref_str) == 0);
    if (_5745 != 0)
        goto L2;

    // 	CompileErr("internal: deref problem")
    RefDS(_5749);
    _6CompileErr(_5749);
L2:

    //     if deref_type != TYPE_INTEGER then
    if (_18deref_type == 1)
        goto L3;

    // 	if savespace() then
    _5745 = _18savespace();
    if (_5745 == 0)
        goto L4;

    // 	    c_stmt0("DeRef1(")  -- less machine code
    RefDS(_5737);
    _16c_stmt0(_5737);
    goto L5;
L4:

    // 	    if deref_short then
    if (_18deref_short == 0)
        goto L6;

    // 		if deref_elem_type = TYPE_INTEGER then 
    if (_18deref_elem_type != 1)
        goto L7;

    // 		    c_stmt0("DeRefDSi(")
    RefDS(_5739);
    _16c_stmt0(_5739);
    goto L8;
L7:

    // 		    c_stmt0("DeRefDS(")
    RefDS(_5740);
    _16c_stmt0(_5740);
L9:
    goto L8;
L6:

    // 		if deref_elem_type = TYPE_INTEGER then
    if (_18deref_elem_type != 1)
        goto LA;

    // 		    c_stmt0("DeRefi(")
    RefDS(_5742);
    _16c_stmt0(_5742);
    goto LB;
LA:

    // 		    c_stmt0("DeRef(")
    RefDS(_5743);
    _16c_stmt0(_5743);
LB:
L8:
L5:

    // 	c_puts(s)
    RefDS(_s);
    _9c_puts(_s);

    // 	c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);
L3:

    // end procedure
    DeRefDS(_s);
    return 0;
    ;
}


int _18CDeRef(int _v)
{
    int _temp_type;
    int _elem_type;
    int _5771;
    int _5754 = 0;
    int _5763 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_v)) {
        _1 = (long)(DBL_PTR(_v)->dbl);
        DeRefDS(_v);
        _v = _1;
    }

    //     if SymTab[v][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _5754 = (int)*(((s1_ptr)_2)->base + _v);
    RefDS(_5754);
    _0 = _5754;
    _2 = (int)SEQ_PTR(_5754);
    _5754 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_5754);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _5754, 3))
        goto L1;

    // 	temp_type = BB_temp_type(v)
    _temp_type = _18BB_temp_type(_v);

    // 	elem_type = BB_temp_elem(v)
    _elem_type = _18BB_temp_elem(_v);

    // 	if temp_type = TYPE_INTEGER then
    if (_temp_type != 1)
        goto L2;

    // 	    return
    DeRef(_5754);
    return 0;
L2:

    // 	if savespace() then
    _0 = _5754;
    _5754 = _18savespace();
    DeRef(_0);
    if (_5754 == 0)
        goto L3;

    // 	    c_stmt0("DeRef1(")  -- less machine code
    RefDS(_5737);
    _16c_stmt0(_5737);
    goto L4;
L3:

    // 	    if temp_type = TYPE_DOUBLE or 
    DeRef(_5754);
    _5754 = (_temp_type == 2);
    if (_5754 != 0) {
        goto L5;
    }
    DeRef(_5763);
    _5763 = (_temp_type == 8);
L6:
    if (_5763 == 0)
        goto L7;
L5:

    // 		c_stmt0("DeRefDS(")
    RefDS(_5740);
    _16c_stmt0(_5740);
    goto L4;
L7:

    // 		c_stmt0("DeRef(")  -- TYPE_ATOM, TYPE_OBJECT, TYPE_NULL
    RefDS(_5743);
    _16c_stmt0(_5743);
L8:
L9:
    goto L4;
L1:

    // 	if TypeIs(v, TYPE_INTEGER) then 
    _0 = _5763;
    _5763 = _16TypeIs(_v, 1);
    DeRef(_0);
    if (_5763 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_5763) && DBL_PTR(_5763)->dbl == 0.0)
            goto LA;
    }

    // 	    return
    DeRef(_5754);
    DeRef(_5763);
    return 0;
LA:

    // 	elem_type = SeqElem(v)
    _elem_type = _18SeqElem(_v);

    // 	if savespace() then
    _0 = _5763;
    _5763 = _18savespace();
    DeRef(_0);
    if (_5763 == 0)
        goto LB;

    // 	    c_stmt0("DeRef1(")  -- less machine code
    RefDS(_5737);
    _16c_stmt0(_5737);
    goto LC;
LB:

    // 	    if TypeIs(v, {TYPE_DOUBLE, TYPE_SEQUENCE}) and
    RefDS(_5669);
    _0 = _5763;
    _5763 = _16TypeIs(_v, _5669);
    DeRef(_0);
    if (IS_ATOM_INT(_5763)) {
        if (_5763 == 0) {
            goto LD;
        }
    }
    else {
        if (DBL_PTR(_5763)->dbl == 0.0) {
            goto LD;
        }
    }
    _0 = _5754;
    _5754 = _18IsParameter(_v);
    DeRef(_0);
    if (_5754 != 0) {
        _5754 = 1;
        goto LE;
    }
    _5771 = _18BB_exist(_v);
    _5754 = (_5771 != 0);
LE:
LF:
    if (_5754 == 0)
        goto LD;

    // 		if elem_type = TYPE_INTEGER then
    if (_elem_type != 1)
        goto L10;

    // 		    c_stmt0("DeRefDSi(")
    RefDS(_5739);
    _16c_stmt0(_5739);
    goto L11;
L10:

    // 		    c_stmt0("DeRefDS(")
    RefDS(_5740);
    _16c_stmt0(_5740);
L12:
    goto L11;
LD:

    // 		if elem_type = TYPE_INTEGER then
    if (_elem_type != 1)
        goto L13;

    // 		    c_stmt0("DeRefi(")
    RefDS(_5742);
    _16c_stmt0(_5742);
    goto L14;
L13:

    // 		    c_stmt0("DeRef(")
    RefDS(_5743);
    _16c_stmt0(_5743);
L14:
L11:
LC:
L4:

    //     LeftSym = TRUE
    _16LeftSym = 1;

    //     CName(v)
    _16CName(_v);

    //     c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);

    // end procedure
    DeRef(_5754);
    DeRef(_5763);
    return 0;
    ;
}


int _18CUnaryOp(int _pc, int _op_int, int _op_gen)
{
    int _target_type;
    int _5777 = 0;
    int _5775 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _5775 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5775 = (int)*(((s1_ptr)_2)->base + _5775);
    Ref(_5775);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5774);
    Ref(_5775);
    Ref(_5777);
    _18CSaveStr(_5774, _5775, _5777, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    RefDS(_5781);
    _0 = _5777;
    _5777 = _16TypeIs(_5777, _5781);
    DeRef(_0);
    if (_5777 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_5777) && DBL_PTR(_5777)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5783);
    Ref(_5777);
    _16c_stmt(_5783, _5777);
L1:

    //     if TypeIsNot(Code[pc+1], {TYPE_DOUBLE, TYPE_SEQUENCE}) then
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    RefDS(_5669);
    _0 = _5777;
    _5777 = _16TypeIsNot(_5777, _5669);
    DeRef(_0);
    if (_5777 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_5777) && DBL_PTR(_5777)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("@ = ", Code[pc+2])
    DeRef(_5777);
    _5777 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5789);
    Ref(_5777);
    _16c_stmt(_5789, _5777);

    // 	c_puts(op_int)
    RefDS(_op_int);
    _9c_puts(_op_int);

    // 	temp_indent = -indent
    _9temp_indent = - _9indent;

    // 	c_stmt("(@);\n", Code[pc+1])
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5793);
    Ref(_5777);
    _16c_stmt(_5793, _5777);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    RefDS(_5781);
    _0 = _5777;
    _5777 = _16TypeIs(_5777, _5781);
    DeRef(_0);
    if (_5777 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_5777) && DBL_PTR(_5777)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L3:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    _0 = _5777;
    _5777 = _16TypeIsNot(_5777, 1);
    DeRef(_0);
    if (_5777 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_5777) && DBL_PTR(_5777)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt("@ = unary_op(", Code[pc+2])
    DeRef(_5777);
    _5777 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5803);
    Ref(_5777);
    _16c_stmt(_5803, _5777);

    // 	c_puts(op_gen)
    RefDS(_op_gen);
    _9c_puts(_op_gen);

    // 	temp_indent = -indent
    _9temp_indent = - _9indent;

    // 	c_stmt(", @);\n", Code[pc+1])
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    RefDS(_5807);
    Ref(_5777);
    _16c_stmt(_5807, _5777);
L4:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    _0 = _5777;
    _5777 = _16TypeIs(_5777, 1);
    DeRef(_0);
    if (_5777 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_5777) && DBL_PTR(_5777)->dbl == 0.0)
            goto L5;
    }

    // 	target_type = TYPE_ATOM
    _target_type = 4;
    goto L6;
L5:

    // 	target_type = GType(Code[pc+1])
    DeRef(_5777);
    _5777 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    _target_type = _16GType(_5777);
L6:

    //     SetBBType(Code[pc+2], target_type, novalue, TYPE_OBJECT)
    DeRef(_5777);
    _5777 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5777 = (int)*(((s1_ptr)_2)->base + _5777);
    Ref(_5777);
    Ref(_5777);
    RefDS(_9novalue);
    _16SetBBType(_5777, _target_type, _9novalue, 16);

    // end procedure
    DeRefDS(_op_int);
    DeRefDS(_op_gen);
    DeRef(_5777);
    DeRef(_5775);
    return 0;
    ;
}


int _18seg_peek1(int _target, int _source, int _mode)
{
    int _5818 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_target)) {
        _1 = (long)(DBL_PTR(_target)->dbl);
        DeRefDS(_target);
        _target = _1;
    }
    if (!IS_ATOM_INT(_source)) {
        _1 = (long)(DBL_PTR(_source)->dbl);
        DeRefDS(_source);
        _source = _1;
    }
    if (!IS_ATOM_INT(_mode)) {
        _1 = (long)(DBL_PTR(_mode)->dbl);
        DeRefDS(_mode);
        _mode = _1;
    }

    //     if atom(dj_path) then
    _5818 = IS_ATOM(_4dj_path);
    if (_5818 == 0)
        goto L1;

    // 	if mode = 1 then
    if (_mode != 1)
        goto L2;

    // 	    c_stmt("@ = *(unsigned char *)(unsigned long)(DBL_PTR(@)->dbl);\n",
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5818 = MAKE_SEQ(_1);
    RefDS(_5820);
    RefDS(_5818);
    _16c_stmt(_5820, _5818);
    goto L3;
L2:

    // 	    c_stmt("@ = *(unsigned char *)@;\n", {target, source})
    DeRef(_5818);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5818 = MAKE_SEQ(_1);
    RefDS(_5822);
    RefDS(_5818);
    _16c_stmt(_5822, _5818);
L4:
    goto L3;
L1:

    // 	if mode = 1 then
    if (_mode != 1)
        goto L5;

    // 	    c_stmt("_1 = (int)(unsigned)DBL_PTR(@)->dbl;\n", source)
    RefDS(_5825);
    _16c_stmt(_5825, _source);

    // 	    c_stmt0("if ((unsigned)_1 > LOW_MEMORY_MAX)\n")
    RefDS(_5826);
    _16c_stmt0(_5826);

    // 	    c_stmt("@ = *(unsigned char *)_1;\n", target)
    RefDS(_5827);
    _16c_stmt(_5827, _target);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("@ = _farpeekb(_go32_info_block.selector_for_linear_memory, (unsigned)_1);\n", 
    RefDS(_5828);
    _16c_stmt(_5828, _target);
    goto L6;
L5:

    // 	elsif mode = 2 then
    if (_mode != 2)
        goto L7;
    goto L6;
L7:

    // 	    c_stmt("if ((unsigned)@ > LOW_MEMORY_MAX)\n", source)
    RefDS(_5830);
    _16c_stmt(_5830, _source);

    // 	    c_stmt("@ = *(unsigned char *)@;\n", {target, source})
    DeRef(_5818);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5818 = MAKE_SEQ(_1);
    RefDS(_5822);
    RefDS(_5818);
    _16c_stmt(_5822, _5818);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    c_stmt("@ = _farpeekb(_go32_info_block.selector_for_linear_memory, (unsigned)@);\n", 
    DeRefDSi(_5818);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _target;
    ((int *)_2)[2] = _source;
    _5818 = MAKE_SEQ(_1);
    RefDS(_5832);
    RefDS(_5818);
    _16c_stmt(_5832, _5818);
L6:
L3:

    // end procedure
    DeRef(_5818);
    return 0;
    ;
}


