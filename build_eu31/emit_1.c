// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _14emit_assign_op(int _op)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_op)) {
        _1 = (long)(DBL_PTR(_op)->dbl);
        DeRefDS(_op);
        _op = _1;
    }

    //     if op = PLUS_EQUALS then
    if (_op != 518)
        goto L1;

    // 	emit_op(PLUS)
    _14emit_op(11);
    goto L2;
L1:

    //     elsif op = MINUS_EQUALS then
    if (_op != 519)
        goto L3;

    // 	emit_op(MINUS)
    _14emit_op(10);
    goto L2;
L3:

    //     elsif op = MULTIPLY_EQUALS then 
    if (_op != 520)
        goto L4;

    // 	emit_op(MULTIPLY)
    _14emit_op(13);
    goto L2;
L4:

    //     elsif op = DIVIDE_EQUALS then 
    if (_op != 521)
        goto L5;

    // 	emit_op(DIVIDE)
    _14emit_op(14);
    goto L2;
L5:

    //     elsif op = CONCAT_EQUALS then
    if (_op != 522)
        goto L6;

    // 	emit_op(CONCAT)
    _14emit_op(15);
L6:
L2:

    // end procedure
    return 0;
    ;
}


int _14StartSourceLine(int _sl)
{
    int _line_span;
    int _2958;
    int _2957;
    int _2946 = 0;
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_sl)) {
        _1 = (long)(DBL_PTR(_sl)->dbl);
        DeRefDS(_sl);
        _sl = _1;
    }

    //     if gline_number = LastLineNumber then
    if (_4gline_number != _11LastLineNumber)
        goto L1;

    // 	if length(LineTable) then
    _2946 = SEQ_PTR(_4LineTable)->length;
    if (_2946 == 0)
        goto L2;

    // 	    return -- ignore duplicates 
    return 0;
    goto L3;
L2:

    // 	    sl = FALSE -- top-level new statement to execute on same line
    _sl = 0;
L3:
L1:

    //     LastLineNumber = gline_number
    _11LastLineNumber = _4gline_number;

    //     line_span = gline_number - SymTab[CurrentSub][S_FIRSTLINE]
    DeRef(_2946);
    _2 = (int)SEQ_PTR(_4SymTab);
    _2946 = (int)*(((s1_ptr)_2)->base + _4CurrentSub);
    RefDS(_2946);
    _0 = _2946;
    _2 = (int)SEQ_PTR(_2946);
    _2946 = (int)*(((s1_ptr)_2)->base + 17);
    Ref(_2946);
    DeRefDS(_0);
    if (IS_ATOM_INT(_2946)) {
        _line_span = _4gline_number - _2946;
    }
    else {
        _line_span = binary_op(MINUS, _4gline_number, _2946);
    }
    if (!IS_ATOM_INT(_line_span)) {
        _1 = (long)(DBL_PTR(_line_span)->dbl);
        DeRefDS(_line_span);
        _line_span = _1;
    }

    //     while length(LineTable) < line_span do
L4:
    DeRef(_2946);
    _2946 = SEQ_PTR(_4LineTable)->length;
    if (_2946 >= _line_span)
        goto L5;

    // 	LineTable = append(LineTable, -1) -- filler
    Append(&_4LineTable, _4LineTable, -1);

    //     end while
    goto L4;
L5:

    //     LineTable = append(LineTable, length(Code))
    DeRef(_2946);
    _2946 = SEQ_PTR(_4Code)->length;
    Append(&_4LineTable, _4LineTable, _2946);

    //     if sl and (TRANSLATE or (OpTrace or OpProfileStatement)) then
    if (_sl == 0) {
        goto L6;
    }
    if (0 != 0) {
        _2957 = 1;
        goto L7;
    }
    if (_4OpTrace != 0) {
        _2958 = 1;
        goto L8;
    }
    _2958 = (_4OpProfileStatement != 0);
L8:
    _2957 = (_2958 != 0);
L7:
L9:
    if (_2957 == 0)
        goto L6;

    // 	emit_op(STARTLINE)
    _14emit_op(58);

    // 	emit_addr(gline_number)
    _14emit_addr(_4gline_number);
L6:

    // end procedure
    DeRef(_2946);
    return 0;
    ;
}


