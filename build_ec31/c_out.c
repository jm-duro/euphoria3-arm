// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _9c_putc(int _c)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_c)) {
        _1 = (long)(DBL_PTR(_c)->dbl);
        DeRefDS(_c);
        _c = _1;
    }

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	puts(c_code, c)
    EPuts(_9c_code, _c);
L1:

    // end procedure
    return 0;
    ;
}


int _9c_hputs(int _c_source)
{
    int _0, _1, _2;
    

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	puts(c_h, c_source)    
    EPuts(_9c_h, _c_source);
L1:

    // end procedure
    DeRefDS(_c_source);
    return 0;
    ;
}


int _9c_puts(int _c_source)
{
    int _0, _1, _2;
    

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	puts(c_code, c_source)
    EPuts(_9c_code, _c_source);
L1:

    // end procedure
    DeRefDS(_c_source);
    return 0;
    ;
}


int _9c_hprintf(int _format, int _value)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_value)) {
        _1 = (long)(DBL_PTR(_value)->dbl);
        DeRefDS(_value);
        _value = _1;
    }

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	printf(c_h, format, value)
    EPrintf(_9c_h, _format, _value);
L1:

    // end procedure
    DeRefDS(_format);
    return 0;
    ;
}


int _9c_printf(int _format, int _value)
{
    int _0, _1, _2;
    
    if (!IS_ATOM_INT(_value)) {
        _1 = (long)(DBL_PTR(_value)->dbl);
        DeRefDS(_value);
        _value = _1;
    }

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	printf(c_code, format, value)
    EPrintf(_9c_code, _format, _value);
L1:

    // end procedure
    DeRefDS(_format);
    return 0;
    ;
}


int _9c_printf8(int _value)
{
    int _buff = 0;
    int _neg;
    int _p;
    int _881;
    int _871;
    int _0, _1, _2;
    

    //     if emit_c_output then
    if (_9emit_c_output == 0)
        goto L1;

    // 	neg = 0
    _neg = 0;

    // 	buff = sprintf("%.16e", value)
    _buff = EPrintf(-9999999, _870, _value);

    // 	if length(buff) < 10 then
    _871 = SEQ_PTR(_buff)->length;
    if (_871 >= 10)
        goto L2;

    // 	    p = 1
    _p = 1;

    // 	    while p <= length(buff) do
L3:
    _871 = SEQ_PTR(_buff)->length;
    if (_p > _871)
        goto L4;

    // 		if buff[p] = '-' then
    _2 = (int)SEQ_PTR(_buff);
    _871 = (int)*(((s1_ptr)_2)->base + _p);
    if (_871 != 45)
        goto L5;

    // 		    neg = 1
    _neg = 1;
    goto L6;
L5:

    // 		elsif buff[p] = 'i' or buff[p] = 'I' then
    _2 = (int)SEQ_PTR(_buff);
    _871 = (int)*(((s1_ptr)_2)->base + _p);
    _871 = (_871 == 105);
    if (_871 != 0) {
        goto L7;
    }
    _2 = (int)SEQ_PTR(_buff);
    _881 = (int)*(((s1_ptr)_2)->base + _p);
    _881 = (_881 == 73);
L8:
    if (_881 == 0)
        goto L9;
L7:

    // 		    buff = CREATE_INF
    RefDS(_9CREATE_INF);
    DeRefi(_buff);
    _buff = _9CREATE_INF;

    // 		    if neg then
    if (_neg == 0)
        goto L4;

    // 			buff = prepend(buff, '-')
    Prepend(&_buff, _buff, 45);
LA:

    // 		    exit
    goto L4;
    goto L6;
L9:

    // 		elsif buff[p] = 'n' or buff[p] = 'N' then
    _2 = (int)SEQ_PTR(_buff);
    _881 = (int)*(((s1_ptr)_2)->base + _p);
    _881 = (_881 == 110);
    if (_881 != 0) {
        goto LB;
    }
    _2 = (int)SEQ_PTR(_buff);
    _871 = (int)*(((s1_ptr)_2)->base + _p);
    _871 = (_871 == 78);
LC:
    if (_871 == 0)
        goto LD;
LB:

    // 		    if ELINUX then
    if (_4ELINUX == 0)
        goto LE;

    // 			buff = CREATE_NAN1
    RefDS(_9CREATE_NAN1);
    DeRefi(_buff);
    _buff = _9CREATE_NAN1;

    // 			if neg then
    if (_neg == 0)
        goto LF;

    // 			    buff = prepend(buff, '-')
    Prepend(&_buff, _buff, 45);
L10:
    goto LF;
LE:

    // 			if sequence(wat_path) or sequence(bor_path) then
    _871 = IS_SEQUENCE(_4wat_path);
    if (_871 != 0) {
        goto L11;
    }
    _881 = IS_SEQUENCE(_4bor_path);
L12:
    if (_881 == 0)
        goto L13;
L11:

    // 			    buff = CREATE_NAN2
    RefDS(_9CREATE_NAN2);
    DeRefi(_buff);
    _buff = _9CREATE_NAN2;

    // 			    if not neg then
    if (_neg != 0)
        goto L4;

    // 				buff = prepend(buff, '-')
    Prepend(&_buff, _buff, 45);
L14:
    goto L4;
L13:

    // 			    buff = CREATE_NAN1
    RefDS(_9CREATE_NAN1);
    DeRefi(_buff);
    _buff = _9CREATE_NAN1;

    // 			    if neg then
    if (_neg == 0)
        goto L4;

    // 				buff = prepend(buff, '-')
    Prepend(&_buff, _buff, 45);
L15:
L16:

    // 			exit
    goto L4;
LF:
LD:
L6:

    // 		p += 1
    _p = _p + 1;

    // 	    end while
    goto L3;
L4:
L2:

    // 	puts(c_code, buff)
    EPuts(_9c_code, _buff);
L1:

    // end procedure
    DeRef(_value);
    DeRefi(_buff);
    return 0;
    ;
}


int _9adjust_indent_before(int _stmt)
{
    int _p;
    int _i;
    int _lb;
    int _rb;
    int _897;
    int _901 = 0;
    int _0, _1, _2;
    

    //     if not emit_c_output then
    if (_9emit_c_output != 0)
        goto L1;

    // 	return
    DeRefDS(_stmt);
    return 0;
L1:

    //     p = 1
    _p = 1;

    //     lb = FALSE
    _lb = 0;

    //     rb = FALSE
    _rb = 0;

    //     while p <= length(stmt) and stmt[p] != '\n' do
L2:
    _897 = SEQ_PTR(_stmt)->length;
    _897 = (_p <= _897);
    if (_897 == 0) {
        goto L3;
    }
    DeRef(_901);
    _2 = (int)SEQ_PTR(_stmt);
    _901 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_901);
    _0 = _901;
    if (IS_ATOM_INT(_901)) {
        _901 = (_901 != 10);
    }
    else {
        _901 = binary_op(NOTEQ, _901, 10);
    }
    DeRef(_0);
L4:
    if (_901 <= 0) {
        if (_901 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_901) && DBL_PTR(_901)->dbl == 0.0)
                goto L3;
        }
    }

    // 	if stmt[p] = '}' then
    DeRef(_901);
    _2 = (int)SEQ_PTR(_stmt);
    _901 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_901);
    if (binary_op_a(NOTEQ, _901, 125))
        goto L5;

    // 	    rb = TRUE
    _rb = 1;
    goto L6;
L5:

    // 	elsif stmt[p] = '{' then
    DeRef(_901);
    _2 = (int)SEQ_PTR(_stmt);
    _901 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_901);
    if (binary_op_a(NOTEQ, _901, 123))
        goto L7;

    // 	    lb = TRUE
    _lb = 1;
L7:
L6:

    // 	p += 1
    _p = _p + 1;

    //     end while
    goto L2;
L3:

    //     if rb and not lb then
    if (_rb == 0) {
        goto L8;
    }
    _897 = (_lb == 0);
L9:
    if (_897 == 0)
        goto L8;

    // 	indent -= 4
    _9indent = _9indent - 4;
L8:

    //     i = indent + temp_indent
    _i = _9indent + _9temp_indent;

    //     while i >= 4 do
LA:
    if (_i < 4)
        goto LB;

    // 	c_puts("    ")
    RefDS(_913);
    _9c_puts(_913);

    // 	i -= 4
    _i = _i - 4;

    //     end while
    goto LA;
LB:

    //     while i > 0 do 
LC:
    if (_i <= 0)
        goto LD;

    // 	c_putc(' ')
    _9c_putc(32);

    // 	i -= 1
    _i = _i - 1;

    //     end while
    goto LC;
LD:

    //     temp_indent = 0    
    _9temp_indent = 0;

    // end procedure
    DeRefDS(_stmt);
    DeRef(_901);
    return 0;
    ;
}


int _9adjust_indent_after(int _stmt)
{
    int _p;
    int _942 = 0;
    int _917 = 0;
    int _921 = 0;
    int _0, _1, _2;
    

    //     if not emit_c_output then
    if (_9emit_c_output != 0)
        goto L1;

    // 	return
    DeRefDS(_stmt);
    return 0;
L1:

    //     p = 1
    _p = 1;

    //     while p <= length(stmt) and stmt[p] != '\n' do
L2:
    DeRef(_917);
    _917 = SEQ_PTR(_stmt)->length;
    _917 = (_p <= _917);
    if (_917 == 0) {
        goto L3;
    }
    DeRef(_921);
    _2 = (int)SEQ_PTR(_stmt);
    _921 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_921);
    _0 = _921;
    if (IS_ATOM_INT(_921)) {
        _921 = (_921 != 10);
    }
    else {
        _921 = binary_op(NOTEQ, _921, 10);
    }
    DeRef(_0);
L4:
    if (_921 <= 0) {
        if (_921 == 0) {
            goto L3;
        }
        else {
            if (!IS_ATOM_INT(_921) && DBL_PTR(_921)->dbl == 0.0)
                goto L3;
        }
    }

    // 	if stmt[p] = '{' then
    DeRef(_921);
    _2 = (int)SEQ_PTR(_stmt);
    _921 = (int)*(((s1_ptr)_2)->base + _p);
    Ref(_921);
    if (binary_op_a(NOTEQ, _921, 123))
        goto L5;

    // 	    indent += 4
    _9indent = _9indent + 4;

    // 	    return
    DeRefDS(_stmt);
    DeRef(_942);
    DeRef(_917);
    DeRef(_921);
    return 0;
L5:

    // 	p += 1
    _p = _p + 1;

    //     end while
    goto L2;
L3:

    //     if length(stmt) >= 3 and equal("if ", stmt[1..3]) then
    DeRef(_921);
    _921 = SEQ_PTR(_stmt)->length;
    _921 = (_921 >= 3);
    if (_921 == 0) {
        goto L6;
    }
    rhs_slice_target = (object_ptr)&_917;
    RHS_Slice((s1_ptr)_stmt, 1, 3);
    _0 = _917;
    if (_930 == _917)
        _917 = 1;
    else if (IS_ATOM_INT(_930) && IS_ATOM_INT(_917))
        _917 = 0;
    else
        _917 = (compare(_930, _917) == 0);
    DeRefDS(_0);
L7:
    if (_917 == 0)
        goto L6;

    // 	temp_indent = 4
    _9temp_indent = 4;
    goto L8;
L6:

    //     elsif length(stmt) >= 5 and equal("else", stmt[1..4]) and
    DeRef(_917);
    _917 = SEQ_PTR(_stmt)->length;
    _917 = (_917 >= 5);
    if (_917 == 0) {
        _917 = 0;
        goto L9;
    }
    rhs_slice_target = (object_ptr)&_921;
    RHS_Slice((s1_ptr)_stmt, 1, 4);
    _0 = _921;
    if (_668 == _921)
        _921 = 1;
    else if (IS_ATOM_INT(_668) && IS_ATOM_INT(_921))
        _921 = 0;
    else
        _921 = (compare(_668, _921) == 0);
    DeRefDS(_0);
    _917 = (_921 != 0);
L9:
    if (_917 == 0) {
        goto LA;
    }
    DeRef(_917);
    _2 = (int)SEQ_PTR(_stmt);
    _917 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_917);
    _0 = _917;
    if (IS_ATOM_INT(_917)) {
        _917 = (_917 == 32);
    }
    else {
        _917 = binary_op(EQUALS, _917, 32);
    }
    DeRef(_0);
    if (IS_ATOM_INT(_917)) {
        if (_917 != 0) {
            DeRef(_917);
            _917 = 1;
            goto LB;
        }
    }
    else {
        if (DBL_PTR(_917)->dbl != 0.0) {
            DeRef(_917);
            _917 = 1;
            goto LB;
        }
    }
    DeRef(_942);
    _2 = (int)SEQ_PTR(_stmt);
    _942 = (int)*(((s1_ptr)_2)->base + 5);
    Ref(_942);
    _0 = _942;
    if (IS_ATOM_INT(_942)) {
        _942 = (_942 == 10);
    }
    else {
        _942 = binary_op(EQUALS, _942, 10);
    }
    DeRef(_0);
    DeRef(_917);
    if (IS_ATOM_INT(_942))
        _917 = (_942 != 0);
    else
        _917 = DBL_PTR(_942)->dbl != 0.0;
LB:
LC:
    if (_917 == 0)
        goto LA;

    // 	temp_indent = 4
    _9temp_indent = 4;
LA:
L8:

    // end procedure
    DeRefDS(_stmt);
    DeRef(_942);
    DeRef(_917);
    DeRef(_921);
    return 0;
    ;
}


