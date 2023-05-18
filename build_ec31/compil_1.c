// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18unary_div(int _pc, int _target_type, int _intcode, int _gencode)
{
    int _6187 = 0;
    int _6185 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }
    if (!IS_ATOM_INT(_target_type)) {
        _1 = (long)(DBL_PTR(_target_type)->dbl);
        DeRefDS(_target_type);
        _target_type = _1;
    }

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], 0, 0)
    _6185 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6185 = (int)*(((s1_ptr)_2)->base + _6185);
    Ref(_6185);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    RefDS(_5774);
    Ref(_6185);
    Ref(_6187);
    _18CSaveStr(_5774, _6185, _6187, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6187);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    Ref(_6187);
    RefDS(_5781);
    _0 = _6187;
    _6187 = _16TypeIs(_6187, _5781);
    DeRef(_0);
    if (_6187 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6187) && DBL_PTR(_6187)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_6187);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    RefDS(_6192);
    Ref(_6187);
    _16c_stmt(_6192, _6187);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6187);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    Ref(_6187);
    RefDS(_6197);
    _0 = _6187;
    _6187 = _16TypeIs(_6187, _6197);
    DeRef(_0);
    if (_6187 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_6187) && DBL_PTR(_6187)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt(intcode, {Code[pc+3], Code[pc+1]})
    DeRef(_6187);
    _6187 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    DeRef(_6185);
    _6185 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6185 = (int)*(((s1_ptr)_2)->base + _6185);
    Ref(_6185);
    _0 = _6185;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6187;
    Ref(_6187);
    ((int *)_2)[2] = _6185;
    Ref(_6185);
    _6185 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_intcode);
    RefDS(_6185);
    _16c_stmt(_intcode, _6185);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6185);
    _6185 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6185 = (int)*(((s1_ptr)_2)->base + _6185);
    Ref(_6185);
    Ref(_6185);
    RefDS(_5781);
    _0 = _6185;
    _6185 = _16TypeIs(_6185, _5781);
    DeRef(_0);
    if (_6185 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6185) && DBL_PTR(_6185)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L3:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_6185);
    _6185 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6185 = (int)*(((s1_ptr)_2)->base + _6185);
    Ref(_6185);
    Ref(_6185);
    _0 = _6185;
    _6185 = _16TypeIsNot(_6185, 1);
    DeRef(_0);
    if (_6185 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_6185) && DBL_PTR(_6185)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt(gencode, {Code[pc+3], Code[pc+1]})
    DeRef(_6185);
    _6185 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6185 = (int)*(((s1_ptr)_2)->base + _6185);
    Ref(_6185);
    DeRef(_6187);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    _0 = _6187;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6185;
    Ref(_6185);
    ((int *)_2)[2] = _6187;
    Ref(_6187);
    _6187 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_gencode);
    RefDS(_6187);
    _16c_stmt(_gencode, _6187);
L4:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6187);
    _6187 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    Ref(_6187);
    RefDS(_5781);
    _0 = _6187;
    _6187 = _16TypeIs(_6187, _5781);
    DeRef(_0);
    if (_6187 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_6187) && DBL_PTR(_6187)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L5:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], target_type, novalue, TYPE_OBJECT)
    DeRef(_6187);
    _6187 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6187 = (int)*(((s1_ptr)_2)->base + _6187);
    Ref(_6187);
    Ref(_6187);
    RefDS(_9novalue);
    _16SetBBType(_6187, _target_type, _9novalue, 16);

    // end procedure 
    DeRefDS(_intcode);
    DeRefDS(_gencode);
    DeRef(_6187);
    DeRef(_6185);
    return 0;
    ;
}


int _18unary_optimize(int _pc, int _target_type, int _target_val, int _intcode, int _intcode2, int _gencode)
{
    int _6222 = 0;
    int _6224 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }
    if (!IS_ATOM_INT(_target_type)) {
        _1 = (long)(DBL_PTR(_target_type)->dbl);
        DeRefDS(_target_type);
        _target_type = _1;
    }

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _6222 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    RefDS(_5774);
    Ref(_6222);
    Ref(_6224);
    _18CSaveStr(_5774, _6222, _6224, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    Ref(_6224);
    RefDS(_5781);
    _0 = _6224;
    _6224 = _16TypeIs(_6224, _5781);
    DeRef(_0);
    if (_6224 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6224) && DBL_PTR(_6224)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    RefDS(_6192);
    Ref(_6224);
    _16c_stmt(_6192, _6224);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    Ref(_6224);
    RefDS(_6197);
    _0 = _6224;
    _6224 = _16TypeIs(_6224, _6197);
    DeRef(_0);
    if (_6224 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_6224) && DBL_PTR(_6224)->dbl == 0.0)
            goto L2;
    }

    // 	if Code[pc] = UMINUS then
    DeRef(_6224);
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6224);
    if (binary_op_a(NOTEQ, _6224, 12))
        goto L3;

    // 	    if (target_type = TYPE_INTEGER or 
    DeRef(_6224);
    _6224 = (_target_type == 1);
    if (_6224 != 0) {
        _6224 = 1;
        goto L4;
    }
    DeRef(_6222);
    _6222 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    _0 = _6222;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6222))
        _6222 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6222)->dbl));
    else
        _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    RefDS(_6222);
    DeRef(_0);
    _0 = _6222;
    _2 = (int)SEQ_PTR(_6222);
    _6222 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6222);
    DeRefDS(_0);
    _0 = _6222;
    if (IS_ATOM_INT(_6222)) {
        _6222 = (_6222 == 1);
    }
    else {
        _6222 = binary_op(EQUALS, _6222, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6222))
        _6224 = (_6222 != 0);
    else
        _6224 = DBL_PTR(_6222)->dbl != 0.0;
L4:
    if (_6224 == 0) {
        goto L5;
    }
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    Ref(_6224);
    _0 = _6224;
    _6224 = _16TypeIs(_6224, 1);
    DeRef(_0);
L6:
    if (_6224 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_6224) && DBL_PTR(_6224)->dbl == 0.0)
            goto L5;
    }

    // 		c_stmt(intcode2, {Code[pc+2], Code[pc+1]})
    DeRef(_6224);
    _6224 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    DeRef(_6222);
    _6222 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    _0 = _6222;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6224;
    Ref(_6224);
    ((int *)_2)[2] = _6222;
    Ref(_6222);
    _6222 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_intcode2);
    RefDS(_6222);
    _16c_stmt(_intcode2, _6222);

    // 		CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 		SetBBType(Code[pc+2], TYPE_INTEGER, target_val, TYPE_OBJECT)
    DeRefDS(_6222);
    _6222 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    Ref(_6222);
    RefDS(_target_val);
    _16SetBBType(_6222, 1, _target_val, 16);

    // 		pc += 3
    _pc = _pc + 3;

    // 		if Code[pc] = INTEGER_CHECK then
    DeRef(_6222);
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6222);
    if (binary_op_a(NOTEQ, _6222, 96))
        goto L7;

    // 		    pc += 2 -- skip it
    _pc = _pc + 2;
L7:

    // 		return pc
    DeRefDS(_target_val);
    DeRefDS(_intcode);
    DeRefDS(_intcode2);
    DeRefDS(_gencode);
    DeRef(_6222);
    DeRef(_6224);
    return _pc;
L5:
L3:

    // 	c_stmt(intcode, {Code[pc+2], Code[pc+1]})
    DeRef(_6222);
    _6222 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    _0 = _6224;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6222;
    Ref(_6222);
    ((int *)_2)[2] = _6224;
    Ref(_6224);
    _6224 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_intcode);
    RefDS(_6224);
    _16c_stmt(_intcode, _6224);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    Ref(_6224);
    RefDS(_5781);
    _0 = _6224;
    _6224 = _16TypeIs(_6224, _5781);
    DeRef(_0);
    if (_6224 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_6224) && DBL_PTR(_6224)->dbl == 0.0)
            goto L8;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L8:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_6224);
    _6224 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    Ref(_6224);
    _0 = _6224;
    _6224 = _16TypeIsNot(_6224, 1);
    DeRef(_0);
    if (_6224 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_6224) && DBL_PTR(_6224)->dbl == 0.0)
            goto L9;
    }

    // 	c_stmt(gencode, {Code[pc+2], Code[pc+1]})
    DeRef(_6224);
    _6224 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6224 = (int)*(((s1_ptr)_2)->base + _6224);
    Ref(_6224);
    DeRef(_6222);
    _6222 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    _0 = _6222;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6224;
    Ref(_6224);
    ((int *)_2)[2] = _6222;
    Ref(_6222);
    _6222 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_gencode);
    RefDS(_6222);
    _16c_stmt(_gencode, _6222);
L9:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_6222);
    _6222 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    Ref(_6222);
    RefDS(_5781);
    _0 = _6222;
    _6222 = _16TypeIs(_6222, _5781);
    DeRef(_0);
    if (_6222 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_6222) && DBL_PTR(_6222)->dbl == 0.0)
            goto LA;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
LA:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+2], target_type, target_val, TYPE_OBJECT)
    DeRef(_6222);
    _6222 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6222 = (int)*(((s1_ptr)_2)->base + _6222);
    Ref(_6222);
    Ref(_6222);
    RefDS(_target_val);
    _16SetBBType(_6222, _target_type, _target_val, 16);

    //     return pc + 3
    DeRef(_6222);
    _6222 = _pc + 3;
    if ((long)((unsigned long)_6222 + (unsigned long)HIGH_BITS) >= 0) 
        _6222 = NewDouble((double)_6222);
    DeRefDS(_target_val);
    DeRefDS(_intcode);
    DeRefDS(_intcode2);
    DeRefDS(_gencode);
    DeRef(_6224);
    return _6222;
    ;
}


int _18ifwi(int _pc, int _op)
{
    int _result = 0;
    int _left_val = 0;
    int _right_val = 0;
    int _6315 = 0;
    int _6289 = 0;
    int _6280 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    //     result = NOVALUE
    RefDS(_4NOVALUE);
    _result = _4NOVALUE;

    //     left_val = ObjMinMax(Code[pc+1])
    _6280 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6280 = (int)*(((s1_ptr)_2)->base + _6280);
    Ref(_6280);
    Ref(_6280);
    _left_val = _18ObjMinMax(_6280);

    //     right_val = ObjMinMax(Code[pc+2])
    DeRef(_6280);
    _6280 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6280 = (int)*(((s1_ptr)_2)->base + _6280);
    Ref(_6280);
    Ref(_6280);
    _right_val = _18ObjMinMax(_6280);

    //     if equal(op, ">=") then
    DeRef(_6280);
    if (_op == _6286)
        _6280 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6286))
        _6280 = 0;
    else
        _6280 = (compare(_op, _6286) == 0);
    if (_6280 == 0)
        goto L1;

    // 	if left_val[MIN] >= right_val[MAX] then
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    if (binary_op_a(LESS, _6280, _6289))
        goto L2;

    // 	    result = TRUE
    DeRefDS(_result);
    _result = 1;
    goto L3;
L2:

    // 	elsif left_val[MAX] < right_val[MIN] then
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    if (binary_op_a(GREATEREQ, _6289, _6280))
        goto L3;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
L4:
L5:
    goto L3;
L1:

    //     elsif equal(op, "<=") then
    DeRef(_6280);
    if (_op == _6294)
        _6280 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6294))
        _6280 = 0;
    else
        _6280 = (compare(_op, _6294) == 0);
    if (_6280 == 0)
        goto L6;

    // 	if left_val[MAX] <= right_val[MIN] then
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    if (binary_op_a(GREATER, _6280, _6289))
        goto L7;

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
    goto L3;
L7:

    // 	elsif left_val[MIN] > right_val[MAX] then
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    if (binary_op_a(LESSEQ, _6289, _6280))
        goto L3;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
L8:
L9:
    goto L3;
L6:

    //     elsif equal(op, "!=") then
    DeRef(_6280);
    if (_op == _6302)
        _6280 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6302))
        _6280 = 0;
    else
        _6280 = (compare(_op, _6302) == 0);
    if (_6280 == 0)
        goto LA;

    // 	if left_val[MAX] < right_val[MIN] then
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    if (binary_op_a(GREATEREQ, _6280, _6289))
        goto LB;

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
    goto L3;
LB:

    // 	elsif left_val[MIN] > right_val[MAX] then
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    if (binary_op_a(LESSEQ, _6289, _6280))
        goto LC;

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
    goto L3;
LC:

    // 	elsif left_val[MAX] = left_val[MIN] and 
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    _0 = _6289;
    if (IS_ATOM_INT(_6280) && IS_ATOM_INT(_6289)) {
        _6289 = (_6280 == _6289);
    }
    else {
        _6289 = binary_op(EQUALS, _6280, _6289);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6289)) {
        if (_6289 == 0) {
            DeRef(_6289);
            _6289 = 0;
            goto LD;
        }
    }
    else {
        if (DBL_PTR(_6289)->dbl == 0.0) {
            DeRef(_6289);
            _6289 = 0;
            goto LD;
        }
    }
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    DeRef(_6315);
    _2 = (int)SEQ_PTR(_right_val);
    _6315 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6315);
    _0 = _6315;
    if (IS_ATOM_INT(_6280) && IS_ATOM_INT(_6315)) {
        _6315 = (_6280 == _6315);
    }
    else {
        _6315 = binary_op(EQUALS, _6280, _6315);
    }
    DeRef(_0);
    DeRef(_6289);
    if (IS_ATOM_INT(_6315))
        _6289 = (_6315 != 0);
    else
        _6289 = DBL_PTR(_6315)->dbl != 0.0;
LD:
    if (_6289 == 0) {
        goto L3;
    }
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    _0 = _6289;
    if (IS_ATOM_INT(_6280) && IS_ATOM_INT(_6289)) {
        _6289 = (_6280 == _6289);
    }
    else {
        _6289 = binary_op(EQUALS, _6280, _6289);
    }
    DeRef(_0);
LE:
    if (_6289 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6289) && DBL_PTR(_6289)->dbl == 0.0)
            goto L3;
    }

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
LF:
L10:
    goto L3;
LA:

    //     elsif equal(op, "==") then
    DeRef(_6289);
    if (_op == _6321)
        _6289 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6321))
        _6289 = 0;
    else
        _6289 = (compare(_op, _6321) == 0);
    if (_6289 == 0)
        goto L11;

    // 	if left_val[MAX] < right_val[MIN] then
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    if (binary_op_a(GREATEREQ, _6289, _6280))
        goto L12;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
    goto L3;
L12:

    // 	elsif left_val[MIN] > right_val[MAX] then
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    if (binary_op_a(LESSEQ, _6280, _6289))
        goto L13;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
    goto L3;
L13:

    // 	elsif left_val[MAX] = left_val[MIN] and 
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    _0 = _6280;
    if (IS_ATOM_INT(_6289) && IS_ATOM_INT(_6280)) {
        _6280 = (_6289 == _6280);
    }
    else {
        _6280 = binary_op(EQUALS, _6289, _6280);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6280)) {
        if (_6280 == 0) {
            DeRef(_6280);
            _6280 = 0;
            goto L14;
        }
    }
    else {
        if (DBL_PTR(_6280)->dbl == 0.0) {
            DeRef(_6280);
            _6280 = 0;
            goto L14;
        }
    }
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    DeRef(_6315);
    _2 = (int)SEQ_PTR(_right_val);
    _6315 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6315);
    _0 = _6315;
    if (IS_ATOM_INT(_6289) && IS_ATOM_INT(_6315)) {
        _6315 = (_6289 == _6315);
    }
    else {
        _6315 = binary_op(EQUALS, _6289, _6315);
    }
    DeRef(_0);
    DeRef(_6280);
    if (IS_ATOM_INT(_6315))
        _6280 = (_6315 != 0);
    else
        _6280 = DBL_PTR(_6315)->dbl != 0.0;
L14:
    if (_6280 == 0) {
        goto L3;
    }
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    _0 = _6280;
    if (IS_ATOM_INT(_6289) && IS_ATOM_INT(_6280)) {
        _6280 = (_6289 == _6280);
    }
    else {
        _6280 = binary_op(EQUALS, _6289, _6280);
    }
    DeRef(_0);
L15:
    if (_6280 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6280) && DBL_PTR(_6280)->dbl == 0.0)
            goto L3;
    }

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
L16:
L17:
    goto L3;
L11:

    //     elsif equal(op, ">") then
    DeRef(_6280);
    if (_op == _6340)
        _6280 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6340))
        _6280 = 0;
    else
        _6280 = (compare(_op, _6340) == 0);
    if (_6280 == 0)
        goto L18;

    // 	if left_val[MIN] > right_val[MAX] then
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    if (binary_op_a(LESSEQ, _6280, _6289))
        goto L19;

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
    goto L3;
L19:

    // 	elsif left_val[MAX] <= right_val[MIN] then
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6280);
    if (binary_op_a(GREATER, _6289, _6280))
        goto L3;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
L1A:
L1B:
    goto L3;
L18:

    //     elsif equal(op, "<") then
    DeRef(_6280);
    if (_op == _6348)
        _6280 = 1;
    else if (IS_ATOM_INT(_op) && IS_ATOM_INT(_6348))
        _6280 = 0;
    else
        _6280 = (compare(_op, _6348) == 0);
    if (_6280 == 0)
        goto L1C;

    // 	if left_val[MAX] < right_val[MIN] then
    _2 = (int)SEQ_PTR(_left_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_right_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    if (binary_op_a(GREATEREQ, _6280, _6289))
        goto L1D;

    // 	    result = TRUE
    DeRef(_result);
    _result = 1;
    goto L1E;
L1D:

    // 	elsif left_val[MIN] >= right_val[MAX] then
    DeRef(_6289);
    _2 = (int)SEQ_PTR(_left_val);
    _6289 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6289);
    DeRef(_6280);
    _2 = (int)SEQ_PTR(_right_val);
    _6280 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6280);
    if (binary_op_a(LESS, _6289, _6280))
        goto L1F;

    // 	    result = FALSE
    DeRef(_result);
    _result = 0;
L1F:
L1E:
L1C:
L3:

    //     if result = TRUE then
    if (binary_op_a(NOTEQ, _result, 1))
        goto L20;

    // 	return Code[pc+3]
    DeRef(_6280);
    _6280 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6280 = (int)*(((s1_ptr)_2)->base + _6280);
    Ref(_6280);
    DeRefDS(_op);
    DeRef(_result);
    DeRef(_left_val);
    DeRef(_right_val);
    DeRef(_6315);
    DeRef(_6289);
    return _6280;
    goto L21;
L20:

    //     elsif result = NOVALUE then
    if (binary_op_a(NOTEQ, _result, _4NOVALUE))
        goto L22;

    // 	c_stmt("if (@ " & op & " @)\n", {Code[pc+1], Code[pc+2]})
    {
        int concat_list[3];

        concat_list[0] = _6361;
        concat_list[1] = _op;
        concat_list[2] = _6360;
        Concat_N((object_ptr)&_6280, concat_list, 3);
    }
    DeRef(_6289);
    _6289 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6289 = (int)*(((s1_ptr)_2)->base + _6289);
    Ref(_6289);
    DeRef(_6315);
    _6315 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6315 = (int)*(((s1_ptr)_2)->base + _6315);
    Ref(_6315);
    _0 = _6315;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6289;
    Ref(_6289);
    ((int *)_2)[2] = _6315;
    Ref(_6315);
    _6315 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_6280);
    RefDS(_6315);
    _16c_stmt(_6280, _6315);

    // 	Goto(Code[pc+3])
    DeRefDS(_6315);
    _6315 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6315 = (int)*(((s1_ptr)_2)->base + _6315);
    Ref(_6315);
    Ref(_6315);
    _18Goto(_6315);

    // 	return pc + 4
    DeRef(_6315);
    _6315 = _pc + 4;
    if ((long)((unsigned long)_6315 + (unsigned long)HIGH_BITS) >= 0) 
        _6315 = NewDouble((double)_6315);
    DeRefDS(_op);
    DeRef(_result);
    DeRef(_left_val);
    DeRef(_right_val);
    DeRefDS(_6280);
    DeRef(_6289);
    return _6315;
    goto L21;
L22:

    // 	return pc + 4
    DeRef(_6315);
    _6315 = _pc + 4;
    if ((long)((unsigned long)_6315 + (unsigned long)HIGH_BITS) >= 0) 
        _6315 = NewDouble((double)_6315);
    DeRefDS(_op);
    DeRef(_result);
    DeRef(_left_val);
    DeRef(_right_val);
    DeRef(_6289);
    DeRef(_6280);
    return _6315;
L21:
    ;
}


int _18ifw(int _pc, int _op, int _intop)
{
    int _6372 = 0;
    int _6376 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) and 
    _6372 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6372 = (int)*(((s1_ptr)_2)->base + _6372);
    Ref(_6372);
    Ref(_6372);
    _0 = _6372;
    _6372 = _16TypeIs(_6372, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_6372)) {
        if (_6372 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_6372)->dbl == 0.0) {
            goto L1;
        }
    }
    _6376 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6376 = (int)*(((s1_ptr)_2)->base + _6376);
    Ref(_6376);
    Ref(_6376);
    _0 = _6376;
    _6376 = _16TypeIs(_6376, 1);
    DeRef(_0);
L2:
    if (_6376 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6376) && DBL_PTR(_6376)->dbl == 0.0)
            goto L1;
    }

    // 	return ifwi(pc, intop)
    RefDS(_intop);
    _0 = _6376;
    _6376 = _18ifwi(_pc, _intop);
    DeRef(_0);
    DeRefDS(_op);
    DeRefDS(_intop);
    DeRef(_6372);
    return _6376;
    goto L3;
L1:

    // 	c_stmt0("if (binary_op_a(")
    RefDS(_6380);
    _16c_stmt0(_6380);

    // 	c_puts(op)
    RefDS(_op);
    _9c_puts(_op);

    // 	temp_indent = -indent
    _9temp_indent = - _9indent;

    // 	c_stmt(", @, @))\n", {Code[pc+1], Code[pc+2]})
    DeRef(_6376);
    _6376 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6376 = (int)*(((s1_ptr)_2)->base + _6376);
    Ref(_6376);
    DeRef(_6372);
    _6372 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6372 = (int)*(((s1_ptr)_2)->base + _6372);
    Ref(_6372);
    _0 = _6372;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6376;
    Ref(_6376);
    ((int *)_2)[2] = _6372;
    Ref(_6372);
    _6372 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_6382);
    RefDS(_6372);
    _16c_stmt(_6382, _6372);
L3:

    //     temp_indent = 4
    _9temp_indent = 4;

    //     Goto(Code[pc+3])
    DeRef(_6372);
    _6372 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6372 = (int)*(((s1_ptr)_2)->base + _6372);
    Ref(_6372);
    Ref(_6372);
    _18Goto(_6372);

    //     return pc + 4
    DeRef(_6372);
    _6372 = _pc + 4;
    if ((long)((unsigned long)_6372 + (unsigned long)HIGH_BITS) >= 0) 
        _6372 = NewDouble((double)_6372);
    DeRefDS(_op);
    DeRefDS(_intop);
    DeRef(_6376);
    return _6372;
    ;
}


