// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _14emit_op(int _op)
{
    int _a;
    int _b;
    int _c;
    int _d;
    int _source;
    int _target;
    int _subsym;
    int _lhs_var;
    int _ib;
    int _ic;
    int _n;
    int _obj = 0;
    int _elements = 0;
    int _element_vals = 0;
    int _2673 = 0;
    int _2487 = 0;
    int _2447 = 0;
    int _2462 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }

    //     if op = ASSIGN then
    if (_op != 18)
        goto L1;

    // 	source = Pop()
    _source = _14Pop();

    // 	target = Pop()
    _target = _14Pop();

    // 	if assignable then
    if (_14assignable == 0)
        goto L2;

    // 	    Code = Code[1..$-1] -- drop previous target
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    rhs_slice_target = (object_ptr)&_4Code;
    RHS_Slice((s1_ptr)_4Code, 1, _2447);

    // 	    op = previous_op -- keep same previous op 
    _op = _14previous_op;

    // 	    if IsInteger(target) then
    _2447 = _14IsInteger(_target);
    if (_2447 == 0)
        goto L3;

    // 		if previous_op = RHS_SUBS then
    if (_14previous_op != 25)
        goto L4;

    // 		    op = RHS_SUBS_I
    _op = 114;

    // 		    backpatch(length(Code) - 2, op)
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 2;
    _14backpatch(_2447, 114);
    goto L3;
L4:

    // 		elsif previous_op = PLUS1 then
    if (_14previous_op != 93)
        goto L5;

    // 		    op = PLUS1_I
    _op = 117;

    // 		    backpatch(length(Code) - 2, op)
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 2;
    _14backpatch(_2447, 117);
    goto L3;
L5:

    // 		elsif previous_op = PLUS or previous_op = MINUS then
    DeRef1(_2447);
    _2447 = (_14previous_op == 11);
    if (_2447 != 0) {
        goto L6;
    }
    DeRef1(_2462);
    _2462 = (_14previous_op == 10);
L7:
    if (_2462 == 0)
        goto L8;
L6:

    // 		    if IsInteger(Code[$]) and
    DeRef1(_2462);
    _2462 = SEQ_PTR(_4Code)->length;
    _2 = (int)SEQ_PTR(_4Code);
    _2462 = (int)*(((s1_ptr)_2)->base + _2462);
    Ref(_2462);
    Ref(_2462);
    _0 = _2462;
    _2462 = _14IsInteger(_2462);
    DeRef1(_0);
    if (_2462 == 0) {
        goto L3;
    }
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _2447 = (int)*(((s1_ptr)_2)->base + _2447);
    Ref(_2447);
    Ref(_2447);
    _0 = _2447;
    _2447 = _14IsInteger(_2447);
    DeRef1(_0);
L9:
    if (_2447 == 0)
        goto L3;

    // 			if previous_op = PLUS then
    if (_14previous_op != 11)
        goto LA;

    // 			    op = PLUS_I
    _op = 115;
    goto LB;
LA:

    // 			    op = MINUS_I
    _op = 116;
LB:

    // 			backpatch(length(Code) - 2, op)
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 2;
    _14backpatch(_2447, _op);
LC:
    goto L3;
L8:

    // 		    if IsInteger(source) then
    _0 = _2447;
    _2447 = _14IsInteger(_source);
    DeRef1(_0);
    if (_2447 == 0)
        goto L3;

    // 			op = ASSIGN_I -- fake to avoid subsequent check
    _op = 113;
LD:
LE:
LF:
    goto L3;
L2:

    // 	    if IsInteger(source) and IsInteger(target) then
    _0 = _2447;
    _2447 = _14IsInteger(_source);
    DeRef1(_0);
    if (_2447 == 0) {
        goto L10;
    }
    _0 = _2462;
    _2462 = _14IsInteger(_target);
    DeRef1(_0);
L11:
    if (_2462 == 0)
        goto L10;

    // 		op = ASSIGN_I
    _op = 113;
L10:

    // 	    if SymTab[source][S_MODE] = M_CONSTANT and 
    DeRef1(_2462);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2462 = (int)*(((s1_ptr)_2)->base + _source);
    RefDS(_2462);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_2462);
    _2462 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2462);
    DeRef1(_0);
    _0 = _2462;
    if (IS_ATOM_INT(_2462)) {
        _2462 = (_2462 == 2);
    }
    else {
        _2462 = binary_op(EQUALS, _2462, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2462)) {
        if (_2462 == 0) {
            goto L12;
        }
    }
    else {
        if (DBL_PTR(_2462)->dbl == 0.0) {
            goto L12;
        }
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _target);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    if (IS_ATOM_INT(_2447)) {
        _2447 = (_2447 == 2);
    }
    else {
        _2447 = binary_op(EQUALS, _2447, 2);
    }
    DeRef1(_0);
L13:
    if (_2447 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_2447) && DBL_PTR(_2447)->dbl == 0.0)
            goto L12;
    }

    // 		SymTab[target][S_OBJ] = SymTab[source][S_OBJ]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_target + ((s1_ptr)_2)->base);
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _source);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    Ref(_2487);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _2487;
    DeRef(_1);
L12:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(source)
    _14emit_addr(_source);
L3:

    // 	assignable = FALSE
    _14assignable = 0;

    // 	emit_addr(target)
    _14emit_addr(_target);
    goto L14;
L1:

    //     elsif op = RHS_SUBS then
    if (_op != 25)
        goto L15;

    // 	b = Pop() -- subscript 
    _b = _14Pop();

    // 	c = Pop() -- sequence 
    _c = _14Pop();

    // 	target = NewTempSym() -- target 
    _target = _10NewTempSym();

    // 	if SymTab[c][S_MODE] = M_NORMAL then
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _2487, 1))
        goto L16;

    // 	    if SymTab[c][S_VTYPE] != sequence_type and 
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != _10sequence_type);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, _10sequence_type);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            goto L17;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            goto L17;
        }
    }
    DeRef1(_2462);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2462 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2462);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_2462);
    _2462 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2462);
    DeRef1(_0);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_2462))
        _2462 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2462)->dbl));
    else
        _2462 = (int)*(((s1_ptr)_2)->base + _2462);
    RefDS(_2462);
    DeRef1(_0);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_2462);
    _2462 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2462);
    DeRef1(_0);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_2462))
        _2462 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2462)->dbl));
    else
        _2462 = (int)*(((s1_ptr)_2)->base + _2462);
    RefDS(_2462);
    DeRef1(_0);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_2462);
    _2462 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2462);
    DeRef1(_0);
    _0 = _2462;
    if (IS_ATOM_INT(_2462)) {
        _2462 = (_2462 != _10sequence_type);
    }
    else {
        _2462 = binary_op(NOTEQ, _2462, _10sequence_type);
    }
    DeRef1(_0);
L18:
    if (_2462 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_2462) && DBL_PTR(_2462)->dbl == 0.0)
            goto L17;
    }

    // 		op = RHS_SUBS_CHECK
    _op = 92;
L19:
    goto L17;
L16:

    // 	elsif SymTab[c][S_MODE] != M_CONSTANT or 
    DeRef1(_2462);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2462 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2462);
    _0 = _2462;
    _2 = (int)SEQ_PTR(_2462);
    _2462 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2462);
    DeRef1(_0);
    _0 = _2462;
    if (IS_ATOM_INT(_2462)) {
        _2462 = (_2462 != 2);
    }
    else {
        _2462 = binary_op(NOTEQ, _2462, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2462)) {
        if (_2462 != 0) {
            goto L1A;
        }
    }
    else {
        if (DBL_PTR(_2462)->dbl != 0.0) {
            goto L1A;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    _2487 = IS_SEQUENCE(_2487);
    DeRef1(_0);
    _2487 = (_2487 == 0);
L1B:
    if (_2487 == 0)
        goto L1C;
L1A:

    // 	    op = RHS_SUBS_CHECK
    _op = 92;
L1C:
L17:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	assignable = TRUE
    _14assignable = 1;

    // 	Push(target)
    _14Push(_target);

    // 	emit_addr(target)
    _14emit_addr(_target);

    // 	current_sequence = append(current_sequence, target)
    Append(&_14current_sequence, _14current_sequence, _target);
    goto L14;
L15:

    //     elsif op = PROC then  -- procedure, function and type calls
    if (_op != 27)
        goto L1D;

    // 	assignable = FALSE -- assume for now 
    _14assignable = 0;

    // 	subsym = op_info1
    _subsym = _14op_info1;

    // 	n = SymTab[subsym][S_NUM_ARGS]
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_2487);
    _2 = (int)SEQ_PTR(_2487);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    // 	if subsym = CurrentSub then
    if (_subsym != _4CurrentSub)
        goto L1E;

    // 	    for i = length(cg_stack)-n+1 to length(cg_stack) do
    DeRef1(_2487);
    _2487 = SEQ_PTR(_14cg_stack)->length;
    _2487 = _2487 - _n;
    if ((long)((unsigned long)_2487 +(unsigned long) HIGH_BITS) >= 0)
        _2487 = NewDouble((double)_2487);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = _2487 + 1;
        if (_2487 > MAXINT)
            _2487 = NewDouble((double)_2487);
    }
    else
        _2487 = binary_op(PLUS, 1, _2487);
    DeRef1(_0);
    DeRef1(_2462);
    _2462 = SEQ_PTR(_14cg_stack)->length;
    { int _i;
        Ref(_2487);
        _i = _2487;
L1F:
        if (binary_op_a(GREATER, _i, _2462))
            goto L20;

        // 		if SymTab[cg_stack[i]][S_SCOPE] = SC_PRIVATE and 
        DeRef(_2487);
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2487 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2487 = (int)*(((s1_ptr)_2)->base + _i);
        _2 = (int)SEQ_PTR(_4SymTab);
        _2487 = (int)*(((s1_ptr)_2)->base + _2487);
        RefDS(_2487);
        _0 = _2487;
        _2 = (int)SEQ_PTR(_2487);
        _2487 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_2487);
        DeRefDS(_0);
        _0 = _2487;
        if (IS_ATOM_INT(_2487)) {
            _2487 = (_2487 == 3);
        }
        else {
            _2487 = binary_op(EQUALS, _2487, 3);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_2487)) {
            if (_2487 == 0) {
                goto L21;
            }
        }
        else {
            if (DBL_PTR(_2487)->dbl == 0.0) {
                goto L21;
            }
        }
        DeRef(_2447);
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2447 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2447 = (int)*(((s1_ptr)_2)->base + _i);
        _2 = (int)SEQ_PTR(_4SymTab);
        _2447 = (int)*(((s1_ptr)_2)->base + _2447);
        RefDS(_2447);
        _0 = _2447;
        _2 = (int)SEQ_PTR(_2447);
        _2447 = (int)*(((s1_ptr)_2)->base + 12);
        Ref(_2447);
        DeRefDS(_0);
        _0 = _2447;
        if (IS_ATOM_INT(_2447) && IS_ATOM_INT(_i)) {
            _2447 = (_2447 < _i);
        }
        else {
            _2447 = binary_op(LESS, _2447, _i);
        }
        DeRef(_0);
L22:
        if (_2447 == 0) {
            goto L21;
        }
        else {
            if (!IS_ATOM_INT(_2447) && DBL_PTR(_2447)->dbl == 0.0)
                goto L21;
        }

        // 		    emit_opcode(ASSIGN)
        _14emit_opcode(18);

        // 		    emit_addr(cg_stack[i])
        DeRef(_2447);
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2447 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2447 = (int)*(((s1_ptr)_2)->base + _i);
        _14emit_addr(_2447);

        // 		    cg_stack[i] = NewTempSym()
        _2447 = _10NewTempSym();
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _14cg_stack = MAKE_SEQ(_2);
        }
        if (!IS_ATOM_INT(_i))
            _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = _2447;

        // 		    emit_addr(cg_stack[i])
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2447 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2447 = (int)*(((s1_ptr)_2)->base + _i);
        _14emit_addr(_2447);
L21:

        // 	    end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L1F;
L20:
        ;
        DeRef1(_i);
    }
L1E:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(subsym)
    _14emit_addr(_subsym);

    // 	for i = length(cg_stack)-n+1 to length(cg_stack) do 
    DeRef1(_2447);
    _2447 = SEQ_PTR(_14cg_stack)->length;
    _2447 = _2447 - _n;
    if ((long)((unsigned long)_2447 +(unsigned long) HIGH_BITS) >= 0)
        _2447 = NewDouble((double)_2447);
    _0 = _2447;
    if (IS_ATOM_INT(_2447)) {
        _2447 = _2447 + 1;
        if (_2447 > MAXINT)
            _2447 = NewDouble((double)_2447);
    }
    else
        _2447 = binary_op(PLUS, 1, _2447);
    DeRef1(_0);
    DeRef1(_2487);
    _2487 = SEQ_PTR(_14cg_stack)->length;
    { int _i;
        Ref(_2447);
        _i = _2447;
L23:
        if (binary_op_a(GREATER, _i, _2487))
            goto L24;

        // 	    emit_addr(cg_stack[i])
        DeRef(_2447);
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2447 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2447 = (int)*(((s1_ptr)_2)->base + _i);
        _14emit_addr(_2447);

        // 	    TempFree(cg_stack[i])
        _2 = (int)SEQ_PTR(_14cg_stack);
        if (!IS_ATOM_INT(_i))
            _2447 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _2447 = (int)*(((s1_ptr)_2)->base + _i);
        _14TempFree(_2447);

        // 	end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + 1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, 1);
        }
        DeRef1(_0);
        goto L23;
L24:
        ;
        DeRef1(_i);
    }

    // 	cg_stack = cg_stack[1..$-n]
    DeRef1(_2447);
    _2447 = SEQ_PTR(_14cg_stack)->length;
    _2447 = _2447 - _n;
    rhs_slice_target = (object_ptr)&_14cg_stack;
    RHS_Slice((s1_ptr)_14cg_stack, 1, _2447);

    // 	if SymTab[subsym][S_TOKEN] != PROC then
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _subsym);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_2447);
    DeRef1(_0);
    if (binary_op_a(EQUALS, _2447, 27))
        goto L14;

    // 	    assignable = TRUE
    _14assignable = 1;

    // 	    c = NewTempSym() -- put final result in temp 
    _c = _10NewTempSym();

    // 	    Push(c)
    _14Push(_c);

    // 	    emit_addr(c)
    _14emit_addr(_c);
L25:
    goto L14;
L1D:

    //     elsif find(op, {NOP1, NOP2, NOPWHILE, PRIVATE_INIT_CHECK, GLOBAL_INIT_CHECK,
    DeRef1(_2447);
    _2447 = find(_op, _2549);
    if (_2447 == 0)
        goto L26;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L26:

    //     elsif op = IF or op = WHILE then
    DeRef1(_2447);
    _2447 = (_op == 20);
    if (_2447 != 0) {
        goto L27;
    }
    DeRef1(_2487);
    _2487 = (_op == 47);
L28:
    if (_2487 == 0)
        goto L29;
L27:

    // 	a = Pop()
    _a = _14Pop();

    // 	assignable = FALSE
    _14assignable = 0;

    // 	if previous_op >= LESS and previous_op <= NOT then
    DeRef1(_2487);
    _2487 = (_14previous_op >= 1);
    if (_2487 == 0) {
        goto L2A;
    }
    DeRef1(_2447);
    _2447 = (_14previous_op <= 7);
L2B:
    if (_2447 == 0)
        goto L2A;

    // 	    Code = Code[1..$-1] 
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    rhs_slice_target = (object_ptr)&_4Code;
    RHS_Slice((s1_ptr)_4Code, 1, _2447);

    // 	    if previous_op = NOT then
    if (_14previous_op != 7)
        goto L2C;

    // 		op = NOT_IFW
    _op = 108;

    // 		backpatch(length(Code) - 1, op)
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    _14backpatch(_2447, 108);
    goto L14;
L2C:

    // 		if IsInteger(Code[$-1]) and
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _2447 = (int)*(((s1_ptr)_2)->base + _2447);
    Ref(_2447);
    Ref(_2447);
    _0 = _2447;
    _2447 = _14IsInteger(_2447);
    DeRef1(_0);
    if (_2447 == 0) {
        goto L2D;
    }
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2 = (int)SEQ_PTR(_4Code);
    _2487 = (int)*(((s1_ptr)_2)->base + _2487);
    Ref(_2487);
    Ref(_2487);
    _0 = _2487;
    _2487 = _14IsInteger(_2487);
    DeRef1(_0);
L2E:
    if (_2487 == 0)
        goto L2D;

    // 		    op = previous_op + LESS_IFW_I - LESS
    DeRef1(_2487);
    _2487 = _14previous_op + 119;
    if ((long)((unsigned long)_2487 + (unsigned long)HIGH_BITS) >= 0) 
        _2487 = NewDouble((double)_2487);
    if (IS_ATOM_INT(_2487)) {
        _op = _2487 - 1;
    }
    else {
        _op = NewDouble(DBL_PTR(_2487)->dbl - (double)1);
    }
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }
    goto L2F;
L2D:

    // 		    op = previous_op + LESS_IFW - LESS
    DeRef1(_2487);
    _2487 = _14previous_op + 102;
    if ((long)((unsigned long)_2487 + (unsigned long)HIGH_BITS) >= 0) 
        _2487 = NewDouble((double)_2487);
    if (IS_ATOM_INT(_2487)) {
        _op = _2487 - 1;
    }
    else {
        _op = NewDouble(DBL_PTR(_2487)->dbl - (double)1);
    }
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }
L2F:

    // 		backpatch(length(Code) - 2, op)
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 2;
    _14backpatch(_2487, _op);
L30:
    goto L14;
L2A:

    // 	elsif op = WHILE and    
    DeRef1(_2487);
    _2487 = (_op == 47);
    if (_2487 == 0) {
        _2487 = 0;
        goto L31;
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    if (IS_ATOM_INT(_2447)) {
        _2447 = (_2447 == 2);
    }
    else {
        _2447 = binary_op(EQUALS, _2447, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2447))
        _2487 = (_2447 != 0);
    else
        _2487 = DBL_PTR(_2447)->dbl != 0.0;
L31:
    if (_2487 == 0) {
        DeRef1(_2447);
        _2447 = 0;
        goto L32;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487))
        _2487 = 1;
    else if (IS_ATOM_DBL(_2487))
        _2487 = IS_ATOM_INT(DoubleToInt(_2487));
    else
        _2487 = 0;
    DeRef1(_0);
    _2447 = (_2487 != 0);
L32:
    if (_2447 == 0) {
        goto L33;
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    if (_2447 == 0)
        _2447 = 1;
    else if (IS_ATOM_INT(_2447) && IS_ATOM_INT(0))
        _2447 = 0;
    else
        _2447 = (compare(_2447, 0) == 0);
    DeRef1(_0);
    _2447 = (_2447 == 0);
L34:
    if (_2447 == 0)
        goto L33;

    // 	    optimized_while = TRUE   -- while TRUE ... emit nothing
    _14optimized_while = 1;
    goto L14;
L33:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(a)       
    _14emit_addr(_a);
L35:
    goto L14;
L29:

    //     elsif op = INTEGER_CHECK then
    if (_op != 96)
        goto L36;

    // 	assignable = FALSE
    _14assignable = 0;

    // 	if previous_op = ASSIGN then 
    if (_14previous_op != 18)
        goto L37;

    // 	    c = Code[$-1]
    DeRef1(_2447);
    _2447 = SEQ_PTR(_4Code)->length;
    _2447 = _2447 - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _c = (int)*(((s1_ptr)_2)->base + _2447);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if not IsInteger(c) then
    _2447 = _14IsInteger(_c);
    if (_2447 != 0)
        goto L14;

    // 		emit_opcode(op)
    _14emit_opcode(_op);

    // 		emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L38:
    goto L14;
L37:

    // 	elsif previous_op = -1 or 
    DeRef1(_2447);
    _2447 = (_14previous_op == -1);
    if (_2447 != 0) {
        goto L39;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_14op_result);
    _2487 = (int)*(((s1_ptr)_2)->base + _14previous_op);
    _2487 = (_2487 != 1);
L3A:
    if (_2487 == 0)
        goto L14;
L39:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L3B:
L3C:
    goto L14;
L36:

    //     elsif op = SEQUENCE_CHECK then
    if (_op != 97)
        goto L3D;

    // 	assignable = FALSE
    _14assignable = 0;

    // 	if previous_op = ASSIGN then
    if (_14previous_op != 18)
        goto L3E;

    // 	    c = Code[$-1]
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _c = (int)*(((s1_ptr)_2)->base + _2487);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if SymTab[c][S_MODE] != M_CONSTANT or 
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != 2);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 != 0) {
            goto L3F;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl != 0.0) {
            goto L3F;
        }
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    _2447 = IS_SEQUENCE(_2447);
    DeRef1(_0);
    _2447 = (_2447 == 0);
L40:
    if (_2447 == 0)
        goto L14;
L3F:

    // 		emit_opcode(op)
    _14emit_opcode(_op);

    // 		emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L41:
    goto L14;
L3E:

    // 	elsif previous_op = -1 or 
    DeRef1(_2447);
    _2447 = (_14previous_op == -1);
    if (_2447 != 0) {
        goto L42;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_14op_result);
    _2487 = (int)*(((s1_ptr)_2)->base + _14previous_op);
    _2487 = (_2487 != 3);
L43:
    if (_2487 == 0)
        goto L14;
L42:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L44:
L45:
    goto L14;
L3D:

    //     elsif op = ATOM_CHECK then
    if (_op != 101)
        goto L46;

    // 	assignable = FALSE
    _14assignable = 0;

    // 	if previous_op = ASSIGN then
    if (_14previous_op != 18)
        goto L47;

    // 	    c = Code[$-1]
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _c = (int)*(((s1_ptr)_2)->base + _2487);
    if (!IS_ATOM_INT(_c))
        _c = (long)DBL_PTR(_c)->dbl;

    // 	    if (SymTab[c][S_MODE] != M_CONSTANT or not atom(SymTab[c][S_OBJ])) 
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != 2);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 != 0) {
            DeRef1(_2487);
            _2487 = 1;
            goto L48;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl != 0.0) {
            DeRef1(_2487);
            _2487 = 1;
            goto L48;
        }
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    _2447 = IS_ATOM(_2447);
    DeRef1(_0);
    _2447 = (_2447 == 0);
    DeRef1(_2487);
    _2487 = (_2447 != 0);
L48:
    if (_2487 == 0) {
        goto L14;
    }
    _0 = _2487;
    _2487 = _14IsInteger(_c);
    DeRef1(_0);
    _2487 = (_2487 == 0);
L49:
    if (_2487 == 0)
        goto L14;

    // 		emit_opcode(op)
    _14emit_opcode(_op);

    // 		emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L4A:
    goto L14;
L47:

    // 	elsif previous_op = -1 or 
    DeRef1(_2487);
    _2487 = (_14previous_op == -1);
    if (_2487 != 0) {
        goto L4B;
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_14op_result);
    _2447 = (int)*(((s1_ptr)_2)->base + _14previous_op);
    _2447 = (_2447 != 1);
    if (_2447 == 0) {
        _2447 = 0;
        goto L4C;
    }
    DeRef1(_2462);
    _2 = (int)SEQ_PTR(_14op_result);
    _2462 = (int)*(((s1_ptr)_2)->base + _14previous_op);
    _2462 = (_2462 != 4);
    _2447 = (_2462 != 0);
L4C:
L4D:
    if (_2447 == 0)
        goto L14;
L4B:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(op_info1)
    _14emit_addr(_14op_info1);
L4E:
L4F:
    goto L14;
L46:

    //     elsif op = RIGHT_BRACE_N then -- form a sequence of n items
    if (_op != 31)
        goto L50;

    // 	n = op_info1
    _n = _14op_info1;

    // 	elements = {}
    RefDS(_39);
    DeRef1(_elements);
    _elements = _39;

    // 	for i = 1 to n do
    DeRef1(_2462);
    _2462 = _n;
    { int _i;
        _i = 1;
L51:
        if (_i > _2462)
            goto L52;

        // 	    elements = append(elements, Pop())
        _0 = _2447;
        _2447 = _14Pop();
        DeRef(_0);
        Append(&_elements, _elements, _2447);

        // 	end for
        _i = _i + 1;
        goto L51;
L52:
        ;
    }

    // 	element_vals = good_string(elements)
    RefDS(_elements);
    _0 = _element_vals;
    _element_vals = _14good_string(_elements);
    DeRef1(_0);

    // 	if sequence(element_vals) then
    DeRef1(_2447);
    _2447 = IS_SEQUENCE(_element_vals);
    if (_2447 == 0)
        goto L53;

    // 	    c = NewStringSym(element_vals)  -- make a string literal
    Ref(_element_vals);
    _c = _10NewStringSym(_element_vals);

    // 	    assignable = FALSE
    _14assignable = 0;
    goto L54;
L53:

    // 	    if n = 2 then
    if (_n != 2)
        goto L55;

    // 		emit_opcode(RIGHT_BRACE_2) -- faster op for two items
    _14emit_opcode(85);
    goto L56;
L55:

    // 		emit_opcode(op)
    _14emit_opcode(_op);

    // 		emit(n)
    _14emit(_n);
L56:

    // 	    for i = 1 to n do
    DeRef1(_2447);
    _2447 = _n;
    { int _i;
        _i = 1;
L57:
        if (_i > _2447)
            goto L58;

        // 		emit_addr(elements[i])
        DeRef(_2462);
        _2 = (int)SEQ_PTR(_elements);
        _2462 = (int)*(((s1_ptr)_2)->base + _i);
        _14emit_addr(_2462);

        // 	    end for
        _i = _i + 1;
        goto L57;
L58:
        ;
    }

    // 	    c = NewTempSym()
    _c = _10NewTempSym();

    // 	    emit_addr(c)
    _14emit_addr(_c);

    // 	    assignable = TRUE
    _14assignable = 1;
L54:

    // 	Push(c)
    _14Push(_c);
    goto L14;
L50:

    //     elsif op = ASSIGN_SUBS2 or -- can't change the op
    DeRef1(_2462);
    _2462 = (_op == 150);
    if (_2462 != 0) {
        _2462 = 1;
        goto L59;
    }
    DeRef1(_2447);
    _2447 = (_op == 16);
    _2462 = (_2447 != 0);
L59:
    if (_2462 != 0) {
        goto L5A;
    }
    DeRef1(_2462);
    _2462 = (_op == 164);
L5B:
    if (_2462 == 0)
        goto L5C;
L5A:

    // 	b = Pop() -- rhs value 
    _b = _14Pop();

    // 	a = Pop() -- subscript
    _a = _14Pop();

    // 	c = Pop() -- sequence 
    _c = _14Pop();

    // 	if op = ASSIGN_SUBS then
    if (_op != 16)
        goto L5D;

    // 	    if (previous_op != LHS_SUBS) and 
    DeRef1(_2462);
    _2462 = (_14previous_op != 95);
    if (_2462 == 0) {
        goto L5E;
    }
    DeRef1(_2447);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2447 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2447);
    _0 = _2447;
    _2 = (int)SEQ_PTR(_2447);
    _2447 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2447);
    DeRef1(_0);
    _0 = _2447;
    if (IS_ATOM_INT(_2447)) {
        _2447 = (_2447 != 1);
    }
    else {
        _2447 = binary_op(NOTEQ, _2447, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2447)) {
        if (_2447 != 0) {
            DeRef1(_2447);
            _2447 = 1;
            goto L5F;
        }
    }
    else {
        if (DBL_PTR(_2447)->dbl != 0.0) {
            DeRef1(_2447);
            _2447 = 1;
            goto L5F;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != _10sequence_type);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, _10sequence_type);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            DeRef1(_2487);
            _2487 = 0;
            goto L60;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            DeRef1(_2487);
            _2487 = 0;
            goto L60;
        }
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_2673))
        _2673 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2673)->dbl));
    else
        _2673 = (int)*(((s1_ptr)_2)->base + _2673);
    RefDS(_2673);
    DeRef1(_0);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_2673))
        _2673 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_2673)->dbl));
    else
        _2673 = (int)*(((s1_ptr)_2)->base + _2673);
    RefDS(_2673);
    DeRef1(_0);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 != _10sequence_type);
    }
    else {
        _2673 = binary_op(NOTEQ, _2673, _10sequence_type);
    }
    DeRef1(_0);
    DeRef1(_2487);
    if (IS_ATOM_INT(_2673))
        _2487 = (_2673 != 0);
    else
        _2487 = DBL_PTR(_2673)->dbl != 0.0;
L60:
    DeRef1(_2447);
    _2447 = (_2487 != 0);
L5F:
L61:
    if (_2447 == 0)
        goto L5E;

    // 		op = ASSIGN_SUBS_CHECK
    _op = 84;
    goto L62;
L5E:

    // 		if IsInteger(b) then
    _0 = _2673;
    _2673 = _14IsInteger(_b);
    DeRef1(_0);
    if (_2673 == 0)
        goto L63;

    // 		    op = ASSIGN_SUBS_I
    _op = 118;
L63:
L62:

    // 	    emit_opcode(op)
    _14emit_opcode(_op);
    goto L64;
L5D:

    // 	elsif op = PASSIGN_SUBS then
    if (_op != 164)
        goto L65;

    // 	    emit_opcode(PASSIGN_SUBS) -- always
    _14emit_opcode(164);
    goto L64;
L65:

    // 	    emit_opcode(ASSIGN_SUBS) -- always
    _14emit_opcode(16);
L64:

    // 	emit_addr(c) -- sequence
    _14emit_addr(_c);

    // 	emit_addr(a) -- subscript 
    _14emit_addr(_a);

    // 	emit_addr(b) -- rhs value
    _14emit_addr(_b);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L5C:

    //     elsif op = LHS_SUBS or op = LHS_SUBS1 or op = LHS_SUBS1_COPY then  
    DeRef1(_2673);
    _2673 = (_op == 95);
    if (_2673 != 0) {
        _2673 = 1;
        goto L66;
    }
    DeRef1(_2487);
    _2487 = (_op == 163);
    _2673 = (_2487 != 0);
L66:
    if (_2673 != 0) {
        goto L67;
    }
    DeRef1(_2673);
    _2673 = (_op == 168);
L68:
    if (_2673 == 0)
        goto L69;
L67:

    // 	a = Pop() -- subs
    _a = _14Pop();

    // 	lhs_var = Pop() -- sequence
    _lhs_var = _14Pop();

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(lhs_var)
    _14emit_addr(_lhs_var);

    // 	emit_addr(a)
    _14emit_addr(_a);

    // 	if op = LHS_SUBS then
    if (_op != 95)
        goto L6A;

    // 	    TempKeep(lhs_var) -- should be lhs_target_temp
    _14TempKeep(_lhs_var);

    // 	    emit_addr(lhs_target_temp)
    _14emit_addr(_14lhs_target_temp);

    // 	    Push(lhs_target_temp)
    _14Push(_14lhs_target_temp);

    // 	    emit_addr(0) -- place holder 
    _14emit_addr(0);
    goto L6B;
L6A:

    // 	    lhs_target_temp = NewTempSym() -- use same temp for all subscripts
    _0 = _10NewTempSym();
    _14lhs_target_temp = _0;

    // 	    emit_addr(lhs_target_temp) -- target temp holds pointer to sequence
    _14emit_addr(_14lhs_target_temp);

    // 	    Push(lhs_target_temp)
    _14Push(_14lhs_target_temp);

    // 	    lhs_subs1_copy_temp = NewTempSym() -- place to copy (may be ignored)
    _0 = _10NewTempSym();
    _14lhs_subs1_copy_temp = _0;

    // 	    emit_addr(lhs_subs1_copy_temp)
    _14emit_addr(_14lhs_subs1_copy_temp);
L6B:

    // 	current_sequence = append(current_sequence, lhs_target_temp)
    Append(&_14current_sequence, _14current_sequence, _14lhs_target_temp);

    // 	assignable = FALSE  -- need to update current_sequence like in RHS_SUBS
    _14assignable = 0;
    goto L14;
L69:

    //     elsif find(op, {RAND, PEEK, PEEK4S, PEEK4U, NOT_BITS, NOT, 
    DeRef1(_2673);
    _2673 = find(_op, _2693);
    if (_2673 == 0)
        goto L6C;

    // 	cont11ii(op, TRUE)
    _14cont11ii(_op, 1);
    goto L14;
L6C:

    //     elsif op = UMINUS then
    if (_op != 12)
        goto L6D;

    // 	a = Pop()
    _a = _14Pop();

    // 	obj = SymTab[a][S_OBJ]
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2673);
    DeRef1(_obj);
    _2 = (int)SEQ_PTR(_2673);
    _obj = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_obj);

    // 	if SymTab[a][S_MODE] = M_CONSTANT then
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    if (binary_op_a(NOTEQ, _2673, 2))
        goto L6E;

    // 	    if integer(obj) then
    DeRef1(_2673);
    if (IS_ATOM_INT(_obj))
        _2673 = 1;
    else if (IS_ATOM_DBL(_obj))
        _2673 = IS_ATOM_INT(DoubleToInt(_obj));
    else
        _2673 = 0;
    if (_2673 == 0)
        goto L6F;

    // 		if obj = MININT then
    if (binary_op_a(NOTEQ, _obj, -1073741824))
        goto L70;

    // 		    Push(NewDoubleSym(-MININT_VAL))
    if (-1073741824 == 0xC0000000)
        _2673 = (int)NewDouble((double)-0xC0000000);
    else
        _2673 = - -1073741824;
    Ref(_2673);
    _0 = _2673;
    _2673 = _10NewDoubleSym(_2673);
    DeRef1(_0);
    _14Push(_2673);
    goto L14;
L70:

    // 		    Push(NewIntSym(-obj))
    DeRef1(_2673);
    if (IS_ATOM_INT(_obj)) {
        if (_obj == 0xC0000000)
            _2673 = (int)NewDouble((double)-0xC0000000);
        else
            _2673 = - _obj;
    }
    else {
        _2673 = unary_op(UMINUS, _obj);
    }
    Ref(_2673);
    _0 = _2673;
    _2673 = _10NewIntSym(_2673);
    DeRef1(_0);
    _14Push(_2673);
L71:
    goto L14;
L6F:

    // 	    elsif atom(obj) and obj != NOVALUE then
    DeRef1(_2673);
    _2673 = IS_ATOM(_obj);
    if (_2673 == 0) {
        goto L72;
    }
    DeRef1(_2487);
    _2487 = binary_op(NOTEQ, _obj, _4NOVALUE);
L73:
    if (_2487 == 0) {
        goto L72;
    }
    else {
        if (!IS_ATOM_INT(_2487) && DBL_PTR(_2487)->dbl == 0.0)
            goto L72;
    }

    // 		Push(NewDoubleSym(-obj)) 
    DeRef1(_2487);
    if (IS_ATOM_INT(_obj)) {
        if (_obj == 0xC0000000)
            _2487 = (int)NewDouble((double)-0xC0000000);
        else
            _2487 = - _obj;
    }
    else {
        _2487 = unary_op(UMINUS, _obj);
    }
    Ref(_2487);
    _0 = _2487;
    _2487 = _10NewDoubleSym(_2487);
    DeRef1(_0);
    _14Push(_2487);
    goto L14;
L72:

    // 		Push(a)
    _14Push(_a);

    // 		cont11ii(op, FALSE)   
    _14cont11ii(_op, 0);
L74:
    goto L14;
L6E:

    // 	elsif TRANSLATE and SymTab[a][S_MODE] = M_TEMP and 
    if (1 == 0) {
        DeRef1(_2487);
        _2487 = 0;
        goto L75;
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 == 3);
    }
    else {
        _2673 = binary_op(EQUALS, _2673, 3);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2673))
        _2487 = (_2673 != 0);
    else
        _2487 = DBL_PTR(_2673)->dbl != 0.0;
L75:
    if (_2487 == 0) {
        goto L76;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 == 2);
    }
    else {
        _2487 = binary_op(EQUALS, _2487, 2);
    }
    DeRef1(_0);
L77:
    if (_2487 == 0) {
        goto L76;
    }
    else {
        if (!IS_ATOM_INT(_2487) && DBL_PTR(_2487)->dbl == 0.0)
            goto L76;
    }

    // 	    Push(NewDoubleSym(-obj)) 
    DeRef1(_2487);
    if (IS_ATOM_INT(_obj)) {
        if (_obj == 0xC0000000)
            _2487 = (int)NewDouble((double)-0xC0000000);
        else
            _2487 = - _obj;
    }
    else {
        _2487 = unary_op(UMINUS, _obj);
    }
    Ref(_2487);
    _0 = _2487;
    _2487 = _10NewDoubleSym(_2487);
    DeRef1(_0);
    _14Push(_2487);
    goto L14;
L76:

    // 	    Push(a)
    _14Push(_a);

    // 	    cont11ii(op, FALSE)   
    _14cont11ii(_op, 0);
L78:
    goto L14;
L6D:

    //     elsif find(op, {IS_AN_INTEGER, IS_AN_ATOM, IS_A_SEQUENCE, IS_AN_OBJECT,
    DeRef1(_2487);
    _2487 = find(_op, _2723);
    if (_2487 == 0)
        goto L79;

    // 	cont11ii(op, FALSE)   
    _14cont11ii(_op, 0);
    goto L14;
L79:

    //     elsif op = ROUTINE_ID then
    if (_op != 136)
        goto L7A;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	source = Pop()
    _source = _14Pop();

    // 	if TRANSLATE then

    // 	    emit_addr(num_routines-1)
    DeRef1(_2487);
    _2487 = _4num_routines - 1;
    if ((long)((unsigned long)_2487 +(unsigned long) HIGH_BITS) >= 0)
        _2487 = NewDouble((double)_2487);
    Ref(_2487);
    _14emit_addr(_2487);

    // 	    last_routine_id = num_routines
    _14last_routine_id = _4num_routines;

    // 	    last_max_params = max_params
    _14last_max_params = _14max_params;

    // 	    MarkTargets(source, S_RI_TARGET)
    _10MarkTargets(_source, 33);
    goto L7B;
L7C:

    // 	    emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);

    // 	    emit_addr(length(SymTab))
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4SymTab)->length;
    _14emit_addr(_2487);

    // 	    if BIND then
L7B:

    // 	emit_addr(source)
    _14emit_addr(_source);

    // 	emit_addr(current_file_no)  -- necessary at top level
    _14emit_addr(_4current_file_no);

    // 	assignable = TRUE
    _14assignable = 1;

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	TempInteger(c) -- result will always be an integer
    _14TempInteger(_c);

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);
    goto L14;
L7A:

    //     elsif op = SC1_OR or op = SC1_AND then
    DeRef1(_2487);
    _2487 = (_op == 145);
    if (_2487 != 0) {
        goto L7D;
    }
    DeRef1(_2673);
    _2673 = (_op == 143);
L7E:
    if (_2673 == 0)
        goto L7F;
L7D:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(Pop())       
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L7F:

    //     elsif find(op, {SYSTEM, PUTS, PRINT, QPRINT, POSITION, MACHINE_PROC,
    DeRef1(_2673);
    _2673 = find(_op, _2735);
    if (_2673 == 0)
        goto L80;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	b = Pop()
    _b = _14Pop();

    // 	emit_addr(Pop())
    _2673 = _14Pop();
    _14emit_addr(_2673);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	if op = C_PROC then
    if (_op != 134)
        goto L81;

    // 	    emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);
L81:

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L80:

    //     elsif find(op, {EQUALS, LESS, GREATER, NOTEQ, LESSEQ, GREATEREQ,
    DeRef1(_2673);
    _2673 = find(_op, _2740);
    if (_2673 == 0)
        goto L82;

    // 	cont21ii(op, TRUE)  -- both integer args => integer result
    _14cont21ii(_op, 1);
    goto L14;
L82:

    //     elsif op = PLUS then
    if (_op != 11)
        goto L83;

    // 	b = Pop()
    _b = _14Pop();

    // 	a = Pop()
    _a = _14Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 1) then 
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 == 2);
    }
    else {
        _2673 = binary_op(EQUALS, _2673, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2673)) {
        if (_2673 == 0) {
            goto L84;
        }
    }
    else {
        if (DBL_PTR(_2673)->dbl == 0.0) {
            goto L84;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (_2487 == 1)
        _2487 = 1;
    else if (IS_ATOM_INT(_2487) && IS_ATOM_INT(1))
        _2487 = 0;
    else
        _2487 = (compare(_2487, 1) == 0);
    DeRef1(_0);
L85:
    if (_2487 == 0)
        goto L84;

    // 	    op = PLUS1
    _op = 93;

    // 	    emit_opcode(op)
    _14emit_opcode(93);

    // 	    emit_addr(a)
    _14emit_addr(_a);

    // 	    emit_addr(0)
    _14emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)
    _14cont21d(93, _a, _b, 0);
    goto L14;
L84:

    // 	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 1) then
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 == 2);
    }
    else {
        _2487 = binary_op(EQUALS, _2487, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            goto L86;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            goto L86;
        }
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (_2673 == 1)
        _2673 = 1;
    else if (IS_ATOM_INT(_2673) && IS_ATOM_INT(1))
        _2673 = 0;
    else
        _2673 = (compare(_2673, 1) == 0);
    DeRef1(_0);
L87:
    if (_2673 == 0)
        goto L86;

    // 	    op = PLUS1
    _op = 93;

    // 	    emit_opcode(op)
    _14emit_opcode(93);

    // 	    emit_addr(b)
    _14emit_addr(_b);

    // 	    emit_addr(0)
    _14emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)
    _14cont21d(93, _a, _b, 0);
    goto L14;
L86:

    // 	    Push(a)
    _14Push(_a);

    // 	    Push(b)
    _14Push(_b);

    // 	    cont21ii(op, FALSE)
    _14cont21ii(_op, 0);
L88:
    goto L14;
L83:

    //     elsif op = MULTIPLY then
    if (_op != 13)
        goto L89;

    // 	b = Pop()
    _b = _14Pop();

    // 	a = Pop()
    _a = _14Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 == 2);
    }
    else {
        _2673 = binary_op(EQUALS, _2673, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2673)) {
        if (_2673 == 0) {
            goto L8A;
        }
    }
    else {
        if (DBL_PTR(_2673)->dbl == 0.0) {
            goto L8A;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (_2487 == 2)
        _2487 = 1;
    else if (IS_ATOM_INT(_2487) && IS_ATOM_INT(2))
        _2487 = 0;
    else
        _2487 = (compare(_2487, 2) == 0);
    DeRef1(_0);
L8B:
    if (_2487 == 0)
        goto L8A;

    // 	    op = PLUS
    _op = 11;

    // 	    emit_opcode(op)
    _14emit_opcode(11);

    // 	    emit_addr(a)
    _14emit_addr(_a);

    // 	    emit_addr(a)
    _14emit_addr(_a);

    // 	    cont21d(op, a, b, FALSE)
    _14cont21d(11, _a, _b, 0);
    goto L14;
L8A:

    // 	elsif SymTab[a][S_MODE] = M_CONSTANT and equal(SymTab[a][S_OBJ], 2) then
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 == 2);
    }
    else {
        _2487 = binary_op(EQUALS, _2487, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            goto L8C;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            goto L8C;
        }
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _a);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (_2673 == 2)
        _2673 = 1;
    else if (IS_ATOM_INT(_2673) && IS_ATOM_INT(2))
        _2673 = 0;
    else
        _2673 = (compare(_2673, 2) == 0);
    DeRef1(_0);
L8D:
    if (_2673 == 0)
        goto L8C;

    // 	    op = PLUS
    _op = 11;

    // 	    emit_opcode(op)
    _14emit_opcode(11);

    // 	    emit_addr(b)
    _14emit_addr(_b);

    // 	    emit_addr(b)
    _14emit_addr(_b);

    // 	    cont21d(op, a, b, FALSE)
    _14cont21d(11, _a, _b, 0);
    goto L14;
L8C:

    // 	    Push(a)
    _14Push(_a);

    // 	    Push(b)
    _14Push(_b);

    // 	    cont21ii(op, FALSE)
    _14cont21ii(_op, 0);
L8E:
    goto L14;
L89:

    //     elsif op = DIVIDE then
    if (_op != 14)
        goto L8F;

    // 	b = Pop()
    _b = _14Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 == 2);
    }
    else {
        _2673 = binary_op(EQUALS, _2673, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2673)) {
        if (_2673 == 0) {
            goto L90;
        }
    }
    else {
        if (DBL_PTR(_2673)->dbl == 0.0) {
            goto L90;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (_2487 == 2)
        _2487 = 1;
    else if (IS_ATOM_INT(_2487) && IS_ATOM_INT(2))
        _2487 = 0;
    else
        _2487 = (compare(_2487, 2) == 0);
    DeRef1(_0);
L91:
    if (_2487 == 0)
        goto L90;

    // 	    op = DIV2
    _op = 98;

    // 	    emit_opcode(op)
    _14emit_opcode(98);

    // 	    emit_addr(Pop()) -- n.b. "a" hasn't been set
    _0 = _2487;
    _2487 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2487);

    // 	    a = 0
    _a = 0;

    // 	    emit_addr(0)
    _14emit_addr(0);

    // 	    cont21d(op, a, b, FALSE)  -- could have fractional result
    _14cont21d(98, 0, _b, 0);
    goto L14;
L90:

    // 	    Push(b) 
    _14Push(_b);

    // 	    cont21ii(op, FALSE)
    _14cont21ii(_op, 0);
L92:
    goto L14;
L8F:

    //     elsif op = FLOOR then
    if (_op != 83)
        goto L93;

    // 	if previous_op = DIVIDE then
    if (_14previous_op != 14)
        goto L94;

    // 	    op = FLOOR_DIV
    _op = 63;

    // 	    backpatch(length(Code) - 3, op)
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 3;
    _14backpatch(_2487, 63);

    // 	    assignable = TRUE
    _14assignable = 1;
    goto L14;
L94:

    // 	elsif previous_op = DIV2 then
    if (_14previous_op != 98)
        goto L95;

    // 	    op = FLOOR_DIV2
    _op = 66;

    // 	    backpatch(length(Code) - 3, op)
    DeRef1(_2487);
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 3;
    _14backpatch(_2487, 66);

    // 	    assignable = TRUE
    _14assignable = 1;

    // 	    if IsInteger(Code[$-2]) then
    _2487 = SEQ_PTR(_4Code)->length;
    _2487 = _2487 - 2;
    _2 = (int)SEQ_PTR(_4Code);
    _2487 = (int)*(((s1_ptr)_2)->base + _2487);
    Ref(_2487);
    Ref(_2487);
    _0 = _2487;
    _2487 = _14IsInteger(_2487);
    DeRef1(_0);
    if (_2487 == 0)
        goto L14;

    // 		TempInteger(Top()) --mark temp as integer type
    _2487 = _14Top();
    _14TempInteger(_2487);
L96:
    goto L14;
L95:

    // 	    cont11ii(op, TRUE)
    _14cont11ii(_op, 1);
L97:
    goto L14;
L93:

    //     elsif find(op, {MINUS, APPEND, PREPEND, COMPARE, EQUAL, FIND, MATCH,
    DeRef1(_2487);
    _2487 = find(_op, _2798);
    if (_2487 == 0)
        goto L98;

    // 	cont21ii(op, FALSE)
    _14cont21ii(_op, 0);
    goto L14;
L98:

    //     elsif op = SC2_NULL then  -- correct the stack - we aren't emitting anything
    if (_op != 147)
        goto L99;

    // 	c = Pop()
    _c = _14Pop();

    // 	TempKeep(c)
    _14TempKeep(_c);

    // 	b = Pop()  -- remove SC1's temp
    _b = _14Pop();

    // 	Push(c)
    _14Push(_c);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L99:

    //     elsif op = SC2_AND or op = SC2_OR then
    DeRef1(_2487);
    _2487 = (_op == 144);
    if (_2487 != 0) {
        goto L9A;
    }
    DeRef1(_2673);
    _2673 = (_op == 146);
L9B:
    if (_2673 == 0)
        goto L9C;
L9A:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(Pop())       
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	c = Pop()
    _c = _14Pop();

    // 	TempKeep(c)
    _14TempKeep(_c);

    // 	emit_addr(c) -- target
    _14emit_addr(_c);

    // 	TempInteger(c)
    _14TempInteger(_c);

    // 	Push(c)
    _14Push(_c);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L9C:

    //     elsif find(op, {MEM_COPY, MEM_SET, PRINTF}) then
    DeRef1(_2673);
    _2673 = find(_op, _2808);
    if (_2673 == 0)
        goto L9D;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	c = Pop()
    _c = _14Pop();

    // 	b = Pop()
    _b = _14Pop();

    // 	emit_addr(Pop())
    _2673 = _14Pop();
    _14emit_addr(_2673);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
L9D:

    //     elsif op = RHS_SLICE or op = FIND_FROM or op = MATCH_FROM then 
    DeRef1(_2673);
    _2673 = (_op == 46);
    if (_2673 != 0) {
        _2673 = 1;
        goto L9E;
    }
    DeRef1(_2487);
    _2487 = (_op == 178);
    _2673 = (_2487 != 0);
L9E:
    if (_2673 != 0) {
        goto L9F;
    }
    DeRef1(_2673);
    _2673 = (_op == 179);
LA0:
    if (_2673 == 0)
        goto LA1;
L9F:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	c = Pop()
    _c = _14Pop();

    // 	b = Pop()
    _b = _14Pop();

    // 	emit_addr(Pop())
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	assignable = TRUE
    _14assignable = 1;

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);
    goto L14;
LA1:

    //     elsif op = CONCAT_N then     -- concatenate 3 or more items
    if (_op != 159)
        goto LA2;

    // 	n = op_info1  -- number of items to concatenate
    _n = _14op_info1;

    // 	emit_opcode(CONCAT_N)
    _14emit_opcode(159);

    // 	emit(n)
    _14emit(_n);

    // 	for i = 1 to n do 
    DeRef1(_2673);
    _2673 = _n;
    { int _i;
        _i = 1;
LA3:
        if (_i > _2673)
            goto LA4;

        // 	    emit_addr(Pop())  -- reverse order
        _0 = _2487;
        _2487 = _14Pop();
        DeRef(_0);
        _14emit_addr(_2487);

        // 	end for
        _i = _i + 1;
        goto LA3;
LA4:
        ;
    }

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	assignable = TRUE
    _14assignable = 1;

    // 	Push(c)
    _14Push(_c);
    goto L14;
LA2:

    //     elsif op = FOR then
    if (_op != 21)
        goto LA5;

    // 	c = Pop() -- increment 
    _c = _14Pop();

    // 	TempKeep(c)
    _14TempKeep(_c);

    // 	ic = IsInteger(c)
    _ic = _14IsInteger(_c);

    // 	if SymTab[c][S_MODE] = M_NORMAL and 
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 == 1);
    }
    else {
        _2487 = binary_op(EQUALS, _2487, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            DeRef1(_2487);
            _2487 = 0;
            goto LA6;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            DeRef1(_2487);
            _2487 = 0;
            goto LA6;
        }
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 != 2);
    }
    else {
        _2673 = binary_op(NOTEQ, _2673, 2);
    }
    DeRef1(_0);
    DeRef1(_2487);
    if (IS_ATOM_INT(_2673))
        _2487 = (_2673 != 0);
    else
        _2487 = DBL_PTR(_2673)->dbl != 0.0;
LA6:
    if (_2487 == 0) {
        goto LA7;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _c);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != 4);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, 4);
    }
    DeRef1(_0);
LA8:
    if (_2487 == 0) {
        goto LA7;
    }
    else {
        if (!IS_ATOM_INT(_2487) && DBL_PTR(_2487)->dbl == 0.0)
            goto LA7;
    }

    // 	    emit_opcode(ASSIGN)
    _14emit_opcode(18);

    // 	    emit_addr(c)
    _14emit_addr(_c);

    // 	    c = NewTempSym()
    _c = _10NewTempSym();

    // 	    emit_addr(c)
    _14emit_addr(_c);
LA7:

    // 	b = Pop() -- limit 
    _b = _14Pop();

    // 	TempKeep(b)
    _14TempKeep(_b);

    // 	ib = IsInteger(b)
    _ib = _14IsInteger(_b);

    // 	if SymTab[b][S_MODE] = M_NORMAL and 
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 == 1);
    }
    else {
        _2487 = binary_op(EQUALS, _2487, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2487)) {
        if (_2487 == 0) {
            DeRef1(_2487);
            _2487 = 0;
            goto LA9;
        }
    }
    else {
        if (DBL_PTR(_2487)->dbl == 0.0) {
            DeRef1(_2487);
            _2487 = 0;
            goto LA9;
        }
    }
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 != 2);
    }
    else {
        _2673 = binary_op(NOTEQ, _2673, 2);
    }
    DeRef1(_0);
    DeRef1(_2487);
    if (IS_ATOM_INT(_2673))
        _2487 = (_2673 != 0);
    else
        _2487 = DBL_PTR(_2673)->dbl != 0.0;
LA9:
    if (_2487 == 0) {
        goto LAA;
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (IS_ATOM_INT(_2487)) {
        _2487 = (_2487 != 4);
    }
    else {
        _2487 = binary_op(NOTEQ, _2487, 4);
    }
    DeRef1(_0);
LAB:
    if (_2487 == 0) {
        goto LAA;
    }
    else {
        if (!IS_ATOM_INT(_2487) && DBL_PTR(_2487)->dbl == 0.0)
            goto LAA;
    }

    // 	    emit_opcode(ASSIGN)
    _14emit_opcode(18);

    // 	    emit_addr(b)
    _14emit_addr(_b);

    // 	    b = NewTempSym()
    _b = _10NewTempSym();

    // 	    emit_addr(b)
    _14emit_addr(_b);
LAA:

    // 	a = Pop() -- initial value 
    _a = _14Pop();

    // 	if IsInteger(a) and ib and ic then
    _0 = _2487;
    _2487 = _14IsInteger(_a);
    DeRef1(_0);
    if (_2487 == 0) {
        _2487 = 0;
        goto LAC;
    }
    _2487 = (_ib != 0);
LAC:
    if (_2487 == 0) {
        goto LAD;
    }
LAE:
    if (_ic == 0)
        goto LAD;

    // 	    SymTab[op_info1][S_VTYPE] = integer_type
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_14op_info1 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _10integer_type;
    DeRef(_1);

    // 	    op = FOR_I
    _op = 125;
    goto LAF;
LAD:

    // 	    op = FOR
    _op = 21;
LAF:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	emit_addr(a)
    _14emit_addr(_a);

    // 	emit_addr(CurrentSub) -- in case recursion check is needed
    _14emit_addr(_4CurrentSub);

    // 	Push(b)
    _14Push(_b);

    // 	Push(c)
    _14Push(_c);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LA5:

    //     elsif op = ENDFOR_GENERAL or op = ENDFOR_INT_UP1 then  -- all ENDFORs  
    DeRef1(_2673);
    _2673 = (_op == 39);
    if (_2673 != 0) {
        goto LB0;
    }
    DeRef1(_2487);
    _2487 = (_op == 54);
LB1:
    if (_2487 == 0)
        goto LB2;
LB0:

    // 	emit_opcode(op) -- will be patched at runtime 
    _14emit_opcode(_op);

    // 	a = Pop() 
    _a = _14Pop();

    // 	emit_addr(op_info2) -- address of top of loop 
    _14emit_addr(_14op_info2);

    // 	emit_addr(Pop())    -- limit 
    _0 = _2487;
    _2487 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2487);

    // 	emit_addr(op_info1) -- loop var 
    _14emit_addr(_14op_info1);

    // 	emit_addr(a)        -- increment - not always used - 
    _14emit_addr(_a);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LB2:

    //     elsif op = ASSIGN_OP_SUBS or op = PASSIGN_OP_SUBS then   
    DeRef1(_2487);
    _2487 = (_op == 151);
    if (_2487 != 0) {
        goto LB3;
    }
    DeRef1(_2673);
    _2673 = (_op == 166);
LB4:
    if (_2673 == 0)
        goto LB5;
LB3:

    // 	b = Pop()      -- rhs value, keep on stack 
    _b = _14Pop();

    // 	TempKeep(b)
    _14TempKeep(_b);

    // 	a = Pop()      -- subscript, keep on stack
    _a = _14Pop();

    // 	TempKeep(a)
    _14TempKeep(_a);

    // 	c = Pop()      -- lhs sequence, keep on stack
    _c = _14Pop();

    // 	TempKeep(c)
    _14TempKeep(_c);

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(c)  
    _14emit_addr(_c);

    // 	emit_addr(a)    
    _14emit_addr(_a);

    // 	d = NewTempSym()
    _d = _10NewTempSym();

    // 	emit_addr(d)   -- place to store result
    _14emit_addr(_d);

    // 	Push(c)
    _14Push(_c);

    // 	Push(a)
    _14Push(_a);

    // 	Push(d)
    _14Push(_d);

    // 	Push(b)
    _14Push(_b);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LB5:

    //     elsif op = ASSIGN_SLICE or op = PASSIGN_SLICE then
    DeRef1(_2673);
    _2673 = (_op == 45);
    if (_2673 != 0) {
        goto LB6;
    }
    DeRef1(_2487);
    _2487 = (_op == 165);
LB7:
    if (_2487 == 0)
        goto LB8;
LB6:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	b = Pop() -- rhs value
    _b = _14Pop();

    // 	a = Pop() -- 2nd subs
    _a = _14Pop();

    // 	c = Pop() -- 1st subs 
    _c = _14Pop();

    // 	emit_addr(Pop()) -- sequence
    _0 = _2487;
    _2487 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2487);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	emit_addr(a)  
    _14emit_addr(_a);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LB8:

    //     elsif op = ASSIGN_OP_SLICE or op = PASSIGN_OP_SLICE then  
    DeRef1(_2487);
    _2487 = (_op == 152);
    if (_2487 != 0) {
        goto LB9;
    }
    DeRef1(_2673);
    _2673 = (_op == 167);
LBA:
    if (_2673 == 0)
        goto LBB;
LB9:

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	b = Pop()        -- rhs value not used
    _b = _14Pop();

    // 	TempKeep(b)
    _14TempKeep(_b);

    // 	a = Pop()        -- 2nd subs
    _a = _14Pop();

    // 	TempKeep(a)
    _14TempKeep(_a);

    // 	c = Pop()        -- 1st subs
    _c = _14Pop();

    // 	TempKeep(c)
    _14TempKeep(_c);

    // 	d = Pop()
    _d = _14Pop();

    // 	TempKeep(d)      -- sequence   
    _14TempKeep(_d);

    // 	emit_addr(d) 
    _14emit_addr(_d);

    // 	Push(d)
    _14Push(_d);

    // 	emit_addr(c) 
    _14emit_addr(_c);

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(a) 
    _14emit_addr(_a);

    // 	Push(a)
    _14Push(_a);

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)     -- place to store result
    _14emit_addr(_c);

    // 	Push(b)
    _14Push(_b);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LBB:

    //     elsif op = CALL_PROC then
    if (_op != 138)
        goto LBC;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	b = Pop()
    _b = _14Pop();

    // 	emit_addr(Pop())
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LBC:

    //     elsif op = CALL_FUNC then
    if (_op != 139)
        goto LBD;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	b = Pop()
    _b = _14Pop();

    // 	emit_addr(Pop())
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	emit_addr(b)
    _14emit_addr(_b);

    // 	assignable = TRUE
    _14assignable = 1;

    // 	c = NewTempSym() 
    _c = _10NewTempSym();

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);
    goto L14;
LBD:

    //     elsif op = RETURNP then
    if (_op != 29)
        goto LBE;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LBE:

    //     elsif op = RETURNF then
    if (_op != 28)
        goto LBF;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);

    // 	emit_addr(Pop())
    _0 = _2673;
    _2673 = _14Pop();
    DeRef1(_0);
    _14emit_addr(_2673);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LBF:

    //     elsif op = RETURNT then
    if (_op != 34)
        goto LC0;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LC0:

    //     elsif find(op, {DATE, TIME, SPACE_USED, GET_KEY, TASK_LIST, 
    DeRef1(_2673);
    _2673 = find(_op, _2899);
    if (_2673 == 0)
        goto LC1;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	assignable = TRUE
    _14assignable = 1;

    // 	if op = GET_KEY then  -- it's in op_result as integer
    if (_op != 79)
        goto LC2;

    // 	    TempInteger(c)
    _14TempInteger(_c);
LC2:

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);
    goto L14;
LC1:

    //     elsif find(op, {CLOSE, ABORT, CALL}) then
    DeRef1(_2673);
    _2673 = find(_op, _2903);
    if (_2673 == 0)
        goto LC3;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(Pop())       
    _2673 = _14Pop();
    _14emit_addr(_2673);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LC3:

    //     elsif op = POWER then
    if (_op != 72)
        goto LC4;

    // 	b = Pop()
    _b = _14Pop();

    // 	a = Pop()
    _a = _14Pop();

    // 	if SymTab[b][S_MODE] = M_CONSTANT and equal(SymTab[b][S_OBJ], 2) then 
    DeRef1(_2673);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2673 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2673);
    _0 = _2673;
    _2 = (int)SEQ_PTR(_2673);
    _2673 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_2673);
    DeRef1(_0);
    _0 = _2673;
    if (IS_ATOM_INT(_2673)) {
        _2673 = (_2673 == 2);
    }
    else {
        _2673 = binary_op(EQUALS, _2673, 2);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_2673)) {
        if (_2673 == 0) {
            goto LC5;
        }
    }
    else {
        if (DBL_PTR(_2673)->dbl == 0.0) {
            goto LC5;
        }
    }
    DeRef1(_2487);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2487 = (int)*(((s1_ptr)_2)->base + _b);
    RefDS(_2487);
    _0 = _2487;
    _2 = (int)SEQ_PTR(_2487);
    _2487 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_2487);
    DeRef1(_0);
    _0 = _2487;
    if (_2487 == 2)
        _2487 = 1;
    else if (IS_ATOM_INT(_2487) && IS_ATOM_INT(2))
        _2487 = 0;
    else
        _2487 = (compare(_2487, 2) == 0);
    DeRef1(_0);
LC6:
    if (_2487 == 0)
        goto LC5;

    // 	    op = MULTIPLY
    _op = 13;

    // 	    emit_opcode(op)
    _14emit_opcode(13);

    // 	    emit_addr(a)
    _14emit_addr(_a);

    // 	    emit_addr(a)
    _14emit_addr(_a);

    // 	    cont21d(op, a, b, FALSE)
    _14cont21d(13, _a, _b, 0);
    goto L14;
LC5:

    // 	    Push(a)
    _14Push(_a);

    // 	    Push(b)
    _14Push(_b);

    // 	    cont21ii(op, FALSE)
    _14cont21ii(_op, 0);
LC7:
    goto L14;
LC4:

    //     elsif op = TYPE_CHECK then
    if (_op != 65)
        goto LC8;

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	c = Pop()       
    _c = _14Pop();

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LC8:

    //     elsif op = DOLLAR then
    if (_op != -22)
        goto LC9;

    // 	if lhs_ptr and length(current_sequence) = 1 then
    if (_14lhs_ptr == 0) {
        goto LCA;
    }
    DeRef1(_2673);
    _2673 = SEQ_PTR(_14current_sequence)->length;
    _2673 = (_2673 == 1);
LCB:
    if (_2673 == 0)
        goto LCA;

    // 	    emit_opcode(PLENGTH)
    _14emit_opcode(162);
    goto LCC;
LCA:

    // 	    emit_opcode(LENGTH) 
    _14emit_opcode(42);
LCC:

    // 	emit_addr(current_sequence[$])
    DeRef1(_2673);
    _2673 = SEQ_PTR(_14current_sequence)->length;
    _2 = (int)SEQ_PTR(_14current_sequence);
    _2673 = (int)*(((s1_ptr)_2)->base + _2673);
    _14emit_addr(_2673);

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	TempInteger(c)
    _14TempInteger(_c);

    // 	Push(c)
    _14Push(_c);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	assignable = FALSE -- it wouldn't be assigned anyway
    _14assignable = 0;
    goto L14;
LC9:

    //     elsif op = TASK_SELF then
    if (_op != 172)
        goto LCD;

    // 	c = NewTempSym()
    _c = _10NewTempSym();

    // 	TempInteger(c)
    _14TempInteger(_c);

    // 	Push(c)
    _14Push(_c);

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(c)
    _14emit_addr(_c);

    // 	assignable = TRUE
    _14assignable = 1;
    goto L14;
LCD:

    //     elsif op = PLATFORM then
    if (_op != 157)
        goto LCE;

    // 	if BIND and shroud_only then
    if (0 == 0) {
        goto LCF;
    }
LD0:
    goto LCF;

    // 	    c = NewTempSym()
    _c = _10NewTempSym();

    // 	    TempInteger(c)
    _14TempInteger(_c);

    // 	    Push(c)
    _14Push(_c);

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(c)
    _14emit_addr(_c);

    // 	    assignable = TRUE
    _14assignable = 1;
    goto L14;
LCF:

    // 	    if ELINUX then
    if (_4ELINUX == 0)
        goto LD1;

    // 		n = 3
    _n = 3;
    goto LD2;
LD1:

    // 	    elsif BIND then

    // 	    elsif EDOS then        
    if (_4EDOS == 0)
        goto LD3;

    // 		n = 1
    _n = 1;
    goto LD2;
LD3:

    // 	    elsif EWINDOWS then
    if (_4EWINDOWS == 0)
        goto LD4;

    // 		n = 2 
    _n = 2;
LD4:
LD2:

    // 	    Push(NewIntSym(n))
    _0 = _2673;
    _2673 = _10NewIntSym(_n);
    DeRef1(_0);
    _14Push(_2673);

    // 	    assignable = FALSE
    _14assignable = 0;
LD5:
    goto L14;
LCE:

    //     elsif find(op, {PROFILE, TASK_SUSPEND}) then
    DeRef1(_2673);
    _2673 = find(_op, _2932);
    if (_2673 == 0)
        goto LD6;

    // 	a = Pop()
    _a = _14Pop();

    // 	emit_opcode(op)
    _14emit_opcode(_op);

    // 	emit_addr(a)       
    _14emit_addr(_a);

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LD6:

    //     elsif op = TRACE then
    if (_op != 64)
        goto LD7;

    // 	a = Pop()
    _a = _14Pop();

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto LD8;

    // 	    emit_opcode(op)
    _14emit_opcode(_op);

    // 	    emit_addr(a)       
    _14emit_addr(_a);

    // 	    if TRANSLATE then

    // 		if not trace_called then
    if (_14trace_called != 0)
        goto LD9;

    // 		    Warning("Statements have been inserted to trace execution of your program.")
    RefDS(_2938);
    _6Warning(_2938);
LD9:

    // 		trace_called = TRUE
    _14trace_called = 1;
LDA:
LD8:

    // 	assignable = FALSE
    _14assignable = 0;
    goto L14;
LD7:

    // 	InternalErr(sprintf("unknown opcode: %d", op))
    DeRef1(_2673);
    _2673 = EPrintf(-9999999, _2939, _op);
    RefDS(_2673);
    _6InternalErr(_2673);
L14:

    //     previous_op = op
    _14previous_op = _op;

    // end procedure
    DeRef1(_obj);
    DeRef1(_elements);
    DeRef1(_element_vals);
    DeRef(_2673);
    DeRef(_2487);
    DeRef(_2447);
    DeRef(_2462);
    return 0;
    ;
}


