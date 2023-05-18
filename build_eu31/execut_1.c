// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16opRETURNF()
{
    int _4953 = 0;
    int _0, _1, _2;
    

    //     result_val = val[Code[pc+2]]
    _4953 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _4953 = (int)*(((s1_ptr)_2)->base + _4953);
    Ref(_4953);
    DeRef(_16result_val);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_4953))
        _16result_val = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4953)->dbl));
    else
        _16result_val = (int)*(((s1_ptr)_2)->base + _4953);
    Ref(_16result_val);

    //     result = call_stack[$-1] - 1
    DeRef(_4953);
    _4953 = SEQ_PTR(_16call_stack)->length;
    _4953 = _4953 - 1;
    _2 = (int)SEQ_PTR(_16call_stack);
    _4953 = (int)*(((s1_ptr)_2)->base + _4953);
    Ref(_4953);
    if (IS_ATOM_INT(_4953)) {
        _16result = _4953 - 1;
    }
    else {
        _16result = binary_op(MINUS, _4953, 1);
    }
    if (!IS_ATOM_INT(_16result)) {
        _1 = (long)(DBL_PTR(_16result)->dbl);
        DeRefDS(_16result);
        _16result = _1;
    }

    //     opRETURNP()
    _16opRETURNP();

    // end procedure
    DeRef(_4953);
    return 0;
    ;
}


int _16opCALL_BACK_RETURN()
{
    int _0, _1, _2;
    

    //     keep_running = FALSE  
    _16keep_running = 0;

    // end procedure
    return 0;
    ;
}


int _16opBADRETURNF()
{
    int _0, _1, _2;
    

    //     RTFatal("attempt to exit a function without returning a value")  
    RefDS(_4960);
    _16RTFatal(_4960);

    // end procedure
    return 0;
    ;
}


int _16opRETURNT()
{
    int _4961;
    int _0, _1, _2;
    

    //     pc += 1
    _16pc = _16pc + 1;

    //     if pc > length(Code) then
    _4961 = SEQ_PTR(_4Code)->length;
    if (_16pc <= _4961)
        goto L1;

    // 	keep_running = FALSE  -- we've reached the end of the code
    _16keep_running = 0;
L1:

    // end procedure
    return 0;
    ;
}


int _16opRHS_SUBS()
{
    int _sub = 0;
    int _x = 0;
    int _4979 = 0;
    int _4964 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _4964 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4964);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _4964 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _4964);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _4964 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _4964);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     sub = val[b]
    _2 = (int)SEQ_PTR(_16val);
    _sub = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_sub);

    //     if atom(x) then
    _4964 = IS_ATOM(_x);
    if (_4964 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_4973);
    _16RTFatal(_4973);
L1:

    //     if sequence(sub) then
    DeRef(_4964);
    _4964 = IS_SEQUENCE(_sub);
    if (_4964 == 0)
        goto L2;

    // 	RTFatal("subscript must be an atom\n(reading an element of a sequence)")
    RefDS(_4975);
    _16RTFatal(_4975);
L2:

    //     sub = floor(sub)
    _0 = _sub;
    if (IS_ATOM_INT(_sub))
        _sub = e_floor(_sub);
    else
        _sub = unary_op(FLOOR, _sub);
    DeRef(_0);

    //     if sub < 1 or sub > length(x) then
    DeRef(_4964);
    if (IS_ATOM_INT(_sub)) {
        _4964 = (_sub < 1);
    }
    else {
        _4964 = binary_op(LESS, _sub, 1);
    }
    if (IS_ATOM_INT(_4964)) {
        if (_4964 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_4964)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_4979);
    _4979 = SEQ_PTR(_x)->length;
    if (IS_ATOM_INT(_sub)) {
        _4979 = (_sub > _4979);
    }
    else {
        _4979 = binary_op(GREATER, _sub, _4979);
    }
L4:
    if (_4979 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_4979) && DBL_PTR(_4979)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	RTFatal(
    DeRef(_4979);
    _4979 = SEQ_PTR(_x)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _sub;
    Ref(_sub);
    ((int *)_2)[2] = _4979;
    _4979 = MAKE_SEQ(_1);
    _0 = _4979;
    _4979 = EPrintf(-9999999, _4981, _4979);
    DeRefDS(_0);
    RefDS(_4979);
    _16RTFatal(_4979);
L5:

    //     val[target] = x[sub]
    DeRef(_4979);
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_sub))
        _4979 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_sub)->dbl));
    else
        _4979 = (int)*(((s1_ptr)_2)->base + _sub);
    Ref(_4979);
    Ref(_4979);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _4979;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_sub);
    DeRef(_x);
    DeRef(_4979);
    DeRef(_4964);
    return 0;
    ;
}


int _16opIF()
{
    int _4987 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _4987 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4987);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if val[a] = 0 then
    _2 = (int)SEQ_PTR(_16val);
    _4987 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4987);
    if (binary_op_a(NOTEQ, _4987, 0))
        goto L1;

    // 	pc = Code[pc+2]
    DeRef(_4987);
    _4987 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _4987);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
    goto L2;
L1:

    // 	pc += 3
    _16pc = _16pc + 3;
L2:

    // end procedure
    DeRef(_4987);
    return 0;
    ;
}


int _16opINTEGER_CHECK()
{
    int _4994 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _4994 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4994);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if not integer(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _4994 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4994);
    _0 = _4994;
    if (IS_ATOM_INT(_4994))
        _4994 = 1;
    else if (IS_ATOM_DBL(_4994))
        _4994 = IS_ATOM_INT(DoubleToInt(_4994));
    else
        _4994 = 0;
    DeRef(_0);
    if (_4994 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _4994 = _16pc + 1;
    if (_4994 > MAXINT)
        _4994 = NewDouble((double)_4994);
    Ref(_4994);
    _16RTFatalType(_4994);
L1:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_4994);
    return 0;
    ;
}


int _16opATOM_CHECK()
{
    int _5001 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5001 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5001);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if not atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5001 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5001);
    _0 = _5001;
    _5001 = IS_ATOM(_5001);
    DeRef(_0);
    if (_5001 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _5001 = _16pc + 1;
    if (_5001 > MAXINT)
        _5001 = NewDouble((double)_5001);
    Ref(_5001);
    _16RTFatalType(_5001);
L1:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_5001);
    return 0;
    ;
}


int _16opSEQUENCE_CHECK()
{
    int _5008 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5008 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5008);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if not sequence(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5008 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5008);
    _0 = _5008;
    _5008 = IS_SEQUENCE(_5008);
    DeRef(_0);
    if (_5008 != 0)
        goto L1;

    // 	RTFatalType(pc+1)
    _5008 = _16pc + 1;
    if (_5008 > MAXINT)
        _5008 = NewDouble((double)_5008);
    Ref(_5008);
    _16RTFatalType(_5008);
L1:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_5008);
    return 0;
    ;
}


int _16opASSIGN()
{
    int _5015 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5015 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5015);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5015 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5015);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _5015 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5015);
    Ref(_5015);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5015;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5015);
    return 0;
    ;
}


int _16opELSE()
{
    int _5021;
    int _0, _1, _2;
    

    //     pc = Code[pc+1]
    _5021 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5021);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // end procedure
    return 0;
    ;
}


int _16opRIGHT_BRACE_N()
{
    int _x = 0;
    int _5023 = 0;
    int _5027 = 0;
    int _0, _1, _2;
    

    //     len = Code[pc+1]
    _5023 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16len = (int)*(((s1_ptr)_2)->base + _5023);
    if (!IS_ATOM_INT(_16len))
        _16len = (long)DBL_PTR(_16len)->dbl;

    //     x = {}
    RefDS(_39);
    _x = _39;

    //     for i = pc+len+1 to pc+2 by -1 do
    _5023 = _16pc + _16len;
    if ((long)((unsigned long)_5023 + (unsigned long)HIGH_BITS) >= 0) 
        _5023 = NewDouble((double)_5023);
    _0 = _5023;
    if (IS_ATOM_INT(_5023)) {
        _5023 = _5023 + 1;
        if (_5023 > MAXINT)
            _5023 = NewDouble((double)_5023);
    }
    else
        _5023 = binary_op(PLUS, 1, _5023);
    DeRef(_0);
    _5027 = _16pc + 2;
    if ((long)((unsigned long)_5027 + (unsigned long)HIGH_BITS) >= 0) 
        _5027 = NewDouble((double)_5027);
    { int _i;
        Ref(_5023);
        _i = _5023;
L1:
        if (binary_op_a(LESS, _i, _5027))
            goto L2;

        // 	x = append(x, val[Code[i]])
        DeRef(_5023);
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_i))
            _5023 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_i)->dbl));
        else
            _5023 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5023);
        _0 = _5023;
        _2 = (int)SEQ_PTR(_16val);
        if (!IS_ATOM_INT(_5023))
            _5023 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5023)->dbl));
        else
            _5023 = (int)*(((s1_ptr)_2)->base + _5023);
        Ref(_5023);
        DeRef(_0);
        Ref(_5023);
        Append(&_x, _x, _5023);

        //     end for
        _0 = _i;
        if (IS_ATOM_INT(_i)) {
            _i = _i + -1;
            if ((long)((unsigned long)_i +(unsigned long) HIGH_BITS) >= 0) 
                _i = NewDouble((double)_i);
        }
        else {
            _i = binary_op_a(PLUS, _i, -1);
        }
        DeRef(_0);
        goto L1;
L2:
        ;
        DeRef(_i);
    }

    //     target = Code[pc+len+2]
    DeRef(_5023);
    _5023 = _16pc + _16len;
    if ((long)((unsigned long)_5023 + (unsigned long)HIGH_BITS) >= 0) 
        _5023 = NewDouble((double)_5023);
    _0 = _5023;
    if (IS_ATOM_INT(_5023)) {
        _5023 = _5023 + 2;
    }
    else {
        _5023 = NewDouble(DBL_PTR(_5023)->dbl + (double)2);
    }
    DeRef(_0);
    _2 = (int)SEQ_PTR(_4Code);
    if (!IS_ATOM_INT(_5023))
        _16target = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5023)->dbl));
    else
        _16target = (int)*(((s1_ptr)_2)->base + _5023);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = x
    RefDS(_x);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    //     pc += 3 + len
    DeRef(_5023);
    _5023 = 3 + _16len;
    if ((long)((unsigned long)_5023 + (unsigned long)HIGH_BITS) >= 0) 
        _5023 = NewDouble((double)_5023);
    if (IS_ATOM_INT(_5023)) {
        _16pc = _16pc + _5023;
    }
    else {
        _16pc = NewDouble((double)_16pc + DBL_PTR(_5023)->dbl);
    }
    if (!IS_ATOM_INT(_16pc)) {
        _1 = (long)(DBL_PTR(_16pc)->dbl);
        DeRefDS(_16pc);
        _16pc = _1;
    }

    // end procedure
    DeRefDS(_x);
    DeRef(_5023);
    DeRef(_5027);
    return 0;
    ;
}


int _16opRIGHT_BRACE_2()
{
    int _5041 = 0;
    int _5036 = 0;
    int _0, _1, _2;
    

    //     target = Code[pc+3]
    _5036 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5036);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = {val[Code[pc+2]], val[Code[pc+1]]}
    _5036 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5036 = (int)*(((s1_ptr)_2)->base + _5036);
    Ref(_5036);
    _0 = _5036;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5036))
        _5036 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5036)->dbl));
    else
        _5036 = (int)*(((s1_ptr)_2)->base + _5036);
    Ref(_5036);
    DeRef(_0);
    _5041 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5041 = (int)*(((s1_ptr)_2)->base + _5041);
    Ref(_5041);
    _0 = _5041;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5041))
        _5041 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5041)->dbl));
    else
        _5041 = (int)*(((s1_ptr)_2)->base + _5041);
    Ref(_5041);
    DeRef(_0);
    _0 = _5041;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5036;
    Ref(_5036);
    ((int *)_2)[2] = _5041;
    Ref(_5041);
    _5041 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_5041);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5041;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_5041);
    DeRef(_5036);
    return 0;
    ;
}


int _16opPLUS1()
{
    int _5046 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5046 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5046);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+3] 
    _5046 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5046);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] + 1
    _2 = (int)SEQ_PTR(_16val);
    _5046 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5046);
    _0 = _5046;
    if (IS_ATOM_INT(_5046)) {
        _5046 = _5046 + 1;
        if (_5046 > MAXINT)
            _5046 = NewDouble((double)_5046);
    }
    else
        _5046 = binary_op(PLUS, 1, _5046);
    DeRef(_0);
    Ref(_5046);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5046;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5046);
    return 0;
    ;
}


int _16opGLOBAL_INIT_CHECK()
{
    int _5053 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5053 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5053);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if equal(val[a], NOVALUE) then
    _2 = (int)SEQ_PTR(_16val);
    _5053 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5053);
    _0 = _5053;
    if (_5053 == _4NOVALUE)
        _5053 = 1;
    else if (IS_ATOM_INT(_5053) && IS_ATOM_INT(_4NOVALUE))
        _5053 = 0;
    else
        _5053 = (compare(_5053, _4NOVALUE) == 0);
    DeRef(_0);
    if (_5053 == 0)
        goto L1;

    // 	RTFatal(SymTab[a][S_NAME] & " has not been initialized")
    _2 = (int)SEQ_PTR(_4SymTab);
    _5053 = (int)*(((s1_ptr)_2)->base + _16a);
    RefDS(_5053);
    _0 = _5053;
    _2 = (int)SEQ_PTR(_5053);
    _5053 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5053);
    DeRefDS(_0);
    if (IS_SEQUENCE(_5053) && IS_ATOM(_5059)) {
    }
    else if (IS_ATOM(_5053) && IS_SEQUENCE(_5059)) {
        Ref(_5053);
        Prepend(&_5053, _5059, _5053);
    }
    else {
        Concat((object_ptr)&_5053, _5053, (s1_ptr)_5059);
    }
    RefDS(_5053);
    _16RTFatal(_5053);
L1:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_5053);
    return 0;
    ;
}


int _16opWHILE()
{
    int _5062 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5062 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5062);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if val[a] = 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5062 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5062);
    if (binary_op_a(NOTEQ, _5062, 0))
        goto L1;

    // 	pc = Code[pc+2]
    DeRef(_5062);
    _5062 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5062);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
    goto L2;
L1:

    // 	pc += 3
    _16pc = _16pc + 3;
L2:

    // end procedure
    DeRef(_5062);
    return 0;
    ;
}


int _16var_subs(int _x, int _subs)
{
    int _si = 0;
    int _5078 = 0;
    int _5071 = 0;
    int _5069;
    int _0, _1, _2;
    

    //     if atom(x) then
    _5069 = IS_ATOM(_x);
    if (_5069 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_4973);
    _16RTFatal(_4973);
L1:

    //     for i = 1 to length(subs) do
    _5069 = SEQ_PTR(_subs)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _5069)
            goto L3;

        // 	si = subs[i]
        DeRef(_si);
        _2 = (int)SEQ_PTR(_subs);
        _si = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_si);

        // 	if sequence(si) then
        DeRef(_5071);
        _5071 = IS_SEQUENCE(_si);
        if (_5071 == 0)
            goto L4;

        // 	    RTFatal("A subscript must be an atom")
        RefDS(_5073);
        _16RTFatal(_5073);
L4:

        // 	si = floor(si)
        _0 = _si;
        if (IS_ATOM_INT(_si))
            _si = e_floor(_si);
        else
            _si = unary_op(FLOOR, _si);
        DeRef(_0);

        // 	if si > length(x) or si < 1 then
        DeRef(_5071);
        _5071 = SEQ_PTR(_x)->length;
        if (IS_ATOM_INT(_si)) {
            _5071 = (_si > _5071);
        }
        else {
            _5071 = binary_op(GREATER, _si, _5071);
        }
        if (IS_ATOM_INT(_5071)) {
            if (_5071 != 0) {
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_5071)->dbl != 0.0) {
                goto L5;
            }
        }
        DeRef(_5078);
        if (IS_ATOM_INT(_si)) {
            _5078 = (_si < 1);
        }
        else {
            _5078 = binary_op(LESS, _si, 1);
        }
L6:
        if (_5078 == 0) {
            goto L7;
        }
        else {
            if (!IS_ATOM_INT(_5078) && DBL_PTR(_5078)->dbl == 0.0)
                goto L7;
        }
L5:

        // 	    RTFatal(
        DeRef(_5078);
        _5078 = SEQ_PTR(_x)->length;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _si;
        Ref(_si);
        ((int *)_2)[2] = _5078;
        _5078 = MAKE_SEQ(_1);
        _0 = _5078;
        _5078 = EPrintf(-9999999, _4981, _5078);
        DeRefDS(_0);
        RefDS(_5078);
        _16RTFatal(_5078);
L7:

        // 	x = x[subs[i]]
        DeRef(_5078);
        _2 = (int)SEQ_PTR(_subs);
        _5078 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5078);
        _0 = _x;
        _2 = (int)SEQ_PTR(_x);
        if (!IS_ATOM_INT(_5078))
            _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5078)->dbl));
        else
            _x = (int)*(((s1_ptr)_2)->base + _5078);
        Ref(_x);
        DeRef(_0);

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     return x
    DeRefDS(_subs);
    DeRef(_si);
    DeRef(_5078);
    DeRef(_5071);
    return _x;
    ;
}


int _16opLENGTH()
{
    int _5084 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5084 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5084);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5084 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5084);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5084 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5084);
    _0 = _5084;
    _5084 = IS_ATOM(_5084);
    DeRef(_0);
    if (_5084 == 0)
        goto L1;

    // 	RTFatal("length of an atom is not defined")
    RefDS(_5090);
    _16RTFatal(_5090);
L1:

    //     val[target] = length(val[a])
    DeRef(_5084);
    _2 = (int)SEQ_PTR(_16val);
    _5084 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5084);
    _0 = _5084;
    _5084 = SEQ_PTR(_5084)->length;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5084;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


int _16opPLENGTH()
{
    int _5101 = 0;
    int _5094 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5094 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5094);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5094 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5094);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_16val);
    _5094 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5094);
    _2 = (int)SEQ_PTR(_5094);
    _16lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16lhs_seq_index))
        _16lhs_seq_index = (long)DBL_PTR(_16lhs_seq_index)->dbl;

    //     lhs_subs = val[a][2..$]
    DeRef(_5094);
    _2 = (int)SEQ_PTR(_16val);
    _5094 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5094);
    _5101 = SEQ_PTR(_5094)->length;
    rhs_slice_target = (object_ptr)&_16lhs_subs;
    RHS_Slice((s1_ptr)_5094, 2, _5101);

    //     val[target] = length(var_subs(val[lhs_seq_index], lhs_subs))
    _2 = (int)SEQ_PTR(_16val);
    _5101 = (int)*(((s1_ptr)_2)->base + _16lhs_seq_index);
    Ref(_5101);
    Ref(_5101);
    RefDS(_16lhs_subs);
    _0 = _5101;
    _5101 = _16var_subs(_5101, _16lhs_subs);
    DeRef(_0);
    _0 = _5101;
    _5101 = SEQ_PTR(_5101)->length;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5101;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5094);
    return 0;
    ;
}


int _16opLHS_SUBS()
{
    int _5114 = 0;
    int _5107 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1] -- base var sequence, or a temp that contains
    _5107 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5107);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2] -- subscript
    _5107 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5107);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3] -- temp for storing result
    _5107 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5107);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = append(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5107 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5107);
    _2 = (int)SEQ_PTR(_16val);
    _5114 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5114);
    Ref(_5114);
    Append(&_5114, _5107, _5114);
    RefDS(_5114);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5114;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRefDS(_5114);
    DeRef(_5107);
    return 0;
    ;
}


int _16opLHS_SUBS1()
{
    int _5117 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1] -- base var sequence, or a temp that contains
    _5117 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5117);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2] -- subscript
    _5117 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5117);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3] -- temp for storing result
    _5117 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5117);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = {a, val[b]}
    _2 = (int)SEQ_PTR(_16val);
    _5117 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5117);
    _0 = _5117;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16a;
    ((int *)_2)[2] = _5117;
    Ref(_5117);
    _5117 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_5117);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5117;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRefDS(_5117);
    return 0;
    ;
}


int _16opLHS_SUBS1_COPY()
{
    int _5126 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1] -- base var sequence
    _5126 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5126);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2] -- subscript
    _5126 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5126);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3] -- temp for storing result
    _5126 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5126);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     c = Code[pc+4] -- temp to hold base sequence while it's manipulated
    _5126 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5126);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     val[c] = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _5126 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5126);
    Ref(_5126);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16c);
    _1 = *(int *)_2;
    *(int *)_2 = _5126;
    DeRef(_1);

    //     val[target] = {c, val[b]}
    DeRef(_5126);
    _2 = (int)SEQ_PTR(_16val);
    _5126 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5126);
    _0 = _5126;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _16c;
    ((int *)_2)[2] = _5126;
    Ref(_5126);
    _5126 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_5126);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5126;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRefDS(_5126);
    return 0;
    ;
}


int _16lhs_check_subs(int _seq, int _subs)
{
    int _5147 = 0;
    int _5138 = 0;
    int _0, _1, _2;
    

    //     if atom(seq) then
    _5138 = IS_ATOM(_seq);
    if (_5138 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(assigning to it)")
    RefDS(_5139);
    _16RTFatal(_5139);
L1:

    //     if sequence(subs) then
    DeRef(_5138);
    _5138 = IS_SEQUENCE(_subs);
    if (_5138 == 0)
        goto L2;

    // 	RTFatal(
    _5138 = SEQ_PTR(_seq)->length;
    _5138 = EPrintf(-9999999, _5141, _5138);
    RefDS(_5138);
    _16RTFatal(_5138);
L2:

    //     subs = floor(subs)
    _0 = _subs;
    if (IS_ATOM_INT(_subs))
        _subs = e_floor(_subs);
    else
        _subs = unary_op(FLOOR, _subs);
    DeRef(_0);

    //     if subs < 1 or subs > length(seq) then
    DeRef(_5138);
    if (IS_ATOM_INT(_subs)) {
        _5138 = (_subs < 1);
    }
    else {
        _5138 = binary_op(LESS, _subs, 1);
    }
    if (IS_ATOM_INT(_5138)) {
        if (_5138 != 0) {
            goto L3;
        }
    }
    else {
        if (DBL_PTR(_5138)->dbl != 0.0) {
            goto L3;
        }
    }
    DeRef(_5147);
    _5147 = SEQ_PTR(_seq)->length;
    if (IS_ATOM_INT(_subs)) {
        _5147 = (_subs > _5147);
    }
    else {
        _5147 = binary_op(GREATER, _subs, _5147);
    }
L4:
    if (_5147 == 0) {
        goto L5;
    }
    else {
        if (!IS_ATOM_INT(_5147) && DBL_PTR(_5147)->dbl == 0.0)
            goto L5;
    }
L3:

    // 	RTFatal(
    DeRef(_5147);
    _5147 = SEQ_PTR(_seq)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _subs;
    Ref(_subs);
    ((int *)_2)[2] = _5147;
    _5147 = MAKE_SEQ(_1);
    _0 = _5147;
    _5147 = EPrintf(-9999999, _5149, _5147);
    DeRefDS(_0);
    RefDS(_5147);
    _16RTFatal(_5147);
L5:

    // end procedure
    DeRef(_seq);
    DeRef(_subs);
    DeRef(_5147);
    DeRef(_5138);
    return 0;
    ;
}


int _16check_slice(int _seq, int _lower, int _upper)
{
    int _len = 0;
    int _5175 = 0;
    int _5173;
    int _5153 = 0;
    int _0, _1, _2;
    

    //     if sequence(lower) then
    _5153 = IS_SEQUENCE(_lower);
    if (_5153 == 0)
        goto L1;

    // 	RTFatal("slice lower index is not an atom")
    RefDS(_5154);
    _16RTFatal(_5154);
L1:

    //     lower = floor(lower)
    _0 = _lower;
    if (IS_ATOM_INT(_lower))
        _lower = e_floor(_lower);
    else
        _lower = unary_op(FLOOR, _lower);
    DeRef(_0);

    //     if lower < 1 then
    if (binary_op_a(GREATEREQ, _lower, 1))
        goto L2;

    // 	RTFatal("slice lower index is less than 1")
    RefDS(_5157);
    _16RTFatal(_5157);
L2:

    //     if sequence(upper) then
    DeRef(_5153);
    _5153 = IS_SEQUENCE(_upper);
    if (_5153 == 0)
        goto L3;

    // 	RTFatal("slice upper index is not an atom")
    RefDS(_5159);
    _16RTFatal(_5159);
L3:

    //     upper = floor(upper)
    _0 = _upper;
    if (IS_ATOM_INT(_upper))
        _upper = e_floor(_upper);
    else
        _upper = unary_op(FLOOR, _upper);
    DeRef(_0);

    //     if upper < 0 then
    if (binary_op_a(GREATEREQ, _upper, 0))
        goto L4;

    // 	RTFatal("slice upper index is less than 0")
    RefDS(_5162);
    _16RTFatal(_5162);
L4:

    //     if atom(seq) then
    DeRef(_5153);
    _5153 = IS_ATOM(_seq);
    if (_5153 == 0)
        goto L5;

    // 	RTFatal("attempt to slice an atom")
    RefDS(_5164);
    _16RTFatal(_5164);
L5:

    //     len = upper - lower + 1
    DeRef(_5153);
    if (IS_ATOM_INT(_upper) && IS_ATOM_INT(_lower)) {
        _5153 = _upper - _lower;
        if ((long)((unsigned long)_5153 +(unsigned long) HIGH_BITS) >= 0)
            _5153 = NewDouble((double)_5153);
    }
    else {
        _5153 = binary_op(MINUS, _upper, _lower);
    }
    DeRef(_len);
    if (IS_ATOM_INT(_5153)) {
        _len = _5153 + 1;
        if (_len > MAXINT)
            _len = NewDouble((double)_len);
    }
    else
        _len = binary_op(PLUS, 1, _5153);

    //     if len < 0 then
    if (binary_op_a(GREATEREQ, _len, 0))
        goto L6;

    // 	RTFatal("slice length is less than 0")
    RefDS(_5168);
    _16RTFatal(_5168);
L6:

    //     if lower > length(seq) + 1 or (len > 0 and lower > length(seq)) then
    DeRef(_5153);
    _5153 = SEQ_PTR(_seq)->length;
    _5153 = _5153 + 1;
    if (IS_ATOM_INT(_lower)) {
        _5153 = (_lower > _5153);
    }
    else {
        _5153 = binary_op(GREATER, _lower, _5153);
    }
    if (IS_ATOM_INT(_5153)) {
        if (_5153 != 0) {
            goto L7;
        }
    }
    else {
        if (DBL_PTR(_5153)->dbl != 0.0) {
            goto L7;
        }
    }
    if (IS_ATOM_INT(_len)) {
        _5173 = (_len > 0);
    }
    else {
        _5173 = (DBL_PTR(_len)->dbl > (double)0);
    }
    if (_5173 == 0) {
        _5173 = 0;
        goto L8;
    }
    DeRef(_5175);
    _5175 = SEQ_PTR(_seq)->length;
    if (IS_ATOM_INT(_lower)) {
        _5175 = (_lower > _5175);
    }
    else {
        _5175 = binary_op(GREATER, _lower, _5175);
    }
    if (IS_ATOM_INT(_5175))
        _5173 = (_5175 != 0);
    else
        _5173 = DBL_PTR(_5175)->dbl != 0.0;
L8:
L9:
    if (_5173 == 0)
        goto LA;
L7:

    // 	RTFatal("slice starts past end of sequence")
    RefDS(_5177);
    _16RTFatal(_5177);
LA:

    //     if upper > length(seq) then
    DeRef(_5175);
    _5175 = SEQ_PTR(_seq)->length;
    if (binary_op_a(LESSEQ, _upper, _5175))
        goto LB;

    // 	RTFatal("slice ends past end of sequence")
    RefDS(_5180);
    _16RTFatal(_5180);
LB:

    // end procedure
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_len);
    DeRef(_5175);
    DeRef(_5153);
    return 0;
    ;
}


int _16lhs_check_slice(int _seq, int _lower, int _upper, int _rhs)
{
    int _len = 0;
    int _5181 = 0;
    int _5182 = 0;
    int _0, _1, _2;
    

    //     check_slice(seq, lower, upper)
    Ref(_seq);
    Ref(_lower);
    Ref(_upper);
    _16check_slice(_seq, _lower, _upper);

    //     len = floor(upper) - floor(lower) + 1
    if (IS_ATOM_INT(_upper))
        _5181 = e_floor(_upper);
    else
        _5181 = unary_op(FLOOR, _upper);
    if (IS_ATOM_INT(_lower))
        _5182 = e_floor(_lower);
    else
        _5182 = unary_op(FLOOR, _lower);
    _0 = _5182;
    if (IS_ATOM_INT(_5181) && IS_ATOM_INT(_5182)) {
        _5182 = _5181 - _5182;
        if ((long)((unsigned long)_5182 +(unsigned long) HIGH_BITS) >= 0)
            _5182 = NewDouble((double)_5182);
    }
    else {
        _5182 = binary_op(MINUS, _5181, _5182);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5182)) {
        _len = _5182 + 1;
        if (_len > MAXINT)
            _len = NewDouble((double)_len);
    }
    else
        _len = binary_op(PLUS, 1, _5182);

    //     if sequence(rhs) and length(rhs) != len then
    DeRef(_5182);
    _5182 = IS_SEQUENCE(_rhs);
    if (_5182 == 0) {
        goto L1;
    }
    DeRef(_5181);
    _5181 = SEQ_PTR(_rhs)->length;
    if (IS_ATOM_INT(_len)) {
        _5181 = (_5181 != _len);
    }
    else {
        _5181 = ((double)_5181 != DBL_PTR(_len)->dbl);
    }
L2:
    if (_5181 == 0)
        goto L1;

    // 	RTFatal("lengths do not match on assignment to slice")
    RefDS(_5189);
    _16RTFatal(_5189);
L1:

    // end procedure
    DeRef(_seq);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs);
    DeRef(_len);
    DeRef(_5181);
    DeRef(_5182);
    return 0;
    ;
}


int _16var_slice(int _x, int _subs, int _lower, int _upper)
{
    int _5197 = 0;
    int _5192 = 0;
    int _5190;
    int _0, _1, _2;
    

    //     if atom(x) then
    _5190 = IS_ATOM(_x);
    if (_5190 == 0)
        goto L1;

    // 	RTFatal("attempt to subscript an atom\n(reading from it)")
    RefDS(_4973);
    _16RTFatal(_4973);
L1:

    //     for i = 1 to length(subs) do
    _5190 = SEQ_PTR(_subs)->length;
    { int _i;
        _i = 1;
L2:
        if (_i > _5190)
            goto L3;

        // 	if sequence(subs[i]) then
        DeRef(_5192);
        _2 = (int)SEQ_PTR(_subs);
        _5192 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5192);
        _0 = _5192;
        _5192 = IS_SEQUENCE(_5192);
        DeRef(_0);
        if (_5192 == 0)
            goto L4;

        // 	    RTFatal("subscript must be an atom")
        RefDS(_5194);
        _16RTFatal(_5194);
L4:

        // 	subs = floor(subs)
        _0 = _subs;
        _subs = unary_op(FLOOR, _subs);
        DeRefDS(_0);

        // 	if subs[i] > length(x) or subs[i] < 1 then
        DeRef(_5192);
        _2 = (int)SEQ_PTR(_subs);
        _5192 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5192);
        DeRef(_5197);
        _5197 = SEQ_PTR(_x)->length;
        if (IS_ATOM_INT(_5192)) {
            _5197 = (_5192 > _5197);
        }
        else {
            _5197 = binary_op(GREATER, _5192, _5197);
        }
        if (IS_ATOM_INT(_5197)) {
            if (_5197 != 0) {
                goto L5;
            }
        }
        else {
            if (DBL_PTR(_5197)->dbl != 0.0) {
                goto L5;
            }
        }
        DeRef(_5192);
        _2 = (int)SEQ_PTR(_subs);
        _5192 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5192);
        _0 = _5192;
        if (IS_ATOM_INT(_5192)) {
            _5192 = (_5192 < 1);
        }
        else {
            _5192 = binary_op(LESS, _5192, 1);
        }
        DeRef(_0);
L6:
        if (_5192 == 0) {
            goto L7;
        }
        else {
            if (!IS_ATOM_INT(_5192) && DBL_PTR(_5192)->dbl == 0.0)
                goto L7;
        }
L5:

        // 	    RTFatal(
        DeRef(_5192);
        _2 = (int)SEQ_PTR(_subs);
        _5192 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5192);
        DeRef(_5197);
        _5197 = SEQ_PTR(_x)->length;
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _5192;
        Ref(_5192);
        ((int *)_2)[2] = _5197;
        _5197 = MAKE_SEQ(_1);
        _0 = _5197;
        _5197 = EPrintf(-9999999, _4981, _5197);
        DeRefDS(_0);
        RefDS(_5197);
        _16RTFatal(_5197);
L7:

        // 	x = x[subs[i]] 
        DeRef(_5197);
        _2 = (int)SEQ_PTR(_subs);
        _5197 = (int)*(((s1_ptr)_2)->base + _i);
        Ref(_5197);
        _0 = _x;
        _2 = (int)SEQ_PTR(_x);
        if (!IS_ATOM_INT(_5197))
            _x = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5197)->dbl));
        else
            _x = (int)*(((s1_ptr)_2)->base + _5197);
        Ref(_x);
        DeRef(_0);

        //     end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    //     check_slice(x, lower, upper)
    Ref(_x);
    Ref(_lower);
    Ref(_upper);
    _16check_slice(_x, _lower, _upper);

    //     return x[lower..upper]
    rhs_slice_target = (object_ptr)&_5197;
    RHS_Slice((s1_ptr)_x, _lower, _upper);
    DeRef(_x);
    DeRefDS(_subs);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_5192);
    return _5197;
    ;
}


int _16assign_subs(int _x, int _subs, int _rhs_val)
{
    int _5218 = 0;
    int _5216 = 0;
    int _5214 = 0;
    int _5209 = 0;
    int _0, _1, _2;
    

    //     lhs_check_subs(x, subs[1])
    _2 = (int)SEQ_PTR(_subs);
    _5209 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5209);
    RefDS(_x);
    Ref(_5209);
    _16lhs_check_subs(_x, _5209);

    //     if length(subs) = 1 then
    DeRef(_5209);
    _5209 = SEQ_PTR(_subs)->length;
    if (_5209 != 1)
        goto L1;

    // 	x[subs[1]] = rhs_val
    _2 = (int)SEQ_PTR(_subs);
    _5209 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5209);
    Ref(_rhs_val);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5209))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5209)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _5209);
    _1 = *(int *)_2;
    *(int *)_2 = _rhs_val;
    DeRef(_1);
    goto L2;
L1:

    // 	x[subs[1]] = assign_subs(x[subs[1]], subs[2..$], rhs_val)
    DeRef(_5209);
    _2 = (int)SEQ_PTR(_subs);
    _5209 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5209);
    DeRef(_5214);
    _2 = (int)SEQ_PTR(_subs);
    _5214 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5214);
    _0 = _5214;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_5214))
        _5214 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5214)->dbl));
    else
        _5214 = (int)*(((s1_ptr)_2)->base + _5214);
    Ref(_5214);
    DeRef(_0);
    DeRef(_5216);
    _5216 = SEQ_PTR(_subs)->length;
    rhs_slice_target = (object_ptr)&_5216;
    RHS_Slice((s1_ptr)_subs, 2, _5216);
    Ref(_rhs_val);
    DeRef(_5218);
    _5218 = _rhs_val;
    Ref(_5214);
    RefDS(_5216);
    Ref(_5218);
    _0 = _5218;
    _5218 = _16assign_subs(_5214, _5216, _5218);
    DeRef(_0);
    RefDS(_5218);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5209))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5209)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _5209);
    _1 = *(int *)_2;
    *(int *)_2 = _5218;
    DeRef(_1);
L2:

    //     return x
    DeRefDS(_subs);
    DeRef(_rhs_val);
    DeRef(_5218);
    DeRef(_5216);
    DeRef(_5214);
    DeRef(_5209);
    return _x;
    ;
}


int _16assign_slice(int _x, int _subs, int _lower, int _upper, int _rhs_val)
{
    int _5235 = 0;
    int _5234 = 0;
    int _5233 = 0;
    int _5231 = 0;
    int _5220 = 0;
    int _5227 = 0;
    int _0, _1, _2, _3;
    

    //     lhs_check_subs(x, subs[1])
    _2 = (int)SEQ_PTR(_subs);
    _5220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5220);
    RefDS(_x);
    Ref(_5220);
    _16lhs_check_subs(_x, _5220);

    //     if length(subs) = 1 then
    DeRef(_5220);
    _5220 = SEQ_PTR(_subs)->length;
    if (_5220 != 1)
        goto L1;

    // 	lhs_check_slice(x[subs[1]],lower,upper,rhs_val)
    _2 = (int)SEQ_PTR(_subs);
    _5220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5220);
    _0 = _5220;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_5220))
        _5220 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5220)->dbl));
    else
        _5220 = (int)*(((s1_ptr)_2)->base + _5220);
    Ref(_5220);
    DeRef(_0);
    Ref(_5220);
    Ref(_lower);
    Ref(_upper);
    Ref(_rhs_val);
    _16lhs_check_slice(_5220, _lower, _upper, _rhs_val);

    // 	x[subs[1]][lower..upper] = rhs_val
    DeRef(_5220);
    _2 = (int)SEQ_PTR(_subs);
    _5220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5220);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5220))
        _3 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5220)->dbl));
    else
        _3 = (int)(_5220 + ((s1_ptr)_2)->base);
    assign_slice_seq = (s1_ptr *)_3;
    AssignSlice(_lower, _upper, _rhs_val);
    goto L2;
L1:

    // 	x[subs[1]] = assign_slice(x[subs[1]], subs[2..$], lower, upper, rhs_val)
    DeRef(_5227);
    _2 = (int)SEQ_PTR(_subs);
    _5227 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5227);
    DeRef(_5220);
    _2 = (int)SEQ_PTR(_subs);
    _5220 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5220);
    _0 = _5220;
    _2 = (int)SEQ_PTR(_x);
    if (!IS_ATOM_INT(_5220))
        _5220 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5220)->dbl));
    else
        _5220 = (int)*(((s1_ptr)_2)->base + _5220);
    Ref(_5220);
    DeRef(_0);
    DeRef(_5231);
    _5231 = SEQ_PTR(_subs)->length;
    rhs_slice_target = (object_ptr)&_5231;
    RHS_Slice((s1_ptr)_subs, 2, _5231);
    Ref(_lower);
    DeRef(_5233);
    _5233 = _lower;
    Ref(_upper);
    DeRef(_5234);
    _5234 = _upper;
    Ref(_rhs_val);
    DeRef(_5235);
    _5235 = _rhs_val;
    Ref(_5220);
    RefDS(_5231);
    Ref(_5233);
    Ref(_5234);
    Ref(_5235);
    _0 = _5235;
    _5235 = _16assign_slice(_5220, _5231, _5233, _5234, _5235);
    DeRef(_0);
    RefDS(_5235);
    _2 = (int)SEQ_PTR(_x);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _x = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5227))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5227)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _5227);
    _1 = *(int *)_2;
    *(int *)_2 = _5235;
    DeRef(_1);
L2:

    //     return x
    DeRefDS(_subs);
    DeRef(_lower);
    DeRef(_upper);
    DeRef(_rhs_val);
    DeRef5(_5235, _5234, _5233, _5231, _5220);
    DeRef(_5227);
    return _x;
    ;
}


int _16opASSIGN_SUBS()
{
    int _x = 0;
    int _subs = 0;
    int _5237 = 0;
    int _0, _1, _2, _3;
    

    //     a = Code[pc+1]  -- the sequence
    _5237 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5237);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]  -- the subscript
    _5237 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5237);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if sequence(val[b]) then
    _2 = (int)SEQ_PTR(_16val);
    _5237 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5237);
    _0 = _5237;
    _5237 = IS_SEQUENCE(_5237);
    DeRef(_0);
    if (_5237 == 0)
        goto L1;

    // 	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")        
    RefDS(_5243);
    _16RTFatal(_5243);
L1:

    //     c = Code[pc+3]  -- the RHS value
    DeRef(_5237);
    _5237 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5237);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     x = val[a] -- avoid lingering ref count on val[a]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     lhs_check_subs(x, val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5237 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5237);
    Ref(_x);
    Ref(_5237);
    _16lhs_check_subs(_x, _5237);

    //     x = val[c]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_x);

    //     subs = val[b]
    DeRef(_subs);
    _2 = (int)SEQ_PTR(_16val);
    _subs = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_subs);

    //     val[a][subs] = x  -- single LHS subscript
    _2 = (int)SEQ_PTR(_16val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16val = MAKE_SEQ(_2);
    }
    _3 = (int)(_16a + ((s1_ptr)_2)->base);
    Ref(_x);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_subs))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_subs)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _subs);
    _1 = *(int *)_2;
    *(int *)_2 = _x;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_x);
    DeRef(_subs);
    DeRef(_5237);
    return 0;
    ;
}


int _16opPASSIGN_SUBS()
{
    int _5269 = 0;
    int _5253 = 0;
    int _5264 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5253 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5253);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]  -- subscript
    _5253 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5253);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if sequence(val[b]) then
    _2 = (int)SEQ_PTR(_16val);
    _5253 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5253);
    _0 = _5253;
    _5253 = IS_SEQUENCE(_5253);
    DeRef(_0);
    if (_5253 == 0)
        goto L1;

    // 	RTFatal("subscript must be an atom\n(assigning to subscript of a sequence)")        
    RefDS(_5243);
    _16RTFatal(_5243);
L1:

    //     c = Code[pc+3]  -- RHS value
    DeRef(_5253);
    _5253 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5253);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_16val);
    _5253 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5253);
    _2 = (int)SEQ_PTR(_5253);
    _16lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16lhs_seq_index))
        _16lhs_seq_index = (long)DBL_PTR(_16lhs_seq_index)->dbl;

    //     lhs_subs = val[a][2..$]    
    DeRef(_5253);
    _2 = (int)SEQ_PTR(_16val);
    _5253 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5253);
    DeRef(_5264);
    _5264 = SEQ_PTR(_5253)->length;
    rhs_slice_target = (object_ptr)&_16lhs_subs;
    RHS_Slice((s1_ptr)_5253, 2, _5264);

    //     val[lhs_seq_index] = assign_subs(val[lhs_seq_index], 
    _2 = (int)SEQ_PTR(_16val);
    _5264 = (int)*(((s1_ptr)_2)->base + _16lhs_seq_index);
    Ref(_5264);
    DeRef(_5253);
    _2 = (int)SEQ_PTR(_16val);
    _5253 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5253);
    if (IS_SEQUENCE(_16lhs_subs) && IS_ATOM(_5253)) {
        Ref(_5253);
        Append(&_5253, _16lhs_subs, _5253);
    }
    else if (IS_ATOM(_16lhs_subs) && IS_SEQUENCE(_5253)) {
    }
    else {
        Concat((object_ptr)&_5253, _16lhs_subs, (s1_ptr)_5253);
    }
    DeRef(_5269);
    _2 = (int)SEQ_PTR(_16val);
    _5269 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5269);
    Ref(_5264);
    RefDS(_5253);
    Ref(_5269);
    _0 = _5269;
    _5269 = _16assign_subs(_5264, _5253, _5269);
    DeRef(_0);
    RefDS(_5269);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16lhs_seq_index);
    _1 = *(int *)_2;
    *(int *)_2 = _5269;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDS(_5269);
    DeRefDS(_5253);
    DeRef(_5264);
    return 0;
    ;
}


int _16opASSIGN_OP_SUBS()
{
    int _x = 0;
    int _5272 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5272 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5272);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5272 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5272);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5272 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5272);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     lhs_subs = {}
    RefDS(_39);
    DeRef(_16lhs_subs);
    _16lhs_subs = _39;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     val[target] = var_subs(x, lhs_subs & val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5272 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5272);
    if (IS_SEQUENCE(_16lhs_subs) && IS_ATOM(_5272)) {
        Ref(_5272);
        Append(&_5272, _16lhs_subs, _5272);
    }
    else if (IS_ATOM(_16lhs_subs) && IS_SEQUENCE(_5272)) {
    }
    else {
        Concat((object_ptr)&_5272, _16lhs_subs, (s1_ptr)_5272);
    }
    Ref(_x);
    RefDS(_5272);
    _0 = _5272;
    _5272 = _16var_subs(_x, _5272);
    DeRefDS(_0);
    Ref(_5272);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5272;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_x);
    DeRef(_5272);
    return 0;
    ;
}


int _16opPASSIGN_OP_SUBS()
{
    int _5292 = 0;
    int _5283 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5283 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5283);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5283 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5283);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5283 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5283);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_16val);
    _5283 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5283);
    _2 = (int)SEQ_PTR(_5283);
    _16lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16lhs_seq_index))
        _16lhs_seq_index = (long)DBL_PTR(_16lhs_seq_index)->dbl;

    //     lhs_subs = val[a][2..$]
    DeRef(_5283);
    _2 = (int)SEQ_PTR(_16val);
    _5283 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5283);
    _5292 = SEQ_PTR(_5283)->length;
    rhs_slice_target = (object_ptr)&_16lhs_subs;
    RHS_Slice((s1_ptr)_5283, 2, _5292);

    //     Code[pc+9] = Code[pc+1] -- patch upcoming op
    _5292 = _16pc + 9;
    if ((long)((unsigned long)_5292 + (unsigned long)HIGH_BITS) >= 0) 
        _5292 = NewDouble((double)_5292);
    DeRef(_5283);
    _5283 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5283 = (int)*(((s1_ptr)_2)->base + _5283);
    Ref(_5283);
    Ref(_5283);
    _2 = (int)SEQ_PTR(_4Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4Code = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5292))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5292)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _5292);
    _1 = *(int *)_2;
    *(int *)_2 = _5283;
    DeRef(_1);

    //     val[target] = var_subs(val[lhs_seq_index], lhs_subs & val[b])
    DeRef(_5283);
    _2 = (int)SEQ_PTR(_16val);
    _5283 = (int)*(((s1_ptr)_2)->base + _16lhs_seq_index);
    Ref(_5283);
    DeRef(_5292);
    _2 = (int)SEQ_PTR(_16val);
    _5292 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5292);
    if (IS_SEQUENCE(_16lhs_subs) && IS_ATOM(_5292)) {
        Ref(_5292);
        Append(&_5292, _16lhs_subs, _5292);
    }
    else if (IS_ATOM(_16lhs_subs) && IS_SEQUENCE(_5292)) {
    }
    else {
        Concat((object_ptr)&_5292, _16lhs_subs, (s1_ptr)_5292);
    }
    Ref(_5283);
    RefDS(_5292);
    _0 = _5292;
    _5292 = _16var_subs(_5283, _5292);
    DeRefDS(_0);
    Ref(_5292);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5292;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5292);
    DeRef(_5283);
    return 0;
    ;
}


int _16opASSIGN_OP_SLICE()
{
    int _x = 0;
    int _5302 = 0;
    int _5309 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5302 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5302);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     b = Code[pc+2]
    _5302 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5302);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if floor(val[b]) > length(x) or floor(val[b]) < 1 then
    _2 = (int)SEQ_PTR(_16val);
    _5302 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5302);
    _0 = _5302;
    if (IS_ATOM_INT(_5302))
        _5302 = e_floor(_5302);
    else
        _5302 = unary_op(FLOOR, _5302);
    DeRef(_0);
    _5309 = SEQ_PTR(_x)->length;
    if (IS_ATOM_INT(_5302)) {
        _5309 = (_5302 > _5309);
    }
    else {
        _5309 = binary_op(GREATER, _5302, _5309);
    }
    if (IS_ATOM_INT(_5309)) {
        if (_5309 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_5309)->dbl != 0.0) {
            goto L1;
        }
    }
    DeRef(_5302);
    _2 = (int)SEQ_PTR(_16val);
    _5302 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5302);
    _0 = _5302;
    if (IS_ATOM_INT(_5302))
        _5302 = e_floor(_5302);
    else
        _5302 = unary_op(FLOOR, _5302);
    DeRef(_0);
    _0 = _5302;
    if (IS_ATOM_INT(_5302)) {
        _5302 = (_5302 < 1);
    }
    else {
        _5302 = binary_op(LESS, _5302, 1);
    }
    DeRef(_0);
L2:
    if (_5302 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_5302) && DBL_PTR(_5302)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	RTFatal(
    DeRef(_5302);
    _2 = (int)SEQ_PTR(_16val);
    _5302 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5302);
    DeRef(_5309);
    _5309 = SEQ_PTR(_x)->length;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = _5302;
    Ref(_5302);
    ((int *)_2)[2] = _5309;
    _5309 = MAKE_SEQ(_1);
    _0 = _5309;
    _5309 = EPrintf(-9999999, _4981, _5309);
    DeRefDS(_0);
    RefDS(_5309);
    _16RTFatal(_5309);
L3:

    //     c = Code[pc+3]
    DeRef(_5309);
    _5309 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5309);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     target = Code[pc+4]
    _5309 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5309);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = var_slice(x, {}, val[b], val[c])
    _2 = (int)SEQ_PTR(_16val);
    _5309 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5309);
    DeRef(_5302);
    _2 = (int)SEQ_PTR(_16val);
    _5302 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5302);
    Ref(_x);
    RefDS(_39);
    Ref(_5309);
    Ref(_5302);
    _0 = _5302;
    _5302 = _16var_slice(_x, _39, _5309, _5302);
    DeRef(_0);
    RefDS(_5302);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5302;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_x);
    DeRefDS(_5302);
    DeRef(_5309);
    return 0;
    ;
}


int _16opPASSIGN_OP_SLICE()
{
    int _x = 0;
    int _5344 = 0;
    int _5327 = 0;
    int _5340 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5327 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5327);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     b = Code[pc+2]
    _5327 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5327);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]
    _5327 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5327);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     target = Code[pc+4]
    _5327 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5327);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     lhs_seq_index = x[1]
    _2 = (int)SEQ_PTR(_x);
    _16lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16lhs_seq_index))
        _16lhs_seq_index = (long)DBL_PTR(_16lhs_seq_index)->dbl;

    //     lhs_subs = x[2..$]
    _5327 = SEQ_PTR(_x)->length;
    rhs_slice_target = (object_ptr)&_16lhs_subs;
    RHS_Slice((s1_ptr)_x, 2, _5327);

    //     Code[pc+10] = Code[pc+1]
    _5327 = _16pc + 10;
    if ((long)((unsigned long)_5327 + (unsigned long)HIGH_BITS) >= 0) 
        _5327 = NewDouble((double)_5327);
    _5340 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5340 = (int)*(((s1_ptr)_2)->base + _5340);
    Ref(_5340);
    Ref(_5340);
    _2 = (int)SEQ_PTR(_4Code);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4Code = MAKE_SEQ(_2);
    }
    if (!IS_ATOM_INT(_5327))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_5327)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _5327);
    _1 = *(int *)_2;
    *(int *)_2 = _5340;
    DeRef(_1);

    //     val[target] = var_slice(val[lhs_seq_index], lhs_subs, val[b], val[c])
    DeRef(_5340);
    _2 = (int)SEQ_PTR(_16val);
    _5340 = (int)*(((s1_ptr)_2)->base + _16lhs_seq_index);
    Ref(_5340);
    DeRef(_5327);
    _2 = (int)SEQ_PTR(_16val);
    _5327 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5327);
    _2 = (int)SEQ_PTR(_16val);
    _5344 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5344);
    Ref(_5340);
    RefDS(_16lhs_subs);
    Ref(_5327);
    Ref(_5344);
    _0 = _5344;
    _5344 = _16var_slice(_5340, _16lhs_subs, _5327, _5344);
    DeRef(_0);
    RefDS(_5344);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5344;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_x);
    DeRefDS(_5344);
    DeRef(_5327);
    DeRef(_5340);
    return 0;
    ;
}


int _16opASSIGN_SLICE()
{
    int _x = 0;
    int _5363 = 0;
    int _5347 = 0;
    int _5357 = 0;
    int _5358 = 0;
    int _0, _1, _2, _3;
    

    //     a = Code[pc+1]  -- sequence
    _5347 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5347);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]  -- 1st index
    _5347 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5347);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]  -- 2nd index
    _5347 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5347);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     d = Code[pc+4]  -- rhs value to assign
    _5347 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16d = (int)*(((s1_ptr)_2)->base + _5347);
    if (!IS_ATOM_INT(_16d))
        _16d = (long)DBL_PTR(_16d)->dbl;

    //     x = val[a] -- avoid lingering ref count on val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     lhs_check_slice(x, val[b], val[c], val[d])
    _2 = (int)SEQ_PTR(_16val);
    _5347 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5347);
    _2 = (int)SEQ_PTR(_16val);
    _5357 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5357);
    _2 = (int)SEQ_PTR(_16val);
    _5358 = (int)*(((s1_ptr)_2)->base + _16d);
    Ref(_5358);
    Ref(_x);
    Ref(_5347);
    Ref(_5357);
    Ref(_5358);
    _16lhs_check_slice(_x, _5347, _5357, _5358);

    //     x = val[d]
    DeRef(_x);
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16d);
    Ref(_x);

    //     val[a][val[b]..val[c]] = x
    _2 = (int)SEQ_PTR(_16val);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16val = MAKE_SEQ(_2);
    }
    _3 = (int)(_16a + ((s1_ptr)_2)->base);
    DeRef(_5347);
    _2 = (int)SEQ_PTR(_16val);
    _5347 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5347);
    _2 = (int)SEQ_PTR(_16val);
    _5363 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5363);
    assign_slice_seq = (s1_ptr *)_3;
    AssignSlice(_5347, _5363, _x);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_x);
    DeRef(_5363);
    DeRef(_5347);
    DeRef(_5357);
    DeRef(_5358);
    return 0;
    ;
}


int _16opPASSIGN_SLICE()
{
    int _5381 = 0;
    int _5380 = 0;
    int _5365 = 0;
    int _5376 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]  -- sequence
    _5365 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5365);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]  -- 1st index
    _5365 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5365);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]  -- 2nd index
    _5365 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5365);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     d = Code[pc+4]  -- rhs value to assign
    _5365 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16d = (int)*(((s1_ptr)_2)->base + _5365);
    if (!IS_ATOM_INT(_16d))
        _16d = (long)DBL_PTR(_16d)->dbl;

    //     lhs_seq_index = val[a][1]
    _2 = (int)SEQ_PTR(_16val);
    _5365 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5365);
    _2 = (int)SEQ_PTR(_5365);
    _16lhs_seq_index = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_16lhs_seq_index))
        _16lhs_seq_index = (long)DBL_PTR(_16lhs_seq_index)->dbl;

    //     lhs_subs = val[a][2..$]
    DeRef(_5365);
    _2 = (int)SEQ_PTR(_16val);
    _5365 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5365);
    _5376 = SEQ_PTR(_5365)->length;
    rhs_slice_target = (object_ptr)&_16lhs_subs;
    RHS_Slice((s1_ptr)_5365, 2, _5376);

    //     val[lhs_seq_index] = assign_slice(val[lhs_seq_index],
    _2 = (int)SEQ_PTR(_16val);
    _5376 = (int)*(((s1_ptr)_2)->base + _16lhs_seq_index);
    Ref(_5376);
    DeRef(_5365);
    _2 = (int)SEQ_PTR(_16val);
    _5365 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5365);
    _2 = (int)SEQ_PTR(_16val);
    _5380 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5380);
    _2 = (int)SEQ_PTR(_16val);
    _5381 = (int)*(((s1_ptr)_2)->base + _16d);
    Ref(_5381);
    Ref(_5376);
    RefDS(_16lhs_subs);
    Ref(_5365);
    Ref(_5380);
    Ref(_5381);
    _0 = _5381;
    _5381 = _16assign_slice(_5376, _16lhs_subs, _5365, _5380, _5381);
    DeRef(_0);
    RefDS(_5381);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16lhs_seq_index);
    _1 = *(int *)_2;
    *(int *)_2 = _5381;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRefDS(_5381);
    DeRef(_5380);
    DeRef(_5365);
    DeRef(_5376);
    return 0;
    ;
}


int _16opRHS_SLICE()
{
    int _x = 0;
    int _5384 = 0;
    int _5394 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]  -- sequence
    _5384 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5384);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]  -- 1st index
    _5384 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5384);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]  -- 2nd index
    _5384 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _5384);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     target = Code[pc+4]  
    _5384 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5384);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     x = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_x);

    //     check_slice(x, val[b], val[c])
    _2 = (int)SEQ_PTR(_16val);
    _5384 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5384);
    _2 = (int)SEQ_PTR(_16val);
    _5394 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5394);
    Ref(_x);
    Ref(_5384);
    Ref(_5394);
    _16check_slice(_x, _5384, _5394);

    //     val[target] = x[val[b]..val[c]]
    DeRef(_5394);
    _2 = (int)SEQ_PTR(_16val);
    _5394 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5394);
    DeRef(_5384);
    _2 = (int)SEQ_PTR(_16val);
    _5384 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_5384);
    rhs_slice_target = (object_ptr)&_5384;
    RHS_Slice((s1_ptr)_x, _5394, _5384);
    RefDS(_5384);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5384;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_x);
    DeRefDS(_5384);
    DeRef(_5394);
    return 0;
    ;
}


int _16opTYPE_CHECK()
{
    int _5399 = 0;
    int _0, _1, _2;
    

    //     if val[Code[pc-1]] = 0 then
    _5399 = _16pc - 1;
    _2 = (int)SEQ_PTR(_4Code);
    _5399 = (int)*(((s1_ptr)_2)->base + _5399);
    Ref(_5399);
    _0 = _5399;
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5399))
        _5399 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5399)->dbl));
    else
        _5399 = (int)*(((s1_ptr)_2)->base + _5399);
    Ref(_5399);
    DeRef(_0);
    if (binary_op_a(NOTEQ, _5399, 0))
        goto L1;

    // 	RTFatalType(pc-2)
    DeRef(_5399);
    _5399 = _16pc - 2;
    if ((long)((unsigned long)_5399 +(unsigned long) HIGH_BITS) >= 0)
        _5399 = NewDouble((double)_5399);
    Ref(_5399);
    _16RTFatalType(_5399);
L1:

    //     pc += 1
    _16pc = _16pc + 1;

    // end procedure
    DeRef(_5399);
    return 0;
    ;
}


int _16opIS_AN_INTEGER()
{
    int _5405 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5405 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5405);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5405 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5405);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = integer(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5405 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5405);
    _0 = _5405;
    if (IS_ATOM_INT(_5405))
        _5405 = 1;
    else if (IS_ATOM_DBL(_5405))
        _5405 = IS_ATOM_INT(DoubleToInt(_5405));
    else
        _5405 = 0;
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5405;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


