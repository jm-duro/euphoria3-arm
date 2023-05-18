// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16opQPRINT()
{
    int _6508 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+2]
    _6508 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6508);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     ? val[a]
    _2 = (int)SEQ_PTR(_16val);
    _6508 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6508);
    StdPrint(1, _6508, 1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6508);
    return 0;
    ;
}


int _16opPRINT()
{
    int _6517 = 0;
    int _6512 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6512 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6512);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6512 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6512);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     print(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6512 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6512);
    _2 = (int)SEQ_PTR(_16val);
    _6517 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6517);
    StdPrint(_6512, _6517, 0);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_6517);
    DeRef(_6512);
    return 0;
    ;
}


int _16opPRINTF()
{
    int _6527 = 0;
    int _6526 = 0;
    int _6519 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6519 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6519);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6519 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6519);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     c = Code[pc+3]
    _6519 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16c = (int)*(((s1_ptr)_2)->base + _6519);
    if (!IS_ATOM_INT(_16c))
        _16c = (long)DBL_PTR(_16c)->dbl;

    //     printf(val[a], val[b], val[c])
    _2 = (int)SEQ_PTR(_16val);
    _6519 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6519);
    _2 = (int)SEQ_PTR(_16val);
    _6526 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6526);
    _2 = (int)SEQ_PTR(_16val);
    _6527 = (int)*(((s1_ptr)_2)->base + _16c);
    Ref(_6527);
    EPrintf(_6519, _6526, _6527);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6527);
    DeRef(_6526);
    DeRef(_6519);
    return 0;
    ;
}


int _16opSPRINTF()
{
    int _6536 = 0;
    int _6529 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6529 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6529);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6529 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6529);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6529 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6529);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = sprintf(val[a], val[b])
    _2 = (int)SEQ_PTR(_16val);
    _6529 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6529);
    _2 = (int)SEQ_PTR(_16val);
    _6536 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6536);
    _0 = _6536;
    _6536 = EPrintf(-9999999, _6529, _6536);
    DeRef(_0);
    RefDS(_6536);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6536;
    DeRef(_1);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRefDSi(_6536);
    DeRef(_6529);
    return 0;
    ;
}


int _16opCOMMAND_LINE()
{
    int _cmd = 0;
    int _6546 = 0;
    int _6539 = 0;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _6539 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6539);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     cmd = command_line()
    _cmd = Command_Line();

    //     if length(cmd) > 2 then
    _6539 = SEQ_PTR(_cmd)->length;
    if (_6539 <= 2)
        goto L1;

    // 	cmd = {cmd[1]} & cmd[3..$]
    _2 = (int)SEQ_PTR(_cmd);
    _6539 = (int)*(((s1_ptr)_2)->base + 1);
    RefDS(_6539);
    _0 = _6539;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_6539);
    *((int *)(_2+4)) = _6539;
    _6539 = MAKE_SEQ(_1);
    DeRefDS(_0);
    _6546 = SEQ_PTR(_cmd)->length;
    rhs_slice_target = (object_ptr)&_6546;
    RHS_Slice((s1_ptr)_cmd, 3, _6546);
    Concat((object_ptr)&_cmd, _6539, (s1_ptr)_6546);
L1:

    //     val[target] = cmd
    RefDS(_cmd);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _cmd;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRefDS(_cmd);
    DeRef(_6546);
    DeRef(_6539);
    return 0;
    ;
}


int _16opGETENV()
{
    int _6550 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6550 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6550);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _6550 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6550);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     if atom(val[a]) then
    _2 = (int)SEQ_PTR(_16val);
    _6550 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6550);
    _0 = _6550;
    _6550 = IS_ATOM(_6550);
    DeRef(_0);
    if (_6550 == 0)
        goto L1;

    // 	RTFatal("argument to getenv must be a sequence")
    RefDS(_6556);
    _16RTFatal(_6556);
L1:

    //     val[target] = getenv(val[a])
    DeRef(_6550);
    _2 = (int)SEQ_PTR(_16val);
    _6550 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6550);
    DeRef(_6550);
    _6550 = EGetEnv(_6550);
    Ref(_6550);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6550;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRefi(_6550);
    return 0;
    ;
}


int _16opC_PROC()
{
    int _sub;
    int _6567 = 0;
    int _6560 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6560 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6560);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6560 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6560);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     sub = Code[pc+3]
    _6560 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _6560);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     c_proc(val[a], val[b])  -- callback could happen here
    _2 = (int)SEQ_PTR(_16val);
    _6560 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6560);
    _2 = (int)SEQ_PTR(_16val);
    _6567 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6567);
    call_c(0, _6560, _6567);

    //     restore_privates(sub)
    _16restore_privates(_sub);

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_6567);
    DeRef(_6560);
    return 0;
    ;
}


int _16opC_FUNC()
{
    int _target;
    int _sub;
    int _temp = 0;
    int _6578 = 0;
    int _6569 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6569 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6569);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6569 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6569);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     sub = Code[pc+3]
    _6569 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _6569);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     target = Code[pc+4]
    _6569 = _16pc + 4;
    _2 = (int)SEQ_PTR(_4Code);
    _target = (int)*(((s1_ptr)_2)->base + _6569);
    if (!IS_ATOM_INT(_target))
        _target = (long)DBL_PTR(_target)->dbl;

    //     temp = c_func(val[a], val[b])  -- callback could happen here
    _2 = (int)SEQ_PTR(_16val);
    _6569 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6569);
    _2 = (int)SEQ_PTR(_16val);
    _6578 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6578);
    _temp = call_c(1, _6569, _6578);

    //     restore_privates(sub)
    _16restore_privates(_sub);

    //     val[target] = temp
    Ref(_temp);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _target);
    _1 = *(int *)_2;
    *(int *)_2 = _temp;
    DeRef(_1);

    //     pc += 5
    _16pc = _16pc + 5;

    // end procedure
    DeRef(_temp);
    DeRef(_6578);
    DeRef(_6569);
    return 0;
    ;
}


int _16opTRACE()
{
    int _6581 = 0;
    int _0, _1, _2;
    

    //     TraceOn = val[Code[pc+1]]
    _6581 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _6581 = (int)*(((s1_ptr)_2)->base + _6581);
    Ref(_6581);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_6581))
        _16TraceOn = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6581)->dbl));
    else
        _16TraceOn = (int)*(((s1_ptr)_2)->base + _6581);
    if (!IS_ATOM_INT(_16TraceOn))
        _16TraceOn = (long)DBL_PTR(_16TraceOn)->dbl;

    //     pc += 2  -- turn on/off tracing
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_6581);
    return 0;
    ;
}


int _16opPROFILE()
{
    int _0, _1, _2;
    

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    return 0;
    ;
}


int _16opUPDATE_GLOBALS()
{
    int _0, _1, _2;
    

    //     pc += 1
    _16pc = _16pc + 1;

    // end procedure
    return 0;
    ;
}


int _16do_exec()
{
    int _op;
    int _6587;
    int _0, _1, _2;
    

    //     keep_running = TRUE
    _16keep_running = 1;

    //     while keep_running do 
L1:
    if (_16keep_running == 0)
        goto L2;

    // 	op = Code[pc]
    _2 = (int)SEQ_PTR(_4Code);
    _op = (int)*(((s1_ptr)_2)->base + _16pc);
    if (!IS_ATOM_INT(_op))
        _op = (long)DBL_PTR(_op)->dbl;

    // 	call_proc(operation[op], {}) -- opcodes start at 1
    _2 = (int)SEQ_PTR(_16operation);
    _6587 = (int)*(((s1_ptr)_2)->base + _op);
    _0 = (int)_00[_6587].addr;
    (*(int (*)())_0)(
                         );

    //     end while
    goto L1;
L2:

    //     keep_running = TRUE -- so higher-level do_exec() will keep running
    _16keep_running = 1;

    // end procedure
    return 0;
    ;
}


int _16general_callback(int _routine, int _args)
{
    int _6591 = 0;
    int _6589 = 0;
    int _0, _1, _2, _3;
    

    //     val[t_id] = routine[C_USER_ROUTINE]
    _2 = (int)SEQ_PTR(_routine);
    _6589 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_6589);
    Ref(_6589);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16t_id);
    _1 = *(int *)_2;
    *(int *)_2 = _6589;
    DeRef(_1);

    //     val[t_arglist] = args
    RefDS(_args);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16t_arglist);
    _1 = *(int *)_2;
    *(int *)_2 = _args;
    DeRef(_1);

    //     SymTab[call_back_routine][S_RESIDENT_TASK] = current_task
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_16call_back_routine + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _16current_task;
    DeRef(_1);

    //     call_stack = append(call_stack, pc)
    Append(&_16call_stack, _16call_stack, _16pc);

    //     call_stack = append(call_stack, call_back_routine)
    Append(&_16call_stack, _16call_stack, _16call_back_routine);

    //     Code = call_back_code 
    RefDS(_16call_back_code);
    DeRef(_4Code);
    _4Code = _16call_back_code;

    //     pc = 1 
    _16pc = 1;

    //     do_exec()
    _16do_exec();

    //     pc = call_stack[$-1]
    _6591 = SEQ_PTR(_16call_stack)->length;
    _6591 = _6591 - 1;
    _2 = (int)SEQ_PTR(_16call_stack);
    _16pc = (int)*(((s1_ptr)_2)->base + _6591);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    //     call_stack = call_stack[1..$-2]
    _6591 = SEQ_PTR(_16call_stack)->length;
    _6591 = _6591 - 2;
    rhs_slice_target = (object_ptr)&_16call_stack;
    RHS_Slice((s1_ptr)_16call_stack, 1, _6591);

    //     Code = SymTab[call_stack[$]][S_CODE]
    _6591 = SEQ_PTR(_16call_stack)->length;
    _2 = (int)SEQ_PTR(_16call_stack);
    _6591 = (int)*(((s1_ptr)_2)->base + _6591);
    Ref(_6591);
    _0 = _6591;
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!IS_ATOM_INT(_6591))
        _6591 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_6591)->dbl));
    else
        _6591 = (int)*(((s1_ptr)_2)->base + _6591);
    RefDS(_6591);
    DeRef(_0);
    DeRefDS(_4Code);
    _2 = (int)SEQ_PTR(_6591);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    //     return val[t_return_val]
    DeRefDS(_6591);
    _2 = (int)SEQ_PTR(_16val);
    _6591 = (int)*(((s1_ptr)_2)->base + _16t_return_val);
    Ref(_6591);
    DeRefDS(_routine);
    DeRefDS(_args);
    DeRef(_6589);
    return _6591;
    ;
}


int _16machine_callback(int _cbx, int _ptr)
{
    int _routine = 0;
    int _args = 0;
    int _6607 = 0;
    int _0, _1, _2;
    

    //     routine = call_backs[cbx]
    _2 = (int)SEQ_PTR(_16call_backs);
    if (!IS_ATOM_INT(_cbx))
        _routine = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _routine = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_routine);

    //     args = peek4u(ptr & call_backs[cbx][C_NUM_ARGS])
    _2 = (int)SEQ_PTR(_16call_backs);
    if (!IS_ATOM_INT(_cbx))
        _6607 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_cbx)->dbl));
    else
        _6607 = (int)*(((s1_ptr)_2)->base + _cbx);
    RefDS(_6607);
    _0 = _6607;
    _2 = (int)SEQ_PTR(_6607);
    _6607 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_6607);
    DeRefDS(_0);
    if (IS_SEQUENCE(_ptr) && IS_ATOM(_6607)) {
    }
    else if (IS_ATOM(_ptr) && IS_SEQUENCE(_6607)) {
        Ref(_ptr);
        Prepend(&_6607, _6607, _ptr);
    }
    else {
        Concat((object_ptr)&_6607, _ptr, (s1_ptr)_6607);
    }
    _1 = (int)SEQ_PTR(_6607);
    peek4_addr = (unsigned long *)get_pos_int("peek4s/peek4u", *(((s1_ptr)_1)->base+1));
    _2 = get_pos_int("peek", *(((s1_ptr)_1)->base+2));
    poke4_addr = (unsigned long *)NewS1(_2);
    _args = MAKE_SEQ(poke4_addr);
    poke4_addr = (unsigned long *)((s1_ptr)poke4_addr)->base;
    while (--_2 >= 0) {
        poke4_addr++;
        _1 = (int)*peek4_addr++;
        if ((unsigned)_1 > (unsigned)MAXINT)
            _1 = NewDouble((double)(unsigned long)_1);
        *(int *)poke4_addr = _1;
    }

    //     return general_callback(routine, args)
    RefDS(_routine);
    RefDS(_args);
    _0 = _6607;
    _6607 = _16general_callback(_routine, _args);
    DeRefDS(_0);
    DeRef(_cbx);
    DeRef(_ptr);
    DeRefDS(_routine);
    DeRefDS(_args);
    return _6607;
    ;
}


int _16do_callback(int _b)
{
    int _r;
    int _asm97531 = 0;
    int _id;
    int _convention;
    int _x = 0;
    int _6626 = 0;
    int _6620 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     x = val[b]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_x);

    //     if atom(x) then
    _6620 = IS_ATOM(_x);
    if (_6620 == 0)
        goto L1;

    // 	id = x
    Ref(_x);
    _id = _x;
    if (!IS_ATOM_INT(_id)) {
        _1 = (long)(DBL_PTR(_id)->dbl);
        DeRefDS(_id);
        _id = _1;
    }

    // 	convention = 0
    _convention = 0;
    goto L2;
L1:

    // 	id = x[2]
    _2 = (int)SEQ_PTR(_x);
    _id = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_id))
        _id = (long)DBL_PTR(_id)->dbl;

    // 	convention = x[1]
    _2 = (int)SEQ_PTR(_x);
    _convention = (int)*(((s1_ptr)_2)->base + 1);
    if (!IS_ATOM_INT(_convention))
        _convention = (long)DBL_PTR(_convention)->dbl;
L2:

    //     if id < 0 or id >= length(e_routine) then
    DeRef(_6620);
    _6620 = (_id < 0);
    if (_6620 != 0) {
        goto L3;
    }
    DeRef(_6626);
    _6626 = SEQ_PTR(_16e_routine)->length;
    _6626 = (_id >= _6626);
L4:
    if (_6626 == 0)
        goto L5;
L3:

    // 	RTFatal("Invalid routine id")
    RefDS(_6628);
    _16RTFatal(_6628);
L5:

    //     r = e_routine[id+1]
    DeRef(_6626);
    _6626 = _id + 1;
    _2 = (int)SEQ_PTR(_16e_routine);
    _r = (int)*(((s1_ptr)_2)->base + _6626);

    //     if platform() = WIN32 and convention = 0 then
    _6626 = (3 == 2);
    if (_6626 == 0) {
        goto L6;
    }
    DeRef(_6620);
    _6620 = (_convention == 0);
L7:
    if (_6620 == 0)
        goto L6;

    // 	asm = allocate( length(cb_std) )
    DeRef(_6620);
    _6620 = 24;
    _0 = _asm97531;
    _asm97531 = _7allocate(24);
    DeRef(_0);

    // 	poke( asm, cb_std ) 
    if (IS_ATOM_INT(_asm97531))
        poke_addr = (unsigned char *)_asm97531;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_asm97531)->dbl);
    _1 = (int)SEQ_PTR(_16cb_std);
    _1 = (int)((s1_ptr)_1)->base;
    while (1) {
        _1 += 4;
        _2 = *((int *)_1);
        if (IS_ATOM_INT(_2))
            *poke_addr++ = (unsigned char)_2;
        else if (_2 == NOVALUE)
            break;
        else {
            *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
        }
    }

    // 	poke4( asm + 7, length(call_backs) + 1 )
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 7;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)7);
    }
    DeRef(_6626);
    _6626 = SEQ_PTR(_16call_backs)->length;
    _6626 = _6626 + 1;
    if (IS_ATOM_INT(_6620))
        poke4_addr = (unsigned long *)_6620;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6620)->dbl);
    *poke4_addr = (unsigned long)_6626;

    // 	poke4( asm + 13, asm + 20 )
    if (IS_ATOM_INT(_asm97531)) {
        _6626 = _asm97531 + 13;
        if ((long)((unsigned long)_6626 + (unsigned long)HIGH_BITS) >= 0) 
            _6626 = NewDouble((double)_6626);
    }
    else {
        _6626 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)13);
    }
    DeRef(_6620);
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 20;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)20);
    }
    if (IS_ATOM_INT(_6626))
        poke4_addr = (unsigned long *)_6626;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6626)->dbl);
    if (IS_ATOM_INT(_6620)) {
        *poke4_addr = (unsigned long)_6620;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_6620)->dbl;
    }

    // 	poke( asm + 18, SymTab[r][S_NUM_ARGS] * 4 )
    DeRef(_6620);
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 18;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)18);
    }
    DeRef(_6626);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6626 = (int)*(((s1_ptr)_2)->base + _r);
    RefDS(_6626);
    _0 = _6626;
    _2 = (int)SEQ_PTR(_6626);
    _6626 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6626);
    DeRefDS(_0);
    _0 = _6626;
    if (IS_ATOM_INT(_6626)) {
        if (_6626 == (short)_6626)
            _6626 = _6626 * 4;
        else
            _6626 = NewDouble(_6626 * (double)4);
    }
    else {
        _6626 = binary_op(MULTIPLY, _6626, 4);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6620))
        poke_addr = (unsigned char *)_6620;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_6620)->dbl);
    if (IS_ATOM_INT(_6626)) {
        *poke_addr = (unsigned char)_6626;
    }
    else if (IS_ATOM(_6626)) {
        *poke_addr = (signed char)DBL_PTR(_6626)->dbl;
    }
    else {
        _1 = (int)SEQ_PTR(_6626);
        _1 = (int)((s1_ptr)_1)->base;
        while (1) {
            _1 += 4;
            _2 = *((int *)_1);
            if (IS_ATOM_INT(_2))
                *poke_addr++ = (unsigned char)_2;
            else if (_2 == NOVALUE)
                break;
            else {
                *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
            }
        }
    }

    // 	poke4( asm + 20, call_back( routine_id("machine_callback") ) )
    DeRef(_6626);
    if (IS_ATOM_INT(_asm97531)) {
        _6626 = _asm97531 + 20;
        if ((long)((unsigned long)_6626 + (unsigned long)HIGH_BITS) >= 0) 
            _6626 = NewDouble((double)_6626);
    }
    else {
        _6626 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)20);
    }
    DeRef(_6620);
    _6620 = CRoutineId(383, 16, _6646);
    _6620 = _17call_back(_6620);
    if (IS_ATOM_INT(_6626))
        poke4_addr = (unsigned long *)_6626;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6626)->dbl);
    if (IS_ATOM_INT(_6620)) {
        *poke4_addr = (unsigned long)_6620;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_6620)->dbl;
    }
    goto L8;
L6:

    // 	asm = allocate( length(cb_cdecl) )  
    DeRef(_6620);
    _6620 = 27;
    _0 = _asm97531;
    _asm97531 = _7allocate(27);
    DeRef(_0);

    // 	poke( asm, cb_cdecl )
    if (IS_ATOM_INT(_asm97531))
        poke_addr = (unsigned char *)_asm97531;
    else
        poke_addr = (unsigned char *)(unsigned long)(DBL_PTR(_asm97531)->dbl);
    _1 = (int)SEQ_PTR(_16cb_cdecl);
    _1 = (int)((s1_ptr)_1)->base;
    while (1) {
        _1 += 4;
        _2 = *((int *)_1);
        if (IS_ATOM_INT(_2))
            *poke_addr++ = (unsigned char)_2;
        else if (_2 == NOVALUE)
            break;
        else {
            *poke_addr++ = (signed char)DBL_PTR(_2)->dbl;
        }
    }

    // 	poke4( asm + 7, length(call_backs) + 1 )
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 7;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)7);
    }
    DeRef(_6626);
    _6626 = SEQ_PTR(_16call_backs)->length;
    _6626 = _6626 + 1;
    if (IS_ATOM_INT(_6620))
        poke4_addr = (unsigned long *)_6620;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6620)->dbl);
    *poke4_addr = (unsigned long)_6626;

    // 	poke4( asm + 13, asm + 23 )
    if (IS_ATOM_INT(_asm97531)) {
        _6626 = _asm97531 + 13;
        if ((long)((unsigned long)_6626 + (unsigned long)HIGH_BITS) >= 0) 
            _6626 = NewDouble((double)_6626);
    }
    else {
        _6626 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)13);
    }
    DeRef(_6620);
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 23;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)23);
    }
    if (IS_ATOM_INT(_6626))
        poke4_addr = (unsigned long *)_6626;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6626)->dbl);
    if (IS_ATOM_INT(_6620)) {
        *poke4_addr = (unsigned long)_6620;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_6620)->dbl;
    }

    // 	poke4( asm + 23, call_back( '+' & routine_id("machine_callback") ) )
    DeRef(_6620);
    if (IS_ATOM_INT(_asm97531)) {
        _6620 = _asm97531 + 23;
        if ((long)((unsigned long)_6620 + (unsigned long)HIGH_BITS) >= 0) 
            _6620 = NewDouble((double)_6620);
    }
    else {
        _6620 = NewDouble(DBL_PTR(_asm97531)->dbl + (double)23);
    }
    DeRef(_6626);
    _6626 = CRoutineId(383, 16, _6646);
    Concat((object_ptr)&_6626, 43, (s1_ptr)_6626);
    RefDS(_6626);
    _0 = _6626;
    _6626 = _17call_back(_6626);
    DeRefDSi(_0);
    if (IS_ATOM_INT(_6620))
        poke4_addr = (unsigned long *)_6620;
    else
        poke4_addr = (unsigned long *)(unsigned long)(DBL_PTR(_6620)->dbl);
    if (IS_ATOM_INT(_6626)) {
        *poke4_addr = (unsigned long)_6626;
    }
    else {
        *poke4_addr = (unsigned long)DBL_PTR(_6626)->dbl;
    }
L8:

    //     val[target] = asm
    Ref(_asm97531);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _asm97531;
    DeRef(_1);

    //     call_backs = append( call_backs, { r, id, SymTab[r][S_NUM_ARGS] })
    DeRef(_6626);
    _2 = (int)SEQ_PTR(_4SymTab);
    _6626 = (int)*(((s1_ptr)_2)->base + _r);
    RefDS(_6626);
    _0 = _6626;
    _2 = (int)SEQ_PTR(_6626);
    _6626 = (int)*(((s1_ptr)_2)->base + 20);
    Ref(_6626);
    DeRefDS(_0);
    _0 = _6626;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _r;
    *((int *)(_2+8)) = _id;
    Ref(_6626);
    *((int *)(_2+12)) = _6626;
    _6626 = MAKE_SEQ(_1);
    DeRef(_0);
    RefDS(_6626);
    Append(&_16call_backs, _16call_backs, _6626);

    // end procedure        
    DeRef(_asm97531);
    DeRef(_x);
    DeRefDS(_6626);
    DeRef(_6620);
    return 0;
    ;
}


int _16do_crash_routine(int _b)
{
    int _x = 0;
    int _6664 = 0;
    int _6667 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_b)) {
        _1 = (long)(DBL_PTR(_b)->dbl);
        DeRefDS(_b);
        _b = _1;
    }

    //     x = val[b]
    _2 = (int)SEQ_PTR(_16val);
    _x = (int)*(((s1_ptr)_2)->base + _b);
    Ref(_x);

    //     if atom(x) and x >= 0 and x < length(e_routine) then
    _6664 = IS_ATOM(_x);
    if (_6664 == 0) {
        _6664 = 0;
        goto L1;
    }
    if (IS_ATOM_INT(_x)) {
        _6667 = (_x >= 0);
    }
    else {
        _6667 = binary_op(GREATEREQ, _x, 0);
    }
    if (IS_ATOM_INT(_6667))
        _6664 = (_6667 != 0);
    else
        _6664 = DBL_PTR(_6667)->dbl != 0.0;
L1:
    if (_6664 == 0) {
        goto L2;
    }
    DeRef(_6664);
    _6664 = SEQ_PTR(_16e_routine)->length;
    if (IS_ATOM_INT(_x)) {
        _6664 = (_x < _6664);
    }
    else {
        _6664 = binary_op(LESS, _x, _6664);
    }
L3:
    if (_6664 == 0) {
        goto L2;
    }
    else {
        if (!IS_ATOM_INT(_6664) && DBL_PTR(_6664)->dbl == 0.0)
            goto L2;
    }

    // 	crash_list = append(crash_list, x)
    Ref(_x);
    Append(&_16crash_list, _16crash_list, _x);
    goto L4;
L2:

    // 	RTFatal("crash routine requires a valid routine id")
    RefDS(_6672);
    _16RTFatal(_6672);
L4:

    // end procedure
    DeRef(_x);
    DeRef(_6664);
    DeRef(_6667);
    return 0;
    ;
}


int _16opMACHINE_FUNC()
{
    int _6683 = 0;
    int _6673 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6673 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6673);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2] 
    _6673 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6673);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     target = Code[pc+3]
    _6673 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _6673);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     pc += 4
    _16pc = _16pc + 4;

    //     if val[a] = M_CALL_BACK then
    _2 = (int)SEQ_PTR(_16val);
    _6673 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6673);
    if (binary_op_a(NOTEQ, _6673, 52))
        goto L1;

    // 	do_callback(b)  
    _16do_callback(_16b);
    goto L2;
L1:

    // 	val[target] = machine_func(val[a], val[b])
    DeRef(_6673);
    _2 = (int)SEQ_PTR(_16val);
    _6673 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_6673);
    DeRef(_6683);
    _2 = (int)SEQ_PTR(_16val);
    _6683 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6683);
    _0 = _6683;
    _6683 = machine(_6673, _6683);
    DeRef(_0);
    Ref(_6683);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _6683;
    DeRef(_1);
L2:

    // end procedure
    DeRef(_6683);
    DeRef(_6673);
    return 0;
    ;
}


int _16opMACHINE_PROC()
{
    int _v = 0;
    int _6685 = 0;
    int _6695 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _6685 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _6685);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     b = Code[pc+2]
    _6685 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _6685);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     v = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _v = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_v);

    //     if v = M_CRASH_ROUTINE then
    if (binary_op_a(NOTEQ, _v, 66))
        goto L1;

    // 	do_crash_routine(b) 
    _16do_crash_routine(_16b);
    goto L2;
L1:

    //     elsif v = M_CRASH_MESSAGE then
    if (binary_op_a(NOTEQ, _v, 37))
        goto L3;

    // 	crash_msg = val[b]
    DeRef(_16crash_msg);
    _2 = (int)SEQ_PTR(_16val);
    _16crash_msg = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_16crash_msg);
    goto L2;
L3:

    //     elsif v = M_CRASH_FILE and sequence(val[b]) then
    DeRef(_6685);
    if (IS_ATOM_INT(_v)) {
        _6685 = (_v == 57);
    }
    else {
        _6685 = binary_op(EQUALS, _v, 57);
    }
    if (IS_ATOM_INT(_6685)) {
        if (_6685 == 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_6685)->dbl == 0.0) {
            goto L4;
        }
    }
    DeRef(_6695);
    _2 = (int)SEQ_PTR(_16val);
    _6695 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6695);
    _0 = _6695;
    _6695 = IS_SEQUENCE(_6695);
    DeRef(_0);
L5:
    if (_6695 == 0)
        goto L4;

    // 	err_file_name = val[b]  
    DeRef(_16err_file_name);
    _2 = (int)SEQ_PTR(_16val);
    _16err_file_name = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_16err_file_name);
    goto L2;
L4:

    //     elsif EDOS and v = M_TICK_RATE and val[b] > 18 and val[b] < 10000 then
    if (_4EDOS == 0) {
        DeRef(_6695);
        _6695 = 0;
        goto L6;
    }
    DeRef(_6685);
    if (IS_ATOM_INT(_v)) {
        _6685 = (_v == 38);
    }
    else {
        _6685 = binary_op(EQUALS, _v, 38);
    }
    if (IS_ATOM_INT(_6685))
        _6695 = (_6685 != 0);
    else
        _6695 = DBL_PTR(_6685)->dbl != 0.0;
L6:
    if (_6695 == 0) {
        DeRef(_6685);
        _6685 = 0;
        goto L7;
    }
    DeRef(_6695);
    _2 = (int)SEQ_PTR(_16val);
    _6695 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6695);
    _0 = _6695;
    if (IS_ATOM_INT(_6695)) {
        _6695 = (_6695 > 18);
    }
    else {
        _6695 = binary_op(GREATER, _6695, 18);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_6695))
        _6685 = (_6695 != 0);
    else
        _6685 = DBL_PTR(_6695)->dbl != 0.0;
L7:
    if (_6685 == 0) {
        goto L8;
    }
    DeRef(_6685);
    _2 = (int)SEQ_PTR(_16val);
    _6685 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6685);
    _0 = _6685;
    if (IS_ATOM_INT(_6685)) {
        _6685 = (_6685 < 10000);
    }
    else {
        _6685 = binary_op(LESS, _6685, 10000);
    }
    DeRef(_0);
L9:
    if (_6685 == 0) {
        goto L8;
    }
    else {
        if (!IS_ATOM_INT(_6685) && DBL_PTR(_6685)->dbl == 0.0)
            goto L8;
    }

    // 	clock_period = 1 / val[b]
    DeRef(_6685);
    _2 = (int)SEQ_PTR(_16val);
    _6685 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6685);
    DeRef(_16clock_period);
    if (IS_ATOM_INT(_6685)) {
        _16clock_period = (1 % _6685) ? NewDouble((double)1 / _6685) : (1 / _6685);
    }
    else {
        _16clock_period = binary_op(DIVIDE, 1, _6685);
    }

    // 	machine_proc(v, val[b]) 
    DeRef(_6685);
    _2 = (int)SEQ_PTR(_16val);
    _6685 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6685);
    machine(_v, _6685);
    goto L2;
L8:

    // 	machine_proc(v, val[b]) 
    DeRef(_6685);
    _2 = (int)SEQ_PTR(_16val);
    _6685 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_6685);
    machine(_v, _6685);
L2:

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_v);
    DeRef(_6685);
    DeRef(_6695);
    return 0;
    ;
}


int _16InitBackEnd(int _ignore)
{
    int _name = 0;
    int _6711 = 0;
    int _6714 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_ignore)) {
        _1 = (long)(DBL_PTR(_ignore)->dbl);
        DeRefDS(_ignore);
        _ignore = _1;
    }

    //     val = repeat(0, length(SymTab))
    _6711 = SEQ_PTR(_4SymTab)->length;
    DeRef(_16val);
    _16val = Repeat(0, _6711);

    //     for i = 1 to length(SymTab) do
    _6711 = SEQ_PTR(_4SymTab)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _6711)
            goto L2;

        // 	val[i] = SymTab[i][S_OBJ] -- might be NOVALUE
        DeRef(_6714);
        _2 = (int)SEQ_PTR(_4SymTab);
        _6714 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_6714);
        _0 = _6714;
        _2 = (int)SEQ_PTR(_6714);
        _6714 = (int)*(((s1_ptr)_2)->base + 1);
        Ref(_6714);
        DeRefDS(_0);
        Ref(_6714);
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _6714;
        DeRef(_1);

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     operation = repeat(-1, length(opnames))
    DeRef(_6714);
    _6714 = 179;
    DeRefi(_16operation);
    _16operation = Repeat(-1, 179);

    //     for i = 1 to length(opnames) do
    _6714 = 179;
    { int _i;
        _i = 1;
L3:
        if (_i > 179)
            goto L4;

        // 	name = opnames[i]
        DeRef(_name);
        _2 = (int)SEQ_PTR(_18opnames);
        _name = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_name);

        // 	if find(name, {"RHS_SUBS_CHECK", "RHS_SUBS_I"}) then
        DeRef(_6711);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4052;
        RefDS(_4052);
        ((int *)_2)[2] = _4074;
        RefDS(_4074);
        _6711 = MAKE_SEQ(_1);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto L5;

        // 	    name = "RHS_SUBS"
        RefDS(_3985);
        DeRefDS(_name);
        _name = _3985;
        goto L6;
L5:

        // 	elsif find(name, {"ASSIGN_SUBS_CHECK", "ASSIGN_SUBS_I"}) then
        DeRef(_6711);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4044;
        RefDS(_4044);
        ((int *)_2)[2] = _4078;
        RefDS(_4078);
        _6711 = MAKE_SEQ(_1);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto L7;

        // 	    name = "ASSIGN_SUBS"
        RefDS(_3976);
        DeRefDS(_name);
        _name = _3976;
        goto L6;
L7:

        // 	elsif equal(name, "ASSIGN_I") then
        DeRef(_6711);
        if (_name == _4073)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4073))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4073) == 0);
        if (_6711 == 0)
            goto L8;

        // 	    name = "ASSIGN"
        RefDS(_3978);
        DeRefDS(_name);
        _name = _3978;
        goto L6;
L8:

        // 	elsif find(name, {"EXIT", "ENDWHILE"}) then
        DeRef(_6711);
        _1 = NewS1(2);
        _2 = (int)((s1_ptr)_1)->base;
        ((int *)_2)[1] = _4021;
        RefDS(_4021);
        ((int *)_2)[2] = _3982;
        RefDS(_3982);
        _6711 = MAKE_SEQ(_1);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto L9;

        // 	    name = "ELSE"
        RefDS(_3983);
        DeRefDS(_name);
        _name = _3983;
        goto L6;
L9:

        // 	elsif equal(name, "PLUS1_I") then
        DeRef(_6711);
        if (_name == _4077)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4077))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4077) == 0);
        if (_6711 == 0)
            goto LA;

        // 	    name = "PLUS1"      
        RefDS(_4053);
        DeRefDS(_name);
        _name = _4053;
        goto L6;
LA:

        // 	elsif equal(name, "PRIVATE_INIT_CHECK") then
        DeRef(_6711);
        if (_name == _3990)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_3990))
            _6711 = 0;
        else
            _6711 = (compare(_name, _3990) == 0);
        if (_6711 == 0)
            goto LB;

        // 	    name = "GLOBAL_INIT_CHECK"
        RefDS(_4069);
        DeRefDS(_name);
        _name = _4069;
        goto L6;
LB:

        // 	elsif equal(name, "PLUS_I") then
        DeRef(_6711);
        if (_name == _4075)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4075))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4075) == 0);
        if (_6711 == 0)
            goto LC;

        // 	    name = "PLUS"
        RefDS(_3971);
        DeRefDS(_name);
        _name = _3971;
        goto L6;
LC:

        // 	elsif equal(name, "MINUS_I") then
        DeRef(_6711);
        if (_name == _4076)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4076))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4076) == 0);
        if (_6711 == 0)
            goto LD;

        // 	    name = "MINUS"
        RefDS(_3970);
        DeRefDS(_name);
        _name = _3970;
        goto L6;
LD:

        // 	elsif equal(name, "FOR_I") then
        DeRef(_6711);
        if (_name == _4085)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4085))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4085) == 0);
        if (_6711 == 0)
            goto LE;

        // 	    name = "FOR"
        RefDS(_3981);
        DeRefDS(_name);
        _name = _3981;
        goto L6;
LE:

        // 	elsif find(name, {"ENDFOR_UP", "ENDFOR_DOWN", 
        _0 = _6711;
        _1 = NewS1(5);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_4009);
        *((int *)(_2+4)) = _4009;
        RefDS(_4010);
        *((int *)(_2+8)) = _4010;
        RefDS(_4008);
        *((int *)(_2+12)) = _4008;
        RefDS(_4012);
        *((int *)(_2+16)) = _4012;
        RefDS(_4015);
        *((int *)(_2+20)) = _4015;
        _6711 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto LF;

        // 	    name = "ENDFOR_GENERAL"
        RefDS(_3999);
        DeRefDS(_name);
        _name = _3999;
        goto L6;
LF:

        // 	elsif equal(name, "CALL_FUNC") then
        DeRef(_6711);
        if (_name == _4099)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4099))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4099) == 0);
        if (_6711 == 0)
            goto L10;

        // 	    name = "CALL_PROC"
        RefDS(_4098);
        DeRefDS(_name);
        _name = _4098;
        goto L6;
L10:

        // 	elsif find(name, {"DISPLAY_VAR", "ERASE_PRIVATE_NAMES", 
        _0 = _6711;
        _1 = NewS1(3);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_4047);
        *((int *)(_2+4)) = _4047;
        RefDS(_4048);
        *((int *)(_2+8)) = _4048;
        RefDS(_4050);
        *((int *)(_2+12)) = _4050;
        _6711 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto L11;

        // 	    name = "PROFILE"
        RefDS(_4113);
        DeRefDS(_name);
        _name = _4113;
        goto L6;
L11:

        // 	elsif equal(name, "SC2_AND") then
        DeRef(_6711);
        if (_name == _4104)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4104))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4104) == 0);
        if (_6711 == 0)
            goto L12;

        // 	    name = "SC2_OR"
        RefDS(_4106);
        DeRefDS(_name);
        _name = _4106;
        goto L6;
L12:

        // 	elsif find(name, {"SC2_NULL", "ASSIGN_SUBS2", "PLATFORM",
        _0 = _6711;
        _1 = NewS1(6);
        _2 = (int)((s1_ptr)_1)->base;
        RefDS(_4107);
        *((int *)(_2+4)) = _4107;
        RefDS(_4110);
        *((int *)(_2+8)) = _4110;
        RefDS(_4117);
        *((int *)(_2+12)) = _4117;
        RefDS(_4118);
        *((int *)(_2+16)) = _4118;
        RefDS(_4120);
        *((int *)(_2+20)) = _4120;
        RefDS(_4121);
        *((int *)(_2+24)) = _4121;
        _6711 = MAKE_SEQ(_1);
        DeRef(_0);
        _0 = _6711;
        _6711 = find(_name, _6711);
        DeRefDS(_0);
        if (_6711 == 0)
            goto L13;

        // 	    name = "NOP2" 
        RefDS(_4070);
        DeRefDS(_name);
        _name = _4070;
        goto L6;
L13:

        // 	elsif equal(name, "GREATER_IFW_I") then
        DeRef(_6711);
        if (_name == _4084)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4084))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4084) == 0);
        if (_6711 == 0)
            goto L14;

        // 	    name = "GREATER_IFW"
        RefDS(_4067);
        DeRefDS(_name);
        _name = _4067;
        goto L6;
L14:

        // 	elsif equal(name, "LESS_IFW_I") then
        DeRef(_6711);
        if (_name == _4079)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4079))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4079) == 0);
        if (_6711 == 0)
            goto L15;

        // 	    name = "LESS_IFW"
        RefDS(_4062);
        DeRefDS(_name);
        _name = _4062;
        goto L6;
L15:

        // 	elsif equal(name, "EQUALS_IFW_I") then
        DeRef(_6711);
        if (_name == _4081)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4081))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4081) == 0);
        if (_6711 == 0)
            goto L16;

        // 	    name = "EQUALS_IFW"
        RefDS(_4064);
        DeRefDS(_name);
        _name = _4064;
        goto L6;
L16:

        // 	elsif equal(name, "NOTEQ_IFW_I") then
        DeRef(_6711);
        if (_name == _4082)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4082))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4082) == 0);
        if (_6711 == 0)
            goto L17;

        // 	    name = "NOTEQ_IFW"
        RefDS(_4065);
        DeRefDS(_name);
        _name = _4065;
        goto L6;
L17:

        // 	elsif equal(name, "GREATEREQ_IFW_I") then
        DeRef(_6711);
        if (_name == _4080)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4080))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4080) == 0);
        if (_6711 == 0)
            goto L18;

        // 	    name = "GREATEREQ_IFW"
        RefDS(_4063);
        DeRefDS(_name);
        _name = _4063;
        goto L6;
L18:

        // 	elsif equal(name, "LESSEQ_IFW_I") then
        DeRef(_6711);
        if (_name == _4083)
            _6711 = 1;
        else if (IS_ATOM_INT(_name) && IS_ATOM_INT(_4083))
            _6711 = 0;
        else
            _6711 = (compare(_name, _4083) == 0);
        if (_6711 == 0)
            goto L19;

        // 	    name = "LESSEQ_IFW"
        RefDS(_4066);
        DeRefDS(_name);
        _name = _4066;
L19:
L6:

        // 	operation[i] = routine_id("op" & name)
        Concat((object_ptr)&_6711, _6746, (s1_ptr)_name);
        _0 = _6711;
        _6711 = CRoutineId(387, 16, _6711);
        DeRefDS(_0);
        _2 = (int)SEQ_PTR(_16operation);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        *(int *)_2 = _6711;

        // 	if operation[i] = -1 then
        _2 = (int)SEQ_PTR(_16operation);
        _6711 = (int)*(((s1_ptr)_2)->base + _i);
        if (_6711 != -1)
            goto L1A;

        // 	    RTInternal("no routine id for op" & name)
        Concat((object_ptr)&_6711, _6751, (s1_ptr)_name);
        RefDS(_6711);
        _16RTInternal(_6711);
L1A:

        //     end for
        _i = _i + 1;
        goto L3;
L4:
        ;
    }

    // end procedure
    DeRef(_name);
    DeRef(_6711);
    DeRef(_6714);
    return 0;
    ;
}


int _16Execute(int _proc, int _start_index)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_proc)) {
        _1 = (long)(DBL_PTR(_proc)->dbl);
        DeRefDS(_proc);
        _proc = _1;
    }
    if (!IS_ATOM_INT(_start_index)) {
        _1 = (long)(DBL_PTR(_start_index)->dbl);
        DeRefDS(_start_index);
        _start_index = _1;
    }

    //     current_task = 1
    _16current_task = 1;

    //     call_stack = {proc}
    _0 = _16call_stack;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    *((int *)(_2+4)) = _proc;
    _16call_stack = MAKE_SEQ(_1);
    DeRef(_0);

    //     pc = start_index
    _16pc = _start_index;

    //     do_exec()
    _16do_exec();

    // end procedure
    return 0;
    ;
}


int _16BackEnd(int _ignore)
{
    int _0, _1, _2;
    

    //     Execute(TopLevelSub, 1)
    _16Execute(_4TopLevelSub, 1);

    // end procedure
    return 0;
    ;
}


