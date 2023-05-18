// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opRETURNP()
{
    int _8977 = 0;
    int _8976 = 0;
    int _0, _1, _2;
    

    //     for i = 1 to length(in_loop) do
    _8976 = SEQ_PTR(_18in_loop)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _8976)
            goto L2;

        // 	if in_loop[i] != 0 then
        DeRef(_8977);
        _2 = (int)SEQ_PTR(_18in_loop);
        _8977 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8977);
        if (binary_op_a(EQUALS, _8977, 0))
            goto L3;

        // 	    CDeRef(in_loop[i])
        DeRef(_8977);
        _2 = (int)SEQ_PTR(_18in_loop);
        _8977 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_8977);
        Ref(_8977);
        _18CDeRef(_8977);
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     sub = Code[pc+1]
    DeRef(_8977);
    _8977 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _18sub = (int)*(((s1_ptr)_2)->base + _8977);
    if (!IS_ATOM_INT(_18sub))
        _18sub = (long)DBL_PTR(_18sub)->dbl;

    //     sym = SymTab[sub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sub);
    RefDS(_8977);
    _2 = (int)SEQ_PTR(_8977);
    _18sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_18sym))
        _18sym = (long)DBL_PTR(_18sym)->dbl;

    //     while sym != 0 and SymTab[sym][S_SCOPE] <= SC_PRIVATE do
L4:
    DeRef(_8977);
    _8977 = (_18sym != 0);
    if (_8977 == 0) {
        goto L5;
    }
    DeRef(_8976);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8976 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8976);
    _0 = _8976;
    _2 = (int)SEQ_PTR(_8976);
    _8976 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8976);
    DeRefDS(_0);
    _0 = _8976;
    if (IS_ATOM_INT(_8976)) {
        _8976 = (_8976 <= 3);
    }
    else {
        _8976 = binary_op(LESSEQ, _8976, 3);
    }
    DeRef(_0);
L6:
    if (_8976 <= 0) {
        if (_8976 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_8976) && DBL_PTR(_8976)->dbl == 0.0)
                goto L5;
        }
    }

    // 	if SymTab[sym][S_SCOPE] != SC_LOOP_VAR and
    DeRef(_8976);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8976 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8976);
    _0 = _8976;
    _2 = (int)SEQ_PTR(_8976);
    _8976 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8976);
    DeRefDS(_0);
    _0 = _8976;
    if (IS_ATOM_INT(_8976)) {
        _8976 = (_8976 != 2);
    }
    else {
        _8976 = binary_op(NOTEQ, _8976, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_8976)) {
        if (_8976 == 0) {
            goto L7;
        }
    }
    else {
        if (DBL_PTR(_8976)->dbl == 0.0) {
            goto L7;
        }
    }
    DeRef(_8977);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8977);
    _0 = _8977;
    _2 = (int)SEQ_PTR(_8977);
    _8977 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8977);
    DeRefDS(_0);
    _0 = _8977;
    if (IS_ATOM_INT(_8977)) {
        _8977 = (_8977 != 4);
    }
    else {
        _8977 = binary_op(NOTEQ, _8977, 4);
    }
    DeRef(_0);
L8:
    if (_8977 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_8977) && DBL_PTR(_8977)->dbl == 0.0)
            goto L7;
    }

    // 	    CDeRef(sym)
    _18CDeRef(_18sym);
L7:

    // 	sym = SymTab[sym][S_NEXT]
    DeRef(_8977);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8977);
    _2 = (int)SEQ_PTR(_8977);
    _18sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_18sym))
        _18sym = (long)DBL_PTR(_18sym)->dbl;

    //     end while
    goto L4;
L5:

    //     sym = SymTab[sub][S_TEMPS]
    DeRef(_8977);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sub);
    RefDS(_8977);
    _2 = (int)SEQ_PTR(_8977);
    _18sym = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_18sym))
        _18sym = (long)DBL_PTR(_18sym)->dbl;

    //     while sym != 0 do
L9:
    if (_18sym == 0)
        goto LA;

    // 	if SymTab[sym][S_SCOPE] != DELETED then
    DeRef(_8977);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8977);
    _0 = _8977;
    _2 = (int)SEQ_PTR(_8977);
    _8977 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_8977);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _8977, 2))
        goto LB;

    // 	    FinalDeRef(sym)
    _18FinalDeRef(_18sym);
LB:

    // 	sym = SymTab[sym][S_NEXT]
    DeRef(_8977);
    _2 = (int)SEQ_PTR(_4SymTab);
    _8977 = (int)*(((s1_ptr)_2)->base + _18sym);
    RefDS(_8977);
    _2 = (int)SEQ_PTR(_8977);
    _18sym = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_18sym))
        _18sym = (long)DBL_PTR(_18sym)->dbl;

    //     end while
    goto L9;
LA:

    //     FlushDeRef()
    _18FlushDeRef();

    //     c_stmt0("return 0;\n")
    RefDS(_9006);
    _16c_stmt0(_9006);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_8977);
    DeRef(_8976);
    return 0;
    ;
}


int _18opROUTINE_ID()
{
    int _9010 = 0;
    int _9008 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+4], Code[pc+2], 0, 0)
    _9008 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9008 = (int)*(((s1_ptr)_2)->base + _9008);
    Ref(_9008);
    _9010 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    RefDS(_5774);
    Ref(_9008);
    Ref(_9010);
    _18CSaveStr(_5774, _9008, _9010, 0, 0);

    //     c_stmt("@ = CRoutineId(", Code[pc+4])
    DeRef(_9010);
    _9010 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    RefDS(_9012);
    Ref(_9010);
    _16c_stmt(_9012, _9010);

    //     c_printf("%d, ", Code[pc+1])  -- sequence number
    DeRef(_9010);
    _9010 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    RefDS(_9015);
    Ref(_9010);
    _9c_printf(_9015, _9010);

    //     c_printf("%d", Code[pc+3])  -- current file number
    DeRef(_9010);
    _9010 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    RefDS(_9018);
    Ref(_9010);
    _9c_printf(_9018, _9010);

    //     temp_indent = -indent
    _9temp_indent = - _9indent;

    //     c_stmt(", @);\n", Code[pc+2])  -- name
    DeRef(_9010);
    _9010 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    RefDS(_5807);
    Ref(_9010);
    _16c_stmt(_5807, _9010);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {-1, 1000000}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 1000000;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+4], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_9010);
    _9010 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9010 = (int)*(((s1_ptr)_2)->base + _9010);
    Ref(_9010);
    Ref(_9010);
    RefDS(_18target);
    _16SetBBType(_9010, 1, _18target, 16);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_9010);
    DeRef(_9008);
    return 0;
    ;
}


int _18opAPPEND()
{
    int _preserve;
    int _t;
    int _9028 = 0;
    int _9039 = 0;
    int _9033 = 0;
    int _0, _1, _2, _3;
    

    //     CRef(Code[pc+2])
    _9028 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9028 = (int)*(((s1_ptr)_2)->base + _9028);
    Ref(_9028);
    Ref(_9028);
    _18CRef(_9028);

    //     SymTab[Code[pc+2]][S_ONE_REF] = FALSE
    DeRef(_9028);
    _9028 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9028 = (int)*(((s1_ptr)_2)->base + _9028);
    Ref(_9028);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9028))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9028)->dbl));
    else
        _3 = (int)(_9028 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     c_stmt("Append(&@, @, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    _9033 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9033 = (int)*(((s1_ptr)_2)->base + _9033);
    Ref(_9033);
    DeRef(_9028);
    _9028 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9028 = (int)*(((s1_ptr)_2)->base + _9028);
    Ref(_9028);
    _9039 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    _0 = _9039;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9033);
    *((int *)(_2+4)) = _9033;
    Ref(_9028);
    *((int *)(_2+8)) = _9028;
    Ref(_9039);
    *((int *)(_2+12)) = _9039;
    _9039 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9034);
    RefDS(_9039);
    _16c_stmt(_9034, _9039);

    //     target = {NOVALUE, 0}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = 0;
    _18target = MAKE_SEQ(_1);

    //     if TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRefDS(_9039);
    _9039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    Ref(_9039);
    _0 = _9039;
    _9039 = _16TypeIs(_9039, 8);
    DeRef(_0);
    if (_9039 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9039) && DBL_PTR(_9039)->dbl == 0.0)
            goto L1;
    }

    // 	target[MIN] = SeqLen(Code[pc+1]) + 1
    DeRef(_9039);
    _9039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    Ref(_9039);
    _0 = _9039;
    _9039 = _18SeqLen(_9039);
    DeRef(_0);
    _0 = _9039;
    if (IS_ATOM_INT(_9039)) {
        _9039 = _9039 + 1;
        if (_9039 > MAXINT)
            _9039 = NewDouble((double)_9039);
    }
    else
        _9039 = binary_op(PLUS, 1, _9039);
    DeRef(_0);
    Ref(_9039);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9039;
    DeRef(_1);
L1:

    //     t = Code[pc+3]
    DeRef(_9039);
    _9039 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _t = (int)*(((s1_ptr)_2)->base + _9039);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     if t = Code[pc+1] and SymTab[t][S_MODE] = M_NORMAL then
    _9039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    _0 = _9039;
    if (IS_ATOM_INT(_9039)) {
        _9039 = (_t == _9039);
    }
    else {
        _9039 = binary_op(EQUALS, _t, _9039);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_9039)) {
        if (_9039 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_9039)->dbl == 0.0) {
            goto L2;
        }
    }
    DeRef(_9028);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9028 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_9028);
    _0 = _9028;
    _2 = (int)SEQ_PTR(_9028);
    _9028 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9028);
    DeRefDS(_0);
    _0 = _9028;
    if (IS_ATOM_INT(_9028)) {
        _9028 = (_9028 == 1);
    }
    else {
        _9028 = binary_op(EQUALS, _9028, 1);
    }
    DeRef(_0);
L3:
    if (_9028 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9028) && DBL_PTR(_9028)->dbl == 0.0)
            goto L2;
    }

    // 	preserve = or_type(SymTab[t][S_SEQ_ELEM_NEW], GType(Code[pc+2]))
    DeRef(_9028);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9028 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_9028);
    _0 = _9028;
    _2 = (int)SEQ_PTR(_9028);
    _9028 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_9028);
    DeRefDS(_0);
    DeRef(_9039);
    _9039 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    Ref(_9039);
    _0 = _9039;
    _9039 = _16GType(_9039);
    DeRef(_0);
    Ref(_9028);
    _preserve = _16or_type(_9028, _9039);

    // 	SetBBType(t, TYPE_SEQUENCE, target, 
    _9039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    Ref(_9039);
    _0 = _9039;
    _9039 = _18SeqElem(_9039);
    DeRef(_0);
    DeRef(_9028);
    _9028 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9028 = (int)*(((s1_ptr)_2)->base + _9028);
    Ref(_9028);
    Ref(_9028);
    _0 = _9028;
    _9028 = _16GType(_9028);
    DeRef(_0);
    _9028 = _16or_type(_9039, _9028);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _9028);

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
    goto L4;
L2:

    // 	SetBBType(t, TYPE_SEQUENCE, target, 
    DeRef(_9039);
    _9039 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9039 = (int)*(((s1_ptr)_2)->base + _9039);
    Ref(_9039);
    Ref(_9039);
    _0 = _9039;
    _9039 = _18SeqElem(_9039);
    DeRef(_0);
    DeRef(_9028);
    _9028 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9028 = (int)*(((s1_ptr)_2)->base + _9028);
    Ref(_9028);
    Ref(_9028);
    _0 = _9028;
    _9028 = _16GType(_9028);
    DeRef(_0);
    _9028 = _16or_type(_9039, _9028);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _9028);
L4:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9028);
    DeRef(_9039);
    DeRef(_9033);
    return 0;
    ;
}


int _18opPREPEND()
{
    int _preserve;
    int _t;
    int _9082 = 0;
    int _9093 = 0;
    int _9087 = 0;
    int _0, _1, _2, _3;
    

    //     CRef(Code[pc+2])
    _9082 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9082 = (int)*(((s1_ptr)_2)->base + _9082);
    Ref(_9082);
    Ref(_9082);
    _18CRef(_9082);

    //     SymTab[Code[pc+2]][S_ONE_REF] = FALSE
    DeRef(_9082);
    _9082 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9082 = (int)*(((s1_ptr)_2)->base + _9082);
    Ref(_9082);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9082))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9082)->dbl));
    else
        _3 = (int)(_9082 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     c_stmt("Prepend(&@, @, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    _9087 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9087 = (int)*(((s1_ptr)_2)->base + _9087);
    Ref(_9087);
    DeRef(_9082);
    _9082 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9082 = (int)*(((s1_ptr)_2)->base + _9082);
    Ref(_9082);
    _9093 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    _0 = _9093;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9087);
    *((int *)(_2+4)) = _9087;
    Ref(_9082);
    *((int *)(_2+8)) = _9082;
    Ref(_9093);
    *((int *)(_2+12)) = _9093;
    _9093 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9088);
    RefDS(_9093);
    _16c_stmt(_9088, _9093);

    //     target = {NOVALUE, 0}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _4NOVALUE;
    RefDS(_4NOVALUE);
    ((int *)_2)[2] = 0;
    _18target = MAKE_SEQ(_1);

    //     if TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRefDS(_9093);
    _9093 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    Ref(_9093);
    _0 = _9093;
    _9093 = _16TypeIs(_9093, 8);
    DeRef(_0);
    if (_9093 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9093) && DBL_PTR(_9093)->dbl == 0.0)
            goto L1;
    }

    // 	target[MIN] = SeqLen(Code[pc+1]) + 1
    DeRef(_9093);
    _9093 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    Ref(_9093);
    _0 = _9093;
    _9093 = _18SeqLen(_9093);
    DeRef(_0);
    _0 = _9093;
    if (IS_ATOM_INT(_9093)) {
        _9093 = _9093 + 1;
        if (_9093 > MAXINT)
            _9093 = NewDouble((double)_9093);
    }
    else
        _9093 = binary_op(PLUS, 1, _9093);
    DeRef(_0);
    Ref(_9093);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9093;
    DeRef(_1);
L1:

    //     t = Code[pc+3]
    DeRef(_9093);
    _9093 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _t = (int)*(((s1_ptr)_2)->base + _9093);
    if (!IS_ATOM_INT(_t))
        _t = (long)DBL_PTR(_t)->dbl;

    //     if t = Code[pc+1] and SymTab[t][S_MODE] = M_NORMAL then
    _9093 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    _0 = _9093;
    if (IS_ATOM_INT(_9093)) {
        _9093 = (_t == _9093);
    }
    else {
        _9093 = binary_op(EQUALS, _t, _9093);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_9093)) {
        if (_9093 == 0) {
            goto L2;
        }
    }
    else {
        if (DBL_PTR(_9093)->dbl == 0.0) {
            goto L2;
        }
    }
    DeRef(_9082);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9082 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_9082);
    _0 = _9082;
    _2 = (int)SEQ_PTR(_9082);
    _9082 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9082);
    DeRefDS(_0);
    _0 = _9082;
    if (IS_ATOM_INT(_9082)) {
        _9082 = (_9082 == 1);
    }
    else {
        _9082 = binary_op(EQUALS, _9082, 1);
    }
    DeRef(_0);
L3:
    if (_9082 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9082) && DBL_PTR(_9082)->dbl == 0.0)
            goto L2;
    }

    // 	preserve = or_type(SymTab[t][S_SEQ_ELEM_NEW], GType(Code[pc+2]))
    DeRef(_9082);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9082 = (int)*(((s1_ptr)_2)->base + _t);
    RefDS(_9082);
    _0 = _9082;
    _2 = (int)SEQ_PTR(_9082);
    _9082 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_9082);
    DeRefDS(_0);
    DeRef(_9093);
    _9093 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    Ref(_9093);
    _0 = _9093;
    _9093 = _16GType(_9093);
    DeRef(_0);
    Ref(_9082);
    _preserve = _16or_type(_9082, _9093);

    // 	SetBBType(t, TYPE_SEQUENCE, target, 
    _9093 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    Ref(_9093);
    _0 = _9093;
    _9093 = _18SeqElem(_9093);
    DeRef(_0);
    DeRef(_9082);
    _9082 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9082 = (int)*(((s1_ptr)_2)->base + _9082);
    Ref(_9082);
    Ref(_9082);
    _0 = _9082;
    _9082 = _16GType(_9082);
    DeRef(_0);
    _9082 = _16or_type(_9093, _9082);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _9082);

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
    goto L4;
L2:

    // 	SetBBType(t, TYPE_SEQUENCE, target, 
    DeRef(_9093);
    _9093 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9093 = (int)*(((s1_ptr)_2)->base + _9093);
    Ref(_9093);
    Ref(_9093);
    _0 = _9093;
    _9093 = _18SeqElem(_9093);
    DeRef(_0);
    DeRef(_9082);
    _9082 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9082 = (int)*(((s1_ptr)_2)->base + _9082);
    Ref(_9082);
    Ref(_9082);
    _0 = _9082;
    _9082 = _16GType(_9082);
    DeRef(_0);
    _9082 = _16or_type(_9093, _9082);
    RefDS(_18target);
    _16SetBBType(_t, 8, _18target, _9082);
L4:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9082);
    DeRef(_9093);
    DeRef(_9087);
    return 0;
    ;
}


int _18opCONCAT()
{
    int _t;
    int _p3;
    int _preserve;
    int _j = 0;
    int _target = 0;
    int _9136 = 0;
    int _9163 = 0;
    int _9140 = 0;
    int _0, _1, _2, _3;
    

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) or 
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 16);
    DeRef(_0);
    if (IS_ATOM_INT(_9136)) {
        if (_9136 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_9136)->dbl != 0.0) {
            goto L1;
        }
    }
    _9140 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _0 = _9140;
    _9140 = _16TypeIs(_9140, 16);
    DeRef(_0);
L2:
    if (_9140 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_9140) && DBL_PTR(_9140)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	c_stmt("if (IS_SEQUENCE(@) && IS_ATOM(@)) {\n", {Code[pc+1], Code[pc+2]})
    DeRef(_9140);
    _9140 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    _0 = _9136;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9140;
    Ref(_9140);
    ((int *)_2)[2] = _9136;
    Ref(_9136);
    _9136 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9143);
    RefDS(_9136);
    _16c_stmt(_9143, _9136);
L3:

    //     if TypeIs(Code[pc+1], {TYPE_OBJECT, TYPE_SEQUENCE}) and
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    RefDS(_9151);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, _9151);
    DeRef(_0);
    if (IS_ATOM_INT(_9136)) {
        if (_9136 == 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_9136)->dbl == 0.0) {
            goto L4;
        }
    }
    DeRef(_9140);
    _9140 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _0 = _9140;
    _9140 = _16TypeIsNot(_9140, 8);
    DeRef(_0);
L5:
    if (_9140 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_9140) && DBL_PTR(_9140)->dbl == 0.0)
            goto L4;
    }

    // 	CRef(Code[pc+2])
    DeRef(_9140);
    _9140 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _18CRef(_9140);

    // 	c_stmt("Append(&@, @, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_9140);
    _9140 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    _0 = _9163;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9140);
    *((int *)(_2+4)) = _9140;
    Ref(_9136);
    *((int *)(_2+8)) = _9136;
    Ref(_9163);
    *((int *)(_2+12)) = _9163;
    _9163 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9034);
    RefDS(_9163);
    _16c_stmt(_9034, _9163);
L4:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) or 
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, 16);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 != 0) {
            goto L6;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl != 0.0) {
            goto L6;
        }
    }
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 16);
    DeRef(_0);
L7:
    if (_9136 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L8;
    }
L6:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt("else if (IS_ATOM(@) && IS_SEQUENCE(@)) {\n",
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    _0 = _9163;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9136;
    Ref(_9136);
    ((int *)_2)[2] = _9163;
    Ref(_9163);
    _9163 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9173);
    RefDS(_9163);
    _16c_stmt(_9173, _9163);
L8:

    //     if TypeIs(Code[pc+2], {TYPE_OBJECT, TYPE_SEQUENCE}) and
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    RefDS(_9151);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, _9151);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 == 0) {
            goto L9;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl == 0.0) {
            goto L9;
        }
    }
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIsNot(_9136, 8);
    DeRef(_0);
LA:
    if (_9136 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L9;
    }

    // 	CRef(Code[pc+1])
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _18CRef(_9136);

    // 	c_stmt("Prepend(&@, @, @);\n", {Code[pc+3], Code[pc+2], Code[pc+1]})
    DeRef(_9136);
    _9136 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    DeRef(_9140);
    _9140 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    _0 = _9140;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9136);
    *((int *)(_2+4)) = _9136;
    Ref(_9163);
    *((int *)(_2+8)) = _9163;
    Ref(_9140);
    *((int *)(_2+12)) = _9140;
    _9140 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9088);
    RefDS(_9140);
    _16c_stmt(_9088, _9140);
L9:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) or 
    DeRef(_9140);
    _9140 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _0 = _9140;
    _9140 = _16TypeIs(_9140, 16);
    DeRef(_0);
    if (IS_ATOM_INT(_9140)) {
        if (_9140 != 0) {
            goto LB;
        }
    }
    else {
        if (DBL_PTR(_9140)->dbl != 0.0) {
            goto LB;
        }
    }
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, 16);
    DeRef(_0);
LC:
    if (_9163 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_9163) && DBL_PTR(_9163)->dbl == 0.0)
            goto LD;
    }
LB:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
LD:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) or 
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, 16);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 != 0) {
            DeRef(_9163);
            _9163 = 1;
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl != 0.0) {
            DeRef(_9163);
            _9163 = 1;
            goto LE;
        }
    }
    DeRef(_9140);
    _9140 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _0 = _9140;
    _9140 = _16TypeIs(_9140, 16);
    DeRef(_0);
    DeRef(_9163);
    if (IS_ATOM_INT(_9140))
        _9163 = (_9140 != 0);
    else
        _9163 = DBL_PTR(_9140)->dbl != 0.0;
LE:
    if (_9163 != 0) {
        DeRef(_9140);
        _9140 = 1;
        goto LF;
    }
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, 8);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 == 0) {
            DeRef(_9163);
            _9163 = 0;
            goto L10;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl == 0.0) {
            DeRef(_9163);
            _9163 = 0;
            goto L10;
        }
    }
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 8);
    DeRef(_0);
    DeRef(_9163);
    if (IS_ATOM_INT(_9136))
        _9163 = (_9136 != 0);
    else
        _9163 = DBL_PTR(_9136)->dbl != 0.0;
L10:
    DeRef(_9140);
    _9140 = (_9163 != 0);
LF:
    if (_9140 != 0) {
        goto L11;
    }
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIsNot(_9163, 8);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 == 0) {
            DeRef(_9163);
            _9163 = 0;
            goto L12;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl == 0.0) {
            DeRef(_9163);
            _9163 = 0;
            goto L12;
        }
    }
    DeRef(_9140);
    _9140 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    Ref(_9140);
    _0 = _9140;
    _9140 = _16TypeIsNot(_9140, 8);
    DeRef(_0);
    DeRef(_9163);
    if (IS_ATOM_INT(_9140))
        _9163 = (_9140 != 0);
    else
        _9163 = DBL_PTR(_9140)->dbl != 0.0;
L12:
L13:
    if (_9163 == 0)
        goto L14;
L11:

    // 	c_stmt("Concat((object_ptr)&@, @, (s1_ptr)@);\n", 
    DeRef(_9140);
    _9140 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9140 = (int)*(((s1_ptr)_2)->base + _9140);
    Ref(_9140);
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    _0 = _9136;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9140);
    *((int *)(_2+4)) = _9140;
    Ref(_9163);
    *((int *)(_2+8)) = _9163;
    Ref(_9136);
    *((int *)(_2+12)) = _9136;
    _9136 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9225);
    RefDS(_9136);
    _16c_stmt(_9225, _9136);
L14:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) or 
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 16);
    DeRef(_0);
    if (IS_ATOM_INT(_9136)) {
        if (_9136 != 0) {
            goto L15;
        }
    }
    else {
        if (DBL_PTR(_9136)->dbl != 0.0) {
            goto L15;
        }
    }
    DeRef(_9163);
    _9163 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, 16);
    DeRef(_0);
L16:
    if (_9163 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_9163) && DBL_PTR(_9163)->dbl == 0.0)
            goto L17;
    }
L15:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L17:

    //     target = {0, 0}
    DeRef(_target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 0;
    _target = MAKE_SEQ(_1);

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_ATOM}) and
    DeRef(_9163);
    _9163 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9163 = (int)*(((s1_ptr)_2)->base + _9163);
    Ref(_9163);
    Ref(_9163);
    RefDS(_9243);
    _0 = _9163;
    _9163 = _16TypeIs(_9163, _9243);
    DeRef(_0);
    if (IS_ATOM_INT(_9163)) {
        if (_9163 == 0) {
            goto L18;
        }
    }
    else {
        if (DBL_PTR(_9163)->dbl == 0.0) {
            goto L18;
        }
    }
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    RefDS(_9243);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, _9243);
    DeRef(_0);
L19:
    if (_9136 == 0) {
        goto L18;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L18;
    }

    // 	if TypeIs(Code[pc+1], TYPE_ATOM) then
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 4);
    DeRef(_0);
    if (_9136 == 0) {
        goto L1A;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L1A;
    }

    // 	    target[MIN] = 1
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
    goto L1B;
L1A:

    // 	    target[MIN] = SeqLen(Code[pc+1])
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _18SeqLen(_9136);
    DeRef(_0);
    Ref(_9136);
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9136;
    DeRef(_1);
L1B:

    // 	if target[MIN] != NOVALUE then
    DeRef(_9136);
    _2 = (int)SEQ_PTR(_target);
    _9136 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9136);
    if (binary_op_a(EQUALS, _9136, _4NOVALUE))
        goto L1C;

    // 	    if TypeIs(Code[pc+2], TYPE_ATOM) then
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 4);
    DeRef(_0);
    if (_9136 == 0) {
        goto L1D;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L1D;
    }

    // 		target[MIN] += 1
    DeRef(_9136);
    _2 = (int)SEQ_PTR(_target);
    _9136 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9136);
    _0 = _9136;
    if (IS_ATOM_INT(_9136)) {
        _9136 = _9136 + 1;
        if (_9136 > MAXINT)
            _9136 = NewDouble((double)_9136);
    }
    else
        _9136 = binary_op(PLUS, 1, _9136);
    DeRef(_0);
    Ref(_9136);
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9136;
    DeRef(_1);
    goto L1C;
L1D:

    // 		j = SeqLen(Code[pc+2])
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _j;
    _j = _18SeqLen(_9136);
    DeRef(_0);

    // 		if j = NOVALUE then
    if (binary_op_a(NOTEQ, _j, _4NOVALUE))
        goto L1E;

    // 		    target[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
    goto L1C;
L1E:

    // 		    target[MIN] += j
    DeRef(_9136);
    _2 = (int)SEQ_PTR(_target);
    _9136 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_9136);
    _0 = _9136;
    if (IS_ATOM_INT(_9136) && IS_ATOM_INT(_j)) {
        _9136 = _9136 + _j;
        if ((long)((unsigned long)_9136 + (unsigned long)HIGH_BITS) >= 0) 
            _9136 = NewDouble((double)_9136);
    }
    else {
        _9136 = binary_op(PLUS, _9136, _j);
    }
    DeRef(_0);
    Ref(_9136);
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9136;
    DeRef(_1);
L1F:
L20:
L21:
    goto L1C;
L18:

    // 	target[MIN] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);
L1C:

    //     if TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 8);
    DeRef(_0);
    if (_9136 == 0) {
        goto L22;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L22;
    }

    // 	j = SeqElem(Code[pc+1])
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _j;
    _j = _18SeqElem(_9136);
    DeRef(_0);
    goto L23;
L22:

    // 	j = GType(Code[pc+1])    
    DeRef(_9136);
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _j;
    _j = _16GType(_9136);
    DeRef(_0);
L23:

    //     if TypeIs(Code[pc+2], TYPE_SEQUENCE) then
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _0 = _9136;
    _9136 = _16TypeIs(_9136, 8);
    DeRef(_0);
    if (_9136 == 0) {
        goto L24;
    }
    else {
        if (!IS_ATOM_INT(_9136) && DBL_PTR(_9136)->dbl == 0.0)
            goto L24;
    }

    // 	t = SeqElem(Code[pc+2])
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _t = _18SeqElem(_9136);
    goto L25;
L24:

    // 	t = GType(Code[pc+2])
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    Ref(_9136);
    _t = _16GType(_9136);
L25:

    //     p3 = Code[pc+3]
    DeRef(_9136);
    _9136 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _p3 = (int)*(((s1_ptr)_2)->base + _9136);
    if (!IS_ATOM_INT(_p3))
        _p3 = (long)DBL_PTR(_p3)->dbl;

    //     if p3 = Code[pc+1] and SymTab[p3][S_MODE] = M_NORMAL then
    _9136 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    _0 = _9136;
    if (IS_ATOM_INT(_9136)) {
        _9136 = (_p3 == _9136);
    }
    else {
        _9136 = binary_op(EQUALS, _p3, _9136);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_9136)) {
        if (_9136 == 0) {
            goto L26;
        }
    }
    else {
        if (DBL_PTR(_9136)->dbl == 0.0) {
            goto L26;
        }
    }
    DeRef(_9163);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9163 = (int)*(((s1_ptr)_2)->base + _p3);
    RefDS(_9163);
    _0 = _9163;
    _2 = (int)SEQ_PTR(_9163);
    _9163 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9163);
    DeRefDS(_0);
    _0 = _9163;
    if (IS_ATOM_INT(_9163)) {
        _9163 = (_9163 == 1);
    }
    else {
        _9163 = binary_op(EQUALS, _9163, 1);
    }
    DeRef(_0);
L27:
    if (_9163 == 0) {
        goto L26;
    }
    else {
        if (!IS_ATOM_INT(_9163) && DBL_PTR(_9163)->dbl == 0.0)
            goto L26;
    }

    // 	preserve = or_type(SymTab[p3][S_SEQ_ELEM_NEW], t)
    DeRef(_9163);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9163 = (int)*(((s1_ptr)_2)->base + _p3);
    RefDS(_9163);
    _0 = _9163;
    _2 = (int)SEQ_PTR(_9163);
    _9163 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_9163);
    DeRefDS(_0);
    Ref(_9163);
    _preserve = _16or_type(_9163, _t);

    // 	SetBBType(p3, TYPE_SEQUENCE, target, or_type(j, t))
    Ref(_j);
    _0 = _9163;
    _9163 = _16or_type(_j, _t);
    DeRef(_0);
    RefDS(_target);
    _16SetBBType(_p3, 8, _target, _9163);

    // 	SymTab[p3][S_SEQ_ELEM_NEW] = preserve
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p3 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _preserve;
    DeRef(_1);
    goto L28;
L26:

    //     elsif p3 = Code[pc+2] and SymTab[p3][S_MODE] = M_NORMAL then
    DeRef(_9136);
    _9136 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9136 = (int)*(((s1_ptr)_2)->base + _9136);
    Ref(_9136);
    _0 = _9136;
    if (IS_ATOM_INT(_9136)) {
        _9136 = (_p3 == _9136);
    }
    else {
        _9136 = binary_op(EQUALS, _p3, _9136);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_9136)) {
        if (_9136 == 0) {
            goto L29;
        }
    }
    else {
        if (DBL_PTR(_9136)->dbl == 0.0) {
            goto L29;
        }
    }
    DeRef(_9163);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9163 = (int)*(((s1_ptr)_2)->base + _p3);
    RefDS(_9163);
    _0 = _9163;
    _2 = (int)SEQ_PTR(_9163);
    _9163 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_9163);
    DeRefDS(_0);
    _0 = _9163;
    if (IS_ATOM_INT(_9163)) {
        _9163 = (_9163 == 1);
    }
    else {
        _9163 = binary_op(EQUALS, _9163, 1);
    }
    DeRef(_0);
L2A:
    if (_9163 == 0) {
        goto L29;
    }
    else {
        if (!IS_ATOM_INT(_9163) && DBL_PTR(_9163)->dbl == 0.0)
            goto L29;
    }

    // 	preserve = or_type(SymTab[p3][S_SEQ_ELEM_NEW], j)
    DeRef(_9163);
    _2 = (int)SEQ_PTR(_4SymTab);
    _9163 = (int)*(((s1_ptr)_2)->base + _p3);
    RefDS(_9163);
    _0 = _9163;
    _2 = (int)SEQ_PTR(_9163);
    _9163 = (int)*(((s1_ptr)_2)->base + 37);
    Ref(_9163);
    DeRefDS(_0);
    Ref(_9163);
    Ref(_j);
    _preserve = _16or_type(_9163, _j);

    // 	SetBBType(p3, TYPE_SEQUENCE, target, or_type(j, t))
    Ref(_j);
    _0 = _9163;
    _9163 = _16or_type(_j, _t);
    DeRef(_0);
    RefDS(_target);
    _16SetBBType(_p3, 8, _target, _9163);

    // 	SymTab[p3][S_SEQ_ELEM_NEW] = preserve
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_p3 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 37);
    _1 = *(int *)_2;
    *(int *)_2 = _preserve;
    DeRef(_1);
    goto L28;
L29:

    // 	SetBBType(p3, TYPE_SEQUENCE, target, or_type(j, t))
    Ref(_j);
    _0 = _9136;
    _9136 = _16or_type(_j, _t);
    DeRef(_0);
    RefDS(_target);
    _16SetBBType(_p3, 8, _target, _9136);
L28:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_j);
    DeRef(_target);
    DeRef(_9136);
    DeRef(_9163);
    DeRef(_9140);
    return 0;
    ;
}


int _18opCONCAT_N()
{
    int _9323 = 0;
    int _9316 = 0;
    int _0, _1, _2;
    

    //     n = Code[pc+1]
    _9316 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _18n = (int)*(((s1_ptr)_2)->base + _9316);
    if (!IS_ATOM_INT(_18n))
        _18n = (long)DBL_PTR(_18n)->dbl;

    //     c_stmt0("{\n")
    RefDS(_5169);
    _16c_stmt0(_5169);

    //     c_stmt0("int concat_list[")
    RefDS(_9318);
    _16c_stmt0(_9318);

    //     c_printf("%d];\n\n", n)
    RefDS(_9319);
    _9c_printf(_9319, _18n);

    //     t = TYPE_NULL
    _18t = 0;

    //     for i = 0 to n-1 do
    _9316 = _18n - 1;
    if ((long)((unsigned long)_9316 +(unsigned long) HIGH_BITS) >= 0)
        _9316 = NewDouble((double)_9316);
    { int _i;
        _i = 0;
L1:
        if (binary_op_a(GREATER, _i, _9316))
            goto L2;

        // 	c_stmt0("concat_list[")
        RefDS(_9321);
        _16c_stmt0(_9321);

        // 	c_printf("%d] = ", i)
        RefDS(_9322);
        Ref(_i);
        _9c_printf(_9322, _i);

        // 	CName(Code[pc+2+i])
        DeRef(_9323);
        _9323 = _18pc + 2;
        if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
            _9323 = NewDouble((double)_9323);
        _0 = _9323;
        if (IS_ATOM_INT(_9323) && IS_ATOM_INT(_i)) {
            _9323 = _9323 + _i;
        }
        else {
            if (IS_ATOM_INT(_9323)) {
                _9323 = NewDouble((double)_9323 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)_i);
                }
                else
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _9323;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_9323))
            _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
        else
            _9323 = (int)*(((s1_ptr)_2)->base + _9323);
        Ref(_9323);
        DeRef(_0);
        Ref(_9323);
        _16CName(_9323);

        // 	c_puts(";\n")
        RefDS(_4460);
        _9c_puts(_4460);

        // 	if TypeIs(Code[pc+2+i], TYPE_SEQUENCE) then
        DeRef(_9323);
        _9323 = _18pc + 2;
        if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
            _9323 = NewDouble((double)_9323);
        _0 = _9323;
        if (IS_ATOM_INT(_9323) && IS_ATOM_INT(_i)) {
            _9323 = _9323 + _i;
        }
        else {
            if (IS_ATOM_INT(_9323)) {
                _9323 = NewDouble((double)_9323 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)_i);
                }
                else
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _9323;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_9323))
            _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
        else
            _9323 = (int)*(((s1_ptr)_2)->base + _9323);
        Ref(_9323);
        DeRef(_0);
        Ref(_9323);
        _0 = _9323;
        _9323 = _16TypeIs(_9323, 8);
        DeRef(_0);
        if (_9323 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_9323) && DBL_PTR(_9323)->dbl == 0.0)
                goto L3;
        }

        // 	    t = or_type(t, SeqElem(Code[pc+2+i]))
        DeRef(_9323);
        _9323 = _18pc + 2;
        if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
            _9323 = NewDouble((double)_9323);
        _0 = _9323;
        if (IS_ATOM_INT(_9323) && IS_ATOM_INT(_i)) {
            _9323 = _9323 + _i;
        }
        else {
            if (IS_ATOM_INT(_9323)) {
                _9323 = NewDouble((double)_9323 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)_i);
                }
                else
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _9323;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_9323))
            _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
        else
            _9323 = (int)*(((s1_ptr)_2)->base + _9323);
        Ref(_9323);
        DeRef(_0);
        Ref(_9323);
        _0 = _9323;
        _9323 = _18SeqElem(_9323);
        DeRef(_0);
        _0 = _16or_type(_18t, _9323);
        _18t = _0;
        goto L4;
L3:

        // 	    t = or_type(t, GType(Code[pc+2+i])) 
        DeRef(_9323);
        _9323 = _18pc + 2;
        if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
            _9323 = NewDouble((double)_9323);
        _0 = _9323;
        if (IS_ATOM_INT(_9323) && IS_ATOM_INT(_i)) {
            _9323 = _9323 + _i;
        }
        else {
            if (IS_ATOM_INT(_9323)) {
                _9323 = NewDouble((double)_9323 + DBL_PTR(_i)->dbl);
            }
            else {
                if (IS_ATOM_INT(_i)) {
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)_i);
                }
                else
                    _9323 = NewDouble(DBL_PTR(_9323)->dbl + DBL_PTR(_i)->dbl);
            }
        }
        DeRef(_0);
        _0 = _9323;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_9323))
            _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
        else
            _9323 = (int)*(((s1_ptr)_2)->base + _9323);
        Ref(_9323);
        DeRef(_0);
        Ref(_9323);
        _0 = _9323;
        _9323 = _16GType(_9323);
        DeRef(_0);
        _0 = _16or_type(_18t, _9323);
        _18t = _0;
L4:

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

    //     c_stmt("Concat_N((object_ptr)&@, concat_list", Code[pc+n+2])  
    DeRef(_9323);
    _9323 = _18pc + _18n;
    if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
        _9323 = NewDouble((double)_9323);
    _0 = _9323;
    if (IS_ATOM_INT(_9323)) {
        _9323 = _9323 + 2;
    }
    else {
        _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)2);
    }
    DeRef(_0);
    _0 = _9323;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_9323))
        _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
    else
        _9323 = (int)*(((s1_ptr)_2)->base + _9323);
    Ref(_9323);
    DeRef(_0);
    RefDS(_9340);
    Ref(_9323);
    _16c_stmt(_9340, _9323);

    //     c_printf(", %d);\n", n)
    RefDS(_5677);
    _9c_printf(_5677, _18n);

    //     c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    //     SetBBType(Code[pc+n+2], TYPE_SEQUENCE, novalue, t)
    DeRef(_9323);
    _9323 = _18pc + _18n;
    if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
        _9323 = NewDouble((double)_9323);
    _0 = _9323;
    if (IS_ATOM_INT(_9323)) {
        _9323 = _9323 + 2;
    }
    else {
        _9323 = NewDouble(DBL_PTR(_9323)->dbl + (double)2);
    }
    DeRef(_0);
    _0 = _9323;
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_9323))
        _9323 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_9323)->dbl));
    else
        _9323 = (int)*(((s1_ptr)_2)->base + _9323);
    Ref(_9323);
    DeRef(_0);
    Ref(_9323);
    RefDS(_9novalue);
    _16SetBBType(_9323, 8, _9novalue, _18t);

    //     pc += n+3
    DeRef(_9323);
    _9323 = _18n + 3;
    if ((long)((unsigned long)_9323 + (unsigned long)HIGH_BITS) >= 0) 
        _9323 = NewDouble((double)_9323);
    if (IS_ATOM_INT(_9323)) {
        _18pc = _18pc + _9323;
    }
    else {
        _18pc = NewDouble((double)_18pc + DBL_PTR(_9323)->dbl);
    }
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_9323);
    DeRef(_9316);
    return 0;
    ;
}


int _18opREPEAT()
{
    int _9351 = 0;
    int _9349 = 0;
    int _9353 = 0;
    int _0, _1, _2, _3;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9349 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9349 = (int)*(((s1_ptr)_2)->base + _9349);
    Ref(_9349);
    _9351 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    _9353 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9353 = (int)*(((s1_ptr)_2)->base + _9353);
    Ref(_9353);
    RefDS(_5774);
    Ref(_9349);
    Ref(_9351);
    Ref(_9353);
    _18CSaveStr(_5774, _9349, _9351, _9353, 0);

    //     c_stmt("@ = Repeat(@, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_9353);
    _9353 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9353 = (int)*(((s1_ptr)_2)->base + _9353);
    Ref(_9353);
    DeRef(_9351);
    _9351 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    DeRef(_9349);
    _9349 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9349 = (int)*(((s1_ptr)_2)->base + _9349);
    Ref(_9349);
    _0 = _9349;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9353);
    *((int *)(_2+4)) = _9353;
    Ref(_9351);
    *((int *)(_2+8)) = _9351;
    Ref(_9349);
    *((int *)(_2+12)) = _9349;
    _9349 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9355);
    RefDS(_9349);
    _16c_stmt(_9355, _9349);

    //     SymTab[Code[pc+1]][S_ONE_REF] = FALSE
    DeRefDS(_9349);
    _9349 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9349 = (int)*(((s1_ptr)_2)->base + _9349);
    Ref(_9349);
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_9349))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_9349)->dbl));
    else
        _3 = (int)(_9349 + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 32);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     if TypeIs(Code[pc+2], TYPE_INTEGER) then
    DeRef(_9351);
    _9351 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    Ref(_9351);
    _0 = _9351;
    _9351 = _16TypeIs(_9351, 1);
    DeRef(_0);
    if (_9351 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9351) && DBL_PTR(_9351)->dbl == 0.0)
            goto L1;
    }

    // 	target[MIN] = ObjValue(Code[pc+2])
    DeRef(_9351);
    _9351 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    Ref(_9351);
    _0 = _9351;
    _9351 = _16ObjValue(_9351);
    DeRef(_0);
    Ref(_9351);
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _9351;
    DeRef(_1);

    // 	SetBBType(Code[pc+3], TYPE_SEQUENCE, target, GType(Code[pc+1]))
    DeRef(_9351);
    _9351 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    DeRef(_9349);
    _9349 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9349 = (int)*(((s1_ptr)_2)->base + _9349);
    Ref(_9349);
    Ref(_9349);
    _0 = _9349;
    _9349 = _16GType(_9349);
    DeRef(_0);
    Ref(_9351);
    RefDS(_18target);
    _16SetBBType(_9351, 8, _18target, _9349);
    goto L2;
L1:

    // 	SetBBType(Code[pc+3], TYPE_SEQUENCE, novalue, GType(Code[pc+1]))
    DeRef(_9349);
    _9349 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9349 = (int)*(((s1_ptr)_2)->base + _9349);
    Ref(_9349);
    DeRef(_9351);
    _9351 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9351 = (int)*(((s1_ptr)_2)->base + _9351);
    Ref(_9351);
    Ref(_9351);
    _0 = _9351;
    _9351 = _16GType(_9351);
    DeRef(_0);
    Ref(_9349);
    RefDS(_9novalue);
    _16SetBBType(_9349, 8, _9novalue, _9351);
L2:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9351);
    DeRef(_9349);
    DeRef(_9353);
    return 0;
    ;
}


int _18opDATE()
{
    int _9384 = 0;
    int _0, _1, _2;
    

    //     CDeRef(Code[pc+1])  -- Code[pc+1] not used in next expression
    _9384 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9384 = (int)*(((s1_ptr)_2)->base + _9384);
    Ref(_9384);
    Ref(_9384);
    _18CDeRef(_9384);

    //     c_stmt("@ = Date();\n", Code[pc+1])
    DeRef(_9384);
    _9384 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9384 = (int)*(((s1_ptr)_2)->base + _9384);
    Ref(_9384);
    RefDS(_9386);
    Ref(_9384);
    _16c_stmt(_9386, _9384);

    //     target[MIN] = 8
    _2 = (int)SEQ_PTR(_18target);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = 8;
    DeRef(_1);

    //     SetBBType(Code[pc+1], TYPE_SEQUENCE, target, TYPE_INTEGER)
    DeRef(_9384);
    _9384 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9384 = (int)*(((s1_ptr)_2)->base + _9384);
    Ref(_9384);
    Ref(_9384);
    RefDS(_18target);
    _16SetBBType(_9384, 8, _18target, 1);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_9384);
    return 0;
    ;
}


int _18opTIME()
{
    int _9392 = 0;
    int _0, _1, _2;
    

    //     CDeRef(Code[pc+1]) -- Code[pc+1] not used in next expression
    _9392 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9392 = (int)*(((s1_ptr)_2)->base + _9392);
    Ref(_9392);
    Ref(_9392);
    _18CDeRef(_9392);

    //     c_stmt("@ = NewDouble(current_time());\n", Code[pc+1])
    DeRef(_9392);
    _9392 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9392 = (int)*(((s1_ptr)_2)->base + _9392);
    Ref(_9392);
    RefDS(_9394);
    Ref(_9392);
    _16c_stmt(_9394, _9392);

    //     SetBBType(Code[pc+1], TYPE_DOUBLE, novalue, TYPE_OBJECT)
    DeRef(_9392);
    _9392 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9392 = (int)*(((s1_ptr)_2)->base + _9392);
    Ref(_9392);
    Ref(_9392);
    RefDS(_9novalue);
    _16SetBBType(_9392, 2, _9novalue, 16);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_9392);
    return 0;
    ;
}


int _18opSPACE_USED()
{
    int _9400 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+1], 0, 0, 0)
    _9400 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9400 = (int)*(((s1_ptr)_2)->base + _9400);
    Ref(_9400);
    RefDS(_5774);
    Ref(_9400);
    _18CSaveStr(_5774, _9400, 0, 0, 0);

    //     c_stmt("@ = bytes_allocated;\n", Code[pc+1])
    DeRef(_9400);
    _9400 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9400 = (int)*(((s1_ptr)_2)->base + _9400);
    Ref(_9400);
    RefDS(_9402);
    Ref(_9400);
    _16c_stmt(_9402, _9400);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+1], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_9400);
    _9400 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9400 = (int)*(((s1_ptr)_2)->base + _9400);
    Ref(_9400);
    Ref(_9400);
    RefDS(_9novalue);
    _16SetBBType(_9400, 1, _9novalue, 16);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_9400);
    return 0;
    ;
}


int _18opPOSITION()
{
    int _9411 = 0;
    int _9409 = 0;
    int _0, _1, _2;
    

    //     c_stmt("Position(@, @);\n", {Code[pc+1], Code[pc+2]})
    _9409 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9409 = (int)*(((s1_ptr)_2)->base + _9409);
    Ref(_9409);
    _9411 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9411 = (int)*(((s1_ptr)_2)->base + _9411);
    Ref(_9411);
    _0 = _9411;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9409;
    Ref(_9409);
    ((int *)_2)[2] = _9411;
    Ref(_9411);
    _9411 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9408);
    RefDS(_9411);
    _16c_stmt(_9408, _9411);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_9411);
    DeRef(_9409);
    return 0;
    ;
}


int _18opEQUAL()
{
    int _9415 = 0;
    int _9417 = 0;
    int _9419 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9415 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9415 = (int)*(((s1_ptr)_2)->base + _9415);
    Ref(_9415);
    _9417 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9417 = (int)*(((s1_ptr)_2)->base + _9417);
    Ref(_9417);
    _9419 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9419 = (int)*(((s1_ptr)_2)->base + _9419);
    Ref(_9419);
    RefDS(_5774);
    Ref(_9415);
    Ref(_9417);
    Ref(_9419);
    _18CSaveStr(_5774, _9415, _9417, _9419, 0);

    //     c_stmt("if (@ == @)\n", {Code[pc+1], Code[pc+2]})
    DeRef(_9419);
    _9419 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9419 = (int)*(((s1_ptr)_2)->base + _9419);
    Ref(_9419);
    DeRef(_9417);
    _9417 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9417 = (int)*(((s1_ptr)_2)->base + _9417);
    Ref(_9417);
    _0 = _9417;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9419;
    Ref(_9419);
    ((int *)_2)[2] = _9417;
    Ref(_9417);
    _9417 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9421);
    RefDS(_9417);
    _16c_stmt(_9421, _9417);

    //     c_stmt("@ = 1;\n", Code[pc+3])
    DeRefDS(_9417);
    _9417 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9417 = (int)*(((s1_ptr)_2)->base + _9417);
    Ref(_9417);
    RefDS(_7825);
    Ref(_9417);
    _16c_stmt(_7825, _9417);

    //     c_stmt("else if (IS_ATOM_INT(@) && IS_ATOM_INT(@))\n", 
    DeRef(_9417);
    _9417 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9417 = (int)*(((s1_ptr)_2)->base + _9417);
    Ref(_9417);
    DeRef(_9419);
    _9419 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9419 = (int)*(((s1_ptr)_2)->base + _9419);
    Ref(_9419);
    _0 = _9419;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9417;
    Ref(_9417);
    ((int *)_2)[2] = _9419;
    Ref(_9419);
    _9419 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9429);
    RefDS(_9419);
    _16c_stmt(_9429, _9419);

    //     c_stmt("@ = 0;\n", Code[pc+3])
    DeRefDS(_9419);
    _9419 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9419 = (int)*(((s1_ptr)_2)->base + _9419);
    Ref(_9419);
    RefDS(_7831);
    Ref(_9419);
    _16c_stmt(_7831, _9419);

    //     c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    //     c_stmt("@ = (compare(@, @) == 0);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_9419);
    _9419 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9419 = (int)*(((s1_ptr)_2)->base + _9419);
    Ref(_9419);
    DeRef(_9417);
    _9417 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9417 = (int)*(((s1_ptr)_2)->base + _9417);
    Ref(_9417);
    DeRef(_9415);
    _9415 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9415 = (int)*(((s1_ptr)_2)->base + _9415);
    Ref(_9415);
    _0 = _9415;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9419);
    *((int *)(_2+4)) = _9419;
    Ref(_9417);
    *((int *)(_2+8)) = _9417;
    Ref(_9415);
    *((int *)(_2+12)) = _9415;
    _9415 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9437);
    RefDS(_9415);
    _16c_stmt(_9437, _9415);

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

    //     SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9415);
    _9415 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9415 = (int)*(((s1_ptr)_2)->base + _9415);
    Ref(_9415);
    Ref(_9415);
    RefDS(_18target);
    _16SetBBType(_9415, 1, _18target, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9415);
    DeRef(_9417);
    DeRef(_9419);
    return 0;
    ;
}


