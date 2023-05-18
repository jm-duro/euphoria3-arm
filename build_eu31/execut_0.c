// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _16task_insert(int _first, int _task)
{
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_first)) {
        _1 = (long)(DBL_PTR(_first)->dbl);
        DeRefDS(_first);
        _first = _1;
    }
    if (!IS_ATOM_INT(_task)) {
        _1 = (long)(DBL_PTR(_task)->dbl);
        DeRefDS(_task);
        _task = _1;
    }

    //     tcb[task][TASK_NEXT] = first
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _first;
    DeRef(_1);

    //     return task
    return _task;
    ;
}


int _16task_delete(int _first, int _task)
{
    int _p;
    int _prev_p;
    int _4577 = 0;
    int _4570 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_first)) {
        _1 = (long)(DBL_PTR(_first)->dbl);
        DeRefDS(_first);
        _first = _1;
    }
    if (!IS_ATOM_INT(_task)) {
        _1 = (long)(DBL_PTR(_task)->dbl);
        DeRefDS(_task);
        _task = _1;
    }

    //     prev_p = -1
    _prev_p = -1;

    //     p = first
    _p = _first;

    //     while p != 0 do
L1:
    if (_p == 0)
        goto L2;

    // 	if p = task then
    if (_p != _task)
        goto L3;

    // 	    if prev_p = -1 then
    if (_prev_p != -1)
        goto L4;

    // 		return tcb[p][TASK_NEXT]
    DeRef(_4570);
    _2 = (int)SEQ_PTR(_16tcb);
    _4570 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_4570);
    _0 = _4570;
    _2 = (int)SEQ_PTR(_4570);
    _4570 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_4570);
    DeRefDS(_0);
    DeRef(_4577);
    return _4570;
    goto L5;
L4:

    // 		tcb[prev_p][TASK_NEXT] = tcb[p][TASK_NEXT]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_prev_p + ((s1_ptr)_2)->base);
    DeRef(_4577);
    _2 = (int)SEQ_PTR(_16tcb);
    _4577 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_4577);
    _0 = _4577;
    _2 = (int)SEQ_PTR(_4577);
    _4577 = (int)*(((s1_ptr)_2)->base + 12);
    Ref(_4577);
    DeRefDS(_0);
    Ref(_4577);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 12);
    _1 = *(int *)_2;
    *(int *)_2 = _4577;
    DeRef(_1);

    // 		return first
    DeRef(_4577);
    DeRef(_4570);
    return _first;
L5:
L3:

    // 	prev_p = p
    _prev_p = _p;

    // 	p = tcb[p][TASK_NEXT]
    DeRef(_4577);
    _2 = (int)SEQ_PTR(_16tcb);
    _4577 = (int)*(((s1_ptr)_2)->base + _p);
    RefDS(_4577);
    _2 = (int)SEQ_PTR(_4577);
    _p = (int)*(((s1_ptr)_2)->base + 12);
    if (!IS_ATOM_INT(_p))
        _p = (long)DBL_PTR(_p)->dbl;

    //     end while
    goto L1;
L2:

    //     return first
    DeRef(_4577);
    DeRef(_4570);
    return _first;
    ;
}


int _16opTASK_YIELD()
{
    int _now = 0;
    int _4581 = 0;
    int _4589 = 0;
    int _4588 = 0;
    int _0, _1, _2, _3;
    

    //     if tcb[current_task][TASK_STATUS] = ST_ACTIVE then
    _2 = (int)SEQ_PTR(_16tcb);
    _4581 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4581);
    _0 = _4581;
    _2 = (int)SEQ_PTR(_4581);
    _4581 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4581);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4581, 0))
        goto L1;

    // 	if tcb[current_task][TASK_RUNS_LEFT] > 0 then
    DeRef(_4581);
    _2 = (int)SEQ_PTR(_16tcb);
    _4581 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4581);
    _0 = _4581;
    _2 = (int)SEQ_PTR(_4581);
    _4581 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4581);
    DeRefDS(_0);
    if (binary_op_a(LESSEQ, _4581, 0))
        goto L2;

    // 	    tcb[current_task][TASK_RUNS_LEFT] -= 1
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    _4589 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4589);
    _0 = _4589;
    if (IS_ATOM_INT(_4589)) {
        _4589 = _4589 - 1;
        if ((long)((unsigned long)_4589 +(unsigned long) HIGH_BITS) >= 0)
            _4589 = NewDouble((double)_4589);
    }
    else {
        _4589 = binary_op(MINUS, _4589, 1);
    }
    DeRef(_0);
    Ref(_4589);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _4589;
    DeRef(_1);
L2:

    // 	if tcb[current_task][TASK_TYPE] = T_REAL_TIME then
    DeRef(_4589);
    _2 = (int)SEQ_PTR(_16tcb);
    _4589 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4589);
    _0 = _4589;
    _2 = (int)SEQ_PTR(_4589);
    _4589 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4589);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4589, 1))
        goto L3;

    // 	    now = time()
    DeRef(_now);
    _now = NewDouble(current_time());

    // 	    if tcb[current_task][TASK_RUNS_MAX] > 1 and 
    DeRef(_4589);
    _2 = (int)SEQ_PTR(_16tcb);
    _4589 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4589);
    _0 = _4589;
    _2 = (int)SEQ_PTR(_4589);
    _4589 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4589);
    DeRefDS(_0);
    _0 = _4589;
    if (IS_ATOM_INT(_4589)) {
        _4589 = (_4589 > 1);
    }
    else {
        _4589 = binary_op(GREATER, _4589, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4589)) {
        if (_4589 == 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_4589)->dbl == 0.0) {
            goto L4;
        }
    }
    DeRef(_4588);
    _2 = (int)SEQ_PTR(_16tcb);
    _4588 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4588);
    _0 = _4588;
    _2 = (int)SEQ_PTR(_4588);
    _4588 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_4588);
    DeRefDS(_0);
    _0 = _4588;
    _4588 = binary_op(EQUALS, _4588, _now);
    DeRef(_0);
L5:
    if (_4588 == 0) {
        goto L4;
    }
    else {
        if (!IS_ATOM_INT(_4588) && DBL_PTR(_4588)->dbl == 0.0)
            goto L4;
    }

    // 		if tcb[current_task][TASK_RUNS_LEFT] = 0 then
    DeRef(_4588);
    _2 = (int)SEQ_PTR(_16tcb);
    _4588 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4588);
    _0 = _4588;
    _2 = (int)SEQ_PTR(_4588);
    _4588 = (int)*(((s1_ptr)_2)->base + 10);
    Ref(_4588);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4588, 0))
        goto L6;

    // 		    now += clock_period
    _0 = _now;
    if (IS_ATOM_INT(_now) && IS_ATOM_INT(_16clock_period)) {
        _now = _now + _16clock_period;
        if ((long)((unsigned long)_now + (unsigned long)HIGH_BITS) >= 0) 
            _now = NewDouble((double)_now);
    }
    else {
        if (IS_ATOM_INT(_now)) {
            _now = NewDouble((double)_now + DBL_PTR(_16clock_period)->dbl);
        }
        else {
            if (IS_ATOM_INT(_16clock_period)) {
                _now = NewDouble(DBL_PTR(_now)->dbl + (double)_16clock_period);
            }
            else
                _now = NewDouble(DBL_PTR(_now)->dbl + DBL_PTR(_16clock_period)->dbl);
        }
    }
    DeRef(_0);

    // 		    tcb[current_task][TASK_RUNS_LEFT] = tcb[current_task][TASK_RUNS_MAX]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    DeRef(_4581);
    _2 = (int)SEQ_PTR(_16tcb);
    _4581 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4581);
    _0 = _4581;
    _2 = (int)SEQ_PTR(_4581);
    _4581 = (int)*(((s1_ptr)_2)->base + 11);
    Ref(_4581);
    DeRefDS(_0);
    Ref(_4581);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 10);
    _1 = *(int *)_2;
    *(int *)_2 = _4581;
    DeRef(_1);

    // 		    tcb[current_task][TASK_MIN_TIME] = now + 
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    DeRef(_4588);
    _2 = (int)SEQ_PTR(_16tcb);
    _4588 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4588);
    _0 = _4588;
    _2 = (int)SEQ_PTR(_4588);
    _4588 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4588);
    DeRefDS(_0);
    _0 = _4588;
    if (IS_ATOM_INT(_now) && IS_ATOM_INT(_4588)) {
        _4588 = _now + _4588;
        if ((long)((unsigned long)_4588 + (unsigned long)HIGH_BITS) >= 0) 
            _4588 = NewDouble((double)_4588);
    }
    else {
        _4588 = binary_op(PLUS, _now, _4588);
    }
    DeRef(_0);
    Ref(_4588);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _4588;
    DeRef(_1);

    // 		    tcb[current_task][TASK_MAX_TIME] = now + 
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    DeRef(_4581);
    _2 = (int)SEQ_PTR(_16tcb);
    _4581 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4581);
    _0 = _4581;
    _2 = (int)SEQ_PTR(_4581);
    _4581 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4581);
    DeRefDS(_0);
    _0 = _4581;
    if (IS_ATOM_INT(_now) && IS_ATOM_INT(_4581)) {
        _4581 = _now + _4581;
        if ((long)((unsigned long)_4581 + (unsigned long)HIGH_BITS) >= 0) 
            _4581 = NewDouble((double)_4581);
    }
    else {
        _4581 = binary_op(PLUS, _now, _4581);
    }
    DeRef(_0);
    Ref(_4581);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _4581;
    DeRef(_1);
    goto L6;
L7:
L8:
    goto L6;
L4:

    // 		tcb[current_task][TASK_MIN_TIME] = now + 
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    DeRef(_4588);
    _2 = (int)SEQ_PTR(_16tcb);
    _4588 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4588);
    _0 = _4588;
    _2 = (int)SEQ_PTR(_4588);
    _4588 = (int)*(((s1_ptr)_2)->base + 6);
    Ref(_4588);
    DeRefDS(_0);
    _0 = _4588;
    if (IS_ATOM_INT(_now) && IS_ATOM_INT(_4588)) {
        _4588 = _now + _4588;
        if ((long)((unsigned long)_4588 + (unsigned long)HIGH_BITS) >= 0) 
            _4588 = NewDouble((double)_4588);
    }
    else {
        _4588 = binary_op(PLUS, _now, _4588);
    }
    DeRef(_0);
    Ref(_4588);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _4588;
    DeRef(_1);

    // 		tcb[current_task][TASK_MAX_TIME] = now + 
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_16current_task + ((s1_ptr)_2)->base);
    DeRef(_4581);
    _2 = (int)SEQ_PTR(_16tcb);
    _4581 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4581);
    _0 = _4581;
    _2 = (int)SEQ_PTR(_4581);
    _4581 = (int)*(((s1_ptr)_2)->base + 7);
    Ref(_4581);
    DeRefDS(_0);
    _0 = _4581;
    if (IS_ATOM_INT(_now) && IS_ATOM_INT(_4581)) {
        _4581 = _now + _4581;
        if ((long)((unsigned long)_4581 + (unsigned long)HIGH_BITS) >= 0) 
            _4581 = NewDouble((double)_4581);
    }
    else {
        _4581 = binary_op(PLUS, _now, _4581);
    }
    DeRef(_0);
    Ref(_4581);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _4581;
    DeRef(_1);
L6:
L3:
L1:

    //     scheduler()
    _16scheduler();

    // end procedure
    DeRef(_now);
    DeRef(_4581);
    DeRef(_4589);
    DeRef(_4588);
    return 0;
    ;
}


int _16kill_task(int _task)
{
    int _4630 = 0;
    int _0, _1, _2, _3;
    
    if (!IS_ATOM_INT(_task)) {
        _1 = (long)(DBL_PTR(_task)->dbl);
        DeRefDS(_task);
        _task = _1;
    }

    //     if tcb[task][TASK_TYPE] = T_REAL_TIME then
    _2 = (int)SEQ_PTR(_16tcb);
    _4630 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4630);
    _0 = _4630;
    _2 = (int)SEQ_PTR(_4630);
    _4630 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4630);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4630, 1))
        goto L1;

    // 	rt_first = task_delete(rt_first, task)
    _0 = _16task_delete(_16rt_first, _task);
    _16rt_first = _0;
    if (!IS_ATOM_INT(_16rt_first)) {
        _1 = (long)(DBL_PTR(_16rt_first)->dbl);
        DeRefDS(_16rt_first);
        _16rt_first = _1;
    }
    goto L2;
L1:

    // 	ts_first = task_delete(ts_first, task)
    _0 = _16task_delete(_16ts_first, _task);
    _16ts_first = _0;
    if (!IS_ATOM_INT(_16ts_first)) {
        _1 = (long)(DBL_PTR(_16ts_first)->dbl);
        DeRefDS(_16ts_first);
        _16ts_first = _1;
    }
L2:

    //     tcb[task][TASK_STATUS] = ST_DEAD
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);

    // end procedure
    DeRef(_4630);
    return 0;
    ;
}


int _16which_task(int _tid)
{
    int _4638 = 0;
    int _4637;
    int _0, _1, _2;
    

    //     for i = 1 to length(tcb) do
    _4637 = SEQ_PTR(_16tcb)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _4637)
            goto L2;

        // 	if tcb[i][TASK_TID] = tid then
        DeRef(_4638);
        _2 = (int)SEQ_PTR(_16tcb);
        _4638 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4638);
        _0 = _4638;
        _2 = (int)SEQ_PTR(_4638);
        _4638 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4638);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _4638, _tid))
            goto L3;

        // 	    return i
        DeRef(_tid);
        DeRef(_4638);
        return _i;
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     RTFatal("invalid task id")
    RefDS(_4641);
    _16RTFatal(_4641);
    ;
}


int _16opTASK_STATUS()
{
    int _r;
    int _tid = 0;
    int _4648 = 0;
    int _4642;
    int _0, _1, _2;
    

    //     a = Code[pc+1]
    _4642 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4642);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     target = Code[pc+2]
    _4642 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _4642);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     tid = val[a]
    _2 = (int)SEQ_PTR(_16val);
    _tid = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_tid);

    //     r = -1
    _r = -1;

    //     for t = 1 to length(tcb) do
    _4642 = SEQ_PTR(_16tcb)->length;
    { int _t;
        _t = 1;
L1:
        if (_t > _4642)
            goto L2;

        // 	if tcb[t][TASK_TID] = tid then
        DeRef(_4648);
        _2 = (int)SEQ_PTR(_16tcb);
        _4648 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_4648);
        _0 = _4648;
        _2 = (int)SEQ_PTR(_4648);
        _4648 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4648);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _4648, _tid))
            goto L3;

        // 	    if tcb[t][TASK_STATUS] = ST_ACTIVE then
        DeRef(_4648);
        _2 = (int)SEQ_PTR(_16tcb);
        _4648 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_4648);
        _0 = _4648;
        _2 = (int)SEQ_PTR(_4648);
        _4648 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_4648);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _4648, 0))
            goto L4;

        // 		r = 1
        _r = 1;
        goto L2;
L4:

        // 	    elsif tcb[t][TASK_STATUS] = ST_SUSPENDED then
        DeRef(_4648);
        _2 = (int)SEQ_PTR(_16tcb);
        _4648 = (int)*(((s1_ptr)_2)->base + _t);
        RefDS(_4648);
        _0 = _4648;
        _2 = (int)SEQ_PTR(_4648);
        _4648 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_4648);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _4648, 1))
            goto L2;

        // 		r = 0
        _r = 0;
L5:
L6:

        // 	    exit
        goto L2;
L3:

        //     end for
        _t = _t + 1;
        goto L1;
L2:
        ;
    }

    //     val[target] = r
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _r;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_tid);
    DeRef(_4648);
    return 0;
    ;
}


int _16opTASK_LIST()
{
    int _list = 0;
    int _4661 = 0;
    int _4658;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _4658 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _4658);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     list = {}
    RefDS(_39);
    _list = _39;

    //     for i = 1 to length(tcb) do
    _4658 = SEQ_PTR(_16tcb)->length;
    { int _i;
        _i = 1;
L1:
        if (_i > _4658)
            goto L2;

        // 	if tcb[i][TASK_STATUS] != ST_DEAD then
        DeRef(_4661);
        _2 = (int)SEQ_PTR(_16tcb);
        _4661 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4661);
        _0 = _4661;
        _2 = (int)SEQ_PTR(_4661);
        _4661 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_4661);
        DeRefDS(_0);
        if (binary_op_a(EQUALS, _4661, 2))
            goto L3;

        // 	    list = append(list, tcb[i][TASK_TID])
        DeRef(_4661);
        _2 = (int)SEQ_PTR(_16tcb);
        _4661 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4661);
        _0 = _4661;
        _2 = (int)SEQ_PTR(_4661);
        _4661 = (int)*(((s1_ptr)_2)->base + 2);
        Ref(_4661);
        DeRefDS(_0);
        Ref(_4661);
        Append(&_list, _list, _4661);
L3:

        //     end for
        _i = _i + 1;
        goto L1;
L2:
        ;
    }

    //     val[target] = list
    RefDS(_list);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _list;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRefDS(_list);
    DeRef(_4661);
    return 0;
    ;
}


int _16opTASK_SELF()
{
    int _4668 = 0;
    int _0, _1, _2;
    

    //     target = Code[pc+1]
    _4668 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _4668);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = tcb[current_task][TASK_TID]
    _2 = (int)SEQ_PTR(_16tcb);
    _4668 = (int)*(((s1_ptr)_2)->base + _16current_task);
    RefDS(_4668);
    _0 = _4668;
    _2 = (int)SEQ_PTR(_4668);
    _4668 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4668);
    DeRefDS(_0);
    Ref(_4668);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _4668;
    DeRef(_1);

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_4668);
    return 0;
    ;
}


int _16opTASK_CLOCK_STOP()
{
    int _0, _1, _2;
    

    //     if not clock_stopped then
    if (_16clock_stopped != 0)
        goto L1;

    // 	save_clock = time()
    DeRef(_16save_clock);
    _16save_clock = NewDouble(current_time());

    // 	clock_stopped = TRUE
    _16clock_stopped = 1;
L1:

    //     pc += 1
    _16pc = _16pc + 1;

    // end procedure
    return 0;
    ;
}


int _16opTASK_CLOCK_START()
{
    int _shift = 0;
    int _4676 = 0;
    int _4685 = 0;
    int _4678 = 0;
    int _0, _1, _2, _3;
    

    //     if clock_stopped then
    if (_16clock_stopped == 0)
        goto L1;

    // 	if save_clock >= 0 and save_clock < time() then
    if (IS_ATOM_INT(_16save_clock)) {
        _4676 = (_16save_clock >= 0);
    }
    else {
        _4676 = (DBL_PTR(_16save_clock)->dbl >= (double)0);
    }
    if (_4676 == 0) {
        goto L2;
    }
    _4678 = NewDouble(current_time());
    _0 = _4678;
    if (IS_ATOM_INT(_16save_clock)) {
        _4678 = ((double)_16save_clock < DBL_PTR(_4678)->dbl);
    }
    else {
        _4678 = (DBL_PTR(_16save_clock)->dbl < DBL_PTR(_4678)->dbl);
    }
    DeRefDS(_0);
L3:
    if (_4678 == 0)
        goto L2;

    // 	    shift = time() - save_clock
    DeRef(_4678);
    _4678 = NewDouble(current_time());
    DeRef(_shift);
    if (IS_ATOM_INT(_16save_clock)) {
        _shift = NewDouble(DBL_PTR(_4678)->dbl - (double)_16save_clock);
    }
    else
        _shift = NewDouble(DBL_PTR(_4678)->dbl - DBL_PTR(_16save_clock)->dbl);

    // 	    for i = 1 to length(tcb) do
    DeRefDS(_4678);
    _4678 = SEQ_PTR(_16tcb)->length;
    { int _i;
        _i = 1;
L4:
        if (_i > _4678)
            goto L5;

        // 		tcb[i][TASK_MIN_TIME] += shift
        _2 = (int)SEQ_PTR(_16tcb);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _16tcb = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_4685);
        _2 = (int)SEQ_PTR(*(int *)_3);
        _4685 = (int)*(((s1_ptr)_2)->base + 8);
        Ref(_4685);
        _0 = _4685;
        _4685 = binary_op(PLUS, _4685, _shift);
        DeRef(_0);
        Ref(_4685);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 8);
        _1 = *(int *)_2;
        *(int *)_2 = _4685;
        DeRef(_1);

        // 		tcb[i][TASK_MAX_TIME] += shift
        _2 = (int)SEQ_PTR(_16tcb);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _16tcb = MAKE_SEQ(_2);
        }
        _3 = (int)(_i + ((s1_ptr)_2)->base);
        DeRef(_4676);
        _2 = (int)SEQ_PTR(*(int *)_3);
        _4676 = (int)*(((s1_ptr)_2)->base + 9);
        Ref(_4676);
        _0 = _4676;
        _4676 = binary_op(PLUS, _4676, _shift);
        DeRef(_0);
        Ref(_4676);
        _2 = (int)SEQ_PTR(*(int *)_3);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            *(int *)_3 = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + 9);
        _1 = *(int *)_2;
        *(int *)_2 = _4676;
        DeRef(_1);

        // 	    end for
        _i = _i + 1;
        goto L4;
L5:
        ;
    }
L2:

    // 	clock_stopped = FALSE
    _16clock_stopped = 0;
L1:

    //     pc += 1
    _16pc = _16pc + 1;

    // end procedure
    DeRef(_shift);
    DeRef(_4676);
    DeRef(_4685);
    DeRef(_4678);
    return 0;
    ;
}


int _16opTASK_SUSPEND()
{
    int _task;
    int _4692 = 0;
    int _0, _1, _2, _3;
    

    //     a = Code[pc+1]
    _4692 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4692);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     task = which_task(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _4692 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4692);
    Ref(_4692);
    _task = _16which_task(_4692);

    //     tcb[task][TASK_STATUS] = ST_SUSPENDED
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);

    //     tcb[task][TASK_MAX_TIME] = TASK_NEVER
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    RefDS(_16TASK_NEVER);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _16TASK_NEVER;
    DeRef(_1);

    //     if tcb[task][TASK_TYPE] = T_REAL_TIME then
    DeRef(_4692);
    _2 = (int)SEQ_PTR(_16tcb);
    _4692 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4692);
    _0 = _4692;
    _2 = (int)SEQ_PTR(_4692);
    _4692 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4692);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4692, 1))
        goto L1;

    // 	rt_first = task_delete(rt_first, task)
    _0 = _16task_delete(_16rt_first, _task);
    _16rt_first = _0;
    if (!IS_ATOM_INT(_16rt_first)) {
        _1 = (long)(DBL_PTR(_16rt_first)->dbl);
        DeRefDS(_16rt_first);
        _16rt_first = _1;
    }
    goto L2;
L1:

    // 	ts_first = task_delete(ts_first, task)
    _0 = _16task_delete(_16ts_first, _task);
    _16ts_first = _0;
    if (!IS_ATOM_INT(_16ts_first)) {
        _1 = (long)(DBL_PTR(_16ts_first)->dbl);
        DeRefDS(_16ts_first);
        _16ts_first = _1;
    }
L2:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRef(_4692);
    return 0;
    ;
}


int _16opTASK_CREATE()
{
    int _sub;
    int _new_entry = 0;
    int _recycle;
    int _4712 = 0;
    int _4711 = 0;
    int _4706 = 0;
    int _0, _1, _2;
    

    //     a = Code[pc+1] -- routine id
    _4706 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4706);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     if val[a] < 0 or val[a] >= length(e_routine) then
    _2 = (int)SEQ_PTR(_16val);
    _4706 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4706);
    _0 = _4706;
    if (IS_ATOM_INT(_4706)) {
        _4706 = (_4706 < 0);
    }
    else {
        _4706 = binary_op(LESS, _4706, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4706)) {
        if (_4706 != 0) {
            goto L1;
        }
    }
    else {
        if (DBL_PTR(_4706)->dbl != 0.0) {
            goto L1;
        }
    }
    _2 = (int)SEQ_PTR(_16val);
    _4711 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4711);
    _4712 = SEQ_PTR(_16e_routine)->length;
    if (IS_ATOM_INT(_4711)) {
        _4712 = (_4711 >= _4712);
    }
    else {
        _4712 = binary_op(GREATEREQ, _4711, _4712);
    }
L2:
    if (_4712 == 0) {
        goto L3;
    }
    else {
        if (!IS_ATOM_INT(_4712) && DBL_PTR(_4712)->dbl == 0.0)
            goto L3;
    }
L1:

    // 	RTFatal("invalid routine id")
    RefDS(_4714);
    _16RTFatal(_4714);
L3:

    //     sub = e_routine[val[a]+1]
    DeRef(_4712);
    _2 = (int)SEQ_PTR(_16val);
    _4712 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4712);
    _0 = _4712;
    if (IS_ATOM_INT(_4712)) {
        _4712 = _4712 + 1;
    }
    else
        _4712 = binary_op(PLUS, 1, _4712);
    DeRef(_0);
    _2 = (int)SEQ_PTR(_16e_routine);
    if (!IS_ATOM_INT(_4712))
        _sub = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4712)->dbl));
    else
        _sub = (int)*(((s1_ptr)_2)->base + _4712);

    //     if SymTab[sub][S_TOKEN] != PROC then
    DeRef(_4712);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4712 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4712);
    _0 = _4712;
    _2 = (int)SEQ_PTR(_4712);
    _4712 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4712);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4712, 27))
        goto L4;

    // 	RTFatal("specify the routine id of a procedure, not a function or type")
    RefDS(_4721);
    _16RTFatal(_4721);
L4:

    //     b = Code[pc+2] -- args
    DeRef(_4712);
    _4712 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _4712);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     new_entry = {val[a], next_task_id, T_REAL_TIME, ST_SUSPENDED, 0, 
    _2 = (int)SEQ_PTR(_16val);
    _4712 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4712);
    DeRef(_4711);
    _2 = (int)SEQ_PTR(_16val);
    _4711 = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_4711);
    _0 = _new_entry;
    _1 = NewS1(16);
    _2 = (int)((s1_ptr)_1)->base;
    Ref(_4712);
    *((int *)(_2+4)) = _4712;
    Ref(_16next_task_id);
    *((int *)(_2+8)) = _16next_task_id;
    *((int *)(_2+12)) = 1;
    *((int *)(_2+16)) = 1;
    *((int *)(_2+20)) = 0;
    *((int *)(_2+24)) = 0;
    *((int *)(_2+28)) = 0;
    *((int *)(_2+32)) = 0;
    RefDS(_16TASK_NEVER);
    *((int *)(_2+36)) = _16TASK_NEVER;
    *((int *)(_2+40)) = 1;
    *((int *)(_2+44)) = 1;
    *((int *)(_2+48)) = 0;
    Ref(_4711);
    *((int *)(_2+52)) = _4711;
    *((int *)(_2+56)) = 0;
    RefDSn(_39, 2);
    *((int *)(_2+60)) = _39;
    *((int *)(_2+64)) = _39;
    _new_entry = MAKE_SEQ(_1);
    DeRef(_0);

    //     recycle = FALSE
    _recycle = 0;

    //     for i = 1 to length(tcb) do
    DeRef(_4711);
    _4711 = SEQ_PTR(_16tcb)->length;
    { int _i;
        _i = 1;
L5:
        if (_i > _4711)
            goto L6;

        // 	if tcb[i][TASK_STATUS] = ST_DEAD then
        DeRef(_4712);
        _2 = (int)SEQ_PTR(_16tcb);
        _4712 = (int)*(((s1_ptr)_2)->base + _i);
        RefDS(_4712);
        _0 = _4712;
        _2 = (int)SEQ_PTR(_4712);
        _4712 = (int)*(((s1_ptr)_2)->base + 4);
        Ref(_4712);
        DeRefDS(_0);
        if (binary_op_a(NOTEQ, _4712, 2))
            goto L7;

        // 	    tcb[i] = new_entry
        RefDS(_new_entry);
        _2 = (int)SEQ_PTR(_16tcb);
        _2 = (int)(((s1_ptr)_2)->base + _i);
        _1 = *(int *)_2;
        *(int *)_2 = _new_entry;
        DeRefDS(_1);

        // 	    recycle = TRUE
        _recycle = 1;

        // 	    exit
        goto L6;
L7:

        //     end for
        _i = _i + 1;
        goto L5;
L6:
        ;
    }

    //     if not recycle then
    if (_recycle != 0)
        goto L8;

    // 	tcb = append(tcb, new_entry)
    RefDS(_new_entry);
    Append(&_16tcb, _16tcb, _new_entry);
L8:

    //     target = Code[pc+3]
    DeRef(_4712);
    _4712 = _16pc + 3;
    _2 = (int)SEQ_PTR(_4Code);
    _16target = (int)*(((s1_ptr)_2)->base + _4712);
    if (!IS_ATOM_INT(_16target))
        _16target = (long)DBL_PTR(_16target)->dbl;

    //     val[target] = next_task_id
    Ref(_16next_task_id);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _16target);
    _1 = *(int *)_2;
    *(int *)_2 = _16next_task_id;
    DeRef(_1);

    //     if not id_wrap and next_task_id < TASK_ID_MAX then
    _4712 = (_16id_wrap == 0);
    if (_4712 == 0) {
        goto L9;
    }
    DeRef(_4711);
    if (IS_ATOM_INT(_16next_task_id)) {
        _4711 = ((double)_16next_task_id < DBL_PTR(_16TASK_ID_MAX)->dbl);
    }
    else {
        _4711 = (DBL_PTR(_16next_task_id)->dbl < DBL_PTR(_16TASK_ID_MAX)->dbl);
    }
LA:
    if (_4711 == 0)
        goto L9;

    // 	next_task_id += 1
    _0 = _16next_task_id;
    if (IS_ATOM_INT(_16next_task_id)) {
        _16next_task_id = _16next_task_id + 1;
        if (_16next_task_id > MAXINT)
            _16next_task_id = NewDouble((double)_16next_task_id);
    }
    else
        _16next_task_id = binary_op(PLUS, 1, _16next_task_id);
    DeRef(_0);
    goto LB;
L9:

    // 	id_wrap = TRUE -- id's have wrapped
    _16id_wrap = 1;

    // 	for i = 1 to TASK_ID_MAX do
    { int _i;
        _i = 1;
LC:
        if (binary_op_a(GREATER, _i, _16TASK_ID_MAX))
            goto LD;

        // 	    next_task_id = i
        Ref(_i);
        DeRef(_16next_task_id);
        _16next_task_id = _i;

        // 	    for j = 1 to length(tcb) do
        DeRef(_4711);
        _4711 = SEQ_PTR(_16tcb)->length;
        { int _j;
            _j = 1;
LE:
            if (_j > _4711)
                goto LF;

            // 		if next_task_id = tcb[j][TASK_TID] then
            DeRef(_4712);
            _2 = (int)SEQ_PTR(_16tcb);
            _4712 = (int)*(((s1_ptr)_2)->base + _j);
            RefDS(_4712);
            _0 = _4712;
            _2 = (int)SEQ_PTR(_4712);
            _4712 = (int)*(((s1_ptr)_2)->base + 2);
            Ref(_4712);
            DeRefDS(_0);
            if (binary_op_a(NOTEQ, _16next_task_id, _4712))
                goto L10;

            // 		    next_task_id = 0
            DeRef(_16next_task_id);
            _16next_task_id = 0;

            // 		    exit -- this id is still in use
            goto LF;
L10:

            // 	    end for
            _j = _j + 1;
            goto LE;
LF:
            ;
        }

        // 	    if next_task_id then
        if (_16next_task_id == 0) {
            goto L11;
        }
        else {
            if (!IS_ATOM_INT(_16next_task_id) && DBL_PTR(_16next_task_id)->dbl == 0.0)
                goto L11;
        }

        // 		exit -- found unused id for next time
        goto LD;
L11:

        // 	end for
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
        goto LC;
LD:
        ;
        DeRef(_i);
    }
LB:

    //     pc += 4
    _16pc = _16pc + 4;

    // end procedure
    DeRef(_new_entry);
    DeRef(_4712);
    DeRef(_4711);
    DeRef(_4706);
    return 0;
    ;
}


int _16opTASK_SCHEDULE()
{
    int _task;
    int _now = 0;
    int _s = 0;
    int _4791 = 0;
    int _4755 = 0;
    int _4744 = 0;
    int _0, _1, _2, _3;
    

    //     a = Code[pc+1]
    _4744 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4744);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    //     task = which_task(val[a])
    _2 = (int)SEQ_PTR(_16val);
    _4744 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4744);
    Ref(_4744);
    _task = _16which_task(_4744);

    //     b = Code[pc+2]
    DeRef(_4744);
    _4744 = _16pc + 2;
    _2 = (int)SEQ_PTR(_4Code);
    _16b = (int)*(((s1_ptr)_2)->base + _4744);
    if (!IS_ATOM_INT(_16b))
        _16b = (long)DBL_PTR(_16b)->dbl;

    //     s = val[b]
    _2 = (int)SEQ_PTR(_16val);
    _s = (int)*(((s1_ptr)_2)->base + _16b);
    Ref(_s);

    //     if atom(s) then
    _4744 = IS_ATOM(_s);
    if (_4744 == 0)
        goto L1;

    // 	if s <= 0 then
    if (binary_op_a(GREATER, _s, 0))
        goto L2;

    // 	    RTFatal("number of executions must be greater than 0")
    RefDS(_4753);
    _16RTFatal(_4753);
L2:

    // 	tcb[task][TASK_RUNS_MAX] = s   -- max execution count
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    Ref(_s);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _s;
    DeRef(_1);

    // 	if tcb[task][TASK_TYPE] = T_REAL_TIME then
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_16tcb);
    _4755 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4755);
    _0 = _4755;
    _2 = (int)SEQ_PTR(_4755);
    _4755 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4755);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4755, 1))
        goto L3;

    // 	    rt_first = task_delete(rt_first, task)
    _0 = _16task_delete(_16rt_first, _task);
    _16rt_first = _0;
    if (!IS_ATOM_INT(_16rt_first)) {
        _1 = (long)(DBL_PTR(_16rt_first)->dbl);
        DeRefDS(_16rt_first);
        _16rt_first = _1;
    }
L3:

    // 	if tcb[task][TASK_TYPE] = T_REAL_TIME or
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_16tcb);
    _4755 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4755);
    _0 = _4755;
    _2 = (int)SEQ_PTR(_4755);
    _4755 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4755);
    DeRefDS(_0);
    _0 = _4755;
    if (IS_ATOM_INT(_4755)) {
        _4755 = (_4755 == 1);
    }
    else {
        _4755 = binary_op(EQUALS, _4755, 1);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4755)) {
        if (_4755 != 0) {
            goto L4;
        }
    }
    else {
        if (DBL_PTR(_4755)->dbl != 0.0) {
            goto L4;
        }
    }
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_16tcb);
    _4744 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4744);
    _0 = _4744;
    _2 = (int)SEQ_PTR(_4744);
    _4744 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4744);
    DeRefDS(_0);
    _0 = _4744;
    if (IS_ATOM_INT(_4744)) {
        _4744 = (_4744 == 1);
    }
    else {
        _4744 = binary_op(EQUALS, _4744, 1);
    }
    DeRef(_0);
L5:
    if (_4744 == 0) {
        goto L6;
    }
    else {
        if (!IS_ATOM_INT(_4744) && DBL_PTR(_4744)->dbl == 0.0)
            goto L6;
    }
L4:

    // 	    ts_first = task_insert(ts_first, task)
    _0 = _16task_insert(_16ts_first, _task);
    _16ts_first = _0;
L6:

    // 	tcb[task][TASK_TYPE] = T_TIME_SHARE
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 2;
    DeRef(_1);
    goto L7;
L1:

    // 	if length(s) != 2 then
    DeRef(_4755);
    _4755 = SEQ_PTR(_s)->length;
    if (_4755 == 2)
        goto L8;

    // 	    RTFatal("second argument must be {min-time, max-time}")
    RefDS(_4772);
    _16RTFatal(_4772);
L8:

    // 	if sequence(s[1]) or sequence(s[2]) then
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4755);
    _0 = _4755;
    _4755 = IS_SEQUENCE(_4755);
    DeRef(_0);
    if (_4755 != 0) {
        goto L9;
    }
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_s);
    _4744 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4744);
    _0 = _4744;
    _4744 = IS_SEQUENCE(_4744);
    DeRef(_0);
LA:
    if (_4744 == 0)
        goto LB;
L9:

    // 	    RTFatal("min and max times must be atoms")
    RefDS(_4778);
    _16RTFatal(_4778);
LB:

    // 	if s[1] < 0 or s[2] < 0 then
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_s);
    _4744 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4744);
    _0 = _4744;
    if (IS_ATOM_INT(_4744)) {
        _4744 = (_4744 < 0);
    }
    else {
        _4744 = binary_op(LESS, _4744, 0);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4744)) {
        if (_4744 != 0) {
            goto LC;
        }
    }
    else {
        if (DBL_PTR(_4744)->dbl != 0.0) {
            goto LC;
        }
    }
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4755);
    _0 = _4755;
    if (IS_ATOM_INT(_4755)) {
        _4755 = (_4755 < 0);
    }
    else {
        _4755 = binary_op(LESS, _4755, 0);
    }
    DeRef(_0);
LD:
    if (_4755 == 0) {
        goto LE;
    }
    else {
        if (!IS_ATOM_INT(_4755) && DBL_PTR(_4755)->dbl == 0.0)
            goto LE;
    }
LC:

    // 	    RTFatal("min and max times must be greater than or equal to 0")
    RefDS(_4784);
    _16RTFatal(_4784);
LE:

    // 	if s[1] > s[2] then
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4755);
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_s);
    _4744 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4744);
    if (binary_op_a(LESSEQ, _4755, _4744))
        goto LF;

    // 	    RTFatal("task min time must be <= task max time")
    RefDS(_4788);
    _16RTFatal(_4788);
LF:

    // 	tcb[task][TASK_MIN_INC] = s[1]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    DeRef(_4791);
    _2 = (int)SEQ_PTR(_s);
    _4791 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4791);
    Ref(_4791);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 6);
    _1 = *(int *)_2;
    *(int *)_2 = _4791;
    DeRef(_1);

    // 	if s[1] < clock_period/2 then
    DeRef(_4791);
    _2 = (int)SEQ_PTR(_s);
    _4791 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4791);
    DeRef(_4755);
    if (IS_ATOM_INT(_16clock_period)) {
        if (_16clock_period & 1) {
            _4755 = NewDouble((_16clock_period >> 1) + 0.5);
        }
        else
            _4755 = _16clock_period >> 1;
    }
    else {
        _4755 = binary_op(DIVIDE, _16clock_period, 2);
    }
    if (binary_op_a(GREATEREQ, _4791, _4755))
        goto L10;

    // 	    if s[1] > 1.0e-9 then
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4755);
    if (binary_op_a(LESSEQ, _4755, _4796))
        goto L11;

    // 		tcb[task][TASK_RUNS_MAX] =  floor(clock_period / s[1])
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_s);
    _4744 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4744);
    _0 = _4744;
    if (IS_ATOM_INT(_16clock_period) && IS_ATOM_INT(_4744)) {
        if (_4744 > 0 && _16clock_period >= 0) {
            _4744 = _16clock_period / _4744;
        }
        else {
            temp_dbl = floor((double)_16clock_period / (double)_4744);
            if (_16clock_period != MININT)
                _4744 = (long)temp_dbl;
            else
                _4744 = NewDouble(temp_dbl);
        }
    }
    else {
        _2 = binary_op(DIVIDE, _16clock_period, _4744);
        _4744 = unary_op(FLOOR, _2);
        DeRef(_2);
    }
    DeRef(_0);
    Ref(_4744);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = _4744;
    DeRef(_1);
    goto L12;
L11:

    // 		tcb[task][TASK_RUNS_MAX] =  1000000000 -- arbitrary, large
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 1000000000;
    DeRef(_1);
L13:
    goto L12;
L10:

    // 	    tcb[task][TASK_RUNS_MAX] = 1
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 11);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L12:

    // 	tcb[task][TASK_MAX_INC] = s[2]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4755);
    Ref(_4755);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 7);
    _1 = *(int *)_2;
    *(int *)_2 = _4755;
    DeRef(_1);

    // 	now = time()
    DeRef(_now);
    _now = NewDouble(current_time());

    // 	tcb[task][TASK_MIN_TIME] = now + s[1]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    DeRef(_4744);
    _2 = (int)SEQ_PTR(_s);
    _4744 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4744);
    _0 = _4744;
    _4744 = binary_op(PLUS, _now, _4744);
    DeRef(_0);
    Ref(_4744);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 8);
    _1 = *(int *)_2;
    *(int *)_2 = _4744;
    DeRef(_1);

    // 	tcb[task][TASK_MAX_TIME] = now + s[2]
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_s);
    _4755 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4755);
    _0 = _4755;
    _4755 = binary_op(PLUS, _now, _4755);
    DeRef(_0);
    Ref(_4755);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 9);
    _1 = *(int *)_2;
    *(int *)_2 = _4755;
    DeRef(_1);

    // 	if tcb[task][TASK_TYPE] = T_TIME_SHARE then
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_16tcb);
    _4755 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4755);
    _0 = _4755;
    _2 = (int)SEQ_PTR(_4755);
    _4755 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4755);
    DeRefDS(_0);
    if (binary_op_a(NOTEQ, _4755, 2))
        goto L14;

    // 	    ts_first = task_delete(ts_first, task)
    _0 = _16task_delete(_16ts_first, _task);
    _16ts_first = _0;
    if (!IS_ATOM_INT(_16ts_first)) {
        _1 = (long)(DBL_PTR(_16ts_first)->dbl);
        DeRefDS(_16ts_first);
        _16ts_first = _1;
    }
L14:

    // 	if tcb[task][TASK_TYPE] = T_TIME_SHARE or
    DeRef(_4755);
    _2 = (int)SEQ_PTR(_16tcb);
    _4755 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4755);
    _0 = _4755;
    _2 = (int)SEQ_PTR(_4755);
    _4755 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4755);
    DeRefDS(_0);
    _0 = _4755;
    if (IS_ATOM_INT(_4755)) {
        _4755 = (_4755 == 2);
    }
    else {
        _4755 = binary_op(EQUALS, _4755, 2);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_4755)) {
        if (_4755 != 0) {
            goto L15;
        }
    }
    else {
        if (DBL_PTR(_4755)->dbl != 0.0) {
            goto L15;
        }
    }
    DeRef(_4791);
    _2 = (int)SEQ_PTR(_16tcb);
    _4791 = (int)*(((s1_ptr)_2)->base + _task);
    RefDS(_4791);
    _0 = _4791;
    _2 = (int)SEQ_PTR(_4791);
    _4791 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4791);
    DeRefDS(_0);
    _0 = _4791;
    if (IS_ATOM_INT(_4791)) {
        _4791 = (_4791 == 1);
    }
    else {
        _4791 = binary_op(EQUALS, _4791, 1);
    }
    DeRef(_0);
L16:
    if (_4791 == 0) {
        goto L17;
    }
    else {
        if (!IS_ATOM_INT(_4791) && DBL_PTR(_4791)->dbl == 0.0)
            goto L17;
    }
L15:

    // 	    rt_first = task_insert(rt_first, task)
    _0 = _16task_insert(_16rt_first, _task);
    _16rt_first = _0;
L17:

    // 	tcb[task][TASK_TYPE] = T_REAL_TIME
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 3);
    _1 = *(int *)_2;
    *(int *)_2 = 1;
    DeRef(_1);
L7:

    //     tcb[task][TASK_STATUS] = ST_ACTIVE
    _2 = (int)SEQ_PTR(_16tcb);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _16tcb = MAKE_SEQ(_2);
    }
    _3 = (int)(_task + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 4);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     pc += 3
    _16pc = _16pc + 3;

    // end procedure
    DeRef(_now);
    DeRef(_s);
    DeRef(_4791);
    DeRef(_4755);
    DeRef(_4744);
    return 0;
    ;
}


int _16one_trace_line(int _line)
{
    int _4836 = 0;
    int _0, _1, _2;
    

    //     if ELINUX then
    if (_4ELINUX == 0)
        goto L1;

    // 	printf(trace_file, "%-78.78s\n", {line})
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_line);
    *((int *)(_2+4)) = _line;
    _4836 = MAKE_SEQ(_1);
    EPrintf(_16trace_file, _4835, _4836);
    goto L2;
L1:

    // 	printf(trace_file, "%-77.77s\r\n", {line})
    _0 = _4836;
    _1 = NewS1(1);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_line);
    *((int *)(_2+4)) = _line;
    _4836 = MAKE_SEQ(_1);
    DeRef(_0);
    EPrintf(_16trace_file, _4837, _4836);
L2:

    // end procedure
    DeRefDS(_line);
    DeRef(_4836);
    return 0;
    ;
}


int _16opSTARTLINE()
{
    int _line = 0;
    int _w;
    int _4859 = 0;
    int _4839 = 0;
    int _0, _1, _2;
    

    //     if TraceOn then
    if (_16TraceOn == 0)
        goto L1;

    // 	if trace_file = -1 then
    if (_16trace_file != -1)
        goto L2;

    // 	    trace_file = open("ctrace.out", "wb")
    _16trace_file = EOpen(_4840, _4841);

    // 	    if trace_file = -1 then
    if (_16trace_file != -1)
        goto L3;

    // 		RTFatal("Couldn't open ctrace.out")
    RefDS(_4844);
    _16RTFatal(_4844);
L3:
L2:

    // 	a = Code[pc+1]
    DeRef(_4839);
    _4839 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _16a = (int)*(((s1_ptr)_2)->base + _4839);
    if (!IS_ATOM_INT(_16a))
        _16a = (long)DBL_PTR(_16a)->dbl;

    // 	if atom(slist[$]) then
    _4839 = SEQ_PTR(_4slist)->length;
    _2 = (int)SEQ_PTR(_4slist);
    _4839 = (int)*(((s1_ptr)_2)->base + _4839);
    Ref(_4839);
    _0 = _4839;
    _4839 = IS_ATOM(_4839);
    DeRef(_0);
    if (_4839 == 0)
        goto L4;

    // 	    slist = s_expand(slist)
    RefDS(_4slist);
    _0 = _11s_expand(_4slist);
    DeRefDS(_4slist);
    _4slist = _0;
L4:

    // 	line = fetch_line(slist[a][SRC])
    DeRef(_4839);
    _2 = (int)SEQ_PTR(_4slist);
    _4839 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4839);
    _0 = _4839;
    _2 = (int)SEQ_PTR(_4839);
    _4839 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_4839);
    DeRef(_0);
    Ref(_4839);
    _0 = _line;
    _line = _11fetch_line(_4839);
    DeRefi(_0);

    // 	line = sprintf("%s:%d\t%s",
    DeRef(_4839);
    _2 = (int)SEQ_PTR(_4slist);
    _4839 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4839);
    _0 = _4839;
    _2 = (int)SEQ_PTR(_4839);
    _4839 = (int)*(((s1_ptr)_2)->base + 3);
    Ref(_4839);
    DeRef(_0);
    _0 = _4839;
    _2 = (int)SEQ_PTR(_4file_name);
    if (!IS_ATOM_INT(_4839))
        _4839 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4839)->dbl));
    else
        _4839 = (int)*(((s1_ptr)_2)->base + _4839);
    RefDS(_4839);
    DeRef(_0);
    RefDS(_4839);
    _0 = _4839;
    _4839 = _10name_ext(_4839);
    DeRefDS(_0);
    DeRef(_4859);
    _2 = (int)SEQ_PTR(_4slist);
    _4859 = (int)*(((s1_ptr)_2)->base + _16a);
    Ref(_4859);
    _0 = _4859;
    _2 = (int)SEQ_PTR(_4859);
    _4859 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_4859);
    DeRef(_0);
    _0 = _4859;
    _1 = NewS1(3);
    _2 = (int)((s1_ptr)_1)->base;
    RefDS(_4839);
    *((int *)(_2+4)) = _4839;
    Ref(_4859);
    *((int *)(_2+8)) = _4859;
    RefDS(_line);
    *((int *)(_2+12)) = _line;
    _4859 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRefDSi(_line);
    _line = EPrintf(-9999999, _4854, _4859);

    // 	trace_line += 1
    _16trace_line = _16trace_line + 1;

    // 	if trace_line >= 500 then
    if (_16trace_line < 500)
        goto L5;

    // 	    trace_line = 0
    _16trace_line = 0;

    // 	    one_trace_line("")
    RefDS(_39);
    _16one_trace_line(_39);

    // 	    one_trace_line("               ")
    RefDS(_4865);
    _16one_trace_line(_4865);

    // 	    flush(trace_file)
    _12flush(_16trace_file);

    // 	    if seek(trace_file, 0) then
    _0 = _4859;
    _4859 = _12seek(_16trace_file, 0);
    DeRefDS(_0);
    if (_4859 == 0)
        goto L6;
L6:
L5:

    // 	one_trace_line(line)
    RefDS(_line);
    _16one_trace_line(_line);

    // 	one_trace_line("")
    RefDS(_39);
    _16one_trace_line(_39);

    // 	one_trace_line("=== THE END ===")
    RefDS(_4867);
    _16one_trace_line(_4867);

    // 	one_trace_line("")
    RefDS(_39);
    _16one_trace_line(_39);

    // 	one_trace_line("")
    RefDS(_39);
    _16one_trace_line(_39);

    // 	one_trace_line("")
    RefDS(_39);
    _16one_trace_line(_39);

    // 	flush(trace_file)
    _12flush(_16trace_file);

    // 	w = where(trace_file)
    _w = _12where(_16trace_file);
    if (!IS_ATOM_INT(_w)) {
        _1 = (long)(DBL_PTR(_w)->dbl);
        DeRefDS(_w);
        _w = _1;
    }

    // 	if seek(trace_file, w-79*5) then -- back up 5 (fixed-width) lines
    DeRef(_4859);
    _4859 = 395;
    _4859 = _w - 395;
    if ((long)((unsigned long)_4859 +(unsigned long) HIGH_BITS) >= 0)
        _4859 = NewDouble((double)_4859);
    Ref(_4859);
    _0 = _4859;
    _4859 = _12seek(_16trace_file, _4859);
    DeRef(_0);
    if (_4859 == 0)
        goto L7;
L7:
L1:

    //     pc += 2
    _16pc = _16pc + 2;

    // end procedure
    DeRefi(_line);
    DeRef(_4859);
    DeRef(_4839);
    return 0;
    ;
}


int _16opPROC()
{
    int _n;
    int _arg;
    int _sub;
    int _p;
    int _private_block = 0;
    int _4873 = 0;
    int _4886 = 0;
    int _0, _1, _2, _3;
    

    //     sub = Code[pc+1] -- subroutine
    _4873 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _4873);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     arg = SymTab[sub][S_NEXT] 
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _2 = (int)SEQ_PTR(_4873);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    //     n = SymTab[sub][S_NUM_ARGS]
    DeRefDS(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _2 = (int)SEQ_PTR(_4873);
    _n = (int)*(((s1_ptr)_2)->base + 20);
    if (!IS_ATOM_INT(_n))
        _n = (long)DBL_PTR(_n)->dbl;

    //     if SymTab[sub][S_RESIDENT_TASK] != 0 then
    DeRefDS(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _0 = _4873;
    _2 = (int)SEQ_PTR(_4873);
    _4873 = (int)*(((s1_ptr)_2)->base + 23);
    Ref(_4873);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4873, 0))
        goto L1;

    // 	private_block = repeat(0, SymTab[sub][S_STACK_SPACE])
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _0 = _4873;
    _2 = (int)SEQ_PTR(_4873);
    _4873 = (int)*(((s1_ptr)_2)->base + 25);
    Ref(_4873);
    DeRefDS(_0);
    _private_block = Repeat(0, _4873);

    // 	p = 1
    _p = 1;

    // 	for i = 1 to n do
    DeRef(_4873);
    _4873 = _n;
    { int _i;
        _i = 1;
L2:
        if (_i > _4873)
            goto L3;

        // 	    private_block[p] = val[arg]
        DeRef(_4886);
        _2 = (int)SEQ_PTR(_16val);
        _4886 = (int)*(((s1_ptr)_2)->base + _arg);
        Ref(_4886);
        Ref(_4886);
        _2 = (int)SEQ_PTR(_private_block);
        if (!UNIQUE(_2)) {
            _2 = (int)SequenceCopy((s1_ptr)_2);
            _private_block = MAKE_SEQ(_2);
        }
        _2 = (int)(((s1_ptr)_2)->base + _p);
        _1 = *(int *)_2;
        *(int *)_2 = _4886;
        DeRef(_1);

        // 	    p += 1
        _p = _p + 1;

        // 	    val[arg] = val[Code[pc+1+i]]
        DeRef(_4886);
        _4886 = _16pc + 1;
        if (_4886 > MAXINT)
            _4886 = NewDouble((double)_4886);
        _0 = _4886;
        if (IS_ATOM_INT(_4886)) {
            _4886 = _4886 + _i;
        }
        else {
            _4886 = NewDouble(DBL_PTR(_4886)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _4886;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_4886))
            _4886 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4886)->dbl));
        else
            _4886 = (int)*(((s1_ptr)_2)->base + _4886);
        Ref(_4886);
        DeRef(_0);
        _0 = _4886;
        _2 = (int)SEQ_PTR(_16val);
        if (!IS_ATOM_INT(_4886))
            _4886 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4886)->dbl));
        else
            _4886 = (int)*(((s1_ptr)_2)->base + _4886);
        Ref(_4886);
        DeRef(_0);
        Ref(_4886);
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _4886;
        DeRef(_1);

        // 	    arg = SymTab[arg][S_NEXT]
        DeRef(_4886);
        _2 = (int)SEQ_PTR(_4SymTab);
        _4886 = (int)*(((s1_ptr)_2)->base + _arg);
        RefDS(_4886);
        _2 = (int)SEQ_PTR(_4886);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 	end for
        _i = _i + 1;
        goto L2;
L3:
        ;
    }

    // 	while arg != 0 and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L4:
    DeRef(_4886);
    _4886 = (_arg != 0);
    if (_4886 == 0) {
        goto L5;
    }
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4873);
    _0 = _4873;
    _2 = (int)SEQ_PTR(_4873);
    _4873 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4873);
    DeRefDS(_0);
    _0 = _4873;
    if (IS_ATOM_INT(_4873)) {
        _4873 = (_4873 <= 3);
    }
    else {
        _4873 = binary_op(LESSEQ, _4873, 3);
    }
    DeRef(_0);
L6:
    if (_4873 <= 0) {
        if (_4873 == 0) {
            goto L5;
        }
        else {
            if (!IS_ATOM_INT(_4873) && DBL_PTR(_4873)->dbl == 0.0)
                goto L5;
        }
    }

    // 	    private_block[p] = val[arg]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_16val);
    _4873 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_4873);
    Ref(_4873);
    _2 = (int)SEQ_PTR(_private_block);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _private_block = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _4873;
    DeRef(_1);

    // 	    p += 1
    _p = _p + 1;

    // 	    val[arg] = NOVALUE  -- necessary?
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4873);
    _2 = (int)SEQ_PTR(_4873);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto L4;
L5:

    // 	arg = SymTab[sub][S_TEMPS]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _2 = (int)SEQ_PTR(_4873);
    _arg = (int)*(((s1_ptr)_2)->base + 18);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	while arg != 0 do
L7:
    if (_arg == 0)
        goto L8;

    // 	    private_block[p] = val[arg]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_16val);
    _4873 = (int)*(((s1_ptr)_2)->base + _arg);
    Ref(_4873);
    Ref(_4873);
    _2 = (int)SEQ_PTR(_private_block);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _private_block = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + _p);
    _1 = *(int *)_2;
    *(int *)_2 = _4873;
    DeRef(_1);

    // 	    p += 1
    _p = _p + 1;

    // 	    val[arg] = NOVALUE -- necessary?
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	    arg = SymTab[arg][S_NEXT]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4873);
    _2 = (int)SEQ_PTR(_4873);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    // 	end while
    goto L7;
L8:

    // 	save_private_block(sub, private_block)
    RefDS(_private_block);
    _16save_private_block(_sub, _private_block);
    goto L9;
L1:

    // 	for i = 1 to n do
    DeRef(_4873);
    _4873 = _n;
    { int _i;
        _i = 1;
LA:
        if (_i > _4873)
            goto LB;

        // 	    val[arg] = val[Code[pc+1+i]]
        DeRef(_4886);
        _4886 = _16pc + 1;
        if (_4886 > MAXINT)
            _4886 = NewDouble((double)_4886);
        _0 = _4886;
        if (IS_ATOM_INT(_4886)) {
            _4886 = _4886 + _i;
        }
        else {
            _4886 = NewDouble(DBL_PTR(_4886)->dbl + (double)_i);
        }
        DeRef(_0);
        _0 = _4886;
        _2 = (int)SEQ_PTR(_4Code);
        if (!IS_ATOM_INT(_4886))
            _4886 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4886)->dbl));
        else
            _4886 = (int)*(((s1_ptr)_2)->base + _4886);
        Ref(_4886);
        DeRef(_0);
        _0 = _4886;
        _2 = (int)SEQ_PTR(_16val);
        if (!IS_ATOM_INT(_4886))
            _4886 = (int)*(((s1_ptr)_2)->base + (int)(DBL_PTR(_4886)->dbl));
        else
            _4886 = (int)*(((s1_ptr)_2)->base + _4886);
        Ref(_4886);
        DeRef(_0);
        Ref(_4886);
        _2 = (int)SEQ_PTR(_16val);
        _2 = (int)(((s1_ptr)_2)->base + _arg);
        _1 = *(int *)_2;
        *(int *)_2 = _4886;
        DeRef(_1);

        // 	    arg = SymTab[arg][S_NEXT]
        DeRef(_4886);
        _2 = (int)SEQ_PTR(_4SymTab);
        _4886 = (int)*(((s1_ptr)_2)->base + _arg);
        RefDS(_4886);
        _2 = (int)SEQ_PTR(_4886);
        _arg = (int)*(((s1_ptr)_2)->base + 2);
        if (!IS_ATOM_INT(_arg))
            _arg = (long)DBL_PTR(_arg)->dbl;

        // 	end for
        _i = _i + 1;
        goto LA;
LB:
        ;
    }
L9:

    //     SymTab[sub][S_RESIDENT_TASK] = current_task
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = _16current_task;
    DeRef(_1);

    //     pc = pc + 2 + n
    DeRef(_4873);
    _4873 = _16pc + 2;
    if ((long)((unsigned long)_4873 + (unsigned long)HIGH_BITS) >= 0) 
        _4873 = NewDouble((double)_4873);
    if (IS_ATOM_INT(_4873)) {
        _16pc = _4873 + _n;
    }
    else {
        _16pc = NewDouble(DBL_PTR(_4873)->dbl + (double)_n);
    }
    if (!IS_ATOM_INT(_16pc)) {
        _1 = (long)(DBL_PTR(_16pc)->dbl);
        DeRefDS(_16pc);
        _16pc = _1;
    }

    //     if SymTab[sub][S_TOKEN] != PROC then
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    _0 = _4873;
    _2 = (int)SEQ_PTR(_4873);
    _4873 = (int)*(((s1_ptr)_2)->base + 9);
    Ref(_4873);
    DeRefDS(_0);
    if (binary_op_a(EQUALS, _4873, 27))
        goto LC;

    // 	pc += 1
    _16pc = _16pc + 1;
LC:

    //     call_stack = append(call_stack, pc) 
    Append(&_16call_stack, _16call_stack, _16pc);

    //     call_stack = append(call_stack, sub)
    Append(&_16call_stack, _16call_stack, _sub);

    //     Code = SymTab[sub][S_CODE]
    DeRef(_4873);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4873 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4873);
    DeRef(_4Code);
    _2 = (int)SEQ_PTR(_4873);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    //     pc = 1 
    _16pc = 1;

    // end procedure
    DeRef(_private_block);
    DeRefDS(_4873);
    DeRef(_4886);
    return 0;
    ;
}


int _16opRETURNP()
{
    int _arg;
    int _sub;
    int _caller;
    int _4929 = 0;
    int _4940 = 0;
    int _0, _1, _2, _3;
    

    //     sub = Code[pc+1]
    _4929 = _16pc + 1;
    _2 = (int)SEQ_PTR(_4Code);
    _sub = (int)*(((s1_ptr)_2)->base + _4929);
    if (!IS_ATOM_INT(_sub))
        _sub = (long)DBL_PTR(_sub)->dbl;

    //     pc = call_stack[$-1]
    _4929 = SEQ_PTR(_16call_stack)->length;
    _4929 = _4929 - 1;
    _2 = (int)SEQ_PTR(_16call_stack);
    _16pc = (int)*(((s1_ptr)_2)->base + _4929);
    if (!IS_ATOM_INT(_16pc))
        _16pc = (long)DBL_PTR(_16pc)->dbl;

    //     call_stack = call_stack[1..$-2]
    _4929 = SEQ_PTR(_16call_stack)->length;
    _4929 = _4929 - 2;
    rhs_slice_target = (object_ptr)&_16call_stack;
    RHS_Slice((s1_ptr)_16call_stack, 1, _4929);

    //     arg = SymTab[sub][S_NEXT]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4929 = (int)*(((s1_ptr)_2)->base + _sub);
    RefDS(_4929);
    _2 = (int)SEQ_PTR(_4929);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    //     while arg and SymTab[arg][S_SCOPE] <= SC_PRIVATE do
L1:
    if (_arg == 0) {
        goto L2;
    }
    DeRef(_4940);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4940 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4940);
    _0 = _4940;
    _2 = (int)SEQ_PTR(_4940);
    _4940 = (int)*(((s1_ptr)_2)->base + 4);
    Ref(_4940);
    DeRefDS(_0);
    _0 = _4940;
    if (IS_ATOM_INT(_4940)) {
        _4940 = (_4940 <= 3);
    }
    else {
        _4940 = binary_op(LESSEQ, _4940, 3);
    }
    DeRef(_0);
L3:
    if (_4940 <= 0) {
        if (_4940 == 0) {
            goto L2;
        }
        else {
            if (!IS_ATOM_INT(_4940) && DBL_PTR(_4940)->dbl == 0.0)
                goto L2;
        }
    }

    // 	val[arg] = NOVALUE
    RefDS(_4NOVALUE);
    _2 = (int)SEQ_PTR(_16val);
    _2 = (int)(((s1_ptr)_2)->base + _arg);
    _1 = *(int *)_2;
    *(int *)_2 = _4NOVALUE;
    DeRef(_1);

    // 	arg = SymTab[arg][S_NEXT]
    DeRef(_4940);
    _2 = (int)SEQ_PTR(_4SymTab);
    _4940 = (int)*(((s1_ptr)_2)->base + _arg);
    RefDS(_4940);
    _2 = (int)SEQ_PTR(_4940);
    _arg = (int)*(((s1_ptr)_2)->base + 2);
    if (!IS_ATOM_INT(_arg))
        _arg = (long)DBL_PTR(_arg)->dbl;

    //     end while
    goto L1;
L2:

    //     SymTab[sub][S_RESIDENT_TASK] = 0
    _2 = (int)SEQ_PTR(_4SymTab);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        _4SymTab = MAKE_SEQ(_2);
    }
    _3 = (int)(_sub + ((s1_ptr)_2)->base);
    _2 = (int)SEQ_PTR(*(int *)_3);
    if (!UNIQUE(_2)) {
        _2 = (int)SequenceCopy((s1_ptr)_2);
        *(int *)_3 = MAKE_SEQ(_2);
    }
    _2 = (int)(((s1_ptr)_2)->base + 23);
    _1 = *(int *)_2;
    *(int *)_2 = 0;
    DeRef(_1);

    //     if length(call_stack) then
    DeRef(_4929);
    _4929 = SEQ_PTR(_16call_stack)->length;
    if (_4929 == 0)
        goto L4;

    // 	caller = call_stack[$]
    _4929 = SEQ_PTR(_16call_stack)->length;
    _2 = (int)SEQ_PTR(_16call_stack);
    _caller = (int)*(((s1_ptr)_2)->base + _4929);
    if (!IS_ATOM_INT(_caller))
        _caller = (long)DBL_PTR(_caller)->dbl;

    // 	Code = SymTab[caller][S_CODE]
    _2 = (int)SEQ_PTR(_4SymTab);
    _4929 = (int)*(((s1_ptr)_2)->base + _caller);
    RefDS(_4929);
    DeRef(_4Code);
    _2 = (int)SEQ_PTR(_4929);
    _4Code = (int)*(((s1_ptr)_2)->base + 15);
    Ref(_4Code);

    // 	restore_privates(caller)
    _16restore_privates(_caller);

    // 	if result then
    if (_16result == 0)
        goto L5;

    // 	    val[Code[result]] = result_val
    DeRefDS(_4929);
    _2 = (int)SEQ_PTR(_4Code);
    _4929 = (int)*(((s1_ptr)_2)->base + _16result);
    Ref(_4929);
    Ref(_16result_val);
    _2 = (int)SEQ_PTR(_16val);
    if (!IS_ATOM_INT(_4929))
        _2 = (int)(((s1_ptr)_2)->base + (int)(DBL_PTR(_4929)->dbl));
    else
        _2 = (int)(((s1_ptr)_2)->base + _4929);
    _1 = *(int *)_2;
    *(int *)_2 = _16result_val;
    DeRef(_1);

    // 	    result = 0
    _16result = 0;
L6:
    goto L5;
L4:

    // 	kill_task(current_task)
    _16kill_task(_16current_task);

    // 	scheduler()
    _16scheduler();
L5:

    // end procedure
    DeRef(_4929);
    DeRef(_4940);
    return 0;
    ;
}


