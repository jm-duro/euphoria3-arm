// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opSC2_OR()
{
    int _8393 = 0;
    int _8406 = 0;
    int _0, _1, _2;
    

    //     CDeRef(Code[pc+2])
    _8393 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    Ref(_8393);
    _18CDeRef(_8393);

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8393);
    _8393 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    Ref(_8393);
    RefDS(_5781);
    _0 = _8393;
    _8393 = _16TypeIs(_8393, _5781);
    DeRef(_0);
    if (_8393 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8393) && DBL_PTR(_8393)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_8393);
    _8393 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    RefDS(_5783);
    Ref(_8393);
    _16c_stmt(_5783, _8393);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8393);
    _8393 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    Ref(_8393);
    RefDS(_6197);
    _0 = _8393;
    _8393 = _16TypeIs(_8393, _6197);
    DeRef(_0);
    if (_8393 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_8393) && DBL_PTR(_8393)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("@ = (@ != 0);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_8393);
    _8393 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    DeRef(_8406);
    _8406 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8406 = (int)*(((s1_ptr)_2)->base + _8406);
    Ref(_8406);
    _0 = _8406;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8393;
    Ref(_8393);
    ((int *)_2)[2] = _8406;
    Ref(_8406);
    _8406 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8403);
    RefDS(_8406);
    _16c_stmt(_8403, _8406);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8406);
    _8406 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8406 = (int)*(((s1_ptr)_2)->base + _8406);
    Ref(_8406);
    Ref(_8406);
    RefDS(_5781);
    _0 = _8406;
    _8406 = _16TypeIs(_8406, _5781);
    DeRef(_0);
    if (_8406 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8406) && DBL_PTR(_8406)->dbl == 0.0)
            goto L3;
    }

    // 	c_stmt("else\n", Code[pc+1])
    DeRef(_8406);
    _8406 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8406 = (int)*(((s1_ptr)_2)->base + _8406);
    Ref(_8406);
    RefDS(_5799);
    Ref(_8406);
    _16c_stmt(_5799, _8406);
L3:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8406);
    _8406 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8406 = (int)*(((s1_ptr)_2)->base + _8406);
    Ref(_8406);
    Ref(_8406);
    _0 = _8406;
    _8406 = _16TypeIsNot(_8406, 1);
    DeRef(_0);
    if (_8406 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8406) && DBL_PTR(_8406)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt("@ = DBL_PTR(@)->dbl != 0.0;\n", {Code[pc+2], Code[pc+1]})
    DeRef(_8406);
    _8406 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8406 = (int)*(((s1_ptr)_2)->base + _8406);
    Ref(_8406);
    DeRef(_8393);
    _8393 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    _0 = _8393;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8406;
    Ref(_8406);
    ((int *)_2)[2] = _8393;
    Ref(_8393);
    _8393 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8417);
    RefDS(_8393);
    _16c_stmt(_8417, _8393);
L4:

    //     SetBBType(Code[pc+2], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_8393);
    _8393 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8393 = (int)*(((s1_ptr)_2)->base + _8393);
    Ref(_8393);
    Ref(_8393);
    RefDS(_9novalue);
    _16SetBBType(_8393, 1, _9novalue, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_8393);
    DeRef(_8406);
    return 0;
    ;
}


int _18opFOR()
{
    int _range1 = 0;
    int _range2 = 0;
    int _inc = 0;
    int _8507 = 0;
    int _8436 = 0;
    int _8501 = 0;
    int _8426 = 0;
    int _0, _1, _2, _3;
    

    //     in_loop = append(in_loop, Code[pc+5]) -- loop var
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    Append(&_18in_loop, _18in_loop, _8426);

    //     c_stmt("{ int @;\n", Code[pc+5])
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    RefDS(_8429);
    Ref(_8426);
    _16c_stmt(_8429, _8426);

    //     CRef(Code[pc+3])
    DeRef(_8426);
    _8426 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _18CRef(_8426);

    //     c_stmt("@ = @;\n", {Code[pc+5], Code[pc+3]})
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _8436 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8426;
    Ref(_8426);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7362);
    RefDS(_8436);
    _16c_stmt(_7362, _8436);

    //     Label(pc+7)
    DeRefDS(_8436);
    _8436 = _18pc + 7;
    if ((long)((unsigned long)_8436 + (unsigned long)HIGH_BITS) >= 0) 
        _8436 = NewDouble((double)_8436);
    Ref(_8436);
    _18Label(_8436);

    //     inc = ObjMinMax(Code[pc+1])
    DeRef(_8436);
    _8436 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _inc = _18ObjMinMax(_8436);

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) then 
    DeRef(_8436);
    _8436 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _0 = _8436;
    _8436 = _16TypeIs(_8436, 1);
    DeRef(_0);
    if (_8436 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8436) && DBL_PTR(_8436)->dbl == 0.0)
            goto L1;
    }

    // 	if TypeIs(Code[pc+3], TYPE_INTEGER) and
    DeRef(_8436);
    _8436 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _0 = _8436;
    _8436 = _16TypeIs(_8436, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8436)) {
        if (_8436 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_8436)->dbl == 0.0) {
            goto L2;
        }
    }
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _0 = _8426;
    _8426 = _16TypeIs(_8426, 1);
    DeRef(_0);
L3:
    if (_8426 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_8426) && DBL_PTR(_8426)->dbl == 0.0)
            goto L2;
    }

    // 	    range1 = ObjMinMax(Code[pc+3])  -- start
    DeRef(_8426);
    _8426 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _0 = _range1;
    _range1 = _18ObjMinMax(_8426);
    DeRef(_0);

    // 	    range2 = ObjMinMax(Code[pc+2])  -- limit
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _0 = _range2;
    _range2 = _18ObjMinMax(_8426);
    DeRef(_0);

    // 	    SymTab[Code[pc+5]][S_GTYPE] = TYPE_INTEGER    
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8426))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8426)->dbl));
    else
        _3 = (int)(_8426 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
    goto L4;
L2:

    // 	    range1 = {NOVALUE, NOVALUE}
    DeRef(_range1);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = _4NOVALUE;
    RefDS(_4NOVALUE);
    _range1 = MAKE_SEQ(_1);

    // 	    SymTab[Code[pc+5]][S_GTYPE] = TYPE_ATOM    
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8436))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8436)->dbl));
    else
        _3 = (int)(_8436 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 26);
    _1 = *(int *)_2;
    *(int *)_2 = 4;
    DeRef(_1);

    // 	    SymTab[Code[pc+5]][S_OBJ] = NOVALUE
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8426))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8426)->dbl));
    else
        _3 = (int)(_8426 + ((s1_ptr)_2)->base);
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
L4:

    // 	if inc[MIN] >= 0 then
    DeRef(_8436);
    _2 = (int)SEQ_PTR(_inc);
    _8436 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8436);
    if (binary_op_a(LESS, _8436, 0))
        goto L5;

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    if TypeIs(Code[pc+5], TYPE_INTEGER) and
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _0 = _8436;
    _8436 = _16TypeIs(_8436, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8436)) {
        if (_8436 == 0) {
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_8436)->dbl == 0.0) {
            goto L6;
        }
    }
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _0 = _8426;
    _8426 = _16TypeIs(_8426, 1);
    DeRef(_0);
L7:
    if (_8426 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_8426) && DBL_PTR(_8426)->dbl == 0.0)
            goto L6;
    }

    // 		c_stmt("if (@ > @)\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8426;
    Ref(_8426);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8481);
    RefDS(_8436);
    _16c_stmt(_8481, _8436);
    goto L8;
L6:

    // 		c_stmt("if (binary_op_a(GREATER, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _0 = _8426;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8436;
    Ref(_8436);
    ((int *)_2)[2] = _8426;
    Ref(_8426);
    _8426 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8487);
    RefDS(_8426);
    _16c_stmt(_8487, _8426);
L8:

    // 	    Goto(Code[pc+6])
    DeRef(_8426);
    _8426 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _18Goto(_8426);

    // 	    if range1[MIN] != NOVALUE then
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_range1);
    _8426 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8426);
    if (binary_op_a(EQUALS, _8426, _4NOVALUE))
        goto L9;

    // 		SymTab[Code[pc+5]][S_OBJ_MIN] = range1[MIN]
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8426))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8426)->dbl));
    else
        _3 = (int)(_8426 + ((s1_ptr)_2)->base);
    DeRef(_8501);
    _2 = (int)SEQ_PTR(_range1);
    _8501 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8501);
    Ref(_8501);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _8501;
    DeRef(_1);

    // 		SymTab[Code[pc+5]][S_OBJ_MAX] = max(range1[MAX], range2[MAX])  
    DeRef(_8501);
    _8501 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8501 = (int)*(((s1_ptr)_2)->base + _8501);
    Ref(_8501);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8501))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8501)->dbl));
    else
        _3 = (int)(_8501 + ((s1_ptr)_2)->base);
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_range1);
    _8426 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8426);
    DeRef(_8507);
    _2 = (int)SEQ_PTR(_range2);
    _8507 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8507);
    Ref(_8426);
    Ref(_8507);
    _0 = _8507;
    _8507 = _18max(_8426, _8507);
    DeRef(_0);
    Ref(_8507);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _8507;
    DeRef(_1);
LA:
    goto L9;
L5:

    // 	elsif inc[MAX] < 0 then
    DeRef(_8507);
    _2 = (int)SEQ_PTR(_inc);
    _8507 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8507);
    if (binary_op_a(GREATEREQ, _8507, 0))
        goto LB;

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    if TypeIs(Code[pc+5], TYPE_INTEGER) and
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _0 = _8507;
    _8507 = _16TypeIs(_8507, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8507)) {
        if (_8507 == 0) {
            goto LC;
        }
    }
    else {
        if (DBL_PTR(_8507)->dbl == 0.0) {
            goto LC;
        }
    }
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _0 = _8426;
    _8426 = _16TypeIs(_8426, 1);
    DeRef(_0);
LD:
    if (_8426 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_8426) && DBL_PTR(_8426)->dbl == 0.0)
            goto LC;
    }

    // 		c_stmt("if (@ < @)\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _0 = _8507;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8426;
    Ref(_8426);
    ((int *)_2)[2] = _8507;
    Ref(_8507);
    _8507 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8518);
    RefDS(_8507);
    _16c_stmt(_8518, _8507);
    goto LE;
LC:

    // 		c_stmt("if (binary_op_a(LESS, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    DeRef(_8426);
    _8426 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _0 = _8426;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8507;
    Ref(_8507);
    ((int *)_2)[2] = _8426;
    Ref(_8426);
    _8426 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8524);
    RefDS(_8426);
    _16c_stmt(_8524, _8426);
LE:

    // 	    Goto(Code[pc+6])
    DeRef(_8426);
    _8426 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    Ref(_8426);
    _18Goto(_8426);

    // 	    if range1[MIN] != NOVALUE then
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_range1);
    _8426 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8426);
    if (binary_op_a(EQUALS, _8426, _4NOVALUE))
        goto L9;

    // 		SymTab[Code[pc+5]][S_OBJ_MIN] = min(range1[MIN], range2[MIN])  
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8426))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8426)->dbl));
    else
        _3 = (int)(_8426 + ((s1_ptr)_2)->base);
    DeRef(_8436);
    _2 = (int)SEQ_PTR(_range1);
    _8436 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8436);
    DeRef(_8501);
    _2 = (int)SEQ_PTR(_range2);
    _8501 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8501);
    Ref(_8436);
    Ref(_8501);
    _0 = _8501;
    _8501 = _18min(_8436, _8501);
    DeRef(_0);
    Ref(_8501);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _8501;
    DeRef(_1);

    // 		SymTab[Code[pc+5]][S_OBJ_MAX] = range1[MAX]
    DeRef(_8501);
    _8501 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8501 = (int)*(((s1_ptr)_2)->base + _8501);
    Ref(_8501);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8501))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8501)->dbl));
    else
        _3 = (int)(_8501 + ((s1_ptr)_2)->base);
    DeRef(_8507);
    _2 = (int)SEQ_PTR(_range1);
    _8507 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8507);
    Ref(_8507);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _8507;
    DeRef(_1);
LF:
    goto L9;
LB:

    // 	    c_stmt("if (@ >= 0) {\n", Code[pc+1])
    DeRef(_8507);
    _8507 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    RefDS(_8546);
    Ref(_8507);
    _16c_stmt(_8546, _8507);

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    if TypeIs(Code[pc+5], TYPE_INTEGER) and
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _0 = _8507;
    _8507 = _16TypeIs(_8507, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8507)) {
        if (_8507 == 0) {
            goto L10;
        }
    }
    else {
        if (DBL_PTR(_8507)->dbl == 0.0) {
            goto L10;
        }
    }
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _0 = _8436;
    _8436 = _16TypeIs(_8436, 1);
    DeRef(_0);
L11:
    if (_8436 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_8436) && DBL_PTR(_8436)->dbl == 0.0)
            goto L10;
    }

    // 		c_stmt("if (@ > @)\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _0 = _8507;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8436;
    Ref(_8436);
    ((int *)_2)[2] = _8507;
    Ref(_8507);
    _8507 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8481);
    RefDS(_8507);
    _16c_stmt(_8481, _8507);
    goto L12;
L10:

    // 		c_stmt("if (binary_op_a(GREATER, @, @))\n", 
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8507;
    Ref(_8507);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8487);
    RefDS(_8436);
    _16c_stmt(_8487, _8436);
L12:

    // 	    Goto(Code[pc+6])
    DeRef(_8436);
    _8436 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _18Goto(_8436);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	    LeftSym = TRUE
    _16LeftSym = 1;

    // 	    if TypeIs(Code[pc+5], TYPE_INTEGER) and
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _0 = _8436;
    _8436 = _16TypeIs(_8436, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8436)) {
        if (_8436 == 0) {
            goto L13;
        }
    }
    else {
        if (DBL_PTR(_8436)->dbl == 0.0) {
            goto L13;
        }
    }
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _0 = _8507;
    _8507 = _16TypeIs(_8507, 1);
    DeRef(_0);
L14:
    if (_8507 == 0) {
        goto L13;
    }
    else {
        if (!IS_ATOM_INT(_8507) && DBL_PTR(_8507)->dbl == 0.0)
            goto L13;
    }

    // 		c_stmt("if (@ < @)\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8507;
    Ref(_8507);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8518);
    RefDS(_8436);
    _16c_stmt(_8518, _8436);
    goto L15;
L13:

    // 		c_stmt("if (binary_op_a(LESS, @, @))\n", 
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _0 = _8507;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8436;
    Ref(_8436);
    ((int *)_2)[2] = _8507;
    Ref(_8507);
    _8507 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8524);
    RefDS(_8507);
    _16c_stmt(_8524, _8507);
L15:

    // 	    Goto(Code[pc+6])
    DeRef(_8507);
    _8507 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _18Goto(_8507);

    // 	    if range1[MIN] != NOVALUE then
    DeRef(_8507);
    _2 = (int)SEQ_PTR(_range1);
    _8507 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8507);
    if (binary_op_a(EQUALS, _8507, _4NOVALUE))
        goto L16;

    // 		SymTab[Code[pc+5]][S_OBJ_MIN] = min(range1[MIN], range2[MIN])
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8507))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8507)->dbl));
    else
        _3 = (int)(_8507 + ((s1_ptr)_2)->base);
    DeRef(_8501);
    _2 = (int)SEQ_PTR(_range1);
    _8501 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8501);
    DeRef(_8426);
    _2 = (int)SEQ_PTR(_range2);
    _8426 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8426);
    Ref(_8501);
    Ref(_8426);
    _0 = _8426;
    _8426 = _18min(_8501, _8426);
    DeRef(_0);
    Ref(_8426);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 27);
    _1 = *(int *)_2;
    *(int *)_2 = _8426;
    DeRef(_1);

    // 		SymTab[Code[pc+5]][S_OBJ_MAX] = max(range1[MAX], range2[MAX])
    DeRef(_8426);
    _8426 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8426 = (int)*(((s1_ptr)_2)->base + _8426);
    Ref(_8426);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8426))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8426)->dbl));
    else
        _3 = (int)(_8426 + ((s1_ptr)_2)->base);
    DeRef(_8436);
    _2 = (int)SEQ_PTR(_range1);
    _8436 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8436);
    DeRef(_8507);
    _2 = (int)SEQ_PTR(_range2);
    _8507 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8507);
    Ref(_8436);
    Ref(_8507);
    _0 = _8507;
    _8507 = _18max(_8436, _8507);
    DeRef(_0);
    Ref(_8507);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 28);
    _1 = *(int *)_2;
    *(int *)_2 = _8507;
    DeRef(_1);
L16:

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L17:
    goto L9;
L1:

    // 	c_stmt("if (@ >= 0) {\n", Code[pc+1])
    DeRef(_8507);
    _8507 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    RefDS(_8546);
    Ref(_8507);
    _16c_stmt(_8546, _8507);

    // 	c_stmt("if (binary_op_a(GREATER, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8507;
    Ref(_8507);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8487);
    RefDS(_8436);
    _16c_stmt(_8487, _8436);

    // 	Goto(Code[pc+6])
    DeRefDS(_8436);
    _8436 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _18Goto(_8436);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt("else if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_8436);
    _8436 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    RefDS(_8612);
    Ref(_8436);
    _16c_stmt(_8612, _8436);

    // 	c_stmt("if (binary_op_a(LESS, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _0 = _8507;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8436;
    Ref(_8436);
    ((int *)_2)[2] = _8507;
    Ref(_8507);
    _8507 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8524);
    RefDS(_8507);
    _16c_stmt(_8524, _8507);

    // 	Goto(Code[pc+6])
    DeRefDS(_8507);
    _8507 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _18Goto(_8507);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	c_stmt("if (DBL_PTR(@)->dbl >= 0.0) {\n", Code[pc+1])          
    DeRef(_8507);
    _8507 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    RefDS(_8622);
    Ref(_8507);
    _16c_stmt(_8622, _8507);

    // 	c_stmt("if (binary_op_a(GREATER, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8507);
    _8507 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    DeRef(_8436);
    _8436 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    _0 = _8436;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8507;
    Ref(_8507);
    ((int *)_2)[2] = _8436;
    Ref(_8436);
    _8436 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8487);
    RefDS(_8436);
    _16c_stmt(_8487, _8436);

    // 	Goto(Code[pc+6])
    DeRefDS(_8436);
    _8436 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    Ref(_8436);
    _18Goto(_8436);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	c_stmt("if (binary_op_a(LESS, @, @))\n", {Code[pc+5], Code[pc+2]})
    DeRef(_8436);
    _8436 = _18pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _8436 = (int)*(((s1_ptr)_2)->base + _8436);
    Ref(_8436);
    DeRef(_8507);
    _8507 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    _0 = _8507;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8436;
    Ref(_8436);
    ((int *)_2)[2] = _8507;
    Ref(_8507);
    _8507 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8524);
    RefDS(_8507);
    _16c_stmt(_8524, _8507);

    // 	Goto(Code[pc+6])
    DeRefDS(_8507);
    _8507 = _18pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _8507 = (int)*(((s1_ptr)_2)->base + _8507);
    Ref(_8507);
    Ref(_8507);
    _18Goto(_8507);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L9:

    //     pc += 7
    _18pc = _18pc + 7;

    // end procedure
    DeRef(_range1);
    DeRef(_range2);
    DeRef(_inc);
    DeRef(_8507);
    DeRef(_8436);
    DeRef(_8501);
    DeRef(_8426);
    return 0;
    ;
}


int _18opENDFOR_GENERAL()
{
    int _close_brace;
    int _gencode = 0;
    int _intcode = 0;
    int _8647 = 0;
    int _8640 = 0;
    int _8645 = 0;
    int _0, _1, _2;
    

    //     in_loop = in_loop[1..length(in_loop)-1]
    _8640 = SEQ_PTR(_18in_loop)->length;
    _8640 = _8640 - 1;
    rhs_slice_target = (object_ptr)&_18in_loop;
    RHS_Slice((s1_ptr)_18in_loop, 1, _8640);

    //     CSaveStr("_0", Code[pc+3], Code[pc+3], Code[pc+4], 0)
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    RefDS(_5774);
    Ref(_8640);
    Ref(_8645);
    Ref(_8647);
    _18CSaveStr(_5774, _8640, _8645, _8647, 0);

    //     close_brace = FALSE
    _close_brace = 0;

    //     gencode = "@ = binary_op_a(PLUS, @, @);\n"
    RefDS(_8649);
    _gencode = _8649;

    //     intcode = "@1 = @2 + @3;\n" &
    {
        int concat_list[3];

        concat_list[0] = _8090;
        concat_list[1] = _8650;
        concat_list[2] = _8088;
        Concat_N((object_ptr)&_intcode, concat_list, 3);
    }

    //     if TypeIs(Code[pc+3], TYPE_INTEGER) and 
    DeRef(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    Ref(_8647);
    _0 = _8647;
    _8647 = _16TypeIs(_8647, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8647)) {
        if (_8647 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8647)->dbl == 0.0) {
            goto L1;
        }
    }
    DeRef(_8645);
    _8645 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    Ref(_8645);
    _0 = _8645;
    _8645 = _16TypeIs(_8645, 1);
    DeRef(_0);
L2:
    if (_8645 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8645) && DBL_PTR(_8645)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("@1 = @2 + @3;\n", {Code[pc+3], Code[pc+3], Code[pc+4]})
    DeRef(_8645);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    DeRef(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    DeRef(_8640);
    _8640 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    _0 = _8640;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8645);
    *((int *)(_2+4)) = _8645;
    Ref(_8647);
    *((int *)(_2+8)) = _8647;
    Ref(_8640);
    *((int *)(_2+12)) = _8640;
    _8640 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8088);
    RefDS(_8640);
    _16c_stmt(_8088, _8640);
    goto L3;
L1:

    //     elsif TypeIs(Code[pc+3], TYPE_INTEGER) and 
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    Ref(_8640);
    _0 = _8640;
    _8640 = _16TypeIs(_8640, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8640)) {
        if (_8640 == 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_8640)->dbl == 0.0) {
            goto L4;
        }
    }
    DeRef(_8647);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    Ref(_8647);
    RefDS(_5781);
    _0 = _8647;
    _8647 = _16TypeIs(_8647, _5781);
    DeRef(_0);
L5:
    if (_8647 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8647) && DBL_PTR(_8647)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+4])
    DeRef(_8647);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    RefDS(_6192);
    Ref(_8647);
    _16c_stmt(_6192, _8647);

    // 	c_stmt("@1 = @2 + @3;\n", {Code[pc+3], Code[pc+3], Code[pc+4]})
    DeRef(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    DeRef(_8645);
    _8645 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    _0 = _8645;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8647);
    *((int *)(_2+4)) = _8647;
    Ref(_8640);
    *((int *)(_2+8)) = _8640;
    Ref(_8645);
    *((int *)(_2+12)) = _8645;
    _8645 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_8088);
    RefDS(_8645);
    _16c_stmt(_8088, _8645);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
    goto L3;
L4:

    //     elsif TypeIs(Code[pc+4], TYPE_INTEGER) and
    DeRef(_8645);
    _8645 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    Ref(_8645);
    _0 = _8645;
    _8645 = _16TypeIs(_8645, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8645)) {
        if (_8645 == 0) {
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_8645)->dbl == 0.0) {
            goto L6;
        }
    }
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    Ref(_8640);
    RefDS(_5781);
    _0 = _8640;
    _8640 = _16TypeIs(_8640, _5781);
    DeRef(_0);
L7:
    if (_8640 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_8640) && DBL_PTR(_8640)->dbl == 0.0)
            goto L6;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+3])
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    RefDS(_6192);
    Ref(_8640);
    _16c_stmt(_6192, _8640);

    // 	c_stmt(intcode, {Code[pc+3], Code[pc+3], Code[pc+4]})
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    DeRef(_8645);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    DeRef(_8647);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    _0 = _8647;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8640);
    *((int *)(_2+4)) = _8640;
    Ref(_8645);
    *((int *)(_2+8)) = _8645;
    Ref(_8647);
    *((int *)(_2+12)) = _8647;
    _8647 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_intcode);
    RefDS(_8647);
    _16c_stmt(_intcode, _8647);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
L6:
L3:

    //     if TypeIs(Code[pc+3], {TYPE_ATOM, TYPE_OBJECT}) and
    DeRef(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    Ref(_8647);
    RefDS(_5781);
    _0 = _8647;
    _8647 = _16TypeIs(_8647, _5781);
    DeRef(_0);
    if (IS_ATOM_INT(_8647)) {
        if (_8647 == 0) {
            goto L8;
        }
    }
    else {
        if (DBL_PTR(_8647)->dbl == 0.0) {
            goto L8;
        }
    }
    DeRef(_8645);
    _8645 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    Ref(_8645);
    RefDS(_5781);
    _0 = _8645;
    _8645 = _16TypeIs(_8645, _5781);
    DeRef(_0);
L9:
    if (_8645 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_8645) && DBL_PTR(_8645)->dbl == 0.0)
            goto L8;
    }

    // 	c_stmt("if (IS_ATOM_INT(@) && IS_ATOM_INT(@)) {\n", 
    DeRef(_8645);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    DeRef(_8647);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    _0 = _8647;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _8645;
    Ref(_8645);
    ((int *)_2)[2] = _8647;
    Ref(_8647);
    _8647 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_6621);
    RefDS(_8647);
    _16c_stmt(_6621, _8647);

    // 	c_stmt(intcode, {Code[pc+3], Code[pc+3], Code[pc+4]})
    DeRefDS(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    DeRef(_8645);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    DeRef(_8640);
    _8640 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    _0 = _8640;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8647);
    *((int *)(_2+4)) = _8647;
    Ref(_8645);
    *((int *)(_2+8)) = _8645;
    Ref(_8640);
    *((int *)(_2+12)) = _8640;
    _8640 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_intcode);
    RefDS(_8640);
    _16c_stmt(_intcode, _8640);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	close_brace = TRUE
    _close_brace = 1;
L8:

    //     if TypeIsNot(Code[pc+3], TYPE_INTEGER) or 
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    Ref(_8640);
    _0 = _8640;
    _8640 = _16TypeIsNot(_8640, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8640)) {
        if (_8640 != 0) {
            goto LA;
        }
    }
    else {
        if (DBL_PTR(_8640)->dbl != 0.0) {
            goto LA;
        }
    }
    DeRef(_8645);
    _8645 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    Ref(_8645);
    _0 = _8645;
    _8645 = _16TypeIsNot(_8645, 1);
    DeRef(_0);
LB:
    if (_8645 == 0) {
        goto LC;
    }
    else {
        if (!IS_ATOM_INT(_8645) && DBL_PTR(_8645)->dbl == 0.0)
            goto LC;
    }
LA:

    // 	c_stmt(gencode, {Code[pc+3], Code[pc+3], Code[pc+4]})
    DeRef(_8645);
    _8645 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8645 = (int)*(((s1_ptr)_2)->base + _8645);
    Ref(_8645);
    DeRef(_8640);
    _8640 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8640 = (int)*(((s1_ptr)_2)->base + _8640);
    Ref(_8640);
    DeRef(_8647);
    _8647 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    _0 = _8647;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_8645);
    *((int *)(_2+4)) = _8645;
    Ref(_8640);
    *((int *)(_2+8)) = _8640;
    Ref(_8647);
    *((int *)(_2+12)) = _8647;
    _8647 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_gencode);
    RefDS(_8647);
    _16c_stmt(_gencode, _8647);
LC:

    //     if close_brace then
    if (_close_brace == 0)
        goto LD;

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
LD:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     Goto(Code[pc+1])
    DeRef(_8647);
    _8647 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    Ref(_8647);
    _18Goto(_8647);

    //     Label(pc+5)
    DeRef(_8647);
    _8647 = _18pc + 5;
    if ((long)((unsigned long)_8647 + (unsigned long)HIGH_BITS) >= 0) 
        _8647 = NewDouble((double)_8647);
    Ref(_8647);
    _18Label(_8647);

    //     c_stmt0(";\n")
    RefDS(_4460);
    _16c_stmt0(_4460);

    //     CDeRef(Code[pc+3])
    DeRef(_8647);
    _8647 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8647 = (int)*(((s1_ptr)_2)->base + _8647);
    Ref(_8647);
    Ref(_8647);
    _18CDeRef(_8647);

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRefi(_gencode);
    DeRefi(_intcode);
    DeRef(_8647);
    DeRef(_8640);
    DeRef(_8645);
    return 0;
    ;
}


int _18opCALL_PROC()
{
    int _8737 = 0;
    int _8763 = 0;
    int _8739 = 0;
    int _0, _1, _2, _3;
    

    //     if last_routine_id > 0 or Code[pc] = CALL_FUNC then
    _8737 = (_14last_routine_id > 0);
    if (_8737 != 0) {
        goto L1;
    }
    _2 = (int)SEQ_PTR(_4Code);
    _8739 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8739);
    _0 = _8739;
    if (IS_ATOM_INT(_8739)) {
        _8739 = (_8739 == 139);
    }
    else {
        _8739 = binary_op(EQUALS, _8739, 139);
    }
    DeRef(_0);
L2:
    if (_8739 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8739) && DBL_PTR(_8739)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	if TypeIs(Code[pc+2], TYPE_SEQUENCE) then
    DeRef(_8739);
    _8739 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8739 = (int)*(((s1_ptr)_2)->base + _8739);
    Ref(_8739);
    Ref(_8739);
    _0 = _8739;
    _8739 = _16TypeIs(_8739, 8);
    DeRef(_0);
    if (_8739 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8739) && DBL_PTR(_8739)->dbl == 0.0)
            goto L4;
    }

    // 	    len = SeqLen(Code[pc+2])
    DeRef(_8739);
    _8739 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8739 = (int)*(((s1_ptr)_2)->base + _8739);
    Ref(_8739);
    Ref(_8739);
    _0 = _18SeqLen(_8739);
    DeRef(_18len);
    _18len = _0;
    goto L5;
L4:

    // 	    len = NOVALUE
    RefDS(_4NOVALUE);
    DeRef(_18len);
    _18len = _4NOVALUE;
L5:

    // 	if len != 0 then
    if (binary_op_a(EQUALS, _18len, 0))
        goto L6;

    // 	    c_stmt("_1 = (int)SEQ_PTR(@);\n", Code[pc+2])
    DeRef(_8739);
    _8739 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8739 = (int)*(((s1_ptr)_2)->base + _8739);
    Ref(_8739);
    RefDS(_8748);
    Ref(_8739);
    _16c_stmt(_8748, _8739);

    // 	    c_stmt0("_2 = (int)((s1_ptr)_1)->base;\n")
    RefDS(_7439);
    _16c_stmt0(_7439);
L6:

    // 	c_stmt("_0 = (int)_00[@].addr;\n", Code[pc+1])
    DeRef(_8739);
    _8739 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8739 = (int)*(((s1_ptr)_2)->base + _8739);
    Ref(_8739);
    RefDS(_8751);
    Ref(_8739);
    _16c_stmt(_8751, _8739);

    // 	if len = NOVALUE then
    if (binary_op_a(NOTEQ, _18len, _4NOVALUE))
        goto L7;

    // 	    c_stmt0("switch(((s1_ptr)_1)->length) {\n")
    RefDS(_8755);
    _16c_stmt0(_8755);
L7:

    // 	for i = 0 to last_max_params do
    DeRef(_8739);
    _8739 = _14last_max_params;
    { int _i;
        _i = 0;
L8:
        if (_i > _8739)
            goto L9;

        // 	    if len = NOVALUE then
        if (binary_op_a(NOTEQ, _18len, _4NOVALUE))
            goto LA;

        // 		c_stmt0("case ")
        RefDS(_8758);
        _16c_stmt0(_8758);

        // 		c_printf("%d:\n", i)
        RefDS(_8759);
        _9c_printf(_8759, _i);

        // 		indent += 4
        _9indent = _9indent + 4;
LA:

        // 	    if len = NOVALUE or len = i then
        DeRef(_8737);
        if (IS_ATOM_INT(_18len)) {
            _8737 = ((double)_18len == DBL_PTR(_4NOVALUE)->dbl);
        }
        else {
            _8737 = (DBL_PTR(_18len)->dbl == DBL_PTR(_4NOVALUE)->dbl);
        }
        if (_8737 != 0) {
            goto LB;
        }
        DeRef(_8763);
        if (IS_ATOM_INT(_18len)) {
            _8763 = (_18len == _i);
        }
        else {
            _8763 = (DBL_PTR(_18len)->dbl == (double)_i);
        }
LC:
        if (_8763 == 0)
            goto LD;
LB:

        // 		for k = 1 to i do
        { int _k;
            _k = 1;
LE:
            if (_k > _i)
                goto LF;

            // 		    c_stmt0("Ref(*(int *)(_2+")
            RefDS(_8764);
            _16c_stmt0(_8764);

            // 		    c_printf("%d));\n", k * 4)
            DeRef(_8763);
            if (_k == (short)_k)
                _8763 = _k * 4;
            else
                _8763 = NewDouble(_k * (double)4);
            RefDS(_8765);
            Ref(_8763);
            _9c_printf(_8765, _8763);

            // 		end for
            _k = _k + 1;
            goto LE;
LF:
            ;
        }

        // 		if EWINDOWS and dll_option then
        if (_4EWINDOWS == 0) {
            goto L10;
        }
L11:
        if (_16dll_option == 0)
            goto L10;

        // 		    c_stmt("if (_00[@].convention) {\n", Code[pc+1])
        DeRef(_8763);
        _8763 = _18pc + 1;
        _2 = (int)SEQ_PTR(_4Code);
        _8763 = (int)*(((s1_ptr)_2)->base + _8763);
        Ref(_8763);
        RefDS(_8768);
        Ref(_8763);
        _16c_stmt(_8768, _8763);

        // 		    if Code[pc] = CALL_FUNC then 
        DeRef(_8763);
        _2 = (int)SEQ_PTR(_4Code);
        _8763 = (int)*(((s1_ptr)_2)->base + _18pc);
        Ref(_8763);
        if (binary_op_a(NOTEQ, _8763, 139))
            goto L12;

        // 			c_stmt0("_1 = (*(int (__stdcall *)())_0)(\n")
        RefDS(_8773);
        _16c_stmt0(_8773);

        // 			arg_list(i)
        _18arg_list(_i);

        // 			c_stmt0("}\n")
        RefDS(_6207);
        _16c_stmt0(_6207);

        // 			c_stmt0("else {\n")
        RefDS(_6208);
        _16c_stmt0(_6208);

        // 			c_stmt0("_1 = (*(int (*)())_0)(\n")
        RefDS(_8774);
        _16c_stmt0(_8774);
        goto L13;
L12:

        // 			c_stmt0("(*(int (__stdcall *)())_0)(\n")
        RefDS(_8775);
        _16c_stmt0(_8775);

        // 			arg_list(i)
        _18arg_list(_i);

        // 			c_stmt0("}\n")
        RefDS(_6207);
        _16c_stmt0(_6207);

        // 			c_stmt0("else {\n")
        RefDS(_6208);
        _16c_stmt0(_6208);

        // 			c_stmt0("(*(int (*)())_0)(\n")
        RefDS(_8776);
        _16c_stmt0(_8776);
L13:

        // 		    arg_list(i)
        _18arg_list(_i);

        // 		    c_stmt0("}\n")
        RefDS(_6207);
        _16c_stmt0(_6207);
        goto L14;
L10:

        // 		    if Code[pc] = CALL_FUNC then 
        DeRef(_8763);
        _2 = (int)SEQ_PTR(_4Code);
        _8763 = (int)*(((s1_ptr)_2)->base + _18pc);
        Ref(_8763);
        if (binary_op_a(NOTEQ, _8763, 139))
            goto L15;

        // 			c_stmt0("_1 = (*(int (*)())_0)(\n")
        RefDS(_8774);
        _16c_stmt0(_8774);
        goto L16;
L15:

        // 			c_stmt0("(*(int (*)())_0)(\n")
        RefDS(_8776);
        _16c_stmt0(_8776);
L16:

        // 		    arg_list(i)
        _18arg_list(_i);
L14:
LD:

        // 	    if len = NOVALUE then
        if (binary_op_a(NOTEQ, _18len, _4NOVALUE))
            goto L17;

        // 		c_stmt0("break;\n")
        RefDS(_8780);
        _16c_stmt0(_8780);

        // 		indent -= 4
        _9indent = _9indent - 4;
L17:

        // 	end for
        _i = _i + 1;
        goto L8;
L9:
        ;
    }

    // 	if len = NOVALUE then
    if (binary_op_a(NOTEQ, _18len, _4NOVALUE))
        goto L18;

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L18:

    // 	NewBB(1, E_ALL_EFFECT, 0) -- Windows call-back to Euphoria routine could occur
    _16NewBB(1, 1073741823, 0);

    // 	if Code[pc] = CALL_FUNC then
    DeRef(_8763);
    _2 = (int)SEQ_PTR(_4Code);
    _8763 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8763);
    if (binary_op_a(NOTEQ, _8763, 139))
        goto L19;

    // 	    CDeRef(Code[pc+3])
    DeRef(_8763);
    _8763 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8763 = (int)*(((s1_ptr)_2)->base + _8763);
    Ref(_8763);
    Ref(_8763);
    _18CDeRef(_8763);

    // 	    c_stmt("@ = _1;\n", Code[pc+3])
    DeRef(_8763);
    _8763 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8763 = (int)*(((s1_ptr)_2)->base + _8763);
    Ref(_8763);
    RefDS(_7200);
    Ref(_8763);
    _16c_stmt(_7200, _8763);

    // 	    SymTab[Code[pc+3]][S_ONE_REF] = FALSE
    DeRef(_8763);
    _8763 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8763 = (int)*(((s1_ptr)_2)->base + _8763);
    Ref(_8763);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8763))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8763)->dbl));
    else
        _3 = (int)(_8763 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	    SetBBType(Code[pc+3], TYPE_OBJECT, novalue, TYPE_OBJECT)
    DeRef(_8737);
    _8737 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8737 = (int)*(((s1_ptr)_2)->base + _8737);
    Ref(_8737);
    Ref(_8737);
    RefDS(_9novalue);
    _16SetBBType(_8737, 16, _9novalue, 16);
L19:
L3:

    //     pc += 3 + (Code[pc] = CALL_FUNC)
    DeRef(_8737);
    _2 = (int)SEQ_PTR(_4Code);
    _8737 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8737);
    _0 = _8737;
    if (IS_ATOM_INT(_8737)) {
        _8737 = (_8737 == 139);
    }
    else {
        _8737 = binary_op(EQUALS, _8737, 139);
    }
    DeRef(_0);
    _0 = _8737;
    if (IS_ATOM_INT(_8737)) {
        _8737 = 3 + _8737;
        if ((long)((unsigned long)_8737 + (unsigned long)HIGH_BITS) >= 0) 
            _8737 = NewDouble((double)_8737);
    }
    else {
        _8737 = binary_op(PLUS, 3, _8737);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8737)) {
        _18pc = _18pc + _8737;
    }
    else {
        _18pc = binary_op(PLUS, _18pc, _8737);
    }
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8737);
    DeRef(_8763);
    DeRef(_8739);
    return 0;
    ;
}


int _18opCALL_BACK_RETURN()
{
    int _0, _1, _2;
    

    //     pc += 1
    _18pc = _18pc + 1;

    //     all_done = TRUE
    _18all_done = 1;

    // end procedure               
    return 0;
    ;
}


int _18opBADRETURNF()
{
    int _0, _1, _2;
    

    //     pc += 1
    _18pc = _18pc + 1;

    //     all_done = TRUE  -- end of a function
    _18all_done = 1;

    // end procedure
    return 0;
    ;
}


int _18opRETURNF()
{
    int _sym;
    int _sub;
    int _doref;
    int _x = 0;
    int _8805 = 0;
    int _8804 = 0;
    int _8801 = 0;
    int _8807 = 0;
    int _0, _1, _2, _3;
    

    //     sub = Code[pc+1]
    _8801 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _8801);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     SymTab[sub][S_GTYPE_NEW] = or_type(SymTab[sub][S_GTYPE_NEW], 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8805 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8805);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_8805);
    _8805 = (int)*(((s1_ptr)_2)->base + 35);
    Ref(_8805);
    DeRefDS(_0);
    _8807 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8807 = (int)*(((s1_ptr)_2)->base + _8807);
    Ref(_8807);
    Ref(_8807);
    _0 = _8807;
    _8807 = _16GType(_8807);
    DeRef(_0);
    Ref(_8805);
    _8807 = _16or_type(_8805, _8807);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 35);
    _1 = *(int *)_2;
    *(int *)_2 = _8807;
    DeRef(_1);

    //     SymTab[sub][S_SEQ_ELEM_NEW] = or_type(SymTab[sub][S_SEQ_ELEM_NEW], 
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_8804);
    DeRefDS(_0);
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    Ref(_8801);
    _0 = _8801;
    _8801 = _18SeqElem(_8801);
    DeRef(_0);
    Ref(_8804);
    _8801 = _16or_type(_8804, _8801);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _8801;
    DeRef(_1);

    //     if GType(Code[pc+2]) = TYPE_INTEGER then
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    Ref(_8801);
    _0 = _8801;
    _8801 = _16GType(_8801);
    DeRef(_0);
    if (_8801 != 1)
        goto L1;

    // 	x = ObjMinMax(Code[pc+2])
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    Ref(_8801);
    _x = _18ObjMinMax(_8801);

    // 	if SymTab[sub][S_OBJ_MIN_NEW] = -NOVALUE then
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_8801);
    DeRefDS(_0);
    DeRef(_8804);
    _8804 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _8801, _8804))
        goto L2;

    // 	    SymTab[sub][S_OBJ_MIN_NEW] = x[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_x);
    _8805 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8805);
    Ref(_8805);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _8805;
    DeRef(_1);

    // 	    SymTab[sub][S_OBJ_MAX_NEW] = x[MAX]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRefDS(_8804);
    _2 = (int)SEQ_PTR(_x);
    _8804 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8804);
    Ref(_8804);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 39);
    _1 = *(int *)_2;
    *(int *)_2 = _8804;
    DeRef(_1);
    goto L3;
L2:

    // 	elsif SymTab[sub][S_OBJ_MIN_NEW] != NOVALUE then
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_8804);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _8804, _4NOVALUE))
        goto L3;

    // 	    if x[MIN] < SymTab[sub][S_OBJ_MIN_NEW] then
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_x);
    _8804 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8804);
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 38);
    Ref(_8801);
    DeRefDS(_0);
    if (binary_op_a(GREATEREQ, _8804, _8801))
        goto L4;

    // 		SymTab[sub][S_OBJ_MIN_NEW] = x[MIN]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_x);
    _8805 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8805);
    Ref(_8805);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 38);
    _1 = *(int *)_2;
    *(int *)_2 = _8805;
    DeRef(_1);
L4:

    // 	    if x[MAX] > SymTab[sub][S_OBJ_MAX_NEW] then
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_x);
    _8805 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8805);
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 39);
    Ref(_8804);
    DeRefDS(_0);
    if (binary_op_a(LESSEQ, _8805, _8804))
        goto L3;

    // 		SymTab[sub][S_OBJ_MAX_NEW] = x[MAX]
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_x);
    _8801 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8801);
    Ref(_8801);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 39);
    _1 = *(int *)_2;
    *(int *)_2 = _8801;
    DeRef(_1);
L5:
L6:
L7:
    goto L3;
L1:

    //     elsif GType(Code[pc+2]) = TYPE_SEQUENCE then
    DeRef(_8801);
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    Ref(_8801);
    _0 = _8801;
    _8801 = _16GType(_8801);
    DeRef(_0);
    if (_8801 != 8)
        goto L8;

    // 	if SymTab[sub][S_SEQ_LEN_NEW] = -NOVALUE then
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_8801);
    DeRefDS(_0);
    DeRef(_8805);
    _8805 = unary_op(UMINUS, _4NOVALUE);
    if (binary_op_a(NOTEQ, _8801, _8805))
        goto L9;

    // 	    SymTab[sub][S_SEQ_LEN_NEW] = SeqLen(Code[pc+2])
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    DeRef(_8804);
    _8804 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    Ref(_8804);
    Ref(_8804);
    _0 = _8804;
    _8804 = _18SeqLen(_8804);
    DeRef(_0);
    Ref(_8804);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 36);
    _1 = *(int *)_2;
    *(int *)_2 = _8804;
    DeRef(_1);
    goto L3;
L9:

    // 	elsif SymTab[sub][S_SEQ_LEN_NEW] != SeqLen(Code[pc+2]) then
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 36);
    Ref(_8804);
    DeRefDS(_0);
    DeRef(_8801);
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    Ref(_8801);
    _0 = _8801;
    _8801 = _18SeqLen(_8801);
    DeRef(_0);
    if (binary_op_a(EQUALS, _8804, _8801))
        goto L3;

    // 	    SymTab[sub][S_SEQ_LEN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
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
LA:
LB:
    goto L3;
L8:

    // 	SymTab[sub][S_OBJ_MIN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
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

    // 	SymTab[sub][S_SEQ_LEN_NEW] = NOVALUE
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
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
L3:

    //     doref = TRUE
    _doref = 1;

    //     for i = 1 to length(in_loop) do
    DeRef(_8804);
    _8804 = SEQ_PTR(_18in_loop)->length;
    { int _i;
        _i = 1;
LC:
        if (_i > _8804)
            goto LD;

        // 	if in_loop[i] != 0 then
        DeRef(_8801);
        _2 = (int)SEQ_PTR(_18in_loop);
        _8801 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8801);
        if (binary_op_a(EQUALS, _8801, 0))
            goto LE;

        // 	    if in_loop[i] = Code[pc+2] then
        DeRef(_8801);
        _2 = (int)SEQ_PTR(_18in_loop);
        _8801 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8801);
        DeRef(_8805);
        _8805 = _18pc + 2;
        _2 = (int)SEQ_PTR(_4Code);
        _8805 = (int)*(((s1_ptr)_2)->base + _8805);
        Ref(_8805);
        if (binary_op_a(NOTEQ, _8801, _8805))
            goto LF;

        // 		doref = FALSE
        _doref = 0;
        goto L10;
LF:

        // 		CDeRef(in_loop[i])
        DeRef(_8805);
        _2 = (int)SEQ_PTR(_18in_loop);
        _8805 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8805);
        Ref(_8805);
        _18CDeRef(_8805);
L10:
LE:

        //     end for
        _i = _i + 1;
        goto LC;
LD:
        ;
    }

    //     if SymTab[Code[pc+2]][S_MODE] = M_TEMP then
    DeRef(_8805);
    _8805 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8805 = (int)*(((s1_ptr)_2)->base + _8805);
    Ref(_8805);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_8805))
        _8805 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8805)->dbl));
    else
        _8805 = (int)*(((s1_ptr)_2)->base + _8805);
    RefDS(_8805);
    DeRef(_0);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_8805);
    _8805 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_8805);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _8805, 3))
        goto L11;

    // 	sym = SymTab[sub][S_TEMPS]
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8805 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8805);
    _2 = (int)SEQ_PTR(_8805);
    _sym = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	while sym != 0 do
L12:
    if (_sym == 0)
        goto L13;

    // 	    if SymTab[sym][S_SCOPE] != DELETED and 
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8805 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8805);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_8805);
    _8805 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8805);
    DeRefDS(_0);
    _0 = _8805;
    if (IS_ATOM_INT(_8805)) {
        _8805 = (_8805 != 2);
    }
    else {
        _8805 = binary_op(NOTEQ, _8805, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8805)) {
        if (_8805 == 0) {
            goto L14;
        }
    }
    else {
        if (DBL_PTR(_8805)->dbl == 0.0) {
            goto L14;
        }
    }
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_8801);
    DeRefDS(_0);
    DeRef(_8804);
    _8804 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    Ref(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_8804))
        _8804 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8804)->dbl));
    else
        _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    RefDS(_8804);
    DeRef(_0);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_8804);
    DeRefDS(_0);
    _0 = _8804;
    if (IS_ATOM_INT(_8801) && IS_ATOM_INT(_8804)) {
        _8804 = (_8801 == _8804);
    }
    else {
        _8804 = binary_op(EQUALS, _8801, _8804);
    }
    DeRef(_0);
L15:
    if (_8804 == 0) {
        goto L14;
    }
    else {
        if (!IS_ATOM_INT(_8804) && DBL_PTR(_8804)->dbl == 0.0)
            goto L14;
    }

    // 		doref = FALSE
    _doref = 0;

    // 		exit
    goto L13;
L14:

    // 	    sym = SymTab[sym][S_NEXT]
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _2 = (int)SEQ_PTR(_8804);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	end while
    goto L12;
L16:
    goto L13;
L11:

    // 	sym = SymTab[sub][S_NEXT]
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8804);
    _2 = (int)SEQ_PTR(_8804);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	while sym != 0 and SymTab[sym][S_SCOPE] <= SC_PRIVATE do
L17:
    DeRef(_8804);
    _8804 = (_sym != 0);
    if (_8804 == 0) {
        goto L18;
    }
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8801);
    DeRefDS(_0);
    _0 = _8801;
    if (IS_ATOM_INT(_8801)) {
        _8801 = (_8801 <= 3);
    }
    else {
        _8801 = binary_op(LESSEQ, _8801, 3);
    }
    DeRef(_0);
L19:
    if (_8801 <= 0) {
        if (_8801 == 0) {
            goto L18;
        }
        else {
            if (!IS_ATOM_INT(_8801) && DBL_PTR(_8801)->dbl == 0.0)
                goto L18;
        }
    }

    // 	    if SymTab[sym][S_SCOPE] != SC_LOOP_VAR and
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8801);
    DeRefDS(_0);
    _0 = _8801;
    if (IS_ATOM_INT(_8801)) {
        _8801 = (_8801 != 2);
    }
    else {
        _8801 = binary_op(NOTEQ, _8801, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8801)) {
        if (_8801 == 0) {
            goto L1A;
        }
    }
    else {
        if (DBL_PTR(_8801)->dbl == 0.0) {
            goto L1A;
        }
    }
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8804);
    DeRefDS(_0);
    _0 = _8804;
    if (IS_ATOM_INT(_8804)) {
        _8804 = (_8804 != 4);
    }
    else {
        _8804 = binary_op(NOTEQ, _8804, 4);
    }
    DeRef(_0);
L1B:
    if (_8804 == 0) {
        goto L1A;
    }
    else {
        if (!IS_ATOM_INT(_8804) && DBL_PTR(_8804)->dbl == 0.0)
            goto L1A;
    }

    // 		if sym = Code[pc+2] then
    DeRef(_8804);
    _8804 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    Ref(_8804);
    if (binary_op_a(NOTEQ, _sym, _8804))
        goto L1C;

    // 		    doref = FALSE
    _doref = 0;

    // 		    exit
    goto L18;
L1C:
L1A:

    // 	    sym = SymTab[sym][S_NEXT]
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _2 = (int)SEQ_PTR(_8804);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    // 	end while
    goto L17;
L18:
L13:

    //     if doref then
    if (_doref == 0)
        goto L1D;

    // 	CRef(Code[pc+2])                
    DeRef(_8804);
    _8804 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    Ref(_8804);
    Ref(_8804);
    _18CRef(_8804);
L1D:

    //     SymTab[Code[pc+2]][S_ONE_REF] = FALSE
    DeRef(_8804);
    _8804 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8804 = (int)*(((s1_ptr)_2)->base + _8804);
    Ref(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_8804))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_8804)->dbl));
    else
        _3 = (int)(_8804 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     sym = SymTab[sub][S_NEXT]
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8801);
    _2 = (int)SEQ_PTR(_8801);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     while sym != 0 and SymTab[sym][S_SCOPE] <= SC_PRIVATE do
L1E:
    DeRef(_8801);
    _8801 = (_sym != 0);
    if (_8801 == 0) {
        goto L1F;
    }
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8804);
    DeRefDS(_0);
    _0 = _8804;
    if (IS_ATOM_INT(_8804)) {
        _8804 = (_8804 <= 3);
    }
    else {
        _8804 = binary_op(LESSEQ, _8804, 3);
    }
    DeRef(_0);
L20:
    if (_8804 <= 0) {
        if (_8804 == 0) {
            goto L1F;
        }
        else {
            if (!IS_ATOM_INT(_8804) && DBL_PTR(_8804)->dbl == 0.0)
                goto L1F;
        }
    }

    // 	if SymTab[sym][S_SCOPE] != SC_LOOP_VAR and
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8804);
    DeRefDS(_0);
    _0 = _8804;
    if (IS_ATOM_INT(_8804)) {
        _8804 = (_8804 != 2);
    }
    else {
        _8804 = binary_op(NOTEQ, _8804, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8804)) {
        if (_8804 == 0) {
            goto L21;
        }
    }
    else {
        if (DBL_PTR(_8804)->dbl == 0.0) {
            goto L21;
        }
    }
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8801);
    DeRefDS(_0);
    _0 = _8801;
    if (IS_ATOM_INT(_8801)) {
        _8801 = (_8801 != 4);
    }
    else {
        _8801 = binary_op(NOTEQ, _8801, 4);
    }
    DeRef(_0);
L22:
    if (_8801 == 0) {
        goto L21;
    }
    else {
        if (!IS_ATOM_INT(_8801) && DBL_PTR(_8801)->dbl == 0.0)
            goto L21;
    }

    // 	    if sym != Code[pc+2] then
    DeRef(_8801);
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    if (binary_op_a(EQUALS, _sym, _8801))
        goto L23;

    // 		CDeRef(sym)
    _18CDeRef(_sym);
L23:
L21:

    // 	sym = SymTab[sym][S_NEXT]
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _2 = (int)SEQ_PTR(_8801);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     end while
    goto L1E;
L1F:

    //     sym = SymTab[sub][S_TEMPS]
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_8801);
    _2 = (int)SEQ_PTR(_8801);
    _sym = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     while sym != 0 do
L24:
    if (_sym == 0)
        goto L25;

    // 	if SymTab[sym][S_SCOPE] != DELETED then  
    DeRef(_8801);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8801 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8801);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _8801, 2))
        goto L26;

    // 	    if SymTab[Code[pc+2]][S_MODE] != M_TEMP or
    DeRef(_8801);
    _8801 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    Ref(_8801);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_8801))
        _8801 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8801)->dbl));
    else
        _8801 = (int)*(((s1_ptr)_2)->base + _8801);
    RefDS(_8801);
    DeRef(_0);
    _0 = _8801;
    _2 = (int)SEQ_PTR(_8801);
    _8801 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_8801);
    DeRefDS(_0);
    _0 = _8801;
    if (IS_ATOM_INT(_8801)) {
        _8801 = (_8801 != 3);
    }
    else {
        _8801 = binary_op(NOTEQ, _8801, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8801)) {
        if (_8801 != 0) {
            goto L27;
        }
    }
    else {
        if (DBL_PTR(_8801)->dbl != 0.0) {
            goto L27;
        }
    }
    DeRef(_8804);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8804 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8804);
    _0 = _8804;
    _2 = (int)SEQ_PTR(_8804);
    _8804 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_8804);
    DeRefDS(_0);
    DeRef(_8805);
    _8805 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8805 = (int)*(((s1_ptr)_2)->base + _8805);
    Ref(_8805);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_8805))
        _8805 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_8805)->dbl));
    else
        _8805 = (int)*(((s1_ptr)_2)->base + _8805);
    RefDS(_8805);
    DeRef(_0);
    _0 = _8805;
    _2 = (int)SEQ_PTR(_8805);
    _8805 = (int)*(((s1_ptr)_2)->base + 31);
    Ref(_8805);
    DeRefDS(_0);
    _0 = _8805;
    if (IS_ATOM_INT(_8804) && IS_ATOM_INT(_8805)) {
        _8805 = (_8804 != _8805);
    }
    else {
        _8805 = binary_op(NOTEQ, _8804, _8805);
    }
    DeRef(_0);
L28:
    if (_8805 == 0) {
        goto L29;
    }
    else {
        if (!IS_ATOM_INT(_8805) && DBL_PTR(_8805)->dbl == 0.0)
            goto L29;
    }
L27:

    // 		FinalDeRef(sym)
    _18FinalDeRef(_sym);
L29:
L26:

    // 	sym = SymTab[sym][S_NEXT]
    DeRef(_8805);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8805 = (int)*(((s1_ptr)_2)->base + _sym);
    RefDS(_8805);
    _2 = (int)SEQ_PTR(_8805);
    _sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_sym))
        _sym = (long)DBL_PTR(_sym)->dbl;

    //     end while
    goto L24;
L25:

    //     FlushDeRef()
    _18FlushDeRef();

    //     c_stmt0("return ")
    RefDS(_8972);
    _16c_stmt0(_8972);

    //     CName(Code[pc+2])
    DeRef(_8805);
    _8805 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8805 = (int)*(((s1_ptr)_2)->base + _8805);
    Ref(_8805);
    Ref(_8805);
    _16CName(_8805);

    //     c_puts(";\n")
    RefDS(_4460);
    _9c_puts(_4460);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_x);
    DeRef(_8805);
    DeRef(_8804);
    DeRef(_8801);
    DeRef(_8807);
    return 0;
    ;
}


