// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16opIS_AN_ATOM()
{
    int _5412 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5412 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5412);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5412 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5412);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = atom(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5412 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5412);
    _0 = _5412;
    _5412 = IS_ATOM(_5412);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5412;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


int _16opIS_A_SEQUENCE()
{
    int _5419 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5419 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5419);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5419 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5419);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = sequence(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5419 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5419);
    _0 = _5419;
    _5419 = IS_SEQUENCE(_5419);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5419;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


int _16opIS_AN_OBJECT()
{
    int _5426;
    int _0, _1, _2;
    

    //     target = Code[pc+2]
    _5426 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5426);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = 1
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    return 0;
    ;
}


int _16opSQRT()
{
    int _5429 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5429 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5429);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5429 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5429);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = sqrt(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5429 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5429);
    _0 = _5429;
    if (IS_ATOM_INT(_5429))
        _5429 = e_sqrt(_5429);
    else
        _5429 = unary_op(SQRT, _5429);
    DeRef(_0);
    Ref(_5429);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5429;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5429);
    return 0;
    ;
}


int _16opSIN()
{
    int _5436 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5436 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5436);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5436 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5436);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = sin(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5436 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5436);
    _0 = _5436;
    if (IS_ATOM_INT(_5436))
        _5436 = e_sin(_5436);
    else
        _5436 = unary_op(SIN, _5436);
    DeRef(_0);
    Ref(_5436);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5436;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5436);
    return 0;
    ;
}


int _16opCOS()
{
    int _5443 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5443 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5443);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5443 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5443);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = cos(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5443 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5443);
    _0 = _5443;
    if (IS_ATOM_INT(_5443))
        _5443 = e_cos(_5443);
    else
        _5443 = unary_op(COS, _5443);
    DeRef(_0);
    Ref(_5443);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5443;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5443);
    return 0;
    ;
}


int _16opTAN()
{
    int _5450 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5450 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5450);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5450 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5450);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = tan(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5450 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5450);
    _0 = _5450;
    if (IS_ATOM_INT(_5450))
        _5450 = e_tan(_5450);
    else
        _5450 = unary_op(TAN, _5450);
    DeRef(_0);
    Ref(_5450);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5450;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5450);
    return 0;
    ;
}


int _16opARCTAN()
{
    int _5457 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5457 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5457);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5457 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5457);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = arctan(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5457 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5457);
    _0 = _5457;
    if (IS_ATOM_INT(_5457))
        _5457 = e_arctan(_5457);
    else
        _5457 = unary_op(ARCTAN, _5457);
    DeRef(_0);
    Ref(_5457);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5457;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5457);
    return 0;
    ;
}


int _16opLOG()
{
    int _5464 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5464 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5464);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5464 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5464);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = log(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5464 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5464);
    _0 = _5464;
    if (IS_ATOM_INT(_5464))
        _5464 = e_log(_5464);
    else
        _5464 = unary_op(LOG, _5464);
    DeRef(_0);
    Ref(_5464);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5464;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5464);
    return 0;
    ;
}


int _16opNOT_BITS()
{
    int _5471 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5471 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5471);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5471 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5471);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = not_bits(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5471 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5471);
    _0 = _5471;
    if (IS_ATOM_INT(_5471))
        _5471 = not_bits(_5471);
    else
        _5471 = unary_op(NOT_BITS, _5471);
    DeRef(_0);
    Ref(_5471);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5471;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5471);
    return 0;
    ;
}


int _16opFLOOR()
{
    int _5478 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5478 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5478);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5478 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5478);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = floor(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5478 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5478);
    _0 = _5478;
    if (IS_ATOM_INT(_5478))
        _5478 = e_floor(_5478);
    else
        _5478 = unary_op(FLOOR, _5478);
    DeRef(_0);
    Ref(_5478);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5478;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5478);
    return 0;
    ;
}


int _16opNOT_IFW()
{
    int _5485 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5485 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5485);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if val[a] = 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5485 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5485);
    if (binary_op_a(NOTEQ, _5485, 0))
        goto L1;

    // 	pc += 3
    _16pc = _16pc + 3;
    goto L2;
L1:

    // 	pc = Code[pc+2]
    DeRef(_5485);
    _5485 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5485);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5485);
    return 0;
    ;
}


int _16opNOT()
{
    int _5492 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5492 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5492);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5492 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5492);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = not val[a]
    _2 = (int)SEQ_PTR(_16val);
    _5492 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5492);
    _0 = _5492;
    if (IS_ATOM_INT(_5492)) {
        _5492 = (_5492 == 0);
    }
    else {
        _5492 = unary_op(NOT, _5492);
    }
    DeRef(_0);
    Ref(_5492);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5492;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5492);
    return 0;
    ;
}


int _16opUMINUS()
{
    int _5499 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5499 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5499);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5499 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5499);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = -val[a]
    _2 = (int)SEQ_PTR(_16val);
    _5499 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5499);
    _0 = _5499;
    if (IS_ATOM_INT(_5499)) {
        if (_5499 == 0xC0000000)
            _5499 = (int)NewDouble((double)-0xC0000000);
        else
            _5499 = - _5499;
    }
    else {
        _5499 = unary_op(UMINUS, _5499);
    }
    DeRef(_0);
    Ref(_5499);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5499;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5499);
    return 0;
    ;
}


int _16opRAND()
{
    int _5506 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5506 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5506);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _5506 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5506);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = rand(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _5506 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5506);
    _0 = _5506;
    if (IS_ATOM_INT(_5506)) {
        _5506 = good_rand() % ((unsigned)_5506) + 1;
    }
    else {
        _5506 = unary_op(RAND, _5506);
    }
    DeRef(_0);
    Ref(_5506);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5506;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5506);
    return 0;
    ;
}


int _16opDIV2()
{
    int _5513 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5513 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5513);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+3]
    _5513 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5513);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] / 2
    _2 = (int)SEQ_PTR(_16val);
    _5513 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5513);
    _0 = _5513;
    if (IS_ATOM_INT(_5513)) {
        if (_5513 & 1) {
            _5513 = NewDouble((_5513 >> 1) + 0.5);
        }
        else
            _5513 = _5513 >> 1;
    }
    else {
        _5513 = binary_op(DIVIDE, _5513, 2);
    }
    DeRef(_0);
    Ref(_5513);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5513;
    DeRef(_1);

    //     pc += 4 
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5513);
    return 0;
    ;
}


int _16opFLOOR_DIV2()
{
    int _5520 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5520 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5520);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+3]
    _5520 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5520);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = floor(val[a] / 2)
    _2 = (int)SEQ_PTR(_16val);
    _5520 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5520);
    _0 = _5520;
    if (IS_ATOM_INT(_5520)) {
        _5520 = _5520 >> 1;
    }
    else {
        _1 = binary_op(DIVIDE, _5520, 2);
        _5520 = unary_op(FLOOR, _1);
        DeRef(_1);
    }
    DeRef(_0);
    Ref(_5520);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5520;
    DeRef(_1);

    //     pc += 4 
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5520);
    return 0;
    ;
}


int _16opGREATER_IFW()
{
    int _5532 = 0;
    int _5527 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5527 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5527);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5527 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5527);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] > val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5527 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5527);
    _2 = (int)SEQ_PTR(_16val);
    _5532 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5532);
    if (binary_op_a(LESSEQ, _5527, _5532))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5532);
    _5532 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5532);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5532);
    DeRef(_5527);
    return 0;
    ;
}


int _16opNOTEQ_IFW()
{
    int _5542 = 0;
    int _5537 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5537 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5537);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5537 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5537);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] != val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5537 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5537);
    _2 = (int)SEQ_PTR(_16val);
    _5542 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5542);
    if (binary_op_a(EQUALS, _5537, _5542))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5542);
    _5542 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5542);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5542);
    DeRef(_5537);
    return 0;
    ;
}


int _16opLESSEQ_IFW()
{
    int _5552 = 0;
    int _5547 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5547 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5547);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5547 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5547);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] <= val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5547 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5547);
    _2 = (int)SEQ_PTR(_16val);
    _5552 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5552);
    if (binary_op_a(GREATER, _5547, _5552))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5552);
    _5552 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5552);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5552);
    DeRef(_5547);
    return 0;
    ;
}


int _16opGREATEREQ_IFW()
{
    int _5562 = 0;
    int _5557 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5557 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5557);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5557 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5557);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] >= val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5557 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5557);
    _2 = (int)SEQ_PTR(_16val);
    _5562 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5562);
    if (binary_op_a(LESS, _5557, _5562))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5562);
    _5562 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5562);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5562);
    DeRef(_5557);
    return 0;
    ;
}


int _16opEQUALS_IFW()
{
    int _5572 = 0;
    int _5567 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5567 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5567);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5567 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5567);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] = val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5567 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5567);
    _2 = (int)SEQ_PTR(_16val);
    _5572 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5572);
    if (binary_op_a(NOTEQ, _5567, _5572))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5572);
    _5572 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5572);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5572);
    DeRef(_5567);
    return 0;
    ;
}


int _16opLESS_IFW()
{
    int _5582 = 0;
    int _5577 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5577 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5577);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5577 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5577);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if val[a] < val[b] then
    _2 = (int)SEQ_PTR(_16val);
    _5577 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5577);
    _2 = (int)SEQ_PTR(_16val);
    _5582 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5582);
    if (binary_op_a(GREATEREQ, _5577, _5582))
        goto L1;

    // 	pc += 4
    _16pc = _16pc + 4;
    goto L2;
L1:

    // 	pc = Code[pc+3]
    DeRef(_5582);
    _5582 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5582);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_5582);
    DeRef(_5577);
    return 0;
    ;
}


int _16opMULTIPLY()
{
    int _5594 = 0;
    int _5587 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5587 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5587);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5587 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5587);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5587 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5587);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] * val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5587 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5587);
    _2 = (int)SEQ_PTR(_16val);
    _5594 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5594);
    _0 = _5594;
    if (IS_ATOM_INT(_5587) && IS_ATOM_INT(_5594)) {
        if (_5587 == (short)_5587 && _5594 <= INT15 && _5594 >= -INT15)
            _5594 = _5587 * _5594;
        else
            _5594 = NewDouble(_5587 * (double)_5594);
    }
    else {
        _5594 = binary_op(MULTIPLY, _5587, _5594);
    }
    DeRef(_0);
    Ref(_5594);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5594;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5594);
    DeRef(_5587);
    return 0;
    ;
}


int _16opPLUS()
{
    int _5604 = 0;
    int _5597 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5597 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5597);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5597 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5597);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5597 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5597);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] + val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5597 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5597);
    _2 = (int)SEQ_PTR(_16val);
    _5604 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5604);
    _0 = _5604;
    if (IS_ATOM_INT(_5597) && IS_ATOM_INT(_5604)) {
        _5604 = _5597 + _5604;
        if ((long)((unsigned long)_5604 + (unsigned long)HIGH_BITS) >= 0) 
            _5604 = NewDouble((double)_5604);
    }
    else {
        _5604 = binary_op(PLUS, _5597, _5604);
    }
    DeRef(_0);
    Ref(_5604);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5604;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5604);
    DeRef(_5597);
    return 0;
    ;
}


int _16opMINUS()
{
    int _5614 = 0;
    int _5607 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5607 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5607);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5607 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5607);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5607 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5607);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] - val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5607 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5607);
    _2 = (int)SEQ_PTR(_16val);
    _5614 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5614);
    _0 = _5614;
    if (IS_ATOM_INT(_5607) && IS_ATOM_INT(_5614)) {
        _5614 = _5607 - _5614;
        if ((long)((unsigned long)_5614 +(unsigned long) HIGH_BITS) >= 0)
            _5614 = NewDouble((double)_5614);
    }
    else {
        _5614 = binary_op(MINUS, _5607, _5614);
    }
    DeRef(_0);
    Ref(_5614);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5614;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5614);
    DeRef(_5607);
    return 0;
    ;
}


int _16opOR()
{
    int _5624 = 0;
    int _5617 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5617 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5617);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5617 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5617);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5617 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5617);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] or val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5617 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5617);
    _2 = (int)SEQ_PTR(_16val);
    _5624 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5624);
    _0 = _5624;
    if (IS_ATOM_INT(_5617) && IS_ATOM_INT(_5624)) {
        _5624 = (_5617 != 0 || _5624 != 0);
    }
    else {
        _5624 = binary_op(OR, _5617, _5624);
    }
    DeRef(_0);
    Ref(_5624);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5624;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5624);
    DeRef(_5617);
    return 0;
    ;
}


int _16opXOR()
{
    int _5634 = 0;
    int _5627 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5627 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5627);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5627 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5627);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5627 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5627);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] xor val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5627 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5627);
    _2 = (int)SEQ_PTR(_16val);
    _5634 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5634);
    _0 = _5634;
    if (IS_ATOM_INT(_5627) && IS_ATOM_INT(_5634)) {
        _5634 = ((_5627 != 0) != (_5634 != 0));
    }
    else {
        _5634 = binary_op(XOR, _5627, _5634);
    }
    DeRef(_0);
    Ref(_5634);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5634;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5634);
    DeRef(_5627);
    return 0;
    ;
}


int _16opAND()
{
    int _5644 = 0;
    int _5637 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5637 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5637);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5637 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5637);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5637 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5637);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] and val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5637 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5637);
    _2 = (int)SEQ_PTR(_16val);
    _5644 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5644);
    _0 = _5644;
    if (IS_ATOM_INT(_5637) && IS_ATOM_INT(_5644)) {
        _5644 = (_5637 != 0 && _5644 != 0);
    }
    else {
        _5644 = binary_op(AND, _5637, _5644);
    }
    DeRef(_0);
    Ref(_5644);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5644;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5644);
    DeRef(_5637);
    return 0;
    ;
}


int _16opDIVIDE()
{
    int _5657 = 0;
    int _5647 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5647 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5647);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5647 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5647);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5647 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5647);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_16val);
    _5647 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5647);
    _0 = _5647;
    if (_5647 == 0)
        _5647 = 1;
    else if (IS_ATOM_INT(_5647) && IS_ATOM_INT(0))
        _5647 = 0;
    else
        _5647 = (compare(_5647, 0) == 0);
    DeRef(_0);
    if (_5647 == 0)
        goto L1;

    // 	RTFatal("attempt to divide by 0")
    RefDS(_5655);
    _16RTFatal(_5655);
L1:

    //     val[target] = val[a] / val[b]
    DeRef(_5647);
    _2 = (int)SEQ_PTR(_16val);
    _5647 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5647);
    DeRef(_5657);
    _2 = (int)SEQ_PTR(_16val);
    _5657 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5657);
    _0 = _5657;
    if (IS_ATOM_INT(_5647) && IS_ATOM_INT(_5657)) {
        _5657 = (_5647 % _5657) ? NewDouble((double)_5647 / _5657) : (_5647 / _5657);
    }
    else {
        _5657 = binary_op(DIVIDE, _5647, _5657);
    }
    DeRef(_0);
    Ref(_5657);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5657;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5657);
    DeRef(_5647);
    return 0;
    ;
}


int _16opREMAINDER()
{
    int _5670 = 0;
    int _5660 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5660 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5660);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5660 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5660);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5660 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5660);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_16val);
    _5660 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5660);
    _0 = _5660;
    if (_5660 == 0)
        _5660 = 1;
    else if (IS_ATOM_INT(_5660) && IS_ATOM_INT(0))
        _5660 = 0;
    else
        _5660 = (compare(_5660, 0) == 0);
    DeRef(_0);
    if (_5660 == 0)
        goto L1;

    // 	RTFatal("Can't get remainder of a number divided by 0")
    RefDS(_5668);
    _16RTFatal(_5668);
L1:

    //     val[target] = remainder(val[a], val[b])
    DeRef(_5660);
    _2 = (int)SEQ_PTR(_16val);
    _5660 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5660);
    DeRef(_5670);
    _2 = (int)SEQ_PTR(_16val);
    _5670 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5670);
    _0 = _5670;
    if (IS_ATOM_INT(_5660) && IS_ATOM_INT(_5670)) {
        _5670 = (_5660 % _5670);
    }
    else {
        _5670 = binary_op(REMAINDER, _5660, _5670);
    }
    DeRef(_0);
    Ref(_5670);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5670;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5670);
    DeRef(_5660);
    return 0;
    ;
}


int _16opFLOOR_DIV()
{
    int _5682 = 0;
    int _5673 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5673 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5673);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5673 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5673);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5673 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5673);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if equal(val[b], 0) then
    _2 = (int)SEQ_PTR(_16val);
    _5673 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5673);
    _0 = _5673;
    if (_5673 == 0)
        _5673 = 1;
    else if (IS_ATOM_INT(_5673) && IS_ATOM_INT(0))
        _5673 = 0;
    else
        _5673 = (compare(_5673, 0) == 0);
    DeRef(_0);
    if (_5673 == 0)
        goto L1;

    // 	RTFatal("attempt to divide by 0")
    RefDS(_5655);
    _16RTFatal(_5655);
L1:

    //     val[target] = floor(val[a] / val[b])
    DeRef(_5673);
    _2 = (int)SEQ_PTR(_16val);
    _5673 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5673);
    DeRef(_5682);
    _2 = (int)SEQ_PTR(_16val);
    _5682 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5682);
    _0 = _5682;
    if (IS_ATOM_INT(_5673) && IS_ATOM_INT(_5682)) {
        if (_5682 > 0 && _5673 >= 0) {
            _5682 = _5673 / _5682;
        }
        else {
            temp_dbl = floor((double)_5673 / (double)_5682);
            if (_5673 != MININT)
                _5682 = (long)temp_dbl;
            else
                _5682 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _5673, _5682);
        _5682 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);
    Ref(_5682);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5682;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5682);
    DeRef(_5673);
    return 0;
    ;
}


int _16opAND_BITS()
{
    int _5692 = 0;
    int _5685 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5685 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5685);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5685 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5685);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5685 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5685);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = and_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5685 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5685);
    _2 = (int)SEQ_PTR(_16val);
    _5692 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5692);
    _0 = _5692;
    if (IS_ATOM_INT(_5685) && IS_ATOM_INT(_5692)) {
        _5692 = (_5685 & _5692);
    }
    else {
        _5692 = binary_op(AND_BITS, _5685, _5692);
    }
    DeRef(_0);
    Ref(_5692);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5692;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5692);
    DeRef(_5685);
    return 0;
    ;
}


int _16opOR_BITS()
{
    int _5702 = 0;
    int _5695 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5695 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5695);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5695 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5695);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5695 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5695);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = or_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5695 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5695);
    _2 = (int)SEQ_PTR(_16val);
    _5702 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5702);
    _0 = _5702;
    if (IS_ATOM_INT(_5695) && IS_ATOM_INT(_5702)) {
        _5702 = (_5695 | _5702);
    }
    else {
        _5702 = binary_op(OR_BITS, _5695, _5702);
    }
    DeRef(_0);
    Ref(_5702);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5702;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5702);
    DeRef(_5695);
    return 0;
    ;
}


int _16opXOR_BITS()
{
    int _5712 = 0;
    int _5705 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5705 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5705);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5705 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5705);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5705 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5705);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = xor_bits(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5705 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5705);
    _2 = (int)SEQ_PTR(_16val);
    _5712 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5712);
    _0 = _5712;
    if (IS_ATOM_INT(_5705) && IS_ATOM_INT(_5712)) {
        _5712 = (_5705 ^ _5712);
    }
    else {
        _5712 = binary_op(XOR_BITS, _5705, _5712);
    }
    DeRef(_0);
    Ref(_5712);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5712;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5712);
    DeRef(_5705);
    return 0;
    ;
}


int _16opPOWER()
{
    int _5722 = 0;
    int _5715 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5715 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5715);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5715 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5715);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5715 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5715);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = power(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _5715 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5715);
    _2 = (int)SEQ_PTR(_16val);
    _5722 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5722);
    _0 = _5722;
    if (IS_ATOM_INT(_5715) && IS_ATOM_INT(_5722)) {
        _5722 = power(_5715, _5722);
    }
    else {
        _5722 = binary_op(POWER, _5715, _5722);
    }
    DeRef(_0);
    Ref(_5722);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5722;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5722);
    DeRef(_5715);
    return 0;
    ;
}


int _16opLESS()
{
    int _5732 = 0;
    int _5725 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5725 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5725);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5725 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5725);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5725 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5725);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] < val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5725 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5725);
    _2 = (int)SEQ_PTR(_16val);
    _5732 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5732);
    _0 = _5732;
    if (IS_ATOM_INT(_5725) && IS_ATOM_INT(_5732)) {
        _5732 = (_5725 < _5732);
    }
    else {
        _5732 = binary_op(LESS, _5725, _5732);
    }
    DeRef(_0);
    Ref(_5732);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5732;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5732);
    DeRef(_5725);
    return 0;
    ;
}


int _16opGREATER()
{
    int _5742 = 0;
    int _5735 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5735 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5735);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5735 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5735);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5735 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5735);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] > val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5735 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5735);
    _2 = (int)SEQ_PTR(_16val);
    _5742 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5742);
    _0 = _5742;
    if (IS_ATOM_INT(_5735) && IS_ATOM_INT(_5742)) {
        _5742 = (_5735 > _5742);
    }
    else {
        _5742 = binary_op(GREATER, _5735, _5742);
    }
    DeRef(_0);
    Ref(_5742);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5742;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5742);
    DeRef(_5735);
    return 0;
    ;
}


int _16opEQUALS()
{
    int _5752 = 0;
    int _5745 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5745 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5745);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5745 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5745);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5745 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5745);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] = val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5745 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5745);
    _2 = (int)SEQ_PTR(_16val);
    _5752 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5752);
    _0 = _5752;
    if (IS_ATOM_INT(_5745) && IS_ATOM_INT(_5752)) {
        _5752 = (_5745 == _5752);
    }
    else {
        _5752 = binary_op(EQUALS, _5745, _5752);
    }
    DeRef(_0);
    Ref(_5752);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5752;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5752);
    DeRef(_5745);
    return 0;
    ;
}


int _16opNOTEQ()
{
    int _5762 = 0;
    int _5755 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5755 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5755);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5755 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5755);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5755 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5755);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] != val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5755 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5755);
    _2 = (int)SEQ_PTR(_16val);
    _5762 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5762);
    _0 = _5762;
    if (IS_ATOM_INT(_5755) && IS_ATOM_INT(_5762)) {
        _5762 = (_5755 != _5762);
    }
    else {
        _5762 = binary_op(NOTEQ, _5755, _5762);
    }
    DeRef(_0);
    Ref(_5762);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5762;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5762);
    DeRef(_5755);
    return 0;
    ;
}


int _16opLESSEQ()
{
    int _5772 = 0;
    int _5765 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5765 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5765);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5765 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5765);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5765 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5765);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] <= val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5765 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5765);
    _2 = (int)SEQ_PTR(_16val);
    _5772 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5772);
    _0 = _5772;
    if (IS_ATOM_INT(_5765) && IS_ATOM_INT(_5772)) {
        _5772 = (_5765 <= _5772);
    }
    else {
        _5772 = binary_op(LESSEQ, _5765, _5772);
    }
    DeRef(_0);
    Ref(_5772);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5772;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5772);
    DeRef(_5765);
    return 0;
    ;
}


int _16opGREATEREQ()
{
    int _5782 = 0;
    int _5775 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5775 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5775);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5775 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5775);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _5775 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _5775);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = val[a] >= val[b]
    _2 = (int)SEQ_PTR(_16val);
    _5775 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5775);
    _2 = (int)SEQ_PTR(_16val);
    _5782 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_5782);
    _0 = _5782;
    if (IS_ATOM_INT(_5775) && IS_ATOM_INT(_5782)) {
        _5782 = (_5775 >= _5782);
    }
    else {
        _5782 = binary_op(GREATEREQ, _5775, _5782);
    }
    DeRef(_0);
    Ref(_5782);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _5782;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5782);
    DeRef(_5775);
    return 0;
    ;
}


int _16opSC1_AND()
{
    int _5785 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5785 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5785);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5785 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5785);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5785 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5785);
    _0 = _5785;
    _5785 = IS_ATOM(_5785);
    DeRef(_0);
    if (_5785 == 0)
        goto L1;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5785 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5785);
    if (binary_op_a(NOTEQ, _5785, 0))
        goto L2;

    // 	    val[b] = 0
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16b);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_5785);
    _5785 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5785);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_5795);
    _16RTFatal(_5795);
L2:

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5785);
    return 0;
    ;
}


int _16opSC1_AND_IF()
{
    int _5797 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5797 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5797);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5797 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5797);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5797 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5797);
    _0 = _5797;
    _5797 = IS_ATOM(_5797);
    DeRef(_0);
    if (_5797 == 0)
        goto L1;

    // 	if val[a] = 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5797 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5797);
    if (binary_op_a(NOTEQ, _5797, 0))
        goto L2;

    // 	    pc = Code[pc+3]
    DeRef(_5797);
    _5797 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5797);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_5795);
    _16RTFatal(_5795);
L2:

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5797);
    return 0;
    ;
}


int _16opSC1_OR()
{
    int _5808 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5808 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5808);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5808 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5808);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5808 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5808);
    _0 = _5808;
    _5808 = IS_ATOM(_5808);
    DeRef(_0);
    if (_5808 == 0)
        goto L1;

    // 	if val[a] != 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5808 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5808);
    if (binary_op_a(EQUALS, _5808, 0))
        goto L2;

    // 	    val[b] = 1
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16b);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_5808);
    _5808 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5808);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_5795);
    _16RTFatal(_5795);
L2:

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5808);
    return 0;
    ;
}


int _16opSC1_OR_IF()
{
    int _5819 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5819 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5819);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5819 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5819);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5819 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5819);
    _0 = _5819;
    _5819 = IS_ATOM(_5819);
    DeRef(_0);
    if (_5819 == 0)
        goto L1;

    // 	if val[a] != 0 then
    _2 = (int)SEQ_PTR(_16val);
    _5819 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5819);
    if (binary_op_a(EQUALS, _5819, 0))
        goto L2;

    // 	    val[b] = 1
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16b);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    // 	    pc = Code[pc+3]
    DeRef(_5819);
    _5819 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5819);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    // 	    return
    return 0;
L3:
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_5795);
    _16RTFatal(_5795);
L2:

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_5819);
    return 0;
    ;
}


int _16opSC2_OR()
{
    int _5830 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _5830 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _5830);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _5830 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _5830);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _5830 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5830);
    _0 = _5830;
    _5830 = IS_ATOM(_5830);
    DeRef(_0);
    if (_5830 == 0)
        goto L1;

    // 	val[b] = val[a] 
    _2 = (int)SEQ_PTR(_16val);
    _5830 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_5830);
    Ref(_5830);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16b);
    _1 = *(int *)_2;
    *(int *)_2 = _5830;
    DeRef(_1);
    goto L2;
L1:

    // 	RTFatal("true/false condition must be an ATOM")
    RefDS(_5795);
    _16RTFatal(_5795);
L2:

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_5830);
    return 0;
    ;
}


int _16opFOR()
{
    int _increment;
    int _limit;
    int _initial;
    int _loopvar;
    int _jump;
    int _5838 = 0;
    int _5861 = 0;
    int _0, _1, _2;
    

    //     increment = Code[pc+1]
    _5838 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _increment = (int)*(((s1_ptr)_2)->base + _5838);
    if (!IS_ATOM_INT(_increment))
        _increment = (long)DBL_PTR(_increment)->dbl;

    //     limit = Code[pc+2]
    _5838 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _limit = (int)*(((s1_ptr)_2)->base + _5838);
    if (!IS_ATOM_INT(_limit))
        _limit = (long)DBL_PTR(_limit)->dbl;

    //     initial = Code[pc+3]
    _5838 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _initial = (int)*(((s1_ptr)_2)->base + _5838);
    if (!IS_ATOM_INT(_initial))
        _initial = (long)DBL_PTR(_initial)->dbl;

    //     loopvar = Code[pc+5]
    _5838 = _16pc + 5;
    _2 = (int)SEQ_PTR(_4Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _5838);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    //     jump = Code[pc+6]
    _5838 = _16pc + 6;
    _2 = (int)SEQ_PTR(_4Code);
    _jump = (int)*(((s1_ptr)_2)->base + _5838);
    if (!IS_ATOM_INT(_jump))
        _jump = (long)DBL_PTR(_jump)->dbl;

    //     if sequence(val[initial]) then
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_5838);
    _0 = _5838;
    _5838 = IS_SEQUENCE(_5838);
    DeRef(_0);
    if (_5838 == 0)
        goto L1;

    // 	RTFatal("for-loop variable is not an atom")
    RefDS(_5850);
    _16RTFatal(_5850);
L1:

    //     if sequence(val[limit]) then
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_5838);
    _0 = _5838;
    _5838 = IS_SEQUENCE(_5838);
    DeRef(_0);
    if (_5838 == 0)
        goto L2;

    // 	RTFatal("for-loop limit is not an atom")
    RefDS(_5853);
    _16RTFatal(_5853);
L2:

    //     if sequence(val[increment]) then
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _increment);
    Ref(_5838);
    _0 = _5838;
    _5838 = IS_SEQUENCE(_5838);
    DeRef(_0);
    if (_5838 == 0)
        goto L3;

    // 	RTFatal("for-loop increment is not an atom")
    RefDS(_5856);
    _16RTFatal(_5856);
L3:

    //     pc += 7 -- to enter into the loop
    _16pc = _16pc + 7;

    //     if val[increment] >= 0 then
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _increment);
    Ref(_5838);
    if (binary_op_a(LESS, _5838, 0))
        goto L4;

    // 	if val[initial] > val[limit] then
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_5838);
    DeRef(_5861);
    _2 = (int)SEQ_PTR(_16val);
    _5861 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_5861);
    if (binary_op_a(LESSEQ, _5838, _5861))
        goto L5;

    // 	    pc = jump -- quit immediately, 0 iterations
    _16pc = _jump;
L6:
    goto L5;
L4:

    // 	if val[initial] < val[limit] then
    DeRef(_5861);
    _2 = (int)SEQ_PTR(_16val);
    _5861 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_5861);
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _limit);
    Ref(_5838);
    if (binary_op_a(GREATEREQ, _5861, _5838))
        goto L7;

    // 	    pc = jump -- quit immediately, 0 iterations
    _16pc = _jump;
L7:
L5:

    //     val[loopvar] = val[initial] -- initialize loop var
    DeRef(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _5838 = (int)*(((s1_ptr)_2)->base + _initial);
    Ref(_5838);
    Ref(_5838);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _5838;
    DeRef(_1);

    // end procedure
    DeRef(_5838);
    DeRef(_5861);
    return 0;
    ;
}


int _16opENDFOR_GENERAL()
{
    int _loopvar;
    int _increment = 0;
    int _limit = 0;
    int _next = 0;
    int _5867 = 0;
    int _0, _1, _2;
    

    //     limit = val[Code[pc+2]]
    _5867 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5867 = (int)*(((s1_ptr)_2)->base + _5867);
    Ref(_5867);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5867))
        _limit = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5867)->dbl));
    else
        _limit = (int)*(((s1_ptr)_2)->base + _5867);
    Ref(_limit);

    //     increment = val[Code[pc+4]]
    DeRef(_5867);
    _5867 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _5867 = (int)*(((s1_ptr)_2)->base + _5867);
    Ref(_5867);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5867))
        _increment = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5867)->dbl));
    else
        _increment = (int)*(((s1_ptr)_2)->base + _5867);
    Ref(_increment);

    //     loopvar = Code[pc+3]
    DeRef(_5867);
    _5867 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _5867);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    //     next = val[loopvar] + increment
    _2 = (int)SEQ_PTR(_16val);
    _5867 = (int)*(((s1_ptr)_2)->base + _loopvar);
    Ref(_5867);
    if (IS_ATOM_INT(_5867) && IS_ATOM_INT(_increment)) {
        _next = _5867 + _increment;
        if ((long)((unsigned long)_next + (unsigned long)HIGH_BITS) >= 0) 
            _next = NewDouble((double)_next);
    }
    else {
        _next = binary_op(PLUS, _5867, _increment);
    }

    //     if increment >= 0 then
    if (binary_op_a(LESS, _increment, 0))
        goto L1;

    // 	if next > limit then
    if (binary_op_a(LESSEQ, _next, _limit))
        goto L2;

    // 	    pc += 5 -- exit loop
    _16pc = _16pc + 5;
    goto L3;
L2:

    // 	    val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	    pc = Code[pc+1] -- loop again
    DeRef(_5867);
    _5867 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5867);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L4:
    goto L3;
L1:

    // 	if next < limit then
    if (binary_op_a(GREATEREQ, _next, _limit))
        goto L5;

    // 	    pc += 5 -- exit loop
    _16pc = _16pc + 5;
    goto L6;
L5:

    // 	    val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	    pc = Code[pc+1] -- loop again
    DeRef(_5867);
    _5867 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5867);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L6:
L3:

    // end procedure
    DeRef(_increment);
    DeRef(_limit);
    DeRef(_next);
    DeRef(_5867);
    return 0;
    ;
}


int _16opENDFOR_INT_UP1()
{
    int _loopvar;
    int _limit = 0;
    int _next = 0;
    int _5886 = 0;
    int _0, _1, _2;
    

    //     limit = val[Code[pc+2]]
    _5886 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _5886 = (int)*(((s1_ptr)_2)->base + _5886);
    Ref(_5886);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_5886))
        _limit = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_5886)->dbl));
    else
        _limit = (int)*(((s1_ptr)_2)->base + _5886);
    Ref(_limit);

    //     loopvar = Code[pc+3]
    DeRef(_5886);
    _5886 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _loopvar = (int)*(((s1_ptr)_2)->base + _5886);
    if (!IS_ATOM_INT(_loopvar))
        _loopvar = (long)DBL_PTR(_loopvar)->dbl;

    //     next = val[loopvar] + 1
    _2 = (int)SEQ_PTR(_16val);
    _5886 = (int)*(((s1_ptr)_2)->base + _loopvar);
    Ref(_5886);
    if (IS_ATOM_INT(_5886)) {
        _next = _5886 + 1;
        if (_next > MAXINT)
            _next = NewDouble((double)_next);
    }
    else
        _next = binary_op(PLUS, 1, _5886);

    //     if next > limit then
    if (binary_op_a(LESSEQ, _next, _limit))
        goto L1;

    // 	pc += 5 -- exit loop
    _16pc = _16pc + 5;
    goto L2;
L1:

    // 	val[loopvar] = next
    Ref(_next);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _loopvar);
    _1 = *(int *)_2;
    *(int *)_2 = _next;
    DeRef(_1);

    // 	pc = Code[pc+1] -- loop again
    DeRef(_5886);
    _5886 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16pc = (int)*(((s1_ptr)_2)->base + _5886);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;
L2:

    // end procedure
    DeRef(_limit);
    DeRef(_next);
    DeRef(_5886);
    return 0;
    ;
}


int _16RTLookup(int _name, int _file, int _proc, int _stlen)
{
    int _s;
    int _global_found;
    int _ns = 0;
    int _colon;
    int _ns_file;
    int _5897 = 0;
    int _6009 = 0;
    int _5901 = 0;
    int _5909 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_file)) {
        _1 = (long)(DBL_PTR(_file)->dbl);
        DeRefDS(_file);
        _file = _1;
    }
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }
    if (!IS_ATOM_INT(_stlen)) {
        _1 = (long)(DBL_PTR(_stlen)->dbl);
        DeRefDS(_stlen);
        _stlen = _1;
    }

    //     colon = find(':', name)
    _colon = find(58, _name);

    //     if colon then
    if (_colon == 0)
        goto L1;

    // 	ns = name[1..colon-1]
    _5897 = _colon - 1;
    rhs_slice_target = (object_ptr)&_ns;
    RHS_Slice((s1_ptr)_name, 1, _5897);

    // 	name = name[colon+1..$]
    _5897 = _colon + 1;
    _5901 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, _5897, _5901);

    // 	while length(ns) and (ns[$] = ' ' or ns[$] = '\t') do
L2:
    DeRef(_5901);
    _5901 = SEQ_PTR(_ns)->length;
    if (_5901 == 0) {
        goto L3;
    }
    DeRef(_5897);
    _5897 = SEQ_PTR(_ns)->length;
    _2 = (int)SEQ_PTR(_ns);
    _5897 = (int)*(((s1_ptr)_2)->base + _5897);
    Ref(_5897);
    _0 = _5897;
    if (IS_ATOM_INT(_5897)) {
        _5897 = (_5897 == 32);
    }
    else {
        _5897 = binary_op(EQUALS, _5897, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5897)) {
        if (_5897 != 0) {
            DeRef(_5897);
            _5897 = 1;
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_5897)->dbl != 0.0) {
            DeRef(_5897);
            _5897 = 1;
            goto L4;
        }
    }
    DeRef(_5909);
    _5909 = SEQ_PTR(_ns)->length;
    _2 = (int)SEQ_PTR(_ns);
    _5909 = (int)*(((s1_ptr)_2)->base + _5909);
    Ref(_5909);
    _0 = _5909;
    if (IS_ATOM_INT(_5909)) {
        _5909 = (_5909 == 9);
    }
    else {
        _5909 = binary_op(EQUALS, _5909, 9);
    }
    DeRef(_0);
    DeRef(_5897);
    if (IS_ATOM_INT(_5909))
        _5897 = (_5909 != 0);
    else
        _5897 = DBL_PTR(_5909)->dbl != 0.0;
L4:
L5:
    if (_5897 == 0)
        goto L3;

    // 	    ns = ns[1..$-1]
    DeRef(_5909);
    _5909 = SEQ_PTR(_ns)->length;
    _5909 = _5909 - 1;
    rhs_slice_target = (object_ptr)&_ns;
    RHS_Slice((s1_ptr)_ns, 1, _5909);

    // 	end while
    goto L2;
L3:

    // 	while length(ns) and (ns[1] = ' ' or ns[1] = '\t') do
L6:
    DeRef(_5909);
    _5909 = SEQ_PTR(_ns)->length;
    if (_5909 == 0) {
        goto L7;
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_ns);
    _5897 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5897);
    _0 = _5897;
    if (IS_ATOM_INT(_5897)) {
        _5897 = (_5897 == 32);
    }
    else {
        _5897 = binary_op(EQUALS, _5897, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5897)) {
        if (_5897 != 0) {
            DeRef(_5897);
            _5897 = 1;
            goto L8;
        }
    }
    else {
        if (DBL_PTR(_5897)->dbl != 0.0) {
            DeRef(_5897);
            _5897 = 1;
            goto L8;
        }
    }
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_ns);
    _5901 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5901);
    _0 = _5901;
    if (IS_ATOM_INT(_5901)) {
        _5901 = (_5901 == 9);
    }
    else {
        _5901 = binary_op(EQUALS, _5901, 9);
    }
    DeRef(_0);
    DeRef(_5897);
    if (IS_ATOM_INT(_5901))
        _5897 = (_5901 != 0);
    else
        _5897 = DBL_PTR(_5901)->dbl != 0.0;
L8:
L9:
    if (_5897 == 0)
        goto L7;

    // 	    ns = ns[2..$]
    DeRef(_5901);
    _5901 = SEQ_PTR(_ns)->length;
    rhs_slice_target = (object_ptr)&_ns;
    RHS_Slice((s1_ptr)_ns, 2, _5901);

    // 	end while
    goto L6;
L7:

    // 	if length(ns) = 0 then
    DeRef(_5901);
    _5901 = SEQ_PTR(_ns)->length;
    if (_5901 != 0)
        goto LA;

    // 	    return 0 -- bad syntax
    DeRefDS(_name);
    DeRefDS(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5909);
    return 0;
LA:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5901);
    _2 = (int)SEQ_PTR(_5901);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != 0 and s <= stlen do
LB:
    DeRef(_5901);
    _5901 = (_s != 0);
    if (_5901 == 0) {
        goto LC;
    }
    DeRef(_5897);
    _5897 = (_s <= _stlen);
LD:
    if (_5897 == 0)
        goto LC;

    // 	    if file = SymTab[s][S_FILE_NO] and 
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (IS_ATOM_INT(_5897)) {
        _5897 = (_file == _5897);
    }
    else {
        _5897 = binary_op(EQUALS, _file, _5897);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5897)) {
        if (_5897 == 0) {
            DeRef(_5897);
            _5897 = 0;
            goto LE;
        }
    }
    else {
        if (DBL_PTR(_5897)->dbl == 0.0) {
            DeRef(_5897);
            _5897 = 0;
            goto LE;
        }
    }
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5901);
    _0 = _5901;
    _2 = (int)SEQ_PTR(_5901);
    _5901 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_5901);
    DeRefDS(_0);
    _0 = _5901;
    if (IS_ATOM_INT(_5901)) {
        _5901 = (_5901 == 523);
    }
    else {
        _5901 = binary_op(EQUALS, _5901, 523);
    }
    DeRef(_0);
    DeRef(_5897);
    if (IS_ATOM_INT(_5901))
        _5897 = (_5901 != 0);
    else
        _5897 = DBL_PTR(_5901)->dbl != 0.0;
LE:
    if (_5897 == 0) {
        goto LF;
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (_ns == _5897)
        _5897 = 1;
    else if (IS_ATOM_INT(_ns) && IS_ATOM_INT(_5897))
        _5897 = 0;
    else
        _5897 = (compare(_ns, _5897) == 0);
    DeRef(_0);
L10:
    if (_5897 == 0)
        goto LF;

    // 		exit
    goto LC;
LF:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto LB;
LC:

    // 	if s = 0 then
    if (_s != 0)
        goto L11;

    // 	    return 0 -- couldn't find ns
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return 0;
L11:

    // 	ns_file = SymTab[s][S_OBJ]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _ns_file = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_ns_file))
        _ns_file = (long)DBL_PTR(_ns_file)->dbl;

    // 	while length(name) and (name[1] = ' ' or name[1] = '\t') do
L12:
    DeRef(_5897);
    _5897 = SEQ_PTR(_name)->length;
    if (_5897 == 0) {
        goto L13;
    }
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_name);
    _5901 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5901);
    _0 = _5901;
    if (IS_ATOM_INT(_5901)) {
        _5901 = (_5901 == 32);
    }
    else {
        _5901 = binary_op(EQUALS, _5901, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5901)) {
        if (_5901 != 0) {
            DeRef(_5901);
            _5901 = 1;
            goto L14;
        }
    }
    else {
        if (DBL_PTR(_5901)->dbl != 0.0) {
            DeRef(_5901);
            _5901 = 1;
            goto L14;
        }
    }
    DeRef(_5909);
    _2 = (int)SEQ_PTR(_name);
    _5909 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_5909);
    _0 = _5909;
    if (IS_ATOM_INT(_5909)) {
        _5909 = (_5909 == 9);
    }
    else {
        _5909 = binary_op(EQUALS, _5909, 9);
    }
    DeRef(_0);
    DeRef(_5901);
    if (IS_ATOM_INT(_5909))
        _5901 = (_5909 != 0);
    else
        _5901 = DBL_PTR(_5909)->dbl != 0.0;
L14:
L15:
    if (_5901 == 0)
        goto L13;

    // 	    name = name[2..$]
    DeRef(_5909);
    _5909 = SEQ_PTR(_name)->length;
    rhs_slice_target = (object_ptr)&_name;
    RHS_Slice((s1_ptr)_name, 2, _5909);

    // 	end while
    goto L12;
L13:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_5909);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5909 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5909);
    _2 = (int)SEQ_PTR(_5909);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != 0 and s <= stlen do
L16:
    DeRef(_5909);
    _5909 = (_s != 0);
    if (_5909 == 0) {
        goto L17;
    }
    DeRef(_5901);
    _5901 = (_s <= _stlen);
L18:
    if (_5901 == 0)
        goto L17;

    // 	    if SymTab[s][S_FILE_NO] = ns_file and 
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5901);
    _0 = _5901;
    _2 = (int)SEQ_PTR(_5901);
    _5901 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_5901);
    DeRefDS(_0);
    _0 = _5901;
    if (IS_ATOM_INT(_5901)) {
        _5901 = (_5901 == _ns_file);
    }
    else {
        _5901 = binary_op(EQUALS, _5901, _ns_file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5901)) {
        if (_5901 == 0) {
            DeRef(_5901);
            _5901 = 0;
            goto L19;
        }
    }
    else {
        if (DBL_PTR(_5901)->dbl == 0.0) {
            DeRef(_5901);
            _5901 = 0;
            goto L19;
        }
    }
    DeRef(_5909);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5909 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5909);
    _0 = _5909;
    _2 = (int)SEQ_PTR(_5909);
    _5909 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5909);
    DeRefDS(_0);
    _0 = _5909;
    if (IS_ATOM_INT(_5909)) {
        _5909 = (_5909 == 6);
    }
    else {
        _5909 = binary_op(EQUALS, _5909, 6);
    }
    DeRef(_0);
    DeRef(_5901);
    if (IS_ATOM_INT(_5909))
        _5901 = (_5909 != 0);
    else
        _5901 = DBL_PTR(_5909)->dbl != 0.0;
L19:
    if (_5901 == 0) {
        goto L1A;
    }
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5901);
    _0 = _5901;
    _2 = (int)SEQ_PTR(_5901);
    _5901 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5901);
    DeRefDS(_0);
    _0 = _5901;
    if (_name == _5901)
        _5901 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5901))
        _5901 = 0;
    else
        _5901 = (compare(_name, _5901) == 0);
    DeRef(_0);
L1B:
    if (_5901 == 0)
        goto L1A;

    // 		return s
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return _s;
L1A:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5901);
    _2 = (int)SEQ_PTR(_5901);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while
    goto L16;
L17:

    // 	return 0 -- couldn't find name in ns file
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return 0;
    goto L1C;
L1:

    // 	if proc != TopLevelSub then  
    if (_proc == _4TopLevelSub)
        goto L1D;

    // 	    s = SymTab[proc][S_NEXT]
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _proc);
    RefDS(_5901);
    _2 = (int)SEQ_PTR(_5901);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    while s and (SymTab[s][S_SCOPE] = SC_PRIVATE or 
L1E:
    if (_s == 0) {
        goto L1F;
    }
    DeRef(_5909);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5909 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5909);
    _0 = _5909;
    _2 = (int)SEQ_PTR(_5909);
    _5909 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5909);
    DeRefDS(_0);
    _0 = _5909;
    if (IS_ATOM_INT(_5909)) {
        _5909 = (_5909 == 3);
    }
    else {
        _5909 = binary_op(EQUALS, _5909, 3);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5909)) {
        if (_5909 != 0) {
            DeRef(_5909);
            _5909 = 1;
            goto L20;
        }
    }
    else {
        if (DBL_PTR(_5909)->dbl != 0.0) {
            DeRef(_5909);
            _5909 = 1;
            goto L20;
        }
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (IS_ATOM_INT(_5897)) {
        _5897 = (_5897 == 2);
    }
    else {
        _5897 = binary_op(EQUALS, _5897, 2);
    }
    DeRef(_0);
    DeRef(_5909);
    if (IS_ATOM_INT(_5897))
        _5909 = (_5897 != 0);
    else
        _5909 = DBL_PTR(_5897)->dbl != 0.0;
L20:
L21:
    if (_5909 == 0)
        goto L1F;

    // 		if equal(name, SymTab[s][S_NAME]) then
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (_name == _5897)
        _5897 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5897))
        _5897 = 0;
    else
        _5897 = (compare(_name, _5897) == 0);
    DeRef(_0);
    if (_5897 == 0)
        goto L22;

    // 		    return s           
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return _s;
L22:

    // 		s = SymTab[s][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	    end while
    goto L1E;
L1F:
L1D:

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != 0 and s <= stlen do
L23:
    DeRef(_5897);
    _5897 = (_s != 0);
    if (_5897 == 0) {
        goto L24;
    }
    DeRef(_5909);
    _5909 = (_s <= _stlen);
L25:
    if (_5909 == 0)
        goto L24;

    // 	    if SymTab[s][S_FILE_NO] = file and 
    DeRef(_5909);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5909 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5909);
    _0 = _5909;
    _2 = (int)SEQ_PTR(_5909);
    _5909 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_5909);
    DeRefDS(_0);
    _0 = _5909;
    if (IS_ATOM_INT(_5909)) {
        _5909 = (_5909 == _file);
    }
    else {
        _5909 = binary_op(EQUALS, _5909, _file);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5909)) {
        if (_5909 == 0) {
            DeRef(_5909);
            _5909 = 0;
            goto L26;
        }
    }
    else {
        if (DBL_PTR(_5909)->dbl == 0.0) {
            DeRef(_5909);
            _5909 = 0;
            goto L26;
        }
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (IS_ATOM_INT(_5897)) {
        _5897 = (_5897 == 5);
    }
    else {
        _5897 = binary_op(EQUALS, _5897, 5);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_5897)) {
        if (_5897 != 0) {
            DeRef(_5897);
            _5897 = 1;
            goto L27;
        }
    }
    else {
        if (DBL_PTR(_5897)->dbl != 0.0) {
            DeRef(_5897);
            _5897 = 1;
            goto L27;
        }
    }
    DeRef(_5901);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5901 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5901);
    _0 = _5901;
    _2 = (int)SEQ_PTR(_5901);
    _5901 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_5901);
    DeRefDS(_0);
    _0 = _5901;
    if (IS_ATOM_INT(_5901)) {
        _5901 = (_5901 == 6);
    }
    else {
        _5901 = binary_op(EQUALS, _5901, 6);
    }
    DeRef(_0);
    DeRef(_5897);
    if (IS_ATOM_INT(_5901))
        _5897 = (_5901 != 0);
    else
        _5897 = DBL_PTR(_5901)->dbl != 0.0;
L27:
    if (_5897 != 0) {
        DeRef(_5901);
        _5901 = 1;
        goto L28;
    }
    DeRef(_5897);
    _5897 = (_proc == _4TopLevelSub);
    if (_5897 == 0) {
        _5897 = 0;
        goto L29;
    }
    DeRef(_6009);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6009 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_6009);
    _0 = _6009;
    _2 = (int)SEQ_PTR(_6009);
    _6009 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6009);
    DeRefDS(_0);
    _0 = _6009;
    if (IS_ATOM_INT(_6009)) {
        _6009 = (_6009 == 4);
    }
    else {
        _6009 = binary_op(EQUALS, _6009, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6009))
        _5897 = (_6009 != 0);
    else
        _5897 = DBL_PTR(_6009)->dbl != 0.0;
L29:
    DeRef(_5901);
    _5901 = (_5897 != 0);
L28:
    DeRef(_5909);
    _5909 = (_5901 != 0);
L26:
    if (_5909 == 0) {
        goto L2A;
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (_name == _5897)
        _5897 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5897))
        _5897 = 0;
    else
        _5897 = (compare(_name, _5897) == 0);
    DeRef(_0);
L2B:
    if (_5897 == 0)
        goto L2A;

    // 		return s
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return _s;
L2A:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L23;
L24:

    // 	global_found = FALSE
    _global_found = 0;

    // 	s = SymTab[TopLevelSub][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _4TopLevelSub);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	while s != 0 and s <= stlen do
L2C:
    DeRef(_5897);
    _5897 = (_s != 0);
    if (_5897 == 0) {
        goto L2D;
    }
    DeRef(_6009);
    _6009 = (_s <= _stlen);
L2E:
    if (_6009 == 0)
        goto L2D;

    // 	    if SymTab[s][S_SCOPE] = SC_GLOBAL and 
    DeRef(_6009);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6009 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_6009);
    _0 = _6009;
    _2 = (int)SEQ_PTR(_6009);
    _6009 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_6009);
    DeRefDS(_0);
    _0 = _6009;
    if (IS_ATOM_INT(_6009)) {
        _6009 = (_6009 == 6);
    }
    else {
        _6009 = binary_op(EQUALS, _6009, 6);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6009)) {
        if (_6009 == 0) {
            goto L2F;
        }
    }
    else {
        if (DBL_PTR(_6009)->dbl == 0.0) {
            goto L2F;
        }
    }
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _0 = _5897;
    _2 = (int)SEQ_PTR(_5897);
    _5897 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_5897);
    DeRefDS(_0);
    _0 = _5897;
    if (_name == _5897)
        _5897 = 1;
    else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_5897))
        _5897 = 0;
    else
        _5897 = (compare(_name, _5897) == 0);
    DeRef(_0);
L30:
    if (_5897 == 0)
        goto L2F;

    // 		if not global_found then
    if (_global_found != 0)
        goto L31;

    // 		    global_found = s
    _global_found = _s;
    goto L32;
L31:

    // 		    return 0 -- 2nd global with same name
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return 0;
L32:
L2F:

    // 	    s = SymTab[s][S_NEXT]
    DeRef(_5897);
    _2 = (int)SEQ_PTR(_4SymTab);
    _5897 = (int)*(((s1_ptr)_2)->base + _s);
    RefDS(_5897);
    _2 = (int)SEQ_PTR(_5897);
    _s = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_s))
        _s = (long)DBL_PTR(_s)->dbl;

    // 	end while 
    goto L2C;
L2D:

    // 	return global_found
    DeRefDS(_name);
    DeRef(_ns);
    DeRef(_5897);
    DeRef(_6009);
    DeRef(_5901);
    DeRef(_5909);
    return _global_found;
L1C:
    ;
}


