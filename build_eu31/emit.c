// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _14Push(int _x)
{
    int _0, _1, _2;
    

    //     cg_stack = append(cg_stack, x)
    Append(&_14cg_stack, _14cg_stack, _x);

    // end procedure
    return 0;
    ;
}


int _14Top()
{
    int _2345;
    int _0, _1, _2;
    

    //     return cg_stack[$]
    _2345 = SEQ_PTR(_14cg_stack)->length;
    _2 = (int)SEQ_PTR(_14cg_stack);
    _2345 = (int)*(((s1_ptr)_2)->base + _2345);
    return _2345;
    ;
}


int _14Pop()
{
    int _t;
    int _2347 = 0;
    int _0, _1, _2, _3;
    

    //     t = cg_stack[$]
    _2347 = SEQ_PTR(_14cg_stack)->length;
    _2 = (int)SEQ_PTR(_14cg_stack);
    _t = (int)*(((s1_ptr)_2)->base + _2347);

    //     cg_stack = cg_stack[1..$-1]
    _2347 = SEQ_PTR(_14cg_stack)->length;
    _2347 = _2347 - 1;
    rhs_slice_target = (object_ptr)&_14cg_stack;
    RHS_Slice((s1_ptr)_14cg_stack, 1, _2347);

    //     if SymTab[t][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _2347 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_2347);
    _0 = _2347;
    _2 = (int)SEQ_PTR(_2347);
    _2347 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2347);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _2347, 3))
        goto L1;

    // 	SymTab[t][S_SCOPE] = FREE -- mark it as being free
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_t + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L1:

    //     return t    
    DeRef(_2347);
    return _t;
    ;
}


int _14TempKeep(int _x)
{
    int _2357 = 0;
    int _0, _1, _2, _3;
    

    //     if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _2357 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_2357);
    _0 = _2357;
    _2 = (int)SEQ_PTR(_2357);
    _2357 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2357);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _2357, 3))
        goto L1;

    // 	SymTab[x][S_SCOPE] = IN_USE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2357);
    return 0;
    ;
}


int _14TempFree(int _x)
{
    int _2362 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_x)) {
        _1 = (long)(DBL_PTR(_x)->dbl);
        DeRefDS(_x);
        _x = _1;
    }

    //    if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _2362 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_2362);
    _0 = _2362;
    _2 = (int)SEQ_PTR(_2362);
    _2362 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2362);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _2362, 3))
        goto L1;

    //        SymTab[x][S_SCOPE] = FREE 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2362);
    return 0;
    ;
}


int _14TempInteger(int _x)
{
    int _2367 = 0;
    int _0, _1, _2, _3;
    

    //     if SymTab[x][S_MODE] = M_TEMP then
    _2 = (int)SEQ_PTR(_4SymTab);
    _2367 = (int)*(((s1_ptr)_2)->base + _x);
    RefDS(_2367);
    _0 = _2367;
    _2 = (int)SEQ_PTR(_2367);
    _2367 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2367);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _2367, 3))
        goto L1;

    // 	SymTab[x][S_USAGE] = T_INTEGER
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_x + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L1:

    // end procedure
    DeRef(_2367);
    return 0;
    ;
}


int _14LexName(int _t)
{
    int _i;
    int _2375 = 0;
    int _2372;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_t)) {
        _1 = (long)(DBL_PTR(_t)->dbl);
        DeRefDS(_t);
        _t = _1;
    }

    //     i = 1
    _i = 1;

    //     while i <= length(token_name) and t != token_name[i][LEX_NUMBER] do
L1:
    _2372 = 59;
    _2372 = (_i <= 59);
    if (_2372 == 0) {
        goto L2;
    }
    DeRef(_2375);
    _2 = (int)SEQ_PTR(_14token_name);
    _2375 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_2375);
    _0 = _2375;
    _2 = (int)SEQ_PTR(_2375);
    _2375 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2375);
    DeRefDS(_0);
    _0 = _2375;
    if (IS_ATOM_INT(_2375)) {
        _2375 = (_t != _2375);
    }
    else {
        _2375 = binary_op(NOTEQ, _t, _2375);
    }
    DeRef(_0);
L3:
    if (_2375 <= 0) {
        if (_2375 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_2375) && DBL_PTR(_2375)->dbl == 0.0)
                goto L2;
        }
    }

    // 	i += 1
    _i = _i + 1;

    //     end while
    goto L1;
L2:

    //     if i > length(token_name) then
    DeRef(_2375);
    _2375 = 59;
    if (_i <= 59)
        goto L4;

    // 	return "this ..." -- try to avoid this case 
    RefDS(_2381);
    return _2381;
    goto L5;
L4:

    // 	return token_name[i][LEX_NAME]
    DeRef(_2375);
    _2 = (int)SEQ_PTR(_14token_name);
    _2375 = (int)*(((s1_ptr)_2)->base + _i);
    RefDS(_2375);
    _0 = _2375;
    _2 = (int)SEQ_PTR(_2375);
    _2375 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2375);
    DeRefDS(_0);
    return _2375;
L5:
    ;
}


int _14InitEmit()
{
    int _0, _1, _2;
    

    //     cg_stack = {}
    RefDS(_39);
    DeRefi(_14cg_stack);
    _14cg_stack = _39;

    // end procedure
    return 0;
    ;
}


int _14IsInteger(int _sym)
{
    int _mode;
    int _t;
    int _pt;
    int _2393 = 0;
    int _2384 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    //     mode = SymTab[sym][S_MODE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _2384 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_2384);
    _2 = (int)SEQ_PTR(_2384);
    _mode = (int)*(((s1_ptr)_2)->base + 3);
    if (!IS_ATOM_INT(_mode))
        _mode = (long)DBL_PTR(_mode)->dbl;

    //     if mode = M_NORMAL then
    if (_mode != 1)
        goto L1;

    // 	t = SymTab[sym][S_VTYPE] 
    DeRefDS(_2384);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2384 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_2384);
    _2 = (int)SEQ_PTR(_2384);
    _t = (int)*(((s1_ptr)_2)->base + 14);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    // 	if t = integer_type then
    if (_t != _10integer_type)
        goto L2;

    // 	    return TRUE
    DeRefDS(_2384);
    return 1;
L2:

    // 	if t then
    if (_t == 0)
        goto L3;

    // 	    pt = SymTab[t][S_NEXT]
    DeRef(_2384);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2384 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_2384);
    _2 = (int)SEQ_PTR(_2384);
    _pt = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_pt))
        _pt = (long)DBL_PTR(_pt)->dbl;

    // 	    if pt and SymTab[pt][S_VTYPE] = integer_type then
    if (_pt == 0) {
        goto L3;
    }
    DeRef(_2393);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2393 = (int)*(((s1_ptr)_2)->base + _pt);
    RefDS(_2393);
    _0 = _2393;
    _2 = (int)SEQ_PTR(_2393);
    _2393 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2393);
    DeRefDS(_0);
    _0 = _2393;
    if (IS_ATOM_INT(_2393)) {
        _2393 = (_2393 == _10integer_type);
    }
    else {
        _2393 = binary_op(EQUALS, _2393, _10integer_type);
    }
    DeRef(_0);
L4:
    if (_2393 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_2393) && DBL_PTR(_2393)->dbl == 0.0)
            goto L3;
    }

    // 		return TRUE   -- usertype(integer x)
    DeRef(_2393);
    DeRef(_2384);
    return 1;
L5:
L6:
    goto L3;
L1:

    //     elsif mode = M_CONSTANT then
    if (_mode != 2)
        goto L7;

    // 	if integer(SymTab[sym][S_OBJ]) then  -- bug fixed: can't allow PLUS1_I op 
    DeRef(_2393);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2393 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_2393);
    _0 = _2393;
    _2 = (int)SEQ_PTR(_2393);
    _2393 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2393);
    DeRefDS(_0);
    _0 = _2393;
    if (IS_ATOM_INT(_2393))
        _2393 = 1;
    else if (IS_ATOM_DBL(_2393))
        _2393 = IS_ATOM_INT(DoubleToInt(_2393));
    else
        _2393 = 0;
    DeRef(_0);
    if (_2393 == 0)
        goto L3;

    // 	    return TRUE
    DeRef(_2384);
    return 1;
L8:
    goto L3;
L7:

    //     elsif mode = M_TEMP then
    if (_mode != 3)
        goto L9;

    // 	if SymTab[sym][S_USAGE] = T_INTEGER then
    DeRef(_2393);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2393 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_2393);
    _0 = _2393;
    _2 = (int)SEQ_PTR(_2393);
    _2393 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_2393);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _2393, 1))
        goto LA;

    // 	    return TRUE
    DeRef(_2393);
    DeRef(_2384);
    return 1;
LA:
L9:
L3:

    //     return FALSE
    DeRef(_2393);
    DeRef(_2384);
    return 0;
    ;
}


int _14emit(int _val)
{
    int _0, _1, _2;
    

    //     Code = append(Code, val)
    Append(&_4Code, _4Code, _val);

    // end procedure
    return 0;
    ;
}


int _14emit_opnd(int _opnd)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_opnd)) {
        _1 = (long)(DBL_PTR(_opnd)->dbl);
        DeRefDS(_opnd);
        _opnd = _1;
    }

    //     Push(opnd)
    _14Push(_opnd);

    //     previous_op = -1  -- N.B.
    _14previous_op = -1;

    // end procedure
    return 0;
    ;
}


int _14emit_addr(int _x)
{
    int _0, _1, _2;
    

    //     Code = append(Code, x)
    Ref(_x);
    Append(&_4Code, _4Code, _x);

    // end procedure
    DeRef(_x);
    return 0;
    ;
}


int _14emit_opcode(int _op)
{
    int _0, _1, _2;
    

    //     Code = append(Code, op)
    Append(&_4Code, _4Code, _op);

    // end procedure
    return 0;
    ;
}


int _14backpatch(int _index, int _val)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_index)) {
        _1 = (long)(DBL_PTR(_index)->dbl);
        DeRefDS(_index);
        _index = _1;
    }
    if (!IS_ATOM_INT(_val)) {
        _1 = (long)(DBL_PTR(_val)->dbl);
        DeRefDS(_val);
        _val = _1;
    }

    //     Code[index] = val
    _2 = (int)SEQ_PTR(_4Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4Code = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _index);
    _1 = *(int *)_2;
    *(int *)_2 = _val;
    DeRef(_1);

    // end procedure
    return 0;
    ;
}


int _14cont11ii(int _op, int _ii)
{
    int _t;
    int _source;
    int _c;
    int _2413;
    int _2412;
    int _2408;
    int _0, _1, _2;
    

    //     emit_opcode(op)
    _14emit_opcode(_op);

    //     source = Pop()
    _source = _14Pop();

    //     emit_addr(source)
    _14emit_addr(_source);

    //     assignable = TRUE
    _14assignable = 1;

    //     t = op_result[op]
    _2 = (int)SEQ_PTR(_14op_result);
    _t = (int)*(((s1_ptr)_2)->base + _op);

    //     if t = T_INTEGER or (ii and IsInteger(source)) then
    _2408 = (_t == 1);
    if (_2408 != 0) {
        goto L1;
    }
    if (_ii == 0) {
        _2412 = 0;
        goto L2;
    }
    _2413 = _14IsInteger(_source);
    _2412 = (_2413 != 0);
L2:
L3:
    if (_2412 == 0)
        goto L4;
L1:

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	TempInteger(c)
    _14TempInteger(_c);
    goto L5;
L4:

    // 	c = NewTempSym() -- allocate *after* checking opnd type
    _c = _10NewTempSym();
L5:

    //     Push(c)
    _14Push(_c);

    //     emit_addr(c)
    _14emit_addr(_c);

    // end procedure
    return 0;
    ;
}


int _14cont21d(int _op, int _a, int _b, int _ii)
{
    int _c;
    int _t;
    int _2420;
    int _2421;
    int _2416;
    int _0, _1, _2;
    

    //     assignable = TRUE
    _14assignable = 1;

    //     t = op_result[op]
    _2 = (int)SEQ_PTR(_14op_result);
    _t = (int)*(((s1_ptr)_2)->base + _op);

    //     if op = C_FUNC then
    if (_op != 135)
        goto L1;

    // 	emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);
L1:

    //     if t = T_INTEGER or (ii and IsInteger(a) and IsInteger(b)) then
    _2416 = (_t == 1);
    if (_2416 != 0) {
        goto L2;
    }
    if (_ii == 0) {
        _2420 = 0;
        goto L3;
    }
    _2421 = _14IsInteger(_a);
    _2420 = (_2421 != 0);
L3:
    if (_2420 == 0) {
        _2421 = 0;
        goto L4;
    }
    _2420 = _14IsInteger(_b);
    _2421 = (_2420 != 0);
L4:
L5:
    if (_2421 == 0)
        goto L6;
L2:

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	TempInteger(c)
    _14TempInteger(_c);
    goto L7;
L6:

    // 	c = NewTempSym() -- allocate *after* checking opnd types
    _c = _10NewTempSym();
L7:

    //     Push(c)
    _14Push(_c);

    //     emit_addr(c)
    _14emit_addr(_c);

    // end procedure
    return 0;
    ;
}


int _14cont21ii(int _op, int _ii)
{
    int _a;
    int _b;
    int _0, _1, _2;
    

    //     b = Pop()
    _b = _14Pop();

    //     emit_opcode(op)
    _14emit_opcode(_op);

    //     a = Pop()
    _a = _14Pop();

    //     emit_addr(a)
    _14emit_addr(_a);

    //     emit_addr(b)
    _14emit_addr(_b);

    //     cont21d(op, a, b, ii)
    _14cont21d(_op, _a, _b, _ii);

    // end procedure
    return 0;
    ;
}


int _14good_string(int _elements)
{
    int _obj = 0;
    int _e;
    int _element_vals = 0;
    int _2445 = 0;
    int _2443 = 0;
    int _2428 = 0;
    int _2439;
    int _2429;
    int _0, _1, _2;
    

    //     if TRANSLATE and length(elements) > 10000 then
    if (0 == 0) {
        goto L1;
    }
    _2429 = SEQ_PTR(_elements)->length;
    _2429 = (_2429 > 10000);
L2:
    if (_2429 == 0)
        goto L1;

    // 	return -1 -- A huge string might upset the C compiler.
    DeRefDSi(_elements);
    DeRef(_obj);
    DeRef(_element_vals);
    DeRef(_2445);
    DeRef(_2443);
    DeRef(_2428);
    return -1;
L1:

    //     element_vals = {}
    RefDS(_39);
    DeRef(_element_vals);
    _element_vals = _39;

    //     for i = 1 to length(elements) do
    _2429 = SEQ_PTR(_elements)->length;
    { int _i;
        _i = 1;
L3:
        if (_i > _2429)
            goto L4;

        // 	e = elements[i]
        _2 = (int)SEQ_PTR(_elements);
        _e = (int)*(((s1_ptr)_2)->base + _i);

        // 	obj = SymTab[e][S_OBJ]
        DeRef(_2428);
        _2 = (int)SEQ_PTR(_4SymTab);
        _2428 = (int)*(((s1_ptr)_2)->base + _e);
        RefDS(_2428);
        DeRef(_obj);
        _2 = (int)SEQ_PTR(_2428);
        _obj = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_obj);

        // 	if SymTab[e][S_MODE] = M_CONSTANT and
        DeRefDS(_2428);
        _2 = (int)SEQ_PTR(_4SymTab);
        _2428 = (int)*(((s1_ptr)_2)->base + _e);
        RefDS(_2428);
        _0 = _2428;
        _2 = (int)SEQ_PTR(_2428);
        _2428 = (int)*(((s1_ptr)_2)->base + 3);
        Ref(_2428);
        DeRefDS(_0);
        _0 = _2428;
        if (IS_ATOM_INT(_2428)) {
            _2428 = (_2428 == 2);
        }
        else {
            _2428 = binary_op(EQUALS, _2428, 2);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_2428)) {
            if (_2428 == 0) {
                DeRef(_2428);
                _2428 = 0;
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_2428)->dbl == 0.0) {
                DeRef(_2428);
                _2428 = 0;
                goto L5;
            }
        }
        if (IS_ATOM_INT(_obj))
            _2439 = 1;
        else if (IS_ATOM_DBL(_obj))
            _2439 = IS_ATOM_INT(DoubleToInt(_obj));
        else
            _2439 = 0;
        DeRef(_2428);
        _2428 = (_2439 != 0);
L5:
        if (_2428 == 0) {
            goto L6;
        }
        DeRef(_2428);
        _2428 = (0 == 0);
        if (_2428 != 0) {
            _2428 = 1;
            goto L7;
        }
        DeRef(_2443);
        if (IS_ATOM_INT(_obj)) {
            _2443 = (_obj >= 1);
        }
        else {
            _2443 = binary_op(GREATEREQ, _obj, 1);
        }
        if (IS_ATOM_INT(_2443)) {
            if (_2443 == 0) {
                DeRef(_2443);
                _2443 = 0;
                goto L8;
            }
        }
        else {
            if (DBL_PTR(_2443)->dbl == 0.0) {
                DeRef(_2443);
                _2443 = 0;
                goto L8;
            }
        }
        DeRef(_2445);
        if (IS_ATOM_INT(_obj)) {
            _2445 = (_obj <= 255);
        }
        else {
            _2445 = binary_op(LESSEQ, _obj, 255);
        }
        DeRef(_2443);
        if (IS_ATOM_INT(_2445))
            _2443 = (_2445 != 0);
        else
            _2443 = DBL_PTR(_2445)->dbl != 0.0;
L8:
        DeRef(_2428);
        _2428 = (_2443 != 0);
L7:
L9:
        if (_2428 == 0)
            goto L6;

        // 	    element_vals = prepend(element_vals, obj)
        Ref(_obj);
        Prepend(&_element_vals, _element_vals, _obj);
        goto LA;
L6:

        // 	    return -1
        DeRefDSi(_elements);
        DeRef(_obj);
        DeRef(_element_vals);
        DeRef(_2445);
        DeRef(_2443);
        DeRef(_2428);
        return -1;
LA:

        //     end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    //     return element_vals
    DeRefDSi(_elements);
    DeRef(_obj);
    DeRef(_2445);
    DeRef(_2443);
    DeRef(_2428);
    return _element_vals;
    ;
}


