// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opRHS_SUBS()
{
    int _7022 = 0;
    int _7020 = 0;
    int _7018 = 0;
    int _0, _1, _2, _3;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+2], Code[pc+1], 0)
    _7018 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7018 = (int)*(((s1_ptr)_2)->base + _7018);
    Ref(_7018);
    _7020 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_5774);
    Ref(_7018);
    Ref(_7020);
    Ref(_7022);
    _18CSaveStr(_5774, _7018, _7020, _7022, 0);

    //     SymTab[Code[pc+3]][S_ONE_REF] = FALSE
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7022))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7022)->dbl));
    else
        _3 = (int)(_7022 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     if Code[pc] = ASSIGN_OP_SUBS or Code[pc] = PASSIGN_OP_SUBS then
    DeRef(_7020);
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7020);
    _0 = _7020;
    if (IS_ATOM_INT(_7020)) {
        _7020 = (_7020 == 151);
    }
    else {
        _7020 = binary_op(EQUALS, _7020, 151);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7020)) {
        if (_7020 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_7020)->dbl != 0.0) {
            goto L1;
        }
    }
    DeRef(_7022);
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7022);
    _0 = _7022;
    if (IS_ATOM_INT(_7022)) {
        _7022 = (_7022 == 166);
    }
    else {
        _7022 = binary_op(EQUALS, _7022, 166);
    }
    DeRef(_0);
L2:
    if (_7022 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_7022) && DBL_PTR(_7022)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	if Code[pc] = PASSIGN_OP_SUBS then
    DeRef(_7022);
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7022);
    if (binary_op_a(NOTEQ, _7022, 166))
        goto L4;

    // 	    c_stmt0("_2 = (int)SEQ_PTR(*(int *)_3);\n")
    RefDS(_7035);
    _16c_stmt0(_7035);
    goto L5;
L4:

    // 	    c_stmt("_2 = (int)SEQ_PTR(@);\n", Code[pc+1])
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_7036);
    Ref(_7022);
    _16c_stmt(_7036, _7022);

    // 	    SetBBType(Code[pc+1], TYPE_SEQUENCE, novalue, TYPE_OBJECT)
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    RefDS(_9novalue);
    _16SetBBType(_7022, 8, _9novalue, 16);
L6:
    goto L5;
L3:

    // 	c_stmt("_2 = (int)SEQ_PTR(@);\n", Code[pc+1])
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_7036);
    Ref(_7022);
    _16c_stmt(_7036, _7022);
L5:

    //     if TypeIsNot(Code[pc+2], TYPE_INTEGER) then
    DeRef(_7022);
    _7022 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    _0 = _7022;
    _7022 = _16TypeIsNot(_7022, 1);
    DeRef(_0);
    if (_7022 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_7022) && DBL_PTR(_7022)->dbl == 0.0)
            goto L7;
    }

    // 	c_stmt("if (!IS_ATOM_INT(@))\n", Code[pc+2])
    DeRef(_7022);
    _7022 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_7046);
    Ref(_7022);
    _16c_stmt(_7046, _7022);

    // 	c_stmt("@ = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(@)->dbl));\n", 
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    DeRef(_7020);
    _7020 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    _0 = _7020;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7022;
    Ref(_7022);
    ((int *)_2)[2] = _7020;
    Ref(_7020);
    _7020 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7049);
    RefDS(_7020);
    _16c_stmt(_7049, _7020);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L7:

    //     c_stmt("@ = (int)*(((s1_ptr)_2)->base + @);\n", {Code[pc+3], Code[pc+2]})
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    DeRef(_7022);
    _7022 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    _0 = _7022;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7020;
    Ref(_7020);
    ((int *)_2)[2] = _7022;
    Ref(_7022);
    _7022 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7055);
    RefDS(_7022);
    _16c_stmt(_7055, _7022);

    //     if Code[pc] = PASSIGN_OP_SUBS then -- simplified
    DeRefDS(_7022);
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7022);
    if (binary_op_a(NOTEQ, _7022, 166))
        goto L8;

    // 	LeftSym = TRUE
    _16LeftSym = 1;

    // 	c_stmt("Ref(@);\n", Code[pc+3])
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_7063);
    Ref(_7022);
    _16c_stmt(_7063, _7022);

    // 	CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	SetBBType(Code[pc+3], 
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    RefDS(_9novalue);
    _16SetBBType(_7022, 16, _9novalue, 16);
    goto L9;
L8:

    // 	if Code[pc] = RHS_SUBS_I then
    DeRef(_7022);
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_7022);
    if (binary_op_a(NOTEQ, _7022, 114))
        goto LA;

    // 	    if SeqElem(Code[pc+1]) != TYPE_INTEGER then
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    _0 = _7022;
    _7022 = _18SeqElem(_7022);
    DeRef(_0);
    if (_7022 == 1)
        goto LB;

    // 		SetBBType(Code[pc+3], TYPE_OBJECT, novalue, TYPE_OBJECT)
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    RefDS(_9novalue);
    _16SetBBType(_7022, 16, _9novalue, 16);

    // 		c_stmt("if (!IS_ATOM_INT(@))\n", Code[pc+3])
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    RefDS(_7046);
    Ref(_7022);
    _16c_stmt(_7046, _7022);

    // 		c_stmt("@ = (long)DBL_PTR(@)->dbl;\n", {Code[pc+3], Code[pc+3]})
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    _0 = _7020;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7022;
    Ref(_7022);
    ((int *)_2)[2] = _7020;
    Ref(_7020);
    _7020 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7078);
    RefDS(_7020);
    _16c_stmt(_7078, _7020);
LB:

    // 	    CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	    SetBBType(Code[pc+3], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    Ref(_7020);
    RefDS(_9novalue);
    _16SetBBType(_7020, 1, _9novalue, 16);
    goto LC;
LA:

    // 	elsif Code[pc+4] = INTEGER_CHECK then
    DeRef(_7020);
    _7020 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    if (binary_op_a(NOTEQ, _7020, 96))
        goto LD;

    // 	    if SeqElem(Code[pc+1]) != TYPE_INTEGER then
    DeRef(_7020);
    _7020 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    Ref(_7020);
    _0 = _7020;
    _7020 = _18SeqElem(_7020);
    DeRef(_0);
    if (_7020 == 1)
        goto LE;

    // 		SetBBType(Code[pc+3], TYPE_OBJECT, novalue, TYPE_OBJECT)
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    Ref(_7020);
    RefDS(_9novalue);
    _16SetBBType(_7020, 16, _9novalue, 16);

    // 		c_stmt("if (!IS_ATOM_INT(@))\n", Code[pc+3])
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    RefDS(_7046);
    Ref(_7020);
    _16c_stmt(_7046, _7020);

    // 		c_stmt("@ = (long)DBL_PTR(@)->dbl;\n", {Code[pc+3], Code[pc+3]})
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    _0 = _7022;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7020;
    Ref(_7020);
    ((int *)_2)[2] = _7022;
    Ref(_7022);
    _7022 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7078);
    RefDS(_7022);
    _16c_stmt(_7078, _7022);
LE:

    // 	    CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	    SetBBType(Code[pc+3], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_7022);
    _7022 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    RefDS(_9novalue);
    _16SetBBType(_7022, 1, _9novalue, 16);

    // 	    pc += 2 -- skip INTEGER_CHECK 
    _18pc = _18pc + 2;
    goto LC;
LD:

    // 	    if SeqElem(Code[pc+1]) != TYPE_INTEGER then
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    _0 = _7022;
    _7022 = _18SeqElem(_7022);
    DeRef(_0);
    if (_7022 == 1)
        goto LF;

    // 		LeftSym = TRUE
    _16LeftSym = 1;

    // 		if SeqElem(Code[pc+1]) = TYPE_OBJECT or
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    _0 = _7022;
    _7022 = _18SeqElem(_7022);
    DeRef(_0);
    _7022 = (_7022 == 16);
    if (_7022 != 0) {
        goto L10;
    }
    DeRef(_7020);
    _7020 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    Ref(_7020);
    _0 = _7020;
    _7020 = _18SeqElem(_7020);
    DeRef(_0);
    _7020 = (_7020 == 4);
L11:
    if (_7020 == 0)
        goto L12;
L10:

    // 		    c_stmt("Ref(@);\n", Code[pc+3])
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    RefDS(_7063);
    Ref(_7020);
    _16c_stmt(_7063, _7020);
    goto L13;
L12:

    // 		    c_stmt("RefDS(@);\n", Code[pc+3])
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    RefDS(_7120);
    Ref(_7020);
    _16c_stmt(_7120, _7020);
L13:
LF:

    // 	    CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	    SetBBType(Code[pc+3], SeqElem(Code[pc+1]), novalue, TYPE_OBJECT)
    DeRef(_7020);
    _7020 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7020 = (int)*(((s1_ptr)_2)->base + _7020);
    Ref(_7020);
    DeRef(_7022);
    _7022 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7022 = (int)*(((s1_ptr)_2)->base + _7022);
    Ref(_7022);
    Ref(_7022);
    _0 = _7022;
    _7022 = _18SeqElem(_7022);
    DeRef(_0);
    Ref(_7020);
    RefDS(_9novalue);
    _16SetBBType(_7020, _7022, _9novalue, 16);
LC:
L9:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure           
    DeRef(_7022);
    DeRef(_7020);
    DeRef(_7018);
    return 0;
    ;
}


int _18opNOP1()
{
    int _7129 = 0;
    int _0, _1, _2;
    

    //     if opcode = NOPWHILE then
    if (_18opcode != 160)
        goto L1;

    // 	in_loop = append(in_loop, 0)
    Append(&_18in_loop, _18in_loop, 0);
L1:

    //     Label(pc+1)
    DeRef(_7129);
    _7129 = _18pc + 1;
    if (_7129 > MAXINT)
        _7129 = NewDouble((double)_7129);
    Ref(_7129);
    _18Label(_7129);

    //     pc += 1
    _18pc = _18pc + 1;

    // end procedure
    DeRef(_7129);
    return 0;
    ;
}


int _18opINTERNAL_ERROR()
{
    int _0, _1, _2;
    

    //     InternalErr("This opcode should never be emitted!")
    RefDS(_7133);
    _6InternalErr(_7133);

    // end procedure
    return 0;
    ;
}


int _18opIF()
{
    int _7172 = 0;
    int _7149 = 0;
    int _7134 = 0;
    int _0, _1, _2;
    

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    Ref(_7134);
    _0 = _7134;
    _7134 = _16TypeIsNot(_7134, 1);
    DeRef(_0);
    if (_7134 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7134) && DBL_PTR(_7134)->dbl == 0.0)
            goto L1;
    }

    // 	if opcode = WHILE then
    if (_18opcode != 47)
        goto L2;

    // 	    c_stmt("if (@ <= 0) {\n", Code[pc+1]) -- quick test 
    DeRef(_7134);
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    RefDS(_7138);
    Ref(_7134);
    _16c_stmt(_7138, _7134);
L2:

    // 	c_stmt("if (@ == 0) {\n", Code[pc+1])
    DeRef(_7134);
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    RefDS(_7141);
    Ref(_7134);
    _16c_stmt(_7141, _7134);

    // 	Goto(Code[pc+2])
    DeRef(_7134);
    _7134 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    Ref(_7134);
    _18Goto(_7134);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	c_stmt("if (!IS_ATOM_INT(@) && DBL_PTR(@)->dbl == 0.0)\n", 
    DeRef(_7134);
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    DeRef(_7149);
    _7149 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7149 = (int)*(((s1_ptr)_2)->base + _7149);
    Ref(_7149);
    _0 = _7149;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7134;
    Ref(_7134);
    ((int *)_2)[2] = _7149;
    Ref(_7149);
    _7149 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7146);
    RefDS(_7149);
    _16c_stmt(_7146, _7149);

    // 	Goto(Code[pc+2])
    DeRefDS(_7149);
    _7149 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7149 = (int)*(((s1_ptr)_2)->base + _7149);
    Ref(_7149);
    Ref(_7149);
    _18Goto(_7149);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	if opcode = WHILE then
    if (_18opcode != 47)
        goto L3;

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L3:

    // 	pc += 3
    _18pc = _18pc + 3;
    goto L4;
L1:

    //     elsif ObjValue(Code[pc+1]) != NOVALUE and
    DeRef(_7149);
    _7149 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7149 = (int)*(((s1_ptr)_2)->base + _7149);
    Ref(_7149);
    Ref(_7149);
    _0 = _7149;
    _7149 = _16ObjValue(_7149);
    DeRef(_0);
    _0 = _7149;
    _7149 = binary_op(NOTEQ, _7149, _4NOVALUE);
    DeRef(_0);
    if (IS_ATOM_INT(_7149)) {
        if (_7149 == 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_7149)->dbl == 0.0) {
            goto L5;
        }
    }
    DeRef(_7134);
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    Ref(_7134);
    _0 = _7134;
    _7134 = _16ObjValue(_7134);
    DeRef(_0);
    _0 = _7134;
    if (IS_ATOM_INT(_7134)) {
        _7134 = (_7134 != 0);
    }
    else {
        _7134 = binary_op(NOTEQ, _7134, 0);
    }
    DeRef(_0);
L6:
    if (_7134 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_7134) && DBL_PTR(_7134)->dbl == 0.0)
            goto L5;
    }

    // 	pc += 3 -- if/while TRUE - skip the test and goto
    _18pc = _18pc + 3;
    goto L4;
L5:

    //     elsif ObjValue(Code[pc+1]) = NOVALUE or
    DeRef(_7134);
    _7134 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7134 = (int)*(((s1_ptr)_2)->base + _7134);
    Ref(_7134);
    Ref(_7134);
    _0 = _7134;
    _7134 = _16ObjValue(_7134);
    DeRef(_0);
    _0 = _7134;
    _7134 = binary_op(EQUALS, _7134, _4NOVALUE);
    DeRef(_0);
    if (IS_ATOM_INT(_7134)) {
        if (_7134 != 0) {
            goto L7;
        }
    }
    else {
        if (DBL_PTR(_7134)->dbl != 0.0) {
            goto L7;
        }
    }
    DeRef(_7149);
    _7149 = _18pc + 3;
    if ((long)((unsigned long)_7149 + (unsigned long)HIGH_BITS) >= 0) 
        _7149 = NewDouble((double)_7149);
    DeRef(_7172);
    _7172 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7172 = (int)*(((s1_ptr)_2)->base + _7172);
    Ref(_7172);
    _0 = _7172;
    if (IS_ATOM_INT(_7172)) {
        _7172 = _7172 - 1;
        if ((long)((unsigned long)_7172 +(unsigned long) HIGH_BITS) >= 0)
            _7172 = NewDouble((double)_7172);
    }
    else {
        _7172 = binary_op(MINUS, _7172, 1);
    }
    DeRef(_0);
    Ref(_7149);
    Ref(_7172);
    _0 = _7172;
    _7172 = _18forward_branch_into(_7149, _7172);
    DeRef(_0);
L8:
    if (_7172 == 0)
        goto L9;
L7:

    // 	if ObjValue(Code[pc+1]) != 0 then  -- non-zero handled above
    DeRef(_7172);
    _7172 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7172 = (int)*(((s1_ptr)_2)->base + _7172);
    Ref(_7172);
    Ref(_7172);
    _0 = _7172;
    _7172 = _16ObjValue(_7172);
    DeRef(_0);
    if (binary_op_a(EQUALS, _7172, 0))
        goto LA;

    // 	    c_stmt("if (@ == 0)\n", Code[pc+1])
    DeRef(_7172);
    _7172 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7172 = (int)*(((s1_ptr)_2)->base + _7172);
    Ref(_7172);
    RefDS(_7180);
    Ref(_7172);
    _16c_stmt(_7180, _7172);
LA:

    // 	Goto(Code[pc+2])
    DeRef(_7172);
    _7172 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7172 = (int)*(((s1_ptr)_2)->base + _7172);
    Ref(_7172);
    Ref(_7172);
    _18Goto(_7172);

    // 	pc += 3
    _18pc = _18pc + 3;
    goto L4;
L9:

    // 	pc = Code[pc+2]  -- if/while FALSE - skip the whole block
    DeRef(_7172);
    _7172 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _18pc = (int)*(((s1_ptr)_2)->base + _7172);
    if (!IS_ATOM_INT(_18pc))
        _18pc = (long)DBL_PTR(_18pc)->dbl;
L4:

    // end procedure               
    DeRef(_7172);
    DeRef(_7149);
    DeRef(_7134);
    return 0;
    ;
}


int _18opINTEGER_CHECK()
{
    int _7188 = 0;
    int _0, _1, _2;
    

    //     if BB_var_type(Code[pc+1]) != TYPE_INTEGER then
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    Ref(_7188);
    _0 = _7188;
    _7188 = _16BB_var_type(_7188);
    DeRef(_0);
    if (binary_op_a(EQUALS, _7188, 1))
        goto L1;

    // 	c_stmt("if (!IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_7188);
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    RefDS(_7192);
    Ref(_7188);
    _16c_stmt(_7192, _7188);

    // 	LeftSym = TRUE
    _16LeftSym = 1;

    // 	c_stmt("_1 = (long)(DBL_PTR(@)->dbl);\n", Code[pc+1])
    DeRef(_7188);
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    RefDS(_7195);
    Ref(_7188);
    _16c_stmt(_7195, _7188);

    // 	LeftSym = TRUE
    _16LeftSym = 1;

    // 	c_stmt("DeRefDS(@);\n", Code[pc+1])
    DeRef(_7188);
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    RefDS(_6121);
    Ref(_7188);
    _16c_stmt(_6121, _7188);

    // 	c_stmt("@ = _1;\n", Code[pc+1])
    DeRef(_7188);
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    RefDS(_7200);
    Ref(_7188);
    _16c_stmt(_7200, _7188);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	SetBBType(Code[pc+1], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_7188);
    _7188 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7188 = (int)*(((s1_ptr)_2)->base + _7188);
    Ref(_7188);
    Ref(_7188);
    RefDS(_9novalue);
    _16SetBBType(_7188, 1, _9novalue, 16);
L1:

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure           
    DeRef(_7188);
    return 0;
    ;
}


int _18opATOM_CHECK()
{
    int _0, _1, _2;
    

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure           
    return 0;
    ;
}


int _18opASSIGN_SUBS()
{
    int _7207 = 0;
    int _7212 = 0;
    int _0, _1, _2, _3;
    

    //     const_subs = -1
    _18const_subs = -1;

    //     CRef(Code[pc+3]) -- takes care of ASSIGN_SUBS_I
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    Ref(_7207);
    _18CRef(_7207);

    //     SymTab[Code[pc+3]][S_ONE_REF] = FALSE
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7207))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7207)->dbl));
    else
        _3 = (int)(_7207 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     if Code[pc+1] = Code[pc+3] then
    _7212 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    if (binary_op_a(NOTEQ, _7212, _7207))
        goto L1;

    // 	c_stmt("_0 = @;\n", Code[pc+3]) 
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7218);
    Ref(_7207);
    _16c_stmt(_7218, _7207);
L1:

    //     if opcode = PASSIGN_SUBS then
    if (_18opcode != 164)
        goto L2;

    // 	c_stmt0("_2 = (int)SEQ_PTR(*(int *)_3);\n")
    RefDS(_7035);
    _16c_stmt0(_7035);

    // 	c_stmt0("if (!UNIQUE(_2)) {\n")
    RefDS(_7222);
    _16c_stmt0(_7222);

    // 	c_stmt0("_2 = (int)SequenceCopy((s1_ptr)_2);\n")
    RefDS(_7223);
    _16c_stmt0(_7223);

    // 	c_stmt0("*(int *)_3 = MAKE_SEQ(_2);\n")
    RefDS(_7224);
    _16c_stmt0(_7224);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
    goto L3;
L2:

    // 	c_stmt("_2 = (int)SEQ_PTR(@);\n", Code[pc+1])
    DeRef(_7207);
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7036);
    Ref(_7207);
    _16c_stmt(_7036, _7207);

    // 	if SymTab[Code[pc+1]][S_ONE_REF] = FALSE then
    DeRef(_7207);
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    _0 = _7207;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_7207))
        _7207 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7207)->dbl));
    else
        _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    RefDS(_7207);
    DeRef(_0);
    _0 = _7207;
    _2 = (int)SEQ_PTR(_7207);
    _7207 = (int)*(((s1_ptr)_2)->base + 32);
    Ref(_7207);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _7207, 0))
        goto L4;

    // 	    c_stmt0("if (!UNIQUE(_2)) {\n")
    RefDS(_7222);
    _16c_stmt0(_7222);

    // 	    c_stmt0("_2 = (int)SequenceCopy((s1_ptr)_2);\n")
    RefDS(_7223);
    _16c_stmt0(_7223);

    // 	    c_stmt("@ = MAKE_SEQ(_2);\n", Code[pc+1])
    DeRef(_7207);
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7232);
    Ref(_7207);
    _16c_stmt(_7232, _7207);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L4:
L3:

    //     if TypeIsNot(Code[pc+2], TYPE_INTEGER) then
    DeRef(_7207);
    _7207 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    Ref(_7207);
    _0 = _7207;
    _7207 = _16TypeIsNot(_7207, 1);
    DeRef(_0);
    if (_7207 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_7207) && DBL_PTR(_7207)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt("if (!IS_ATOM_INT(@))\n", Code[pc+2])
    DeRef(_7207);
    _7207 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7046);
    Ref(_7207);
    _16c_stmt(_7046, _7207);

    // 	c_stmt("_2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(@)->dbl));\n", 
    DeRef(_7207);
    _7207 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7240);
    Ref(_7207);
    _16c_stmt(_7240, _7207);

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L5:

    //     c_stmt("_2 = (int)(((s1_ptr)_2)->base + @);\n", Code[pc+2])
    DeRef(_7207);
    _7207 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7243);
    Ref(_7207);
    _16c_stmt(_7243, _7207);

    //     if opcode = PASSIGN_SUBS then  
    if (_18opcode != 164)
        goto L6;

    // 	c_stmt0("_1 = *(int *)_2;\n")
    RefDS(_7247);
    _16c_stmt0(_7247);

    // 	if Code[pc+1] = Code[pc+3] then
    DeRef(_7207);
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    DeRef(_7212);
    _7212 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    if (binary_op_a(NOTEQ, _7207, _7212))
        goto L7;

    // 	    c_stmt0("*(int *)_2 = _0;\n")
    RefDS(_7253);
    _16c_stmt0(_7253);
    goto L8;
L7:

    // 	    c_stmt("*(int *)_2 = @;\n", Code[pc+3])
    DeRef(_7212);
    _7212 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    RefDS(_7254);
    Ref(_7212);
    _16c_stmt(_7254, _7212);
L8:

    // 	c_stmt0("DeRef(_1);\n")
    RefDS(_7257);
    _16c_stmt0(_7257);
    goto L9;
L6:

    // 	if SeqElem(Code[pc+1]) != TYPE_INTEGER then 
    DeRef(_7212);
    _7212 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    Ref(_7212);
    _0 = _7212;
    _7212 = _18SeqElem(_7212);
    DeRef(_0);
    if (_7212 == 1)
        goto LA;

    // 	    c_stmt0("_1 = *(int *)_2;\n")
    RefDS(_7247);
    _16c_stmt0(_7247);
LA:

    // 	if Code[pc+1] = Code[pc+3] then
    DeRef(_7212);
    _7212 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    if (binary_op_a(NOTEQ, _7212, _7207))
        goto LB;

    // 	    c_stmt0("*(int *)_2 = _0;\n")
    RefDS(_7253);
    _16c_stmt0(_7253);
    goto LC;
LB:

    // 	    c_stmt("*(int *)_2 = @;\n", Code[pc+3])
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    RefDS(_7254);
    Ref(_7207);
    _16c_stmt(_7254, _7207);
LC:

    // 	if SeqElem(Code[pc+1]) != TYPE_INTEGER then
    DeRef(_7207);
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    Ref(_7207);
    _0 = _7207;
    _7207 = _18SeqElem(_7207);
    DeRef(_0);
    if (_7207 == 1)
        goto LD;

    // 	    if SeqElem(Code[pc+1]) = TYPE_OBJECT or
    _7207 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    Ref(_7207);
    _0 = _7207;
    _7207 = _18SeqElem(_7207);
    DeRef(_0);
    _7207 = (_7207 == 16);
    if (_7207 != 0) {
        goto LE;
    }
    DeRef(_7212);
    _7212 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    Ref(_7212);
    _0 = _7212;
    _7212 = _18SeqElem(_7212);
    DeRef(_0);
    _7212 = (_7212 == 4);
LF:
    if (_7212 == 0)
        goto L10;
LE:

    // 		c_stmt0("DeRef(_1);\n")
    RefDS(_7257);
    _16c_stmt0(_7257);
    goto L11;
L10:

    // 		c_stmt0("DeRefDS(_1);\n")
    RefDS(_7282);
    _16c_stmt0(_7282);
L11:
LD:

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

    // 	SetBBType(Code[pc+1], TYPE_SEQUENCE, target, GType(Code[pc+3]))
    DeRef(_7212);
    _7212 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7212 = (int)*(((s1_ptr)_2)->base + _7212);
    Ref(_7212);
    DeRef(_7207);
    _7207 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7207 = (int)*(((s1_ptr)_2)->base + _7207);
    Ref(_7207);
    Ref(_7207);
    _0 = _7207;
    _7207 = _16GType(_7207);
    DeRef(_0);
    Ref(_7212);
    RefDS(_18target);
    _16SetBBType(_7212, 8, _18target, _7207);
L9:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_7207);
    DeRef(_7212);
    return 0;
    ;
}


int _18opLENGTH()
{
    int _7289 = 0;
    int _7291 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _7289 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    _7291 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7291 = (int)*(((s1_ptr)_2)->base + _7291);
    Ref(_7291);
    RefDS(_5774);
    Ref(_7289);
    Ref(_7291);
    _18CSaveStr(_5774, _7289, _7291, 0, 0);

    //     if opcode = LENGTH and 
    DeRef(_7291);
    _7291 = (_18opcode == 42);
    if (_7291 == 0) {
        goto L1;
    }
    DeRef(_7289);
    _7289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    Ref(_7289);
    RefDS(_4094);
    _0 = _7289;
    _7289 = _16TypeIs(_7289, _4094);
    DeRef(_0);
L2:
    if (_7289 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_7289) && DBL_PTR(_7289)->dbl == 0.0)
            goto L1;
    }

    // 	if SeqLen(Code[pc+1]) != NOVALUE then
    DeRef(_7289);
    _7289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    Ref(_7289);
    _0 = _7289;
    _7289 = _18SeqLen(_7289);
    DeRef(_0);
    if (binary_op_a(EQUALS, _7289, _4NOVALUE))
        goto L3;

    // 	    c_stmt("@ = ", Code[pc+2])
    DeRef(_7289);
    _7289 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    RefDS(_5789);
    Ref(_7289);
    _16c_stmt(_5789, _7289);

    // 	    c_printf("%d;\n", SeqLen(Code[pc+1]))
    DeRef(_7289);
    _7289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    Ref(_7289);
    _0 = _7289;
    _7289 = _18SeqLen(_7289);
    DeRef(_0);
    RefDS(_5980);
    Ref(_7289);
    _9c_printf(_5980, _7289);

    // 	    target = repeat(SeqLen(Code[pc+1]), 2)
    DeRef(_7289);
    _7289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    Ref(_7289);
    _0 = _7289;
    _7289 = _18SeqLen(_7289);
    DeRef(_0);
    DeRef(_18target);
    _18target = Repeat(_7289, 2);
    goto L4;
L3:

    // 	    c_stmt("@ = SEQ_PTR(@)->length;\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7289);
    _7289 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    DeRef(_7291);
    _7291 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7291 = (int)*(((s1_ptr)_2)->base + _7291);
    Ref(_7291);
    _0 = _7291;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7289;
    Ref(_7289);
    ((int *)_2)[2] = _7291;
    Ref(_7291);
    _7291 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7311);
    RefDS(_7291);
    _16c_stmt(_7311, _7291);

    // 	    target = {0, MAXLEN}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1072741823;
    _18target = MAKE_SEQ(_1);
L4:

    // 	CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_7291);
    _7291 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7291 = (int)*(((s1_ptr)_2)->base + _7291);
    Ref(_7291);
    Ref(_7291);
    RefDS(_18target);
    _16SetBBType(_7291, 1, _18target, 16);
    goto L5;
L1:

    // 	if opcode = PLENGTH then
    if (_18opcode != 162)
        goto L6;

    // 	    c_stmt("@ = SEQ_PTR(*(object_ptr)_3)->length;\n", Code[pc+2])
    DeRef(_7291);
    _7291 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7291 = (int)*(((s1_ptr)_2)->base + _7291);
    Ref(_7291);
    RefDS(_7321);
    Ref(_7291);
    _16c_stmt(_7321, _7291);
    goto L7;
L6:

    // 	    c_stmt("@ = SEQ_PTR(@)->length;\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7291);
    _7291 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7291 = (int)*(((s1_ptr)_2)->base + _7291);
    Ref(_7291);
    DeRef(_7289);
    _7289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    _0 = _7289;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7291;
    Ref(_7291);
    ((int *)_2)[2] = _7289;
    Ref(_7289);
    _7289 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7311);
    RefDS(_7289);
    _16c_stmt(_7311, _7289);
L7:

    // 	CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    // 	SetBBType(Code[pc+2], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_7289);
    _7289 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7289 = (int)*(((s1_ptr)_2)->base + _7289);
    Ref(_7289);
    Ref(_7289);
    RefDS(_9novalue);
    _16SetBBType(_7289, 1, _9novalue, 16);
L5:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7289);
    DeRef(_7291);
    return 0;
    ;
}


int _18opASSIGN()
{
    int _7337 = 0;
    int _7332 = 0;
    int _7390 = 0;
    int _0, _1, _2, _3;
    

    //     CRef(Code[pc+1])
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    Ref(_7332);
    _18CRef(_7332);

    //     SymTab[Code[pc+1]][S_ONE_REF] = FALSE
    DeRef(_7332);
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7332))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7332)->dbl));
    else
        _3 = (int)(_7332 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     SymTab[Code[pc+2]][S_ONE_REF] = FALSE
    _7337 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7337))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7337)->dbl));
    else
        _3 = (int)(_7337 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     if SymTab[Code[pc+2]][S_MODE] = M_CONSTANT then
    DeRef(_7332);
    _7332 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    _0 = _7332;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_7332))
        _7332 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7332)->dbl));
    else
        _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    RefDS(_7332);
    DeRef(_0);
    _0 = _7332;
    _2 = (int)SEQ_PTR(_7332);
    _7332 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_7332);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _7332, 2))
        goto L1;

    // 	if SymTab[Code[pc+1]][S_MODE] != M_CONSTANT or
    DeRef(_7332);
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    _0 = _7332;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_7332))
        _7332 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7332)->dbl));
    else
        _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    RefDS(_7332);
    DeRef(_0);
    _0 = _7332;
    _2 = (int)SEQ_PTR(_7332);
    _7332 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_7332);
    DeRefDS(_0);
    _0 = _7332;
    if (IS_ATOM_INT(_7332)) {
        _7332 = (_7332 != 2);
    }
    else {
        _7332 = binary_op(NOTEQ, _7332, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7332)) {
        if (_7332 != 0) {
            DeRef(_7332);
            _7332 = 1;
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_7332)->dbl != 0.0) {
            DeRef(_7332);
            _7332 = 1;
            goto L2;
        }
    }
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    Ref(_7337);
    _0 = _7337;
    _7337 = _16TypeIsNot(_7337, 1);
    DeRef(_0);
    DeRef(_7332);
    if (IS_ATOM_INT(_7337))
        _7332 = (_7337 != 0);
    else
        _7332 = DBL_PTR(_7337)->dbl != 0.0;
L2:
    if (_7332 != 0) {
        goto L3;
    }
    DeRef(_7332);
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    Ref(_7332);
    _0 = _7332;
    _7332 = _16ObjValue(_7332);
    DeRef(_0);
    _0 = _7332;
    if (IS_ATOM_INT(_7332))
        _7332 = 1;
    else if (IS_ATOM_DBL(_7332))
        _7332 = IS_ATOM_INT(DoubleToInt(_7332));
    else
        _7332 = 0;
    DeRef(_0);
    _7332 = (_7332 == 0);
L4:
    if (_7332 == 0)
        goto L5;
L3:

    // 	    c_stmt("@ = @;\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7332);
    _7332 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    _0 = _7337;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7332;
    Ref(_7332);
    ((int *)_2)[2] = _7337;
    Ref(_7337);
    _7337 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7362);
    RefDS(_7337);
    _16c_stmt(_7362, _7337);
    goto L6;
L5:

    // 	    SymTab[Code[pc+2]][S_USAGE] = U_DELETED
    DeRef(_7337);
    _7337 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7337))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7337)->dbl));
    else
        _3 = (int)(_7337 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 5);
    _1 = *(int *)_2;
    *(int *)_2 = 99;
    DeRef(_1);
L7:
    goto L6;
L1:

    // 	CDeRef(Code[pc+2])
    DeRef(_7332);
    _7332 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    Ref(_7332);
    _18CDeRef(_7332);

    // 	c_stmt("@ = @;\n", {Code[pc+2], Code[pc+1]})
    DeRef(_7332);
    _7332 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    _0 = _7337;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7332;
    Ref(_7332);
    ((int *)_2)[2] = _7337;
    Ref(_7337);
    _7337 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7362);
    RefDS(_7337);
    _16c_stmt(_7362, _7337);
L6:

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    Ref(_7337);
    RefDS(_4094);
    _0 = _7337;
    _7337 = _16TypeIs(_7337, _4094);
    DeRef(_0);
    if (_7337 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_7337) && DBL_PTR(_7337)->dbl == 0.0)
            goto L8;
    }

    // 	target[MIN] = SeqLen(Code[pc+1])
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    Ref(_7337);
    _0 = _7337;
    _7337 = _18SeqLen(_7337);
    DeRef(_0);
    Ref(_7337);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7337;
    DeRef(_1);

    // 	SetBBType(Code[pc+2], GType(Code[pc+1]), target, SeqElem(Code[pc+1]))
    DeRef(_7337);
    _7337 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    DeRef(_7332);
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    Ref(_7332);
    _0 = _7332;
    _7332 = _16GType(_7332);
    DeRef(_0);
    DeRef(_7390);
    _7390 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7390 = (int)*(((s1_ptr)_2)->base + _7390);
    Ref(_7390);
    Ref(_7390);
    _0 = _7390;
    _7390 = _18SeqElem(_7390);
    DeRef(_0);
    Ref(_7337);
    RefDS(_18target);
    _16SetBBType(_7337, _7332, _18target, _7390);
    goto L9;
L8:

    // 	SetBBType(Code[pc+2], GType(Code[pc+1]), ObjMinMax(Code[pc+1]),
    DeRef(_7390);
    _7390 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7390 = (int)*(((s1_ptr)_2)->base + _7390);
    Ref(_7390);
    DeRef(_7332);
    _7332 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7332 = (int)*(((s1_ptr)_2)->base + _7332);
    Ref(_7332);
    Ref(_7332);
    _0 = _7332;
    _7332 = _16GType(_7332);
    DeRef(_0);
    DeRef(_7337);
    _7337 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7337 = (int)*(((s1_ptr)_2)->base + _7337);
    Ref(_7337);
    Ref(_7337);
    _0 = _7337;
    _7337 = _18ObjMinMax(_7337);
    DeRef(_0);
    Ref(_7390);
    RefDS(_7337);
    _16SetBBType(_7390, _7332, _7337, 16);
L9:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_7337);
    DeRef(_7332);
    DeRef(_7390);
    return 0;
    ;
}


int _18opASSIGN_I()
{
    int _7402 = 0;
    int _7404 = 0;
    int _0, _1, _2;
    

    //     c_stmt("@ = @;\n", {Code[pc+2], Code[pc+1]})
    _7402 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7402 = (int)*(((s1_ptr)_2)->base + _7402);
    Ref(_7402);
    _7404 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7404 = (int)*(((s1_ptr)_2)->base + _7404);
    Ref(_7404);
    _0 = _7404;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _7402;
    Ref(_7402);
    ((int *)_2)[2] = _7404;
    Ref(_7404);
    _7404 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_7362);
    RefDS(_7404);
    _16c_stmt(_7362, _7404);

    //     SetBBType(Code[pc+2], TYPE_INTEGER, ObjMinMax(Code[pc+1]), TYPE_OBJECT)
    DeRefDS(_7404);
    _7404 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7404 = (int)*(((s1_ptr)_2)->base + _7404);
    Ref(_7404);
    DeRef(_7402);
    _7402 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7402 = (int)*(((s1_ptr)_2)->base + _7402);
    Ref(_7402);
    Ref(_7402);
    _0 = _7402;
    _7402 = _18ObjMinMax(_7402);
    DeRef(_0);
    Ref(_7404);
    RefDS(_7402);
    _16SetBBType(_7404, 1, _7402, 16);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_7402);
    DeRef(_7404);
    return 0;
    ;
}


int _18opEXIT()
{
    int _7413 = 0;
    int _0, _1, _2;
    

    //     if opcode = ENDWHILE then
    if (_18opcode != 22)
        goto L1;

    // 	in_loop = in_loop[1..length(in_loop)-1]
    _7413 = SEQ_PTR(_18in_loop)->length;
    _7413 = _7413 - 1;
    rhs_slice_target = (object_ptr)&_18in_loop;
    RHS_Slice((s1_ptr)_18in_loop, 1, _7413);
L1:

    //     Goto(Code[pc+1])               
    DeRef(_7413);
    _7413 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7413 = (int)*(((s1_ptr)_2)->base + _7413);
    Ref(_7413);
    Ref(_7413);
    _18Goto(_7413);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_7413);
    return 0;
    ;
}


int _18opRIGHT_BRACE_N()
{
    int _7446 = 0;
    int _7420 = 0;
    int _7430 = 0;
    int _0, _1, _2, _3;
    

    //     len = Code[pc+1]+2
    _7420 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    DeRef(_18len);
    if (IS_ATOM_INT(_7420)) {
        _18len = _7420 + 2;
        if ((long)((unsigned long)_18len + (unsigned long)HIGH_BITS) >= 0) 
            _18len = NewDouble((double)_18len);
    }
    else {
        _18len = binary_op(PLUS, _7420, 2);
    }

    //     if Code[pc+1] = 0 then
    DeRef(_7420);
    _7420 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    if (binary_op_a(NOTEQ, _7420, 0))
        goto L1;

    // 	CSaveStr("_0", Code[pc+len], 0, 0, 0) -- no need to delay DeRef
    DeRef(_7420);
    if (IS_ATOM_INT(_18len)) {
        _7420 = _18pc + _18len;
    }
    else {
        _7420 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
    }
    _0 = _7420;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_7420))
        _7420 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7420)->dbl));
    else
        _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    DeRef(_0);
    RefDS(_5774);
    Ref(_7420);
    _18CSaveStr(_5774, _7420, 0, 0, 0);
    goto L2;
L1:

    // 	CSaveStr("_0", Code[pc+len], Code[pc+len], 0, 0) 
    DeRef(_7420);
    if (IS_ATOM_INT(_18len)) {
        _7420 = _18pc + _18len;
    }
    else {
        _7420 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
    }
    _0 = _7420;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_7420))
        _7420 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7420)->dbl));
    else
        _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    DeRef(_0);
    DeRef(_7430);
    if (IS_ATOM_INT(_18len)) {
        _7430 = _18pc + _18len;
    }
    else {
        _7430 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
    }
    _0 = _7430;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_7430))
        _7430 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7430)->dbl));
    else
        _7430 = (int)*(((s1_ptr)_2)->base + _7430);
    Ref(_7430);
    DeRef(_0);
    RefDS(_5774);
    Ref(_7420);
    Ref(_7430);
    _18CSaveStr(_5774, _7420, _7430, 0, 0);
L2:

    //     c_stmt0("_1 = NewS1(")
    RefDS(_7432);
    _16c_stmt0(_7432);

    //     c_printf("%d);\n", Code[pc+1])
    DeRef(_7430);
    _7430 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7430 = (int)*(((s1_ptr)_2)->base + _7430);
    Ref(_7430);
    RefDS(_7433);
    Ref(_7430);
    _9c_printf(_7433, _7430);

    //     if Code[pc+1] > 0 then
    DeRef(_7430);
    _7430 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7430 = (int)*(((s1_ptr)_2)->base + _7430);
    Ref(_7430);
    if (binary_op_a(LESSEQ, _7430, 0))
        goto L3;

    // 	c_stmt0("_2 = (int)((s1_ptr)_1)->base;\n")
    RefDS(_7439);
    _16c_stmt0(_7439);
L3:

    //     n = 0 -- repeat count
    _18n = 0;

    //     for i = 1 to Code[pc+1] do
    DeRef(_7430);
    _7430 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7430 = (int)*(((s1_ptr)_2)->base + _7430);
    Ref(_7430);
    { int _i;
        _i = 1;
L4:
        if (binary_op_a(GREATER, _i, _7430))
            goto L5;

        // 	t = Code[pc+len-i]
        DeRef(_7420);
        if (IS_ATOM_INT(_18len)) {
            _7420 = _18pc + _18len;
            if ((long)((unsigned long)_7420 + (unsigned long)HIGH_BITS) >= 0) 
                _7420 = NewDouble((double)_7420);
        }
        else {
            _7420 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
        }
        _0 = _7420;
        if (IS_ATOM_INT(_7420) && IS_ATOM_INT(_i)) {
            _7420 = _7420 - _i;
        }
        else {
            if (IS_ATOM_INT(_7420)) {
                _7420 = NewDouble((double)_7420 - DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _7420 = NewDouble(DBL_PTR(_7420)->dbl - (double)_i);
                }
                else
                    _7420 = NewDouble(DBL_PTR(_7420)->dbl - DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_7420))
            _18t = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7420)->dbl));
        else
            _18t = (int)*(((s1_ptr)_2)->base + _7420);
        if (!IS_ATOM_INT(_18t))
            _18t = (long)DBL_PTR(_18t)->dbl;

        // 	SymTab[t][S_ONE_REF] = FALSE
        _2 = (int)SEQ_PTR(_4SymTab);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _4SymTab = MAKE_SEQ(_2);
        }
        _3 = (int)(_18t + ((s1_ptr)_2)->base);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 32);
        _1 = *(int *)_2;
        *(int *)_2 = 0;
        DeRef(_1);

        // 	if i < Code[pc+1] and t = Code[pc+len-i-1] then
        DeRef(_7446);
        _7446 = _18pc + 1;
        _2 = (int)SEQ_PTR(_4Code);
        _7446 = (int)*(((s1_ptr)_2)->base + _7446);
        Ref(_7446);
        _0 = _7446;
        if (IS_ATOM_INT(_i) && IS_ATOM_INT(_7446)) {
            _7446 = (_i < _7446);
        }
        else {
            _7446 = binary_op(LESS, _i, _7446);
        }
        DeRef(_0);
        if (IS_ATOM_INT(_7446)) {
            if (_7446 == 0) {
                goto L6;
            }
        }
        else {
            if (DBL_PTR(_7446)->dbl == 0.0) {
                goto L6;
            }
        }
        DeRef(_7420);
        if (IS_ATOM_INT(_18len)) {
            _7420 = _18pc + _18len;
            if ((long)((unsigned long)_7420 + (unsigned long)HIGH_BITS) >= 0) 
                _7420 = NewDouble((double)_7420);
        }
        else {
            _7420 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
        }
        _0 = _7420;
        if (IS_ATOM_INT(_7420) && IS_ATOM_INT(_i)) {
            _7420 = _7420 - _i;
            if ((long)((unsigned long)_7420 +(unsigned long) HIGH_BITS) >= 0)
                _7420 = NewDouble((double)_7420);
        }
        else {
            if (IS_ATOM_INT(_7420)) {
                _7420 = NewDouble((double)_7420 - DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _7420 = NewDouble(DBL_PTR(_7420)->dbl - (double)_i);
                }
                else
                    _7420 = NewDouble(DBL_PTR(_7420)->dbl - DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _7420;
        if (IS_ATOM_INT(_7420)) {
            _7420 = _7420 - 1;
        }
        else {
            _7420 = NewDouble(DBL_PTR(_7420)->dbl - (double)1);
        }
        DeRef(_0);
        _0 = _7420;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_7420))
            _7420 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7420)->dbl));
        else
            _7420 = (int)*(((s1_ptr)_2)->base + _7420);
        Ref(_7420);
        DeRef(_0);
        _0 = _7420;
        if (IS_ATOM_INT(_7420)) {
            _7420 = (_18t == _7420);
        }
        else {
            _7420 = binary_op(EQUALS, _18t, _7420);
        }
        DeRef(_0);
L7:
        if (_7420 == 0) {
            goto L6;
        }
        else {
            if (!IS_ATOM_INT(_7420) && DBL_PTR(_7420)->dbl == 0.0)
                goto L6;
        }

        // 	    n += 1   -- same as the next one
        _18n = _18n + 1;
        goto L8;
L6:

        // 	    if n <= 6 then
        if (_18n > 6)
            goto L9;

        // 		if n > 0 then
        if (_18n <= 0)
            goto LA;

        // 		    CRefn(t, n+1)
        DeRef(_7420);
        _7420 = _18n + 1;
        if (_7420 > MAXINT)
            _7420 = NewDouble((double)_7420);
        Ref(_7420);
        _18CRefn(_18t, _7420);
        goto LB;
LA:

        // 		    CRef(t)
        _18CRef(_18t);
LB:

        // 		while n >= 0 do
LC:
        if (_18n < 0)
            goto LD;

        // 		    c_stmt0("*((int *)(_2")
        RefDS(_7461);
        _16c_stmt0(_7461);

        // 		    c_printf("+%d", (i-n)*4)
        DeRef(_7420);
        if (IS_ATOM_INT(_i)) {
            _7420 = _i - _18n;
            if ((long)((unsigned long)_7420 +(unsigned long) HIGH_BITS) >= 0)
                _7420 = NewDouble((double)_7420);
        }
        else {
            _7420 = NewDouble(DBL_PTR(_i)->dbl - (double)_18n);
        }
        _0 = _7420;
        if (IS_ATOM_INT(_7420)) {
            if (_7420 == (short)_7420)
                _7420 = _7420 * 4;
            else
                _7420 = NewDouble(_7420 * (double)4);
        }
        else {
            _7420 = NewDouble(DBL_PTR(_7420)->dbl * (double)4);
        }
        DeRef(_0);
        RefDS(_7462);
        Ref(_7420);
        _9c_printf(_7462, _7420);

        // 		    c_puts("))")
        RefDS(_7465);
        _9c_puts(_7465);

        // 		    temp_indent = -indent
        _9temp_indent = - _9indent;

        // 		    c_stmt(" = @;\n", t)
        RefDS(_7467);
        _16c_stmt(_7467, _18t);

        // 		    n -= 1
        _18n = _18n - 1;

        // 		end while
        goto LC;
LE:
        goto LD;
L9:

        // 		c_stmt0("RepeatElem(_2")  -- does Refs too
        RefDS(_7469);
        _16c_stmt0(_7469);

        // 		temp_indent = -indent
        _9temp_indent = - _9indent;

        // 		c_printf("+%d,", (i-n)*4)
        DeRef(_7420);
        if (IS_ATOM_INT(_i)) {
            _7420 = _i - _18n;
            if ((long)((unsigned long)_7420 +(unsigned long) HIGH_BITS) >= 0)
                _7420 = NewDouble((double)_7420);
        }
        else {
            _7420 = NewDouble(DBL_PTR(_i)->dbl - (double)_18n);
        }
        _0 = _7420;
        if (IS_ATOM_INT(_7420)) {
            if (_7420 == (short)_7420)
                _7420 = _7420 * 4;
            else
                _7420 = NewDouble(_7420 * (double)4);
        }
        else {
            _7420 = NewDouble(DBL_PTR(_7420)->dbl * (double)4);
        }
        DeRef(_0);
        RefDS(_7471);
        Ref(_7420);
        _9c_printf(_7471, _7420);

        // 		temp_indent = -indent
        _9temp_indent = - _9indent;

        // 		c_stmt(" @, ", t)
        RefDS(_7475);
        _16c_stmt(_7475, _18t);

        // 		c_printf("%d);\n", n+1)
        DeRef(_7420);
        _7420 = _18n + 1;
        if (_7420 > MAXINT)
            _7420 = NewDouble((double)_7420);
        RefDS(_7433);
        Ref(_7420);
        _9c_printf(_7433, _7420);
LD:

        // 	    n = 0
        _18n = 0;
L8:

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
        goto L4;
L5:
        ;
        DeRef(_i);
    }

    //     c_stmt("@ = MAKE_SEQ(_1);\n", Code[pc+len])
    DeRef(_7420);
    if (IS_ATOM_INT(_18len)) {
        _7420 = _18pc + _18len;
    }
    else {
        _7420 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
    }
    _0 = _7420;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_7420))
        _7420 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7420)->dbl));
    else
        _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    DeRef(_0);
    RefDS(_7477);
    Ref(_7420);
    _16c_stmt(_7477, _7420);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     t = TYPE_NULL
    _18t = 0;

    //     for i = 1 to Code[pc+1] do
    DeRef(_7420);
    _7420 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7420 = (int)*(((s1_ptr)_2)->base + _7420);
    Ref(_7420);
    { int _i;
        _i = 1;
LF:
        if (binary_op_a(GREATER, _i, _7420))
            goto L10;

        // 	t = or_type(t, GType(Code[pc+len-i]))
        DeRef(_7446);
        if (IS_ATOM_INT(_18len)) {
            _7446 = _18pc + _18len;
            if ((long)((unsigned long)_7446 + (unsigned long)HIGH_BITS) >= 0) 
                _7446 = NewDouble((double)_7446);
        }
        else {
            _7446 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
        }
        _0 = _7446;
        if (IS_ATOM_INT(_7446) && IS_ATOM_INT(_i)) {
            _7446 = _7446 - _i;
        }
        else {
            if (IS_ATOM_INT(_7446)) {
                _7446 = NewDouble((double)_7446 - DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _7446 = NewDouble(DBL_PTR(_7446)->dbl - (double)_i);
                }
                else
                    _7446 = NewDouble(DBL_PTR(_7446)->dbl - DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _7446;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_7446))
            _7446 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7446)->dbl));
        else
            _7446 = (int)*(((s1_ptr)_2)->base + _7446);
        Ref(_7446);
        DeRef(_0);
        Ref(_7446);
        _0 = _7446;
        _7446 = _16GType(_7446);
        DeRef(_0);
        _0 = _16or_type(_18t, _7446);
        _18t = _0;

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
        goto LF;
L10:
        ;
        DeRef(_i);
    }

    //     target[MIN] = Code[pc+1]
    DeRef(_7446);
    _7446 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7446 = (int)*(((s1_ptr)_2)->base + _7446);
    Ref(_7446);
    Ref(_7446);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _7446;
    DeRef(_1);

    //     SetBBType(Code[pc+len], TYPE_SEQUENCE, target, t)
    DeRef(_7446);
    if (IS_ATOM_INT(_18len)) {
        _7446 = _18pc + _18len;
    }
    else {
        _7446 = NewDouble((double)_18pc + DBL_PTR(_18len)->dbl);
    }
    _0 = _7446;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_7446))
        _7446 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_7446)->dbl));
    else
        _7446 = (int)*(((s1_ptr)_2)->base + _7446);
    Ref(_7446);
    DeRef(_0);
    Ref(_7446);
    RefDS(_18target);
    _16SetBBType(_7446, 8, _18target, _18t);

    //     pc += 3 + Code[pc+1]
    DeRef(_7446);
    _7446 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7446 = (int)*(((s1_ptr)_2)->base + _7446);
    Ref(_7446);
    _0 = _7446;
    if (IS_ATOM_INT(_7446)) {
        _7446 = 3 + _7446;
        if ((long)((unsigned long)_7446 + (unsigned long)HIGH_BITS) >= 0) 
            _7446 = NewDouble((double)_7446);
    }
    else {
        _7446 = binary_op(PLUS, 3, _7446);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_7446)) {
        _18pc = _18pc + _7446;
    }
    else {
        _18pc = binary_op(PLUS, _18pc, _7446);
    }
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_7446);
    DeRef(_7420);
    DeRef(_7430);
    return 0;
    ;
}


int _18opRIGHT_BRACE_2()
{
    int _7495 = 0;
    int _7497 = 0;
    int _7499 = 0;
    int _0, _1, _2, _3;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _7495 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7495 = (int)*(((s1_ptr)_2)->base + _7495);
    Ref(_7495);
    _7497 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7497 = (int)*(((s1_ptr)_2)->base + _7497);
    Ref(_7497);
    _7499 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    RefDS(_5774);
    Ref(_7495);
    Ref(_7497);
    Ref(_7499);
    _18CSaveStr(_5774, _7495, _7497, _7499, 0);

    //     c_stmt0("_1 = NewS1(2);\n")
    RefDS(_7501);
    _16c_stmt0(_7501);

    //     c_stmt0("_2 = (int)((s1_ptr)_1)->base;\n")
    RefDS(_7439);
    _16c_stmt0(_7439);

    //     c_stmt("((int *)_2)[1] = @;\n", Code[pc+2])
    DeRef(_7499);
    _7499 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    RefDS(_7502);
    Ref(_7499);
    _16c_stmt(_7502, _7499);

    //     CRef(Code[pc+2])
    DeRef(_7499);
    _7499 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    Ref(_7499);
    _18CRef(_7499);

    //     SymTab[Code[pc+2]][S_ONE_REF] = FALSE
    DeRef(_7499);
    _7499 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7499))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7499)->dbl));
    else
        _3 = (int)(_7499 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     c_stmt("((int *)_2)[2] = @;\n", Code[pc+1])
    DeRef(_7497);
    _7497 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7497 = (int)*(((s1_ptr)_2)->base + _7497);
    Ref(_7497);
    RefDS(_7511);
    Ref(_7497);
    _16c_stmt(_7511, _7497);

    //     CRef(Code[pc+1])
    DeRef(_7497);
    _7497 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7497 = (int)*(((s1_ptr)_2)->base + _7497);
    Ref(_7497);
    Ref(_7497);
    _18CRef(_7497);

    //     SymTab[Code[pc+1]][S_ONE_REF] = FALSE
    DeRef(_7497);
    _7497 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7497 = (int)*(((s1_ptr)_2)->base + _7497);
    Ref(_7497);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_7497))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_7497)->dbl));
    else
        _3 = (int)(_7497 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     c_stmt("@ = MAKE_SEQ(_1);\n", Code[pc+3])
    DeRef(_7499);
    _7499 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    RefDS(_7477);
    Ref(_7499);
    _16c_stmt(_7477, _7499);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target[MIN] = 2
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    //     SetBBType(Code[pc+3], TYPE_SEQUENCE, target, 
    DeRef(_7499);
    _7499 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _7499 = (int)*(((s1_ptr)_2)->base + _7499);
    Ref(_7499);
    DeRef(_7497);
    _7497 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _7497 = (int)*(((s1_ptr)_2)->base + _7497);
    Ref(_7497);
    Ref(_7497);
    _0 = _7497;
    _7497 = _16GType(_7497);
    DeRef(_0);
    DeRef(_7495);
    _7495 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _7495 = (int)*(((s1_ptr)_2)->base + _7495);
    Ref(_7495);
    Ref(_7495);
    _0 = _7495;
    _7495 = _16GType(_7495);
    DeRef(_0);
    _7495 = _16or_type(_7497, _7495);
    Ref(_7499);
    RefDS(_18target);
    _16SetBBType(_7499, 8, _18target, _7495);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_7499);
    return 0;
    ;
}


