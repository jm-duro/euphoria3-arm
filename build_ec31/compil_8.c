// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opCOMPARE()
{
    int _9451 = 0;
    int _9449 = 0;
    int _9453 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9449 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9449 = (int)*(((s1_ptr)_2)->base + _9449);
    Ref(_9449);
    _9451 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9451 = (int)*(((s1_ptr)_2)->base + _9451);
    Ref(_9451);
    _9453 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9453 = (int)*(((s1_ptr)_2)->base + _9453);
    Ref(_9453);
    RefDS(_5774);
    Ref(_9449);
    Ref(_9451);
    Ref(_9453);
    _18CSaveStr(_5774, _9449, _9451, _9453, 0);

    //     c_stmt("if (IS_ATOM_INT(@) && IS_ATOM_INT(@))\n", {Code[pc+1], Code[pc+2]})
    DeRef(_9453);
    _9453 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9453 = (int)*(((s1_ptr)_2)->base + _9453);
    Ref(_9453);
    DeRef(_9451);
    _9451 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9451 = (int)*(((s1_ptr)_2)->base + _9451);
    Ref(_9451);
    _0 = _9451;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9453;
    Ref(_9453);
    ((int *)_2)[2] = _9451;
    Ref(_9451);
    _9451 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9455);
    RefDS(_9451);
    _16c_stmt(_9455, _9451);

    //     c_stmt("@ = (@ < @) ? -1 : ", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRefDS(_9451);
    _9451 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9451 = (int)*(((s1_ptr)_2)->base + _9451);
    Ref(_9451);
    DeRef(_9453);
    _9453 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9453 = (int)*(((s1_ptr)_2)->base + _9453);
    Ref(_9453);
    DeRef(_9449);
    _9449 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9449 = (int)*(((s1_ptr)_2)->base + _9449);
    Ref(_9449);
    _0 = _9449;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9451);
    *((int *)(_2+4)) = _9451;
    Ref(_9453);
    *((int *)(_2+8)) = _9453;
    Ref(_9449);
    *((int *)(_2+12)) = _9449;
    _9449 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9461);
    RefDS(_9449);
    _16c_stmt(_9461, _9449);

    //     temp_indent = -indent
    _9temp_indent = - _9indent;

    //     c_stmt("(@ > @);\n", {Code[pc+1], Code[pc+2]})
    DeRefDS(_9449);
    _9449 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9449 = (int)*(((s1_ptr)_2)->base + _9449);
    Ref(_9449);
    DeRef(_9453);
    _9453 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9453 = (int)*(((s1_ptr)_2)->base + _9453);
    Ref(_9453);
    _0 = _9453;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9449;
    Ref(_9449);
    ((int *)_2)[2] = _9453;
    Ref(_9453);
    _9453 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9470);
    RefDS(_9453);
    _16c_stmt(_9470, _9453);

    //     c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    //     c_stmt("@ = compare(@, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRefDS(_9453);
    _9453 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9453 = (int)*(((s1_ptr)_2)->base + _9453);
    Ref(_9453);
    DeRef(_9449);
    _9449 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9449 = (int)*(((s1_ptr)_2)->base + _9449);
    Ref(_9449);
    DeRef(_9451);
    _9451 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9451 = (int)*(((s1_ptr)_2)->base + _9451);
    Ref(_9451);
    _0 = _9451;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9453);
    *((int *)(_2+4)) = _9453;
    Ref(_9449);
    *((int *)(_2+8)) = _9449;
    Ref(_9451);
    *((int *)(_2+12)) = _9451;
    _9451 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9476);
    RefDS(_9451);
    _16c_stmt(_9476, _9451);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {-1, 1}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 1;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9451);
    _9451 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9451 = (int)*(((s1_ptr)_2)->base + _9451);
    Ref(_9451);
    Ref(_9451);
    RefDS(_18target);
    _16SetBBType(_9451, 1, _18target, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9451);
    DeRef(_9449);
    DeRef(_9453);
    return 0;
    ;
}


int _18opFIND()
{
    int _9488 = 0;
    int _9490 = 0;
    int _9492 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9488 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9488 = (int)*(((s1_ptr)_2)->base + _9488);
    Ref(_9488);
    _9490 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9490 = (int)*(((s1_ptr)_2)->base + _9490);
    Ref(_9490);
    _9492 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9492 = (int)*(((s1_ptr)_2)->base + _9492);
    Ref(_9492);
    RefDS(_5774);
    Ref(_9488);
    Ref(_9490);
    Ref(_9492);
    _18CSaveStr(_5774, _9488, _9490, _9492, 0);

    //     c_stmt("@ = find(@, @);\n", 
    DeRef(_9492);
    _9492 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9492 = (int)*(((s1_ptr)_2)->base + _9492);
    Ref(_9492);
    DeRef(_9490);
    _9490 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9490 = (int)*(((s1_ptr)_2)->base + _9490);
    Ref(_9490);
    DeRef(_9488);
    _9488 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9488 = (int)*(((s1_ptr)_2)->base + _9488);
    Ref(_9488);
    _0 = _9488;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9492);
    *((int *)(_2+4)) = _9492;
    Ref(_9490);
    *((int *)(_2+8)) = _9490;
    Ref(_9488);
    *((int *)(_2+12)) = _9488;
    _9488 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9494);
    RefDS(_9488);
    _16c_stmt(_9494, _9488);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, MAXLEN}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1072741823;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9488);
    _9488 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9488 = (int)*(((s1_ptr)_2)->base + _9488);
    Ref(_9488);
    Ref(_9488);
    RefDS(_18target);
    _16SetBBType(_9488, 1, _18target, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9488);
    DeRef(_9490);
    DeRef(_9492);
    return 0;
    ;
}


int _18opFIND_FROM()
{
    int _9506 = 0;
    int _9508 = 0;
    int _9510 = 0;
    int _9512 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+4], Code[pc+1], Code[pc+2], Code[pc+3])
    _9506 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9506 = (int)*(((s1_ptr)_2)->base + _9506);
    Ref(_9506);
    _9508 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9508 = (int)*(((s1_ptr)_2)->base + _9508);
    Ref(_9508);
    _9510 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9510 = (int)*(((s1_ptr)_2)->base + _9510);
    Ref(_9510);
    _9512 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9512 = (int)*(((s1_ptr)_2)->base + _9512);
    Ref(_9512);
    RefDS(_5774);
    Ref(_9506);
    Ref(_9508);
    Ref(_9510);
    Ref(_9512);
    _18CSaveStr(_5774, _9506, _9508, _9510, _9512);

    //     c_stmt("@ = find_from(@, @, @);\n", 
    DeRef(_9512);
    _9512 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9512 = (int)*(((s1_ptr)_2)->base + _9512);
    Ref(_9512);
    DeRef(_9510);
    _9510 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9510 = (int)*(((s1_ptr)_2)->base + _9510);
    Ref(_9510);
    DeRef(_9508);
    _9508 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9508 = (int)*(((s1_ptr)_2)->base + _9508);
    Ref(_9508);
    DeRef(_9506);
    _9506 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9506 = (int)*(((s1_ptr)_2)->base + _9506);
    Ref(_9506);
    _0 = _9506;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9512);
    *((int *)(_2+4)) = _9512;
    Ref(_9510);
    *((int *)(_2+8)) = _9510;
    Ref(_9508);
    *((int *)(_2+12)) = _9508;
    Ref(_9506);
    *((int *)(_2+16)) = _9506;
    _9506 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9514);
    RefDS(_9506);
    _16c_stmt(_9514, _9506);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, MAXLEN}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1072741823;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+4], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9506);
    _9506 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9506 = (int)*(((s1_ptr)_2)->base + _9506);
    Ref(_9506);
    Ref(_9506);
    RefDS(_18target);
    _16SetBBType(_9506, 1, _18target, 16);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_9506);
    DeRef(_9508);
    DeRef(_9510);
    DeRef(_9512);
    return 0;
    ;
}


int _18opMATCH()
{
    int _9528 = 0;
    int _9530 = 0;
    int _9532 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9528 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    _9530 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9530 = (int)*(((s1_ptr)_2)->base + _9530);
    Ref(_9530);
    _9532 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9532 = (int)*(((s1_ptr)_2)->base + _9532);
    Ref(_9532);
    RefDS(_5774);
    Ref(_9528);
    Ref(_9530);
    Ref(_9532);
    _18CSaveStr(_5774, _9528, _9530, _9532, 0);

    //     c_stmt("@ = e_match(@, @);\n", 
    DeRef(_9532);
    _9532 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9532 = (int)*(((s1_ptr)_2)->base + _9532);
    Ref(_9532);
    DeRef(_9530);
    _9530 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9530 = (int)*(((s1_ptr)_2)->base + _9530);
    Ref(_9530);
    DeRef(_9528);
    _9528 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    _0 = _9528;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9532);
    *((int *)(_2+4)) = _9532;
    Ref(_9530);
    *((int *)(_2+8)) = _9530;
    Ref(_9528);
    *((int *)(_2+12)) = _9528;
    _9528 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9534);
    RefDS(_9528);
    _16c_stmt(_9534, _9528);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, MAXLEN}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1072741823;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9528);
    _9528 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9528 = (int)*(((s1_ptr)_2)->base + _9528);
    Ref(_9528);
    Ref(_9528);
    RefDS(_18target);
    _16SetBBType(_9528, 1, _18target, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9528);
    DeRef(_9530);
    DeRef(_9532);
    return 0;
    ;
}


int _18opMATCH_FROM()
{
    int _9546 = 0;
    int _9548 = 0;
    int _9550 = 0;
    int _9552 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+4], Code[pc+1], Code[pc+2], Code[pc+3])
    _9546 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9546 = (int)*(((s1_ptr)_2)->base + _9546);
    Ref(_9546);
    _9548 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9548 = (int)*(((s1_ptr)_2)->base + _9548);
    Ref(_9548);
    _9550 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9550 = (int)*(((s1_ptr)_2)->base + _9550);
    Ref(_9550);
    _9552 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9552 = (int)*(((s1_ptr)_2)->base + _9552);
    Ref(_9552);
    RefDS(_5774);
    Ref(_9546);
    Ref(_9548);
    Ref(_9550);
    Ref(_9552);
    _18CSaveStr(_5774, _9546, _9548, _9550, _9552);

    //     c_stmt("@ = e_match_from(@, @, @);\n", 
    DeRef(_9552);
    _9552 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9552 = (int)*(((s1_ptr)_2)->base + _9552);
    Ref(_9552);
    DeRef(_9550);
    _9550 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9550 = (int)*(((s1_ptr)_2)->base + _9550);
    Ref(_9550);
    DeRef(_9548);
    _9548 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9548 = (int)*(((s1_ptr)_2)->base + _9548);
    Ref(_9548);
    DeRef(_9546);
    _9546 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9546 = (int)*(((s1_ptr)_2)->base + _9546);
    Ref(_9546);
    _0 = _9546;
    _1 = NewS1(4);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9552);
    *((int *)(_2+4)) = _9552;
    Ref(_9550);
    *((int *)(_2+8)) = _9550;
    Ref(_9548);
    *((int *)(_2+12)) = _9548;
    Ref(_9546);
    *((int *)(_2+16)) = _9546;
    _9546 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9554);
    RefDS(_9546);
    _16c_stmt(_9554, _9546);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {0, MAXLEN}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1072741823;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+4], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9546);
    _9546 = _18pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _9546 = (int)*(((s1_ptr)_2)->base + _9546);
    Ref(_9546);
    Ref(_9546);
    RefDS(_18target);
    _16SetBBType(_9546, 1, _18target, 16);

    //     pc += 5
    _18pc = _18pc + 5;

    // end procedure
    DeRef(_9546);
    DeRef(_9548);
    DeRef(_9550);
    DeRef(_9552);
    return 0;
    ;
}


int _18opPEEK()
{
    int _9570 = 0;
    int _9568 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_5774);
    Ref(_9568);
    Ref(_9570);
    _18CSaveStr(_5774, _9568, _9570, 0, 0);

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_5781);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, _5781);
    DeRef(_0);
    if (_9570 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_6192);
    Ref(_9570);
    _16c_stmt(_6192, _9570);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_6197);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, _6197);
    DeRef(_0);
    if (_9570 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L2;
    }

    // 	if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L3;

    // 	    seg_peek1(Code[pc+2], Code[pc+1], 0)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    Ref(_9570);
    Ref(_9568);
    _18seg_peek1(_9570, _9568, 0);
    goto L4;
L3:

    // 	    seg_peek4(Code[pc+2], Code[pc+1], 0)
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9568);
    Ref(_9570);
    _18seg_peek4(_9568, _9570, 0);

    // 	    SetBBType(Code[pc+2], GType(Code[pc+2]), novalue, TYPE_OBJECT)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    Ref(_9568);
    _0 = _9568;
    _9568 = _16GType(_9568);
    DeRef(_0);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, _9568, _9novalue, 16);

    // 	    if Code[pc] = PEEK4S then
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9568);
    if (binary_op_a(NOTEQ, _9568, 141))
        goto L5;

    // 		c_stmt("if (@ < MININT || @ > MAXINT)\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    _0 = _9570;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9568;
    Ref(_9568);
    ((int *)_2)[2] = _9570;
    Ref(_9570);
    _9570 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9597);
    RefDS(_9570);
    _16c_stmt(_9597, _9570);

    // 		c_stmt("@ = NewDouble((double)(long)@);\n", 
    DeRefDS(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    _0 = _9568;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9570;
    Ref(_9570);
    ((int *)_2)[2] = _9568;
    Ref(_9568);
    _9568 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9603);
    RefDS(_9568);
    _16c_stmt(_9603, _9568);
    goto L6;
L5:

    // 		c_stmt("if ((unsigned)@ > (unsigned)MAXINT)\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    RefDS(_9609);
    Ref(_9568);
    _16c_stmt(_9609, _9568);

    // 		c_stmt("@ = NewDouble((double)(unsigned long)@);\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    _0 = _9570;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9568;
    Ref(_9568);
    ((int *)_2)[2] = _9570;
    Ref(_9570);
    _9570 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9612);
    RefDS(_9570);
    _16c_stmt(_9612, _9570);
L6:
L4:
L2:

    //     if TypeIs(Code[pc+1], TYPE_ATOM) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, 4);
    DeRef(_0);
    if (_9570 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L7;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt("else {\n", Code[pc+1])
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_6208);
    Ref(_9570);
    _16c_stmt(_6208, _9570);
    goto L8;
L7:

    //     elsif TypeIs(Code[pc+1], TYPE_OBJECT) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, 16);
    DeRef(_0);
    if (_9570 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L9;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt("else if (IS_ATOM(@)) {\n", Code[pc+1])
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_9626);
    Ref(_9570);
    _16c_stmt(_9626, _9570);
L9:
L8:

    //     if TypeIsNot(Code[pc+1], {TYPE_INTEGER, TYPE_SEQUENCE}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_9631);
    _0 = _9570;
    _9570 = _16TypeIsNot(_9570, _9631);
    DeRef(_0);
    if (_9570 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto LA;
    }

    // 	if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto LB;

    // 	    seg_peek1(Code[pc+2], Code[pc+1], 1)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    Ref(_9570);
    Ref(_9568);
    _18seg_peek1(_9570, _9568, 1);
    goto LC;
LB:

    // 	    seg_peek4(Code[pc+2], Code[pc+1], 1)
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9568);
    Ref(_9570);
    _18seg_peek4(_9568, _9570, 1);

    // 	    SetBBType(Code[pc+2], GType(Code[pc+2]), novalue, TYPE_OBJECT)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    Ref(_9568);
    _0 = _9568;
    _9568 = _16GType(_9568);
    DeRef(_0);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, _9568, _9novalue, 16);

    // 	    if Code[pc] = PEEK4S then
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9568);
    if (binary_op_a(NOTEQ, _9568, 141))
        goto LD;

    // 		c_stmt("if (@ < MININT || @ > MAXINT)\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    _0 = _9570;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9568;
    Ref(_9568);
    ((int *)_2)[2] = _9570;
    Ref(_9570);
    _9570 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9597);
    RefDS(_9570);
    _16c_stmt(_9597, _9570);

    // 		c_stmt("@ = NewDouble((double)(long)@);\n", 
    DeRefDS(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    _0 = _9568;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9570;
    Ref(_9570);
    ((int *)_2)[2] = _9568;
    Ref(_9568);
    _9568 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9603);
    RefDS(_9568);
    _16c_stmt(_9603, _9568);
    goto LE;
LD:

    // 		c_stmt("if ((unsigned)@ > (unsigned)MAXINT)\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    RefDS(_9609);
    Ref(_9568);
    _16c_stmt(_9609, _9568);

    // 		c_stmt("@ = NewDouble((double)(unsigned long)@);\n", 
    DeRef(_9568);
    _9568 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9568 = (int)*(((s1_ptr)_2)->base + _9568);
    Ref(_9568);
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    _0 = _9570;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9568;
    Ref(_9568);
    ((int *)_2)[2] = _9570;
    Ref(_9570);
    _9570 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9612);
    RefDS(_9570);
    _16c_stmt(_9612, _9570);
LE:
LC:
LA:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_5781);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, _5781);
    DeRef(_0);
    if (_9570 == 0) {
        goto LF;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto LF;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
LF:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, 16);
    DeRef(_0);
    if (_9570 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L10;
    }

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L10:

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_4094);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, _4094);
    DeRef(_0);
    if (_9570 == 0) {
        goto L11;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L11;
    }

    // 	c_stmt("_1 = (int)SEQ_PTR(@);\n", Code[pc+1])
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_8748);
    Ref(_9570);
    _16c_stmt(_8748, _9570);

    // 	if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L12;

    // 	    c_stmt0("poke_addr = (unsigned char *)get_pos_int(\"peek\", *(((s1_ptr)_1)->base+1));\n")
    RefDS(_9680);
    _16c_stmt0(_9680);
    goto L13;
L12:

    // 	    c_stmt0("peek4_addr = (unsigned long *)get_pos_int(\"peek4s/peek4u\", *(((s1_ptr)_1)->base+1));\n")
    RefDS(_9681);
    _16c_stmt0(_9681);
L13:

    // 	c_stmt0("_2 = get_pos_int(\"peek\", *(((s1_ptr)_1)->base+2));\n")
    RefDS(_9682);
    _16c_stmt0(_9682);

    // 	c_stmt("poke4_addr = (unsigned long *)NewS1(_2);\n", Code[pc+2])
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_9683);
    Ref(_9570);
    _16c_stmt(_9683, _9570);

    // 	c_stmt("@ = MAKE_SEQ(poke4_addr);\n", Code[pc+2])
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    RefDS(_9686);
    Ref(_9570);
    _16c_stmt(_9686, _9570);

    // 	c_stmt0("poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;\n")
    RefDS(_9689);
    _16c_stmt0(_9689);

    // 	if sequence(dj_path) then
    DeRef(_9570);
    _9570 = IS_SEQUENCE(_4dj_path);
    if (_9570 == 0)
        goto L14;

    // 	    if Code[pc] = PEEK then  
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L15;

    // 		c_stmt0("if ((unsigned)poke_addr <= LOW_MEMORY_MAX) {\n")
    RefDS(_9693);
    _16c_stmt0(_9693);
    goto L16;
L15:

    // 		c_stmt0("if ((unsigned)peek4_addr <= LOW_MEMORY_MAX) {\n")
    RefDS(_9694);
    _16c_stmt0(_9694);
L16:

    // 	    c_stmt0("while (--_2 >= 0) {\n")  -- SLOW WHILE
    RefDS(_9695);
    _16c_stmt0(_9695);

    // 	    c_stmt0("poke4_addr++;\n")
    RefDS(_9696);
    _16c_stmt0(_9696);

    // 	    if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L17;

    // 		c_stmt0("*(int *)poke4_addr = _farpeekb(_go32_info_block.selector_for_linear_memory, (unsigned)(poke_addr++));\n")
    RefDS(_9699);
    _16c_stmt0(_9699);
    goto L18;
L17:

    // 		c_stmt0("_1 = _farpeekl(_go32_info_block.selector_for_linear_memory, (unsigned)(peek4_addr++));\n")
    RefDS(_9700);
    _16c_stmt0(_9700);

    // 		if Code[pc] = PEEK4S then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 141))
        goto L19;

    // 		    c_stmt0("if (_1 < MININT || _1 > MAXINT)\n")
    RefDS(_9703);
    _16c_stmt0(_9703);

    // 		    c_stmt0("_1 = NewDouble((double)(long)_1);\n")
    RefDS(_9704);
    _16c_stmt0(_9704);
    goto L1A;
L19:

    // 		    c_stmt0("if ((unsigned)_1 > (unsigned)MAXINT)\n")
    RefDS(_9705);
    _16c_stmt0(_9705);

    // 		    c_stmt0("_1 = NewDouble((double)(unsigned long)_1);\n")
    RefDS(_9706);
    _16c_stmt0(_9706);
L1A:

    // 		c_stmt0("*(int *)poke4_addr = _1;\n")
    RefDS(_9707);
    _16c_stmt0(_9707);
L18:

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L14:

    // 	c_stmt0("while (--_2 >= 0) {\n")  -- FAST WHILE
    RefDS(_9695);
    _16c_stmt0(_9695);

    // 	c_stmt0("poke4_addr++;\n")
    RefDS(_9696);
    _16c_stmt0(_9696);

    // 	if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L1B;

    // 	    c_stmt0("*(int *)poke4_addr = *poke_addr++;\n")
    RefDS(_9710);
    _16c_stmt0(_9710);
    goto L1C;
L1B:

    // 	    c_stmt0("_1 = (int)*peek4_addr++;\n")
    RefDS(_9711);
    _16c_stmt0(_9711);

    // 	    if Code[pc] = PEEK4S then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 141))
        goto L1D;

    // 		c_stmt0("if (_1 < MININT || _1 > MAXINT)\n")
    RefDS(_9703);
    _16c_stmt0(_9703);

    // 		c_stmt0("_1 = NewDouble((double)(long)_1);\n")
    RefDS(_9704);
    _16c_stmt0(_9704);
    goto L1E;
L1D:

    // 		c_stmt0("if ((unsigned)_1 > (unsigned)MAXINT)\n")
    RefDS(_9705);
    _16c_stmt0(_9705);

    // 		c_stmt0("_1 = NewDouble((double)(unsigned long)_1);\n")
    RefDS(_9706);
    _16c_stmt0(_9706);
L1E:

    // 	    c_stmt0("*(int *)poke4_addr = _1;\n")
    RefDS(_9707);
    _16c_stmt0(_9707);
L1C:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	if sequence(dj_path) then 
    DeRef(_9570);
    _9570 = IS_SEQUENCE(_4dj_path);
    if (_9570 == 0)
        goto L1F;

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L1F:
L11:

    //     if TypeIs(Code[pc+1], TYPE_OBJECT) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, 16);
    DeRef(_0);
    if (_9570 == 0) {
        goto L20;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L20;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L20:

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_DOUBLE}) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_7867);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, _7867);
    DeRef(_0);
    if (_9570 == 0) {
        goto L21;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L21;
    }

    // 	if Code[pc] = PEEK then
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L22;

    // 	    target = {0, 255}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 255;
    _18target = MAKE_SEQ(_1);

    // 	    SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_18target);
    _16SetBBType(_9570, 1, _18target, 16);
    goto L23;
L22:

    // 	    SetBBType(Code[pc+2], TYPE_ATOM, novalue, TYPE_OBJECT)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, 4, _9novalue, 16);
L24:
    goto L23;
L21:

    //     elsif TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRef(_9570);
    _9570 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    _0 = _9570;
    _9570 = _16TypeIs(_9570, 8);
    DeRef(_0);
    if (_9570 == 0) {
        goto L25;
    }
    else {
        if (!IS_ATOM_INT(_9570) && DBL_PTR(_9570)->dbl == 0.0)
            goto L25;
    }

    // 	if Code[pc] = PEEK then 
    DeRef(_9570);
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9570);
    if (binary_op_a(NOTEQ, _9570, 127))
        goto L26;

    // 	    SetBBType(Code[pc+2], TYPE_SEQUENCE, novalue, TYPE_INTEGER)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, 8, _9novalue, 1);
    goto L23;
L26:

    // 	    SetBBType(Code[pc+2], TYPE_SEQUENCE, novalue, TYPE_ATOM)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, 8, _9novalue, 4);
L27:
    goto L23;
L25:

    // 	SetBBType(Code[pc+2], TYPE_OBJECT, novalue, TYPE_OBJECT)
    DeRef(_9570);
    _9570 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9570 = (int)*(((s1_ptr)_2)->base + _9570);
    Ref(_9570);
    Ref(_9570);
    RefDS(_9novalue);
    _16SetBBType(_9570, 16, _9novalue, 16);
L23:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_9570);
    DeRef(_9568);
    return 0;
    ;
}


int _18opPOKE()
{
    int _9740 = 0;
    int _9837;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_5781);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _5781);
    DeRef(_0);
    if (_9740 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_5783);
    Ref(_9740);
    _16c_stmt(_5783, _9740);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_6197);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _6197);
    DeRef(_0);
    if (_9740 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L2;
    }

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L3;

    // 	    c_stmt("poke4_addr = (unsigned long *)@;\n", Code[pc+1])
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_9750);
    Ref(_9740);
    _16c_stmt(_9750, _9740);
    goto L4;
L3:

    // 	    c_stmt("poke_addr = (unsigned char *)@;\n", Code[pc+1])
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_9753);
    Ref(_9740);
    _16c_stmt(_9753, _9740);
L4:
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_5781);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _5781);
    DeRef(_0);
    if (_9740 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L5:

    //     if TypeIsNot(Code[pc+1], {TYPE_INTEGER, TYPE_SEQUENCE}) then
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_9631);
    _0 = _9740;
    _9740 = _16TypeIsNot(_9740, _9631);
    DeRef(_0);
    if (_9740 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L6;
    }

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L7;

    // 	    c_stmt("poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(@)->dbl);\n", 
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_9764);
    Ref(_9740);
    _16c_stmt(_9764, _9740);
    goto L8;
L7:

    // 	    c_stmt("poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(@)->dbl);\n", 
    DeRef(_9740);
    _9740 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_9767);
    Ref(_9740);
    _16c_stmt(_9767, _9740);
L8:
L6:

    //     if TypeIs(Code[pc+2], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_5781);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _5781);
    DeRef(_0);
    if (_9740 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L9;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+2])
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_6192);
    Ref(_9740);
    _16c_stmt(_6192, _9740);
L9:

    //     if TypeIs(Code[pc+2], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_6197);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _6197);
    DeRef(_0);
    if (_9740 == 0) {
        goto LA;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto LA;
    }

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto LB;

    // 	    seg_poke4(Code[pc+2], 0)
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _18seg_poke4(_9740, 0);
    goto LC;
LB:

    // 	    seg_poke1(Code[pc+2], 0)
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _18seg_poke1(_9740, 0);
LC:
LA:

    //     if TypeIs(Code[pc+2], TYPE_ATOM) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, 4);
    DeRef(_0);
    if (_9740 == 0) {
        goto LD;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto LD;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
    goto LE;
LD:

    //     elsif TypeIs(Code[pc+2], TYPE_OBJECT) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, 16);
    DeRef(_0);
    if (_9740 == 0) {
        goto LF;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto LF;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt("else if (IS_ATOM(@)) {\n", Code[pc+2])
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_9626);
    Ref(_9740);
    _16c_stmt(_9626, _9740);
LF:
LE:

    //     if TypeIsNot(Code[pc+2], {TYPE_INTEGER, TYPE_SEQUENCE}) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_9631);
    _0 = _9740;
    _9740 = _16TypeIsNot(_9740, _9631);
    DeRef(_0);
    if (_9740 == 0) {
        goto L10;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L10;
    }

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L11;

    // 	    seg_poke4(Code[pc+2], 1)
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _18seg_poke4(_9740, 1);
    goto L12;
L11:

    // 	    seg_poke1(Code[pc+2], 1)
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _18seg_poke1(_9740, 1);
L12:
L10:

    //     if TypeIs(Code[pc+2], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_5781);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _5781);
    DeRef(_0);
    if (_9740 == 0) {
        goto L13;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L13;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L13:

    //     if TypeIs(Code[pc+2], TYPE_OBJECT) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, 16);
    DeRef(_0);
    if (_9740 == 0) {
        goto L14;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L14;
    }

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L14:

    //     if TypeIs(Code[pc+2], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    RefDS(_4094);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, _4094);
    DeRef(_0);
    if (_9740 == 0) {
        goto L15;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L15;
    }

    // 	c_stmt("_1 = (int)SEQ_PTR(@);\n", Code[pc+2])
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    RefDS(_8748);
    Ref(_9740);
    _16c_stmt(_8748, _9740);

    // 	c_stmt0("_1 = (int)((s1_ptr)_1)->base;\n")
    RefDS(_9812);
    _16c_stmt0(_9812);

    // 	if sequence(dj_path) then
    DeRef(_9740);
    _9740 = IS_SEQUENCE(_4dj_path);
    if (_9740 == 0)
        goto L16;

    // 	    if Code[pc] = POKE4 then
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L17;

    // 		c_stmt0("if ((unsigned)poke4_addr <= LOW_MEMORY_MAX) {\n")
    RefDS(_9816);
    _16c_stmt0(_9816);
    goto L18;
L17:

    // 		c_stmt0("if ((unsigned)poke_addr <= LOW_MEMORY_MAX) {\n")
    RefDS(_9693);
    _16c_stmt0(_9693);
L18:

    // 	    c_stmt0("while (1) {\n")  -- SLOW WHILE
    RefDS(_9817);
    _16c_stmt0(_9817);

    // 	    c_stmt0("_1 += 4;\n")
    RefDS(_9818);
    _16c_stmt0(_9818);

    // 	    c_stmt0("_2 = *((int *)_1);\n")
    RefDS(_9819);
    _16c_stmt0(_9819);

    // 	    c_stmt0("if (IS_ATOM_INT(_2))\n")
    RefDS(_9820);
    _16c_stmt0(_9820);

    // 	    if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L19;

    // 		c_stmt0("_farpokel(_go32_info_block.selector_for_linear_memory, (unsigned long)(poke4_addr++), (unsigned long)_2);\n")
    RefDS(_9823);
    _16c_stmt0(_9823);
    goto L1A;
L19:

    // 		c_stmt0("_farpokeb(_go32_info_block.selector_for_linear_memory, (unsigned long)(poke_addr++), (unsigned char)_2);\n")
    RefDS(_9824);
    _16c_stmt0(_9824);
L1A:

    // 	    c_stmt0("else if (_2 == NOVALUE)\n")
    RefDS(_9825);
    _16c_stmt0(_9825);

    // 	    c_stmt0("break;\n")
    RefDS(_8780);
    _16c_stmt0(_8780);

    // 	    c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    // 	    if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L1B;

    // 		c_stmt0("_farpokel(_go32_info_block.selector_for_linear_memory, (unsigned long)(poke4_addr++), (unsigned long)DBL_PTR(_2)->dbl);\n")
    RefDS(_9828);
    _16c_stmt0(_9828);
    goto L1C;
L1B:

    // 		c_stmt0("_farpokeb(_go32_info_block.selector_for_linear_memory, (unsigned long)(poke_addr++), (unsigned char)DBL_PTR(_2)->dbl);\n")
    RefDS(_9829);
    _16c_stmt0(_9829);
L1C:

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	    c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L16:

    // 	c_stmt0("while (1) {\n") -- FAST WHILE 
    RefDS(_9817);
    _16c_stmt0(_9817);

    // 	c_stmt0("_1 += 4;\n")
    RefDS(_9818);
    _16c_stmt0(_9818);

    // 	c_stmt0("_2 = *((int *)_1);\n")
    RefDS(_9819);
    _16c_stmt0(_9819);

    // 	c_stmt0("if (IS_ATOM_INT(_2))\n")
    RefDS(_9820);
    _16c_stmt0(_9820);

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L1D;

    // 	    c_stmt0("*(int *)poke4_addr++ = (unsigned long)_2;\n")
    RefDS(_9832);
    _16c_stmt0(_9832);
    goto L1E;
L1D:

    // 	    c_stmt0("*poke_addr++ = (unsigned char)_2;\n")
    RefDS(_9833);
    _16c_stmt0(_9833);
L1E:

    // 	c_stmt0("else if (_2 == NOVALUE)\n")
    RefDS(_9825);
    _16c_stmt0(_9825);

    // 	c_stmt0("break;\n")
    RefDS(_8780);
    _16c_stmt0(_8780);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);

    // 	if Code[pc] = POKE4 then
    DeRef(_9740);
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9740);
    if (binary_op_a(NOTEQ, _9740, 140))
        goto L1F;

    // 	    if EWINDOWS and atom(bor_path) and atom(wat_path) then
    if (_4EWINDOWS == 0) {
        DeRef(_9740);
        _9740 = 0;
        goto L20;
    }
    _9837 = IS_ATOM(_4bor_path);
    _9740 = (_9837 != 0);
L20:
    if (_9740 == 0) {
        goto L21;
    }
    DeRef(_9740);
    _9740 = IS_ATOM(_4wat_path);
L22:
    if (_9740 == 0)
        goto L21;

    // 		c_stmt0("_0 = (unsigned long)DBL_PTR(_2)->dbl;\n")
    RefDS(_9840);
    _16c_stmt0(_9840);

    // 		c_stmt0("*(int *)poke4_addr++ = (unsigned long)_0;\n")
    RefDS(_9841);
    _16c_stmt0(_9841);
    goto L23;
L21:

    // 		c_stmt0("*(int *)poke4_addr++ = (unsigned long)DBL_PTR(_2)->dbl;\n")
    RefDS(_9842);
    _16c_stmt0(_9842);
L24:
    goto L23;
L1F:

    // 	    if EWINDOWS and atom(bor_path) and atom(wat_path) then
    if (_4EWINDOWS == 0) {
        DeRef(_9740);
        _9740 = 0;
        goto L25;
    }
    _9837 = IS_ATOM(_4bor_path);
    _9740 = (_9837 != 0);
L25:
    if (_9740 == 0) {
        goto L26;
    }
    DeRef(_9740);
    _9740 = IS_ATOM(_4wat_path);
L27:
    if (_9740 == 0)
        goto L26;

    // 		c_stmt0("_0 = (signed char)DBL_PTR(_2)->dbl;\n")
    RefDS(_9847);
    _16c_stmt0(_9847);

    // 		c_stmt0("*poke_addr++ = (signed char)_0;\n")
    RefDS(_9848);
    _16c_stmt0(_9848);
    goto L28;
L26:

    // 		c_stmt0("*poke_addr++ = (signed char)DBL_PTR(_2)->dbl;\n")
    RefDS(_9849);
    _16c_stmt0(_9849);
L28:
L23:

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	if sequence(dj_path) then
    DeRef(_9740);
    _9740 = IS_SEQUENCE(_4dj_path);
    if (_9740 == 0)
        goto L29;

    // 	    c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L29:
L15:

    //     if TypeIs(Code[pc+2], TYPE_OBJECT) then
    DeRef(_9740);
    _9740 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9740 = (int)*(((s1_ptr)_2)->base + _9740);
    Ref(_9740);
    Ref(_9740);
    _0 = _9740;
    _9740 = _16TypeIs(_9740, 16);
    DeRef(_0);
    if (_9740 == 0) {
        goto L2A;
    }
    else {
        if (!IS_ATOM_INT(_9740) && DBL_PTR(_9740)->dbl == 0.0)
            goto L2A;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L2A:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_9740);
    return 0;
    ;
}


int _18opMEM_COPY()
{
    int _9860 = 0;
    int _9858 = 0;
    int _9856 = 0;
    int _0, _1, _2;
    

    //     c_stmt("memory_copy(@, @, @);\n", {Code[pc+1], Code[pc+2], Code[pc+3]})
    _9856 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9856 = (int)*(((s1_ptr)_2)->base + _9856);
    Ref(_9856);
    _9858 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9858 = (int)*(((s1_ptr)_2)->base + _9858);
    Ref(_9858);
    _9860 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9860 = (int)*(((s1_ptr)_2)->base + _9860);
    Ref(_9860);
    _0 = _9860;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9856);
    *((int *)(_2+4)) = _9856;
    Ref(_9858);
    *((int *)(_2+8)) = _9858;
    Ref(_9860);
    *((int *)(_2+12)) = _9860;
    _9860 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9855);
    RefDS(_9860);
    _16c_stmt(_9855, _9860);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRefDS(_9860);
    DeRef(_9858);
    DeRef(_9856);
    return 0;
    ;
}


int _18opMEM_SET()
{
    int _9869 = 0;
    int _9867 = 0;
    int _9865 = 0;
    int _0, _1, _2;
    

    //     c_stmt("memory_set(@, @, @);\n", {Code[pc+1], Code[pc+2], Code[pc+3]})
    _9865 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9865 = (int)*(((s1_ptr)_2)->base + _9865);
    Ref(_9865);
    _9867 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9867 = (int)*(((s1_ptr)_2)->base + _9867);
    Ref(_9867);
    _9869 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9869 = (int)*(((s1_ptr)_2)->base + _9869);
    Ref(_9869);
    _0 = _9869;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9865);
    *((int *)(_2+4)) = _9865;
    Ref(_9867);
    *((int *)(_2+8)) = _9867;
    Ref(_9869);
    *((int *)(_2+12)) = _9869;
    _9869 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9864);
    RefDS(_9869);
    _16c_stmt(_9864, _9869);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRefDS(_9869);
    DeRef(_9867);
    DeRef(_9865);
    return 0;
    ;
}


int _18opPIXEL()
{
    int _9876 = 0;
    int _9874 = 0;
    int _0, _1, _2;
    

    //     c_stmt("Pixel(@, @);\n", {Code[pc+1], Code[pc+2]})
    _9874 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9874 = (int)*(((s1_ptr)_2)->base + _9874);
    Ref(_9874);
    _9876 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9876 = (int)*(((s1_ptr)_2)->base + _9876);
    Ref(_9876);
    _0 = _9876;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9874;
    Ref(_9874);
    ((int *)_2)[2] = _9876;
    Ref(_9876);
    _9876 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9873);
    RefDS(_9876);
    _16c_stmt(_9873, _9876);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_9876);
    DeRef(_9874);
    return 0;
    ;
}


int _18opGET_PIXEL()
{
    int _9880 = 0;
    int _9882 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+2], Code[pc+1], 0, 0)
    _9880 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    _9882 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9882 = (int)*(((s1_ptr)_2)->base + _9882);
    Ref(_9882);
    RefDS(_5774);
    Ref(_9880);
    Ref(_9882);
    _18CSaveStr(_5774, _9880, _9882, 0, 0);

    //     c_stmt("@ = Get_Pixel(@);\n", {Code[pc+2], Code[pc+1]})
    DeRef(_9882);
    _9882 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9882 = (int)*(((s1_ptr)_2)->base + _9882);
    Ref(_9882);
    DeRef(_9880);
    _9880 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    _0 = _9880;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9882;
    Ref(_9882);
    ((int *)_2)[2] = _9880;
    Ref(_9880);
    _9880 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9884);
    RefDS(_9880);
    _16c_stmt(_9884, _9880);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     if TypeIs(Code[pc+1], TYPE_SEQUENCE) then
    DeRefDS(_9880);
    _9880 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    _0 = _9880;
    _9880 = _16TypeIs(_9880, 8);
    DeRef(_0);
    if (_9880 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9880) && DBL_PTR(_9880)->dbl == 0.0)
            goto L1;
    }

    // 	if SeqLen(Code[pc+1]) = 2 then
    DeRef(_9880);
    _9880 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    _0 = _9880;
    _9880 = _18SeqLen(_9880);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _9880, 2))
        goto L2;

    // 	    target = {0, 255}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 255;
    _18target = MAKE_SEQ(_1);

    // 	    SetBBType(Code[pc+2], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRef(_9880);
    _9880 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    RefDS(_18target);
    _16SetBBType(_9880, 1, _18target, 16);
    goto L3;
L2:

    // 	elsif SeqLen(Code[pc+1]) = 3 then
    DeRef(_9880);
    _9880 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    _0 = _9880;
    _9880 = _18SeqLen(_9880);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _9880, 3))
        goto L4;

    // 	    SetBBType(Code[pc+2], TYPE_SEQUENCE, novalue, TYPE_INTEGER)
    DeRef(_9880);
    _9880 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    RefDS(_9novalue);
    _16SetBBType(_9880, 8, _9novalue, 1);
    goto L3;
L4:

    // 	    SetBBType(Code[pc+2], TYPE_OBJECT, novalue, TYPE_OBJECT)
    DeRef(_9880);
    _9880 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    RefDS(_9novalue);
    _16SetBBType(_9880, 16, _9novalue, 16);
L5:
    goto L3;
L1:

    // 	SetBBType(Code[pc+2], TYPE_OBJECT, novalue, TYPE_OBJECT)
    DeRef(_9880);
    _9880 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9880 = (int)*(((s1_ptr)_2)->base + _9880);
    Ref(_9880);
    Ref(_9880);
    RefDS(_9novalue);
    _16SetBBType(_9880, 16, _9novalue, 16);
L3:

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRef(_9880);
    DeRef(_9882);
    return 0;
    ;
}


int _18opCALL()
{
    int _9911 = 0;
    int _0, _1, _2;
    

    //     c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    _9911 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9911 = (int)*(((s1_ptr)_2)->base + _9911);
    Ref(_9911);
    RefDS(_5783);
    Ref(_9911);
    _16c_stmt(_5783, _9911);

    //     c_stmt("_0 = (int)@;\n", Code[pc+1])
    DeRef(_9911);
    _9911 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9911 = (int)*(((s1_ptr)_2)->base + _9911);
    Ref(_9911);
    RefDS(_9913);
    Ref(_9911);
    _16c_stmt(_9913, _9911);

    //     c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);

    //     c_stmt("_0 = (int)(unsigned long)(DBL_PTR(@)->dbl);\n", Code[pc+1])
    DeRef(_9911);
    _9911 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9911 = (int)*(((s1_ptr)_2)->base + _9911);
    Ref(_9911);
    RefDS(_9916);
    Ref(_9911);
    _16c_stmt(_9916, _9911);

    //     c_stmt0("(*(void(*)())_0)();\n")
    RefDS(_9919);
    _16c_stmt0(_9919);

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_9911);
    return 0;
    ;
}


int _18opSYSTEM()
{
    int _9924 = 0;
    int _9922 = 0;
    int _0, _1, _2;
    

    //     c_stmt("system_call(@, @);\n", {Code[pc+1], Code[pc+2]})
    _9922 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9922 = (int)*(((s1_ptr)_2)->base + _9922);
    Ref(_9922);
    _9924 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9924 = (int)*(((s1_ptr)_2)->base + _9924);
    Ref(_9924);
    _0 = _9924;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _9922;
    Ref(_9922);
    ((int *)_2)[2] = _9924;
    Ref(_9924);
    _9924 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9921);
    RefDS(_9924);
    _16c_stmt(_9921, _9924);

    //     pc += 3
    _18pc = _18pc + 3;

    // end procedure
    DeRefDS(_9924);
    DeRef(_9922);
    return 0;
    ;
}


int _18opSYSTEM_EXEC()
{
    int _9928 = 0;
    int _9930 = 0;
    int _9932 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9928 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9928 = (int)*(((s1_ptr)_2)->base + _9928);
    Ref(_9928);
    _9930 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9930 = (int)*(((s1_ptr)_2)->base + _9930);
    Ref(_9930);
    _9932 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9932 = (int)*(((s1_ptr)_2)->base + _9932);
    Ref(_9932);
    RefDS(_5774);
    Ref(_9928);
    Ref(_9930);
    Ref(_9932);
    _18CSaveStr(_5774, _9928, _9930, _9932, 0);

    //     c_stmt("@ = system_exec_call(@, @);\n", 
    DeRef(_9932);
    _9932 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9932 = (int)*(((s1_ptr)_2)->base + _9932);
    Ref(_9932);
    DeRef(_9930);
    _9930 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9930 = (int)*(((s1_ptr)_2)->base + _9930);
    Ref(_9930);
    DeRef(_9928);
    _9928 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9928 = (int)*(((s1_ptr)_2)->base + _9928);
    Ref(_9928);
    _0 = _9928;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9932);
    *((int *)(_2+4)) = _9932;
    Ref(_9930);
    *((int *)(_2+8)) = _9930;
    Ref(_9928);
    *((int *)(_2+12)) = _9928;
    _9928 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9934);
    RefDS(_9928);
    _16c_stmt(_9934, _9928);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     SetBBType(Code[pc+3], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRefDS(_9928);
    _9928 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9928 = (int)*(((s1_ptr)_2)->base + _9928);
    Ref(_9928);
    Ref(_9928);
    RefDS(_9novalue);
    _16SetBBType(_9928, 1, _9novalue, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9928);
    DeRef(_9930);
    DeRef(_9932);
    return 0;
    ;
}


int _18opOPEN()
{
    int _9945 = 0;
    int _9947 = 0;
    int _9949 = 0;
    int _0, _1, _2;
    

    //     CSaveStr("_0", Code[pc+3], Code[pc+1], Code[pc+2], 0)
    _9945 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9945 = (int)*(((s1_ptr)_2)->base + _9945);
    Ref(_9945);
    _9947 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9947 = (int)*(((s1_ptr)_2)->base + _9947);
    Ref(_9947);
    _9949 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9949 = (int)*(((s1_ptr)_2)->base + _9949);
    Ref(_9949);
    RefDS(_5774);
    Ref(_9945);
    Ref(_9947);
    Ref(_9949);
    _18CSaveStr(_5774, _9945, _9947, _9949, 0);

    //     c_stmt("@ = EOpen(@, @);\n", {Code[pc+3], Code[pc+1], Code[pc+2]})
    DeRef(_9949);
    _9949 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9949 = (int)*(((s1_ptr)_2)->base + _9949);
    Ref(_9949);
    DeRef(_9947);
    _9947 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9947 = (int)*(((s1_ptr)_2)->base + _9947);
    Ref(_9947);
    DeRef(_9945);
    _9945 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _9945 = (int)*(((s1_ptr)_2)->base + _9945);
    Ref(_9945);
    _0 = _9945;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_9949);
    *((int *)(_2+4)) = _9949;
    Ref(_9947);
    *((int *)(_2+8)) = _9947;
    Ref(_9945);
    *((int *)(_2+12)) = _9945;
    _9945 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_9951);
    RefDS(_9945);
    _16c_stmt(_9951, _9945);

    //     CDeRefStr("_0")
    RefDS(_5774);
    _18CDeRefStr(_5774);

    //     target = {-1, 100000}
    DeRef(_18target);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 100000;
    _18target = MAKE_SEQ(_1);

    //     SetBBType(Code[pc+3], TYPE_INTEGER, target, TYPE_OBJECT)
    DeRefDS(_9945);
    _9945 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _9945 = (int)*(((s1_ptr)_2)->base + _9945);
    Ref(_9945);
    Ref(_9945);
    RefDS(_18target);
    _16SetBBType(_9945, 1, _18target, 16);

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_9945);
    DeRef(_9947);
    DeRef(_9949);
    return 0;
    ;
}


int _18opCLOSE()
{
    int _9964 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    Ref(_9964);
    RefDS(_5781);
    _0 = _9964;
    _9964 = _16TypeIs(_9964, _5781);
    DeRef(_0);
    if (_9964 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_9964) && DBL_PTR(_9964)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@))\n", Code[pc+1])
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    RefDS(_5783);
    Ref(_9964);
    _16c_stmt(_5783, _9964);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    Ref(_9964);
    RefDS(_6197);
    _0 = _9964;
    _9964 = _16TypeIs(_9964, _6197);
    DeRef(_0);
    if (_9964 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_9964) && DBL_PTR(_9964)->dbl == 0.0)
            goto L2;
    }

    // 	if Code[pc] = ABORT then 
    DeRef(_9964);
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9964);
    if (binary_op_a(NOTEQ, _9964, 126))
        goto L3;

    // 	    c_stmt("UserCleanup(@);\n", Code[pc+1])
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    RefDS(_9974);
    Ref(_9964);
    _16c_stmt(_9974, _9964);
    goto L4;
L3:

    // 	    c_stmt("EClose(@);\n", Code[pc+1])
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    RefDS(_9977);
    Ref(_9964);
    _16c_stmt(_9977, _9964);
L4:
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    Ref(_9964);
    RefDS(_5781);
    _0 = _9964;
    _9964 = _16TypeIs(_9964, _5781);
    DeRef(_0);
    if (_9964 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_9964) && DBL_PTR(_9964)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt0("else\n")
    RefDS(_5799);
    _16c_stmt0(_5799);
L5:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    Ref(_9964);
    _0 = _9964;
    _9964 = _16TypeIsNot(_9964, 1);
    DeRef(_0);
    if (_9964 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_9964) && DBL_PTR(_9964)->dbl == 0.0)
            goto L6;
    }

    // 	if Code[pc] = ABORT then 
    DeRef(_9964);
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_9964);
    if (binary_op_a(NOTEQ, _9964, 126))
        goto L7;

    // 	    c_stmt("UserCleanup((int)DBL_PTR(@)->dbl);\n", Code[pc+1])
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    RefDS(_9988);
    Ref(_9964);
    _16c_stmt(_9988, _9964);
    goto L8;
L7:

    // 	    c_stmt("EClose((int)DBL_PTR(@)->dbl);\n", Code[pc+1])
    DeRef(_9964);
    _9964 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _9964 = (int)*(((s1_ptr)_2)->base + _9964);
    Ref(_9964);
    RefDS(_9991);
    Ref(_9964);
    _16c_stmt(_9991, _9964);
L8:
L6:

    //     pc += 2
    _18pc = _18pc + 2;

    // end procedure
    DeRef(_9964);
    return 0;
    ;
}


