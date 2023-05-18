// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16opCALL_PROC()
{
    int _cf;
    int _n;
    int _arg;
    int _p;
    int _sub;
    int _private_block = 0;
    int _6033 = 0;
    int _6041 = 0;
    int _6040 = 0;
    int _0, _1, _2, _3;
    

    //     cf = Code[pc] = CALL_FUNC
    _2 = (int)SEQ_PTR(_4Code);
    _6033 = (int)*(((s1_ptr)_2)->base + _16pc);
    Ref(_6033);
    if (IS_ATOM_INT(_6033)) {
        _cf = (_6033 == 139);
    }
    else {
        _cf = binary_op(EQUALS, _6033, 139);
    }
    if (!IS_ATOM_INT(_cf)) {
        _1 = (long)(DBL_PTR(_cf)->dbl);
        DeRefDS(_cf);
        _cf = _1;
    }

    //     a = Code[pc+1]  -- routine id
    DeRef(_6033);
    _6033 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6033);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if val[a] < 0 or val[a] >= length(e_routine) then
    _2 = (int)SEQ_PTR(_16val);
    _6033 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6033);
    _0 = _6033;
    if (IS_ATOM_INT(_6033)) {
        _6033 = (_6033 < 0);
    }
    else {
        _6033 = binary_op(LESS, _6033, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6033)) {
        if (_6033 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_6033)->dbl != 0.0) {
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_16val);
    _6040 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6040);
    _6041 = SEQ_PTR(_16e_routine)->length;
    if (IS_ATOM_INT(_6040)) {
        _6041 = (_6040 >= _6041);
    }
    else {
        _6041 = binary_op(GREATEREQ, _6040, _6041);
    }
L2:
    if (_6041 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6041) && DBL_PTR(_6041)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	RTFatal("invalid routine id")
    RefDS(_4714);
    _16RTFatal(_4714);
L3:

    //     sub = e_routine[val[a]+1]
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_16val);
    _6041 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6041);
    _0 = _6041;
    if (IS_ATOM_INT(_6041)) {
        _6041 = _6041 + 1;
    }
    else
        _6041 = binary_op(PLUS, 1, _6041);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16e_routine);
    if (!IS_ATOM_INT(_6041))
        _sub = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6041)->dbl));
    else
        _sub = (int)*(((s1_ptr)_2)->base + _6041);

    //     b = Code[pc+2]  -- argument list
    DeRef(_6041);
    _6041 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6041);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if cf then
    if (_cf == 0)
        goto L4;

    // 	if SymTab[sub][S_TOKEN] = PROC then
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6041);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _6041, 27))
        goto L5;

    // 	    RTFatal(sprintf("%s() does not return a value", SymTab[sub][S_NAME]))
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6041);
    DeRefDS(_0);
    _0 = _6041;
    _6041 = EPrintf(-9999999, _6051, _6041);
    DeRef(_0);
    RefDS(_6041);
    _16RTFatal(_6041);
L6:
    goto L5;
L4:

    // 	if SymTab[sub][S_TOKEN] != PROC then
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6041);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _6041, 27))
        goto L7;

    // 	    RTFatal(sprintf("the value returned by %s() must be assigned or used",
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6041);
    DeRefDS(_0);
    _0 = _6041;
    _6041 = EPrintf(-9999999, _6058, _6041);
    DeRef(_0);
    RefDS(_6041);
    _16RTFatal(_6041);
L7:
L5:

    //     if atom(val[b]) then
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_16val);
    _6041 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6041);
    _0 = _6041;
    _6041 = IS_ATOM(_6041);
    DeRef(_0);
    if (_6041 == 0)
        goto L8;

    // 	RTFatal("argument list must be a sequence")
    RefDS(_6064);
    _16RTFatal(_6064);
L8:

    //     if SymTab[sub][S_NUM_ARGS] != length(val[b]) then
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6041);
    DeRefDS(_0);
    DeRef(_6040);
    _2 = (int)SEQ_PTR(_16val);
    _6040 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6040);
    _0 = _6040;
    _6040 = SEQ_PTR(_6040)->length;
    DeRef(_0);
    if (binary_op_a(EQUALS, _6041, _6040))
        goto L9;

    // 	RTFatal(sprintf("call to %s() via routine-id should pass %d arguments, not %d",
    _2 = (int)SEQ_PTR(_4SymTab);
    _6040 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6040);
    _0 = _6040;
    _2 = (int)SEQ_PTR(_6040);
    _6040 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_6040);
    DeRefDS(_0);
    DeRef(_6041);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6041 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6041);
    _0 = _6041;
    _2 = (int)SEQ_PTR(_6041);
    _6041 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6041);
    DeRefDS(_0);
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_16val);
    _6033 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6033);
    _0 = _6033;
    _6033 = SEQ_PTR(_6033)->length;
    DeRef(_0);
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6040);
    *((int *)(_2+4)) = _6040;
    Ref(_6041);
    *((int *)(_2+8)) = _6041;
    *((int *)(_2+12)) = _6033;
    _6033 = MAKE_SEQ(_1);
    _0 = _6033;
    _6033 = EPrintf(-9999999, _6070, _6033);
    DeRefDS(_0);
    RefDS(_6033);
    _16RTFatal(_6033);
L9:

    //     n = SymTab[sub][S_NUM_ARGS]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    _2 = (int)SEQ_PTR(_6033);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     arg = SymTab[sub][S_NEXT]
    DeRefDS(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    _2 = (int)SEQ_PTR(_6033);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    //     if SymTab[sub][S_RESIDENT_TASK] != 0 then
    DeRefDS(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    _0 = _6033;
    _2 = (int)SEQ_PTR(_6033);
    _6033 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_6033);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _6033, 0))
        goto LA;

    // 	private_block = repeat(0, SymTab[sub][S_STACK_SPACE])
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    _0 = _6033;
    _2 = (int)SEQ_PTR(_6033);
    _6033 = (int)*(((s1_ptr)_2)->base + 25);
    Ref(_6033);
    DeRefDS(_0);
    DeRef(_private_block);
    _private_block = Repeat(0, _6033);

    // 	p = 1
    _p = 1;

    // 	for i = 1 to n do
    DeRef(_6033);
    _6033 = _n;
    { int _i;
        _i = 1;
LB:
        if (_i > _6033)
            goto LC;

        // 	    private_block[p] = val[arg]
        DeRef(_6041);
        _2 = (int)SEQ_PTR(_16val);
        _6041 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_6041);
        Ref(_6041);
        _2 = (int)SEQ_PTR(_private_block);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _private_block = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _p);
        _1 = *(int *)_2;
        *(int *)_2 = _6041;
        DeRef(_1);

        // 	    p += 1
        _p = _p + 1;

        // 	    val[arg] = val[b][i]
        DeRef(_6041);
        _2 = (int)SEQ_PTR(_16val);
        _6041 = (int)*(((s1_ptr)_2)->base + _16b);
        Ref(_6041);
        _0 = _6041;
        _2 = (int)SEQ_PTR(_6041);
        _6041 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6041);
        DeRef(_0);
        Ref(_6041);
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _6041;
        DeRef(_1);

        // 	    arg = SymTab[arg][S_NEXT]
        DeRef(_6041);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6041 = (int)*(((s1_ptr)_2)->base + _arg);
        RefDS(_6041);
        _2 = (int)SEQ_PTR(_6041);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 	end for
        _i = _i + 1;
        goto LB;
LC:
        ;
    }

    // 	while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
LD:
    DeRef(_6041);
    _6041 = (_arg != 0);
    if (_6041 == 0) {
        goto LE;
    }
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_6033);
    _0 = _6033;
    _2 = (int)SEQ_PTR(_6033);
    _6033 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6033);
    DeRefDS(_0);
    _0 = _6033;
    if (IS_ATOM_INT(_6033)) {
        _6033 = (_6033 <= 3);
    }
    else {
        _6033 = binary_op(LESSEQ, _6033, 3);
    }
    DeRef(_0);
LF:
    if (_6033 <= 0) {
        if (_6033 == 0) {
            goto LE;
        }
        else {
            if (!IS_ATOM_INT(_6033) && DBL_PTR(_6033)->dbl == 0.0)
                goto LE;
        }
    }

    // 	    private_block[p] = val[arg]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_16val);
    _6033 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_6033);
    Ref(_6033);
    _2 = (int)SEQ_PTR(_private_block);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _private_block = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _6033;
    DeRef(_1);

    // 	    p += 1
    _p = _p + 1;

    // 	    val[arg] = NOVALUE -- necessary?
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_6033);
    _2 = (int)SEQ_PTR(_6033);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto LD;
LE:

    // 	arg = SymTab[sub][S_TEMPS]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    _2 = (int)SEQ_PTR(_6033);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	while arg != 0 do
L10:
    if (_arg == 0)
        goto L11;

    // 	    private_block[p] = val[arg]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_16val);
    _6033 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_6033);
    Ref(_6033);
    _2 = (int)SEQ_PTR(_private_block);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _private_block = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _6033;
    DeRef(_1);

    // 	    p += 1
    _p = _p + 1;

    // 	    val[arg] = NOVALUE -- necessary?
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_6033);
    _2 = (int)SEQ_PTR(_6033);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto L10;
L11:

    // 	save_private_block(sub, private_block)
    RefDS(_private_block);
    _16save_private_block(_sub, _private_block);
    goto L12;
LA:

    // 	for i = 1 to n do
    DeRef(_6033);
    _6033 = _n;
    { int _i;
        _i = 1;
L13:
        if (_i > _6033)
            goto L14;

        // 	    val[arg] = val[b][i]
        DeRef(_6041);
        _2 = (int)SEQ_PTR(_16val);
        _6041 = (int)*(((s1_ptr)_2)->base + _16b);
        Ref(_6041);
        _0 = _6041;
        _2 = (int)SEQ_PTR(_6041);
        _6041 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6041);
        DeRef(_0);
        Ref(_6041);
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _6041;
        DeRef(_1);

        // 	    arg = SymTab[arg][S_NEXT]
        DeRef(_6041);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6041 = (int)*(((s1_ptr)_2)->base + _arg);
        RefDS(_6041);
        _2 = (int)SEQ_PTR(_6041);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 	end for
        _i = _i + 1;
        goto L13;
L14:
        ;
    }
L12:

    //     SymTab[sub][S_RESIDENT_TASK] = current_task
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
    *(int *)_2 = _16current_task;
    DeRef(_1);

    //     pc += 3 + cf
    DeRef(_6033);
    _6033 = 3 + _cf;
    if ((long)((unsigned long)_6033 + (unsigned long)HIGH_BITS) >= 0) 
        _6033 = NewDouble((double)_6033);
    if (IS_ATOM_INT(_6033)) {
        _16pc = _16pc + _6033;
    }
    else {
        _16pc = NewDouble((double)_16pc + DBL_PTR(_6033)->dbl);
    }
    if (!IS_ATOM_INT(_16pc)) {
        _1 = (long)(DBL_PTR(_16pc)->dbl);
        DeRefDS(_16pc);
        _16pc = _1;
    }

    //     call_stack = append(call_stack, pc) 
    Append(&_16call_stack, _16call_stack, _16pc);

    //     call_stack = append(call_stack, sub)
    Append(&_16call_stack, _16call_stack, _sub);

    //     Code = SymTab[sub][S_CODE]
    DeRef(_6033);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6033 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6033);
    DeRef(_4Code);
    _2 = (int)SEQ_PTR(_6033);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    //     pc = 1
    _16pc = 1;

    // end procedure
    DeRef(_private_block);
    DeRefDS(_6033);
    DeRef(_6041);
    DeRef(_6040);
    return 0;
    ;
}


int _16opROUTINE_ID()
{
    int _sub;
    int _fn;
    int _p;
    int _stlen;
    int _name = 0;
    int _6141 = 0;
    int _6143 = 0;
    int _6125 = 0;
    int _0, _1, _2;
    

    //     sub = Code[pc+1]   -- CurrentSub
    _6125 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _6125);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     stlen = Code[pc+2]  -- s.t. length
    _6125 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _stlen = (int)*(((s1_ptr)_2)->base + _6125);
    if (!IS_ATOM_INT(_stlen))
        _stlen = (long)DBL_PTR(_stlen)->dbl;

    //     name = val[Code[pc+3]]  -- routine name sequence
    _6125 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6125 = (int)*(((s1_ptr)_2)->base + _6125);
    Ref(_6125);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6125))
        _name = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6125)->dbl));
    else
        _name = (int)*(((s1_ptr)_2)->base + _6125);
    Ref(_name);

    //     fn = Code[pc+4]    -- file number
    DeRef(_6125);
    _6125 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _fn = (int)*(((s1_ptr)_2)->base + _6125);
    if (!IS_ATOM_INT(_fn))
        _fn = (long)DBL_PTR(_fn)->dbl;

    //     target = Code[pc+5]
    _6125 = _16pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6125);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     pc += 6
    _16pc = _16pc + 6;

    //     if atom(name) then
    _6125 = IS_ATOM(_name);
    if (_6125 == 0)
        goto L1;

    // 	val[target] = -1
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	return
    DeRef(_name);
    return 0;
L1:

    //     p = RTLookup(name, fn, sub, stlen)
    Ref(_name);
    _p = _16RTLookup(_name, _fn, _sub, _stlen);

    //     if p = 0 or not find(SymTab[p][S_TOKEN], {PROC, FUNC, TYPE}) then
    DeRef(_6125);
    _6125 = (_p == 0);
    if (_6125 != 0) {
        goto L2;
    }
    DeRef(_6141);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6141 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6141);
    _0 = _6141;
    _2 = (int)SEQ_PTR(_6141);
    _6141 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6141);
    DeRefDS(_0);
    _0 = _6143;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 27;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    _6143 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _6143;
    _6143 = find(_6141, _6143);
    DeRefDSi(_0);
    _6143 = (_6143 == 0);
L3:
    if (_6143 == 0)
        goto L4;
L2:

    // 	val[target] = -1  -- name is not a routine
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	return
    DeRef(_name);
    DeRef(_6141);
    DeRef(_6143);
    DeRef(_6125);
    return 0;
L4:

    //     for i = 1 to length(e_routine) do
    DeRef(_6143);
    _6143 = SEQ_PTR(_16e_routine)->length;
    { int _i;
        _i = 1;
L5:
        if (_i > _6143)
            goto L6;

        // 	if e_routine[i] = p then
        DeRef(_6141);
        _2 = (int)SEQ_PTR(_16e_routine);
        _6141 = (int)*(((s1_ptr)_2)->base + _i);
        if (_6141 != _p)
            goto L7;

        // 	    val[target] = i - 1  -- routine was already assigned an id
        _6141 = _i - 1;
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _16target);
        _1 = *(int *)_2;
        *(int *)_2 = _6141;
        DeRef(_1);

        // 	    return
        DeRef(_name);
        DeRef(_6143);
        DeRef(_6125);
        return 0;
L7:

        //     end for 
        _i = _i + 1;
        goto L5;
L6:
        ;
    }

    //     e_routine = append(e_routine, p)
    Append(&_16e_routine, _16e_routine, _p);

    //     val[target] = length(e_routine) - 1
    DeRef(_6141);
    _6141 = SEQ_PTR(_16e_routine)->length;
    _6141 = _6141 - 1;
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6141;
    DeRef(_1);

    // end procedure
    DeRef(_name);
    DeRef(_6143);
    DeRef(_6125);
    return 0;
    ;
}


int _16opAPPEND()
{
    int _6160 = 0;
    int _6153 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6153 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6153);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6153 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6153);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6153 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6153);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = append(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6153 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6153);
    _2 = (int)SEQ_PTR(_16val);
    _6160 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6160);
    Ref(_6160);
    Append(&_6160, _6153, _6160);
    RefDS(_6160);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6160;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_6160);
    DeRef(_6153);
    return 0;
    ;
}


int _16opPREPEND()
{
    int _6170 = 0;
    int _6163 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6163 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6163);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6163 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6163);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6163 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6163);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = prepend(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6163 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6163);
    _2 = (int)SEQ_PTR(_16val);
    _6170 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6170);
    Ref(_6170);
    Prepend(&_6170, _6163, _6170);
    RefDS(_6170);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6170;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_6170);
    DeRef(_6163);
    return 0;
    ;
}


int _16opCONCAT()
{
    int _6180 = 0;
    int _6173 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6173 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6173);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6173 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6173);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6173 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6173);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] & val[b]
    _2 = (int)SEQ_PTR(_16val);
    _6173 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6173);
    _2 = (int)SEQ_PTR(_16val);
    _6180 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6180);
    if (IS_SEQUENCE(_6173) && IS_ATOM(_6180)) {
        Ref(_6180);
        Append(&_6180, _6173, _6180);
    }
    else if (IS_ATOM(_6173) && IS_SEQUENCE(_6180)) {
        Ref(_6173);
        Prepend(&_6180, _6180, _6173);
    }
    else {
        Concat((object_ptr)&_6180, _6173, (s1_ptr)_6180);
    }
    RefDS(_6180);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6180;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_6180);
    DeRef(_6173);
    return 0;
    ;
}


int _16opCONCAT_N()
{
    int _n;
    int _x = 0;
    int _6183 = 0;
    int _6189 = 0;
    int _0, _1, _2;
    

    //     n = Code[pc+1] -- number of items
    _6183 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _n = (int)*(((s1_ptr)_2)->base + _6183);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     x = val[Code[pc+2]] -- last one
    _6183 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6183 = (int)*(((s1_ptr)_2)->base + _6183);
    Ref(_6183);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6183))
        _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6183)->dbl));
    else
        _x = (int)*(((s1_ptr)_2)->base + _6183);
    Ref(_x);

    //     for i = pc+3 to pc+n+1 do
    DeRef(_6183);
    _6183 = _16pc + 3;
    if ((long)((unsigned long)_6183 + (unsigned long)HIGH_BITS) >= 0) 
        _6183 = NewDouble((double)_6183);
    _6189 = _16pc + _n;
    if ((long)((unsigned long)_6189 + (unsigned long)HIGH_BITS) >= 0) 
        _6189 = NewDouble((double)_6189);
    _0 = _6189;
    if (IS_ATOM_INT(_6189)) {
        _6189 = _6189 + 1;
        if (_6189 > MAXINT)
            _6189 = NewDouble((double)_6189);
    }
    else
        _6189 = binary_op(PLUS, 1, _6189);
    DeRef(_0);
    { int _i;
        Ref(_6183);
        _i = _6183;
L1:
        if (binary_op_a(GREATER, _i, _6189))
            goto L2;

        // 	x = val[Code[i]] & x
        DeRef(_6183);
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_i))
            _6183 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _6183 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_6183);
        _0 = _6183;
        _2 = (int)SEQ_PTR(_16val);
        if (!IS_ATOM_INT(_6183))
            _6183 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6183)->dbl));
        else
            _6183 = (int)*(((s1_ptr)_2)->base + _6183);
        Ref(_6183);
        DeRef(_0);
        if (IS_SEQUENCE(_6183) && IS_ATOM(_x)) {
            Ref(_x);
            Append(&_x, _6183, _x);
        }
        else if (IS_ATOM(_6183) && IS_SEQUENCE(_x)) {
            Ref(_6183);
            Prepend(&_x, _x, _6183);
        }
        else {
            Concat((object_ptr)&_x, _6183, (s1_ptr)_x);
        }

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
        goto L1;
L2:
        ;
        DeRef(_i);
    }

    //     target = Code[pc+n+2]
    DeRef(_6183);
    _6183 = _16pc + _n;
    if ((long)((unsigned long)_6183 + (unsigned long)HIGH_BITS) >= 0) 
        _6183 = NewDouble((double)_6183);
    _0 = _6183;
    if (IS_ATOM_INT(_6183)) {
        _6183 = _6183 + 2;
    }
    else {
        _6183 = NewDouble(DBL_PTR(_6183)->dbl + (double)2);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6183))
        _16target = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6183)->dbl));
    else
        _16target = (int)*(((s1_ptr)_2)->base + _6183);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = x
    Ref(_x);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    //     pc += n+3
    DeRef(_6183);
    _6183 = _n + 3;
    if ((long)((unsigned long)_6183 + (unsigned long)HIGH_BITS) >= 0) 
        _6183 = NewDouble((double)_6183);
    if (IS_ATOM_INT(_6183)) {
        _16pc = _16pc + _6183;
    }
    else {
        _16pc = NewDouble((double)_16pc + DBL_PTR(_6183)->dbl);
    }
    if (!IS_ATOM_INT(_16pc)) {
        _1 = (long)(DBL_PTR(_16pc)->dbl);
        DeRefDS(_16pc);
        _16pc = _1;
    }

    // end procedure
    DeRef(_x);
    DeRef(_6183);
    DeRef(_6189);
    return 0;
    ;
}


int _16opREPEAT()
{
    int _6216 = 0;
    int _6199 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6199 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6199);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6199 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6199);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6199 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6199);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if not atom(val[b]) then
    _2 = (int)SEQ_PTR(_16val);
    _6199 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6199);
    _0 = _6199;
    _6199 = IS_ATOM(_6199);
    DeRef(_0);
    if (_6199 != 0)
        goto L1;

    // 	RTFatal("repetition count must be an atom")
    RefDS(_6208);
    _16RTFatal(_6208);
L1:

    //     if val[b] < 0 then
    DeRef(_6199);
    _2 = (int)SEQ_PTR(_16val);
    _6199 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6199);
    if (binary_op_a(GREATEREQ, _6199, 0))
        goto L2;

    // 	RTFatal("repetition count must not be negative")
    RefDS(_6211);
    _16RTFatal(_6211);
L2:

    //     if val[b] > 1073741823 then
    DeRef(_6199);
    _2 = (int)SEQ_PTR(_16val);
    _6199 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6199);
    if (binary_op_a(LESSEQ, _6199, 1073741823))
        goto L3;

    // 	RTFatal("repetition count is too large")
    RefDS(_6214);
    _16RTFatal(_6214);
L3:

    //     val[target] = repeat(val[a], val[b])
    DeRef(_6199);
    _2 = (int)SEQ_PTR(_16val);
    _6199 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6199);
    DeRef(_6216);
    _2 = (int)SEQ_PTR(_16val);
    _6216 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6216);
    _0 = _6216;
    _6216 = Repeat(_6199, _6216);
    DeRef(_0);
    RefDS(_6216);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6216;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_6216);
    DeRef(_6199);
    return 0;
    ;
}


int _16opDATE()
{
    int _6219 = 0;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _6219 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6219);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = date()
    _6219 = Date();
    RefDS(_6219);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6219;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRefDSi(_6219);
    return 0;
    ;
}


int _16opTIME()
{
    int _6223 = 0;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _6223 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6223);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = time()
    _6223 = NewDouble(current_time());
    RefDS(_6223);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6223;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRefDS(_6223);
    return 0;
    ;
}


int _16opSPACE_USED()
{
    int _0, _1, _2;
    

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    return 0;
    ;
}


int _16opNOP2()
{
    int _0, _1, _2;
    

    //     pc+= 2
    _16pc = _16pc + 2;

    // end procedure
    return 0;
    ;
}


int _16opPOSITION()
{
    int _6234 = 0;
    int _6229 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6229 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6229);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6229 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6229);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     position(val[a], val[b])  -- error checks
    _2 = (int)SEQ_PTR(_16val);
    _6229 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6229);
    _2 = (int)SEQ_PTR(_16val);
    _6234 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6234);
    Position(_6229, _6234);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6234);
    DeRef(_6229);
    return 0;
    ;
}


int _16opEQUAL()
{
    int _6243 = 0;
    int _6236 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6236 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6236);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6236 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6236);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6236 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6236);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = equal(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6236 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6236);
    _2 = (int)SEQ_PTR(_16val);
    _6243 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6243);
    _0 = _6243;
    if (_6236 == _6243)
        _6243 = 1;
    else if (IS_ATOM_INT(_6236) && IS_ATOM_INT(_6243))
        _6243 = 0;
    else
        _6243 = (compare(_6236, _6243) == 0);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6243;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6236);
    return 0;
    ;
}


int _16opCOMPARE()
{
    int _6253 = 0;
    int _6246 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6246 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6246);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6246 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6246);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6246 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6246);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = compare(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6246 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6246);
    _2 = (int)SEQ_PTR(_16val);
    _6253 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6253);
    _0 = _6253;
    if (IS_ATOM_INT(_6246) && IS_ATOM_INT(_6253))
        _6253 = (_6246 < _6253) ? -1 : (_6246 > _6253);
    else
        _6253 = compare(_6246, _6253);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6253;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6246);
    return 0;
    ;
}


int _16opFIND()
{
    int _6267 = 0;
    int _6256 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6256 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6256);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6256 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6256);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6256 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6256);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if not sequence(val[b]) then
    _2 = (int)SEQ_PTR(_16val);
    _6256 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6256);
    _0 = _6256;
    _6256 = IS_SEQUENCE(_6256);
    DeRef(_0);
    if (_6256 != 0)
        goto L1;

    // 	RTFatal("second argument of find() must be a sequence")
    RefDS(_6265);
    _16RTFatal(_6265);
L1:

    //     val[target] = find(val[a], val[b])
    DeRef(_6256);
    _2 = (int)SEQ_PTR(_16val);
    _6256 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6256);
    DeRef(_6267);
    _2 = (int)SEQ_PTR(_16val);
    _6267 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6267);
    _0 = _6267;
    _6267 = find(_6256, _6267);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6267;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6256);
    return 0;
    ;
}


int _16opMATCH()
{
    int _6289 = 0;
    int _6270 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6270 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6270);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6270 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6270);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6270 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6270);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if not sequence(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _6270 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6270);
    _0 = _6270;
    _6270 = IS_SEQUENCE(_6270);
    DeRef(_0);
    if (_6270 != 0)
        goto L1;

    // 	RTFatal("first argument of match() must be a sequence")
    RefDS(_6279);
    _16RTFatal(_6279);
L1:

    //     if not sequence(val[b]) then
    DeRef(_6270);
    _2 = (int)SEQ_PTR(_16val);
    _6270 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6270);
    _0 = _6270;
    _6270 = IS_SEQUENCE(_6270);
    DeRef(_0);
    if (_6270 != 0)
        goto L2;

    // 	RTFatal("second argument of match() must be a sequence")
    RefDS(_6283);
    _16RTFatal(_6283);
L2:

    //     if length(val[a]) = 0 then
    DeRef(_6270);
    _2 = (int)SEQ_PTR(_16val);
    _6270 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6270);
    _0 = _6270;
    _6270 = SEQ_PTR(_6270)->length;
    DeRef(_0);
    if (_6270 != 0)
        goto L3;

    // 	 RTFatal("first argument of match() must be a non-empty sequence")
    RefDS(_6287);
    _16RTFatal(_6287);
L3:

    //     val[target] = match(val[a], val[b])
    DeRef(_6270);
    _2 = (int)SEQ_PTR(_16val);
    _6270 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6270);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_16val);
    _6289 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6289);
    _0 = _6289;
    _6289 = e_match(_6270, _6289);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6289;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6270);
    return 0;
    ;
}


int _16opFIND_FROM()
{
    int _s = 0;
    int _6307 = 0;
    int _6292 = 0;
    int _0, _1, _2;
    

    // 	c = val[Code[pc+3]]
    _6292 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6292 = (int)*(((s1_ptr)_2)->base + _6292);
    Ref(_6292);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6292))
        _16c = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6292)->dbl));
    else
        _16c = (int)*(((s1_ptr)_2)->base + _6292);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    // 	target = Code[pc+4]
    DeRef(_6292);
    _6292 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6292);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    // 	if not sequence(val[Code[pc+2]]) then
    _6292 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6292 = (int)*(((s1_ptr)_2)->base + _6292);
    Ref(_6292);
    _0 = _6292;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6292))
        _6292 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6292)->dbl));
    else
        _6292 = (int)*(((s1_ptr)_2)->base + _6292);
    Ref(_6292);
    DeRef(_0);
    _0 = _6292;
    _6292 = IS_SEQUENCE(_6292);
    DeRef(_0);
    if (_6292 != 0)
        goto L1;

    // 		RTFatal("second argument of find_from() must be a sequence")
    RefDS(_6302);
    _16RTFatal(_6302);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    return 0;
L1:

    // 	s = val[Code[pc+2]][c..$]
    DeRef(_6292);
    _6292 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6292 = (int)*(((s1_ptr)_2)->base + _6292);
    Ref(_6292);
    _0 = _6292;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6292))
        _6292 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6292)->dbl));
    else
        _6292 = (int)*(((s1_ptr)_2)->base + _6292);
    Ref(_6292);
    DeRef(_0);
    DeRef(_6307);
    _6307 = SEQ_PTR(_6292)->length;
    rhs_slice_target = (object_ptr)&_s;
    RHS_Slice((s1_ptr)_6292, _16c, _6307);

    // 	b = find( val[Code[pc+1]], s )
    _6307 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6307 = (int)*(((s1_ptr)_2)->base + _6307);
    Ref(_6307);
    _0 = _6307;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6307))
        _6307 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6307)->dbl));
    else
        _6307 = (int)*(((s1_ptr)_2)->base + _6307);
    Ref(_6307);
    DeRef(_0);
    _16b = find(_6307, _s);

    // 	if b then
    if (_16b == 0)
        goto L2;

    // 		b += c - 1
    DeRef(_6307);
    _6307 = _16c - 1;
    if ((long)((unsigned long)_6307 +(unsigned long) HIGH_BITS) >= 0)
        _6307 = NewDouble((double)_6307);
    if (IS_ATOM_INT(_6307)) {
        _16b = _16b + _6307;
    }
    else {
        _16b = NewDouble((double)_16b + DBL_PTR(_6307)->dbl);
    }
    if (!IS_ATOM_INT(_16b)) {
        _1 = (long)(DBL_PTR(_16b)->dbl);
        DeRefDS(_16b);
        _16b = _1;
    }
L2:

    // 	val[target] = b
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _16b;
    DeRef(_1);

    // 	pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_s);
    DeRef(_6307);
    DeRef(_6292);
    return 0;
    ;
}


int _16opMATCH_FROM()
{
    int _s = 0;
    int _6316 = 0;
    int _0, _1, _2;
    

    // 	c = val[Code[pc+3]]
    _6316 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6316 = (int)*(((s1_ptr)_2)->base + _6316);
    Ref(_6316);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6316))
        _16c = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6316)->dbl));
    else
        _16c = (int)*(((s1_ptr)_2)->base + _6316);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    // 	target = Code[pc+4]
    DeRef(_6316);
    _6316 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6316);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    // 	s = val[Code[pc+2]]
    _6316 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6316 = (int)*(((s1_ptr)_2)->base + _6316);
    Ref(_6316);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6316))
        _s = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6316)->dbl));
    else
        _s = (int)*(((s1_ptr)_2)->base + _6316);
    Ref(_s);

    // 	a = Code[pc+1]
    DeRef(_6316);
    _6316 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6316);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    // 	if not sequence(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _6316 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6316);
    _0 = _6316;
    _6316 = IS_SEQUENCE(_6316);
    DeRef(_0);
    if (_6316 != 0)
        goto L1;

    // 		RTFatal("first argument of match_from() must be a sequence")
    RefDS(_6329);
    _16RTFatal(_6329);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    DeRef(_s);
    return 0;
L1:

    // 	if length(val[a]) = 0 then
    DeRef(_6316);
    _2 = (int)SEQ_PTR(_16val);
    _6316 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6316);
    _0 = _6316;
    _6316 = SEQ_PTR(_6316)->length;
    DeRef(_0);
    if (_6316 != 0)
        goto L2;

    // 		RTFatal("first argument of match_from() must be a non-empty sequence")
    RefDS(_6334);
    _16RTFatal(_6334);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    DeRef(_s);
    return 0;
L2:

    // 	if not sequence(s) then
    DeRef(_6316);
    _6316 = IS_SEQUENCE(_s);
    if (_6316 != 0)
        goto L3;

    // 		RTFatal("second argument of match_from() must be a sequence")
    RefDS(_6338);
    _16RTFatal(_6338);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    DeRef(_s);
    return 0;
L3:

    // 	if c < 1 then
    if (_16c >= 1)
        goto L4;

    // 		RTFatal("index out of bounds in match_from()")
    RefDS(_6341);
    _16RTFatal(_6341);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    DeRef(_s);
    DeRef(_6316);
    return 0;
L4:

    // 	if c > length(s) then
    DeRef(_6316);
    _6316 = SEQ_PTR(_s)->length;
    if (_16c <= _6316)
        goto L5;

    // 		RTFatal("index out of bounds in match_from()")
    RefDS(_6341);
    _16RTFatal(_6341);

    // 		pc += 5
    _16pc = _16pc + 5;

    // 		return
    DeRef(_s);
    return 0;
L5:

    // 	s = s[c..$]
    DeRef(_6316);
    _6316 = SEQ_PTR(_s)->length;
    rhs_slice_target = (object_ptr)&_s;
    RHS_Slice((s1_ptr)_s, _16c, _6316);

    // 	b = match( val[Code[pc+1]], s )
    _6316 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6316 = (int)*(((s1_ptr)_2)->base + _6316);
    Ref(_6316);
    _0 = _6316;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6316))
        _6316 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6316)->dbl));
    else
        _6316 = (int)*(((s1_ptr)_2)->base + _6316);
    Ref(_6316);
    DeRef(_0);
    _16b = e_match(_6316, _s);

    // 	if b then
    if (_16b == 0)
        goto L6;

    // 		b += c - 1
    DeRef(_6316);
    _6316 = _16c - 1;
    if ((long)((unsigned long)_6316 +(unsigned long) HIGH_BITS) >= 0)
        _6316 = NewDouble((double)_6316);
    if (IS_ATOM_INT(_6316)) {
        _16b = _16b + _6316;
    }
    else {
        _16b = NewDouble((double)_16b + DBL_PTR(_6316)->dbl);
    }
    if (!IS_ATOM_INT(_16b)) {
        _1 = (long)(DBL_PTR(_16b)->dbl);
        DeRefDS(_16b);
        _16b = _1;
    }
L6:

    // 	val[target] = b
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _16b;
    DeRef(_1);

    // 	pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_s);
    DeRef(_6316);
    return 0;
    ;
}


int _16opPEEK4U()
{
    int _6355 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6355 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6355);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6355 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6355);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = peek4u(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6355 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6355);
    _0 = _6355;
    if (IS_ATOM_INT(_6355)) {
        _6355 = *(unsigned long *)_6355;
        if ((unsigned)_6355 > (unsigned)MAXINT)
            _6355 = NewDouble((double)(unsigned long)_6355);
    }
    else if (IS_ATOM(_6355)) {
        _6355 = *(unsigned long *)(unsigned long)(DBL_PTR(_6355)->dbl);
        if ((unsigned)_6355 > (unsigned)MAXINT)
            _6355 = NewDouble((double)(unsigned long)_6355);
    }
    else {
        _1 = (int)SEQ_PTR(_6355);
        peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _6355 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            _1 = (int)*peek4_addr++;
            if ((unsigned)_1 > (unsigned)MAXINT)
                _1 = NewDouble((double)(unsigned long)_1);
            *(int *)poke4_addr = _1;
        }
    }
    DeRef(_0);
    Ref(_6355);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6355;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6355);
    return 0;
    ;
}


int _16opPEEK4S()
{
    int _6362 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6362 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6362);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6362 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6362);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = peek4s(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6362 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6362);
    _0 = _6362;
    if (IS_ATOM_INT(_6362)) {
        _6362 = *(unsigned long *)_6362;
        if (_6362 < MININT || _6362 > MAXINT)
            _6362 = NewDouble((double)(long)_6362);
    }
    else if (IS_ATOM(_6362)) {
        _6362 = *(unsigned long *)(unsigned long)(DBL_PTR(_6362)->dbl);
        if (_6362 < MININT || _6362 > MAXINT)
            _6362 = NewDouble((double)(long)_6362);
    }
    else {
        _1 = (int)SEQ_PTR(_6362);
        peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _6362 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            _1 = (int)*peek4_addr++;
            if (_1 < MININT || _1 > MAXINT)
                _1 = NewDouble((double)(long)_1);
            *(int *)poke4_addr = _1;
        }
    }
    DeRef(_0);
    Ref(_6362);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6362;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6362);
    return 0;
    ;
}


int _16opPEEK()
{
    int _6369 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6369 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6369);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6369 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6369);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = peek(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6369 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6369);
    _0 = _6369;
    if (IS_ATOM_INT(_6369)) {
        _6369 = *(unsigned char *)_6369;
    }
    else if (IS_ATOM(_6369)) {
        _6369 = *(unsigned char *)(unsigned long)(DBL_PTR(_6369)->dbl);
    }
    else {
        _1 = (int)SEQ_PTR(_6369);
        poke_addr = (unsigned char *)get_pos_int("peek", *(((s1_ptr)_1)->base+1));
        _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
        poke4_addr = (unsigned long *)NewS1(_2);
        _6369 = MAKE_SEQ(poke4_addr);
        poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
        while (--_2 >= 0) {
            poke4_addr++;
            *(int *)poke4_addr = *poke_addr++;
        }
    }
    DeRef(_0);
    Ref(_6369);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6369;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6369);
    return 0;
    ;
}


int _16opPOKE()
{
    int _6381 = 0;
    int _6376 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6376 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6376);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6376 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6376);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     poke(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6376 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6376);
    _2 = (int)SEQ_PTR(_16val);
    _6381 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6381);
    if (IS_ATOM_INT(_6376))
        poke_addr = (unsigned char *)_6376;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_6376)->dbl);
    if (IS_ATOM_INT(_6381)) {
        *poke_addr = (unsigned char)_6381;
    }
    else if (IS_ATOM(_6381)) {
        *poke_addr = (signed char)DBL_PTR(_6381)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_6381);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *poke_addr++ = (unsigned char)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
            }
        }
    }

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6381);
    DeRef(_6376);
    return 0;
    ;
}


int _16opPOKE4()
{
    int _6388 = 0;
    int _6383 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6383 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6383);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6383 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6383);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     poke4(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6383 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6383);
    _2 = (int)SEQ_PTR(_16val);
    _6388 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6388);
    if (IS_ATOM_INT(_6383))
        poke4_addr = (unsigned long *)_6383;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6383)->dbl);
    if (IS_ATOM_INT(_6388)) {
        *poke4_addr = (unsigned long)_6388;
    }
    else if (IS_ATOM(_6388)) {
        *poke4_addr = (unsigned long)DBL_PTR(_6388)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_6388);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *(int *)poke4_addr++ = (unsigned long)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *(int *)poke4_addr++ = (unsigned long)DBL_PTR(_2)->dbl;
            }
        }
    }

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6388);
    DeRef(_6383);
    return 0;
    ;
}


int _16opMEM_COPY()
{
    int _6398 = 0;
    int _6397 = 0;
    int _6390 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6390 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6390);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6390 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6390);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]
    _6390 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _6390);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     mem_copy(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_16val);
    _6390 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6390);
    _2 = (int)SEQ_PTR(_16val);
    _6397 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6397);
    _2 = (int)SEQ_PTR(_16val);
    _6398 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_6398);
    memory_copy(_6390, _6397, _6398);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6398);
    DeRef(_6397);
    DeRef(_6390);
    return 0;
    ;
}


int _16opMEM_SET()
{
    int _6408 = 0;
    int _6407 = 0;
    int _6400 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6400 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6400);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6400 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6400);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]
    _6400 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _6400);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     mem_set(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_16val);
    _6400 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6400);
    _2 = (int)SEQ_PTR(_16val);
    _6407 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6407);
    _2 = (int)SEQ_PTR(_16val);
    _6408 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_6408);
    memory_set(_6400, _6407, _6408);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6408);
    DeRef(_6407);
    DeRef(_6400);
    return 0;
    ;
}


int _16opPIXEL()
{
    int _6415 = 0;
    int _6410 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6410 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6410);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6410 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6410);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     pixel(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6410 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6410);
    _2 = (int)SEQ_PTR(_16val);
    _6415 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6415);
    Pixel(_6410, _6415);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6415);
    DeRef(_6410);
    return 0;
    ;
}


int _16opGET_PIXEL()
{
    int _6417 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6417 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6417);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6417 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6417);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = get_pixel(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6417 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6417);
    _0 = _6417;
    _6417 = Get_Pixel(_6417);
    DeRef(_0);
    Ref(_6417);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6417;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6417);
    return 0;
    ;
}


int _16opCALL()
{
    int _6424 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6424 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6424);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     call(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6424 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6424);
    if (IS_ATOM_INT(_6424))
        _0 = (int)_6424;
    else
        _0 = (int)(unsigned long)(DBL_PTR(_6424)->dbl);
    (*(void(*)())_0)();

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_6424);
    return 0;
    ;
}


int _16opSYSTEM()
{
    int _6439 = 0;
    int _6428 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6428 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6428);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6428 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6428);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _6428 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6428);
    _0 = _6428;
    _6428 = IS_ATOM(_6428);
    DeRef(_0);
    if (_6428 == 0)
        goto L1;

    // 	RTFatal("first argument of system() must be a sequence")
    RefDS(_6434);
    _16RTFatal(_6434);
L1:

    //     if sequence(val[b]) then
    DeRef(_6428);
    _2 = (int)SEQ_PTR(_16val);
    _6428 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6428);
    _0 = _6428;
    _6428 = IS_SEQUENCE(_6428);
    DeRef(_0);
    if (_6428 == 0)
        goto L2;

    // 	RTFatal("second argument of system() must be an atom")
    RefDS(_6437);
    _16RTFatal(_6437);
L2:

    //     system(val[a], val[b])
    DeRef(_6428);
    _2 = (int)SEQ_PTR(_16val);
    _6428 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6428);
    DeRef(_6439);
    _2 = (int)SEQ_PTR(_16val);
    _6439 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6439);
    system_call(_6428, _6439);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6439);
    DeRef(_6428);
    return 0;
    ;
}


int _16opSYSTEM_EXEC()
{
    int _6452 = 0;
    int _6441 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6441 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6441);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6441 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6441);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6441 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6441);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _6441 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6441);
    _0 = _6441;
    _6441 = IS_ATOM(_6441);
    DeRef(_0);
    if (_6441 == 0)
        goto L1;

    // 	RTFatal("first argument of system() must be a sequence")
    RefDS(_6434);
    _16RTFatal(_6434);
L1:

    //     if sequence(val[b]) then
    DeRef(_6441);
    _2 = (int)SEQ_PTR(_16val);
    _6441 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6441);
    _0 = _6441;
    _6441 = IS_SEQUENCE(_6441);
    DeRef(_0);
    if (_6441 == 0)
        goto L2;

    // 	RTFatal("second argument of system() must be an atom")
    RefDS(_6437);
    _16RTFatal(_6437);
L2:

    //     val[target] = system_exec(val[a], val[b])
    DeRef(_6441);
    _2 = (int)SEQ_PTR(_16val);
    _6441 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6441);
    DeRef(_6452);
    _2 = (int)SEQ_PTR(_16val);
    _6452 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6452);
    _0 = _6452;
    _6452 = system_exec_call(_6441, _6452);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6452;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6441);
    return 0;
    ;
}


int _16opOPEN()
{
    int _6455 = 0;
    int _6464 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6455 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6455);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6455 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6455);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6455 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6455);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if atom(val[b]) or length(val[b]) > 2 then
    _2 = (int)SEQ_PTR(_16val);
    _6455 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6455);
    _0 = _6455;
    _6455 = IS_ATOM(_6455);
    DeRef(_0);
    if (_6455 != 0) {
        goto L1;
    }
    _2 = (int)SEQ_PTR(_16val);
    _6464 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6464);
    _0 = _6464;
    _6464 = SEQ_PTR(_6464)->length;
    DeRef(_0);
    _6464 = (_6464 > 2);
L2:
    if (_6464 == 0)
        goto L3;
L1:

    //        RTFatal("invalid open mode")
    RefDS(_6467);
    _16RTFatal(_6467);
L3:

    //     if atom(val[a]) then
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_16val);
    _6464 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6464);
    _0 = _6464;
    _6464 = IS_ATOM(_6464);
    DeRef(_0);
    if (_6464 == 0)
        goto L4;

    //        RTFatal("device or file name must be a sequence")
    RefDS(_6470);
    _16RTFatal(_6470);
L4:

    //     val[target] = open(val[a], val[b])
    DeRef(_6464);
    _2 = (int)SEQ_PTR(_16val);
    _6464 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6464);
    DeRef(_6455);
    _2 = (int)SEQ_PTR(_16val);
    _6455 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6455);
    _0 = _6455;
    _6455 = EOpen(_6464, _6455);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6455;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6464);
    return 0;
    ;
}


int _16opCLOSE()
{
    int _6475 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6475 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6475);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     close(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6475 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6475);
    if (IS_ATOM_INT(_6475))
        EClose(_6475);
    else
        EClose((int)DBL_PTR(_6475)->dbl);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_6475);
    return 0;
    ;
}


int _16opABORT()
{
    int _6479 = 0;
    int _0, _1, _2;
    

    //     abort(val[Code[pc+1]])
    _6479 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6479 = (int)*(((s1_ptr)_2)->base + _6479);
    Ref(_6479);
    _0 = _6479;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6479))
        _6479 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6479)->dbl));
    else
        _6479 = (int)*(((s1_ptr)_2)->base + _6479);
    Ref(_6479);
    DeRef(_0);
    if (IS_ATOM_INT(_6479))
        UserCleanup(_6479);
    else
        UserCleanup((int)DBL_PTR(_6479)->dbl);

    // end procedure
    DeRef(_6479);
    return 0;
    ;
}


int _16opGETC()
{
    int _6482 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6482 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6482);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6482 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6482);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = getc(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6482 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6482);
    _0 = _6482;
    if (_6482 != last_r_file_no) {
        last_r_file_ptr = which_file(_6482, EF_READ);
        if (IS_ATOM_INT(_6482))
            last_r_file_no = _6482;
        else
            last_r_file_no = NOVALUE;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _6482 = getc(xstdin);
        }
        else
            _6482 = getc(last_r_file_ptr);
    }
    else
        _6482 = getc(last_r_file_ptr);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6482;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


int _16opGETS()
{
    int _6489 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6489 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6489);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6489 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6489);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = gets(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _6489 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6489);
    _0 = _6489;
    _6489 = EGets(_6489);
    DeRef(_0);
    Ref(_6489);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6489;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRefi(_6489);
    return 0;
    ;
}


int _16opGET_KEY()
{
    int _6496;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _6496 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6496);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = get_key()
    _6496 = get_key(0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6496;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    return 0;
    ;
}


int _16opCLEAR_SCREEN()
{
    int _0, _1, _2;
    

    //     clear_screen()
    ClearScreen();

    //     pc += 1
    _16pc = _16pc + 1;

    // end procedure
    return 0;
    ;
}


int _16opPUTS()
{
    int _6506 = 0;
    int _6501 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6501 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6501);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6501 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6501);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     puts(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6501 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6501);
    _2 = (int)SEQ_PTR(_16val);
    _6506 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6506);
    EPuts(_6501, _6506);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6506);
    DeRef(_6501);
    return 0;
    ;
}


