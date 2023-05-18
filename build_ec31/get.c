// Euphoria To C version 3.1.1
#include "euphoria.h"
#include "main-.h"

int _20get_ch()
{
    int _10598;
    int _0, _1, _2;
    

    //     if sequence(input_string) then
    _10598 = 1;
    if (_10598 == 0)
        goto L1;

    // 	if string_next <= length(input_string) then
    _10598 = SEQ_PTR(_20input_string)->length;
    if (_20string_next > _10598)
        goto L2;

    // 	    ch = input_string[string_next]
    _2 = (int)SEQ_PTR(_20input_string);
    _20ch = (int)*(((s1_ptr)_2)->base + _20string_next);
    if (!IS_ATOM_INT(_20ch))
        _20ch = (long)DBL_PTR(_20ch)->dbl;

    // 	    string_next += 1
    _20string_next = _20string_next + 1;
    goto L3;
L2:

    // 	    ch = GET_EOF
    _20ch = -1;
L4:
    goto L3;
L1:

    // 	ch = getc(input_file)
    if (_20input_file != last_r_file_no) {
        last_r_file_ptr = which_file(_20input_file, EF_READ);
        last_r_file_no = _20input_file;
    }
    if (last_r_file_ptr == xstdin) {
        if (in_from_keyb) {
            _20ch = getc(xstdin);
        }
        else
            _20ch = getc(last_r_file_ptr);
    }
    else
        _20ch = getc(last_r_file_ptr);
L3:

    // end procedure
    return 0;
    ;
}


int _20skip_blanks()
{
    int _10605;
    int _0, _1, _2;
    

    //     while find(ch, " \t\n\r") do
L1:
    _10605 = find(_20ch, _10604);
    if (_10605 == 0)
        goto L2;

    // 	get_ch()
    _20get_ch();

    //     end while
    goto L1;
L2:

    // end procedure
    return 0;
    ;
}


int _20escape_char(int _c)
{
    int _i;
    int _10608;
    int _0, _1, _2;
    

    //     i = find(c, ESCAPE_CHARS)
    _i = find(_c, _20ESCAPE_CHARS);

    //     if i = 0 then
    if (_i != 0)
        goto L1;

    // 	return GET_FAIL
    return 1;
    goto L2;
L1:

    // 	return ESCAPED_CHARS[i]
    _2 = (int)SEQ_PTR(_20ESCAPED_CHARS);
    _10608 = (int)*(((s1_ptr)_2)->base + _i);
    return _10608;
L2:
    ;
}


int _20get_qchar()
{
    int _c;
    int _10611 = 0;
    int _0, _1, _2;
    

    //     get_ch()
    _20get_ch();

    //     c = ch
    _c = _20ch;

    //     if ch = '\\' then
    if (_20ch != 92)
        goto L1;

    // 	get_ch()
    _20get_ch();

    // 	c = escape_char(ch)
    _c = _20escape_char(_20ch);

    // 	if c = GET_FAIL then
    if (_c != 1)
        goto L2;

    // 	    return {GET_FAIL, 0}
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10611 = MAKE_SEQ(_1);
    return _10611;
L3:
    goto L2;
L1:

    //     elsif ch = '\'' then
    if (_20ch != 39)
        goto L4;

    // 	return {GET_FAIL, 0}
    DeRef(_10611);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10611 = MAKE_SEQ(_1);
    return _10611;
L4:
L2:

    //     get_ch()
    _20get_ch();

    //     if ch != '\'' then
    if (_20ch == 39)
        goto L5;

    // 	return {GET_FAIL, 0}
    DeRef(_10611);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10611 = MAKE_SEQ(_1);
    return _10611;
    goto L6;
L5:

    // 	get_ch()
    _20get_ch();

    // 	return {GET_SUCCESS, c}
    DeRef(_10611);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _c;
    _10611 = MAKE_SEQ(_1);
    return _10611;
L6:
    ;
}


int _20get_string()
{
    int _text = 0;
    int _10622 = 0;
    int _10620;
    int _0, _1, _2;
    

    //     text = ""
    RefDS(_39);
    _text = _39;

    //     while TRUE do
L1:

    // 	get_ch()
    _20get_ch();

    // 	if ch = GET_EOF or ch = '\n' then
    _10620 = (_20ch == -1);
    if (_10620 != 0) {
        goto L2;
    }
    DeRef(_10622);
    _10622 = (_20ch == 10);
L3:
    if (_10622 == 0)
        goto L4;
L2:

    // 	    return {GET_FAIL, 0}
    DeRef(_10622);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10622 = MAKE_SEQ(_1);
    DeRefi(_text);
    return _10622;
    goto L5;
L4:

    // 	elsif ch = '"' then
    if (_20ch != 34)
        goto L6;

    // 	    get_ch()
    _20get_ch();

    // 	    return {GET_SUCCESS, text}
    DeRef(_10622);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _text;
    RefDS(_text);
    _10622 = MAKE_SEQ(_1);
    DeRefDSi(_text);
    return _10622;
    goto L5;
L6:

    // 	elsif ch = '\\' then
    if (_20ch != 92)
        goto L7;

    // 	    get_ch()
    _20get_ch();

    // 	    ch = escape_char(ch)
    _0 = _20escape_char(_20ch);
    _20ch = _0;

    // 	    if ch = GET_FAIL then
    if (_20ch != 1)
        goto L8;

    // 		return {GET_FAIL, 0}
    DeRef(_10622);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10622 = MAKE_SEQ(_1);
    DeRefi(_text);
    return _10622;
L8:
L7:
L5:

    // 	text = text & ch
    Append(&_text, _text, _20ch);

    //     end while
    goto L1;
L9:
    ;
}


int _20get_number()
{
    int _sign;
    int _e_sign;
    int _ndigits;
    int _hex_digit;
    int _mantissa = 0;
    int _dec = 0;
    int _e_mag = 0;
    int _10649 = 0;
    int _10634 = 0;
    int _0, _1, _2;
    

    //     sign = +1
    _sign = 1;

    //     mantissa = 0
    _mantissa = 0;

    //     ndigits = 0
    _ndigits = 0;

    //     if ch = '-' then
    if (_20ch != 45)
        goto L1;

    // 	sign = -1
    _sign = -1;

    // 	get_ch()
    _20get_ch();
    goto L2;
L1:

    //     elsif ch = '+' then
    if (_20ch != 43)
        goto L3;

    // 	get_ch()
    _20get_ch();
L3:
L2:

    //     if ch = '#' then
    if (_20ch != 35)
        goto L4;

    // 	get_ch()
    _20get_ch();

    // 	while TRUE do
L5:

    // 	    hex_digit = find(ch, HEX_DIGITS)-1
    DeRef(_10634);
    _10634 = find(_20ch, _20HEX_DIGITS);
    _hex_digit = _10634 - 1;

    // 	    if hex_digit >= 0 then
    if (_hex_digit < 0)
        goto L6;

    // 		ndigits += 1
    _ndigits = _ndigits + 1;

    // 		mantissa = mantissa * 16 + hex_digit
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa == (short)_mantissa)
            _10634 = _mantissa * 16;
        else
            _10634 = NewDouble(_mantissa * (double)16);
    }
    else {
        _10634 = NewDouble(DBL_PTR(_mantissa)->dbl * (double)16);
    }
    DeRef(_mantissa);
    if (IS_ATOM_INT(_10634)) {
        _mantissa = _10634 + _hex_digit;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        _mantissa = NewDouble(DBL_PTR(_10634)->dbl + (double)_hex_digit);
    }

    // 		get_ch()
    _20get_ch();
    goto L5;
L6:

    // 		if ndigits > 0 then
    if (_ndigits <= 0)
        goto L7;

    // 		    return {GET_SUCCESS, sign * mantissa}
    DeRef(_10634);
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa <= INT15 && _mantissa >= -INT15)
            _10634 = _sign * _mantissa;
        else
            _10634 = NewDouble(_sign * (double)_mantissa);
    }
    else {
        _10634 = NewDouble((double)_sign * DBL_PTR(_mantissa)->dbl);
    }
    _0 = _10634;
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _10634;
    Ref(_10634);
    _10634 = MAKE_SEQ(_1);
    DeRef(_0);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_10649);
    return _10634;
    goto L5;
L7:

    // 		    return {GET_FAIL, 0}
    DeRef(_10634);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10634 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_10649);
    return _10634;
L8:
L9:

    // 	end while       
    goto L5;
LA:
L4:

    //     while ch >= '0' and ch <= '9' do
LB:
    DeRef(_10634);
    _10634 = (_20ch >= 48);
    if (_10634 == 0) {
        goto LC;
    }
    DeRef(_10649);
    _10649 = (_20ch <= 57);
LD:
    if (_10649 == 0)
        goto LC;

    // 	ndigits += 1
    _ndigits = _ndigits + 1;

    // 	mantissa = mantissa * 10 + (ch - '0')
    DeRef(_10649);
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa == (short)_mantissa)
            _10649 = _mantissa * 10;
        else
            _10649 = NewDouble(_mantissa * (double)10);
    }
    else {
        _10649 = NewDouble(DBL_PTR(_mantissa)->dbl * (double)10);
    }
    DeRef(_10634);
    _10634 = _20ch - 48;
    if ((long)((unsigned long)_10634 +(unsigned long) HIGH_BITS) >= 0)
        _10634 = NewDouble((double)_10634);
    DeRef(_mantissa);
    if (IS_ATOM_INT(_10649) && IS_ATOM_INT(_10634)) {
        _mantissa = _10649 + _10634;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        if (IS_ATOM_INT(_10649)) {
            _mantissa = NewDouble((double)_10649 + DBL_PTR(_10634)->dbl);
        }
        else {
            if (IS_ATOM_INT(_10634)) {
                _mantissa = NewDouble(DBL_PTR(_10649)->dbl + (double)_10634);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_10649)->dbl + DBL_PTR(_10634)->dbl);
        }
    }

    // 	get_ch()
    _20get_ch();

    //     end while
    goto LB;
LC:

    //     if ch = '.' then
    if (_20ch != 46)
        goto LE;

    // 	get_ch()
    _20get_ch();

    // 	dec = 10
    DeRef(_dec);
    _dec = 10;

    // 	while ch >= '0' and ch <= '9' do
LF:
    DeRef(_10634);
    _10634 = (_20ch >= 48);
    if (_10634 == 0) {
        goto L10;
    }
    DeRef(_10649);
    _10649 = (_20ch <= 57);
L11:
    if (_10649 == 0)
        goto L10;

    // 	    ndigits += 1
    _ndigits = _ndigits + 1;

    // 	    mantissa += (ch - '0') / dec
    DeRef(_10649);
    _10649 = _20ch - 48;
    if ((long)((unsigned long)_10649 +(unsigned long) HIGH_BITS) >= 0)
        _10649 = NewDouble((double)_10649);
    _0 = _10649;
    if (IS_ATOM_INT(_10649) && IS_ATOM_INT(_dec)) {
        _10649 = (_10649 % _dec) ? NewDouble((double)_10649 / _dec) : (_10649 / _dec);
    }
    else {
        if (IS_ATOM_INT(_10649)) {
            _10649 = NewDouble((double)_10649 / DBL_PTR(_dec)->dbl);
        }
        else {
            if (IS_ATOM_INT(_dec)) {
                _10649 = NewDouble(DBL_PTR(_10649)->dbl / (double)_dec);
            }
            else
                _10649 = NewDouble(DBL_PTR(_10649)->dbl / DBL_PTR(_dec)->dbl);
        }
    }
    DeRef(_0);
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_10649)) {
        _mantissa = _mantissa + _10649;
        if ((long)((unsigned long)_mantissa + (unsigned long)HIGH_BITS) >= 0) 
            _mantissa = NewDouble((double)_mantissa);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa + DBL_PTR(_10649)->dbl);
        }
        else {
            if (IS_ATOM_INT(_10649)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + (double)_10649);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl + DBL_PTR(_10649)->dbl);
        }
    }
    DeRef(_0);

    // 	    dec *= 10
    _0 = _dec;
    if (IS_ATOM_INT(_dec)) {
        if (_dec == (short)_dec)
            _dec = _dec * 10;
        else
            _dec = NewDouble(_dec * (double)10);
    }
    else {
        _dec = NewDouble(DBL_PTR(_dec)->dbl * (double)10);
    }
    DeRef(_0);

    // 	    get_ch()
    _20get_ch();

    // 	end while
    goto LF;
L10:
LE:

    //     if ndigits = 0 then
    if (_ndigits != 0)
        goto L12;

    // 	return {GET_FAIL, 0}
    DeRef(_10649);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10649 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_10634);
    return _10649;
L12:

    //     mantissa = sign * mantissa
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa)) {
        if (_mantissa <= INT15 && _mantissa >= -INT15)
            _mantissa = _sign * _mantissa;
        else
            _mantissa = NewDouble(_sign * (double)_mantissa);
    }
    else {
        _mantissa = NewDouble((double)_sign * DBL_PTR(_mantissa)->dbl);
    }
    DeRef(_0);

    //     if ch = 'e' or ch = 'E' then
    DeRef(_10649);
    _10649 = (_20ch == 101);
    if (_10649 != 0) {
        goto L13;
    }
    DeRef(_10634);
    _10634 = (_20ch == 69);
L14:
    if (_10634 == 0)
        goto L15;
L13:

    // 	e_sign = +1
    _e_sign = 1;

    // 	e_mag = 0
    DeRef(_e_mag);
    _e_mag = 0;

    // 	get_ch()
    _20get_ch();

    // 	if ch = '-' then
    if (_20ch != 45)
        goto L16;

    // 	    e_sign = -1
    _e_sign = -1;

    // 	    get_ch()
    _20get_ch();
    goto L17;
L16:

    // 	elsif ch = '+' then
    if (_20ch != 43)
        goto L18;

    // 	    get_ch()
    _20get_ch();
L18:
L17:

    // 	if ch >= '0' and ch <= '9' then
    DeRef(_10634);
    _10634 = (_20ch >= 48);
    if (_10634 == 0) {
        goto L19;
    }
    DeRef(_10649);
    _10649 = (_20ch <= 57);
L1A:
    if (_10649 == 0)
        goto L19;

    // 	    e_mag = ch - '0'
    DeRef(_e_mag);
    _e_mag = _20ch - 48;
    if ((long)((unsigned long)_e_mag +(unsigned long) HIGH_BITS) >= 0)
        _e_mag = NewDouble((double)_e_mag);

    // 	    get_ch()
    _20get_ch();

    // 	    while ch >= '0' and ch <= '9' do
L1B:
    DeRef(_10649);
    _10649 = (_20ch >= 48);
    if (_10649 == 0) {
        goto L1C;
    }
    DeRef(_10634);
    _10634 = (_20ch <= 57);
L1D:
    if (_10634 == 0)
        goto L1C;

    // 		e_mag = e_mag * 10 + ch - '0'
    DeRef(_10634);
    if (IS_ATOM_INT(_e_mag)) {
        if (_e_mag == (short)_e_mag)
            _10634 = _e_mag * 10;
        else
            _10634 = NewDouble(_e_mag * (double)10);
    }
    else {
        _10634 = NewDouble(DBL_PTR(_e_mag)->dbl * (double)10);
    }
    _0 = _10634;
    if (IS_ATOM_INT(_10634)) {
        _10634 = _10634 + _20ch;
        if ((long)((unsigned long)_10634 + (unsigned long)HIGH_BITS) >= 0) 
            _10634 = NewDouble((double)_10634);
    }
    else {
        _10634 = NewDouble(DBL_PTR(_10634)->dbl + (double)_20ch);
    }
    DeRef(_0);
    DeRef(_e_mag);
    if (IS_ATOM_INT(_10634)) {
        _e_mag = _10634 - 48;
        if ((long)((unsigned long)_e_mag +(unsigned long) HIGH_BITS) >= 0)
            _e_mag = NewDouble((double)_e_mag);
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_10634)->dbl - (double)48);
    }

    // 		get_ch()                          
    _20get_ch();

    // 	    end while
    goto L1B;
L1E:
    goto L1C;
L19:

    // 	    return {GET_FAIL, 0} -- no exponent
    DeRef(_10634);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10634 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_10649);
    return _10634;
L1C:

    // 	e_mag *= e_sign 
    _0 = _e_mag;
    if (IS_ATOM_INT(_e_mag)) {
        if (_e_mag == (short)_e_mag)
            _e_mag = _e_mag * _e_sign;
        else
            _e_mag = NewDouble(_e_mag * (double)_e_sign);
    }
    else {
        _e_mag = NewDouble(DBL_PTR(_e_mag)->dbl * (double)_e_sign);
    }
    DeRef(_0);

    // 	if e_mag > 308 then
    if (binary_op_a(LESSEQ, _e_mag, 308))
        goto L1F;

    // 	    mantissa *= power(10, 308)
    DeRef(_10634);
    _10634 = power(10, 308);
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_10634)) {
        if (_mantissa == (short)_mantissa && _10634 <= INT15 && _10634 >= -INT15)
            _mantissa = _mantissa * _10634;
        else
            _mantissa = NewDouble(_mantissa * (double)_10634);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa * DBL_PTR(_10634)->dbl);
        }
        else {
            if (IS_ATOM_INT(_10634)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)_10634);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_10634)->dbl);
        }
    }
    DeRef(_0);

    // 	    if e_mag > 1000 then
    if (binary_op_a(LESSEQ, _e_mag, 1000))
        goto L20;

    // 		e_mag = 1000 
    DeRef(_e_mag);
    _e_mag = 1000;
L20:

    // 	    for i = 1 to e_mag - 308 do
    DeRef(_10634);
    if (IS_ATOM_INT(_e_mag)) {
        _10634 = _e_mag - 308;
        if ((long)((unsigned long)_10634 +(unsigned long) HIGH_BITS) >= 0)
            _10634 = NewDouble((double)_10634);
    }
    else {
        _10634 = NewDouble(DBL_PTR(_e_mag)->dbl - (double)308);
    }
    { int _i;
        _i = 1;
L21:
        if (binary_op_a(GREATER, _i, _10634))
            goto L22;

        // 		mantissa *= 10
        _0 = _mantissa;
        if (IS_ATOM_INT(_mantissa)) {
            if (_mantissa == (short)_mantissa)
                _mantissa = _mantissa * 10;
            else
                _mantissa = NewDouble(_mantissa * (double)10);
        }
        else {
            _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)10);
        }
        DeRef(_0);

        // 	    end for
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
        goto L21;
L22:
        ;
        DeRef(_i);
    }
    goto L23;
L1F:

    // 	    mantissa *= power(10, e_mag)
    DeRef(_10649);
    if (IS_ATOM_INT(_e_mag)) {
        _10649 = power(10, _e_mag);
    }
    else {
        temp_d.dbl = (double)10;
        _10649 = Dpower(&temp_d, DBL_PTR(_e_mag));
    }
    _0 = _mantissa;
    if (IS_ATOM_INT(_mantissa) && IS_ATOM_INT(_10649)) {
        if (_mantissa == (short)_mantissa && _10649 <= INT15 && _10649 >= -INT15)
            _mantissa = _mantissa * _10649;
        else
            _mantissa = NewDouble(_mantissa * (double)_10649);
    }
    else {
        if (IS_ATOM_INT(_mantissa)) {
            _mantissa = NewDouble((double)_mantissa * DBL_PTR(_10649)->dbl);
        }
        else {
            if (IS_ATOM_INT(_10649)) {
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * (double)_10649);
            }
            else
                _mantissa = NewDouble(DBL_PTR(_mantissa)->dbl * DBL_PTR(_10649)->dbl);
        }
    }
    DeRef(_0);
L23:
L15:

    //     return {GET_SUCCESS, mantissa}
    DeRef(_10649);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _mantissa;
    Ref(_mantissa);
    _10649 = MAKE_SEQ(_1);
    DeRef(_mantissa);
    DeRef(_dec);
    DeRef(_e_mag);
    DeRef(_10634);
    return _10649;
    ;
}


int _20Get()
{
    int _s = 0;
    int _e = 0;
    int _10692 = 0;
    int _0, _1, _2;
    

    //     skip_blanks()
    _20skip_blanks();

    //     if find(ch, START_NUMERIC) then
    _10692 = find(_20ch, _20START_NUMERIC);
    if (_10692 == 0)
        goto L1;

    // 	return get_number()
    _10692 = _20get_number();
    return _10692;
    goto L2;
L1:

    //     elsif ch = '{' then
    if (_20ch != 123)
        goto L3;

    // 	s = {}
    RefDS(_39);
    DeRef(_s);
    _s = _39;

    // 	get_ch()
    _20get_ch();

    // 	skip_blanks()
    _20skip_blanks();

    // 	if ch = '}' then
    if (_20ch != 125)
        goto L4;

    // 	    get_ch()
    _20get_ch();

    // 	    return {GET_SUCCESS, s} -- empty sequence
    DeRef(_10692);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _s;
    RefDS(_s);
    _10692 = MAKE_SEQ(_1);
    DeRefDS(_s);
    DeRef(_e);
    return _10692;
L4:

    // 	while TRUE do
L5:

    // 	    e = Get() -- read next element
    _0 = _e;
    _e = _20Get();
    DeRef(_0);

    // 	    if e[1] != GET_SUCCESS then
    DeRef(_10692);
    _2 = (int)SEQ_PTR(_e);
    _10692 = (int)*(((s1_ptr)_2)->base + 1);
    Ref(_10692);
    if (binary_op_a(EQUALS, _10692, 0))
        goto L6;

    // 		return e
    DeRef(_s);
    DeRef(_10692);
    return _e;
L6:

    // 	    s = append(s, e[2])
    DeRef(_10692);
    _2 = (int)SEQ_PTR(_e);
    _10692 = (int)*(((s1_ptr)_2)->base + 2);
    Ref(_10692);
    Ref(_10692);
    Append(&_s, _s, _10692);

    // 	    skip_blanks()
    _20skip_blanks();

    // 	    if ch = '}' then
    if (_20ch != 125)
        goto L7;

    // 		get_ch()
    _20get_ch();

    // 		return {GET_SUCCESS, s}
    DeRef(_10692);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 0;
    ((int *)_2)[2] = _s;
    RefDS(_s);
    _10692 = MAKE_SEQ(_1);
    DeRefDS(_s);
    DeRefDS(_e);
    return _10692;
    goto L8;
L7:

    // 	    elsif ch != ',' then
    if (_20ch == 44)
        goto L9;

    // 		return {GET_FAIL, 0}
    DeRef(_10692);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10692 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _10692;
L9:
L8:

    // 	    get_ch() -- skip comma
    _20get_ch();

    // 	end while
    goto L5;
LA:
    goto L2;
L3:

    //     elsif ch = '\"' then
    if (_20ch != 34)
        goto LB;

    // 	return get_string()
    _0 = _10692;
    _10692 = _20get_string();
    DeRef(_0);
    DeRef(_s);
    DeRef(_e);
    return _10692;
    goto L2;
LB:

    //     elsif ch = '\'' then
    if (_20ch != 39)
        goto LC;

    // 	return get_qchar()
    _0 = _10692;
    _10692 = _20get_qchar();
    DeRef(_0);
    DeRef(_s);
    DeRef(_e);
    return _10692;
    goto L2;
LC:

    //     elsif ch = -1 then
    if (_20ch != -1)
        goto LD;

    // 	return {GET_EOF, 0}
    DeRef(_10692);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = -1;
    ((int *)_2)[2] = 0;
    _10692 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _10692;
    goto L2;
LD:

    // 	return {GET_FAIL, 0}
    DeRef(_10692);
    _1 = NewS1(2);
    _2 = (int)((s1_ptr)_1)->base;
    ((int *)_2)[1] = 1;
    ((int *)_2)[2] = 0;
    _10692 = MAKE_SEQ(_1);
    DeRef(_s);
    DeRef(_e);
    return _10692;
L2:
    ;
}


int _20value(int _string)
{
    int _10714 = 0;
    int _0, _1, _2;
    

    //     input_string = string
    RefDS(_string);
    DeRef(_20input_string);
    _20input_string = _string;

    //     string_next = 1
    _20string_next = 1;

    //     get_ch()
    _20get_ch();

    //     return Get()
    _10714 = _20Get();
    DeRefDS(_string);
    return _10714;
    ;
}


