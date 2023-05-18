// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _15Assignment(int _left_var)
{
    int _tok = 0;
    int _subs;
    int _slice;
    int _assign_op;
    int _subs1_patch;
    int _dangerous;
    int _3369 = 0;
    int _3367 = 0;
    int _3350 = 0;
    int _3345 = 0;
    int _0, _1, _2, _3;
    

    //     left_sym = left_var[T_SYM]
    _2 = (int)SEQ_PTR(_left_var);
    _15left_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_15left_sym))
        _15left_sym = (long)DBL_PTR(_15left_sym)->dbl;

    //     UndefinedVar(left_sym)
    _15UndefinedVar(_15left_sym);

    //     if SymTab[left_sym][S_SCOPE] = SC_LOOP_VAR or 
    _2 = (int)SEQ_PTR(_4SymTab);
    _3345 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3345);
    _0 = _3345;
    _2 = (int)SEQ_PTR(_3345);
    _3345 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3345);
    DeRefDS(_0);
    _0 = _3345;
    if (IS_ATOM_INT(_3345)) {
        _3345 = (_3345 == 2);
    }
    else {
        _3345 = binary_op(EQUALS, _3345, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3345)) {
        if (_3345 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_3345)->dbl != 0.0) {
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_4SymTab);
    _3350 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3350);
    _0 = _3350;
    _2 = (int)SEQ_PTR(_3350);
    _3350 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3350);
    DeRefDS(_0);
    _0 = _3350;
    if (IS_ATOM_INT(_3350)) {
        _3350 = (_3350 == 4);
    }
    else {
        _3350 = binary_op(EQUALS, _3350, 4);
    }
    DeRef(_0);
L2:
    if (_3350 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_3350) && DBL_PTR(_3350)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	CompileErr("may not assign to a for-loop variable")
    RefDS(_3353);
    _6CompileErr(_3353);
    goto L4;
L3:

    //     elsif SymTab[left_sym][S_MODE] = M_CONSTANT then
    DeRef(_3350);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3350 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3350);
    _0 = _3350;
    _2 = (int)SEQ_PTR(_3350);
    _3350 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_3350);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3350, 2))
        goto L5;

    // 	CompileErr("may not change the value of a constant")
    RefDS(_3357);
    _6CompileErr(_3357);
    goto L4;
L5:

    //     elsif SymTab[left_sym][S_SCOPE] = SC_LOCAL or 
    DeRef(_3350);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3350 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3350);
    _0 = _3350;
    _2 = (int)SEQ_PTR(_3350);
    _3350 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3350);
    DeRefDS(_0);
    _0 = _3350;
    if (IS_ATOM_INT(_3350)) {
        _3350 = (_3350 == 5);
    }
    else {
        _3350 = binary_op(EQUALS, _3350, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3350)) {
        if (_3350 != 0) {
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_3350)->dbl != 0.0) {
            goto L6;
        }
    }
    DeRef(_3345);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3345 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3345);
    _0 = _3345;
    _2 = (int)SEQ_PTR(_3345);
    _3345 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3345);
    DeRefDS(_0);
    _0 = _3345;
    if (IS_ATOM_INT(_3345)) {
        _3345 = (_3345 == 6);
    }
    else {
        _3345 = binary_op(EQUALS, _3345, 6);
    }
    DeRef(_0);
L7:
    if (_3345 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_3345) && DBL_PTR(_3345)->dbl == 0.0)
            goto L8;
    }
L6:

    // 	SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    DeRef(_3367);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3367 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3367);
    _0 = _3367;
    _2 = (int)SEQ_PTR(_3367);
    _3367 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3367);
    DeRefDS(_0);
    DeRef(_3369);
    _3369 = (_15left_sym % 29);
    _3369 = power(2, _3369);
    _0 = _3369;
    if (IS_ATOM_INT(_3367) && IS_ATOM_INT(_3369)) {
        _3369 = (_3367 | _3369);
    }
    else {
        _3369 = binary_op(OR_BITS, _3367, _3369);
    }
    DeRef(_0);
    Ref(_3369);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _3369;
    DeRef(_1);
L8:
L4:

    //     SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_WRITTEN)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_15left_sym + ((s1_ptr)_2)->base);
    DeRef(_3350);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3350 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3350);
    _0 = _3350;
    _2 = (int)SEQ_PTR(_3350);
    _3350 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_3350);
    DeRefDS(_0);
    _0 = _3350;
    if (IS_ATOM_INT(_3350)) {
        _3350 = (_3350 | 2);
    }
    else {
        _3350 = binary_op(OR_BITS, _3350, 2);
    }
    DeRef(_0);
    Ref(_3350);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _3350;
    DeRef(_1);

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     subs = 0
    _subs = 0;

    //     slice = FALSE
    _slice = 0;

    //     dangerous = FALSE
    _dangerous = 0;

    //     side_effect_calls = 0
    _15side_effect_calls = 0;

    //     emit_opnd(left_sym)
    _14emit_opnd(_15left_sym);

    //     current_sequence = append(current_sequence, left_sym)
    Append(&_14current_sequence, _14current_sequence, _15left_sym);

    //     while tok[T_ID] = LEFT_SQUARE do
L9:
    DeRef(_3350);
    _2 = (int)SEQ_PTR(_tok);
    _3350 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3350);
    if (binary_op_a(NOTEQ, _3350, -28))
        goto LA;

    // 	if lhs_ptr then
    if (_14lhs_ptr == 0)
        goto LB;

    // 	    current_sequence = current_sequence[1..$-1]
    DeRef(_3350);
    _3350 = SEQ_PTR(_14current_sequence)->length;
    _3350 = _3350 - 1;
    rhs_slice_target = (object_ptr)&_14current_sequence;
    RHS_Slice((s1_ptr)_14current_sequence, 1, _3350);

    // 	    if subs = 1 then
    if (_subs != 1)
        goto LC;

    // 		subs1_patch = length(Code)+1
    _3350 = SEQ_PTR(_4Code)->length;
    _subs1_patch = _3350 + 1;

    // 		emit_op(LHS_SUBS1) -- creates new current_sequence
    _14emit_op(163);
    goto LD;
LC:

    // 		emit_op(LHS_SUBS) -- adds to current_sequence
    _14emit_op(95);
LD:
LB:

    // 	subs += 1
    _subs = _subs + 1;

    // 	if subs = 1 then
    if (_subs != 1)
        goto LE;

    // 	    InitCheck(left_sym, TRUE) 
    _15InitCheck(_15left_sym, 1);
LE:

    // 	Expr() 
    _15Expr();

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	if tok[T_ID] = SLICE then
    DeRef(_3350);
    _2 = (int)SEQ_PTR(_tok);
    _3350 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3350);
    if (binary_op_a(NOTEQ, _3350, 516))
        goto LF;

    // 	    Expr()
    _15Expr();

    // 	    slice = TRUE
    _slice = 1;

    // 	    tok_match(RIGHT_SQUARE)
    _15tok_match(-29);

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 	    exit  -- no further subs or slices allowed 
    goto LA;
    goto L10;
LF:

    // 	    putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	    tok_match(RIGHT_SQUARE)
    _15tok_match(-29);
L10:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	lhs_ptr = TRUE
    _14lhs_ptr = 1;

    //     end while
    goto L9;
LA:

    //     lhs_ptr = FALSE
    _14lhs_ptr = 0;

    //     assign_op = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _assign_op = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_assign_op))
        _assign_op = (long)DBL_PTR(_assign_op)->dbl;

    //     if not find(assign_op, {EQUALS, PLUS_EQUALS, MINUS_EQUALS, MULTIPLY_EQUALS, 
    _0 = _3350;
    _1 = NewS1(6);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = 3;
    *((int *)(_2+8)) = 518;
    *((int *)(_2+12)) = 519;
    *((int *)(_2+16)) = 520;
    *((int *)(_2+20)) = 521;
    *((int *)(_2+24)) = 522;
    _3350 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3350;
    _3350 = find(_assign_op, _3350);
    DeRefDSi(_0);
    if (_3350 != 0)
        goto L11;

    // 	CompileErr("Syntax error - expected to see =, +=, -=, *=, /= or &=")
    RefDS(_3398);
    _6CompileErr(_3398);
L11:

    //     if subs = 0 then
    if (_subs != 0)
        goto L12;

    // 	if assign_op = EQUALS then
    if (_assign_op != 3)
        goto L13;

    // 	    Expr() -- RHS expression
    _15Expr();

    // 	    InitCheck(left_sym, FALSE)
    _15InitCheck(_15left_sym, 0);
    goto L14;
L13:

    // 	    InitCheck(left_sym, TRUE)
    _15InitCheck(_15left_sym, 1);

    // 	    SymTab[left_sym][S_USAGE] = or_bits(SymTab[left_sym][S_USAGE], U_READ)
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_15left_sym + ((s1_ptr)_2)->base);
    DeRef(_3369);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3369 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3369);
    _0 = _3369;
    _2 = (int)SEQ_PTR(_3369);
    _3369 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_3369);
    DeRefDS(_0);
    _0 = _3369;
    if (IS_ATOM_INT(_3369)) {
        _3369 = (_3369 | 1);
    }
    else {
        _3369 = binary_op(OR_BITS, _3369, 1);
    }
    DeRef(_0);
    Ref(_3369);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _3369;
    DeRef(_1);

    // 	    emit_opnd(left_sym)
    _14emit_opnd(_15left_sym);

    // 	    Expr() -- RHS expression
    _15Expr();

    // 	    emit_assign_op(assign_op)
    _14emit_assign_op(_assign_op);
L14:

    // 	emit_op(ASSIGN)
    _14emit_op(18);

    // 	TypeCheck(left_sym)
    _15TypeCheck(_15left_sym);
    goto L15;
L12:

    // 	factors = 0
    _15factors = 0;

    // 	lhs_subs_level = -1
    _15lhs_subs_level = -1;

    // 	Expr() -- RHS expression
    _15Expr();

    // 	if subs > 1 then
    if (_subs <= 1)
        goto L16;

    // 	    if SymTab[left_sym][S_SCOPE] != SC_PRIVATE and
    DeRef(_3369);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3369 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3369);
    _0 = _3369;
    _2 = (int)SEQ_PTR(_3369);
    _3369 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3369);
    DeRefDS(_0);
    _0 = _3369;
    if (IS_ATOM_INT(_3369)) {
        _3369 = (_3369 != 3);
    }
    else {
        _3369 = binary_op(NOTEQ, _3369, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3369)) {
        if (_3369 == 0) {
            goto L17;
        }
    }
    else {
        if (DBL_PTR(_3369)->dbl == 0.0) {
            goto L17;
        }
    }
    DeRef(_3367);
    _3367 = (_15left_sym % 29);
    _3367 = power(2, _3367);
    _0 = _3367;
    if (IS_ATOM_INT(_3367)) {
        _3367 = (_15side_effect_calls & _3367);
    }
    else {
        temp_d.dbl = (double)_15side_effect_calls;
        _3367 = Dand_bits(&temp_d, DBL_PTR(_3367));
    }
    DeRef(_0);
L18:
    if (_3367 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_3367) && DBL_PTR(_3367)->dbl == 0.0)
            goto L17;
    }

    // 		dangerous = TRUE
    _dangerous = 1;
L17:

    // 	    if factors = 1 and 
    DeRef(_3367);
    _3367 = (_15factors == 1);
    if (_3367 == 0) {
        _3367 = 0;
        goto L19;
    }
    DeRef(_3369);
    _3369 = (_15lhs_subs_level >= 0);
    _3367 = (_3369 != 0);
L19:
    if (_3367 == 0) {
        goto L1A;
    }
    DeRef(_3367);
    _3367 = _subs + _slice;
    if ((long)((unsigned long)_3367 + (unsigned long)HIGH_BITS) >= 0) 
        _3367 = NewDouble((double)_3367);
    _0 = _3367;
    if (IS_ATOM_INT(_3367)) {
        _3367 = (_15lhs_subs_level < _3367);
    }
    else {
        _3367 = ((double)_15lhs_subs_level < DBL_PTR(_3367)->dbl);
    }
    DeRef(_0);
L1B:
    if (_3367 == 0)
        goto L1A;

    // 		dangerous = TRUE  
    _dangerous = 1;
L1A:

    // 	    if dangerous then
    if (_dangerous == 0)
        goto L1C;

    // 		backpatch(subs1_patch, LHS_SUBS1_COPY)
    _14backpatch(_subs1_patch, 168);
L1C:
L16:

    // 	if slice then 
    if (_slice == 0)
        goto L1D;

    // 	    if assign_op != EQUALS then
    if (_assign_op == 3)
        goto L1E;

    // 		if subs = 1 then
    if (_subs != 1)
        goto L1F;

    // 		    emit_op(ASSIGN_OP_SLICE)
    _14emit_op(152);
    goto L20;
L1F:

    // 		    emit_op(PASSIGN_OP_SLICE)
    _14emit_op(167);
L20:

    // 		emit_assign_op(assign_op)
    _14emit_assign_op(_assign_op);
L1E:

    // 	    if subs = 1 then
    if (_subs != 1)
        goto L21;

    // 		emit_op(ASSIGN_SLICE)
    _14emit_op(45);
    goto L22;
L21:

    // 		emit_op(PASSIGN_SLICE)
    _14emit_op(165);
L23:
    goto L22;
L1D:

    // 	    if assign_op = EQUALS then
    if (_assign_op != 3)
        goto L24;

    // 		if subs = 1 then
    if (_subs != 1)
        goto L25;

    // 		    emit_op(ASSIGN_SUBS)
    _14emit_op(16);
    goto L26;
L25:

    // 		    emit_op(PASSIGN_SUBS)
    _14emit_op(164);
L27:
    goto L26;
L24:

    // 		if subs = 1 then
    if (_subs != 1)
        goto L28;

    // 		    emit_op(ASSIGN_OP_SUBS)
    _14emit_op(151);
    goto L29;
L28:

    // 		    emit_op(PASSIGN_OP_SUBS)
    _14emit_op(166);
L29:

    // 		emit_assign_op(assign_op)
    _14emit_assign_op(_assign_op);

    // 		if subs = 1 then
    if (_subs != 1)
        goto L2A;

    // 		    emit_op(ASSIGN_SUBS2)
    _14emit_op(150);
    goto L2B;
L2A:

    // 		    emit_op(PASSIGN_SUBS)
    _14emit_op(164);
L2B:
L26:
L22:

    // 	if subs > 1 then
    if (_subs <= 1)
        goto L2C;

    // 	    if dangerous then
    if (_dangerous == 0)
        goto L2D;

    // 		emit_opnd(left_sym)
    _14emit_opnd(_15left_sym);

    // 		emit_opnd(lhs_subs1_copy_temp) -- will be freed 
    _14emit_opnd(_14lhs_subs1_copy_temp);

    // 		emit_op(ASSIGN)
    _14emit_op(18);
    goto L2E;
L2D:

    // 		TempFree(lhs_subs1_copy_temp)
    _14TempFree(_14lhs_subs1_copy_temp);
L2E:
L2C:

    // 	if OpTypeCheck and SymTab[left_sym][S_VTYPE] != sequence_type then
    if (_4OpTypeCheck == 0) {
        goto L2F;
    }
    DeRef(_3369);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3369 = (int)*(((s1_ptr)_2)->base + _15left_sym);
    RefDS(_3369);
    _0 = _3369;
    _2 = (int)SEQ_PTR(_3369);
    _3369 = (int)*(((s1_ptr)_2)->base + 14);
    Ref(_3369);
    DeRefDS(_0);
    _0 = _3369;
    if (IS_ATOM_INT(_3369)) {
        _3369 = (_3369 != _10sequence_type);
    }
    else {
        _3369 = binary_op(NOTEQ, _3369, _10sequence_type);
    }
    DeRef(_0);
L30:
    if (_3369 == 0) {
        goto L2F;
    }
    else {
        if (!IS_ATOM_INT(_3369) && DBL_PTR(_3369)->dbl == 0.0)
            goto L2F;
    }

    // 	    TypeCheck(left_sym)
    _15TypeCheck(_15left_sym);
L2F:
L15:

    //     current_sequence = current_sequence[1..$-1]
    DeRef(_3369);
    _3369 = SEQ_PTR(_14current_sequence)->length;
    _3369 = _3369 - 1;
    rhs_slice_target = (object_ptr)&_14current_sequence;
    RHS_Slice((s1_ptr)_14current_sequence, 1, _3369);

    //     if not TRANSLATE then

    // 	if OpTrace then 
    if (_4OpTrace == 0)
        goto L31;

    // 	    emit_op(DISPLAY_VAR)
    _14emit_op(87);

    // 	    emit_addr(left_sym)
    _14emit_addr(_15left_sym);
L31:
L32:

    // end procedure
    DeRefDS(_left_var);
    DeRef(_tok);
    DeRef(_3369);
    DeRef(_3367);
    DeRef(_3350);
    DeRef(_3345);
    return 0;
    ;
}


int _15Return_statement()
{
    int _tok = 0;
    int _3436 = 0;
    int _0, _1, _2;
    

    //     if CurrentSub = TopLevelSub then
    if (_4CurrentSub != _4TopLevelSub)
        goto L1;

    // 	CompileErr("return must be inside a procedure or function")
    RefDS(_3437);
    _6CompileErr(_3437);
L1:

    //     if not TRANSLATE then    

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto L2;

    // 	    emit_op(ERASE_PRIVATE_NAMES)
    _14emit_op(88);

    // 	    emit_addr(CurrentSub)
    _14emit_addr(_4CurrentSub);
L2:
L3:

    //     if SymTab[CurrentSub][S_TOKEN] != PROC then
    DeRef(_3436);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3436 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3436);
    _0 = _3436;
    _2 = (int)SEQ_PTR(_3436);
    _3436 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_3436);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _3436, 27))
        goto L4;

    // 	Expr()
    _15Expr();

    // 	FuncReturn = TRUE
    _15FuncReturn = 1;

    // 	emit_op(RETURNF)
    _14emit_op(28);
    goto L5;
L4:

    // 	emit_op(RETURNP)
    _14emit_op(29);
L5:

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     NotReached(tok[T_ID], "return")
    DeRef(_3436);
    _2 = (int)SEQ_PTR(_tok);
    _3436 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3436);
    Ref(_3436);
    RefDS(_672);
    _15NotReached(_3436, _672);

    // end procedure
    DeRefDS(_tok);
    DeRef(_3436);
    return 0;
    ;
}


int _15Exit_statement()
{
    int _tok = 0;
    int _3444 = 0;
    int _0, _1, _2;
    

    //     if loop_nest = 0 then
    if (_15loop_nest != 0)
        goto L1;

    // 	CompileErr("exit statement must be inside a loop")
    RefDS(_3445);
    _6CompileErr(_3445);
L1:

    //     emit_op(EXIT)
    _14emit_op(61);

    //     AppendXList(length(Code)+1)
    DeRef(_3444);
    _3444 = SEQ_PTR(_4Code)->length;
    _3444 = _3444 + 1;
    _15AppendXList(_3444);

    //     emit_forward_addr()     -- to be back-patched 
    _15emit_forward_addr();

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     NotReached(tok[T_ID], "exit")
    _2 = (int)SEQ_PTR(_tok);
    _3444 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3444);
    Ref(_3444);
    RefDS(_690);
    _15NotReached(_3444, _690);

    // end procedure
    DeRefDS(_tok);
    DeRef(_3444);
    return 0;
    ;
}


int _15If_statement()
{
    int _tok = 0;
    int _prev_false;
    int _prev_false2;
    int _elist_base;
    int _3450 = 0;
    int _0, _1, _2;
    

    //     elist_base = length(elist)
    _elist_base = SEQ_PTR(_15elist)->length;

    //     short_circuit += 1
    _15short_circuit = _15short_circuit + 1;

    //     short_circuit_B = FALSE
    _15short_circuit_B = 0;

    //     SC1_type = 0
    _15SC1_type = 0;

    //     Expr()
    _15Expr();

    //     emit_op(IF)
    _14emit_op(20);

    //     prev_false = length(Code)+1
    _3450 = SEQ_PTR(_4Code)->length;
    _prev_false = _3450 + 1;

    //     prev_false2 = 0
    _prev_false2 = 0;

    //     emit_forward_addr() -- to be patched 
    _15emit_forward_addr();

    //     if SC1_type = OR then
    if (_15SC1_type != 9)
        goto L1;

    // 	backpatch(SC1_patch-3, SC1_OR_IF)
    _3450 = _15SC1_patch - 3;
    _14backpatch(_3450, 149);

    // 	if TRANSLATE then

    // 	backpatch(SC1_patch, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_15SC1_patch, _3450);
    goto L2;
L1:

    //     elsif SC1_type = AND then
    if (_15SC1_type != 8)
        goto L3;

    // 	backpatch(SC1_patch-3, SC1_AND_IF)
    DeRef(_3450);
    _3450 = _15SC1_patch - 3;
    _14backpatch(_3450, 148);

    // 	prev_false2 = SC1_patch
    _prev_false2 = _15SC1_patch;
L3:
L2:

    //     short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    //     tok_match(THEN)
    _15tok_match(409);

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_15forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     while tok[T_ID] = ELSIF do
L4:
    DeRef(_3450);
    _2 = (int)SEQ_PTR(_tok);
    _3450 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3450);
    if (binary_op_a(NOTEQ, _3450, 413))
        goto L5;

    // 	emit_op(ELSE)
    _14emit_op(23);

    // 	AppendEList(length(Code)+1)
    DeRef(_3450);
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _15AppendEList(_3450);

    // 	emit_forward_addr()  -- to be patched 
    _15emit_forward_addr();

    // 	if TRANSLATE then

    // 	backpatch(prev_false, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false, _3450);

    // 	if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto L6;

    // 	    backpatch(prev_false2, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false2, _3450);
L6:

    // 	StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	short_circuit += 1
    _15short_circuit = _15short_circuit + 1;

    // 	short_circuit_B = FALSE
    _15short_circuit_B = 0;

    // 	SC1_type = 0
    _15SC1_type = 0;

    // 	Expr()
    _15Expr();

    // 	emit_op(IF)
    _14emit_op(20);

    // 	prev_false = length(Code)+1
    DeRef(_3450);
    _3450 = SEQ_PTR(_4Code)->length;
    _prev_false = _3450 + 1;

    // 	prev_false2 = 0
    _prev_false2 = 0;

    // 	emit_forward_addr() -- to be patched 
    _15emit_forward_addr();

    // 	if SC1_type = OR then
    if (_15SC1_type != 9)
        goto L7;

    // 	    backpatch(SC1_patch-3, SC1_OR_IF)
    _3450 = _15SC1_patch - 3;
    _14backpatch(_3450, 149);

    // 	    if TRANSLATE then

    // 	    backpatch(SC1_patch, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_15SC1_patch, _3450);
    goto L8;
L7:

    // 	elsif SC1_type = AND then
    if (_15SC1_type != 8)
        goto L9;

    // 	    backpatch(SC1_patch-3, SC1_AND_IF)
    DeRef(_3450);
    _3450 = _15SC1_patch - 3;
    _14backpatch(_3450, 148);

    // 	    prev_false2 = SC1_patch
    _prev_false2 = _15SC1_patch;
L9:
L8:

    // 	short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    // 	tok_match(THEN)
    _15tok_match(409);

    // 	call_proc(forward_Statement_list, {})
    _0 = (int)_00[_15forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     end while
    goto L4;
L5:

    //     if tok[T_ID] = ELSE then 
    DeRef(_3450);
    _2 = (int)SEQ_PTR(_tok);
    _3450 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3450);
    if (binary_op_a(NOTEQ, _3450, 23))
        goto LA;

    // 	StartSourceLine(FALSE)
    _14StartSourceLine(0);

    // 	emit_op(ELSE)
    _14emit_op(23);

    // 	AppendEList(length(Code)+1)
    DeRef(_3450);
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _15AppendEList(_3450);

    // 	emit_forward_addr() -- to be patched 
    _15emit_forward_addr();

    // 	if TRANSLATE then

    // 	backpatch(prev_false, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false, _3450);

    // 	if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto LB;

    // 	    backpatch(prev_false2, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false2, _3450);
LB:

    // 	call_proc(forward_Statement_list, {})
    _0 = (int)_00[_15forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );
    goto LC;
LA:

    // 	putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	if TRANSLATE then

    // 	backpatch(prev_false, length(Code)+1)
    DeRef(_3450);
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false, _3450);

    // 	if prev_false2 != 0 then
    if (_prev_false2 == 0)
        goto LD;

    // 	    backpatch(prev_false2, length(Code)+1)
    _3450 = SEQ_PTR(_4Code)->length;
    _3450 = _3450 + 1;
    _14backpatch(_prev_false2, _3450);
LD:
LC:

    //     tok_match(END) 
    _15tok_match(402);

    //     tok_match(IF)
    _15tok_match(20);

    //     if TRANSLATE then

    //     PatchEList(elist_base)
    _15PatchEList(_elist_base);

    // end procedure
    DeRef(_tok);
    DeRef(_3450);
    return 0;
    ;
}


int _15While_statement()
{
    int _bp1;
    int _bp2;
    int _exit_base;
    int _3498;
    int _0, _1, _2;
    

    //     if TRANSLATE then

    //     bp1 = length(Code)+1
    _3498 = SEQ_PTR(_4Code)->length;
    _bp1 = _3498 + 1;

    //     short_circuit += 1
    _15short_circuit = _15short_circuit + 1;

    //     short_circuit_B = FALSE
    _15short_circuit_B = 0;

    //     SC1_type = 0
    _15SC1_type = 0;

    //     Expr()
    _15Expr();

    //     tok_match(DO)
    _15tok_match(410);

    //     optimized_while = FALSE
    _14optimized_while = 0;

    //     emit_op(WHILE)
    _14emit_op(47);

    //     short_circuit -= 1
    _15short_circuit = _15short_circuit - 1;

    //     if not optimized_while then
    if (_14optimized_while != 0)
        goto L1;

    // 	bp2 = length(Code)+1
    _3498 = SEQ_PTR(_4Code)->length;
    _bp2 = _3498 + 1;

    // 	emit_forward_addr() -- will be patched 
    _15emit_forward_addr();
    goto L2;
L1:

    // 	bp2 = 0
    _bp2 = 0;
L2:

    //     loop_nest += 1
    _15loop_nest = _15loop_nest + 1;

    //     exit_base = length(exit_list)
    _exit_base = SEQ_PTR(_15exit_list)->length;

    //     if SC1_type = OR then
    if (_15SC1_type != 9)
        goto L3;

    // 	backpatch(SC1_patch-3, SC1_OR_IF)
    _3498 = _15SC1_patch - 3;
    _14backpatch(_3498, 149);

    // 	if TRANSLATE then

    // 	backpatch(SC1_patch, length(Code)+1)
    _3498 = SEQ_PTR(_4Code)->length;
    _3498 = _3498 + 1;
    _14backpatch(_15SC1_patch, _3498);
    goto L4;
L3:

    //     elsif SC1_type = AND then
    if (_15SC1_type != 8)
        goto L5;

    // 	backpatch(SC1_patch-3, SC1_AND_IF)
    _3498 = _15SC1_patch - 3;
    _14backpatch(_3498, 148);

    // 	AppendXList(SC1_patch)
    _15AppendXList(_15SC1_patch);
L5:
L4:

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_15forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok_match(END)
    _15tok_match(402);

    //     tok_match(WHILE)
    _15tok_match(47);

    //     StartSourceLine(TRUE)
    _14StartSourceLine(1);

    //     emit_op(ENDWHILE)
    _14emit_op(22);

    //     loop_nest -= 1
    _15loop_nest = _15loop_nest - 1;

    //     emit_addr(bp1)
    _14emit_addr(_bp1);

    //     if TRANSLATE then

    //     if bp2 != 0 then
    if (_bp2 == 0)
        goto L6;

    // 	backpatch(bp2, length(Code)+1)
    _3498 = SEQ_PTR(_4Code)->length;
    _3498 = _3498 + 1;
    _14backpatch(_bp2, _3498);
L6:

    //     PatchXList(exit_base)
    _15PatchXList(_exit_base);

    // end procedure
    return 0;
    ;
}


int _15SetPrivateScope(int _s, int _type_sym, int _n)
{
    int _hashval;
    int _scope;
    int _t;
    int _3524 = 0;
    int _3517 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_s)) {
        _1 = (long)(DBL_PTR(_s)->dbl);
        DeRefDS(_s);
        _s = _1;
    }

    //     scope = SymTab[s][S_SCOPE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3517 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3517);
    _2 = (int)SEQ_PTR(_3517);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    //     if find(scope, {SC_PRIVATE, SC_LOOP_VAR}) then
    DeRefDS(_3517);
    _3517 = find(_scope, _3519);
    if (_3517 == 0)
        goto L1;

    // 	DefinedYet(s)
    _10DefinedYet(_s);

    // 	return s
    return _s;
    goto L2;
L1:

    //     elsif find(scope, {SC_UNDEFINED, SC_MULTIPLY_DEFINED}) then
    DeRef(_3517);
    _3517 = find(_scope, _3521);
    if (_3517 == 0)
        goto L3;

    // 	SymTab[s][S_SCOPE] = SC_PRIVATE
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
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 3;
    DeRef(_1);

    // 	SymTab[s][S_VARNUM] = n
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
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _n;
    DeRef(_1);

    // 	SymTab[s][S_VTYPE] = type_sym
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
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_sym;
    DeRef(_1);

    // 	return s
    DeRef(_3524);
    return _s;
    goto L2;
L3:

    //     elsif find(scope, {SC_LOCAL, SC_GLOBAL, SC_PREDEF}) then
    DeRef(_3524);
    _3524 = find(_scope, _3529);
    if (_3524 == 0)
        goto L4;

    // 	hashval = SymTab[s][S_HASHVAL]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3524 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3524);
    _2 = (int)SEQ_PTR(_3524);
    _hashval = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_hashval))
        _hashval = (long)DBL_PTR(_hashval)->dbl;

    // 	t = buckets[hashval]
    _2 = (int)SEQ_PTR(_10buckets);
    _t = (int)*(((s1_ptr)_2)->base + _hashval);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    // 	buckets[hashval] = NewEntry(SymTab[s][S_NAME], n, SC_PRIVATE, 
    DeRefDS(_3524);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3524 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3524);
    _0 = _3524;
    _2 = (int)SEQ_PTR(_3524);
    _3524 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3524);
    DeRefDS(_0);
    Ref(_3524);
    _0 = _3524;
    _3524 = _10NewEntry(_3524, _n, 3, -100, _hashval, _t, _type_sym);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_10buckets);
    _2 = (int)(((s1_ptr)_2)->base + _hashval);
    _1 = *(int *)_2;
    *(int *)_2 = _3524;
    DeRef(_1);

    // 	return buckets[hashval]
    _2 = (int)SEQ_PTR(_10buckets);
    _3524 = (int)*(((s1_ptr)_2)->base + _hashval);
    Ref(_3524);
    DeRef(_3517);
    return _3524;
    goto L2;
L4:

    // 	InternalErr("SetPS")
    RefDS(_3538);
    _6InternalErr(_3538);
L2:

    //     return 0
    DeRef(_3524);
    DeRef(_3517);
    return 0;
    ;
}


int _15For_statement()
{
    int _bp1;
    int _exit_base;
    int _tok = 0;
    int _loop_var = 0;
    int _loop_var_sym;
    int _def1;
    int _3565 = 0;
    int _3563 = 0;
    int _3541 = 0;
    int _3539 = 0;
    int _0, _1, _2, _3;
    

    //     loop_var = next_token()
    _loop_var = _15next_token();

    //     if not find(loop_var[T_ID], {VARIABLE, FUNC, TYPE, PROC}) then
    _2 = (int)SEQ_PTR(_loop_var);
    _3539 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3539);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _3541 = MAKE_SEQ(_1);
    _0 = _3541;
    _3541 = find(_3539, _3541);
    DeRefDSi(_0);
    if (_3541 != 0)
        goto L1;

    // 	CompileErr("a loop variable name is expected here")
    RefDS(_3544);
    _6CompileErr(_3544);
L1:

    //     if BIND then

    //     tok_match(EQUALS)
    _15tok_match(3);

    //     Expr()
    _15Expr();

    //     tok_match(TO)
    _15tok_match(403);

    //     loop_nest += 1
    _15loop_nest = _15loop_nest + 1;

    //     exit_base = length(exit_list)    
    _exit_base = SEQ_PTR(_15exit_list)->length;

    //     Expr()
    _15Expr();

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     if tok[T_ID] = BY then
    DeRef(_3541);
    _2 = (int)SEQ_PTR(_tok);
    _3541 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3541);
    if (binary_op_a(NOTEQ, _3541, 404))
        goto L2;

    // 	Expr()
    _15Expr();

    // 	def1 = FALSE
    _def1 = 0;
    goto L3;
L2:

    // 	emit_opnd(NewIntSym(1))
    _0 = _3541;
    _3541 = _10NewIntSym(1);
    DeRef(_0);
    _14emit_opnd(_3541);

    // 	putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	def1 = TRUE
    _def1 = 1;
L3:

    //     loop_var_sym = loop_var[T_SYM]
    _2 = (int)SEQ_PTR(_loop_var);
    _loop_var_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_loop_var_sym))
        _loop_var_sym = (long)DBL_PTR(_loop_var_sym)->dbl;

    //     if CurrentSub = TopLevelSub then
    if (_4CurrentSub != _4TopLevelSub)
        goto L4;

    // 	DefinedYet(loop_var_sym)
    _10DefinedYet(_loop_var_sym);

    // 	SymTab[loop_var_sym][S_SCOPE] = SC_GLOOP_VAR
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 4;
    DeRef(_1);

    // 	SymTab[loop_var_sym][S_VTYPE] = object_type
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _10object_type;
    DeRef(_1);
    goto L5;
L4:

    // 	loop_var_sym = SetPrivateScope(loop_var_sym, object_type, param_num)
    _loop_var_sym = _15SetPrivateScope(_loop_var_sym, _10object_type, _15param_num);
    if (!IS_ATOM_INT(_loop_var_sym)) {
        _1 = (long)(DBL_PTR(_loop_var_sym)->dbl);
        DeRefDS(_loop_var_sym);
        _loop_var_sym = _1;
    }

    // 	param_num += 1
    _15param_num = _15param_num + 1;

    // 	SymTab[loop_var_sym][S_SCOPE] = SC_LOOP_VAR
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);
L5:

    //     SymTab[loop_var_sym][S_USAGE] = or_bits(SymTab[loop_var_sym][S_USAGE], 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_loop_var_sym + ((s1_ptr)_2)->base);
    DeRef(_3563);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3563 = (int)*(((s1_ptr)_2)->base + _loop_var_sym);
    RefDS(_3563);
    _0 = _3563;
    _2 = (int)SEQ_PTR(_3563);
    _3563 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_3563);
    DeRefDS(_0);
    DeRef(_3565);
    _3565 = (1 | 2);
    if (IS_ATOM_INT(_3563)) {
        _3565 = (_3563 | _3565);
    }
    else {
        _3565 = binary_op(OR_BITS, _3563, _3565);
    }
    Ref(_3565);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = _3565;
    DeRef(_1);

    //     op_info1 = loop_var_sym
    _14op_info1 = _loop_var_sym;

    //     emit_op(FOR)
    _14emit_op(21);

    //     emit_addr(loop_var_sym)
    _14emit_addr(_loop_var_sym);

    //     tok_match(DO)
    _15tok_match(410);

    //     bp1 = length(Code)+1
    DeRef(_3565);
    _3565 = SEQ_PTR(_4Code)->length;
    _bp1 = _3565 + 1;

    //     emit_addr(0) -- will be patched - don't straighten 
    _14emit_addr(0);

    //     if not TRANSLATE then

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto L6;

    // 	    emit_op(DISPLAY_VAR)
    _14emit_op(87);

    // 	    emit_addr(loop_var_sym)
    _14emit_addr(_loop_var_sym);
L6:
L7:

    //     call_proc(forward_Statement_list, {})
    _0 = (int)_00[_15forward_Statement_list].addr;
    (*(int (*)())_0)(
                         );

    //     tok_match(END)
    _15tok_match(402);

    //     tok_match(FOR)
    _15tok_match(21);

    //     StartSourceLine(TRUE)
    _14StartSourceLine(1);

    //     op_info1 = loop_var_sym
    _14op_info1 = _loop_var_sym;

    //     op_info2 = bp1 + 1
    _14op_info2 = _bp1 + 1;

    //     if def1 then
    if (_def1 == 0)
        goto L8;

    // 	emit_op(ENDFOR_INT_UP1) -- (loop var might not be integer)
    _14emit_op(54);
    goto L9;
L8:

    // 	emit_op(ENDFOR_GENERAL) -- will be set at runtime by FOR op 
    _14emit_op(39);
L9:

    //     backpatch(bp1, length(Code)+1)
    DeRef(_3565);
    _3565 = SEQ_PTR(_4Code)->length;
    _3565 = _3565 + 1;
    _14backpatch(_bp1, _3565);

    //     PatchXList(exit_base)
    _15PatchXList(_exit_base);

    //     loop_nest -= 1
    _15loop_nest = _15loop_nest - 1;

    //     if not TRANSLATE then

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto LA;

    // 	    emit_op(ERASE_SYMBOL)
    _14emit_op(90);

    // 	    emit_addr(loop_var_sym)
    _14emit_addr(_loop_var_sym);
LA:
LB:

    //     Hide(loop_var_sym)
    _10Hide(_loop_var_sym);

    // end procedure
    DeRef(_tok);
    DeRef(_loop_var);
    DeRef(_3565);
    DeRef(_3563);
    DeRef(_3541);
    DeRef(_3539);
    return 0;
    ;
}


int _15Global_declaration(int _type_ptr, int _is_global)
{
    int _tok = 0;
    int _sym;
    int _h;
    int _3635 = 0;
    int _3591 = 0;
    int _3589 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_type_ptr)) {
        _1 = (long)(DBL_PTR(_type_ptr)->dbl);
        DeRefDS(_type_ptr);
        _type_ptr = _1;
    }

    //     while TRUE do 
L1:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	if not find(tok[T_ID], {VARIABLE, FUNC, TYPE, PROC}) then
    DeRef(_3589);
    _2 = (int)SEQ_PTR(_tok);
    _3589 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3589);
    _0 = _3591;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _3591 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3591;
    _3591 = find(_3589, _3591);
    DeRefDSi(_0);
    if (_3591 != 0)
        goto L2;

    // 	    CompileErr("a name is expected here")
    RefDS(_3594);
    _6CompileErr(_3594);
L2:

    // 	sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	DefinedYet(sym)
    _10DefinedYet(_sym);

    // 	if find(SymTab[sym][S_SCOPE], {SC_GLOBAL, SC_PREDEF}) then
    DeRef(_3591);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3591 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3591);
    _0 = _3591;
    _2 = (int)SEQ_PTR(_3591);
    _3591 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3591);
    DeRefDS(_0);
    _0 = _3591;
    _3591 = find(_3591, _2133);
    DeRef(_0);
    if (_3591 == 0)
        goto L3;

    // 	    h = SymTab[sym][S_HASHVAL]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3591 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3591);
    _2 = (int)SEQ_PTR(_3591);
    _h = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	    sym = NewEntry(SymTab[sym][S_NAME], 0, 0, VARIABLE, h, buckets[h], 0) 
    DeRefDS(_3591);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3591 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3591);
    _0 = _3591;
    _2 = (int)SEQ_PTR(_3591);
    _3591 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3591);
    DeRefDS(_0);
    DeRef(_3589);
    _2 = (int)SEQ_PTR(_10buckets);
    _3589 = (int)*(((s1_ptr)_2)->base + _h);
    Ref(_3589);
    Ref(_3591);
    Ref(_3589);
    _sym = _10NewEntry(_3591, 0, 0, -100, _h, _3589, 0);

    // 	    buckets[h] = sym
    _2 = (int)SEQ_PTR(_10buckets);
    _2 = (int)(((s1_ptr)_2)->base + _h);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);
L3:

    // 	if is_global then
    if (_is_global == 0)
        goto L4;

    // 	    SymTab[sym][S_SCOPE] = SC_GLOBAL 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 6;
    DeRef(_1);
    goto L5;
L4:

    // 	    SymTab[sym][S_SCOPE] = SC_LOCAL
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);
L5:

    // 	if type_ptr = 0 then
    if (_type_ptr != 0)
        goto L6;

    // 	    SymTab[sym][S_MODE] = M_CONSTANT 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	    buckets[SymTab[sym][S_HASHVAL]] = SymTab[sym][S_SAMEHASH]
    DeRef(_3591);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3591 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3591);
    _0 = _3591;
    _2 = (int)SEQ_PTR(_3591);
    _3591 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_3591);
    DeRefDS(_0);
    DeRef(_3589);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3589 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3589);
    _0 = _3589;
    _2 = (int)SEQ_PTR(_3589);
    _3589 = (int)*(((s1_ptr)_2)->base + 8);
    Ref(_3589);
    DeRefDS(_0);
    Ref(_3589);
    _2 = (int)SEQ_PTR(_10buckets);
    if (!IS_ATOM_INT(_3591))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_3591)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _3591);
    _1 = *(int *)_2;
    *(int *)_2 = _3589;
    DeRef(_1);

    // 	    tok_match(EQUALS)
    _15tok_match(3);

    // 	    StartSourceLine(FALSE)
    _14StartSourceLine(0);

    // 	    emit_opnd(sym)
    _14emit_opnd(_sym);

    // 	    Expr()  -- no new symbols can be defined in here 
    _15Expr();

    // 	    buckets[SymTab[sym][S_HASHVAL]] = sym
    DeRef(_3589);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3589 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_3589);
    _0 = _3589;
    _2 = (int)SEQ_PTR(_3589);
    _3589 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_3589);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_10buckets);
    if (!IS_ATOM_INT(_3589))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_3589)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _3589);
    _1 = *(int *)_2;
    *(int *)_2 = _sym;
    DeRef(_1);

    // 	    SymTab[sym][S_USAGE] = U_WRITTEN     
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	    if TRANSLATE then

    // 	    emit_op(ASSIGN)
    _14emit_op(18);
    goto L7;
L6:

    // 	    SymTab[sym][S_MODE] = M_NORMAL
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	    if SymTab[type_ptr][S_TOKEN] = OBJECT then
    DeRef(_3589);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3589 = (int)*(((s1_ptr)_2)->base + _type_ptr);
    RefDS(_3589);
    _0 = _3589;
    _2 = (int)SEQ_PTR(_3589);
    _3589 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_3589);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3589, 414))
        goto L8;

    // 		SymTab[sym][S_VTYPE] = object_type
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _10object_type;
    DeRef(_1);
    goto L9;
L8:

    // 		SymTab[sym][S_VTYPE] = type_ptr
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 14);
    _1 = *(int *)_2;
    *(int *)_2 = _type_ptr;
    DeRef(_1);
L9:

    // 	    if TRANSLATE then
L7:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	if tok[T_ID] != COMMA then
    DeRef(_3635);
    _2 = (int)SEQ_PTR(_tok);
    _3635 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3635);
    if (binary_op_a(EQUALS, _3635, -30))
        goto L1;

    // 	    exit
    goto LA;
LB:

    //     end while 
    goto L1;
LA:

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // end procedure
    DeRefDS(_tok);
    DeRef(_3635);
    DeRef(_3591);
    DeRef(_3589);
    return 0;
    ;
}


int _15Private_declaration(int _type_sym)
{
    int _tok = 0;
    int _sym;
    int _3650 = 0;
    int _3639 = 0;
    int _3641 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_type_sym)) {
        _1 = (long)(DBL_PTR(_type_sym)->dbl);
        DeRefDS(_type_sym);
        _type_sym = _1;
    }

    //     while TRUE do 
L1:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	if not find(tok[T_ID], {VARIABLE, FUNC, TYPE, PROC, NAMESPACE}) then
    DeRef(_3639);
    _2 = (int)SEQ_PTR(_tok);
    _3639 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3639);
    _0 = _3641;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 523;
    _3641 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3641;
    _3641 = find(_3639, _3641);
    DeRefDSi(_0);
    if (_3641 != 0)
        goto L2;

    // 	    CompileErr("a variable name is expected here")
    RefDS(_3644);
    _6CompileErr(_3644);
L2:

    // 	sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
    DeRef(_3641);
    _2 = (int)SEQ_PTR(_tok);
    _3641 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3641);
    Ref(_3641);
    _sym = _15SetPrivateScope(_3641, _type_sym, _15param_num);
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	param_num += 1
    _15param_num = _15param_num + 1;

    // 	if TRANSLATE then

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 	if tok[T_ID] != COMMA then
    DeRef(_3650);
    _2 = (int)SEQ_PTR(_tok);
    _3650 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3650);
    if (binary_op_a(EQUALS, _3650, -30))
        goto L1;

    // 	    exit
    goto L3;
L4:

    //     end while 
    goto L1;
L3:

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // end procedure
    DeRefDS(_tok);
    DeRef(_3650);
    DeRef(_3639);
    DeRef(_3641);
    return 0;
    ;
}


int _15Procedure_call(int _tok)
{
    int _n;
    int _scope;
    int _opcode;
    int _temp_tok = 0;
    int _s;
    int _3667 = 0;
    int _3665 = 0;
    int _3654 = 0;
    int _0, _1, _2, _3;
    

    //     tok_match(LEFT_ROUND)
    _15tok_match(-26);

    //     s = tok[T_SYM] 
    _2 = (int)SEQ_PTR(_tok);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    //     n = SymTab[s][S_NUM_ARGS]
    _2 = (int)SEQ_PTR(_4SymTab);
    _3654 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3654);
    _2 = (int)SEQ_PTR(_3654);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     scope = SymTab[s][S_SCOPE]
    DeRefDS(_3654);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3654 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3654);
    _2 = (int)SEQ_PTR(_3654);
    _scope = (int)*(((s1_ptr)_2)->base + 4);
    if (!IS_ATOM_INT(_scope))
        _scope = (long)DBL_PTR(_scope)->dbl;

    //     opcode = SymTab[s][S_OPCODE]
    DeRefDS(_3654);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3654 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3654);
    _2 = (int)SEQ_PTR(_3654);
    _opcode = (int)*(((s1_ptr)_2)->base + 19);
    if (!IS_ATOM_INT(_opcode))
        _opcode = (long)DBL_PTR(_opcode)->dbl;

    //     if SymTab[s][S_EFFECT] then
    DeRefDS(_3654);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3654 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3654);
    _0 = _3654;
    _2 = (int)SEQ_PTR(_3654);
    _3654 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3654);
    DeRefDS(_0);
    if (_3654 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_3654) && DBL_PTR(_3654)->dbl == 0.0)
            goto L1;
    }

    // 	SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3665 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3665);
    _0 = _3665;
    _2 = (int)SEQ_PTR(_3665);
    _3665 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3665);
    DeRefDS(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3667 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_3667);
    _0 = _3667;
    _2 = (int)SEQ_PTR(_3667);
    _3667 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3667);
    DeRefDS(_0);
    _0 = _3667;
    if (IS_ATOM_INT(_3665) && IS_ATOM_INT(_3667)) {
        _3667 = (_3665 | _3667);
    }
    else {
        _3667 = binary_op(OR_BITS, _3665, _3667);
    }
    DeRef(_0);
    Ref(_3667);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _3667;
    DeRef(_1);
L1:

    //     ParseArgs(s)
    _15ParseArgs(_s);

    //     if scope = SC_PREDEF then
    if (_scope != 7)
        goto L2;

    // 	emit_op(opcode)
    _14emit_op(_opcode);

    // 	if opcode = ABORT then
    if (_opcode != 126)
        goto L3;

    // 	    temp_tok = next_token()
    _0 = _temp_tok;
    _temp_tok = _15next_token();
    DeRef(_0);

    // 	    putback(temp_tok)
    RefDS(_temp_tok);
    _15putback(_temp_tok);

    // 	    NotReached(temp_tok[T_ID], "abort()")
    DeRef(_3667);
    _2 = (int)SEQ_PTR(_temp_tok);
    _3667 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3667);
    Ref(_3667);
    RefDS(_3674);
    _15NotReached(_3667, _3674);
L4:
    goto L3;
L2:

    // 	op_info1 = s
    _14op_info1 = _s;

    // 	emit_op(PROC)
    _14emit_op(27);

    // 	if not TRANSLATE then

    // 	    if OpTrace then
    if (_4OpTrace == 0)
        goto L5;

    // 		emit_op(UPDATE_GLOBALS)
    _14emit_op(89);
L5:
L6:
L3:

    // end procedure
    DeRefDS(_tok);
    DeRef(_temp_tok);
    DeRef(_3667);
    DeRef(_3665);
    DeRef(_3654);
    return 0;
    ;
}


int _15Print_statement()
{
    int _3679 = 0;
    int _3676;
    int _0, _1, _2, _3;
    

    //     emit_opnd(NewIntSym(1)) -- stdout 
    _3676 = _10NewIntSym(1);
    _14emit_opnd(_3676);

    //     Expr()
    _15Expr();

    //     emit_op(QPRINT)
    _14emit_op(36);

    //     SymTab[CurrentSub][S_EFFECT] = or_bits(SymTab[CurrentSub][S_EFFECT],
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3679 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_3679);
    _0 = _3679;
    _2 = (int)SEQ_PTR(_3679);
    _3679 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_3679);
    DeRefDS(_0);
    _0 = _3679;
    if (IS_ATOM_INT(_3679)) {
        _3679 = (_3679 | 536870912);
    }
    else {
        _3679 = binary_op(OR_BITS, _3679, 536870912);
    }
    DeRef(_0);
    Ref(_3679);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = _3679;
    DeRef(_1);

    // end procedure
    DeRef(_3679);
    return 0;
    ;
}


int _15Statement_list()
{
    int _tok = 0;
    int _id;
    int _3682;
    int _3687;
    int _0, _1, _2;
    

    //     stmt_nest += 1
    _15stmt_nest = _15stmt_nest + 1;

    //     while TRUE do 
L1:

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    // 	id = tok[T_ID]
    _2 = (int)SEQ_PTR(_tok);
    _id = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	if id = VARIABLE or id = QUALIFIED_VARIABLE then
    _3682 = (_id == -100);
    if (_3682 != 0) {
        goto L2;
    }
    _3687 = (_id == 515);
L3:
    if (_3687 == 0)
        goto L4;
L2:

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Assignment(tok)
    RefDS(_tok);
    _15Assignment(_tok);
    goto L1;
L4:

    // 	elsif id = PROC or id = QUALIFIED_PROC then
    _3687 = (_id == 27);
    if (_3687 != 0) {
        goto L5;
    }
    _3682 = (_id == 525);
L6:
    if (_3682 == 0)
        goto L7;
L5:

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Procedure_call(tok)
    RefDS(_tok);
    _15Procedure_call(_tok);
    goto L1;
L7:

    // 	elsif id = IF then
    if (_id != 20)
        goto L8;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    If_statement()
    _15If_statement();
    goto L1;
L8:

    // 	elsif id = FOR then
    if (_id != 21)
        goto L9;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    For_statement()
    _15For_statement();
    goto L1;
L9:

    // 	elsif id = RETURN then
    if (_id != 412)
        goto LA;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Return_statement()
    _15Return_statement();
    goto L1;
LA:

    // 	elsif id = EXIT then
    if (_id != 61)
        goto LB;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Exit_statement()
    _15Exit_statement();
    goto L1;
LB:

    // 	elsif id = WHILE then
    if (_id != 47)
        goto LC;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    While_statement()
    _15While_statement();
    goto L1;
LC:

    // 	elsif id = QUESTION_MARK then
    if (_id != -31)
        goto LD;

    // 	    StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	    Print_statement()
    _15Print_statement();
    goto L1;
LD:

    // 	    putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    // 	    stmt_nest -= 1
    _15stmt_nest = _15stmt_nest - 1;

    // 	    InitDelete()
    _15InitDelete();

    // 	    return
    DeRefDS(_tok);
    return 0;
LE:

    //     end while
    goto L1;
LF:

    // end procedure
    DeRef(_tok);
    return 0;
    ;
}


int _15SubProg(int _prog_type, int _is_global)
{
    int _h;
    int _pt;
    int _p;
    int _type_sym;
    int _sym;
    int _tok = 0;
    int _prog_name = 0;
    int _3700 = 0;
    int _3702 = 0;
    int _3784 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_prog_type)) {
        _1 = (long)(DBL_PTR(_prog_type)->dbl);
        DeRefDS(_prog_type);
        _prog_type = _1;
    }

    //     LeaveTopLevel()
    _15LeaveTopLevel();

    //     prog_name = next_token()
    _prog_name = _15next_token();

    //     if not find(prog_name[T_ID], {VARIABLE, FUNC, TYPE, PROC}) then
    _2 = (int)SEQ_PTR(_prog_name);
    _3700 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3700);
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    _3702 = MAKE_SEQ(_1);
    _0 = _3702;
    _3702 = find(_3700, _3702);
    DeRefDSi(_0);
    if (_3702 != 0)
        goto L1;

    // 	CompileErr("a name is expected here")
    RefDS(_3594);
    _6CompileErr(_3594);
L1:

    //     p = prog_name[T_SYM] 
    _2 = (int)SEQ_PTR(_prog_name);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     DefinedYet(p)
    _10DefinedYet(_p);

    //     if prog_type = PROCEDURE then
    if (_prog_type != 405)
        goto L2;

    // 	pt = PROC
    _pt = 27;
    goto L3;
L2:

    //     elsif prog_type = FUNCTION then
    if (_prog_type != 406)
        goto L4;

    // 	pt = FUNC
    _pt = 501;
    goto L3;
L4:

    // 	pt = TYPE
    _pt = 504;
L3:

    //     if find(SymTab[p][S_SCOPE], {SC_PREDEF, SC_GLOBAL}) then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _2 = (int)SEQ_PTR(_3702);
    _3702 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3702);
    DeRefDS(_0);
    _0 = _3702;
    _3702 = find(_3702, _3710);
    DeRef(_0);
    if (_3702 == 0)
        goto L5;

    // 	if SymTab[p][S_SCOPE] = SC_PREDEF then  -- only warn about overriding predefined
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _2 = (int)SEQ_PTR(_3702);
    _3702 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_3702);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _3702, 7))
        goto L6;

    // 	    Warning(sprintf("built-in routine %s() redefined", 
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _2 = (int)SEQ_PTR(_3702);
    _3702 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3702);
    DeRefDS(_0);
    _0 = _3702;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_3702);
    *((int *)(_2+4)) = _3702;
    _3702 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3702;
    _3702 = EPrintf(-9999999, _3715, _3702);
    DeRefDS(_0);
    RefDS(_3702);
    _6Warning(_3702);
L6:

    // 	h = SymTab[p][S_HASHVAL]
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _2 = (int)SEQ_PTR(_3702);
    _h = (int)*(((s1_ptr)_2)->base + 10);
    if (!IS_ATOM_INT(_h))
        _h = (long)DBL_PTR(_h)->dbl;

    // 	sym = buckets[h]
    _2 = (int)SEQ_PTR(_10buckets);
    _sym = (int)*(((s1_ptr)_2)->base + _h);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	p = NewEntry(SymTab[p][S_NAME], 0, 0, pt, h, sym, 0) 
    DeRefDS(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _2 = (int)SEQ_PTR(_3702);
    _3702 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_3702);
    DeRefDS(_0);
    Ref(_3702);
    _p = _10NewEntry(_3702, 0, 0, _pt, _h, _sym, 0);

    // 	buckets[h] = p
    _2 = (int)SEQ_PTR(_10buckets);
    _2 = (int)(((s1_ptr)_2)->base + _h);
    _1 = *(int *)_2;
    *(int *)_2 = _p;
    DeRef(_1);
L5:

    //     CurrentSub = p
    _4CurrentSub = _p;

    //     temps_allocated = 0
    _10temps_allocated = 0;

    //     if is_global then
    if (_is_global == 0)
        goto L7;

    // 	SymTab[p][S_SCOPE] = SC_GLOBAL
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 6;
    DeRef(_1);
    goto L8;
L7:

    // 	SymTab[p][S_SCOPE] = SC_LOCAL
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 5;
    DeRef(_1);
L8:

    //     SymTab[p][S_TOKEN] = pt
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _pt;
    DeRef(_1);

    //     if length(SymTab[p]) < SIZEOF_ROUTINE_ENTRY then
    DeRef(_3700);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3700 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3700);
    _0 = _3700;
    _3700 = SEQ_PTR(_3700)->length;
    DeRefDS(_0);
    if (_3700 >= 25)
        goto L9;

    // 	SymTab[p] = SymTab[p] & repeat(0, SIZEOF_ROUTINE_ENTRY - 
    _2 = (int)SEQ_PTR(_4SymTab);
    _3700 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3700);
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _3702 = SEQ_PTR(_3702)->length;
    DeRefDS(_0);
    _3702 = 25 - _3702;
    _3702 = Repeat(0, _3702);
    Concat((object_ptr)&_3702, _3700, (s1_ptr)_3702);
    RefDS(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _3702;
    DeRefDS(_1);
L9:

    //     SymTab[p][S_CODE] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 15);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_LINETAB] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 16);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_EFFECT] = E_PURE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 21);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_REFLIST] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 22);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     SymTab[p][S_FIRSTLINE] = gline_number
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 17);
    _1 = *(int *)_2;
    *(int *)_2 = _4gline_number;
    DeRef(_1);

    //     SymTab[p][S_TEMPS] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 18);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_RESIDENT_TASK] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[p][S_SAVED_PRIVATES] = {}
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    RefDS(_39);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 24);
    _1 = *(int *)_2;
    *(int *)_2 = _39;
    DeRef(_1);

    //     StartSourceLine(FALSE)  
    _14StartSourceLine(0);

    //     tok_match(LEFT_ROUND)
    _15tok_match(-26);

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     param_num = 0
    _15param_num = 0;

    //     while tok[T_ID] != RIGHT_ROUND do
LA:
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    if (binary_op_a(EQUALS, _3702, -27))
        goto LB;

    // 	if tok[T_ID] != TYPE and tok[T_ID] != QUALIFIED_TYPE then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    _0 = _3702;
    if (IS_ATOM_INT(_3702)) {
        _3702 = (_3702 != 504);
    }
    else {
        _3702 = binary_op(NOTEQ, _3702, 504);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3702)) {
        if (_3702 == 0) {
            goto LC;
        }
    }
    else {
        if (DBL_PTR(_3702)->dbl == 0.0) {
            goto LC;
        }
    }
    DeRef(_3700);
    _2 = (int)SEQ_PTR(_tok);
    _3700 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3700);
    _0 = _3700;
    if (IS_ATOM_INT(_3700)) {
        _3700 = (_3700 != 526);
    }
    else {
        _3700 = binary_op(NOTEQ, _3700, 526);
    }
    DeRef(_0);
LD:
    if (_3700 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_3700) && DBL_PTR(_3700)->dbl == 0.0)
            goto LC;
    }

    // 	    if tok[T_ID] = VARIABLE or tok[T_ID] = QUALIFIED_VARIABLE then
    DeRef(_3700);
    _2 = (int)SEQ_PTR(_tok);
    _3700 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3700);
    _0 = _3700;
    if (IS_ATOM_INT(_3700)) {
        _3700 = (_3700 == -100);
    }
    else {
        _3700 = binary_op(EQUALS, _3700, -100);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3700)) {
        if (_3700 != 0) {
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_3700)->dbl != 0.0) {
            goto LE;
        }
    }
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    _0 = _3702;
    if (IS_ATOM_INT(_3702)) {
        _3702 = (_3702 == 515);
    }
    else {
        _3702 = binary_op(EQUALS, _3702, 515);
    }
    DeRef(_0);
LF:
    if (_3702 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_3702) && DBL_PTR(_3702)->dbl == 0.0)
            goto L10;
    }
LE:

    // 		UndefinedVar(tok[T_SYM])
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3702);
    Ref(_3702);
    _15UndefinedVar(_3702);
L10:

    // 	    CompileErr("a type is expected here")            
    RefDS(_3771);
    _6CompileErr(_3771);
LC:

    // 	type_sym = tok[T_SYM]
    _2 = (int)SEQ_PTR(_tok);
    _type_sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_type_sym))
        _type_sym = (long)DBL_PTR(_type_sym)->dbl;

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 	if not find(tok[T_ID], {VARIABLE, FUNC, TYPE, PROC, NAMESPACE}) then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    _0 = _3700;
    _1 = NewS1(5);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = -100;
    *((int *)(_2+8)) = 501;
    *((int *)(_2+12)) = 504;
    *((int *)(_2+16)) = 27;
    *((int *)(_2+20)) = 523;
    _3700 = MAKE_SEQ(_1);
    DeRef(_0);
    _0 = _3700;
    _3700 = find(_3702, _3700);
    DeRefDSi(_0);
    if (_3700 != 0)
        goto L11;

    // 	    CompileErr("a parameter name is expected here")
    RefDS(_3778);
    _6CompileErr(_3778);
L11:

    // 	sym = SetPrivateScope(tok[T_SYM], type_sym, param_num)
    DeRef(_3700);
    _2 = (int)SEQ_PTR(_tok);
    _3700 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3700);
    Ref(_3700);
    _sym = _15SetPrivateScope(_3700, _type_sym, _15param_num);
    if (!IS_ATOM_INT(_sym)) {
        _1 = (long)(DBL_PTR(_sym)->dbl);
        DeRefDS(_sym);
        _sym = _1;
    }

    // 	param_num += 1
    _15param_num = _15param_num + 1;

    // 	if TRANSLATE then

    // 	SymTab[sym][S_USAGE] = U_WRITTEN     
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sym + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 	if tok[T_ID] = COMMA then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    if (binary_op_a(NOTEQ, _3702, -30))
        goto L12;

    // 	    tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    // 	    if tok[T_ID] = RIGHT_ROUND then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    if (binary_op_a(NOTEQ, _3702, -27))
        goto LA;

    // 		CompileErr("expected to see a parameter declaration, not ')'")
    RefDS(_3793);
    _6CompileErr(_3793);
L13:
    goto LA;
L12:

    // 	elsif tok[T_ID] != RIGHT_ROUND then
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    if (binary_op_a(EQUALS, _3702, -27))
        goto LA;

    // 	    CompileErr("badly-formed list of parameters - expected ',' or ')'")
    RefDS(_3796);
    _6CompileErr(_3796);
L14:
L15:

    //     end while
    goto LA;
LB:

    //     SymTab[p][S_NUM_ARGS] = param_num
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 20);
    _1 = *(int *)_2;
    *(int *)_2 = _15param_num;
    DeRef(_1);

    //     if TRANSLATE then

    //     if SymTab[p][S_TOKEN] = TYPE and param_num != 1 then
    DeRef(_3784);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3784 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3784);
    _0 = _3784;
    _2 = (int)SEQ_PTR(_3784);
    _3784 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_3784);
    DeRefDS(_0);
    _0 = _3784;
    if (IS_ATOM_INT(_3784)) {
        _3784 = (_3784 == 504);
    }
    else {
        _3784 = binary_op(EQUALS, _3784, 504);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3784)) {
        if (_3784 == 0) {
            goto L16;
        }
    }
    else {
        if (DBL_PTR(_3784)->dbl == 0.0) {
            goto L16;
        }
    }
    DeRef(_3702);
    _3702 = (_15param_num != 1);
L17:
    if (_3702 == 0)
        goto L16;

    // 	CompileErr("types must have exactly one parameter")
    RefDS(_3806);
    _6CompileErr(_3806);
L16:

    //     tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRef(_0);

    //     while tok[T_ID] = TYPE or tok[T_ID] = QUALIFIED_TYPE do
L18:
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_tok);
    _3702 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3702);
    _0 = _3702;
    if (IS_ATOM_INT(_3702)) {
        _3702 = (_3702 == 504);
    }
    else {
        _3702 = binary_op(EQUALS, _3702, 504);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_3702)) {
        if (_3702 != 0) {
            goto L19;
        }
    }
    else {
        if (DBL_PTR(_3702)->dbl != 0.0) {
            goto L19;
        }
    }
    DeRef(_3784);
    _2 = (int)SEQ_PTR(_tok);
    _3784 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_3784);
    _0 = _3784;
    if (IS_ATOM_INT(_3784)) {
        _3784 = (_3784 == 526);
    }
    else {
        _3784 = binary_op(EQUALS, _3784, 526);
    }
    DeRef(_0);
L1A:
    if (_3784 <= 0) {
        if (_3784 == 0) {
            goto L1B;
        }
        else {
            if (!IS_ATOM_INT(_3784) && DBL_PTR(_3784)->dbl == 0.0)
                goto L1B;
        }
    }
L19:

    // 	Private_declaration(tok[T_SYM])
    DeRef(_3784);
    _2 = (int)SEQ_PTR(_tok);
    _3784 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_3784);
    Ref(_3784);
    _15Private_declaration(_3784);

    // 	tok = next_token()
    _0 = _tok;
    _tok = _15next_token();
    DeRefDS(_0);

    //     end while
    goto L18;
L1B:

    //     sym = SymTab[p][S_NEXT]
    DeRef(_3784);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3784 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3784);
    _2 = (int)SEQ_PTR(_3784);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     for i = 1 to SymTab[p][S_NUM_ARGS] do
    DeRefDS(_3784);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3784 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3784);
    _0 = _3784;
    _2 = (int)SEQ_PTR(_3784);
    _3784 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3784);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L1C:
        if (binary_op_a(GREATER, _i, _3784))
            goto L1D;

        // 	TypeCheck(sym)
        _15TypeCheck(_sym);

        // 	sym = SymTab[sym][S_NEXT]
        DeRef(_3702);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3702 = (int)*(((s1_ptr)_2)->base + _sym);
        RefDS(_3702);
        _2 = (int)SEQ_PTR(_3702);
        _sym = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sym))
            _sym = (long)DBL_PTR(_sym)->dbl;

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
        goto L1C;
L1D:
        ;
        DeRef(_i);
    }

    //     if not TRANSLATE then

    // 	if OpTrace then
    if (_4OpTrace == 0)
        goto L1E;

    // 	    emit_op(ERASE_PRIVATE_NAMES)
    _14emit_op(88);

    // 	    emit_addr(p)
    _14emit_addr(_p);

    // 	    sym = SymTab[p][S_NEXT]
    DeRef(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _2 = (int)SEQ_PTR(_3702);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	    for i = 1 to SymTab[p][S_NUM_ARGS] do
    DeRefDS(_3702);
    _2 = (int)SEQ_PTR(_4SymTab);
    _3702 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_3702);
    _0 = _3702;
    _2 = (int)SEQ_PTR(_3702);
    _3702 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_3702);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L1F:
        if (binary_op_a(GREATER, _i, _3702))
            goto L20;

        // 		emit_op(DISPLAY_VAR)
        _14emit_op(87);

        // 		emit_addr(sym)
        _14emit_addr(_sym);

        // 		sym = SymTab[sym][S_NEXT]
        DeRef(_3784);
        _2 = (int)SEQ_PTR(_4SymTab);
        _3784 = (int)*(((s1_ptr)_2)->base + _sym);
        RefDS(_3784);
        _2 = (int)SEQ_PTR(_3784);
        _sym = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_sym))
            _sym = (long)DBL_PTR(_sym)->dbl;

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
        DeRef(_0);
        goto L1F;
L20:
        ;
        DeRef(_i);
    }

    // 	    emit_op(UPDATE_GLOBALS)
    _14emit_op(89);
L1E:
L21:

    //     putback(tok)
    RefDS(_tok);
    _15putback(_tok);

    //     FuncReturn = FALSE
    _15FuncReturn = 0;

    //     Statement_list()
    _15Statement_list();

    //     tok_match(END)
    _15tok_match(402);

    //     ExitScope()
    _10ExitScope();

    //     tok_match(prog_type)
    _15tok_match(_prog_type);

    //     if prog_type != PROCEDURE then
    if (_prog_type == 405)
        goto L22;

    // 	if not FuncReturn then
    if (_15FuncReturn != 0)
        goto L23;

    // 	    if prog_type = FUNCTION then
    if (_prog_type != 406)
        goto L24;

    // 		CompileErr("no value returned from function")
    RefDS(_3831);
    _6CompileErr(_3831);
    goto L25;
L24:

    // 		CompileErr("type must return true / false value")
    RefDS(_3832);
    _6CompileErr(_3832);
L25:
L23:

    // 	emit_op(BADRETURNF) -- function/type shouldn't reach here 
    _14emit_op(43);
    goto L26;
L22:

    // 	StartSourceLine(TRUE)
    _14StartSourceLine(1);

    // 	if not TRANSLATE then

    // 	    if OpTrace then
    if (_4OpTrace == 0)
        goto L27;

    // 		emit_op(ERASE_PRIVATE_NAMES)
    _14emit_op(88);

    // 		emit_addr(p)
    _14emit_addr(_p);
L27:
L28:

    // 	emit_op(RETURNP)
    _14emit_op(29);

    // 	if TRANSLATE then
L26:

    //     SymTab[p][S_STACK_SPACE] = temps_allocated + param_num
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p + ((s1_ptr)_2)->base);
    DeRef(_3700);
    _3700 = _10temps_allocated + _15param_num;
    if ((long)((unsigned long)_3700 + (unsigned long)HIGH_BITS) >= 0) 
        _3700 = NewDouble((double)_3700);
    Ref(_3700);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 25);
    _1 = *(int *)_2;
    *(int *)_2 = _3700;
    DeRef(_1);

    //     if temps_allocated + param_num > max_stack_per_call then 
    DeRef(_3700);
    _3700 = _10temps_allocated + _15param_num;
    if ((long)((unsigned long)_3700 + (unsigned long)HIGH_BITS) >= 0) 
        _3700 = NewDouble((double)_3700);
    if (binary_op_a(LESSEQ, _3700, _15max_stack_per_call))
        goto L29;

    // 	max_stack_per_call = temps_allocated + param_num
    _15max_stack_per_call = _10temps_allocated + _15param_num;
L29:

    //     StraightenBranches()
    _15StraightenBranches();

    //     EnterTopLevel()
    _15EnterTopLevel();

    // end procedure
    DeRef(_tok);
    DeRef(_prog_name);
    DeRef(_3700);
    DeRef(_3702);
    DeRef(_3784);
    return 0;
    ;
}


