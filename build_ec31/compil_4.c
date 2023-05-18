// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opPLUS1()
{
    int _7566 = 0;
    int _7534 = 0;
    int _7532 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], 0, 0)
    _7532 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7532 = (int)*(((s1_ptr)_2)->base + _7532);
    Ref(_7532);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    RefDS(_5774);
    Ref(_7532);
    Ref(_7534);
    _18CSaveStr(_5774, _7532, _7534, 0, 0);

    //     target_type = GType(Code[pc+1])
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    _0 = _16GType(_7534);
    _18target_type = _0;

    //     if target_type = TYPE_INTEGER then
    if (_18target_type != 1)
        goto L1;

    // 	target_type = TYPE_ATOM
    _18target_type = 4;
L1:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then 
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    RefDS(_5781);
    _0 = _7534;
    _7534 = _16TypeIs(_7534, _5781);
    DeRef(_0);
    if (_7534 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_7534) && DBL_PTR(_7534)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])              
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    RefDS(_6192);
    Ref(_7534);
    _16c_stmt(_6192, _7534);
L2:

    //     np = pc + 4
    _18np = _18pc + 4;

    //     target_val = novalue
    RefDS(_9novalue);
    DeRef(_18target_val);
    _18target_val = _9novalue;

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    RefDS(_6197);
    _0 = _7534;
    _7534 = _16TypeIs(_7534, _6197);
    DeRef(_0);
    if (_7534 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7534) && DBL_PTR(_7534)->dbl == 0.0)
            goto L3;
    }

    // 	if TypeIs(Code[pc+1], TYPE_INTEGER) then 
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    _0 = _7534;
    _7534 = _16TypeIs(_7534, 1);
    DeRef(_0);
    if (_7534 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_7534) && DBL_PTR(_7534)->dbl == 0.0)
            goto L4;
    }

    // 	    target_val = ObjMinMax(Code[pc+1])
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    _0 = _18ObjMinMax(_7534);
    DeRefDSi(_18target_val);
    _18target_val = _0;
L4:

    // 	ov = TRUE
    _18ov = 1;

    // 	np = pc + 4 + 2 * (Code[pc+4] = INTEGER_CHECK)
    DeRef(_7534);
    _7534 = _18pc + 4;
    if ((long)((unsigned long)_7534 + (unsigned long)HIGH_BITS) >= 0) 
        _7534 = NewDouble((double)_7534);
    DeRef(_7532);
    _7532 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7532 = (int)*(((s1_ptr)_2)->base + _7532);
    Ref(_7532);
    _0 = _7532;
    if (IS_ATOM_INT(_7532)) {
        _7532 = (_7532 == 96);
    }
    else {
        _7532 = binary_op(EQUALS, _7532, 96);
    }
    DeRef(_0);
    _0 = _7532;
    if (IS_ATOM_INT(_7532) && IS_ATOM_INT(_7532)) {
        _7532 = _7532 + _7532;
        if ((long)((unsigned long)_7532 + (unsigned long)HIGH_BITS) >= 0) 
            _7532 = NewDouble((double)_7532);
    }
    else {
        _7532 = binary_op(PLUS, _7532, _7532);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7534) && IS_ATOM_INT(_7532)) {
        _18np = _7534 + _7532;
    }
    else {
        _18np = binary_op(PLUS, _7534, _7532);
    }
    if (!IS_ATOM_INT(_18np)) {
        _1 = (long)(DBL_PTR(_18np)->dbl);
        DeRefDS(_18np);
        _18np = _1;
    }

    // 	if TypeIs(Code[pc+1], TYPE_INTEGER) and
    DeRef(_7532);
    _7532 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7532 = (int)*(((s1_ptr)_2)->base + _7532);
    Ref(_7532);
    Ref(_7532);
    _0 = _7532;
    _7532 = _16TypeIs(_7532, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_7532)) {
        if (_7532 == 0) {
            DeRef(_7532);
            _7532 = 0;
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_7532)->dbl == 0.0) {
            DeRef(_7532);
            _7532 = 0;
            goto L5;
        }
    }
    DeRef(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    _7534 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7534);
    DeRef(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    _7566 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7566);
    _0 = _7566;
    if (IS_ATOM_INT(_7534) && IS_ATOM_INT(_7566)) {
        _7566 = (_7534 == _7566);
    }
    else {
        _7566 = binary_op(EQUALS, _7534, _7566);
    }
    DeRef(_0);
    DeRef(_7532);
    if (IS_ATOM_INT(_7566))
        _7532 = (_7566 != 0);
    else
        _7532 = DBL_PTR(_7566)->dbl != 0.0;
L5:
    if (_7532 == 0) {
        goto L6;
    }
    DeRef(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    _7534 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7534);
    _0 = _7534;
    if (IS_ATOM_INT(_7534)) {
        _7534 = _7534 + 1;
        if (_7534 > MAXINT)
            _7534 = NewDouble((double)_7534);
    }
    else
        _7534 = binary_op(PLUS, 1, _7534);
    DeRef(_0);
    _0 = _7534;
    if (IS_ATOM_INT(_7534)) {
        _7534 = (_7534 <= 1073741823);
    }
    else {
        _7534 = binary_op(LESSEQ, _7534, 1073741823);
    }
    DeRef(_0);
L7:
    if (_7534 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_7534) && DBL_PTR(_7534)->dbl == 0.0)
            goto L6;
    }

    // 	    c_stmt("@ = ", Code[pc+3])
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    RefDS(_5789);
    Ref(_7534);
    _16c_stmt(_5789, _7534);

    // 	    c_printf("%d;\n", target_val[MIN]+1)
    DeRef(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    _7534 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7534);
    _0 = _7534;
    if (IS_ATOM_INT(_7534)) {
        _7534 = _7534 + 1;
        if (_7534 > MAXINT)
            _7534 = NewDouble((double)_7534);
    }
    else
        _7534 = binary_op(PLUS, 1, _7534);
    DeRef(_0);
    RefDS(_5980);
    Ref(_7534);
    _9c_printf(_5980, _7534);

    // 	    target_type = TYPE_INTEGER
    _18target_type = 1;

    // 	    target_val[MIN] += 1
    DeRef(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    _7534 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7534);
    _0 = _7534;
    if (IS_ATOM_INT(_7534)) {
        _7534 = _7534 + 1;
        if (_7534 > MAXINT)
            _7534 = NewDouble((double)_7534);
    }
    else
        _7534 = binary_op(PLUS, 1, _7534);
    DeRef(_0);
    Ref(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7534;
    DeRef(_1);

    // 	    target_val[MAX] += 1
    DeRef(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    _7534 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7534);
    _0 = _7534;
    if (IS_ATOM_INT(_7534)) {
        _7534 = _7534 + 1;
        if (_7534 > MAXINT)
            _7534 = NewDouble((double)_7534);
    }
    else
        _7534 = binary_op(PLUS, 1, _7534);
    DeRef(_0);
    Ref(_7534);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _7534;
    DeRef(_1);

    // 	    ov = FALSE
    _18ov = 0;
    goto L8;
L6:

    // 	    c_stmt("@ = @ + 1;\n", {Code[pc+3], Code[pc+1]})
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    DeRef(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    _0 = _7566;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7534;
    Ref(_7534);
    ((int *)_2)[2] = _7566;
    Ref(_7566);
    _7566 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7580);
    RefDS(_7566);
    _16c_stmt(_7580, _7566);

    // 	    if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRefDS(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    Ref(_7566);
    _0 = _7566;
    _7566 = _16TypeIs(_7566, 1);
    DeRef(_0);
    if (_7566 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_7566) && DBL_PTR(_7566)->dbl == 0.0)
            goto L9;
    }

    // 		if target_val[MAX] < MAXINT then
    DeRef(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    _7566 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7566);
    if (binary_op_a(GREATEREQ, _7566, 1073741823))
        goto LA;

    // 		    target_val[MIN] += 1
    DeRef(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    _7566 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7566);
    _0 = _7566;
    if (IS_ATOM_INT(_7566)) {
        _7566 = _7566 + 1;
        if (_7566 > MAXINT)
            _7566 = NewDouble((double)_7566);
    }
    else
        _7566 = binary_op(PLUS, 1, _7566);
    DeRef(_0);
    Ref(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7566;
    DeRef(_1);

    // 		    target_val[MAX] += 1
    DeRef(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    _7566 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7566);
    _0 = _7566;
    if (IS_ATOM_INT(_7566)) {
        _7566 = _7566 + 1;
        if (_7566 > MAXINT)
            _7566 = NewDouble((double)_7566);
    }
    else
        _7566 = binary_op(PLUS, 1, _7566);
    DeRef(_0);
    Ref(_7566);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _7566;
    DeRef(_1);

    // 		    ov = FALSE
    _18ov = 0;
    goto LB;
LA:

    // 		    target_val = novalue
    RefDS(_9novalue);
    DeRef(_18target_val);
    _18target_val = _9novalue;
LB:
L9:

    // 	    if SymTab[Code[pc+3]][S_GTYPE] = TYPE_INTEGER or 
    DeRef(_7566);
    _7566 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    _0 = _7566;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_7566))
        _7566 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7566)->dbl));
    else
        _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    RefDS(_7566);
    DeRef(_0);
    _0 = _7566;
    _2 = (int)SEQ_PTR(_7566);
    _7566 = (int)*(((s1_ptr)_2)->base + 26);
    Ref(_7566);
    DeRefDS(_0);
    _0 = _7566;
    if (IS_ATOM_INT(_7566)) {
        _7566 = (_7566 == 1);
    }
    else {
        _7566 = binary_op(EQUALS, _7566, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7566)) {
        if (_7566 != 0) {
            DeRef(_7566);
            _7566 = 1;
            goto LC;
        }
    }
    else {
        if (DBL_PTR(_7566)->dbl != 0.0) {
            DeRef(_7566);
            _7566 = 1;
            goto LC;
        }
    }
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    _0 = _7534;
    _7534 = _18IntegerSize(_18np, _7534);
    DeRef(_0);
    DeRef(_7566);
    if (IS_ATOM_INT(_7534))
        _7566 = (_7534 != 0);
    else
        _7566 = DBL_PTR(_7534)->dbl != 0.0;
LC:
    if (_7566 != 0) {
        goto LD;
    }
    DeRef(_7566);
    _7566 = (_18ov == 0);
LE:
    if (_7566 == 0)
        goto LF;
LD:

    // 		if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    Ref(_7566);
    _0 = _7566;
    _7566 = _16TypeIs(_7566, 1);
    DeRef(_0);
    if (_7566 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_7566) && DBL_PTR(_7566)->dbl == 0.0)
            goto L10;
    }

    // 		    target_type = TYPE_INTEGER
    _18target_type = 1;
L11:
    goto L10;
LF:

    // 		SetBBType(Code[pc+3], GType(Code[pc+3]), target_val, 
    DeRef(_7566);
    _7566 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    Ref(_7534);
    _0 = _7534;
    _7534 = _16GType(_7534);
    DeRef(_0);
    Ref(_7566);
    RefDS(_18target_val);
    _16SetBBType(_7566, _7534, _18target_val, 16);

    // 		c_stmt("if (@ > MAXINT)\n", Code[pc+3])
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    RefDS(_7614);
    Ref(_7534);
    _16c_stmt(_7614, _7534);

    // 		c_stmt("@ = NewDouble((double)@);\n", {Code[pc+3], Code[pc+3]})
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    DeRef(_7566);
    _7566 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    _0 = _7566;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7534;
    Ref(_7534);
    ((int *)_2)[2] = _7566;
    Ref(_7566);
    _7566 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7617);
    RefDS(_7566);
    _16c_stmt(_7617, _7566);
L10:
L8:
L3:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    Ref(_7566);
    RefDS(_5781);
    _0 = _7566;
    _7566 = _16TypeIs(_7566, _5781);
    DeRef(_0);
    if (_7566 == 0) {
        goto L12;
    }
    else {
        if (!IS_ATOM_INT(_7566) && DBL_PTR(_7566)->dbl == 0.0)
            goto L12;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L12:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then    
    DeRef(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    Ref(_7566);
    _0 = _7566;
    _7566 = _16TypeIsNot(_7566, 1);
    DeRef(_0);
    if (_7566 == 0) {
        goto L13;
    }
    else {
        if (!IS_ATOM_INT(_7566) && DBL_PTR(_7566)->dbl == 0.0)
            goto L13;
    }

    // 	if Code[pc] = PLUS1 then
    DeRef(_7566);
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7566);
    if (binary_op_a(NOTEQ, _7566, 93))
        goto L14;

    // 	    c_stmt("@ = binary_op(PLUS, 1, @);\n", {Code[pc+3], Code[pc+1]})
    DeRef(_7566);
    _7566 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    DeRef(_7534);
    _7534 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    _0 = _7534;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7566;
    Ref(_7566);
    ((int *)_2)[2] = _7534;
    Ref(_7534);
    _7534 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7631);
    RefDS(_7534);
    _16c_stmt(_7631, _7534);
    goto L15;
L14:

    // 	    c_stmt("@ = 1+(long)(DBL_PTR(@)->dbl);\n", {Code[pc+3], Code[pc+1]})
    DeRef(_7534);
    _7534 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7534 = (int)*(((s1_ptr)_2)->base + _7534);
    Ref(_7534);
    DeRef(_7566);
    _7566 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    _0 = _7566;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7534;
    Ref(_7534);
    ((int *)_2)[2] = _7566;
    Ref(_7566);
    _7566 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7637);
    RefDS(_7566);
    _16c_stmt(_7637, _7566);
L15:
L13:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], target_type, target_val, target_elem)
    DeRef(_7566);
    _7566 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7566 = (int)*(((s1_ptr)_2)->base + _7566);
    Ref(_7566);
    Ref(_7566);
    RefDS(_18target_val);
    _16SetBBType(_7566, _18target_type, _18target_val, 16);

    //     pc = np
    _18pc = _18np;

    // end procedure
    DeRef(_7566);
    DeRef(_7534);
    DeRef(_7532);
    return 0;
    ;
}


int _18opRETURNT()
{
    int _7645;
    int _0, _1, _2;
    

    //     if cfile_size > MAX_CFILE_SIZE then
    if (_4cfile_size <= 2500)
        goto L1;

    // 	c_stmt0("main")
    RefDS(_7646);
    _16c_stmt0(_7646);

    // 	c_printf("%d();\n", main_name_num)
    RefDS(_7647);
    _9c_printf(_7647, _9main_name_num);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	main_name = sprintf("main-%d", main_name_num)
    DeRefi(_18main_name);
    _18main_name = EPrintf(-9999999, _5094, _9main_name_num);

    // 	new_c_file(main_name)
    RefDS(_18main_name);
    _16new_c_file(_18main_name);

    // 	c_stmt0("main")
    RefDS(_7646);
    _16c_stmt0(_7646);

    // 	c_printf("%d()\n", main_name_num)
    RefDS(_7649);
    _9c_printf(_7649, _9main_name_num);

    // 	c_stmt0("{\n")
    RefDS(_5169);
    _16c_stmt0(_5169);

    // 	main_temps()
    _18main_temps();

    // 	c_stmt0("\n")
    RefDS(_629);
    _16c_stmt0(_629);

    // 	main_name_num += 1
    _9main_name_num = _9main_name_num + 1;
L1:

    //     pc += 1
    _18pc = _18pc + 1;

    //     if pc > length(Code) then
    _7645 = SEQ_PTR(_4Code)->length;
    if (_18pc <= _7645)
        goto L2;

    // 	all_done = TRUE
    _18all_done = 1;
L2:

    // end procedure
    return 0;
    ;
}


int _18opGLOBAL_INIT_CHECK()
{
    int _0, _1, _2;
    

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    return 0;
    ;
}


int _18opLHS_SUBS()
{
    int _7656 = 0;
    int _7655 = 0;
    int _0, _1, _2, _3;
    

    //     SymTab[CurrentSub][S_LHS_SUBS2] = TRUE -- need to declare _3
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_4CurrentSub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 34);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     if opcode = LHS_SUBS then
    if (_18opcode != 95)
        goto L1;

    // 	c_stmt0("_2 = (int)SEQ_PTR(*(object_ptr)_3);\n")
    RefDS(_7658);
    _16c_stmt0(_7658);
    goto L2;
L1:

    //     elsif opcode = LHS_SUBS1 then
    if (_18opcode != 163)
        goto L3;

    // 	c_stmt("_2 = (int)SEQ_PTR(@);\n", Code[pc+1])
    DeRef(_7656);
    _7656 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7036);
    Ref(_7656);
    _16c_stmt(_7036, _7656);
    goto L2;
L3:

    // 	c_stmt("DeRef(@);\n", Code[pc+4])
    DeRef(_7656);
    _7656 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_6105);
    Ref(_7656);
    _16c_stmt(_6105, _7656);

    // 	c_stmt("@ = @;\n", {Code[pc+4], Code[pc+1]})
    DeRef(_7656);
    _7656 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    DeRef(_7655);
    _7655 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7655 = (int)*(((s1_ptr)_2)->base + _7655);
    Ref(_7655);
    _0 = _7655;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7656;
    Ref(_7656);
    ((int *)_2)[2] = _7655;
    Ref(_7655);
    _7655 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7362);
    RefDS(_7655);
    _16c_stmt(_7362, _7655);

    // 	c_stmt("Ref(@);\n", Code[pc+4])
    DeRefDS(_7655);
    _7655 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7655 = (int)*(((s1_ptr)_2)->base + _7655);
    Ref(_7655);
    RefDS(_7063);
    Ref(_7655);
    _16c_stmt(_7063, _7655);

    // 	c_stmt("_2 = (int)SEQ_PTR(@);\n", Code[pc+4])
    DeRef(_7655);
    _7655 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7655 = (int)*(((s1_ptr)_2)->base + _7655);
    Ref(_7655);
    RefDS(_7036);
    Ref(_7655);
    _16c_stmt(_7036, _7655);

    // 	target[MIN] = SeqLen(Code[pc+1])
    DeRef(_7655);
    _7655 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7655 = (int)*(((s1_ptr)_2)->base + _7655);
    Ref(_7655);
    Ref(_7655);
    _0 = _7655;
    _7655 = _18SeqLen(_7655);
    DeRef(_0);
    Ref(_7655);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7655;
    DeRef(_1);

    // 	SetBBType(Code[pc+4], TYPE_SEQUENCE, target, SeqElem(Code[pc+1]))               
    DeRef(_7655);
    _7655 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7655 = (int)*(((s1_ptr)_2)->base + _7655);
    Ref(_7655);
    DeRef(_7656);
    _7656 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    Ref(_7656);
    _0 = _7656;
    _7656 = _18SeqElem(_7656);
    DeRef(_0);
    Ref(_7655);
    RefDS(_18target);
    _16SetBBType(_7655, 8, _18target, _7656);
L2:

    //     c_stmt0("if (!UNIQUE(_2)) {\n")
    RefDS(_7222);
    _16c_stmt0(_7222);

    //     c_stmt0("_2 = (int)SequenceCopy((s1_ptr)_2);\n")
    RefDS(_7223);
    _16c_stmt0(_7223);

    //     if opcode = LHS_SUBS then
    if (_18opcode != 95)
        goto L4;

    // 	c_stmt0("*(object_ptr)_3 = MAKE_SEQ(_2);\n")
    RefDS(_7682);
    _16c_stmt0(_7682);
    goto L5;
L4:

    //     elsif opcode = LHS_SUBS1 then
    if (_18opcode != 163)
        goto L6;

    // 	c_stmt("@ = MAKE_SEQ(_2);\n", Code[pc+1])
    DeRef(_7656);
    _7656 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7232);
    Ref(_7656);
    _16c_stmt(_7232, _7656);
    goto L5;
L6:

    // 	c_stmt("@ = MAKE_SEQ(_2);\n", Code[pc+4])
    DeRef(_7656);
    _7656 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7232);
    Ref(_7656);
    _16c_stmt(_7232, _7656);
L5:

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     if TypeIsNot(Code[pc+2], TYPE_INTEGER) then
    DeRef(_7656);
    _7656 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    Ref(_7656);
    _0 = _7656;
    _7656 = _16TypeIsNot(_7656, 1);
    DeRef(_0);
    if (_7656 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_7656) && DBL_PTR(_7656)->dbl == 0.0)
            goto L7;
    }

    // 	c_stmt("if (!IS_ATOM_INT(@))\n", Code[pc+2])
    DeRef(_7656);
    _7656 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7046);
    Ref(_7656);
    _16c_stmt(_7046, _7656);

    // 	c_stmt("_3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(@)->dbl));\n", 
    DeRef(_7656);
    _7656 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7693);
    Ref(_7656);
    _16c_stmt(_7693, _7656);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L7:

    //     c_stmt("_3 = (int)(@ + ((s1_ptr)_2)->base);\n", Code[pc+2])
    DeRef(_7656);
    _7656 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7656 = (int)*(((s1_ptr)_2)->base + _7656);
    Ref(_7656);
    RefDS(_7696);
    Ref(_7656);
    _16c_stmt(_7696, _7656);

    //     target[MIN] = -1
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_7656);
    DeRef(_7655);
    return 0;
    ;
}


int _18opASSIGN_OP_SLICE()
{
    int _7721 = 0;
    int _7701 = 0;
    int _7708 = 0;
    int _0, _1, _2;
    

    //     c_stmt("rhs_slice_target = (object_ptr)&@;\n", Code[pc+4])
    _7701 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7701 = (int)*(((s1_ptr)_2)->base + _7701);
    Ref(_7701);
    RefDS(_7700);
    Ref(_7701);
    _16c_stmt(_7700, _7701);

    //     if opcode = PASSIGN_OP_SLICE then
    if (_18opcode != 167)
        goto L1;

    // 	c_stmt0("assign_slice_seq = (s1_ptr *)_3;\n")
    RefDS(_7704);
    _16c_stmt0(_7704);

    // 	c_stmt("RHS_Slice((s1_ptr)*(int *)_3, @, @);\n", 
    DeRef(_7701);
    _7701 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7701 = (int)*(((s1_ptr)_2)->base + _7701);
    Ref(_7701);
    _7708 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7708 = (int)*(((s1_ptr)_2)->base + _7708);
    Ref(_7708);
    _0 = _7708;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7701;
    Ref(_7701);
    ((int *)_2)[2] = _7708;
    Ref(_7708);
    _7708 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7705);
    RefDS(_7708);
    _16c_stmt(_7705, _7708);
    goto L2;
L1:

    // 	c_stmt("assign_slice_seq = (s1_ptr *)&@;\n", Code[pc+1])
    DeRef(_7708);
    _7708 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7708 = (int)*(((s1_ptr)_2)->base + _7708);
    Ref(_7708);
    RefDS(_7711);
    Ref(_7708);
    _16c_stmt(_7711, _7708);

    // 	target[MIN] = -1
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	SetBBType(Code[pc+1], TYPE_SEQUENCE, target, TYPE_OBJECT) 
    DeRef(_7708);
    _7708 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7708 = (int)*(((s1_ptr)_2)->base + _7708);
    Ref(_7708);
    Ref(_7708);
    RefDS(_18target);
    _16SetBBType(_7708, 8, _18target, 16);

    // 	c_stmt("RHS_Slice((s1_ptr)@, @, @);\n", 
    DeRef(_7708);
    _7708 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7708 = (int)*(((s1_ptr)_2)->base + _7708);
    Ref(_7708);
    DeRef(_7701);
    _7701 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7701 = (int)*(((s1_ptr)_2)->base + _7701);
    Ref(_7701);
    DeRef(_7721);
    _7721 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7721 = (int)*(((s1_ptr)_2)->base + _7721);
    Ref(_7721);
    _0 = _7721;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_7708);
    *((int *)(_2+4)) = _7708;
    Ref(_7701);
    *((int *)(_2+8)) = _7701;
    Ref(_7721);
    *((int *)(_2+12)) = _7721;
    _7721 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7716);
    RefDS(_7721);
    _16c_stmt(_7716, _7721);
L2:

    //     SetBBType(Code[pc+4], TYPE_SEQUENCE, novalue, TYPE_OBJECT) 
    DeRef(_7721);
    _7721 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7721 = (int)*(((s1_ptr)_2)->base + _7721);
    Ref(_7721);
    Ref(_7721);
    RefDS(_9novalue);
    _16SetBBType(_7721, 8, _9novalue, 16);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_7721);
    DeRef(_7701);
    DeRef(_7708);
    return 0;
    ;
}


int _18opASSIGN_SLICE()
{
    int _7743 = 0;
    int _7729 = 0;
    int _7727 = 0;
    int _0, _1, _2;
    

    //     if previous_previous_op = ASSIGN_OP_SLICE or 
    _7727 = (_18previous_previous_op == 152);
    if (_7727 != 0) {
        goto L1;
    }
    _7729 = (_18previous_previous_op == 167);
L2:
    if (_7729 == 0)
        goto L3;
L4:
    goto L1;
L3:

    //     elsif opcode = PASSIGN_SLICE then
    if (_18opcode != 165)
        goto L5;

    // 	c_stmt0("assign_slice_seq = (s1_ptr *)_3;\n")
    RefDS(_7704);
    _16c_stmt0(_7704);
    goto L1;
L5:

    // 	c_stmt("assign_slice_seq = (s1_ptr *)&@;\n", Code[pc+1])
    DeRef(_7729);
    _7729 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7729 = (int)*(((s1_ptr)_2)->base + _7729);
    Ref(_7729);
    RefDS(_7711);
    Ref(_7729);
    _16c_stmt(_7711, _7729);

    // 	target[MIN] = -1
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = -1;
    DeRef(_1);

    // 	SetBBType(Code[pc+1], TYPE_SEQUENCE, target, GType(Code[pc+4])) 
    DeRef(_7729);
    _7729 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7729 = (int)*(((s1_ptr)_2)->base + _7729);
    Ref(_7729);
    DeRef(_7727);
    _7727 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7727 = (int)*(((s1_ptr)_2)->base + _7727);
    Ref(_7727);
    Ref(_7727);
    _0 = _7727;
    _7727 = _16GType(_7727);
    DeRef(_0);
    Ref(_7729);
    RefDS(_18target);
    _16SetBBType(_7729, 8, _18target, _7727);
L1:

    //     c_stmt("AssignSlice(@, @, @);\n", {Code[pc+2], Code[pc+3], Code[pc+4]})
    DeRef(_7727);
    _7727 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7727 = (int)*(((s1_ptr)_2)->base + _7727);
    Ref(_7727);
    DeRef(_7729);
    _7729 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7729 = (int)*(((s1_ptr)_2)->base + _7729);
    Ref(_7729);
    DeRef(_7743);
    _7743 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7743 = (int)*(((s1_ptr)_2)->base + _7743);
    Ref(_7743);
    _0 = _7743;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_7727);
    *((int *)(_2+4)) = _7727;
    Ref(_7729);
    *((int *)(_2+8)) = _7729;
    Ref(_7743);
    *((int *)(_2+12)) = _7743;
    _7743 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7738);
    RefDS(_7743);
    _16c_stmt(_7738, _7743);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRefDS(_7743);
    DeRef(_7729);
    DeRef(_7727);
    return 0;
    ;
}


int _18opRHS_SLICE()
{
    int _left_val = 0;
    int _right_val = 0;
    int _t;
    int _preserve;
    int _7753 = 0;
    int _7747 = 0;
    int _7751 = 0;
    int _0, _1, _2, _3;
    

    //     t = Code[pc+4]
    _7747 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _t = (int)*(((s1_ptr)_2)->base + _7747);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     c_stmt("rhs_slice_target = (object_ptr)&@;\n", t)
    RefDS(_7700);
    _16c_stmt(_7700, _t);

    //     c_stmt("RHS_Slice((s1_ptr)@, @, @);\n", {Code[pc+1], Code[pc+2], Code[pc+3]})
    _7747 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7747 = (int)*(((s1_ptr)_2)->base + _7747);
    Ref(_7747);
    _7751 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7751 = (int)*(((s1_ptr)_2)->base + _7751);
    Ref(_7751);
    _7753 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7753 = (int)*(((s1_ptr)_2)->base + _7753);
    Ref(_7753);
    _0 = _7753;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_7747);
    *((int *)(_2+4)) = _7747;
    Ref(_7751);
    *((int *)(_2+8)) = _7751;
    Ref(_7753);
    *((int *)(_2+12)) = _7753;
    _7753 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7716);
    RefDS(_7753);
    _16c_stmt(_7716, _7753);

    //     target = {NOVALUE, 0}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = 0;
    _18target = MAKE_SEQ(_1);

    //     left_val = ObjMinMax(Code[pc+2])
    DeRefDS(_7753);
    _7753 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7753 = (int)*(((s1_ptr)_2)->base + _7753);
    Ref(_7753);
    Ref(_7753);
    _left_val = _18ObjMinMax(_7753);

    //     right_val = ObjMinMax(Code[pc+3])
    DeRef(_7753);
    _7753 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7753 = (int)*(((s1_ptr)_2)->base + _7753);
    Ref(_7753);
    Ref(_7753);
    _right_val = _18ObjMinMax(_7753);

    //     if left_val[MIN] = left_val[MAX] and right_val[MIN] = right_val[MAX] and
    DeRef(_7753);
    _2 = (int)SEQ_PTR(_left_val);
    _7753 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7753);
    DeRef(_7751);
    _2 = (int)SEQ_PTR(_left_val);
    _7751 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7751);
    _0 = _7751;
    if (IS_ATOM_INT(_7753) && IS_ATOM_INT(_7751)) {
        _7751 = (_7753 == _7751);
    }
    else {
        _7751 = binary_op(EQUALS, _7753, _7751);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7751)) {
        if (_7751 == 0) {
            DeRef(_7751);
            _7751 = 0;
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_7751)->dbl == 0.0) {
            DeRef(_7751);
            _7751 = 0;
            goto L1;
        }
    }
    DeRef(_7753);
    _2 = (int)SEQ_PTR(_right_val);
    _7753 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7753);
    DeRef(_7747);
    _2 = (int)SEQ_PTR(_right_val);
    _7747 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_7747);
    _0 = _7747;
    if (IS_ATOM_INT(_7753) && IS_ATOM_INT(_7747)) {
        _7747 = (_7753 == _7747);
    }
    else {
        _7747 = binary_op(EQUALS, _7753, _7747);
    }
    DeRef(_0);
    DeRef(_7751);
    if (IS_ATOM_INT(_7747))
        _7751 = (_7747 != 0);
    else
        _7751 = DBL_PTR(_7747)->dbl != 0.0;
L1:
    if (_7751 == 0) {
        DeRef(_7747);
        _7747 = 0;
        goto L2;
    }
    DeRef(_7753);
    _2 = (int)SEQ_PTR(_left_val);
    _7753 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7753);
    _0 = _7753;
    _7753 = binary_op(NOTEQ, _7753, _4NOVALUE);
    DeRef(_0);
    if (IS_ATOM_INT(_7753))
        _7747 = (_7753 != 0);
    else
        _7747 = DBL_PTR(_7753)->dbl != 0.0;
L2:
    if (_7747 == 0) {
        goto L3;
    }
    DeRef(_7747);
    _2 = (int)SEQ_PTR(_right_val);
    _7747 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7747);
    _0 = _7747;
    _7747 = binary_op(NOTEQ, _7747, _4NOVALUE);
    DeRef(_0);
L4:
    if (_7747 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7747) && DBL_PTR(_7747)->dbl == 0.0)
            goto L3;
    }

    // 	target[MIN] = right_val[MIN] - left_val[MIN] + 1
    DeRef(_7747);
    _2 = (int)SEQ_PTR(_right_val);
    _7747 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7747);
    DeRef(_7753);
    _2 = (int)SEQ_PTR(_left_val);
    _7753 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_7753);
    _0 = _7753;
    if (IS_ATOM_INT(_7747) && IS_ATOM_INT(_7753)) {
        _7753 = _7747 - _7753;
        if ((long)((unsigned long)_7753 +(unsigned long) HIGH_BITS) >= 0)
            _7753 = NewDouble((double)_7753);
    }
    else {
        _7753 = binary_op(MINUS, _7747, _7753);
    }
    DeRef(_0);
    _0 = _7753;
    if (IS_ATOM_INT(_7753)) {
        _7753 = _7753 + 1;
        if (_7753 > MAXINT)
            _7753 = NewDouble((double)_7753);
    }
    else
        _7753 = binary_op(PLUS, 1, _7753);
    DeRef(_0);
    Ref(_7753);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7753;
    DeRef(_1);
L3:

    //     if t = Code[pc+1] and SymTab[t][S_MODE] = M_NORMAL then
    DeRef(_7753);
    _7753 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7753 = (int)*(((s1_ptr)_2)->base + _7753);
    Ref(_7753);
    _0 = _7753;
    if (IS_ATOM_INT(_7753)) {
        _7753 = (_t == _7753);
    }
    else {
        _7753 = binary_op(EQUALS, _t, _7753);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7753)) {
        if (_7753 == 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_7753)->dbl == 0.0) {
            goto L5;
        }
    }
    DeRef(_7747);
    _2 = (int)SEQ_PTR(_4SymTab);
    _7747 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_7747);
    _0 = _7747;
    _2 = (int)SEQ_PTR(_7747);
    _7747 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_7747);
    DeRefDS(_0);
    _0 = _7747;
    if (IS_ATOM_INT(_7747)) {
        _7747 = (_7747 == 1);
    }
    else {
        _7747 = binary_op(EQUALS, _7747, 1);
    }
    DeRef(_0);
L6:
    if (_7747 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_7747) && DBL_PTR(_7747)->dbl == 0.0)
            goto L5;
    }

    // 	preserve = SymTab[t][S_SEQ_ELEM_NEW]
    DeRef(_7747);
    _2 = (int)SEQ_PTR(_4SymTab);
    _7747 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_7747);
    _2 = (int)SEQ_PTR(_7747);
    _preserve = (int)*(((s1_ptr)_2)->base + 37);
    if (!IS_ATOM_INT(_preserve))
        _preserve = (long)DBL_PTR(_preserve)->dbl;

    // 	SetBBType(t, TYPE_SEQUENCE, target, SeqElem(Code[pc+1])) 
    DeRefDS(_7747);
    _7747 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7747 = (int)*(((s1_ptr)_2)->base + _7747);
    Ref(_7747);
    Ref(_7747);
    _0 = _7747;
    _7747 = _18SeqElem(_7747);
    DeRef(_0);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _7747);

    // 	SymTab[t][S_SEQ_ELEM_NEW] = preserve
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
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _preserve;
    DeRef(_1);
    goto L7;
L5:

    // 	SetBBType(t, TYPE_SEQUENCE, target, SeqElem(Code[pc+1])) 
    DeRef(_7753);
    _7753 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7753 = (int)*(((s1_ptr)_2)->base + _7753);
    Ref(_7753);
    Ref(_7753);
    _0 = _7753;
    _7753 = _18SeqElem(_7753);
    DeRef(_0);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _7753);
L7:

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_left_val);
    DeRef(_right_val);
    DeRef(_7753);
    DeRef(_7747);
    DeRef(_7751);
    return 0;
    ;
}


int _18opTYPE_CHECK()
{
    int _7814 = 0;
    int _7798 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc-1], TYPE_INTEGER) then
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    Ref(_7798);
    _0 = _7798;
    _7798 = _16TypeIs(_7798, 1);
    DeRef(_0);
    if (_7798 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7798) && DBL_PTR(_7798)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (@ == 0)\n", Code[pc-1])
    DeRef(_7798);
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    RefDS(_7180);
    Ref(_7798);
    _16c_stmt(_7180, _7798);

    // 	c_stmt0("RTFatal(\"user-defined type_check failure\");\n")
    RefDS(_7803);
    _16c_stmt0(_7803);
    goto L2;
L1:

    // 	c_stmt("if (@ != 1) {\n", Code[pc-1])
    DeRef(_7798);
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    RefDS(_7804);
    Ref(_7798);
    _16c_stmt(_7804, _7798);

    // 	c_stmt("if (@ == 0)\n", Code[pc-1])
    DeRef(_7798);
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    RefDS(_7180);
    Ref(_7798);
    _16c_stmt(_7180, _7798);

    // 	c_stmt0("RTFatal(\"user-defined type_check failure\");\n")
    RefDS(_7803);
    _16c_stmt0(_7803);

    // 	c_stmt("if (!IS_ATOM_INT(@)) {\n", Code[pc-1])
    DeRef(_7798);
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    RefDS(_7192);
    Ref(_7798);
    _16c_stmt(_7192, _7798);

    // 	c_stmt("if (!(IS_ATOM_DBL(@) && DBL_PTR(@)->dbl != 0.0))\n", 
    DeRef(_7798);
    _7798 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7798 = (int)*(((s1_ptr)_2)->base + _7798);
    Ref(_7798);
    DeRef(_7814);
    _7814 = _18pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7814 = (int)*(((s1_ptr)_2)->base + _7814);
    Ref(_7814);
    _0 = _7814;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7798;
    Ref(_7798);
    ((int *)_2)[2] = _7814;
    Ref(_7814);
    _7814 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7811);
    RefDS(_7814);
    _16c_stmt(_7811, _7814);

    // 	c_stmt0("RTFatal(\"user-defined type_check failure\");\n")
    RefDS(_7803);
    _16c_stmt0(_7803);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L2:

    //     pc += 1
    _18pc = _18pc + 1;

    // end procedure
    DeRef(_7814);
    DeRef(_7798);
    return 0;
    ;
}


int _18opIS_AN_INTEGER()
{
    int _7820 = 0;
    int _7818 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _7818 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    _7820 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    RefDS(_5774);
    Ref(_7818);
    Ref(_7820);
    _18CSaveStr(_5774, _7818, _7820, 0, 0);

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_7820);
    _7820 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    Ref(_7820);
    _0 = _7820;
    _7820 = _16TypeIs(_7820, 1);
    DeRef(_0);
    if (_7820 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7820) && DBL_PTR(_7820)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_7820);
    _7820 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    RefDS(_7825);
    Ref(_7820);
    _16c_stmt(_7825, _7820);
    goto L2;
L1:

    //     elsif TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRef(_7820);
    _7820 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    Ref(_7820);
    _0 = _7820;
    _7820 = _16TypeIs(_7820, 8);
    DeRef(_0);
    if (_7820 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7820) && DBL_PTR(_7820)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt("@ = 0;\n", Code[pc+2])
    DeRef(_7820);
    _7820 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    RefDS(_7831);
    Ref(_7820);
    _16c_stmt(_7831, _7820);
    goto L2;
L3:

    //     elsif TypeIs(Code[pc+1], TYPE_DOUBLE) then
    DeRef(_7820);
    _7820 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    Ref(_7820);
    _0 = _7820;
    _7820 = _16TypeIs(_7820, 2);
    DeRef(_0);
    if (_7820 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_7820) && DBL_PTR(_7820)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt("@ = IS_ATOM_INT(DoubleToInt(@));\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7820);
    _7820 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    DeRef(_7818);
    _7818 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    _0 = _7818;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7820;
    Ref(_7820);
    ((int *)_2)[2] = _7818;
    Ref(_7818);
    _7818 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7837);
    RefDS(_7818);
    _16c_stmt(_7837, _7818);
    goto L2;
L4:

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_7818);
    _7818 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    RefDS(_5783);
    Ref(_7818);
    _16c_stmt(_5783, _7818);

    // 	c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_7818);
    _7818 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    RefDS(_7825);
    Ref(_7818);
    _16c_stmt(_7825, _7818);

    // 	c_stmt("else if (IS_ATOM_DBL(@))\n", Code[pc+1])
    DeRef(_7818);
    _7818 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    RefDS(_7847);
    Ref(_7818);
    _16c_stmt(_7847, _7818);

    // 	c_stmt("@ = IS_ATOM_INT(DoubleToInt(@));\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7818);
    _7818 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7818 = (int)*(((s1_ptr)_2)->base + _7818);
    Ref(_7818);
    DeRef(_7820);
    _7820 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    _0 = _7820;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7818;
    Ref(_7818);
    ((int *)_2)[2] = _7820;
    Ref(_7820);
    _7820 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7837);
    RefDS(_7820);
    _16c_stmt(_7837, _7820);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	c_stmt("@ = 0;\n", Code[pc+2])
    DeRefDS(_7820);
    _7820 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    RefDS(_7831);
    Ref(_7820);
    _16c_stmt(_7831, _7820);
L2:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, 1}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_7820);
    _7820 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7820 = (int)*(((s1_ptr)_2)->base + _7820);
    Ref(_7820);
    Ref(_7820);
    RefDS(_18target);
    _16SetBBType(_7820, 1, _18target, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7820);
    DeRef(_7818);
    return 0;
    ;
}


int _18opIS_AN_ATOM()
{
    int _7861 = 0;
    int _7863 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _7861 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7861 = (int)*(((s1_ptr)_2)->base + _7861);
    Ref(_7861);
    _7863 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    RefDS(_5774);
    Ref(_7861);
    Ref(_7863);
    _18CSaveStr(_5774, _7861, _7863, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_DOUBLE}) then
    DeRef(_7863);
    _7863 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    Ref(_7863);
    RefDS(_7867);
    _0 = _7863;
    _7863 = _16TypeIs(_7863, _7867);
    DeRef(_0);
    if (_7863 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7863) && DBL_PTR(_7863)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_7863);
    _7863 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    RefDS(_7825);
    Ref(_7863);
    _16c_stmt(_7825, _7863);
    goto L2;
L1:

    //     elsif TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRef(_7863);
    _7863 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    Ref(_7863);
    _0 = _7863;
    _7863 = _16TypeIs(_7863, 8);
    DeRef(_0);
    if (_7863 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7863) && DBL_PTR(_7863)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt("@ = 0;\n", Code[pc+2])
    DeRef(_7863);
    _7863 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    RefDS(_7831);
    Ref(_7863);
    _16c_stmt(_7831, _7863);
    goto L2;
L3:

    // 	c_stmt("@ = IS_ATOM(@);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7863);
    _7863 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7863 = (int)*(((s1_ptr)_2)->base + _7863);
    Ref(_7863);
    DeRef(_7861);
    _7861 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7861 = (int)*(((s1_ptr)_2)->base + _7861);
    Ref(_7861);
    _0 = _7861;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7863;
    Ref(_7863);
    ((int *)_2)[2] = _7861;
    Ref(_7861);
    _7861 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7876);
    RefDS(_7861);
    _16c_stmt(_7876, _7861);
L2:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, 1}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_7861);
    _7861 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7861 = (int)*(((s1_ptr)_2)->base + _7861);
    Ref(_7861);
    Ref(_7861);
    RefDS(_18target);
    _16SetBBType(_7861, 1, _18target, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7861);
    DeRef(_7863);
    return 0;
    ;
}


int _18opIS_A_SEQUENCE()
{
    int _7886 = 0;
    int _7888 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _7886 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7886 = (int)*(((s1_ptr)_2)->base + _7886);
    Ref(_7886);
    _7888 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    RefDS(_5774);
    Ref(_7886);
    Ref(_7888);
    _18CSaveStr(_5774, _7886, _7888, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_DOUBLE}) then
    DeRef(_7888);
    _7888 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    Ref(_7888);
    RefDS(_7867);
    _0 = _7888;
    _7888 = _16TypeIs(_7888, _7867);
    DeRef(_0);
    if (_7888 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7888) && DBL_PTR(_7888)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("@ = 0;\n", Code[pc+2])
    DeRef(_7888);
    _7888 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    RefDS(_7831);
    Ref(_7888);
    _16c_stmt(_7831, _7888);
    goto L2;
L1:

    //     elsif TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRef(_7888);
    _7888 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    Ref(_7888);
    _0 = _7888;
    _7888 = _16TypeIs(_7888, 8);
    DeRef(_0);
    if (_7888 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7888) && DBL_PTR(_7888)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_7888);
    _7888 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    RefDS(_7825);
    Ref(_7888);
    _16c_stmt(_7825, _7888);
    goto L2;
L3:

    // 	c_stmt("@ = IS_SEQUENCE(@);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7888);
    _7888 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7888 = (int)*(((s1_ptr)_2)->base + _7888);
    Ref(_7888);
    DeRef(_7886);
    _7886 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7886 = (int)*(((s1_ptr)_2)->base + _7886);
    Ref(_7886);
    _0 = _7886;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7888;
    Ref(_7888);
    ((int *)_2)[2] = _7886;
    Ref(_7886);
    _7886 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7900);
    RefDS(_7886);
    _16c_stmt(_7900, _7886);
L2:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, 1}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_7886);
    _7886 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7886 = (int)*(((s1_ptr)_2)->base + _7886);
    Ref(_7886);
    Ref(_7886);
    RefDS(_18target);
    _16SetBBType(_7886, 1, _18target, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7886);
    DeRef(_7888);
    return 0;
    ;
}


int _18opIS_AN_OBJECT()
{
    int _7910 = 0;
    int _0, _1, _2;
    

    //     CDeRef(Code[pc+2])
    _7910 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7910 = (int)*(((s1_ptr)_2)->base + _7910);
    Ref(_7910);
    Ref(_7910);
    _18CDeRef(_7910);

    //     c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_7910);
    _7910 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7910 = (int)*(((s1_ptr)_2)->base + _7910);
    Ref(_7910);
    RefDS(_7825);
    Ref(_7910);
    _16c_stmt(_7825, _7910);

    //     target = {1, 1}
    RefDS(_7914);
    DeRef(_18target);
    _18target = _7914;

    //     SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_7910);
    _7910 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7910 = (int)*(((s1_ptr)_2)->base + _7910);
    Ref(_7910);
    Ref(_7910);
    RefDS(_18target);
    _16SetBBType(_7910, 1, _18target, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7910);
    return 0;
    ;
}


int _18opSQRT()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_sqrt", "SQRT")
    RefDS(_7918);
    RefDS(_5292);
    _18CUnaryOp(_18pc, _7918, _5292);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opSIN()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_sin", "SIN")
    RefDS(_7920);
    RefDS(_5331);
    _18CUnaryOp(_18pc, _7920, _5331);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opCOS()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_cos", "COS")
    RefDS(_7922);
    RefDS(_5332);
    _18CUnaryOp(_18pc, _7922, _5332);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opTAN()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_tan", "TAN")
    RefDS(_7924);
    RefDS(_5333);
    _18CUnaryOp(_18pc, _7924, _5333);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opARCTAN()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_arctan", "ARCTAN")
    RefDS(_7926);
    RefDS(_5324);
    _18CUnaryOp(_18pc, _7926, _5324);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opLOG()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_log", "LOG")
    RefDS(_7928);
    RefDS(_5325);
    _18CUnaryOp(_18pc, _7928, _5325);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opNOT_BITS()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "not_bits", "NOT_BITS")
    RefDS(_7930);
    RefDS(_5302);
    _18CUnaryOp(_18pc, _7930, _5302);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opFLOOR()
{
    int _0, _1, _2;
    

    //     CUnaryOp(pc, "e_floor", "FLOOR")
    RefDS(_7932);
    RefDS(_5334);
    _18CUnaryOp(_18pc, _7932, _5334);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    return 0;
    ;
}


int _18opNOT_IFW()
{
    int _7952 = 0;
    int _7951 = 0;
    int _7934 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    _7934 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7934 = (int)*(((s1_ptr)_2)->base + _7934);
    Ref(_7934);
    Ref(_7934);
    RefDS(_5781);
    _0 = _7934;
    _7934 = _16TypeIs(_7934, _5781);
    DeRef(_0);
    if (_7934 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7934) && DBL_PTR(_7934)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_7934);
    _7934 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7934 = (int)*(((s1_ptr)_2)->base + _7934);
    Ref(_7934);
    RefDS(_6192);
    Ref(_7934);
    _16c_stmt(_6192, _7934);
L1:

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_7934);
    _7934 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7934 = (int)*(((s1_ptr)_2)->base + _7934);
    Ref(_7934);
    Ref(_7934);
    _0 = _7934;
    _7934 = _16TypeIs(_7934, 1);
    DeRef(_0);
    if (_7934 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_7934) && DBL_PTR(_7934)->dbl == 0.0)
            goto L2;
    }

    // 	if ObjValue(Code[pc+1]) = 0 then
    DeRef(_7934);
    _7934 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7934 = (int)*(((s1_ptr)_2)->base + _7934);
    Ref(_7934);
    Ref(_7934);
    _0 = _7934;
    _7934 = _16ObjValue(_7934);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _7934, 0))
        goto L3;
    goto L4;
L3:

    // 	elsif ObjValue(Code[pc+1]) = NOVALUE or 
    DeRef(_7934);
    _7934 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7934 = (int)*(((s1_ptr)_2)->base + _7934);
    Ref(_7934);
    Ref(_7934);
    _0 = _7934;
    _7934 = _16ObjValue(_7934);
    DeRef(_0);
    _0 = _7934;
    _7934 = binary_op(EQUALS, _7934, _4NOVALUE);
    DeRef(_0);
    if (IS_ATOM_INT(_7934)) {
        if (_7934 != 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_7934)->dbl != 0.0) {
            goto L5;
        }
    }
    DeRef(_7951);
    _7951 = _18pc + 3;
    if ((long)((unsigned long)_7951 + (unsigned long)HIGH_BITS) >= 0) 
        _7951 = NewDouble((double)_7951);
    DeRef(_7952);
    _7952 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    _0 = _7952;
    if (IS_ATOM_INT(_7952)) {
        _7952 = _7952 - 1;
        if ((long)((unsigned long)_7952 +(unsigned long) HIGH_BITS) >= 0)
            _7952 = NewDouble((double)_7952);
    }
    else {
        _7952 = binary_op(MINUS, _7952, 1);
    }
    DeRef(_0);
    Ref(_7951);
    Ref(_7952);
    _0 = _7952;
    _7952 = _18forward_branch_into(_7951, _7952);
    DeRef(_0);
L6:
    if (_7952 == 0)
        goto L7;
L5:

    // 	    if ObjValue(Code[pc+1]) = NOVALUE then -- zero handled above
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    _0 = _7952;
    _7952 = _16ObjValue(_7952);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _7952, _4NOVALUE))
        goto L8;

    // 		c_stmt("if (@ != 0)\n", Code[pc+1])
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    RefDS(_7960);
    Ref(_7952);
    _16c_stmt(_7960, _7952);
L8:

    // 	    Goto(Code[pc+2])
    DeRef(_7952);
    _7952 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    _18Goto(_7952);
    goto L4;
L7:

    // 	    pc = Code[pc+2] -- known, non-zero value, skip whole block
    DeRef(_7952);
    _7952 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _18pc = (int)*(((s1_ptr)_2)->base + _7952);
    if (!IS_ATOM_INT(_18pc))
        _18pc = (long)DBL_PTR(_18pc)->dbl;

    // 	    return
    DeRef(_7951);
    DeRef(_7934);
    return 0;
L9:
    goto L4;
L2:

    //     elsif TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    RefDS(_5781);
    _0 = _7952;
    _7952 = _16TypeIs(_7952, _5781);
    DeRef(_0);
    if (_7952 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_7952) && DBL_PTR(_7952)->dbl == 0.0)
            goto LA;
    }

    // 	c_stmt("if (@ != 0)\n", Code[pc+1])
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    RefDS(_7960);
    Ref(_7952);
    _16c_stmt(_7960, _7952);

    // 	Goto(Code[pc+2])
    DeRef(_7952);
    _7952 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    _18Goto(_7952);
LA:
L4:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    RefDS(_5781);
    _0 = _7952;
    _7952 = _16TypeIs(_7952, _5781);
    DeRef(_0);
    if (_7952 == 0) {
        goto LB;
    }
    else {
        if (!IS_ATOM_INT(_7952) && DBL_PTR(_7952)->dbl == 0.0)
            goto LB;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
LB:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    _0 = _7952;
    _7952 = _16TypeIsNot(_7952, 1);
    DeRef(_0);
    if (_7952 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_7952) && DBL_PTR(_7952)->dbl == 0.0)
            goto LC;
    }

    // 	c_stmt("if (DBL_PTR(@)->dbl != 0.0)\n", Code[pc+1])
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    RefDS(_7980);
    Ref(_7952);
    _16c_stmt(_7980, _7952);

    // 	Goto(Code[pc+2])
    DeRef(_7952);
    _7952 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    _18Goto(_7952);
LC:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then 
    DeRef(_7952);
    _7952 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7952 = (int)*(((s1_ptr)_2)->base + _7952);
    Ref(_7952);
    Ref(_7952);
    RefDS(_5781);
    _0 = _7952;
    _7952 = _16TypeIs(_7952, _5781);
    DeRef(_0);
    if (_7952 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_7952) && DBL_PTR(_7952)->dbl == 0.0)
            goto LD;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
LD:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7952);
    DeRef(_7951);
    DeRef(_7934);
    return 0;
    ;
}


int _18opNOT()
{
    int _7991 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = unary_op(NOT, @);\n"
    RefDS(_7989);
    DeRefi(_18gencode);
    _18gencode = _7989;

    //     intcode = "@ = (@ == 0);\n"
    RefDS(_7990);
    DeRefi(_18intcode);
    _18intcode = _7990;

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    _7991 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7991 = (int)*(((s1_ptr)_2)->base + _7991);
    Ref(_7991);
    Ref(_7991);
    RefDS(_4094);
    _0 = _7991;
    _7991 = _16TypeIs(_7991, _4094);
    DeRef(_0);
    if (_7991 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7991) && DBL_PTR(_7991)->dbl == 0.0)
            goto L1;
    }

    // 	target_type = GType(Code[pc+1])
    DeRef(_7991);
    _7991 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7991 = (int)*(((s1_ptr)_2)->base + _7991);
    Ref(_7991);
    Ref(_7991);
    _0 = _16GType(_7991);
    _18target_type = _0;
    goto L2;
L1:

    // 	target_type = TYPE_INTEGER
    _18target_type = 1;
L2:

    //     pc = unary_optimize(pc, target_type, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18gencode);
    _0 = _18unary_optimize(_18pc, _18target_type, _18target_val, _18intcode, _18intcode2, _18gencode);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_7991);
    return 0;
    ;
}


