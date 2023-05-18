// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _18opUMINUS()
{
    int _8002 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = unary_op(UMINUS, @);\n"
    RefDS(_7998);
    DeRefi(_18gencode);
    _18gencode = _7998;

    //     intcode2= "@1 = - @2;\n"    -- careful about -- occurring
    RefDS(_7999);
    DeRefi(_18intcode2);
    _18intcode2 = _7999;

    //     intcode = "if (@2 == 0xC0000000)\n" &
    {
        int concat_list[4];

        concat_list[0] = _7999;
        concat_list[1] = _5799;
        concat_list[2] = _8001;
        concat_list[3] = _8000;
        Concat_N((object_ptr)&_18intcode, concat_list, 4);
    }

    //     if GType(Code[pc+1]) = TYPE_INTEGER then
    _8002 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8002 = (int)*(((s1_ptr)_2)->base + _8002);
    Ref(_8002);
    Ref(_8002);
    _0 = _8002;
    _8002 = _16GType(_8002);
    DeRef(_0);
    if (_8002 != 1)
        goto L1;

    // 	if NotInRange(Code[pc+1], MININT) then
    _8002 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8002 = (int)*(((s1_ptr)_2)->base + _8002);
    Ref(_8002);
    Ref(_8002);
    _0 = _8002;
    _8002 = _18NotInRange(_8002, -1073741824);
    DeRef(_0);
    if (_8002 == 0)
        goto L2;

    // 	    target_type = TYPE_INTEGER
    _18target_type = 1;
    goto L3;
L2:

    // 	    target_type = TYPE_ATOM
    _18target_type = 4;
L4:
    goto L3;
L1:

    // 	target_type = GType(Code[pc+1])
    DeRef(_8002);
    _8002 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8002 = (int)*(((s1_ptr)_2)->base + _8002);
    Ref(_8002);
    Ref(_8002);
    _0 = _16GType(_8002);
    _18target_type = _0;
L3:

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
    DeRef(_8002);
    return 0;
    ;
}


int _18opRAND()
{
    int _8016 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = unary_op(RAND, @);\n"
    RefDS(_8014);
    DeRefi(_18gencode);
    _18gencode = _8014;

    //     intcode = "@ = good_rand() % ((unsigned)@) + 1;\n"
    RefDS(_8015);
    DeRefi(_18intcode);
    _18intcode = _8015;

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    _8016 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8016 = (int)*(((s1_ptr)_2)->base + _8016);
    Ref(_8016);
    Ref(_8016);
    RefDS(_4094);
    _0 = _8016;
    _8016 = _16TypeIs(_8016, _4094);
    DeRef(_0);
    if (_8016 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8016) && DBL_PTR(_8016)->dbl == 0.0)
            goto L1;
    }

    // 	target_type = GType(Code[pc+1])
    DeRef(_8016);
    _8016 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8016 = (int)*(((s1_ptr)_2)->base + _8016);
    Ref(_8016);
    Ref(_8016);
    _0 = _16GType(_8016);
    _18target_type = _0;
    goto L2;
L1:

    // 	target_type = TYPE_INTEGER
    _18target_type = 1;

    // 	if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8016);
    _8016 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8016 = (int)*(((s1_ptr)_2)->base + _8016);
    Ref(_8016);
    Ref(_8016);
    _0 = _8016;
    _8016 = _16TypeIs(_8016, 1);
    DeRef(_0);
    if (_8016 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8016) && DBL_PTR(_8016)->dbl == 0.0)
            goto L3;
    }

    // 	    target = ObjMinMax(Code[pc+1])
    DeRef(_8016);
    _8016 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8016 = (int)*(((s1_ptr)_2)->base + _8016);
    Ref(_8016);
    Ref(_8016);
    _0 = _18ObjMinMax(_8016);
    DeRef(_18target);
    _18target = _0;

    // 	    target_val = {1, target[MAX]}
    DeRef(_8016);
    _2 = (int)SEQ_PTR(_18target);
    _8016 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8016);
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = _8016;
    Ref(_8016);
    _18target_val = MAKE_SEQ(_1);
L3:
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
    DeRef(_8016);
    return 0;
    ;
}


int _18opDIV2()
{
    int _8035 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(DIVIDE, @, 2);\n"
    RefDS(_8031);
    DeRefi(_18gencode);
    _18gencode = _8031;

    //     intcode = "if (@2 & 1) {\n" &
    {
        int concat_list[5];

        concat_list[0] = _8034;
        concat_list[1] = _5799;
        concat_list[2] = _6207;
        concat_list[3] = _8033;
        concat_list[4] = _8032;
        Concat_N((object_ptr)&_18intcode, concat_list, 5);
    }

    //     if GType(Code[pc+1]) = TYPE_INTEGER then
    _8035 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8035 = (int)*(((s1_ptr)_2)->base + _8035);
    Ref(_8035);
    Ref(_8035);
    _0 = _8035;
    _8035 = _16GType(_8035);
    DeRef(_0);
    if (_8035 != 1)
        goto L1;

    // 	target_type = TYPE_ATOM
    _18target_type = 4;
    goto L2;
L1:

    // 	target_type = GType(Code[pc+1])
    DeRef(_8035);
    _8035 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8035 = (int)*(((s1_ptr)_2)->base + _8035);
    Ref(_8035);
    Ref(_8035);
    _0 = _16GType(_8035);
    _18target_type = _0;
L2:

    //     unary_div(pc, target_type, intcode, gencode)
    RefDS(_18intcode);
    RefDS(_18gencode);
    _18unary_div(_18pc, _18target_type, _18intcode, _18gencode);

    //     pc += 4 
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_8035);
    return 0;
    ;
}


int _18opFLOOR_DIV2()
{
    int _8046 = 0;
    int _0, _1, _2;
    

    //     gencode = "_1 = binary_op(DIVIDE, @2, 2);\n" &
    {
        int concat_list[3];

        concat_list[0] = _7257;
        concat_list[1] = _8045;
        concat_list[2] = _8044;
        Concat_N((object_ptr)&_18gencode, concat_list, 3);
    }

    //     intcode = "@ = @ >> 1;\n"
    RefDS(_8047);
    DeRefi(_18intcode);
    _18intcode = _8047;

    //     if TypeIs(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) then
    _8046 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8046 = (int)*(((s1_ptr)_2)->base + _8046);
    Ref(_8046);
    Ref(_8046);
    RefDS(_4094);
    _0 = _8046;
    _8046 = _16TypeIs(_8046, _4094);
    DeRef(_0);
    if (_8046 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8046) && DBL_PTR(_8046)->dbl == 0.0)
            goto L1;
    }

    // 	target_type = GType(Code[pc+1])
    DeRef(_8046);
    _8046 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8046 = (int)*(((s1_ptr)_2)->base + _8046);
    Ref(_8046);
    Ref(_8046);
    _0 = _16GType(_8046);
    _18target_type = _0;
    goto L2;
L1:

    //     elsif GType(Code[pc+1]) = TYPE_INTEGER then
    DeRef(_8046);
    _8046 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8046 = (int)*(((s1_ptr)_2)->base + _8046);
    Ref(_8046);
    Ref(_8046);
    _0 = _8046;
    _8046 = _16GType(_8046);
    DeRef(_0);
    if (_8046 != 1)
        goto L3;

    // 	target_type = TYPE_INTEGER
    _18target_type = 1;
    goto L2;
L3:

    // 	target_type = TYPE_ATOM
    _18target_type = 4;
L2:

    //     unary_div(pc, target_type, intcode, gencode)
    RefDS(_18intcode);
    RefDS(_18gencode);
    _18unary_div(_18pc, _18target_type, _18intcode, _18gencode);

    //     pc += 4 
    _18pc = _18pc + 4;

    // end procedure            
    DeRef(_8046);
    return 0;
    ;
}


int _18opGREATER_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "LESSEQ", "<=")
    RefDS(_5256);
    RefDS(_6294);
    _0 = _18ifw(_18pc, _5256, _6294);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opNOTEQ_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "EQUALS", "==")
    RefDS(_5254);
    RefDS(_6321);
    _0 = _18ifw(_18pc, _5254, _6321);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opLESSEQ_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "GREATER", ">")
    RefDS(_5257);
    RefDS(_6340);
    _0 = _18ifw(_18pc, _5257, _6340);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opGREATEREQ_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "LESS", "<")
    RefDS(_5252);
    RefDS(_6348);
    _0 = _18ifw(_18pc, _5252, _6348);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure       
    return 0;
    ;
}


int _18opEQUALS_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "NOTEQ", "!=")
    RefDS(_5255);
    RefDS(_6302);
    _0 = _18ifw(_18pc, _5255, _6302);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure       
    return 0;
    ;
}


int _18opLESS_IFW()
{
    int _0, _1, _2;
    

    //     pc = ifw(pc, "GREATEREQ", ">=")
    RefDS(_5253);
    RefDS(_6286);
    _0 = _18ifw(_18pc, _5253, _6286);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure           
    return 0;
    ;
}


int _18opLESS_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, ">=") 
    RefDS(_6286);
    _0 = _18ifwi(_18pc, _6286);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opGREATER_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, "<=")
    RefDS(_6294);
    _0 = _18ifwi(_18pc, _6294);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opEQUALS_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, "!=")
    RefDS(_6302);
    _0 = _18ifwi(_18pc, _6302);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure       
    return 0;
    ;
}


int _18opNOTEQ_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, "==")
    RefDS(_6321);
    _0 = _18ifwi(_18pc, _6321);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure       
    return 0;
    ;
}


int _18opLESSEQ_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, ">")
    RefDS(_6340);
    _0 = _18ifwi(_18pc, _6340);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure       
    return 0;
    ;
}


int _18opGREATEREQ_IFW_I()
{
    int _0, _1, _2;
    

    //     pc = ifwi(pc, "<")
    RefDS(_6348);
    _0 = _18ifwi(_18pc, _6348);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure           
    return 0;
    ;
}


int _18opMULTIPLY()
{
    int _8072 = 0;
    int _8074 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(MULTIPLY, @, @);\n"
    RefDS(_8071);
    DeRefi(_18gencode);
    _18gencode = _8071;

    //     intcode2= "@1 = @2 * @3;\n"
    RefDS(_6182);
    DeRefi(_18intcode2);
    _18intcode2 = _6182;

    //     intcode = IntegerMultiply(Code[pc+1], Code[pc+2])
    _8072 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8072 = (int)*(((s1_ptr)_2)->base + _8072);
    Ref(_8072);
    _8074 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8074 = (int)*(((s1_ptr)_2)->base + _8074);
    Ref(_8074);
    Ref(_8072);
    Ref(_8074);
    _0 = _18IntegerMultiply(_8072, _8074);
    DeRefi(_18intcode);
    _18intcode = _0;

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    DeRef(_8074);
    _8074 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8074 = (int)*(((s1_ptr)_2)->base + _8074);
    Ref(_8074);
    Ref(_8074);
    _0 = _8074;
    _8074 = _16TypeIs(_8074, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8074)) {
        if (_8074 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8074)->dbl != 0.0) {
            goto L1;
        }
    }
    DeRef(_8072);
    _8072 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8072 = (int)*(((s1_ptr)_2)->base + _8072);
    Ref(_8072);
    Ref(_8072);
    _0 = _8072;
    _8072 = _16TypeIs(_8072, 2);
    DeRef(_0);
L2:
    if (_8072 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8072) && DBL_PTR(_8072)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L3:

    //     iii = FALSE
    _18iii = 0;

    //     dblfn="*"
    RefDS(_8084);
    DeRefi(_18dblfn);
    _18dblfn = _8084;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 0, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8072);
    DeRef(_8074);
    return 0;
    ;
}


int _18opPLUS()
{
    int _8096 = 0;
    int _8091 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(PLUS, @, @);\n"
    RefDS(_8086);
    DeRefi(_18gencode);
    _18gencode = _8086;

    //     intcode2= "@1 = @2 + @3;\n"
    RefDS(_8088);
    DeRefi(_18intcode2);
    _18intcode2 = _8088;

    //     intcode = "@1 = @2 + @3;\n"
    RefDS(_8088);
    DeRefi(_18intcode);
    _18intcode = _8088;

    //     intcode_extra = "if ((long)((unsigned long)@1 + (unsigned long)HIGH_BITS) >= 0) \n" &
    Concat((object_ptr)&_18intcode_extra, _8089, (s1_ptr)_8090);

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    _8091 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8091 = (int)*(((s1_ptr)_2)->base + _8091);
    Ref(_8091);
    Ref(_8091);
    _0 = _8091;
    _8091 = _16TypeIs(_8091, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8091)) {
        if (_8091 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8091)->dbl != 0.0) {
            goto L1;
        }
    }
    _8096 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8096 = (int)*(((s1_ptr)_2)->base + _8096);
    Ref(_8096);
    Ref(_8096);
    _0 = _8096;
    _8096 = _16TypeIs(_8096, 2);
    DeRef(_0);
L2:
    if (_8096 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8096) && DBL_PTR(_8096)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L3:

    //     iii = FALSE
    _18iii = 0;

    //     dblfn="+"
    RefDS(_8099);
    DeRefi(_18dblfn);
    _18dblfn = _8099;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 0, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8096);
    DeRef(_8091);
    return 0;
    ;
}


int _18opMINUS()
{
    int _8109 = 0;
    int _8104 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(MINUS, @, @);\n"
    RefDS(_8101);
    DeRefi(_18gencode);
    _18gencode = _8101;

    //     intcode2 ="@1 = @2 - @3;\n"
    RefDS(_8102);
    DeRefi(_18intcode2);
    _18intcode2 = _8102;

    //     intcode = "@1 = @2 - @3;\n"
    RefDS(_8102);
    DeRefi(_18intcode);
    _18intcode = _8102;

    //     intcode_extra = "if ((long)((unsigned long)@1 +(unsigned long) HIGH_BITS) >= 0)\n" &
    Concat((object_ptr)&_18intcode_extra, _8103, (s1_ptr)_8090);

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    _8104 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8104 = (int)*(((s1_ptr)_2)->base + _8104);
    Ref(_8104);
    Ref(_8104);
    _0 = _8104;
    _8104 = _16TypeIs(_8104, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8104)) {
        if (_8104 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8104)->dbl != 0.0) {
            goto L1;
        }
    }
    _8109 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8109 = (int)*(((s1_ptr)_2)->base + _8109);
    Ref(_8109);
    Ref(_8109);
    _0 = _8109;
    _8109 = _16TypeIs(_8109, 2);
    DeRef(_0);
L2:
    if (_8109 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8109) && DBL_PTR(_8109)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L3:

    //     iii = FALSE
    _18iii = 0;

    //     dblfn="-"
    RefDS(_8112);
    DeRefi(_18dblfn);
    _18dblfn = _8112;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 0, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8109);
    DeRef(_8104);
    return 0;
    ;
}


int _18opOR()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(OR, @, @);\n"
    RefDS(_8114);
    DeRefi(_18gencode);
    _18gencode = _8114;

    //     intcode = "@ = (@ != 0 || @ != 0);\n"
    RefDS(_8115);
    DeRefi(_18intcode);
    _18intcode = _8115;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dor"
    RefDS(_8116);
    DeRefi(_18dblfn);
    _18dblfn = _8116;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, 1);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opXOR()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(XOR, @, @);\n"
    RefDS(_8118);
    DeRefi(_18gencode);
    _18gencode = _8118;

    //     intcode = "@ = ((@ != 0) != (@ != 0));\n"
    RefDS(_8119);
    DeRefi(_18intcode);
    _18intcode = _8119;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dxor"
    RefDS(_8120);
    DeRefi(_18dblfn);
    _18dblfn = _8120;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, 1);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opAND()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(AND, @, @);\n"
    RefDS(_8122);
    DeRefi(_18gencode);
    _18gencode = _8122;

    //     intcode = "@ = (@ != 0 && @ != 0);\n"
    RefDS(_8123);
    DeRefi(_18intcode);
    _18intcode = _8123;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dand"
    RefDS(_8124);
    DeRefi(_18dblfn);
    _18dblfn = _8124;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, 1);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opDIVIDE()
{
    int _8126 = 0;
    int _8130 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+2], TYPE_INTEGER) and 
    _8126 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8126 = (int)*(((s1_ptr)_2)->base + _8126);
    Ref(_8126);
    Ref(_8126);
    _0 = _8126;
    _8126 = _16TypeIs(_8126, 1);
    DeRef(_0);
    if (IS_ATOM_INT(_8126)) {
        if (_8126 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8126)->dbl == 0.0) {
            goto L1;
        }
    }
    _8130 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8130 = (int)*(((s1_ptr)_2)->base + _8130);
    Ref(_8130);
    Ref(_8130);
    _0 = _8130;
    _8130 = _16ObjValue(_8130);
    DeRef(_0);
    _0 = _8130;
    if (IS_ATOM_INT(_8130)) {
        _8130 = (_8130 == 0);
    }
    else {
        _8130 = binary_op(EQUALS, _8130, 0);
    }
    DeRef(_0);
L2:
    if (_8130 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8130) && DBL_PTR(_8130)->dbl == 0.0)
            goto L1;
    }

    // 	intcode = "RTFatal(\"divide by 0\");\n"
    RefDS(_8134);
    DeRefi(_18intcode);
    _18intcode = _8134;

    // 	gencode = intcode
    RefDS(_18intcode);
    DeRefi(_18gencode);
    _18gencode = _18intcode;
    goto L3;
L1:

    // 	gencode = "@ = binary_op(DIVIDE, @, @);\n"
    RefDS(_8135);
    DeRefi(_18gencode);
    _18gencode = _8135;

    // 	intcode = "@1 = (@2 % @3) ? NewDouble((double)@2 / @3) : (@2 / @3);\n"
    RefDS(_8136);
    DeRefi(_18intcode);
    _18intcode = _8136;
L3:

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    DeRef(_8130);
    _8130 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8130 = (int)*(((s1_ptr)_2)->base + _8130);
    Ref(_8130);
    Ref(_8130);
    _0 = _8130;
    _8130 = _16TypeIs(_8130, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8130)) {
        if (_8130 != 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_8130)->dbl != 0.0) {
            goto L4;
        }
    }
    DeRef(_8126);
    _8126 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8126 = (int)*(((s1_ptr)_2)->base + _8126);
    Ref(_8126);
    Ref(_8126);
    _0 = _8126;
    _8126 = _16TypeIs(_8126, 2);
    DeRef(_0);
L5:
    if (_8126 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_8126) && DBL_PTR(_8126)->dbl == 0.0)
            goto L6;
    }
L4:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L6:

    //     iii = FALSE
    _18iii = 0;

    //     dblfn="/"
    RefDS(_8144);
    DeRefi(_18dblfn);
    _18dblfn = _8144;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 0, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8126);
    DeRef(_8130);
    return 0;
    ;
}


int _18opREMAINDER()
{
    int _8148 = 0;
    int _8164 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(REMAINDER, @, @);\n"
    RefDS(_8146);
    DeRefi(_18gencode);
    _18gencode = _8146;

    //     intcode = "@ = (@ % @);\n"
    RefDS(_8147);
    DeRefi(_18intcode);
    _18intcode = _8147;

    //     if TypeIs(Code[pc+2], TYPE_INTEGER) then
    _8148 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8148 = (int)*(((s1_ptr)_2)->base + _8148);
    Ref(_8148);
    Ref(_8148);
    _0 = _8148;
    _8148 = _16TypeIs(_8148, 1);
    DeRef(_0);
    if (_8148 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8148) && DBL_PTR(_8148)->dbl == 0.0)
            goto L1;
    }

    // 	if ObjValue(Code[pc+2]) = 0 then
    DeRef(_8148);
    _8148 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8148 = (int)*(((s1_ptr)_2)->base + _8148);
    Ref(_8148);
    Ref(_8148);
    _0 = _8148;
    _8148 = _16ObjValue(_8148);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _8148, 0))
        goto L2;

    // 	    intcode = "RTFatal(\"remainder of a number divided by 0\");\n"
    RefDS(_8155);
    DeRefDSi(_18intcode);
    _18intcode = _8155;

    // 	    gencode = intcode
    RefDS(_18intcode);
    DeRefDSi(_18gencode);
    _18gencode = _18intcode;
    goto L3;
L2:

    // 	elsif TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8148);
    _8148 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8148 = (int)*(((s1_ptr)_2)->base + _8148);
    Ref(_8148);
    Ref(_8148);
    _0 = _8148;
    _8148 = _16TypeIs(_8148, 1);
    DeRef(_0);
    if (_8148 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8148) && DBL_PTR(_8148)->dbl == 0.0)
            goto L4;
    }

    // 	    target_val = ObjMinMax(Code[pc+2])                      
    DeRef(_8148);
    _8148 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8148 = (int)*(((s1_ptr)_2)->base + _8148);
    Ref(_8148);
    Ref(_8148);
    _0 = _18ObjMinMax(_8148);
    DeRef(_18target_val);
    _18target_val = _0;

    // 	    target_val[MAX] = max(abs(target_val[MIN]), 
    DeRef(_8148);
    _2 = (int)SEQ_PTR(_18target_val);
    _8148 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_8148);
    Ref(_8148);
    _0 = _8148;
    _8148 = _18abs(_8148);
    DeRef(_0);
    DeRef(_8164);
    _2 = (int)SEQ_PTR(_18target_val);
    _8164 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8164);
    Ref(_8164);
    _0 = _8164;
    _8164 = _18abs(_8164);
    DeRef(_0);
    Ref(_8148);
    Ref(_8164);
    _0 = _8164;
    _8164 = _18max(_8148, _8164);
    DeRef(_0);
    _0 = _8164;
    if (IS_ATOM_INT(_8164)) {
        _8164 = _8164 - 1;
        if ((long)((unsigned long)_8164 +(unsigned long) HIGH_BITS) >= 0)
            _8164 = NewDouble((double)_8164);
    }
    else {
        _8164 = NewDouble(DBL_PTR(_8164)->dbl - (double)1);
    }
    DeRef(_0);
    Ref(_8164);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 2);
    _1 = *(int *)_2;
    *(int *)_2 = _8164;
    DeRef(_1);

    // 	    target_val[MIN] = -target_val[MAX]
    DeRef(_8164);
    _2 = (int)SEQ_PTR(_18target_val);
    _8164 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_8164);
    _0 = _8164;
    if (IS_ATOM_INT(_8164)) {
        if (_8164 == 0xC0000000)
            _8164 = (int)NewDouble((double)-0xC0000000);
        else
            _8164 = - _8164;
    }
    else {
        _8164 = unary_op(UMINUS, _8164);
    }
    DeRef(_0);
    Ref(_8164);
    _2 = (int)SEQ_PTR(_18target_val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _18target_val = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 1);
    _1 = *(int *)_2;
    *(int *)_2 = _8164;
    DeRef(_1);
L4:
L3:
L1:

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    DeRef(_8164);
    _8164 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8164 = (int)*(((s1_ptr)_2)->base + _8164);
    Ref(_8164);
    Ref(_8164);
    _0 = _8164;
    _8164 = _16TypeIs(_8164, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8164)) {
        if (_8164 != 0) {
            goto L5;
        }
    }
    else {
        if (DBL_PTR(_8164)->dbl != 0.0) {
            goto L5;
        }
    }
    DeRef(_8148);
    _8148 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8148 = (int)*(((s1_ptr)_2)->base + _8148);
    Ref(_8148);
    Ref(_8148);
    _0 = _8148;
    _8148 = _16TypeIs(_8148, 2);
    DeRef(_0);
L6:
    if (_8148 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_8148) && DBL_PTR(_8148)->dbl == 0.0)
            goto L7;
    }
L5:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L7:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dremainder"
    RefDS(_8177);
    DeRefi(_18dblfn);
    _18dblfn = _8177;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8148);
    DeRef(_8164);
    return 0;
    ;
}


int _18opFLOOR_DIV()
{
    int _8193 = 0;
    int _8182 = 0;
    int _0, _1, _2;
    

    //     gencode = "_2 = binary_op(DIVIDE, @2, @3);\n" &
    {
        int concat_list[3];

        concat_list[0] = _8181;
        concat_list[1] = _8180;
        concat_list[2] = _8179;
        Concat_N((object_ptr)&_18gencode, concat_list, 3);
    }

    //     intcode2 = "if (@3 > 0 && @2 >= 0) {\n" &
    {
        int concat_list[7];

        concat_list[0] = _6207;
        concat_list[1] = _8186;
        concat_list[2] = _8185;
        concat_list[3] = _6208;
        concat_list[4] = _6207;
        concat_list[5] = _8184;
        concat_list[6] = _8183;
        Concat_N((object_ptr)&_18intcode2, concat_list, 7);
    }

    //     if GType(Code[pc+1]) = TYPE_INTEGER and
    _8182 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8182 = (int)*(((s1_ptr)_2)->base + _8182);
    Ref(_8182);
    Ref(_8182);
    _0 = _8182;
    _8182 = _16GType(_8182);
    DeRef(_0);
    _8182 = (_8182 == 1);
    if (_8182 == 0) {
        _8182 = 0;
        goto L1;
    }
    _8193 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8193 = (int)*(((s1_ptr)_2)->base + _8193);
    Ref(_8193);
    Ref(_8193);
    _0 = _8193;
    _8193 = _16GType(_8193);
    DeRef(_0);
    _8193 = (_8193 == 1);
    _8182 = (_8193 != 0);
L1:
    if (_8182 == 0) {
        DeRef(_8193);
        _8193 = 0;
        goto L2;
    }
    DeRef(_8182);
    _8182 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8182 = (int)*(((s1_ptr)_2)->base + _8182);
    Ref(_8182);
    Ref(_8182);
    _0 = _8182;
    _8182 = _18NotInRange(_8182, -1073741824);
    DeRef(_0);
    _8193 = (_8182 != 0);
L2:
    if (_8193 == 0) {
        goto L3;
    }
    DeRef(_8193);
    _8193 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8193 = (int)*(((s1_ptr)_2)->base + _8193);
    Ref(_8193);
    Ref(_8193);
    _0 = _8193;
    _8193 = _18NotInRange(_8193, -1);
    DeRef(_0);
L4:
    if (_8193 == 0)
        goto L3;

    // 	intcode = intcode2
    RefDS(_18intcode2);
    DeRefi(_18intcode);
    _18intcode = _18intcode2;

    // 	iii = TRUE
    _18iii = 1;
    goto L5;
L3:

    // 	intcode = "if (@3 > 0 && @2 >= 0) {\n" &
    {
        int concat_list[10];

        concat_list[0] = _6207;
        concat_list[1] = _8206;
        concat_list[2] = _5799;
        concat_list[3] = _8186;
        concat_list[4] = _8205;
        concat_list[5] = _8185;
        concat_list[6] = _6208;
        concat_list[7] = _6207;
        concat_list[8] = _8184;
        concat_list[9] = _8183;
        Concat_N((object_ptr)&_18intcode, concat_list, 10);
    }

    // 	iii = FALSE
    _18iii = 0;
L5:

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, _18iii, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8193);
    DeRef(_8182);
    return 0;
    ;
}


int _18opAND_BITS()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(AND_BITS, @, @);\n"
    RefDS(_8209);
    DeRefi(_18gencode);
    _18gencode = _8209;

    //     intcode = "@ = (@ & @);\n"
    RefDS(_8210);
    DeRefi(_18intcode);
    _18intcode = _8210;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dand_bits"
    RefDS(_8211);
    DeRefi(_18dblfn);
    _18dblfn = _8211;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opOR_BITS()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(OR_BITS, @, @);\n"
    RefDS(_8213);
    DeRefi(_18gencode);
    _18gencode = _8213;

    //     intcode = "@ = (@ | @);\n"
    RefDS(_8214);
    DeRefi(_18intcode);
    _18intcode = _8214;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dor_bits"
    RefDS(_8215);
    DeRefi(_18dblfn);
    _18dblfn = _8215;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opXOR_BITS()
{
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(XOR_BITS, @, @);\n"
    RefDS(_8217);
    DeRefi(_18gencode);
    _18gencode = _8217;

    //     intcode = "@ = (@ ^ @);\n"
    RefDS(_8218);
    DeRefi(_18intcode);
    _18intcode = _8218;

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="Dxor_bits"
    RefDS(_8219);
    DeRefi(_18dblfn);
    _18dblfn = _8219;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    return 0;
    ;
}


int _18opPOWER()
{
    int _8227 = 0;
    int _8223 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(POWER, @, @);\n"
    RefDS(_8221);
    DeRefi(_18gencode);
    _18gencode = _8221;

    //     intcode = "@ = power(@, @);\n"
    RefDS(_8222);
    DeRefi(_18intcode);
    _18intcode = _8222;

    //     intcode2 = intcode
    RefDS(_18intcode);
    DeRefi(_18intcode2);
    _18intcode2 = _18intcode;

    //     if TypeIs(Code[pc+1], TYPE_DOUBLE) or
    _8223 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8223 = (int)*(((s1_ptr)_2)->base + _8223);
    Ref(_8223);
    Ref(_8223);
    _0 = _8223;
    _8223 = _16TypeIs(_8223, 2);
    DeRef(_0);
    if (IS_ATOM_INT(_8223)) {
        if (_8223 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8223)->dbl != 0.0) {
            goto L1;
        }
    }
    _8227 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8227 = (int)*(((s1_ptr)_2)->base + _8227);
    Ref(_8227);
    Ref(_8227);
    _0 = _8227;
    _8227 = _16TypeIs(_8227, 2);
    DeRef(_0);
L2:
    if (_8227 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_8227) && DBL_PTR(_8227)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	atom_type = TYPE_DOUBLE
    _18atom_type = 2;
L3:

    //     iii = FALSE
    _18iii = 0;

    //     dblfn="Dpower"
    RefDS(_8230);
    DeRefi(_18dblfn);
    _18dblfn = _8230;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 0, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8227);
    DeRef(_8223);
    return 0;
    ;
}


int _18opLESS()
{
    int _8238 = 0;
    int _8234 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(LESS, @, @);\n"
    RefDS(_8232);
    DeRefi(_18gencode);
    _18gencode = _8232;

    //     intcode = "@ = (@ < @);\n"
    RefDS(_8233);
    DeRefi(_18intcode);
    _18intcode = _8233;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8234 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8234 = (int)*(((s1_ptr)_2)->base + _8234);
    Ref(_8234);
    Ref(_8234);
    RefDS(_4094);
    _0 = _8234;
    _8234 = _16TypeIsNot(_8234, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8234)) {
        if (_8234 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8234)->dbl == 0.0) {
            goto L1;
        }
    }
    _8238 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8238 = (int)*(((s1_ptr)_2)->base + _8238);
    Ref(_8238);
    Ref(_8238);
    RefDS(_4094);
    _0 = _8238;
    _8238 = _16TypeIsNot(_8238, _4094);
    DeRef(_0);
L2:
    if (_8238 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8238) && DBL_PTR(_8238)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="<"
    RefDS(_6348);
    DeRefi(_18dblfn);
    _18dblfn = _6348;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8238);
    DeRef(_8234);
    return 0;
    ;
}


int _18opGREATER()
{
    int _8249 = 0;
    int _8245 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(GREATER, @, @);\n"
    RefDS(_8243);
    DeRefi(_18gencode);
    _18gencode = _8243;

    //     intcode = "@ = (@ > @);\n"
    RefDS(_8244);
    DeRefi(_18intcode);
    _18intcode = _8244;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8245 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8245 = (int)*(((s1_ptr)_2)->base + _8245);
    Ref(_8245);
    Ref(_8245);
    RefDS(_4094);
    _0 = _8245;
    _8245 = _16TypeIsNot(_8245, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8245)) {
        if (_8245 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8245)->dbl == 0.0) {
            goto L1;
        }
    }
    _8249 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8249 = (int)*(((s1_ptr)_2)->base + _8249);
    Ref(_8249);
    Ref(_8249);
    RefDS(_4094);
    _0 = _8249;
    _8249 = _16TypeIsNot(_8249, _4094);
    DeRef(_0);
L2:
    if (_8249 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8249) && DBL_PTR(_8249)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn=">"
    RefDS(_6340);
    DeRefi(_18dblfn);
    _18dblfn = _6340;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8249);
    DeRef(_8245);
    return 0;
    ;
}


int _18opEQUALS()
{
    int _8260 = 0;
    int _8256 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(EQUALS, @, @);\n"
    RefDS(_8254);
    DeRefi(_18gencode);
    _18gencode = _8254;

    //     intcode = "@ = (@ == @);\n"
    RefDS(_8255);
    DeRefi(_18intcode);
    _18intcode = _8255;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8256 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8256 = (int)*(((s1_ptr)_2)->base + _8256);
    Ref(_8256);
    Ref(_8256);
    RefDS(_4094);
    _0 = _8256;
    _8256 = _16TypeIsNot(_8256, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8256)) {
        if (_8256 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8256)->dbl == 0.0) {
            goto L1;
        }
    }
    _8260 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8260 = (int)*(((s1_ptr)_2)->base + _8260);
    Ref(_8260);
    Ref(_8260);
    RefDS(_4094);
    _0 = _8260;
    _8260 = _16TypeIsNot(_8260, _4094);
    DeRef(_0);
L2:
    if (_8260 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8260) && DBL_PTR(_8260)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="=="
    RefDS(_6321);
    DeRefi(_18dblfn);
    _18dblfn = _6321;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8260);
    DeRef(_8256);
    return 0;
    ;
}


int _18opNOTEQ()
{
    int _8271 = 0;
    int _8267 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(NOTEQ, @, @);\n"
    RefDS(_8265);
    DeRefi(_18gencode);
    _18gencode = _8265;

    //     intcode = "@ = (@ != @);\n"
    RefDS(_8266);
    DeRefi(_18intcode);
    _18intcode = _8266;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8267 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8267 = (int)*(((s1_ptr)_2)->base + _8267);
    Ref(_8267);
    Ref(_8267);
    RefDS(_4094);
    _0 = _8267;
    _8267 = _16TypeIsNot(_8267, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8267)) {
        if (_8267 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8267)->dbl == 0.0) {
            goto L1;
        }
    }
    _8271 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8271 = (int)*(((s1_ptr)_2)->base + _8271);
    Ref(_8271);
    Ref(_8271);
    RefDS(_4094);
    _0 = _8271;
    _8271 = _16TypeIsNot(_8271, _4094);
    DeRef(_0);
L2:
    if (_8271 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8271) && DBL_PTR(_8271)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="!="
    RefDS(_6302);
    DeRefi(_18dblfn);
    _18dblfn = _6302;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8271);
    DeRef(_8267);
    return 0;
    ;
}


int _18opLESSEQ()
{
    int _8282 = 0;
    int _8278 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(LESSEQ, @, @);\n"
    RefDS(_8276);
    DeRefi(_18gencode);
    _18gencode = _8276;

    //     intcode = "@ = (@ <= @);\n"
    RefDS(_8277);
    DeRefi(_18intcode);
    _18intcode = _8277;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8278 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8278 = (int)*(((s1_ptr)_2)->base + _8278);
    Ref(_8278);
    Ref(_8278);
    RefDS(_4094);
    _0 = _8278;
    _8278 = _16TypeIsNot(_8278, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8278)) {
        if (_8278 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8278)->dbl == 0.0) {
            goto L1;
        }
    }
    _8282 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8282 = (int)*(((s1_ptr)_2)->base + _8282);
    Ref(_8282);
    Ref(_8282);
    RefDS(_4094);
    _0 = _8282;
    _8282 = _16TypeIsNot(_8282, _4094);
    DeRef(_0);
L2:
    if (_8282 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8282) && DBL_PTR(_8282)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn="<="
    RefDS(_6294);
    DeRefi(_18dblfn);
    _18dblfn = _6294;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure
    DeRef(_8282);
    DeRef(_8278);
    return 0;
    ;
}


int _18opGREATEREQ()
{
    int _8293 = 0;
    int _8289 = 0;
    int _0, _1, _2;
    

    //     gencode = "@ = binary_op(GREATEREQ, @, @);\n"
    RefDS(_8287);
    DeRefi(_18gencode);
    _18gencode = _8287;

    //     intcode = "@ = (@ >= @);\n"
    RefDS(_8288);
    DeRefi(_18intcode);
    _18intcode = _8288;

    //     atom_type = TYPE_INTEGER
    _18atom_type = 1;

    //     if TypeIsNot(Code[pc+1], {TYPE_SEQUENCE, TYPE_OBJECT}) and
    _8289 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8289 = (int)*(((s1_ptr)_2)->base + _8289);
    Ref(_8289);
    Ref(_8289);
    RefDS(_4094);
    _0 = _8289;
    _8289 = _16TypeIsNot(_8289, _4094);
    DeRef(_0);
    if (IS_ATOM_INT(_8289)) {
        if (_8289 == 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_8289)->dbl == 0.0) {
            goto L1;
        }
    }
    _8293 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8293 = (int)*(((s1_ptr)_2)->base + _8293);
    Ref(_8293);
    Ref(_8293);
    RefDS(_4094);
    _0 = _8293;
    _8293 = _16TypeIsNot(_8293, _4094);
    DeRef(_0);
L2:
    if (_8293 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8293) && DBL_PTR(_8293)->dbl == 0.0)
            goto L1;
    }

    // 	target_val = {0, 1}
    DeRef(_18target_val);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = 1;
    _18target_val = MAKE_SEQ(_1);
L1:

    //     iii = TRUE
    _18iii = 1;

    //     dblfn = ">="
    RefDS(_6286);
    DeRefi(_18dblfn);
    _18dblfn = _6286;

    //     pc = binary_op(pc, iii, target_val, intcode, intcode2,
    RefDS(_18target_val);
    RefDS(_18intcode);
    RefDS(_18intcode2);
    RefDS(_18intcode_extra);
    RefDS(_18gencode);
    RefDS(_18dblfn);
    _0 = _18binary_op(_18pc, 1, _18target_val, _18intcode, _18intcode2, _18intcode_extra, _18gencode, _18dblfn, _18atom_type);
    _18pc = _0;
    if (!IS_ATOM_INT(_18pc)) {
        _1 = (long)(DBL_PTR(_18pc)->dbl);
        DeRefDS(_18pc);
        _18pc = _1;
    }

    // end procedure           
    DeRef(_8293);
    DeRef(_8289);
    return 0;
    ;
}


int _18opSC1_AND()
{
    int _8298 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then 
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_5781);
    _0 = _8298;
    _8298 = _16TypeIs(_8298, _5781);
    DeRef(_0);
    if (_8298 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    RefDS(_6192);
    Ref(_8298);
    _16c_stmt(_6192, _8298);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_6197);
    _0 = _8298;
    _8298 = _16TypeIs(_8298, _6197);
    DeRef(_0);
    if (_8298 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("if (@ == 0) {\n", Code[pc+1])
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    RefDS(_7141);
    Ref(_8298);
    _16c_stmt(_7141, _8298);

    // 	if Code[pc] = SC1_AND then
    DeRef(_8298);
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8298);
    if (binary_op_a(NOTEQ, _8298, 143))
        goto L3;

    // 	    CDeRef(Code[pc+2])
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _18CDeRef(_8298);

    // 	    c_stmt("@ = 0;\n", Code[pc+2]) -- hard to suppress
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    RefDS(_7831);
    Ref(_8298);
    _16c_stmt(_7831, _8298);
L3:

    // 	Goto(Code[pc+3])
    DeRef(_8298);
    _8298 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _18Goto(_8298);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_5781);
    _0 = _8298;
    _8298 = _16TypeIs(_8298, _5781);
    DeRef(_0);
    if (_8298 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L4:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _0 = _8298;
    _8298 = _16TypeIsNot(_8298, 1);
    DeRef(_0);
    if (_8298 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt("if (DBL_PTR(@)->dbl == 0.0) {\n", Code[pc+1])
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    RefDS(_8322);
    Ref(_8298);
    _16c_stmt(_8322, _8298);

    // 	if Code[pc] = SC1_AND then
    DeRef(_8298);
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8298);
    if (binary_op_a(NOTEQ, _8298, 143))
        goto L6;

    // 	    CDeRef(Code[pc+2])
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _18CDeRef(_8298);

    // 	    c_stmt("@ = 0;\n", Code[pc+2])
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    RefDS(_7831);
    Ref(_8298);
    _16c_stmt(_7831, _8298);
L6:

    // 	Goto(Code[pc+3])
    DeRef(_8298);
    _8298 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _18Goto(_8298);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L5:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then 
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_5781);
    _0 = _8298;
    _8298 = _16TypeIs(_8298, _5781);
    DeRef(_0);
    if (_8298 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L7;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L7:

    //     if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8298);
    _8298 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    _0 = _8298;
    _8298 = _16TypeIs(_8298, 1);
    DeRef(_0);
    if (_8298 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_8298) && DBL_PTR(_8298)->dbl == 0.0)
            goto L8;
    }

    // 	SetBBType(Code[pc+2], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_9novalue);
    _16SetBBType(_8298, 1, _9novalue, 16);
    goto L9;
L8:

    // 	SetBBType(Code[pc+2], TYPE_ATOM, novalue, TYPE_OBJECT)
    DeRef(_8298);
    _8298 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8298 = (int)*(((s1_ptr)_2)->base + _8298);
    Ref(_8298);
    Ref(_8298);
    RefDS(_9novalue);
    _16SetBBType(_8298, 4, _9novalue, 16);
L9:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_8298);
    return 0;
    ;
}


int _18opSC1_OR()
{
    int _8344 = 0;
    int _0, _1, _2;
    

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then 
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_5781);
    _0 = _8344;
    _8344 = _16TypeIs(_8344, _5781);
    DeRef(_0);
    if (_8344 == 0) {
        goto L1;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L1;
    }

    // 	c_stmt("if (IS_ATOM_INT(@)) {\n", Code[pc+1])
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    RefDS(_6192);
    Ref(_8344);
    _16c_stmt(_6192, _8344);
L1:

    //     if TypeIs(Code[pc+1], {TYPE_INTEGER, TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_6197);
    _0 = _8344;
    _8344 = _16TypeIs(_8344, _6197);
    DeRef(_0);
    if (_8344 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L2;
    }

    // 	c_stmt("if (@ != 0) {\n", Code[pc+1]) -- optimize this???
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    RefDS(_8352);
    Ref(_8344);
    _16c_stmt(_8352, _8344);

    // 	if Code[pc] = SC1_OR then
    DeRef(_8344);
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8344);
    if (binary_op_a(NOTEQ, _8344, 145))
        goto L3;

    // 	    CDeRef(Code[pc+2])
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _18CDeRef(_8344);

    // 	    c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    RefDS(_7825);
    Ref(_8344);
    _16c_stmt(_7825, _8344);
L3:

    // 	Goto(Code[pc+3])
    DeRef(_8344);
    _8344 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _18Goto(_8344);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L2:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_5781);
    _0 = _8344;
    _8344 = _16TypeIs(_8344, _5781);
    DeRef(_0);
    if (_8344 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L4;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);

    // 	c_stmt0("else {\n")
    RefDS(_6208);
    _16c_stmt0(_6208);
L4:

    //     if TypeIsNot(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _0 = _8344;
    _8344 = _16TypeIsNot(_8344, 1);
    DeRef(_0);
    if (_8344 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L5;
    }

    // 	c_stmt("if (DBL_PTR(@)->dbl != 0.0) {\n", Code[pc+1])
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    RefDS(_8369);
    Ref(_8344);
    _16c_stmt(_8369, _8344);

    // 	if Code[pc] = SC1_OR then
    DeRef(_8344);
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8344);
    if (binary_op_a(NOTEQ, _8344, 145))
        goto L6;

    // 	    CDeRef(Code[pc+2])
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _18CDeRef(_8344);

    // 	    c_stmt("@ = 1;\n", Code[pc+2])
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    RefDS(_7825);
    Ref(_8344);
    _16c_stmt(_7825, _8344);
L6:

    // 	Goto(Code[pc+3])
    DeRef(_8344);
    _8344 = _18pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _18Goto(_8344);

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L5:

    //     if TypeIs(Code[pc+1], {TYPE_ATOM, TYPE_OBJECT}) then
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_5781);
    _0 = _8344;
    _8344 = _16TypeIs(_8344, _5781);
    DeRef(_0);
    if (_8344 == 0) {
        goto L7;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L7;
    }

    // 	c_stmt0("}\n")
    RefDS(_6207);
    _16c_stmt0(_6207);
L7:

    //     if Code[pc] = SC1_OR then
    DeRef(_8344);
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _18pc);
    Ref(_8344);
    if (binary_op_a(NOTEQ, _8344, 145))
        goto L8;

    // 	if TypeIs(Code[pc+1], TYPE_INTEGER) then
    DeRef(_8344);
    _8344 = _18pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    _0 = _8344;
    _8344 = _16TypeIs(_8344, 1);
    DeRef(_0);
    if (_8344 == 0) {
        goto L9;
    }
    else {
        if (!IS_ATOM_INT(_8344) && DBL_PTR(_8344)->dbl == 0.0)
            goto L9;
    }

    // 	    SetBBType(Code[pc+2], TYPE_INTEGER, novalue, TYPE_OBJECT)
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_9novalue);
    _16SetBBType(_8344, 1, _9novalue, 16);
    goto LA;
L9:

    // 	    SetBBType(Code[pc+2], TYPE_ATOM, novalue, TYPE_OBJECT)
    DeRef(_8344);
    _8344 = _18pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _8344 = (int)*(((s1_ptr)_2)->base + _8344);
    Ref(_8344);
    Ref(_8344);
    RefDS(_9novalue);
    _16SetBBType(_8344, 4, _9novalue, 16);
LA:
L8:

    //     pc += 4
    _18pc = _18pc + 4;

    // end procedure
    DeRef(_8344);
    return 0;
    ;
}


