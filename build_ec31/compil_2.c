// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18binary_op(int _pc, int _iii, int _target_val, int _intcode, int _intcode2, int _intcode_extra, int _gencode, int _dblfn, int _atom_type)
{
    int _target_elem;
    int _target_type;
    int _np;
    int _check;
    int _close_brace;
    int _6404 = 0;
    int _6408 = 0;
    int _6391 = 0;
    int _6395 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_pc)) {
        _1 = (long)(DBL_PTR(_pc)->dbl);
        DeRefDS(_pc);
        _pc = _1;
    }
    if (!IS_ATOM_INT(_iii)) {
        _1 = (long)(DBL_PTR(_iii)->dbl);
        DeRefDS(_iii);
        _iii = _1;
    }
    if (!IS_ATOM_INT(_atom_type)) {
        _1 = (long)(DBL_PTR(_atom_type)->dbl);
        DeRefDS(_atom_type);
        _atom_type = _1;
    }

    //     target_elem = TYPE_OBJECT
    _target_elem = 16;

    //     if TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, 8);
    DeRef1(_0);
    if (_6391 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L1;
    }

    // 	target_type = TYPE_SEQUENCE
    _target_type = 8;

    // 	if iii and 
    if (_iii == 0) {
        DeRef1(_6391);
        _6391 = 0;
        goto L2;
    }
    _6395 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6395);
    _0 = _6395;
    _6395 = _18SeqElem(_6395);
    DeRef1(_0);
    _6395 = (_6395 == 1);
    _6391 = (_6395 != 0);
L2:
    if (_6391 == 0) {
        goto L3;
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, 1);
    DeRef1(_0);
    if (IS_ATOM_INT(_6391)) {
        if (_6391 != 0) {
            DeRef1(_6391);
            _6391 = 1;
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_6391)->dbl != 0.0) {
            DeRef1(_6391);
            _6391 = 1;
            goto L4;
        }
    }
    DeRef1(_6404);
    _6404 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _16TypeIs(_6404, 8);
    DeRef1(_0);
    if (IS_ATOM_INT(_6404)) {
        if (_6404 == 0) {
            DeRef1(_6404);
            _6404 = 0;
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_6404)->dbl == 0.0) {
            DeRef1(_6404);
            _6404 = 0;
            goto L5;
        }
    }
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _18SeqElem(_6408);
    DeRef1(_0);
    _6408 = (_6408 == 1);
    DeRef1(_6404);
    _6404 = (_6408 != 0);
L5:
    DeRef1(_6391);
    _6391 = (_6404 != 0);
L4:
L6:
    if (_6391 == 0)
        goto L3;

    // 	    target_elem = TYPE_INTEGER
    _target_elem = 1;
L7:
    goto L3;
L1:

    //     elsif TypeIs(Code[pc+2], TYPE_SEQUENCE) then
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, 8);
    DeRef1(_0);
    if (_6408 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L8;
    }

    // 	target_type = TYPE_SEQUENCE
    _target_type = 8;

    // 	if iii and 
    if (_iii == 0) {
        DeRef1(_6408);
        _6408 = 0;
        goto L9;
    }
    DeRef1(_6404);
    _6404 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _18SeqElem(_6404);
    DeRef1(_0);
    _6404 = (_6404 == 1);
    _6408 = (_6404 != 0);
L9:
    if (_6408 == 0) {
        goto L3;
    }
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, 1);
    DeRef1(_0);
LA:
    if (_6408 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L3;
    }

    // 	    target_elem = TYPE_INTEGER
    _target_elem = 1;
LB:
    goto L3;
L8:

    //     elsif TypeIs(Code[pc+1], TYPE_OBJECT) then
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, 16);
    DeRef1(_0);
    if (_6408 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto LC;
    }

    // 	target_type = TYPE_OBJECT
    _target_type = 16;
    goto L3;
LC:

    //     elsif TypeIs(Code[pc+2], TYPE_OBJECT) then
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, 16);
    DeRef1(_0);
    if (_6408 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto LD;
    }

    // 	target_type = TYPE_OBJECT
    _target_type = 16;
    goto L3;
LD:

    // 	target_type = atom_type
    _target_type = _atom_type;
L3:

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_5774);
    Ref(_6408);
    Ref(_6404);
    Ref(_6391);
    _18CSaveStr(_5774, _6408, _6404, _6391, 0);

    //     close_brace = FALSE
    _close_brace = 0;

    //     check = 0
    _check = 0;

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) and 
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, 1);
    DeRef1(_0);
    if (IS_ATOM_INT(_6391)) {
        if (_6391 == 0) {
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_6391)->dbl == 0.0) {
            goto LE;
        }
    }
    DeRef1(_6404);
    _6404 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _16TypeIs(_6404, 1);
    DeRef1(_0);
LF:
    if (_6404 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_6404) && DBL_PTR(_6404)->dbl == 0.0)
            goto LE;
    }

    // 	if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I,
    DeRef1(_6404);
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6404);
    _0 = _6404;
    _6404 = find(_6404, _6444);
    DeRef1(_0);
    if (_6404 == 0)
        goto L10;

    // 	    np = pc + 4 + 2 * (Code[pc+4] = INTEGER_CHECK)
    _6404 = _pc + 4;
    if ((long)((unsigned long)_6404 + (unsigned long)HIGH_BITS) >= 0) 
        _6404 = NewDouble((double)_6404);
    DeRef1(_6391);
    _6391 = _pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    _0 = _6391;
    if (IS_ATOM_INT(_6391)) {
        _6391 = (_6391 == 96);
    }
    else {
        _6391 = binary_op(EQUALS, _6391, 96);
    }
    DeRef1(_0);
    _0 = _6391;
    if (IS_ATOM_INT(_6391) && IS_ATOM_INT(_6391)) {
        _6391 = _6391 + _6391;
        if ((long)((unsigned long)_6391 + (unsigned long)HIGH_BITS) >= 0) 
            _6391 = NewDouble((double)_6391);
    }
    else {
        _6391 = binary_op(PLUS, _6391, _6391);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6404) && IS_ATOM_INT(_6391)) {
        _np = _6404 + _6391;
    }
    else {
        _np = binary_op(PLUS, _6404, _6391);
    }
    if (!IS_ATOM_INT(_np)) {
        _1 = (long)(DBL_PTR(_np)->dbl);
        DeRefDS(_np);
        _np = _1;
    }

    // 	    target = FoldInteger(Code[pc], Code[pc+3], Code[pc+1], Code[pc+2])
    DeRef1(_6391);
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6391);
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6391);
    Ref(_6404);
    Ref(_6408);
    Ref(_6395);
    _0 = _18FoldInteger(_6391, _6404, _6408, _6395);
    DeRef1(_18target);
    _18target = _0;

    // 	    if target[MIN] != NOVALUE and 
    DeRef1(_6395);
    _2 = (int)SEQ_PTR(_18target);
    _6395 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6395);
    _0 = _6395;
    _6395 = binary_op(NOTEQ, _6395, _4NOVALUE);
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 == 0) {
            goto L11;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl == 0.0) {
            goto L11;
        }
    }
    DeRef1(_6408);
    _2 = (int)SEQ_PTR(_18target);
    _6408 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6408);
    DeRef1(_6404);
    _2 = (int)SEQ_PTR(_18target);
    _6404 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6404);
    _0 = _6404;
    if (IS_ATOM_INT(_6408) && IS_ATOM_INT(_6404)) {
        _6404 = (_6408 == _6404);
    }
    else {
        _6404 = binary_op(EQUALS, _6408, _6404);
    }
    DeRef1(_0);
L12:
    if (_6404 == 0) {
        goto L11;
    }
    else {
        if (!IS_ATOM_INT(_6404) && DBL_PTR(_6404)->dbl == 0.0)
            goto L11;
    }

    // 		CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 		SetBBType(Code[pc+3], TYPE_INTEGER, target, 
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    RefDS(_18target);
    _16SetBBType(_6404, 1, _18target, 16);

    // 		return np
    DeRef1(_target_val);
    DeRef1(_intcode);
    DeRef1(_intcode2);
    DeRef1(_intcode_extra);
    DeRef1(_gencode);
    DeRef1(_dblfn);
    DeRef(_6404);
    DeRef(_6408);
    DeRef(_6391);
    DeRef(_6395);
    return _np;
    goto L13;
L11:

    // 	    elsif SymTab[Code[pc+3]][S_GTYPE] = TYPE_INTEGER or 
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    _0 = _6404;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6404))
        _6404 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6404)->dbl));
    else
        _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    RefDS(_6404);
    DeRef1(_0);
    _0 = _6404;
    _2 = (int)SEQ_PTR(_6404);
    _6404 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6404);
    DeRef1(_0);
    _0 = _6404;
    if (IS_ATOM_INT(_6404)) {
        _6404 = (_6404 == 1);
    }
    else {
        _6404 = binary_op(EQUALS, _6404, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6404)) {
        if (_6404 != 0) {
            DeRef1(_6404);
            _6404 = 1;
            goto L14;
        }
    }
    else {
        if (DBL_PTR(_6404)->dbl != 0.0) {
            DeRef1(_6404);
            _6404 = 1;
            goto L14;
        }
    }
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _18IntegerSize(_np, _6408);
    DeRef1(_0);
    DeRef1(_6404);
    if (IS_ATOM_INT(_6408))
        _6404 = (_6408 != 0);
    else
        _6404 = DBL_PTR(_6408)->dbl != 0.0;
L14:
    if (_6404 != 0) {
        goto L15;
    }
    DeRef1(_6404);
    _2 = (int)SEQ_PTR(_18target);
    _6404 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6404);
    _0 = _6404;
    _6404 = binary_op(NOTEQ, _6404, _4NOVALUE);
    DeRef1(_0);
L16:
    if (_6404 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_6404) && DBL_PTR(_6404)->dbl == 0.0)
            goto L17;
    }
L15:

    // 		c_stmt(intcode2, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6404);
    *((int *)(_2+4)) = _6404;
    Ref(_6408);
    *((int *)(_2+8)) = _6408;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode2);
    RefDS(_6395);
    _16c_stmt(_intcode2, _6395);

    // 		CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 		if target[MIN] = NOVALUE then
    DeRef1(_6395);
    _2 = (int)SEQ_PTR(_18target);
    _6395 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_6395);
    if (binary_op_a(NOTEQ, _6395, _4NOVALUE))
        goto L18;

    // 		    target = novalue
    RefDS(_9novalue);
    DeRef1(_18target);
    _18target = _9novalue;
L18:

    // 		SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6395);
    RefDS(_18target);
    _16SetBBType(_6395, 1, _18target, 16);

    // 		return np 
    DeRef1(_target_val);
    DeRef1(_intcode);
    DeRef1(_intcode2);
    DeRef1(_intcode_extra);
    DeRef1(_gencode);
    DeRef1(_dblfn);
    DeRef(_6404);
    DeRef(_6408);
    DeRef(_6391);
    DeRef(_6395);
    return _np;
L17:
L13:
L10:

    // 	c_stmt(intcode, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    _0 = _6404;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6395);
    *((int *)(_2+4)) = _6395;
    Ref(_6408);
    *((int *)(_2+8)) = _6408;
    Ref(_6404);
    *((int *)(_2+12)) = _6404;
    _6404 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode);
    RefDS(_6404);
    _16c_stmt(_intcode, _6404);

    // 	if iii then
    if (_iii == 0)
        goto L19;

    // 	    SetBBType(Code[pc+3], TYPE_INTEGER, target_val, TYPE_OBJECT)
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    RefDS(_target_val);
    _16SetBBType(_6404, 1, _target_val, 16);
    goto L1A;
L19:

    // 	    SetBBType(Code[pc+3], TYPE_ATOM, novalue, TYPE_OBJECT)
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    RefDS(_9novalue);
    _16SetBBType(_6404, 4, _9novalue, 16);
L1A:

    // 	if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I}) then
    DeRef1(_6404);
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6404);
    _0 = _6404;
    _6404 = find(_6404, _6503);
    DeRef1(_0);
    if (_6404 == 0)
        goto L1B;

    // 	    c_stmt(intcode_extra, {Code[pc+3], Code[pc+1], Code[pc+2]})
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6404);
    *((int *)(_2+4)) = _6404;
    Ref(_6408);
    *((int *)(_2+8)) = _6408;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode_extra);
    RefDS(_6395);
    _16c_stmt(_intcode_extra, _6395);
L1B:

    // 	CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	return pc + 4
    DeRef1(_6395);
    _6395 = _pc + 4;
    if ((long)((unsigned long)_6395 + (unsigned long)HIGH_BITS) >= 0) 
        _6395 = NewDouble((double)_6395);
    DeRef1(_target_val);
    DeRef1(_intcode);
    DeRef1(_intcode2);
    DeRef1(_intcode_extra);
    DeRef1(_gencode);
    DeRef1(_dblfn);
    DeRef(_6404);
    DeRef(_6408);
    DeRef(_6391);
    return _6395;
    goto L1C;
LE:

    //     elsif TypeIs(Code[pc+2], TYPE_INTEGER) and 
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6395);
    _0 = _6395;
    _6395 = _16TypeIs(_6395, 1);
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 == 0) {
            goto L1D;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl == 0.0) {
            goto L1D;
        }
    }
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_5781);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, _5781);
    DeRef1(_0);
L1E:
    if (_6408 == 0) {
        goto L1D;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L1D;
    }

    // 	check = 1
    _check = 1;

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6192);
    Ref(_6408);
    _16c_stmt(_6192, _6408);

    // 	if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I,
    DeRef1(_6408);
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6408);
    _0 = _6408;
    _6408 = find(_6408, _6523);
    DeRef1(_0);
    if (_6408 == 0) {
        goto L1F;
    }
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6395))
        _6395 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6395)->dbl));
    else
        _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    RefDS(_6395);
    DeRef1(_0);
    _0 = _6395;
    _2 = (int)SEQ_PTR(_6395);
    _6395 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6395);
    DeRef1(_0);
    _0 = _6395;
    if (IS_ATOM_INT(_6395)) {
        _6395 = (_6395 == 1);
    }
    else {
        _6395 = binary_op(EQUALS, _6395, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 != 0) {
            DeRef1(_6395);
            _6395 = 1;
            goto L20;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl != 0.0) {
            DeRef1(_6395);
            _6395 = 1;
            goto L20;
        }
    }
    DeRef1(_6404);
    _6404 = _pc + 4;
    if ((long)((unsigned long)_6404 + (unsigned long)HIGH_BITS) >= 0) 
        _6404 = NewDouble((double)_6404);
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6404);
    Ref(_6391);
    _0 = _6391;
    _6391 = _18IntegerSize(_6404, _6391);
    DeRef1(_0);
    DeRef1(_6395);
    if (IS_ATOM_INT(_6391))
        _6395 = (_6391 != 0);
    else
        _6395 = DBL_PTR(_6391)->dbl != 0.0;
L20:
L21:
    if (_6395 == 0)
        goto L1F;

    // 	    c_stmt(intcode2, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6391);
    *((int *)(_2+4)) = _6391;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode2);
    RefDS(_6395);
    _16c_stmt(_intcode2, _6395);
    goto L22;
L1F:

    // 	    c_stmt(intcode, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    _0 = _6391;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6395);
    *((int *)(_2+4)) = _6395;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6391);
    *((int *)(_2+12)) = _6391;
    _6391 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode);
    RefDS(_6391);
    _16c_stmt(_intcode, _6391);

    // 	    if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I}) then
    DeRef1(_6391);
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6391);
    _0 = _6391;
    _6391 = find(_6391, _6503);
    DeRef1(_0);
    if (_6391 == 0)
        goto L23;

    // 		SetBBType(Code[pc+3], GType(Code[pc+3]), target_val, target_elem)
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _16GType(_6404);
    DeRef1(_0);
    Ref(_6391);
    RefDS(_target_val);
    _16SetBBType(_6391, _6404, _target_val, _target_elem);

    // 		c_stmt(intcode_extra, {Code[pc+3], Code[pc+1], Code[pc+2]})
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6404);
    *((int *)(_2+4)) = _6404;
    Ref(_6391);
    *((int *)(_2+8)) = _6391;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode_extra);
    RefDS(_6395);
    _16c_stmt(_intcode_extra, _6395);
L23:
L22:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
    goto L1C;
L1D:

    //     elsif TypeIs(Code[pc+1], TYPE_INTEGER) and
    DeRef1(_6395);
    _6395 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6395);
    _0 = _6395;
    _6395 = _16TypeIs(_6395, 1);
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 == 0) {
            goto L24;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl == 0.0) {
            goto L24;
        }
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_5781);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, _5781);
    DeRef1(_0);
L25:
    if (_6391 == 0) {
        goto L24;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L24;
    }

    // 	check = 2
    _check = 2;

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+2])
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6192);
    Ref(_6391);
    _16c_stmt(_6192, _6391);

    // 	if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I,
    DeRef1(_6391);
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6391);
    _0 = _6391;
    _6391 = find(_6391, _6523);
    DeRef1(_0);
    if (_6391 == 0) {
        goto L26;
    }
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6395))
        _6395 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6395)->dbl));
    else
        _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    RefDS(_6395);
    DeRef1(_0);
    _0 = _6395;
    _2 = (int)SEQ_PTR(_6395);
    _6395 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6395);
    DeRef1(_0);
    _0 = _6395;
    if (IS_ATOM_INT(_6395)) {
        _6395 = (_6395 == 1);
    }
    else {
        _6395 = binary_op(EQUALS, _6395, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 != 0) {
            DeRef1(_6395);
            _6395 = 1;
            goto L27;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl != 0.0) {
            DeRef1(_6395);
            _6395 = 1;
            goto L27;
        }
    }
    DeRef1(_6404);
    _6404 = _pc + 4;
    if ((long)((unsigned long)_6404 + (unsigned long)HIGH_BITS) >= 0) 
        _6404 = NewDouble((double)_6404);
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6404);
    Ref(_6408);
    _0 = _6408;
    _6408 = _18IntegerSize(_6404, _6408);
    DeRef1(_0);
    DeRef1(_6395);
    if (IS_ATOM_INT(_6408))
        _6395 = (_6408 != 0);
    else
        _6395 = DBL_PTR(_6408)->dbl != 0.0;
L27:
L28:
    if (_6395 == 0)
        goto L26;

    // 	    c_stmt(intcode2, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6408);
    *((int *)(_2+4)) = _6408;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode2);
    RefDS(_6395);
    _16c_stmt(_intcode2, _6395);
    goto L29;
L26:

    // 	    c_stmt(intcode, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6395);
    _6395 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    _0 = _6408;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6395);
    *((int *)(_2+4)) = _6395;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6408);
    *((int *)(_2+12)) = _6408;
    _6408 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode);
    RefDS(_6408);
    _16c_stmt(_intcode, _6408);

    // 	    if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I}) then
    DeRef1(_6408);
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6408);
    _0 = _6408;
    _6408 = find(_6408, _6503);
    DeRef1(_0);
    if (_6408 == 0)
        goto L2A;

    // 		SetBBType(Code[pc+3], GType(Code[pc+3]), 
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _16GType(_6404);
    DeRef1(_0);
    Ref(_6408);
    RefDS(_target_val);
    _16SetBBType(_6408, _6404, _target_val, _target_elem);

    // 		c_stmt(intcode_extra, {Code[pc+3], Code[pc+1], Code[pc+2]})
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6404);
    *((int *)(_2+4)) = _6404;
    Ref(_6408);
    *((int *)(_2+8)) = _6408;
    Ref(_6395);
    *((int *)(_2+12)) = _6395;
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode_extra);
    RefDS(_6395);
    _16c_stmt(_intcode_extra, _6395);
L2A:
L29:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
    goto L1C;
L24:

    //     elsif TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) and
    DeRef1(_6395);
    _6395 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    Ref(_6395);
    RefDS(_5781);
    _0 = _6395;
    _6395 = _16TypeIs(_6395, _5781);
    DeRef1(_0);
    if (IS_ATOM_INT(_6395)) {
        if (_6395 == 0) {
            goto L2B;
        }
    }
    else {
        if (DBL_PTR(_6395)->dbl == 0.0) {
            goto L2B;
        }
    }
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_5781);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, _5781);
    DeRef1(_0);
L2C:
    if (_6408 == 0) {
        goto L2B;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L2B;
    }

    // 	c_stmt("if (IS_ATOM_INT(@) && IS_ATOM_INT(@)) {\n", {Code[pc+1], Code[pc+2]})
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6395);
    _6395 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _6395);
    Ref(_6395);
    _0 = _6395;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6408;
    Ref(_6408);
    ((int *)_2)[2] = _6395;
    Ref(_6395);
    _6395 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_6621);
    RefDS(_6395);
    _16c_stmt(_6621, _6395);

    // 	if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I,
    DeRef1(_6395);
    _2 = (int)SEQ_PTR(_4Code);
    _6395 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6395);
    _0 = _6395;
    _6395 = find(_6395, _6523);
    DeRef1(_0);
    if (_6395 == 0) {
        goto L2D;
    }
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    _0 = _6408;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6408))
        _6408 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6408)->dbl));
    else
        _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    RefDS(_6408);
    DeRef1(_0);
    _0 = _6408;
    _2 = (int)SEQ_PTR(_6408);
    _6408 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6408);
    DeRef1(_0);
    _0 = _6408;
    if (IS_ATOM_INT(_6408)) {
        _6408 = (_6408 == 1);
    }
    else {
        _6408 = binary_op(EQUALS, _6408, 1);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6408)) {
        if (_6408 != 0) {
            DeRef1(_6408);
            _6408 = 1;
            goto L2E;
        }
    }
    else {
        if (DBL_PTR(_6408)->dbl != 0.0) {
            DeRef1(_6408);
            _6408 = 1;
            goto L2E;
        }
    }
    DeRef1(_6404);
    _6404 = _pc + 4;
    if ((long)((unsigned long)_6404 + (unsigned long)HIGH_BITS) >= 0) 
        _6404 = NewDouble((double)_6404);
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6404);
    Ref(_6391);
    _0 = _6391;
    _6391 = _18IntegerSize(_6404, _6391);
    DeRef1(_0);
    DeRef1(_6408);
    if (IS_ATOM_INT(_6391))
        _6408 = (_6391 != 0);
    else
        _6408 = DBL_PTR(_6391)->dbl != 0.0;
L2E:
L2F:
    if (_6408 == 0)
        goto L2D;

    // 	    c_stmt(intcode2, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    _0 = _6408;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6391);
    *((int *)(_2+4)) = _6391;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6408);
    *((int *)(_2+12)) = _6408;
    _6408 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode2);
    RefDS(_6408);
    _16c_stmt(_intcode2, _6408);
    goto L30;
L2D:

    // 	    c_stmt(intcode, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    _0 = _6391;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6408);
    *((int *)(_2+4)) = _6408;
    Ref(_6404);
    *((int *)(_2+8)) = _6404;
    Ref(_6391);
    *((int *)(_2+12)) = _6391;
    _6391 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode);
    RefDS(_6391);
    _16c_stmt(_intcode, _6391);

    // 	    if find(Code[pc], {PLUS, PLUS_I, MINUS, MINUS_I}) then
    DeRef1(_6391);
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6391);
    _0 = _6391;
    _6391 = find(_6391, _6503);
    DeRef1(_0);
    if (_6391 == 0)
        goto L31;

    // 		SetBBType(Code[pc+3], GType(Code[pc+3]), target_val, target_elem)
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    _0 = _6404;
    _6404 = _16GType(_6404);
    DeRef1(_0);
    Ref(_6391);
    RefDS(_target_val);
    _16SetBBType(_6391, _6404, _target_val, _target_elem);

    // 		c_stmt(intcode_extra, {Code[pc+3], Code[pc+1], Code[pc+2]})
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    _0 = _6408;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6404);
    *((int *)(_2+4)) = _6404;
    Ref(_6391);
    *((int *)(_2+8)) = _6391;
    Ref(_6408);
    *((int *)(_2+12)) = _6408;
    _6408 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_intcode_extra);
    RefDS(_6408);
    _16c_stmt(_intcode_extra, _6408);
L31:
L30:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
L2B:
L1C:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) or 
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIsNot(_6408, 1);
    DeRef1(_0);
    if (IS_ATOM_INT(_6408)) {
        if (_6408 != 0) {
            goto L32;
        }
    }
    else {
        if (DBL_PTR(_6408)->dbl != 0.0) {
            goto L32;
        }
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    _0 = _6391;
    _6391 = _16TypeIsNot(_6391, 1);
    DeRef1(_0);
L33:
    if (_6391 == 0) {
        goto L34;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L34;
    }
L32:

    // 	if Code[pc] != FLOOR_DIV and
    DeRef1(_6391);
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _pc);
    Ref(_6391);
    _0 = _6391;
    if (IS_ATOM_INT(_6391)) {
        _6391 = (_6391 != 63);
    }
    else {
        _6391 = binary_op(NOTEQ, _6391, 63);
    }
    DeRef1(_0);
    if (IS_ATOM_INT(_6391)) {
        if (_6391 == 0) {
            DeRef1(_6391);
            _6391 = 0;
            goto L35;
        }
    }
    else {
        if (DBL_PTR(_6391)->dbl == 0.0) {
            DeRef1(_6391);
            _6391 = 0;
            goto L35;
        }
    }
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_4094);
    _0 = _6408;
    _6408 = _16TypeIsNot(_6408, _4094);
    DeRef1(_0);
    DeRef1(_6391);
    if (IS_ATOM_INT(_6408))
        _6391 = (_6408 != 0);
    else
        _6391 = DBL_PTR(_6408)->dbl != 0.0;
L35:
    if (_6391 == 0) {
        goto L36;
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_4094);
    _0 = _6391;
    _6391 = _16TypeIsNot(_6391, _4094);
    DeRef1(_0);
L37:
    if (_6391 == 0) {
        goto L36;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L36;
    }

    // 	    if check != 1 and 
    DeRef1(_6391);
    _6391 = (_check != 1);
    if (_6391 == 0) {
        goto L38;
    }
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_5781);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, _5781);
    DeRef1(_0);
L39:
    if (_6408 == 0) {
        goto L38;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L38;
    }

    // 		c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6192);
    Ref(_6408);
    _16c_stmt(_6192, _6408);
L38:

    // 	    if check != 1 and 
    DeRef1(_6408);
    _6408 = (_check != 1);
    if (_6408 == 0) {
        goto L3A;
    }
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_6197);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, _6197);
    DeRef1(_0);
L3B:
    if (_6391 == 0) {
        goto L3A;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L3A;
    }

    // 		if length(dblfn) > 2 then
    DeRef1(_6391);
    _6391 = SEQ_PTR(_dblfn)->length;
    if (_6391 <= 2)
        goto L3C;

    // 		    c_stmt("temp_d.dbl = (double)@;\n", Code[pc+1])
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6699);
    Ref(_6391);
    _16c_stmt(_6699, _6391);

    // 		    c_stmt("@ = ", Code[pc+3])
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_5789);
    Ref(_6391);
    _16c_stmt(_5789, _6391);

    // 		    c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 		    temp_indent = -indent
    _9temp_indent = - _9indent;

    // 		    c_stmt("(&temp_d, DBL_PTR(@));\n", Code[pc+2])
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6705);
    Ref(_6391);
    _16c_stmt(_6705, _6391);
    goto L3D;
L3C:

    // 		    c_stmt("@ = ", Code[pc+3])
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_5789);
    Ref(_6391);
    _16c_stmt(_5789, _6391);

    // 		    temp_indent = -indent
    _9temp_indent = - _9indent;

    // 		    if atom_type = TYPE_INTEGER then
    if (_atom_type != 1)
        goto L3E;

    // 			c_stmt("((double)@ ", Code[pc+1])
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6712);
    Ref(_6391);
    _16c_stmt(_6712, _6391);
    goto L3F;
L3E:

    // 			c_stmt("NewDouble((double)@ ", Code[pc+1])
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6715);
    Ref(_6391);
    _16c_stmt(_6715, _6391);
L3F:

    // 		    c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 		    temp_indent = -indent
    _9temp_indent = - _9indent;

    // 		    c_stmt(" DBL_PTR(@)->dbl);\n", Code[pc+2])
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6719);
    Ref(_6391);
    _16c_stmt(_6719, _6391);
L3D:
L3A:

    // 	    if check != 1 and
    DeRef1(_6391);
    _6391 = (_check != 1);
    if (_6391 == 0) {
        goto L40;
    }
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_5781);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, _5781);
    DeRef1(_0);
L41:
    if (_6408 == 0) {
        goto L40;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L40;
    }

    // 		c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 		c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L40:

    // 	    if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    _0 = _6408;
    _6408 = _16TypeIsNot(_6408, 1);
    DeRef1(_0);
    if (_6408 == 0) {
        goto L42;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L42;
    }

    // 		if check != 2 and
    DeRef1(_6408);
    _6408 = (_check != 2);
    if (_6408 == 0) {
        goto L43;
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_5781);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, _5781);
    DeRef1(_0);
L44:
    if (_6391 == 0) {
        goto L43;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L43;
    }

    // 		    c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+2])
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_6192);
    Ref(_6391);
    _16c_stmt(_6192, _6391);
L43:

    // 		if check != 2 and 
    DeRef1(_6391);
    _6391 = (_check != 2);
    if (_6391 == 0) {
        goto L45;
    }
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    Ref(_6408);
    RefDS(_6197);
    _0 = _6408;
    _6408 = _16TypeIs(_6408, _6197);
    DeRef1(_0);
L46:
    if (_6408 == 0) {
        goto L45;
    }
    else {
        if (!IS_ATOM_INT(_6408) && DBL_PTR(_6408)->dbl == 0.0)
            goto L45;
    }

    // 		    if length(dblfn) > 2 then
    DeRef1(_6408);
    _6408 = SEQ_PTR(_dblfn)->length;
    if (_6408 <= 2)
        goto L47;

    // 			c_stmt("temp_d.dbl = (double)@;\n", Code[pc+2])
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6699);
    Ref(_6408);
    _16c_stmt(_6699, _6408);

    // 			c_stmt("@ = ", Code[pc+3])
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_5789);
    Ref(_6408);
    _16c_stmt(_5789, _6408);

    // 			c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			c_stmt("(DBL_PTR(@), &temp_d);\n", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6749);
    Ref(_6408);
    _16c_stmt(_6749, _6408);
    goto L48;
L47:

    // 			c_stmt("@ = ", Code[pc+3])
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_5789);
    Ref(_6408);
    _16c_stmt(_5789, _6408);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			if atom_type = TYPE_INTEGER then
    if (_atom_type != 1)
        goto L49;

    // 			    c_stmt("(DBL_PTR(@)->dbl ", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6756);
    Ref(_6408);
    _16c_stmt(_6756, _6408);
    goto L4A;
L49:

    // 			    c_stmt("NewDouble(DBL_PTR(@)->dbl ", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6759);
    Ref(_6408);
    _16c_stmt(_6759, _6408);
L4A:

    // 			c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			c_stmt(" (double)@);\n", Code[pc+2])
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6763);
    Ref(_6408);
    _16c_stmt(_6763, _6408);
L48:
L45:

    // 		if check != 2 and 
    DeRef1(_6408);
    _6408 = (_check != 2);
    if (_6408 == 0) {
        goto L4B;
    }
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_5781);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, _5781);
    DeRef1(_0);
L4C:
    if (_6391 == 0) {
        goto L4B;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L4B;
    }

    // 		    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 		    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L4B:

    // 		if TypeIsNot(Code[pc+2], TYPE_INTEGER) then
    DeRef1(_6391);
    _6391 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    _0 = _6391;
    _6391 = _16TypeIsNot(_6391, 1);
    DeRef1(_0);
    if (_6391 == 0) {
        goto L4D;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L4D;
    }

    // 		    if length(dblfn) > 2 then
    DeRef1(_6391);
    _6391 = SEQ_PTR(_dblfn)->length;
    if (_6391 <= 2)
        goto L4E;

    // 			c_stmt("@ = ", Code[pc+3])
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    RefDS(_5789);
    Ref(_6391);
    _16c_stmt(_5789, _6391);

    // 			c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			c_stmt("(DBL_PTR(@), DBL_PTR(@));\n", 
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    _0 = _6408;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6391;
    Ref(_6391);
    ((int *)_2)[2] = _6408;
    Ref(_6408);
    _6408 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_6779);
    RefDS(_6408);
    _16c_stmt(_6779, _6408);
    goto L4F;
L4E:

    // 			c_stmt("@ = ", Code[pc+3])
    DeRef1(_6408);
    _6408 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_5789);
    Ref(_6408);
    _16c_stmt(_5789, _6408);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			if atom_type = TYPE_INTEGER then
    if (_atom_type != 1)
        goto L50;

    // 			    c_stmt("(DBL_PTR(@)->dbl ", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6756);
    Ref(_6408);
    _16c_stmt(_6756, _6408);
    goto L51;
L50:

    // 			    c_stmt("NewDouble(DBL_PTR(@)->dbl ", Code[pc+1])
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6759);
    Ref(_6408);
    _16c_stmt(_6759, _6408);
L51:

    // 			c_puts(dblfn)
    RefDS(_dblfn);
    _9c_puts(_dblfn);

    // 			temp_indent = -indent
    _9temp_indent = - _9indent;

    // 			c_stmt(" DBL_PTR(@)->dbl);\n", Code[pc+2])
    DeRef1(_6408);
    _6408 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    RefDS(_6719);
    Ref(_6408);
    _16c_stmt(_6719, _6408);
L4F:
L4D:
L42:

    // 	    if check != 1 and 
    DeRef1(_6408);
    _6408 = (_check != 1);
    if (_6408 == 0) {
        goto L52;
    }
    DeRef1(_6391);
    _6391 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    Ref(_6391);
    RefDS(_5781);
    _0 = _6391;
    _6391 = _16TypeIs(_6391, _5781);
    DeRef1(_0);
L53:
    if (_6391 == 0) {
        goto L52;
    }
    else {
        if (!IS_ATOM_INT(_6391) && DBL_PTR(_6391)->dbl == 0.0)
            goto L52;
    }

    // 		c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L54:
    goto L52;
L36:

    // 	    c_stmt(gencode, {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef1(_6391);
    _6391 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6391 = (int)*(((s1_ptr)_2)->base + _6391);
    Ref(_6391);
    DeRef1(_6408);
    _6408 = _pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6408 = (int)*(((s1_ptr)_2)->base + _6408);
    Ref(_6408);
    DeRef1(_6404);
    _6404 = _pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    _0 = _6404;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_6391);
    *((int *)(_2+4)) = _6391;
    Ref(_6408);
    *((int *)(_2+8)) = _6408;
    Ref(_6404);
    *((int *)(_2+12)) = _6404;
    _6404 = MAKE_SEQ(_1);
    DeRef1(_0);
    RefDS(_gencode);
    RefDS(_6404);
    _16c_stmt(_gencode, _6404);
L52:
L34:

    //     if close_brace then
    if (_close_brace == 0)
        goto L55;

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L55:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], target_type, target_val, target_elem)
    DeRef1(_6404);
    _6404 = _pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _6404 = (int)*(((s1_ptr)_2)->base + _6404);
    Ref(_6404);
    Ref(_6404);
    RefDS(_target_val);
    _16SetBBType(_6404, _target_type, _target_val, _target_elem);

    //     return pc + 4
    DeRef1(_6404);
    _6404 = _pc + 4;
    if ((long)((unsigned long)_6404 + (unsigned long)HIGH_BITS) >= 0) 
        _6404 = NewDouble((double)_6404);
    DeRef1(_target_val);
    DeRef1(_intcode);
    DeRef1(_intcode2);
    DeRef1(_intcode_extra);
    DeRef1(_gencode);
    DeRef1(_dblfn);
    DeRef(_6408);
    DeRef(_6391);
    DeRef(_6395);
    return _6404;
    ;
}


int _18arg_list(int _i)
{
    int _6815 = 0;
    int _6811;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_i)) {
        _1 = (long)(DBL_PTR(_i)->dbl);
        DeRefDS(_i);
        _i = _1;
    }

    //     indent += 20
    _9indent = _9indent + 20;

    //     for k = 1 to i do
    _6811 = _i;
    { int _k;
        _k = 1;
L1:
        if (_k > _6811)
            goto L2;

        // 	c_stmt0("*(int *)(_2+")
        RefDS(_6813);
        _16c_stmt0(_6813);

        // 	c_printf("%d)", k * 4)
        DeRef(_6815);
        if (_k == (short)_k)
            _6815 = _k * 4;
        else
            _6815 = NewDouble(_k * (double)4);
        RefDS(_6814);
        Ref(_6815);
        _9c_printf(_6814, _6815);

        // 	if k != i then
        if (_k == _i)
            goto L3;

        // 	    c_puts(", ")
        RefDS(_5165);
        _9c_puts(_5165);
L3:

        // 	c_puts("\n")
        RefDS(_629);
        _9c_puts(_629);

        //     end for
        _k = _k + 1;
        goto L1;
L2:
        ;
    }

    //     c_stmt0(" );\n")
    RefDS(_6817);
    _16c_stmt0(_6817);

    //     indent -= 20
    _9indent = _9indent - 20;

    // end procedure
    DeRef(_6815);
    return 0;
    ;
}


int _18opSTARTLINE()
{
    int _line = 0;
    int _offset;
    int _6825 = 0;
    int _6819 = 0;
    int _0, _1, _2;
    

    //     c_putc('\n')
    _9c_putc(10);

    //     offset = slist[Code[pc+1]][SRC]
    _6819 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6819 = (int)*(((s1_ptr)_2)->base + _6819);
    Ref(_6819);
    _0 = _6819;
    _2 = (int)SEQ_PTR(_4slist);
    if (!IS_ATOM_INT(_6819))
        _6819 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6819)->dbl));
    else
        _6819 = (int)*(((s1_ptr)_2)->base + _6819);
    Ref(_6819);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_6819);
    _offset = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_offset))
        _offset = (long)DBL_PTR(_offset)->dbl;

    //     line = fetch_line(offset)
    _line = _11fetch_line(_offset);

    //     if trace_called and 
    if (_14trace_called == 0) {
        goto L1;
    }
    _6825 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_4slist);
    if (!IS_ATOM_INT(_6825))
        _6825 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6825)->dbl));
    else
        _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    DeRef(_0);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_6825);
    _6825 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6825);
    DeRef(_0);
    _0 = _6825;
    if (IS_ATOM_INT(_6825)) {
        _6825 = (_6825 & 1);
    }
    else {
        _6825 = binary_op(AND_BITS, _6825, 1);
    }
    DeRef(_0);
L2:
    if (_6825 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_6825) && DBL_PTR(_6825)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt0("ctrace(\"")
    RefDS(_6830);
    _16c_stmt0(_6830);

    // 	c_puts(name_ext(file_name[slist[Code[pc+1]][LOCAL_FILE_NO]]))
    DeRef(_6825);
    _6825 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_4slist);
    if (!IS_ATOM_INT(_6825))
        _6825 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6825)->dbl));
    else
        _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    DeRef(_0);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_6825);
    _6825 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6825);
    DeRef(_0);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_4file_name);
    if (!IS_ATOM_INT(_6825))
        _6825 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6825)->dbl));
    else
        _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    RefDS(_6825);
    DeRef(_0);
    RefDS(_6825);
    _0 = _6825;
    _6825 = _10name_ext(_6825);
    DeRefDS(_0);
    RefDS(_6825);
    _9c_puts(_6825);

    // 	c_printf(":%d\t", slist[Code[pc+1]][LINE])
    DeRefDS(_6825);
    _6825 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_4slist);
    if (!IS_ATOM_INT(_6825))
        _6825 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6825)->dbl));
    else
        _6825 = (int)*(((s1_ptr)_2)->base + _6825);
    Ref(_6825);
    DeRef(_0);
    _0 = _6825;
    _2 = (int)SEQ_PTR(_6825);
    _6825 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6825);
    DeRef(_0);
    RefDS(_6837);
    Ref(_6825);
    _9c_printf(_6837, _6825);

    // 	c_fixquote(line)
    RefDS(_line);
    _18c_fixquote(_line);

    // 	c_puts("\");\n")
    RefDS(_6842);
    _9c_puts(_6842);
    goto L3;
L1:

    // 	c_stmt0("// ")
    RefDS(_6843);
    _16c_stmt0(_6843);

    // 	for i = length(line) to 1 by -1 do
    DeRef(_6825);
    _6825 = SEQ_PTR(_line)->length;
    { int _i;
        _i = _6825;
L4:
        if (_i < 1)
            goto L5;

        // 	    if not find(line[i], " \t\r\n") then
        DeRef(_6825);
        _2 = (int)SEQ_PTR(_line);
        _6825 = (int)*(((s1_ptr)_2)->base + _i);
        _6825 = find(_6825, _6846);
        if (_6825 != 0)
            goto L6;

        // 		if line[i] = '\\' then
        _2 = (int)SEQ_PTR(_line);
        _6825 = (int)*(((s1_ptr)_2)->base + _i);
        if (_6825 != 92)
            goto L5;

        // 		    line &= " --"
        Concat((object_ptr)&_line, _line, (s1_ptr)_6851);
L7:

        // 		exit
        goto L5;
L6:

        // 	end for
        _i = _i + -1;
        goto L4;
L5:
        ;
    }

    // 	c_puts(line)
    RefDS(_line);
    _9c_puts(_line);

    // 	c_puts("\n")
    RefDS(_629);
    _9c_puts(_629);
L3:

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRefi(_line);
    DeRef(_6825);
    DeRef(_6819);
    return 0;
    ;
}


int _18opPROC()
{
    int _sub;
    int _n;
    int _t;
    int _p;
    int _6871 = 0;
    int _6854 = 0;
    int _6876 = 0;
    int _6874 = 0;
    int _6859 = 0;
    int _0, _1, _2, _3;
    

    //     sub = Code[pc+1]
    _6854 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _6854);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     n = 2 + SymTab[sub][S_NUM_ARGS] + (SymTab[sub][S_TOKEN] != PROC)
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6854);
    DeRefDS(_0);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = 2 + _6854;
        if ((long)((unsigned long)_6854 + (unsigned long)HIGH_BITS) >= 0) 
            _6854 = NewDouble((double)_6854);
    }
    else {
        _6854 = binary_op(PLUS, 2, _6854);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6859 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6859);
    _0 = _6859;
    _2 = (int)SEQ_PTR(_6859);
    _6859 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6859);
    DeRefDS(_0);
    _0 = _6859;
    if (IS_ATOM_INT(_6859)) {
        _6859 = (_6859 != 27);
    }
    else {
        _6859 = binary_op(NOTEQ, _6859, 27);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6854) && IS_ATOM_INT(_6859)) {
        _n = _6854 + _6859;
    }
    else {
        _n = binary_op(PLUS, _6854, _6859);
    }
    if (!IS_ATOM_INT(_n)) {
        _1 = (long)(DBL_PTR(_n)->dbl);
        DeRefDS(_n);
        _n = _1;
    }

    //     p = SymTab[sub][S_NEXT]
    DeRef(_6859);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6859 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6859);
    _2 = (int)SEQ_PTR(_6859);
    _p = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     for i = 1 to SymTab[sub][S_NUM_ARGS] do
    DeRefDS(_6859);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6859 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6859);
    _0 = _6859;
    _2 = (int)SEQ_PTR(_6859);
    _6859 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6859);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L1:
        if (binary_op_a(GREATER, _i, _6859))
            goto L2;

        // 	t = Code[pc+1+i]
        DeRef(_6854);
        _6854 = _18pc + 1;
        if (_6854 > MAXINT)
            _6854 = NewDouble((double)_6854);
        _0 = _6854;
        if (IS_ATOM_INT(_6854) && IS_ATOM_INT(_i)) {
            _6854 = _6854 + _i;
        }
        else {
            if (IS_ATOM_INT(_6854)) {
                _6854 = NewDouble((double)_6854 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _6854 = NewDouble(DBL_PTR(_6854)->dbl + (double)_i);
                }
                else
                    _6854 = NewDouble(DBL_PTR(_6854)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_6854))
            _t = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6854)->dbl));
        else
            _t = (int)*(((s1_ptr)_2)->base + _6854);
        if (!IS_ATOM_INT(_t))
            _t = (long)DBL_PTR(_t)->dbl;

        // 	CRef(t)
        _18CRef(_t);

        // 	SymTab[t][S_ONE_REF] = FALSE
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
        _2 = (int)(((s1_ptr)_2)->base + 32);
        _1 = *(int *)_2;
        *(int *)_2 = 0;
        DeRef(_1);

        // 	SymTab[p][S_ARG_TYPE_NEW] = or_type(SymTab[p][S_ARG_TYPE_NEW], GType(t))
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRef(_6874);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6874 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6874);
        _0 = _6874;
        _2 = (int)SEQ_PTR(_6874);
        _6874 = (int)*(((s1_ptr)_2)->base + 41);
        Ref(_6874);
        DeRefDS(_0);
        _0 = _6876;
        _6876 = _16GType(_t);
        DeRef(_0);
        Ref(_6874);
        _6876 = _16or_type(_6874, _6876);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 41);
        _1 = *(int *)_2;
        *(int *)_2 = _6876;
        DeRef(_1);

        // 	if TypeIs(t, {TYPE_SEQUENCE, TYPE_OBJECT}) then
        RefDS(_4094);
        _6876 = _16TypeIs(_t, _4094);
        if (_6876 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_6876) && DBL_PTR(_6876)->dbl == 0.0)
                goto L3;
        }

        // 	    SymTab[p][S_ARG_MIN_NEW] = NOVALUE
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        RefDS(_4NOVALUE);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 46);
        _1 = *(int *)_2;
        *(int *)_2 = _4NOVALUE;
        DeRef(_1);

        // 	    SymTab[p][S_ARG_SEQ_ELEM_NEW] = 
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRef(_6854);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6854 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6854);
        _0 = _6854;
        _2 = (int)SEQ_PTR(_6854);
        _6854 = (int)*(((s1_ptr)_2)->base + 43);
        Ref(_6854);
        DeRefDS(_0);
        _0 = _6871;
        _6871 = _18SeqElem(_t);
        DeRef(_0);
        Ref(_6854);
        _6871 = _16or_type(_6854, _6871);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 43);
        _1 = *(int *)_2;
        *(int *)_2 = _6871;
        DeRef(_1);

        // 	    if SymTab[p][S_ARG_SEQ_LEN_NEW] = -NOVALUE then
        _2 = (int)SEQ_PTR(_4SymTab);
        _6871 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6871);
        _0 = _6871;
        _2 = (int)SEQ_PTR(_6871);
        _6871 = (int)*(((s1_ptr)_2)->base + 49);
        Ref(_6871);
        DeRefDS(_0);
        DeRef(_6854);
        _6854 = unary_op(UMINUS, _4NOVALUE);
        if (binary_op_a(NOTEQ, _6871, _6854))
            goto L4;

        // 		SymTab[p][S_ARG_SEQ_LEN_NEW] = SeqLen(t)
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        _0 = _6876;
        _6876 = _18SeqLen(_t);
        DeRef(_0);
        Ref(_6876);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 49);
        _1 = *(int *)_2;
        *(int *)_2 = _6876;
        DeRef(_1);
        goto L5;
L4:

        // 	    elsif SymTab[p][S_ARG_SEQ_LEN_NEW] != SeqLen(t) then
        DeRef(_6876);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6876 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6876);
        _0 = _6876;
        _2 = (int)SEQ_PTR(_6876);
        _6876 = (int)*(((s1_ptr)_2)->base + 49);
        Ref(_6876);
        DeRefDS(_0);
        _0 = _6871;
        _6871 = _18SeqLen(_t);
        DeRef(_0);
        if (binary_op_a(EQUALS, _6876, _6871))
            goto L5;

        // 		SymTab[p][S_ARG_SEQ_LEN_NEW] = NOVALUE
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        RefDS(_4NOVALUE);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 49);
        _1 = *(int *)_2;
        *(int *)_2 = _4NOVALUE;
        DeRef(_1);
L6:
L7:
        goto L5;
L3:

        // 	elsif TypeIs(t, TYPE_INTEGER) then
        _0 = _6876;
        _6876 = _16TypeIs(_t, 1);
        DeRef(_0);
        if (_6876 == 0) {
            goto L8;
        }
        else {
            if (!IS_ATOM_INT(_6876) && DBL_PTR(_6876)->dbl == 0.0)
                goto L8;
        }

        // 	    target = ObjMinMax(t)
        _0 = _18ObjMinMax(_t);
        DeRef(_18target);
        _18target = _0;

        // 	    if SymTab[p][S_ARG_MIN_NEW] = -NOVALUE then
        DeRef(_6876);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6876 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6876);
        _0 = _6876;
        _2 = (int)SEQ_PTR(_6876);
        _6876 = (int)*(((s1_ptr)_2)->base + 46);
        Ref(_6876);
        DeRefDS(_0);
        DeRef(_6871);
        _6871 = unary_op(UMINUS, _4NOVALUE);
        if (binary_op_a(NOTEQ, _6876, _6871))
            goto L9;

        // 		SymTab[p][S_ARG_MIN_NEW] = target[MIN]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRef(_6854);
        _2 = (int)SEQ_PTR(_18target);
        _6854 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6854);
        Ref(_6854);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 46);
        _1 = *(int *)_2;
        *(int *)_2 = _6854;
        DeRef(_1);

        // 		SymTab[p][S_ARG_MAX_NEW] = target[MAX]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRefDS(_6871);
        _2 = (int)SEQ_PTR(_18target);
        _6871 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6871);
        Ref(_6871);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 47);
        _1 = *(int *)_2;
        *(int *)_2 = _6871;
        DeRef(_1);
        goto L5;
L9:

        // 	    elsif SymTab[p][S_ARG_MIN_NEW] != NOVALUE then
        DeRef(_6871);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6871 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6871);
        _0 = _6871;
        _2 = (int)SEQ_PTR(_6871);
        _6871 = (int)*(((s1_ptr)_2)->base + 46);
        Ref(_6871);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _6871, _4NOVALUE))
            goto L5;

        // 		if target[MIN] < SymTab[p][S_ARG_MIN_NEW] then
        DeRef(_6871);
        _2 = (int)SEQ_PTR(_18target);
        _6871 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6871);
        DeRef(_6876);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6876 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6876);
        _0 = _6876;
        _2 = (int)SEQ_PTR(_6876);
        _6876 = (int)*(((s1_ptr)_2)->base + 46);
        Ref(_6876);
        DeRefDS(_0);
        if (binary_op_a(GREATEREQ, _6871, _6876))
            goto LA;

        // 		    SymTab[p][S_ARG_MIN_NEW] = target[MIN]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRef(_6854);
        _2 = (int)SEQ_PTR(_18target);
        _6854 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6854);
        Ref(_6854);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 46);
        _1 = *(int *)_2;
        *(int *)_2 = _6854;
        DeRef(_1);
LA:

        // 		if target[MAX] > SymTab[p][S_ARG_MAX_NEW] then
        DeRef(_6854);
        _2 = (int)SEQ_PTR(_18target);
        _6854 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6854);
        DeRef(_6871);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6871 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6871);
        _0 = _6871;
        _2 = (int)SEQ_PTR(_6871);
        _6871 = (int)*(((s1_ptr)_2)->base + 47);
        Ref(_6871);
        DeRefDS(_0);
        if (binary_op_a(LESSEQ, _6854, _6871))
            goto L5;

        // 		    SymTab[p][S_ARG_MAX_NEW] = target[MAX]
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        DeRef(_6876);
        _2 = (int)SEQ_PTR(_18target);
        _6876 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_6876);
        Ref(_6876);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 47);
        _1 = *(int *)_2;
        *(int *)_2 = _6876;
        DeRef(_1);
LB:
LC:
LD:
        goto L5;
L8:

        // 	    SymTab[p][S_ARG_MIN_NEW] = NOVALUE
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_p + ((s1_ptr)_2)->base);
        RefDS(_4NOVALUE);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 46);
        _1 = *(int *)_2;
        *(int *)_2 = _4NOVALUE;
        DeRef(_1);
L5:

        // 	p = SymTab[p][S_NEXT]
        DeRef(_6854);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6854 = (int)*(((s1_ptr)_2)->base + _p);
        RefDS(_6854);
        _2 = (int)SEQ_PTR(_6854);
        _p = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_p))
            _p = (long)DBL_PTR(_p)->dbl;

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

    //     if SymTab[sub][S_TOKEN] != PROC then
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6854);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _6854, 27))
        goto LE;

    // 	p = Code[pc+n-1]
    DeRef(_6854);
    _6854 = _18pc + _n;
    if ((long)((unsigned long)_6854 + (unsigned long)HIGH_BITS) >= 0) 
        _6854 = NewDouble((double)_6854);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = _6854 - 1;
    }
    else {
        _6854 = NewDouble(DBL_PTR(_6854)->dbl - (double)1);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6854))
        _p = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6854)->dbl));
    else
        _p = (int)*(((s1_ptr)_2)->base + _6854);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    // 	if SymTab[p][S_MODE] = M_NORMAL and (SymTab[p][S_SCOPE] = SC_GLOBAL or
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6854);
    DeRefDS(_0);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = (_6854 == 1);
    }
    else {
        _6854 = binary_op(EQUALS, _6854, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6854)) {
        if (_6854 == 0) {
            goto LF;
        }
    }
    else {
        if (DBL_PTR(_6854)->dbl == 0.0) {
            goto LF;
        }
    }
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6876);
    DeRefDS(_0);
    _0 = _6876;
    if (IS_ATOM_INT(_6876)) {
        _6876 = (_6876 == 6);
    }
    else {
        _6876 = binary_op(EQUALS, _6876, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6876)) {
        if (_6876 != 0) {
            DeRef(_6876);
            _6876 = 1;
            goto L10;
        }
    }
    else {
        if (DBL_PTR(_6876)->dbl != 0.0) {
            DeRef(_6876);
            _6876 = 1;
            goto L10;
        }
    }
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6871);
    DeRefDS(_0);
    _0 = _6871;
    if (IS_ATOM_INT(_6871)) {
        _6871 = (_6871 == 5);
    }
    else {
        _6871 = binary_op(EQUALS, _6871, 5);
    }
    DeRef(_0);
    DeRef(_6876);
    if (IS_ATOM_INT(_6871))
        _6876 = (_6871 != 0);
    else
        _6876 = DBL_PTR(_6871)->dbl != 0.0;
L10:
L11:
    if (_6876 == 0)
        goto LF;

    // 	    c_stmt("_0 = ", p)
    RefDS(_6950);
    _16c_stmt(_6950, _p);
    goto L12;
LF:

    // 	    CSaveStr("_0", p, p, 0, 0)
    RefDS(_5774);
    _18CSaveStr(_5774, _p, _p, 0, 0);

    // 	    c_stmt("@ = ", p)
    RefDS(_5789);
    _16c_stmt(_5789, _p);
L12:

    // 	temp_indent = -indent
    _9temp_indent = - _9indent;
LE:

    //     LeftSym = TRUE
    _16LeftSym = 1;

    //     c_stmt("@", sub)
    RefDS(_6952);
    _16c_stmt(_6952, _sub);

    //     c_puts("(")
    RefDS(_4669);
    _9c_puts(_4669);

    //     for i = 1 to SymTab[sub][S_NUM_ARGS] do
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6871);
    DeRefDS(_0);
    { int _i;
        _i = 1;
L13:
        if (binary_op_a(GREATER, _i, _6871))
            goto L14;

        // 	CName(Code[pc+1+i])
        DeRef(_6876);
        _6876 = _18pc + 1;
        if (_6876 > MAXINT)
            _6876 = NewDouble((double)_6876);
        _0 = _6876;
        if (IS_ATOM_INT(_6876) && IS_ATOM_INT(_i)) {
            _6876 = _6876 + _i;
        }
        else {
            if (IS_ATOM_INT(_6876)) {
                _6876 = NewDouble((double)_6876 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _6876 = NewDouble(DBL_PTR(_6876)->dbl + (double)_i);
                }
                else
                    _6876 = NewDouble(DBL_PTR(_6876)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _6876;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_6876))
            _6876 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6876)->dbl));
        else
            _6876 = (int)*(((s1_ptr)_2)->base + _6876);
        Ref(_6876);
        DeRef(_0);
        Ref(_6876);
        _16CName(_6876);

        // 	if i != SymTab[sub][S_NUM_ARGS] then
        DeRef(_6876);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6876 = (int)*(((s1_ptr)_2)->base + _sub);
        RefDS(_6876);
        _0 = _6876;
        _2 = (int)SEQ_PTR(_6876);
        _6876 = (int)*(((s1_ptr)_2)->base + 20);
        Ref(_6876);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _i, _6876))
            goto L15;

        // 	    c_puts(", ")
        RefDS(_5165);
        _9c_puts(_5165);
L15:

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
        goto L13;
L14:
        ;
        DeRef(_i);
    }

    //     c_puts(");\n")
    RefDS(_4675);
    _9c_puts(_4675);

    //     if SymTab[sub][S_EFFECT] then
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_6876);
    DeRefDS(_0);
    if (_6876 == 0) {
        goto L16;
    }
    else {
        if (!IS_ATOM_INT(_6876) && DBL_PTR(_6876)->dbl == 0.0)
            goto L16;
    }

    // 	NewBB(1, SymTab[sub][S_EFFECT], sub) -- forget some local & global var values 
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 21);
    Ref(_6876);
    DeRefDS(_0);
    Ref(_6876);
    _16NewBB(1, _6876, _sub);
L16:

    //     if SymTab[sub][S_TOKEN] != PROC then
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_6876);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _6876, 27))
        goto L17;

    // 	if SymTab[p][S_MODE] = M_NORMAL and
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6876);
    DeRefDS(_0);
    _0 = _6876;
    if (IS_ATOM_INT(_6876)) {
        _6876 = (_6876 == 1);
    }
    else {
        _6876 = binary_op(EQUALS, _6876, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6876)) {
        if (_6876 == 0) {
            goto L18;
        }
    }
    else {
        if (DBL_PTR(_6876)->dbl == 0.0) {
            goto L18;
        }
    }
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6871);
    DeRefDS(_0);
    _0 = _6871;
    if (IS_ATOM_INT(_6871)) {
        _6871 = (_6871 == 6);
    }
    else {
        _6871 = binary_op(EQUALS, _6871, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6871)) {
        if (_6871 != 0) {
            DeRef(_6871);
            _6871 = 1;
            goto L19;
        }
    }
    else {
        if (DBL_PTR(_6871)->dbl != 0.0) {
            DeRef(_6871);
            _6871 = 1;
            goto L19;
        }
    }
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6854);
    DeRefDS(_0);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = (_6854 == 5);
    }
    else {
        _6854 = binary_op(EQUALS, _6854, 5);
    }
    DeRef(_0);
    DeRef(_6871);
    if (IS_ATOM_INT(_6854))
        _6871 = (_6854 != 0);
    else
        _6871 = DBL_PTR(_6854)->dbl != 0.0;
L19:
L1A:
    if (_6871 == 0)
        goto L18;

    // 	    CDeRef(p)  -- DeRef latest value, not old one
    _18CDeRef(_p);

    // 	    c_stmt("@ = _0;\n", p)
    RefDS(_6979);
    _16c_stmt(_6979, _p);
    goto L1B;
L18:

    // 	    CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);
L1B:

    // 	if SymTab[sub][S_GTYPE] = TYPE_INTEGER then
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6854);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _6854, 1))
        goto L1C;

    // 	    target = {SymTab[sub][S_OBJ_MIN], SymTab[sub][S_OBJ_MAX]}
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 27);
    Ref(_6854);
    DeRefDS(_0);
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 28);
    Ref(_6871);
    DeRefDS(_0);
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _6854;
    Ref(_6854);
    ((int *)_2)[2] = _6871;
    Ref(_6871);
    _18target = MAKE_SEQ(_1);

    // 	    SetBBType(Code[pc+n-1], SymTab[sub][S_GTYPE], target, TYPE_OBJECT)
    DeRef(_6871);
    _6871 = _18pc + _n;
    if ((long)((unsigned long)_6871 + (unsigned long)HIGH_BITS) >= 0) 
        _6871 = NewDouble((double)_6871);
    _0 = _6871;
    if (IS_ATOM_INT(_6871)) {
        _6871 = _6871 - 1;
    }
    else {
        _6871 = NewDouble(DBL_PTR(_6871)->dbl - (double)1);
    }
    DeRef(_0);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6871))
        _6871 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6871)->dbl));
    else
        _6871 = (int)*(((s1_ptr)_2)->base + _6871);
    Ref(_6871);
    DeRef(_0);
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6854);
    DeRefDS(_0);
    Ref(_6871);
    Ref(_6854);
    RefDS(_18target);
    _16SetBBType(_6871, _6854, _18target, 16);
    goto L1D;
L1C:

    // 	elsif SymTab[sub][S_GTYPE] = TYPE_SEQUENCE then
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6854);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _6854, 8))
        goto L1E;

    // 	    target[MIN] = SymTab[sub][S_SEQ_LEN]
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 29);
    Ref(_6854);
    DeRefDS(_0);
    Ref(_6854);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _6854;
    DeRef(_1);

    // 	    SetBBType(Code[pc+n-1], SymTab[sub][S_GTYPE], target, 
    DeRef(_6854);
    _6854 = _18pc + _n;
    if ((long)((unsigned long)_6854 + (unsigned long)HIGH_BITS) >= 0) 
        _6854 = NewDouble((double)_6854);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = _6854 - 1;
    }
    else {
        _6854 = NewDouble(DBL_PTR(_6854)->dbl - (double)1);
    }
    DeRef(_0);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6854))
        _6854 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6854)->dbl));
    else
        _6854 = (int)*(((s1_ptr)_2)->base + _6854);
    Ref(_6854);
    DeRef(_0);
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6871);
    DeRefDS(_0);
    DeRef(_6876);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6876 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6876);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_6876);
    _6876 = (int)*(((s1_ptr)_2)->base + 30);
    Ref(_6876);
    DeRefDS(_0);
    Ref(_6854);
    Ref(_6871);
    RefDS(_18target);
    Ref(_6876);
    _16SetBBType(_6854, _6871, _18target, _6876);
    goto L1D;
L1E:

    // 	    SetBBType(Code[pc+n-1], SymTab[sub][S_GTYPE], novalue, 
    DeRef(_6876);
    _6876 = _18pc + _n;
    if ((long)((unsigned long)_6876 + (unsigned long)HIGH_BITS) >= 0) 
        _6876 = NewDouble((double)_6876);
    _0 = _6876;
    if (IS_ATOM_INT(_6876)) {
        _6876 = _6876 - 1;
    }
    else {
        _6876 = NewDouble(DBL_PTR(_6876)->dbl - (double)1);
    }
    DeRef(_0);
    _0 = _6876;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6876))
        _6876 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6876)->dbl));
    else
        _6876 = (int)*(((s1_ptr)_2)->base + _6876);
    Ref(_6876);
    DeRef(_0);
    DeRef(_6871);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6871 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6871);
    _0 = _6871;
    _2 = (int)SEQ_PTR(_6871);
    _6871 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_6871);
    DeRefDS(_0);
    DeRef(_6854);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6854 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_6854);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_6854);
    _6854 = (int)*(((s1_ptr)_2)->base + 30);
    Ref(_6854);
    DeRefDS(_0);
    Ref(_6876);
    Ref(_6871);
    RefDS(_9novalue);
    Ref(_6854);
    _16SetBBType(_6876, _6871, _9novalue, _6854);
L1D:

    // 	SymTab[Code[pc+n-1]][S_ONE_REF] = FALSE
    DeRef(_6854);
    _6854 = _18pc + _n;
    if ((long)((unsigned long)_6854 + (unsigned long)HIGH_BITS) >= 0) 
        _6854 = NewDouble((double)_6854);
    _0 = _6854;
    if (IS_ATOM_INT(_6854)) {
        _6854 = _6854 - 1;
    }
    else {
        _6854 = NewDouble(DBL_PTR(_6854)->dbl - (double)1);
    }
    DeRef(_0);
    _0 = _6854;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_6854))
        _6854 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6854)->dbl));
    else
        _6854 = (int)*(((s1_ptr)_2)->base + _6854);
    Ref(_6854);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_6854))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_6854)->dbl));
    else
        _3 = (int)(_6854 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);
L17:

    //     pc += n
    _18pc = _18pc + _n;

    // end procedure
    DeRef5(_6871, _6854, _6876, _6874, _6859);
    return 0;
    ;
}


